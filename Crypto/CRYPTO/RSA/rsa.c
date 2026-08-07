#include "rsa.h"
#include "tlsf.h"
#if (CRYPTO_ALGORITHM_RSA == STD_ON)

#if (CRYPTO_RSA_TYPE == 1)
/*RSA 1024*/
#define KEY_SIZE 1024
#elif (CRYPTO_RSA_TYPE == 2)
/*RSA 2048*/
#define KEY_SIZE 2048
#else
/*RSA 3072*/
#define KEY_SIZE 3072
#endif

#define EXPONENT                     65537

#define GET_BYTE(X, i)               (((X)->p[(i) / ciL] >> (((i) % ciL) * 8)) & 0xff)

#define BITS_TO_LIMBS(i)             ((i) / biL + ((i) % biL != 0))

#define CHARS_TO_LIMBS(i)            ((i) / ciL + ((i) % ciL != 0))

#define CRYPTO_INIT_RSA_MEMPOOL()    init_memory_pool(CRYPTO_MEMPOOL_SIZE, Crypto_MemPool)

#define CRYPTO_DESTROY_RSA_MEMPOOL() destroy_memory_pool(Crypto_MemPool)

#define MBEDTLS_MPI_CHK(f)    \
    do                        \
    {                         \
        if ((ret = (f)) != 0) \
            goto cleanup;     \
    } while (0)

static int mbedtls_mpi_sub_int(mbedtls_mpi* X, const mbedtls_mpi* A, mbedtls_mpi_sint b);
static int mbedtls_mpi_mod_mpi(mbedtls_mpi* R, const mbedtls_mpi* A, const mbedtls_mpi* B);
static int mbedtls_mpi_inv_mod(mbedtls_mpi* X, const mbedtls_mpi* A, const mbedtls_mpi* N);
static void mbedtls_rsa_free(mbedtls_rsa_context* ctx);
static uint32 mbedtls_clz(const mbedtls_mpi_uint x);
static void mpi_montg_init(mbedtls_mpi_uint* mm, const mbedtls_mpi* N);
static int mpi_montmul(
    mbedtls_mpi* A,
    const mbedtls_mpi* B,
    const mbedtls_mpi* N,
    mbedtls_mpi_uint mm,
    const mbedtls_mpi* T);
static int mpi_montred(mbedtls_mpi* A, const mbedtls_mpi* N, mbedtls_mpi_uint mm, const mbedtls_mpi* T);
static void mpi_sub_hlp(uint32 n, mbedtls_mpi_uint* s, mbedtls_mpi_uint* d);
static mbedtls_mpi_uint mbedtls_int_div_int(
    mbedtls_mpi_uint u1,
    mbedtls_mpi_uint u0,
    mbedtls_mpi_uint d,
    mbedtls_mpi_uint* r);
static int mbedtls_ct_cond_select_sign(uint8 condition, int if1, int if0);
static int mbedtls_mpi_safe_cond_assign(mbedtls_mpi* X, const mbedtls_mpi* Y, uint8 assign);
static const int small_prime[] = {
    3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
    83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
    193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311,
    313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
    443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577,
    587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709,
    719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857,
    859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, -103};

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
uint8 Crypto_MemPool[CRYPTO_MEMPOOL_SIZE];
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/*
 * Unallocate one MPI
 */
void mbedtls_mpi_free(mbedtls_mpi* X)
{
    if (X == NULL_PTR)
        return;

    if (X->p != NULL_PTR)
    {
        Crypto_memset(X->p, X->n * ciL);
        tlsf_free(X->p);
    }

    X->s = 1;
    X->n = 0;
    X->p = NULL_PTR;
}

void mbedtls_mpi_init(mbedtls_mpi* X)
{
    if (X == NULL_PTR)
    {
        return;
    }

    X->s = 1;
    X->n = 0;
    X->p = NULL_PTR;
}

/*
 * Compare signed values
 */
int mbedtls_mpi_cmp_mpi(const mbedtls_mpi* X, const mbedtls_mpi* Y)
{
    uint32 i, j;

    for (i = X->n; i > 0; i--)
        if (X->p[i - 1] != 0)
            break;

    for (j = Y->n; j > 0; j--)
        if (Y->p[j - 1] != 0)
            break;

    if (i == 0 && j == 0)
        return (0);

    if (i > j)
        return (X->s);
    if (j > i)
        return (-Y->s);

    if (X->s > 0 && Y->s < 0)
        return (1);
    if (Y->s > 0 && X->s < 0)
        return (-1);

    for (; i > 0; i--)
    {
        if (X->p[i - 1] > Y->p[i - 1])
            return (X->s);
        if (X->p[i - 1] < Y->p[i - 1])
            return (-X->s);
    }

    return (0);
}
/*
 * Compare signed values
 */
int mbedtls_mpi_cmp_int(const mbedtls_mpi* X, mbedtls_mpi_sint z)
{
    mbedtls_mpi Y;
    mbedtls_mpi_uint p[1];

    *p = (z < 0) ? -z : z;
    Y.s = (z < 0) ? -1 : 1;
    Y.n = 1;
    Y.p = p;

    return (mbedtls_mpi_cmp_mpi(X, &Y));
}

int mbedtls_rsa_deduce_crt(
    const mbedtls_mpi* P,
    const mbedtls_mpi* Q,
    const mbedtls_mpi* D,
    mbedtls_mpi* DP,
    mbedtls_mpi* DQ,
    mbedtls_mpi* QP)
{
    int ret = 0;
    mbedtls_mpi K;
    mbedtls_mpi_init(&K);

    /* DP = D mod P-1 */
    if (DP != NULL_PTR)
    {
        ret = mbedtls_mpi_sub_int(&K, P, 1);
        ret = mbedtls_mpi_mod_mpi(DP, D, &K);
    }

    /* DQ = D mod Q-1 */
    if (DQ != NULL_PTR)
    {
        ret = mbedtls_mpi_sub_int(&K, Q, 1);
        ret = mbedtls_mpi_mod_mpi(DQ, D, &K);
    }

    /* QP = Q^{-1} mod P */
    if (QP != NULL_PTR)
    {
        ret = mbedtls_mpi_inv_mod(QP, Q, P);
    }
    return ret;
}

/*
 * Export CRT parameters
 * This must also be implemented if CRT is not used, for being able to
 * write DER encoded RSA keys. The helper function mbedtls_rsa_deduce_crt
 * can be used in this case.
 */
int mbedtls_rsa_export_crt(const mbedtls_rsa_context* ctx, mbedtls_mpi* DP, mbedtls_mpi* DQ, mbedtls_mpi* QP)
{
    int ret;
    int is_priv;

    /* Check if key is private or public */
    is_priv = mbedtls_mpi_cmp_int(&ctx->N, 0) != 0 && mbedtls_mpi_cmp_int(&ctx->P, 0) != 0
              && mbedtls_mpi_cmp_int(&ctx->Q, 0) != 0 && mbedtls_mpi_cmp_int(&ctx->D, 0) != 0
              && mbedtls_mpi_cmp_int(&ctx->E, 0) != 0;

    if (!is_priv)
        return (1);

    if ((ret = mbedtls_rsa_deduce_crt(&ctx->P, &ctx->Q, &ctx->D, DP, DQ, QP)) != 0)
    {
        return (1);
    }

    return (0);
}

/*
 * Initialize an RSA context
 */
void mbedtls_rsa_init(mbedtls_rsa_context* ctx)
{
    Crypto_memset(ctx, sizeof(mbedtls_rsa_context));

    ctx->padding = MBEDTLS_RSA_PKCS_V15;
    ctx->hash_id = 0;
}

/*
 * Enlarge to the specified number of limbs
 */

int mbedtls_mpi_grow(mbedtls_mpi* X, uint32 nblimbs)
{
    mbedtls_mpi_uint* p;
    int ret = 0;

    if (nblimbs > 10000)
    {
        ret = 1;
        goto exit;
    }

    if (X->n < nblimbs)
    {
        p = (mbedtls_mpi_uint*)tlsf_calloc(nblimbs, ciL);
        if (p == NULL_PTR)
        {
            ret = 1;
            goto exit;
        }
        if (X->p != NULL_PTR)
        {
            Crypto_memcpy(p, X->p, X->n * ciL);
            Crypto_memset(X->p, X->n);
            tlsf_free(X->p);
        }
        X->n = nblimbs;
        X->p = p;
    }
exit:
    return ret;
}

uint32 mbedtls_mpi_bitlen(const mbedtls_mpi* X)
{
    uint32 i, j;

    if (X->n == 0)
        return (0);

    for (i = X->n - 1; i > 0; i--)
        if (X->p[i] != 0)
            break;

    j = biL - mbedtls_clz(X->p[i]);

    return ((i * biL) + j);
}

/*
 * Copy the contents of Y into X
 */
int mbedtls_mpi_copy(mbedtls_mpi* X, const mbedtls_mpi* Y)
{
    int ret = 0;
    uint32 i;

    if (X == Y)
        return (0);

    if (Y->n == 0)
    {
        mbedtls_mpi_free(X);
        return (0);
    }

    for (i = Y->n - 1; i > 0; i--)
        if (Y->p[i] != 0)
            break;
    i++;

    X->s = Y->s;

    if (X->n < i)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, i));
    }
    else
    {
        Crypto_memset(X->p + i, (X->n - i) * ciL);
    }

    Crypto_memcpy(X->p, Y->p, i * ciL);
cleanup:
    return ret;
}

/*
 * Set value from integer
 */
int mbedtls_mpi_lset(mbedtls_mpi* X, mbedtls_mpi_sint z)
{
    int ret = 0;

    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, 1));
    Crypto_memset(X->p, X->n * ciL);

    X->p[0] = (z < 0) ? -z : z;
    X->s = (z < 0) ? -1 : 1;
cleanup:
    return ret;
}

/*
 * Left-shift: X <<= count
 */
int mbedtls_mpi_shift_l(mbedtls_mpi* X, uint32 count)
{
    int ret;
    uint32 i, v0, t1;
    mbedtls_mpi_uint r0 = 0, r1;

    v0 = count / (biL);
    t1 = count & (biL - 1);

    i = mbedtls_mpi_bitlen(X) + count;

    if (X->n * biL < i)
        MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, BITS_TO_LIMBS(i)));

    ret = 0;

    /*
     * shift by count / limb_size
     */
    if (v0 > 0)
    {
        for (i = X->n; i > v0; i--)
            X->p[i - 1] = X->p[i - v0 - 1];

        for (; i > 0; i--)
            X->p[i - 1] = 0;
    }

    /*
     * shift by count % limb_size
     */
    if (t1 > 0)
    {
        for (i = v0; i < X->n; i++)
        {
            r1 = X->p[i] >> (biL - t1);
            X->p[i] <<= t1;
            X->p[i] |= r0;
            r0 = r1;
        }
    }
cleanup:
    return ret;
}

/*
 * Unsigned subtraction: X = |A| - |B|  (HAC 14.9)
 */
int mbedtls_mpi_sub_abs(mbedtls_mpi* X, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    mbedtls_mpi TB;
    int ret;
    uint32 n;
    mbedtls_mpi_init(&TB);

    if (X == B)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TB, B));
        B = &TB;
    }

    if (X != A)
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(X, A));

    /*
     * X should always be positive as a result of unsigned subtractions.
     */
    X->s = 1;

    ret = 0;

    for (n = B->n; n > 0; n--)
        if (B->p[n - 1] != 0)
            break;

    mpi_sub_hlp(n, B->p, X->p);

cleanup:

    mbedtls_mpi_free(&TB);
    return ret;
}

/*
 * Compare unsigned values
 */
int mbedtls_mpi_cmp_abs(const mbedtls_mpi* X, const mbedtls_mpi* Y)
{
    uint32 i, j;

    for (i = X->n; i > 0; i--)
        if (X->p[i - 1] != 0)
            break;

    for (j = Y->n; j > 0; j--)
        if (Y->p[j - 1] != 0)
            break;

    if (i == 0 && j == 0)
        return (0);

    if (i > j)
        return (1);
    if (j > i)
        return (-1);

    for (; i > 0; i--)
    {
        if (X->p[i - 1] > Y->p[i - 1])
            return (1);
        if (X->p[i - 1] < Y->p[i - 1])
            return (-1);
    }

    return (0);
}

/*
 * Unsigned addition: X = |A| + |B|  (HAC 14.7)
 */
int mbedtls_mpi_add_abs(mbedtls_mpi* X, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    int ret;
    uint32 i, j;
    mbedtls_mpi_uint *o, *p, c, tmp;

    if (X == B)
    {
        const mbedtls_mpi* T = A;
        A = X;
        B = T;
    }

    if (X != A)
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(X, A));

    /*
     * X should always be positive as a result of unsigned additions.
     */
    X->s = 1;

    for (j = B->n; j > 0; j--)
        if (B->p[j - 1] != 0)
            break;

    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, j));

    o = B->p;
    p = X->p;
    c = 0;

    /*
     * tmp is used because it might happen that p == o
     */
    for (i = 0; i < j; i++, o++, p++)
    {
        tmp = *o;
        *p += c;
        c = (*p < c);
        *p += tmp;
        c += (*p < tmp);
    }

    while (c != 0)
    {
        if (i >= X->n)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, i + 1));
            p = X->p + i;
        }

        *p += c;
        c = (*p < c);
        i++;
        p++;
    }
cleanup:
    return ret;
}

/*
 * Signed subtraction: X = A - B
 */
int mbedtls_mpi_sub_mpi(mbedtls_mpi* X, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    int ret, s;

    s = A->s;
    if (A->s * B->s > 0)
    {
        if (mbedtls_mpi_cmp_abs(A, B) >= 0)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_abs(X, A, B));
            X->s = s;
        }
        else
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_abs(X, B, A));
            X->s = -s;
        }
    }
    else
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_add_abs(X, A, B));
        X->s = s;
    }
cleanup:
    return ret;
}

/*
 * Right-shift: X >>= count
 */
int mbedtls_mpi_shift_r(mbedtls_mpi* X, uint32 count)
{
    uint32 i, v0, v1;
    mbedtls_mpi_uint r0 = 0, r1;

    v0 = count / biL;
    v1 = count & (biL - 1);

    if (v0 > X->n || (v0 == X->n && v1 > 0))
        return mbedtls_mpi_lset(X, 0);

    /*
     * shift by count / limb_size
     */
    if (v0 > 0)
    {
        for (i = 0; i < X->n - v0; i++)
            X->p[i] = X->p[i + v0];

        for (; i < X->n; i++)
            X->p[i] = 0;
    }

    /*
     * shift by count % limb_size
     */
    if (v1 > 0)
    {
        for (i = X->n; i > 0; i--)
        {
            r1 = X->p[i - 1] << (biL - v1);
            X->p[i - 1] >>= v1;
            X->p[i - 1] |= r0;
            r0 = r1;
        }
    }

    return (0);
}

void mpi_mul_hlp(uint32 i, mbedtls_mpi_uint* s, mbedtls_mpi_uint* d, mbedtls_mpi_uint b)
{
    mbedtls_mpi_uint c = 0, t = 0;

    for (; i >= 16; i -= 16)
    {
        MULADDC_INIT
        MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE

            MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE
                MULADDC_STOP
    }

    for (; i >= 8; i -= 8)
    {
        MULADDC_INIT
        MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE

            MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_CORE MULADDC_STOP
    }

    for (; i > 0; i--)
    {
        MULADDC_INIT
        MULADDC_CORE
        MULADDC_STOP
    }

    t++;

    do
    {
        *d += c;
        c = (*d < c);
        d++;
    } while (c != 0);
}

/*
 * Baseline multiplication: X = A * B  (HAC 14.12)
 */
int mbedtls_mpi_mul_mpi(mbedtls_mpi* X, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    int ret;
    uint32 i, j;
    mbedtls_mpi TA, TB;
    mbedtls_mpi_init(&TA);
    mbedtls_mpi_init(&TB);

    if (X == A)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TA, A));
        A = &TA;
    }
    if (X == B)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TB, B));
        B = &TB;
    }

    for (i = A->n; i > 0; i--)
        if (A->p[i - 1] != 0)
            break;

    for (j = B->n; j > 0; j--)
        if (B->p[j - 1] != 0)
            break;

    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, i + j));
    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(X, 0));

    for (; j > 0; j--)
        mpi_mul_hlp(i, A->p, X->p + j - 1, B->p[j - 1]);

    X->s = A->s * B->s;

cleanup:

    mbedtls_mpi_free(&TB);
    mbedtls_mpi_free(&TA);
    return (ret);
}

/*
 * Baseline multiplication: X = A * b
 */
int mbedtls_mpi_mul_int(mbedtls_mpi* X, const mbedtls_mpi* A, mbedtls_mpi_uint b)
{
    mbedtls_mpi _B;
    mbedtls_mpi_uint p[1];
    _B.s = 1;
    _B.n = 1;
    _B.p = p;
    p[0] = b;

    return (mbedtls_mpi_mul_mpi(X, A, &_B));
}

/*
 * Signed addition: X = A + B
 */
int mbedtls_mpi_add_mpi(mbedtls_mpi* X, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    int ret, s;

    s = A->s;
    if (A->s * B->s < 0)
    {
        if (mbedtls_mpi_cmp_abs(A, B) >= 0)
        {
            ret = mbedtls_mpi_sub_abs(X, A, B);
            X->s = s;
        }
        else
        {
            ret = mbedtls_mpi_sub_abs(X, B, A);
            X->s = -s;
        }
    }
    else
    {
        ret = mbedtls_mpi_add_abs(X, A, B);
        X->s = s;
    }

    return ret;
}

/*
 * Division by mbedtls_mpi: A = Q * B + R  (HAC 14.20)
 */
int mbedtls_mpi_div_mpi(mbedtls_mpi* Q, mbedtls_mpi* R, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    int ret;
    uint32 i, n, t, k;
    mbedtls_mpi X, Y, Z, T1, T2;

    mbedtls_mpi_init(&X);
    mbedtls_mpi_init(&Y);
    mbedtls_mpi_init(&Z);
    mbedtls_mpi_init(&T1);
    mbedtls_mpi_init(&T2);

    if (mbedtls_mpi_cmp_abs(A, B) < 0)
    {
        if (Q != NULL_PTR)
            MBEDTLS_MPI_CHK(mbedtls_mpi_lset(Q, 0));
        if (R != NULL_PTR)
            MBEDTLS_MPI_CHK(mbedtls_mpi_copy(R, A));
        return (0);
    }

    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&X, A));
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&Y, B));
    X.s = Y.s = 1;

    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&Z, A->n + 2));
    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&Z, 0));
    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&T1, 2));
    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&T2, 3));

    k = mbedtls_mpi_bitlen(&Y) % biL;
    if (k < biL - 1)
    {
        k = biL - 1 - k;
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_l(&X, k));
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_l(&Y, k));
    }
    else
        k = 0;

    n = X.n - 1;
    t = Y.n - 1;
    MBEDTLS_MPI_CHK(mbedtls_mpi_shift_l(&Y, biL * (n - t)));

    while (mbedtls_mpi_cmp_mpi(&X, &Y) >= 0)
    {
        Z.p[n - t]++;
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&X, &X, &Y));
    }
    MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&Y, biL * (n - t)));

    for (i = n; i > t; i--)
    {
        if (X.p[i] >= Y.p[t])
            Z.p[i - t - 1] = ~0;
        else
        {
            Z.p[i - t - 1] = mbedtls_int_div_int(X.p[i], X.p[i - 1], Y.p[t], NULL_PTR);
        }

        Z.p[i - t - 1]++;
        do
        {
            Z.p[i - t - 1]--;

            MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&T1, 0));
            T1.p[0] = (t < 1) ? 0 : Y.p[t - 1];
            T1.p[1] = Y.p[t];
            MBEDTLS_MPI_CHK(mbedtls_mpi_mul_int(&T1, &T1, Z.p[i - t - 1]));

            MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&T2, 0));
            T2.p[0] = (i < 2) ? 0 : X.p[i - 2];
            T2.p[1] = (i < 1) ? 0 : X.p[i - 1];
            T2.p[2] = X.p[i];
        } while (mbedtls_mpi_cmp_mpi(&T1, &T2) > 0);

        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_int(&T1, &Y, Z.p[i - t - 1]));
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_l(&T1, biL * (i - t - 1)));
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&X, &X, &T1));

        if (mbedtls_mpi_cmp_int(&X, 0) < 0)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&T1, &Y));
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_l(&T1, biL * (i - t - 1)));
            MBEDTLS_MPI_CHK(mbedtls_mpi_add_mpi(&X, &X, &T1));
            Z.p[i - t - 1]--;
        }
    }

    if (Q != NULL_PTR)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(Q, &Z));
        Q->s = A->s * B->s;
    }

    if (R != NULL_PTR)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&X, k));
        X.s = A->s;
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(R, &X));

        if (mbedtls_mpi_cmp_int(R, 0) == 0)
            R->s = 1;
    }
cleanup:

    mbedtls_mpi_free(&X);
    mbedtls_mpi_free(&Y);
    mbedtls_mpi_free(&Z);
    mbedtls_mpi_free(&T1);
    mbedtls_mpi_free(&T2);
    return ret;
}

mbedtls_mpi_uint mbedtls_ct_mpi_uint_mask(mbedtls_mpi_uint value)
{
    return (-((value | -value) >> (sizeof(value) * 8 - 1)));
}

void mbedtls_ct_mpi_uint_cond_assign(uint32 n, mbedtls_mpi_uint* dest, const mbedtls_mpi_uint* src, uint8 condition)
{
    uint32 i;

    /* all-bits 1 if condition is 1, all-bits 0 if condition is 0 */
    const mbedtls_mpi_uint mask = -condition;

    for (i = 0; i < n; i++)
        dest[i] = (src[i] & mask) | (dest[i] & ~mask);
}

unsigned mbedtls_ct_size_bool_eq(uint32 x, uint32 y)
{
    /* diff = 0 if x == y, non-zero otherwise */
    const uint32 diff = x ^ y;

    /* diff_msb's most significant bit is equal to x != y */
    const uint32 diff_msb = (diff | (uint32)-diff);

    /* diff1 = (x != y) ? 1 : 0 */
    const unsigned diff1 = diff_msb >> (sizeof(diff_msb) * 8 - 1);

    return (1 ^ diff1);
}

static int mpi_select(mbedtls_mpi* R, const mbedtls_mpi* T, uint32 T_size, uint32 idx)
{
    int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    uint32 i;

    for (i = 0; i < T_size; i++)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_safe_cond_assign(R, &T[i], (uint8)mbedtls_ct_size_bool_eq(i, idx)));
    }

cleanup:
    return (ret);
}

/*
 * Sliding-window exponentiation: X = A^E mod N  (HAC 14.85)
 */
int mbedtls_mpi_exp_mod(
    mbedtls_mpi* X,
    const mbedtls_mpi* A,
    const mbedtls_mpi* E,
    const mbedtls_mpi* N,
    mbedtls_mpi* prec_RR)
{
    int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    uint32 wbits, wsize, one = 1;
    uint32 i, j, nblimbs;
    uint32 bufsize, nbits;
    mbedtls_mpi_uint ei, mm, state;
    mbedtls_mpi RR, T, W[1 << 6], WW, Apos;
    int neg;

    if (mbedtls_mpi_cmp_int(N, 0) <= 0 || (N->p[0] & 1) == 0)
        return (MBEDTLS_ERR_MPI_BAD_INPUT_DATA);

    if (mbedtls_mpi_cmp_int(E, 0) < 0)
        return (MBEDTLS_ERR_MPI_BAD_INPUT_DATA);

    if (mbedtls_mpi_bitlen(E) > MBEDTLS_MPI_MAX_BITS || mbedtls_mpi_bitlen(N) > MBEDTLS_MPI_MAX_BITS)
        return (MBEDTLS_ERR_MPI_BAD_INPUT_DATA);

    /*
     * Init temps and window size
     */
    mpi_montg_init(&mm, N);
    mbedtls_mpi_init(&RR);
    mbedtls_mpi_init(&T);
    mbedtls_mpi_init(&Apos);
    mbedtls_mpi_init(&WW);
    Crypto_memset(W, sizeof(W));

    i = mbedtls_mpi_bitlen(E);

    wsize = (i > 671) ? 6 : (i > 239) ? 5 : (i > 79) ? 4 : (i > 23) ? 3 : 1;

    j = N->n + 1;
    /* All W[i] and X must have at least N->n limbs for the mpi_montmul()
     * and mpi_montred() calls later. Here we ensure that W[1] and X are
     * large enough, and later we'll grow other W[i] to the same length.
     * They must not be shrunk midway through this function!
     */
    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, j));
    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&W[1], j));
    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&T, j * 2));

    /*
     * Compensate for negative A (and correct at the end)
     */
    neg = (A->s == -1);
    if (neg)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&Apos, A));
        Apos.s = 1;
        A = &Apos;
    }

    /*
     * If 1st call, pre-compute R^2 mod N
     */
    if (prec_RR == NULL_PTR || prec_RR->p == NULL_PTR)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&RR, 1));
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_l(&RR, N->n * 2 * biL));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&RR, &RR, N));

        if (prec_RR != NULL_PTR)
            Crypto_memcpy(prec_RR, &RR, sizeof(mbedtls_mpi));
    }
    else
        Crypto_memcpy(&RR, prec_RR, sizeof(mbedtls_mpi));

    /*
     * W[1] = A * R^2 * R^-1 mod N = A * R mod N
     */
    if (mbedtls_mpi_cmp_mpi(A, N) >= 0)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&W[1], A, N));
        /* This should be a no-op because W[1] is already that large before
         * mbedtls_mpi_mod_mpi(), but it's necessary to avoid an overflow
         * in mpi_montmul() below, so let's make sure. */
        MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&W[1], N->n + 1));
    }
    else
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&W[1], A));

    /* Note that this is safe because W[1] always has at least N->n limbs
     * (it grew above and was preserved by mbedtls_mpi_copy()). */
    mpi_montmul(&W[1], &RR, N, mm, &T);

    /*
     * X = R^2 * R^-1 mod N = R mod N
     */
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(X, &RR));
    mpi_montred(X, N, mm, &T);

    if (wsize > 1)
    {
        /*
         * W[1 << (wsize - 1)] = W[1] ^ (wsize - 1)
         */
        j = one << (wsize - 1);

        MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&W[j], N->n + 1));
        MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&W[j], &W[1]));

        for (i = 0; i < wsize - 1; i++)
            mpi_montmul(&W[j], &W[j], N, mm, &T);

        /*
         * W[i] = W[i - 1] * W[1]
         */
        for (i = j + 1; i < (one << wsize); i++)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_grow(&W[i], N->n + 1));
            MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&W[i], &W[i - 1]));

            mpi_montmul(&W[i], &W[1], N, mm, &T);
        }
    }

    nblimbs = E->n;
    bufsize = 0;
    nbits = 0;
    wbits = 0;
    state = 0;

    while (1)
    {
        if (bufsize == 0)
        {
            if (nblimbs == 0)
                break;

            nblimbs--;

            bufsize = sizeof(mbedtls_mpi_uint) << 3;
        }

        bufsize--;

        ei = (E->p[nblimbs] >> bufsize) & 1;

        /*
         * skip leading 0s
         */
        if (ei == 0 && state == 0)
            continue;

        if (ei == 0 && state == 1)
        {
            /*
             * out of window, square X
             */
            mpi_montmul(X, X, N, mm, &T);
            continue;
        }

        /*
         * add ei to current window
         */
        state = 2;

        nbits++;
        wbits |= (ei << (wsize - nbits));

        if (nbits == wsize)
        {
            /*
             * X = X^wsize R^-1 mod N
             */
            for (i = 0; i < wsize; i++)
                mpi_montmul(X, X, N, mm, &T);

            /*
             * X = X * W[wbits] R^-1 mod N
             */
            MBEDTLS_MPI_CHK(mpi_select(&WW, W, (uint32)1 << wsize, wbits));
            mpi_montmul(X, &WW, N, mm, &T);

            state--;
            nbits = 0;
            wbits = 0;
        }
    }

    /*
     * process the remaining bits
     */
    for (i = 0; i < nbits; i++)
    {
        mpi_montmul(X, X, N, mm, &T);

        wbits <<= 1;

        if ((wbits & (one << wsize)) != 0)
            mpi_montmul(X, &W[1], N, mm, &T);
    }

    /*
     * X = A^E * R * R^-1 mod N = A^E mod N
     */
    mpi_montred(X, N, mm, &T);

    if (neg && E->n != 0 && (E->p[0] & 1) != 0)
    {
        X->s = -1;
        MBEDTLS_MPI_CHK(mbedtls_mpi_add_mpi(X, N, X));
    }

cleanup:

    for (i = (one << (wsize - 1)); i < (one << wsize); i++)
        mbedtls_mpi_free(&W[i]);

    mbedtls_mpi_free(&W[1]);
    mbedtls_mpi_free(&T);
    mbedtls_mpi_free(&Apos);
    mbedtls_mpi_free(&WW);

    if (prec_RR == NULL_PTR || prec_RR->p == NULL_PTR)
        mbedtls_mpi_free(&RR);

    return (ret);
}

/*
 * Export X into unsigned binary data, big endian
 */
int mbedtls_mpi_write_binary(const mbedtls_mpi* X, uint8* buf, uint32 buflen)
{
    uint32 stored_bytes;
    uint32 bytes_to_copy;
    uint8* p;
    uint32 i;

    stored_bytes = X->n * ciL;

    if (stored_bytes <= buflen)
    {
        /* There is enough space in the output buffer. Write initial
         * null bytes and record the position at which to start
         * writing the significant bytes. In this case, the execution
         * trace of this function does not depend on the value of the
         * number. */
        bytes_to_copy = stored_bytes;
        p = buf + buflen - stored_bytes;
        Crypto_memset(buf, buflen - stored_bytes);
    }
    else
    {
        /* The output buffer is smaller than the allocated size of X.
         * However X may fit if its leading bytes are zero. */
        bytes_to_copy = buflen;
        p = buf;
        for (i = bytes_to_copy; i < stored_bytes; i++)
        {
            if (GET_BYTE(X, i) != 0)
                return (1);
        }
    }

    for (i = 0; i < bytes_to_copy; i++)
        p[bytes_to_copy - i - 1] = GET_BYTE(X, i);

    return (0);
}

/* Convert a big-endian byte array aligned to the size of mbedtls_mpi_uint
 * into the storage form used by mbedtls_mpi. */

static mbedtls_mpi_uint mpi_uint_bigendian_to_host_c(mbedtls_mpi_uint x)
{
    uint8 i;
    uint8* x_ptr;
    mbedtls_mpi_uint tmp = 0;

    for (i = 0, x_ptr = (uint8*)&x; i < ciL; i++, x_ptr++)
    {
        tmp <<= 8;
        tmp |= (mbedtls_mpi_uint)*x_ptr;
    }

    return (tmp);
}

static void mpi_bigendian_to_host(mbedtls_mpi_uint* const p, uint32 limbs)
{
    mbedtls_mpi_uint* cur_limb_left;
    mbedtls_mpi_uint* cur_limb_right;
    if (limbs == 0)
        return;

    for (cur_limb_left = p, cur_limb_right = p + (limbs - 1); cur_limb_left <= cur_limb_right;
         cur_limb_left++, cur_limb_right--)
    {
        mbedtls_mpi_uint tmp;

        tmp = mpi_uint_bigendian_to_host_c(*cur_limb_left);
        *cur_limb_left = mpi_uint_bigendian_to_host_c(*cur_limb_right);
        *cur_limb_right = tmp;
    }
}

/*
 * Import X from unsigned binary data, big endian
 */
int mbedtls_mpi_read_binary(mbedtls_mpi* X, const uint8* buf, uint32 buflen)
{
    int ret = 0;
    uint32 i, j, n;

    for (n = 0; n < buflen; n++)
        if (buf[n] != 0)
            break;

    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, CHARS_TO_LIMBS(buflen - n)));
    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(X, 0));

    for (i = buflen, j = 0; i > n; i--, j++)
        X->p[j / ciL] |= ((uint32)buf[i - 1]) << ((j % ciL) << 3);

cleanup:
    return ret;
}

/*
 * Do an RSA public key operation
 */
int mbedtls_rsa_public(mbedtls_rsa_context* ctx, const uint8* input, uint8* output)
{
    int ret = 0;
    uint32 olen;
    mbedtls_mpi T;

    mbedtls_mpi_init(&T);

    MBEDTLS_MPI_CHK(mbedtls_mpi_read_binary(&T, input, ctx->len));

    if (mbedtls_mpi_cmp_mpi(&T, &ctx->N) >= 0)
    {
        ret = E_NOT_OK;
        mbedtls_mpi_init(&T);
        goto cleanup;
    }
    olen = ctx->len;

    MBEDTLS_MPI_CHK(mbedtls_mpi_exp_mod(&T, &T, &ctx->E, &ctx->N, &ctx->RN));
    MBEDTLS_MPI_CHK(mbedtls_mpi_write_binary(&T, output, olen));
cleanup:
    mbedtls_mpi_free(&T);

    return ret;
}

/* Resize X to have exactly n limbs and set it to 0. */
static int mbedtls_mpi_resize_clear(mbedtls_mpi* X, uint32 limbs)
{
    if (limbs == 0)
    {
        mbedtls_mpi_free(X);
        return (0);
    }
    else if (X->n == limbs)
    {
        Crypto_memset(X->p, limbs * ciL);
        X->s = 1;
        return (0);
    }
    else
    {
        mbedtls_mpi_free(X);
        return (mbedtls_mpi_grow(X, limbs));
    }
}

/*
 * Fill X with size bytes of random.
 *
 * Use a temporary bytes representation to make sure the result is the same
 * regardless of the platform endianness (useful when f_rng is actually
 * deterministic, eg for tests).
 */
int mbedtls_mpi_fill_random(mbedtls_mpi* X, uint32 size, Std_ReturnType (*f_rng)(void*, uint8*, uint32), void* p_rng)
{
    int ret = 1;
    uint32 const limbs = CHARS_TO_LIMBS(size);

    uint32 const overhead = (limbs * ciL) - size;

    if ((X != NULL_PTR) && (f_rng != NULL_PTR))
    {
        /* Ensure that target MPI has exactly the necessary number of limbs */
        MBEDTLS_MPI_CHK(mbedtls_mpi_resize_clear(X, limbs));
        if (size == 0)
            return 0;
        if (X->n < limbs)
            return 1;

        Crypto_memset(X->p, overhead);
        Crypto_memset((uint8*)X->p + limbs * ciL, (X->n - limbs) * ciL);
        MBEDTLS_MPI_CHK(f_rng(p_rng, (uint8*)X->p + overhead, size));

        mpi_bigendian_to_host(X->p, limbs);
        ret = 0;
    }
cleanup:
    return ret;
}

/*
 * Return the number of less significant zero-bits
 */
uint32 mbedtls_mpi_lsb(const mbedtls_mpi* X)
{
    uint32 i, j, count = 0;

    for (i = 0; i < X->n; i++)
        for (j = 0; j < biL; j++, count++)
            if (((X->p[i] >> j) & 1) != 0)
                return (count);

    return (0);
}
/*
 * Greatest common divisor: G = gcd(A, B)  (HAC 14.54)
 */
int mbedtls_mpi_gcd(mbedtls_mpi* G, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    int ret;
    uint32 lz, lzt;
    mbedtls_mpi TG, TA, TB;
    mbedtls_mpi_init(&TG);
    mbedtls_mpi_init(&TA);
    mbedtls_mpi_init(&TB);

    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TA, A));
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TB, B));

    lz = mbedtls_mpi_lsb(&TA);
    lzt = mbedtls_mpi_lsb(&TB);

    if (lzt < lz)
        lz = lzt;

    MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TA, lz));
    MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TB, lz));

    TA.s = TB.s = 1;

    while (mbedtls_mpi_cmp_int(&TA, 0) != 0)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TA, mbedtls_mpi_lsb(&TA)));
        MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TB, mbedtls_mpi_lsb(&TB)));
        if (mbedtls_mpi_cmp_mpi(&TA, &TB) >= 0)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_abs(&TA, &TA, &TB));
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TA, 1));
        }
        else
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_abs(&TB, &TB, &TA));
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TB, 1));
        }
    }

    MBEDTLS_MPI_CHK(mbedtls_mpi_shift_l(&TB, lz));
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(G, &TB));

cleanup:

    mbedtls_mpi_free(&TG);
    mbedtls_mpi_free(&TA);
    mbedtls_mpi_free(&TB);
    return ret;
}

/*
 * Generate or update blinding values, see section 10 of:
 *  KOCHER, Paul C. Timing attacks on implementations of Diffie-Hellman, RSA,
 *  DSS, and other systems. In : Advances in Cryptology-CRYPTO'96. Springer
 *  Berlin Heidelberg, 1996. p. 104-113.
 */
static int rsa_prepare_blinding(mbedtls_rsa_context* ctx, Std_ReturnType (*f_rng)(void*, uint8*, uint32), void* p_rng)
{
    int ret, count = 0;

    if (ctx->Vf.p != NULL_PTR)
    {
        /* We already have blinding values, just update them by squaring */

        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&ctx->Vi, &ctx->Vi, &ctx->Vi));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&ctx->Vi, &ctx->Vi, &ctx->N));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&ctx->Vf, &ctx->Vf, &ctx->Vf));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&ctx->Vf, &ctx->Vf, &ctx->N));

        goto cleanup;
    }

    /* Unblinding value: Vf = random number, invertible mod N */
    do
    {
        if (count++ > 10)
            return (MBEDTLS_ERR_RSA_RNG_FAILED);

        MBEDTLS_MPI_CHK(mbedtls_mpi_fill_random(&ctx->Vf, ctx->len - 1, f_rng, p_rng));
        MBEDTLS_MPI_CHK(mbedtls_mpi_gcd(&ctx->Vi, &ctx->Vf, &ctx->N));
    } while (mbedtls_mpi_cmp_int(&ctx->Vi, 1) != 0);

    /* Blinding value: Vi =  Vf^(-e) mod N */
    MBEDTLS_MPI_CHK(mbedtls_mpi_inv_mod(&ctx->Vi, &ctx->Vf, &ctx->N));
    MBEDTLS_MPI_CHK(mbedtls_mpi_exp_mod(&ctx->Vi, &ctx->Vi, &ctx->E, &ctx->N, &ctx->RN));
cleanup:
    return ret;
}

/*
 * Exponent blinding supposed to prevent side-channel attacks using multiple
 * traces of measurements to recover the RSA key. The more collisions are there,
 * the more bits of the key can be recovered. See [3].
 *
 * Collecting n collisions with m bit long blinding value requires 2^(m-m/n)
 * observations on avarage.
 *
 * For example with 28 byte blinding to achieve 2 collisions the adversary has
 * to make 2^112 observations on avarage.
 *
 * (With the currently (as of 2017 April) known best algorithms breaking 2048
 * bit RSA requires approximately as much time as trying out 2^112 random keys.
 * Thus in this sense with 28 byte blinding the security is not reduced by
 * side-channel attacks like the one in [3])
 *
 * This countermeasure does not help if the key recovery is possible with a
 * single trace.
 */
#define RSA_EXPONENT_BLINDING 28

/*
 * Do an RSA private key operation
 */
int mbedtls_rsa_private(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    const uint8* input,
    uint8* output)
{
    int ret;
    uint32 olen;
    mbedtls_mpi T, T1, T2;

    mbedtls_mpi_init(&T);
    mbedtls_mpi_init(&T1);
    mbedtls_mpi_init(&T2);

    MBEDTLS_MPI_CHK(mbedtls_mpi_read_binary(&T, input, ctx->len));
    ret = mbedtls_mpi_cmp_mpi(&T, &ctx->N);
    if (ret >= 0)
    {
        ret = 1;
        goto cleanup;
    }

    if (f_rng != NULL_PTR)
    {
        /*
         * Blinding
         * T = T * Vi mod N
         */
        MBEDTLS_MPI_CHK(rsa_prepare_blinding(ctx, f_rng, p_rng));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&T, &T, &ctx->Vi));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&T, &T, &ctx->N));
    }

    MBEDTLS_MPI_CHK(mbedtls_mpi_exp_mod(&T, &T, &ctx->D, &ctx->N, &ctx->RN));

    if (f_rng != NULL_PTR)
    {
        /*
         * Unblind
         * T = T * Vf mod N
         */
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&T, &T, &ctx->Vf));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&T, &T, &ctx->N));
    }

    olen = ctx->len;
    MBEDTLS_MPI_CHK(mbedtls_mpi_write_binary(&T, output, olen));

cleanup:
    mbedtls_mpi_free(&T);
    mbedtls_mpi_free(&T1);
    mbedtls_mpi_free(&T2);

    return (0);
}

int mbedtls_rsa_rsaes_pkcs1_v15_encrypt(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    int mode,
    uint32 ilen,
    const uint8* input,
    uint8* output)
{
    uint32 nb_pad, olen;
    int ret;
    uint8* p = output;

    if (mode == MBEDTLS_RSA_PRIVATE && ctx->padding != MBEDTLS_RSA_PKCS_V15)
    {
        ret = E_NOT_OK;
    }

    olen = ctx->len;

    /* first comparison checks for overflow */
    if (ilen + 11 < ilen || olen < ilen + 11)
    {
        return E_NOT_OK;
    }

    nb_pad = olen - 3 - ilen;

    *p++ = 0;
    if (mode == MBEDTLS_RSA_PUBLIC)
    {
        *p++ = MBEDTLS_RSA_CRYPT;

        while (nb_pad-- > 0)
        {
            int rng_dl = 100;

            do
            {
                ret = f_rng(p_rng, p, 1);
            } while (*p == 0 && --rng_dl && ret == 0);

            /* Check if RNG failed to generate data */
            if (rng_dl == 0 || ret != 0)
                return (E_NOT_OK);

            p++;
        }
    }
    else
    {
        *p++ = MBEDTLS_RSA_SIGN;

        while (nb_pad-- > 0)
            *p++ = 0xFF;
    }

    *p++ = 0;
    Crypto_memcpy(p, (uint8*)input, ilen);

    return (
        (mode == MBEDTLS_RSA_PUBLIC) ? mbedtls_rsa_public(ctx, output, output)
                                     : mbedtls_rsa_private(ctx, f_rng, p_rng, output, output));
}

int mbedtls_rsa_pkcs1_encrypt(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    int mode,
    uint32 ilen,
    const uint8* input,
    uint8* output)
{
    switch (ctx->padding)
    {
    case MBEDTLS_RSA_PKCS_V15:
        return mbedtls_rsa_rsaes_pkcs1_v15_encrypt(ctx, f_rng, p_rng, mode, ilen, input, output);

    default:
        return (MBEDTLS_ERR_RSA_INVALID_PADDING);
    }
}

int mbedtls_rsa_rsaes_pkcs1_v15_decrypt(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    int mode,
    uint32* olen,
    const uint8* input,
    uint8* output,
    uint32 output_max_len)
{
    int ret;
    uint32 ilen, pad_count = 0, i;
    uint8 *p, bad, pad_done = 0;
    uint8 buf[1024];

    ilen = ctx->len;

    if (ilen < 16 || ilen > sizeof(buf))
        return (1);

    ret = (mode == MBEDTLS_RSA_PUBLIC) ? mbedtls_rsa_public(ctx, input, buf)
                                       : mbedtls_rsa_private(ctx, f_rng, p_rng, input, buf);

    if (ret != 0)
        return (ret);

    p = buf;
    bad = 0;

    /*
     * Check and get padding len in "constant-time"
     */
    bad |= *p++; /* First byte must be 0 */

    /* This test does not depend on secret data */
    if (mode == MBEDTLS_RSA_PRIVATE)
    {
        bad |= *p++ ^ MBEDTLS_RSA_CRYPT;

        /* Get padding len, but always read till end of buffer
         * (minus one, for the 00 byte) */
        for (i = 0; i < ilen - 3; i++)
        {
            pad_done |= ((p[i] | (uint8)-p[i]) >> 7) ^ 1;
            pad_count += ((pad_done | (uint8)-pad_done) >> 7) ^ 1;
        }

        p += pad_count;
        bad |= *p++; /* Must be zero */
    }
    else
    {
        bad |= *p++ ^ MBEDTLS_RSA_SIGN;

        /* Get padding len, but always read till end of buffer
         * (minus one, for the 00 byte) */
        for (i = 0; i < ilen - 3; i++)
        {
            pad_done |= (p[i] != 0xFF);
            pad_count += (pad_done == 0);
        }

        p += pad_count;
        bad |= *p++; /* Must be zero */
    }

    if (bad)
        return (1);

    if (ilen - (p - buf) > output_max_len)
        return (1);

    *olen = ilen - (p - buf);
    Crypto_memcpy(output, p, *olen);
    return ret;
}

int mbedtls_rsa_pkcs1_decrypt(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    int mode,
    uint32* olen,
    const uint8* input,
    uint8* output,
    uint32 output_max_len)
{
    switch (ctx->padding)
    {
    case MBEDTLS_RSA_PKCS_V15:
        return mbedtls_rsa_rsaes_pkcs1_v15_decrypt(ctx, f_rng, p_rng, mode, olen, input, output, output_max_len);

    default:
        return E_NOT_OK;
    }
}

/* constant-time buffer comparison */
static inline int mbedtls_safer_memcmp(const void* a, const void* b, uint32 n)
{
    uint32 i;
    const uint8* A = (const uint8*)a;
    const uint8* B = (const uint8*)b;
    uint8 diff = 0;

    for (i = 0; i < n; i++)
        diff |= A[i] ^ B[i];

    return (diff);
}

static int rsa_rsassa_pkcs1_v15_encode(
    mbedtls_md_type_t md_alg,
    uint32 hashlen,
    const uint8* hash,
    uint32 dst_len,
    uint8* dst)
{
    uint32 oid_size = 0;
    uint32 nb_pad = dst_len;
    uint8* p = dst;
    const uint8* oid = NULL_PTR;

    /* Are we signing hashed or raw data? */
    if (md_alg != MBEDTLS_MD_NONE)
    {
        return (MBEDTLS_ERR_RSA_BAD_INPUT_DATA);
    }
    else
    {
        if (nb_pad < hashlen)
            return (MBEDTLS_ERR_RSA_BAD_INPUT_DATA);

        nb_pad -= hashlen;
    }

    /* Need space for signature header and padding delimiter (3 bytes),
     * and 8 bytes for the minimal padding */
    if (nb_pad < 3 + 8)
        return (MBEDTLS_ERR_RSA_BAD_INPUT_DATA);
    nb_pad -= 3;

    /* Now nb_pad is the amount of memory to be filled
     * with padding, and at least 8 bytes long. */

    /* Write signature header and padding */
    *p++ = 0;
    *p++ = MBEDTLS_RSA_SIGN;
    Crypto_memsetVal(p, 0xFF, nb_pad);
    p += nb_pad;
    *p++ = 0;

    /* Are we signing raw data? */
    if (md_alg == MBEDTLS_MD_NONE)
    {
        Crypto_memcpy(p, hash, hashlen);
        return (0);
    }

    /* Signing hashed data, add corresponding ASN.1 structure
     *
     * DigestInfo ::= SEQUENCE {
     *   digestAlgorithm DigestAlgorithmIdentifier,
     *   digest Digest }
     * DigestAlgorithmIdentifier ::= AlgorithmIdentifier
     * Digest ::= OCTET STRING
     *
     * Schematic:
     * TAG-SEQ + LEN [ TAG-SEQ + LEN [ TAG-OID  + LEN [ OID  ]
     *                                 TAG-NULL + LEN [ NULL ] ]
     *                 TAG-OCTET + LEN [ HASH ] ]
     */
    *p++ = MBEDTLS_ASN1_SEQUENCE | MBEDTLS_ASN1_CONSTRUCTED;
    *p++ = (uint8)(0x08 + oid_size + hashlen);
    *p++ = MBEDTLS_ASN1_SEQUENCE | MBEDTLS_ASN1_CONSTRUCTED;
    *p++ = (uint8)(0x04 + oid_size);
    *p++ = MBEDTLS_ASN1_OID;
    *p++ = (uint8)oid_size;
    Crypto_memcpy(p, oid, oid_size);
    p += oid_size;
    *p++ = MBEDTLS_ASN1_NULL;
    *p++ = 0x00;
    *p++ = MBEDTLS_ASN1_OCTET_STRING;
    *p++ = (uint8)hashlen;
    Crypto_memcpy(p, hash, hashlen);
    p += hashlen;

    /* Just a sanity-check, should be automatic
     * after the initial bounds check. */
    if (p != dst + dst_len)
    {
        Crypto_memset(dst, dst_len);
        return (MBEDTLS_ERR_RSA_BAD_INPUT_DATA);
    }

    return (0);
}
/*
 * Do an RSA operation to sign the message digest
 */
int mbedtls_rsa_rsassa_pkcs1_v15_sign(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    int mode,
    mbedtls_md_type_t md_alg,
    uint32 hashlen,
    const uint8* hash,
    uint8* sig)
{
    int ret;
    uint8 *sig_try = NULL_PTR, *verif = NULL_PTR;

    if (mode == MBEDTLS_RSA_PRIVATE && ctx->padding != MBEDTLS_RSA_PKCS_V15)
        return (MBEDTLS_ERR_RSA_BAD_INPUT_DATA);

    /*
     * Prepare PKCS1-v1.5 encoding (padding and hash identifier)
     */

    if ((ret = rsa_rsassa_pkcs1_v15_encode(md_alg, hashlen, hash, ctx->len, sig)) != 0)
        return (ret);

    /*
     * Call respective RSA primitive
     */

    if (mode == MBEDTLS_RSA_PUBLIC)
    {
        /* Skip verification on a public key operation */
        return (mbedtls_rsa_public(ctx, sig, sig));
    }

    /* Private key operation
     *
     * In order to prevent Lenstra's attack, make the signature in a
     * temporary buffer and check it before returning it.
     */

    sig_try = (uint8*)tlsf_calloc(1, ctx->len);
    if (sig_try == NULL_PTR)
        return (MBEDTLS_ERR_MPI_ALLOC_FAILED);

    verif = (uint8*)tlsf_calloc(1, ctx->len);
    if (verif == NULL_PTR)
    {
        tlsf_free(sig_try);
        return (MBEDTLS_ERR_MPI_ALLOC_FAILED);
    }

    MBEDTLS_MPI_CHK(mbedtls_rsa_private(ctx, f_rng, p_rng, sig, sig_try));
    MBEDTLS_MPI_CHK(mbedtls_rsa_public(ctx, sig_try, verif));

    if (mbedtls_safer_memcmp(verif, sig, ctx->len) != 0)
    {
        ret = MBEDTLS_ERR_RSA_PRIVATE_FAILED;
        goto cleanup;
    }

    Crypto_memcpy(sig, sig_try, ctx->len);

cleanup:
    tlsf_free(sig_try);
    tlsf_free(verif);

    return (ret);
}

/*
 * Do an RSA operation to sign the message digest
 */
int mbedtls_rsa_pkcs1_sign(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    int mode,
    mbedtls_md_type_t md_alg,
    uint32 hashlen,
    const uint8* hash,
    uint8* sig)
{
    switch (ctx->padding)
    {
    case MBEDTLS_RSA_PKCS_V15:
        return mbedtls_rsa_rsassa_pkcs1_v15_sign(ctx, f_rng, p_rng, mode, md_alg, hashlen, hash, sig);

    default:
        return E_NOT_OK;
    }
}

/*
 * Implementation of the PKCS#1 v2.1 RSASSA-PKCS1-v1_5-VERIFY function
 */
int mbedtls_rsa_rsassa_pkcs1_v15_verify(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    int mode,
    mbedtls_md_type_t md_alg,
    uint32 hashlen,
    const uint8* hash,
    const uint8* sig)
{
    int ret = 0;
    uint32 sig_len;
    unsigned char *encoded = NULL_PTR, *encoded_expected = NULL_PTR;

    sig_len = ctx->len;

    if (mode == MBEDTLS_RSA_PRIVATE && ctx->padding != MBEDTLS_RSA_PKCS_V15)
        return (MBEDTLS_ERR_RSA_BAD_INPUT_DATA);

    /*
     * Prepare expected PKCS1 v1.5 encoding of hash.
     */

    if ((encoded = tlsf_calloc(1, sig_len)) == NULL_PTR || (encoded_expected = tlsf_calloc(1, sig_len)) == NULL_PTR)
    {
        ret = MBEDTLS_ERR_MPI_ALLOC_FAILED;
        goto cleanup;
    }

    if ((ret = rsa_rsassa_pkcs1_v15_encode(md_alg, hashlen, hash, sig_len, encoded_expected)) != 0)
        goto cleanup;

    /*
     * Apply RSA primitive to get what should be PKCS1 encoded hash.
     */

    ret = (mode == MBEDTLS_RSA_PUBLIC) ? mbedtls_rsa_public(ctx, sig, encoded)
                                       : mbedtls_rsa_private(ctx, f_rng, p_rng, sig, encoded);
    if (ret != 0)
        goto cleanup;

    /*
     * Compare
     */

    if ((ret = mbedtls_safer_memcmp(encoded, encoded_expected, sig_len)) != 0)
    {
        ret = MBEDTLS_ERR_RSA_VERIFY_FAILED;
        goto cleanup;
    }

cleanup:

    if (encoded != NULL_PTR)
    {
        Crypto_memset(encoded, sig_len);
        tlsf_free(encoded);
    }

    if (encoded_expected != NULL_PTR)
    {
        Crypto_memset(encoded_expected, sig_len);
        tlsf_free(encoded_expected);
    }

    return (ret);
}

/*
 * Do an RSA operation and check the message digest
 */
int mbedtls_rsa_pkcs1_verify(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, unsigned char*, uint32),
    void* p_rng,
    int mode,
    mbedtls_md_type_t md_alg,
    unsigned int hashlen,
    const unsigned char* hash,
    const unsigned char* sig)
{
    switch (ctx->padding)
    {
    case MBEDTLS_RSA_PKCS_V15:
        return mbedtls_rsa_rsassa_pkcs1_v15_verify(ctx, f_rng, p_rng, mode, md_alg, hashlen, hash, sig);

    default:
        return E_NOT_OK;
    }
}

uint32 mbedtls_mpi_size(const mbedtls_mpi* X)
{
    return ((mbedtls_mpi_bitlen(X) + 7) >> 3);
}
int mbedtls_rsa_import(
    mbedtls_rsa_context* ctx,
    const mbedtls_mpi* N,
    const mbedtls_mpi* P,
    const mbedtls_mpi* Q,
    const mbedtls_mpi* D,
    const mbedtls_mpi* E)
{
    int ret;

    if ((N != NULL_PTR && (ret = mbedtls_mpi_copy(&ctx->N, N)) != 0)
        || (P != NULL_PTR && (ret = mbedtls_mpi_copy(&ctx->P, P)) != 0)
        || (Q != NULL_PTR && (ret = mbedtls_mpi_copy(&ctx->Q, Q)) != 0)
        || (D != NULL_PTR && (ret = mbedtls_mpi_copy(&ctx->D, D)) != 0)
        || (E != NULL_PTR && (ret = mbedtls_mpi_copy(&ctx->E, E)) != 0))
    {
        return 1;
    }

    if (N != NULL_PTR)
        ctx->len = mbedtls_mpi_size(&ctx->N);

    return (0);
}

int mbedtls_mpi_mod_int(mbedtls_mpi_uint* r, const mbedtls_mpi* A, mbedtls_mpi_sint b)
{
    uint32 i;
    mbedtls_mpi_uint x, y, z;

    if (b == 0)
        return (MBEDTLS_ERR_MPI_DIVISION_BY_ZERO);

    if (b < 0)
        return (MBEDTLS_ERR_MPI_NEGATIVE_VALUE);

    /*
     * handle trivial cases
     */
    if (b == 1)
    {
        *r = 0;
        return (0);
    }

    if (b == 2)
    {
        *r = A->p[0] & 1;
        return (0);
    }

    /*
     * general case
     */
    for (i = A->n, y = 0; i > 0; i--)
    {
        x = A->p[i - 1];
        y = (y << biH) | (x >> biH);
        z = y / b;
        y -= z * b;

        x <<= biH;
        y = (y << biH) | (x >> biH);
        z = y / b;
        y -= z * b;
    }

    /*
     * If A is negative, then the current y represents a negative value.
     * Flipping it to the positive side.
     */
    if (A->s < 0 && y != 0)
        y = b - y;

    *r = y;

    return (0);
}

static int mpi_check_small_factors(const mbedtls_mpi* X)
{
    int ret = 0;
    uint32 i;
    mbedtls_mpi_uint r;

    if ((X->p[0] & 1) == 0)
        return (MBEDTLS_ERR_MPI_NOT_ACCEPTABLE);

    for (i = 0; small_prime[i] > 0; i++)
    {
        if (mbedtls_mpi_cmp_int(X, small_prime[i]) <= 0)
            return (1);

        MBEDTLS_MPI_CHK(mbedtls_mpi_mod_int(&r, X, small_prime[i]));

        if (r == 0)
            return (MBEDTLS_ERR_MPI_NOT_ACCEPTABLE);
    }

cleanup:
    return (ret);
}

static int mpi_miller_rabin(
    const mbedtls_mpi* X,
    uint32 rounds,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng)
{
    int ret, count;
    uint32 i, j, k, s;
    mbedtls_mpi W, R, T, A, RR;

    mbedtls_mpi_init(&W);
    mbedtls_mpi_init(&R);
    mbedtls_mpi_init(&T);
    mbedtls_mpi_init(&A);
    mbedtls_mpi_init(&RR);

    /*
     * W = |X| - 1
     * R = W >> lsb( W )
     */
    MBEDTLS_MPI_CHK(mbedtls_mpi_sub_int(&W, X, 1));
    s = mbedtls_mpi_lsb(&W);
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&R, &W));
    MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&R, s));

    for (i = 0; i < rounds; i++)
    {
        /*
         * pick a random A, 1 < A < |X| - 1
         */
        count = 0;
        do
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_fill_random(&A, X->n * ciL, f_rng, p_rng));

            j = mbedtls_mpi_bitlen(&A);
            k = mbedtls_mpi_bitlen(&W);
            if (j > k)
            {
                A.p[A.n - 1] &= ((mbedtls_mpi_uint)1 << (k - (A.n - 1) * biL - 1)) - 1;
            }

            if (count++ > 30)
            {
                ret = MBEDTLS_ERR_MPI_NOT_ACCEPTABLE;
                goto cleanup;
            }

        } while (mbedtls_mpi_cmp_mpi(&A, &W) >= 0 || mbedtls_mpi_cmp_int(&A, 1) <= 0);

        /*
         * A = A^R mod |X|
         */
        MBEDTLS_MPI_CHK(mbedtls_mpi_exp_mod(&A, &A, &R, X, &RR));

        if (mbedtls_mpi_cmp_mpi(&A, &W) == 0 || mbedtls_mpi_cmp_int(&A, 1) == 0)
            continue;

        j = 1;
        while (j < s && mbedtls_mpi_cmp_mpi(&A, &W) != 0)
        {
            /*
             * A = A * A mod |X|
             */
            MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&T, &A, &A));
            MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&A, &T, X));

            if (mbedtls_mpi_cmp_int(&A, 1) == 0)
                break;

            j++;
        }

        /*
         * not prime if A != |X| - 1 or A == 1
         */
        if (mbedtls_mpi_cmp_mpi(&A, &W) != 0 || mbedtls_mpi_cmp_int(&A, 1) == 0)
        {
            ret = MBEDTLS_ERR_MPI_NOT_ACCEPTABLE;
            break;
        }
    }

cleanup:
    mbedtls_mpi_free(&W);
    mbedtls_mpi_free(&R);
    mbedtls_mpi_free(&T);
    mbedtls_mpi_free(&A);
    mbedtls_mpi_free(&RR);

    return (ret);
}

int mbedtls_mpi_is_prime_ext(
    const mbedtls_mpi* X,
    int rounds,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng)
{
    int ret;
    mbedtls_mpi XX;

    XX.s = 1;
    XX.n = X->n;
    XX.p = X->p;

    if (mbedtls_mpi_cmp_int(&XX, 0) == 0 || mbedtls_mpi_cmp_int(&XX, 1) == 0)
    {
        return (MBEDTLS_ERR_MPI_NOT_ACCEPTABLE);
    }

    if (mbedtls_mpi_cmp_int(&XX, 2) == 0)
        return (0);

    if ((ret = mpi_check_small_factors(&XX)) != 0)
    {
        if (ret == 1)
            return (0);

        return (ret);
    }

    return (mpi_miller_rabin(&XX, rounds, f_rng, p_rng));
}

int mbedtls_mpi_add_int(mbedtls_mpi* X, const mbedtls_mpi* A, mbedtls_mpi_sint b)
{
    mbedtls_mpi _B;
    mbedtls_mpi_uint p[1];

    p[0] = (b < 0) ? -b : b;
    _B.s = (b < 0) ? -1 : 1;
    _B.n = 1;
    _B.p = p;

    return (mbedtls_mpi_add_mpi(X, A, &_B));
}
int mbedtls_mpi_gen_prime(
    mbedtls_mpi* X,
    uint32 nbits,
    int flags,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng)
{
// ceil(2^31.5)
#define CEIL_MAXUINT_DIV_SQRT2 0xb504f334U

    int ret = MBEDTLS_ERR_MPI_NOT_ACCEPTABLE;
    uint32 k, n;
    int rounds;
    mbedtls_mpi_uint r;
    mbedtls_mpi Y;

    if (nbits < 3 || nbits > (8 * 1024))
    {
        return MBEDTLS_ERR_MPI_BAD_INPUT_DATA;
    }
    mbedtls_mpi_init(&Y);

    n = BITS_TO_LIMBS(nbits);

    if ((flags & MBEDTLS_MPI_GEN_PRIME_FLAG_LOW_ERR) == 0)
    {
        /*
         * 2^-80 error probability, number of rounds chosen per HAC, table 4.4
         */
        rounds =
            ((nbits >= 1300)  ? 2
             : (nbits >= 850) ? 3
             : (nbits >= 650) ? 4
             : (nbits >= 350) ? 8
             : (nbits >= 250) ? 12
             : (nbits >= 150) ? 18
                              : 27);
    }
    else
    {
        /*
         * 2^-100 error probability, number of rounds computed based on HAC,
         * fact 4.48
         */
        rounds =
            ((nbits >= 1450)   ? 4
             : (nbits >= 1150) ? 5
             : (nbits >= 1000) ? 6
             : (nbits >= 850)  ? 7
             : (nbits >= 750)  ? 8
             : (nbits >= 500)  ? 13
             : (nbits >= 250)  ? 28
             : (nbits >= 150)  ? 40
                               : 51);
    }

    while (1)
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_fill_random(X, n * ciL, f_rng, p_rng));
        /* make sure generated number is at least (nbits-1)+0.5 bits  */
        if (X->p[n - 1] < CEIL_MAXUINT_DIV_SQRT2)
            continue;

        k = n * biL;
        if (k > nbits)
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(X, k - nbits));
        X->p[0] |= 1;

        if ((flags & MBEDTLS_MPI_GEN_PRIME_FLAG_DH) == 0)
        {
            ret = mbedtls_mpi_is_prime_ext(X, rounds, f_rng, p_rng);
            if (ret != MBEDTLS_ERR_MPI_NOT_ACCEPTABLE)
            {
                goto cleanup;
            }
        }
        else
        {
            /*
             * An necessary condition for Y and X = 2Y + 1 to be prime
             * is X = 2 mod 3 (which is equivalent to Y = 2 mod 3).
             * Make sure it is satisfied, while keeping X = 3 mod 4
             */

            X->p[0] |= 2;

            MBEDTLS_MPI_CHK(mbedtls_mpi_mod_int(&r, X, 3));
            if (r == 0)
                MBEDTLS_MPI_CHK(mbedtls_mpi_add_int(X, X, 8));
            else if (r == 1)
                MBEDTLS_MPI_CHK(mbedtls_mpi_add_int(X, X, 4));

            /* Set Y = (X-1) / 2, which is X / 2 because X is odd */
            MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&Y, X));
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&Y, 1));

            while (1)
            {
                /*
                 * First, check small factors for X and Y
                 * before doing Miller-Rabin on any of them
                 */
                if ((ret = mpi_check_small_factors(X)) == 0 && (ret = mpi_check_small_factors(&Y)) == 0
                    && (ret = mpi_miller_rabin(X, rounds, f_rng, p_rng)) == 0
                    && (ret = mpi_miller_rabin(&Y, rounds, f_rng, p_rng)) == 0)
                    ret = E_NOT_OK;

                /*
                 * Next candidates. We want to preserve Y = (X-1) / 2 and
                 * Y = 1 mod 2 and Y = 2 mod 3 (eq X = 3 mod 4 and X = 2 mod 3)
                 * so up Y by 6 and X by 12.
                 */
                MBEDTLS_MPI_CHK(mbedtls_mpi_add_int(X, X, 12));
                MBEDTLS_MPI_CHK(mbedtls_mpi_add_int(&Y, &Y, 6));
            }
        }
    }
cleanup:
    mbedtls_mpi_free(&Y);
    return ret;
}

void mbedtls_mpi_swap(mbedtls_mpi* X, mbedtls_mpi* Y)
{
    mbedtls_mpi T;
    Crypto_memcpy(&T, X, sizeof(mbedtls_mpi));
    Crypto_memcpy(X, Y, sizeof(mbedtls_mpi));
    Crypto_memcpy(Y, &T, sizeof(mbedtls_mpi));
}
uint32 p[4];
/*
 * Generate an RSA keypair
 *
 * This generation method follows the RSA key pair generation procedure of
 * FIPS 186-4 if 2^16 < exponent < 2^256 and nbits = 2048 or nbits = 3072.
 */
int mbedtls_rsa_gen_key(
    mbedtls_rsa_context* ctx,
    Std_ReturnType (*f_rng)(void*, uint8*, uint32),
    void* p_rng,
    uint32 nbits,
    int exponent)
{
    int ret;
    mbedtls_mpi H, G, L;
    int prime_quality = 0;

    if (nbits > 1024)
    {
        prime_quality = MBEDTLS_MPI_GEN_PRIME_FLAG_LOW_ERR;
    }
    mbedtls_mpi_init(&H);
    mbedtls_mpi_init(&G);
    mbedtls_mpi_init(&L);

    if (nbits < 128 || exponent < 3 || nbits % 2 != 0)
    {
        ret = MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        goto cleanup;
    }

    /*
     * find primes P and Q with Q < P so that:
     * 1.  |P-Q| > 2^( nbits / 2 - 100 )
     * 2.  GCD( E, (P-1)*(Q-1) ) == 1
     * 3.  E^-1 mod LCM(P-1, Q-1) > 2^( nbits / 2 )
     */
    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&ctx->E, exponent));

    do
    {
        MBEDTLS_MPI_CHK(mbedtls_mpi_gen_prime(&ctx->P, nbits >> 1, prime_quality, f_rng, p_rng));

        MBEDTLS_MPI_CHK(mbedtls_mpi_gen_prime(&ctx->Q, nbits >> 1, prime_quality, f_rng, p_rng));

        /* make sure the difference between p and q is not too small (FIPS 186-4 §B.3.3 step 5.4) */
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&H, &ctx->P, &ctx->Q));
        if (mbedtls_mpi_bitlen(&H) <= ((nbits >= 200) ? ((nbits >> 1) - 99) : 0))
            continue;

        /* not required by any standards, but some users rely on the fact that P > Q */
        if (H.s < 0)
            mbedtls_mpi_swap(&ctx->P, &ctx->Q);

        /* Temporarily replace P,Q by P-1, Q-1 */
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_int(&ctx->P, &ctx->P, 1));
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_int(&ctx->Q, &ctx->Q, 1));
        MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&H, &ctx->P, &ctx->Q));

        MBEDTLS_MPI_CHK(mbedtls_mpi_gcd(&G, &ctx->E, &H));
        if (mbedtls_mpi_cmp_int(&G, 1) != 0)
            continue;

        MBEDTLS_MPI_CHK(mbedtls_mpi_gcd(&G, &ctx->P, &ctx->Q));
        MBEDTLS_MPI_CHK(mbedtls_mpi_div_mpi(&L, NULL_PTR, &H, &G));
        MBEDTLS_MPI_CHK(mbedtls_mpi_inv_mod(&ctx->D, &ctx->E, &L));

        if (mbedtls_mpi_bitlen(&ctx->D) <= ((nbits + 1) / 2))
            continue;

        break;
    } while (1);

    /* Restore P,Q */
    MBEDTLS_MPI_CHK(mbedtls_mpi_add_int(&ctx->P, &ctx->P, 1));
    MBEDTLS_MPI_CHK(mbedtls_mpi_add_int(&ctx->Q, &ctx->Q, 1));

    MBEDTLS_MPI_CHK(mbedtls_mpi_mul_mpi(&ctx->N, &ctx->P, &ctx->Q));

    ctx->len = mbedtls_mpi_size(&ctx->N);

cleanup:

    mbedtls_mpi_free(&H);
    mbedtls_mpi_free(&G);
    mbedtls_mpi_free(&L);

    if (ret != 0)
    {
        mbedtls_rsa_free(ctx);
    }

    return ret;
}

int mbedtls_rsa_export(
    const mbedtls_rsa_context* ctx,
    mbedtls_mpi* N,
    mbedtls_mpi* P,
    mbedtls_mpi* Q,
    mbedtls_mpi* D,
    mbedtls_mpi* E)
{
    int ret;
    int is_priv;

    /* Check if key is private or public */
    is_priv = mbedtls_mpi_cmp_int(&ctx->N, 0) != 0 && mbedtls_mpi_cmp_int(&ctx->P, 0) != 0
              && mbedtls_mpi_cmp_int(&ctx->Q, 0) != 0 && mbedtls_mpi_cmp_int(&ctx->D, 0) != 0
              && mbedtls_mpi_cmp_int(&ctx->E, 0) != 0;

    if (!is_priv)
    {
        ret = E_NOT_OK;
    }

    /* Export all requested core parameters. */

    if ((N != NULL_PTR && (ret = mbedtls_mpi_copy(N, &ctx->N)) != 0)
        || (P != NULL_PTR && (ret = mbedtls_mpi_copy(P, &ctx->P)) != 0)
        || (Q != NULL_PTR && (ret = mbedtls_mpi_copy(Q, &ctx->Q)) != 0)
        || (D != NULL_PTR && (ret = mbedtls_mpi_copy(D, &ctx->D)) != 0)
        || (E != NULL_PTR && (ret = mbedtls_mpi_copy(E, &ctx->E)) != 0))
    {
        return ret;
    }

    return 0;
}

FUNC(Std_ReturnType, CRY_CODE) rsa_keygenerate(VAR(uint32, AUTOMATIC) cryptoKeyId)
{
    Std_ReturnType ret = E_NOT_OK;
    mbedtls_rsa_context rsa;
    Crypto_entropy_context entropy;
    Crypto_CtrDrbgData ctr_drbg;
    uint8 keyN[128 * CRYPTO_RSA_TYPE];
    uint8 keyP[64 * CRYPTO_RSA_TYPE];
    uint8 keyQ[64 * CRYPTO_RSA_TYPE];
    uint8 keyD[128 * CRYPTO_RSA_TYPE];
    uint8 keyE[4 * CRYPTO_RSA_TYPE];
    const uint8 pers[16] = {
        'i',
        's',
        'o',
        'f',
        't',
        '_',
        'g',
        'e',
        'n',
        'k',
        'e',
        'y',
    };

    mbedtls_ctr_drbg_init(&ctr_drbg);

    mbedtls_rsa_init(&rsa);

    Crypto_memset(&entropy, sizeof(Crypto_entropy_context));

    CRYPTO_INIT_RSA_MEMPOOL();

    MBEDTLS_MPI_CHK(mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, pers, 16));

    MBEDTLS_MPI_CHK(mbedtls_rsa_gen_key(&rsa, mbedtls_ctr_drbg_random, &ctr_drbg, KEY_SIZE, EXPONENT));

    mbedtls_mpi_write_binary(&rsa.N, keyN, 128 * CRYPTO_RSA_TYPE);
    ret = Crypto_KeyElementSetInternal(cryptoKeyId, 255, keyN, 128 * CRYPTO_RSA_TYPE);
    if (E_OK == ret)
    {
        mbedtls_mpi_write_binary(&rsa.P, keyP, 64 * CRYPTO_RSA_TYPE);
        ret = Crypto_KeyElementSetInternal(cryptoKeyId, 253, keyP, 64 * CRYPTO_RSA_TYPE);
        if (E_OK == ret)
        {
            mbedtls_mpi_write_binary(&rsa.Q, keyQ, 64 * CRYPTO_RSA_TYPE);
            ret = Crypto_KeyElementSetInternal(cryptoKeyId, 252, keyQ, 64 * CRYPTO_RSA_TYPE);
            if (E_OK == ret)
            {
                mbedtls_mpi_write_binary(&rsa.D, keyD, 128 * CRYPTO_RSA_TYPE);
                ret = Crypto_KeyElementSetInternal(cryptoKeyId, 251, keyD, 128 * CRYPTO_RSA_TYPE);
                if (E_OK == ret)
                {
                    mbedtls_mpi_write_binary(&rsa.E, keyE, 4 * CRYPTO_RSA_TYPE);
                    ret = Crypto_KeyElementSetInternal(cryptoKeyId, 254, keyE, 4 * CRYPTO_RSA_TYPE);
                }
            }
        }
    }
cleanup:
    CRYPTO_DESTROY_RSA_MEMPOOL();
    return ret;
}

FUNC(Std_ReturnType, CRY_CODE) rsa_encrypt(uint8 keyN[], uint8 keyE[], uint8 Plaintext[], uint32 Length, uint8 Output[])
{
    Std_ReturnType ret = E_NOT_OK;
    mbedtls_rsa_context rsa;
    Crypto_entropy_context entropy;
    Crypto_CtrDrbgData ctr_drbg;
    const uint8 pers[16] = {
        'i',
        's',
        'o',
        'f',
        't',
        '_',
        'g',
        'e',
        'n',
        'k',
        'e',
        'y',
    };
    mbedtls_mpi N, E;

    mbedtls_rsa_init(&rsa);
    mbedtls_mpi_init(&N);
    mbedtls_mpi_init(&E);
    Crypto_memset(&ctr_drbg, sizeof(Crypto_CtrDrbgData));
    Crypto_memset(&entropy, sizeof(Crypto_entropy_context));

    ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, pers, 16);
    if (E_OK == ret)
    {
        mbedtls_mpi_read_binary(&N, keyN, 128 * CRYPTO_RSA_TYPE);
        mbedtls_mpi_read_binary(&E, keyE, 4 * CRYPTO_RSA_TYPE);
        ret = mbedtls_rsa_import(&rsa, &N, NULL_PTR, NULL_PTR, NULL_PTR, &E);
    }

    /*
     * Calculate the RSA encryption of the hash.
     */
    if (E_OK == ret)
    {
        ret = mbedtls_rsa_pkcs1_encrypt(
            &rsa,
            mbedtls_ctr_drbg_random,
            &ctr_drbg,
            MBEDTLS_RSA_PUBLIC,
            Length,
            Plaintext,
            Output);
    }
    CRYPTO_DESTROY_RSA_MEMPOOL();
    return ret;
}

FUNC(Std_ReturnType, CRY_CODE)
rsa_decrypt(
    uint8 keyN[],
    uint8 keyP[],
    uint8 keyQ[],
    uint8 keyD[],
    uint8 keyE[],
    uint32 Length,
    uint8 Outcome[],
    uint8 Ciphertext[])
{
    Std_ReturnType ret = E_NOT_OK;
    mbedtls_rsa_context rsa;
    Crypto_entropy_context entropy;
    Crypto_CtrDrbgData ctr_drbg;
    uint8 pers[16] = {
        'i',
        's',
        'o',
        'f',
        't',
        '_',
        'g',
        'e',
        'n',
        'k',
        'e',
        'y',
    };

    mbedtls_rsa_init(&rsa);
    Crypto_memset(&ctr_drbg, sizeof(Crypto_CtrDrbgData));
    Crypto_memset(&entropy, sizeof(Crypto_entropy_context));

    ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, pers, 16);

    if (E_OK == ret)
    {
        mbedtls_mpi_read_binary(&rsa.N, keyN, 128 * CRYPTO_RSA_TYPE);

        mbedtls_mpi_read_binary(&rsa.P, keyP, 64 * CRYPTO_RSA_TYPE);

        mbedtls_mpi_read_binary(&rsa.Q, keyQ, 64 * CRYPTO_RSA_TYPE);

        mbedtls_mpi_read_binary(&rsa.D, keyD, 128 * CRYPTO_RSA_TYPE);

        mbedtls_mpi_read_binary(&rsa.E, keyE, 4 * CRYPTO_RSA_TYPE);

        rsa.len = mbedtls_mpi_size(&rsa.N);
    }

    /*
     * Decrypt the encrypted RSA data and print the result.
     */
    if (E_OK == ret)
    {
        ret = mbedtls_rsa_pkcs1_decrypt(
            &rsa,
            mbedtls_ctr_drbg_random,
            &ctr_drbg,
            MBEDTLS_RSA_PRIVATE,
            &Length,
            Ciphertext,
            Outcome,
            1024);
    }
    CRYPTO_DESTROY_RSA_MEMPOOL();
    return ret;
}

FUNC(Std_ReturnType, CRY_CODE)
rsa_sign(
    uint8 keyN[],
    uint8 keyP[],
    uint8 keyQ[],
    uint8 keyD[],
    uint8 keyE[],
    uint8 Length,
    uint8 Plaintext[],
    uint8 Output[])
{
    Std_ReturnType ret;
    mbedtls_rsa_context rsa;

    mbedtls_rsa_init(&rsa);

    mbedtls_mpi_read_binary(&rsa.N, keyN, 128 * CRYPTO_RSA_TYPE);

    mbedtls_mpi_read_binary(&rsa.P, keyP, 64 * CRYPTO_RSA_TYPE);

    mbedtls_mpi_read_binary(&rsa.Q, keyQ, 64 * CRYPTO_RSA_TYPE);

    mbedtls_mpi_read_binary(&rsa.D, keyD, 128 * CRYPTO_RSA_TYPE);

    mbedtls_mpi_read_binary(&rsa.E, keyE, 4 * CRYPTO_RSA_TYPE);
    if ((&rsa.N) != NULL_PTR)
    {
        rsa.len = mbedtls_mpi_size(&(rsa.N));
    }
    ret = mbedtls_rsa_pkcs1_sign(
        &rsa,
        NULL_PTR,
        NULL_PTR,
        MBEDTLS_RSA_PRIVATE,
        MBEDTLS_MD_NONE,
        Length,
        Plaintext,
        Output);

    return ret;
}

FUNC(Std_ReturnType, CRY_CODE) rsa_verify(uint8 keyN[], uint8 keyE[], uint32 Length, uint8 Ciphertext[], uint8 sig[])
{
    Std_ReturnType ret;
    mbedtls_rsa_context rsa;

    mbedtls_rsa_init(&rsa);

    mbedtls_mpi_read_binary(&rsa.N, keyN, 128 * CRYPTO_RSA_TYPE);
    mbedtls_mpi_read_binary(&rsa.E, keyE, 4 * CRYPTO_RSA_TYPE);
    if ((&rsa.N) != NULL_PTR)
    {
        rsa.len = mbedtls_mpi_size(&(rsa.N));
    }

    ret = mbedtls_rsa_pkcs1_verify(
        &rsa,
        NULL_PTR,
        NULL_PTR,
        MBEDTLS_RSA_PUBLIC,
        MBEDTLS_MD_NONE,
        Length,
        Ciphertext,
        sig);
    return ret;
}

/*
 * Signed subtraction: X = A - b
 */
static int mbedtls_mpi_sub_int(mbedtls_mpi* X, const mbedtls_mpi* A, mbedtls_mpi_sint b)
{
    mbedtls_mpi _B;
    mbedtls_mpi_uint p[1];

    p[0] = (b < 0) ? -b : b;
    _B.s = (b < 0) ? -1 : 1;
    _B.n = 1;
    _B.p = p;

    return (mbedtls_mpi_sub_mpi(X, A, &_B));
}

/*
 * Modulo: R = A mod B
 */
static int mbedtls_mpi_mod_mpi(mbedtls_mpi* R, const mbedtls_mpi* A, const mbedtls_mpi* B)
{
    int ret;

    MBEDTLS_MPI_CHK(mbedtls_mpi_div_mpi(NULL_PTR, R, A, B));

    while (mbedtls_mpi_cmp_int(R, 0) < 0)
        MBEDTLS_MPI_CHK(mbedtls_mpi_add_mpi(R, R, B));

    while (mbedtls_mpi_cmp_mpi(R, B) >= 0)
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(R, R, B));
cleanup:
    return ret;
}

/*
 * Modular inverse: X = A^-1 mod N  (HAC 14.61 / 14.64)
 */
static int mbedtls_mpi_inv_mod(mbedtls_mpi* X, const mbedtls_mpi* A, const mbedtls_mpi* N)
{
    int ret;
    mbedtls_mpi G, TA, TU, U1, U2, TB, TV, V1, V2;

    mbedtls_mpi_init(&TA);
    mbedtls_mpi_init(&TU);
    mbedtls_mpi_init(&U1);
    mbedtls_mpi_init(&U2);
    mbedtls_mpi_init(&G);
    mbedtls_mpi_init(&TB);
    mbedtls_mpi_init(&TV);
    mbedtls_mpi_init(&V1);
    mbedtls_mpi_init(&V2);

    MBEDTLS_MPI_CHK(mbedtls_mpi_gcd(&G, A, N));

    if (mbedtls_mpi_cmp_int(&G, 1) != 0)
    {
        ret = E_NOT_OK;
        goto cleanup;
    }

    MBEDTLS_MPI_CHK(mbedtls_mpi_mod_mpi(&TA, A, N));
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TU, &TA));
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TB, N));
    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(&TV, N));

    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&U1, 1));
    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&U2, 0));
    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&V1, 0));
    MBEDTLS_MPI_CHK(mbedtls_mpi_lset(&V2, 1));

    do
    {
        while ((TU.p[0] & 1) == 0)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TU, 1));

            if ((U1.p[0] & 1) != 0 || (U2.p[0] & 1) != 0)
            {
                MBEDTLS_MPI_CHK(mbedtls_mpi_add_mpi(&U1, &U1, &TB));
                MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&U2, &U2, &TA));
            }

            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&U1, 1));
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&U2, 1));
        }

        while ((TV.p[0] & 1) == 0)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&TV, 1));

            if ((V1.p[0] & 1) != 0 || (V2.p[0] & 1) != 0)
            {
                MBEDTLS_MPI_CHK(mbedtls_mpi_add_mpi(&V1, &V1, &TB));
                MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&V2, &V2, &TA));
            }

            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&V1, 1));
            MBEDTLS_MPI_CHK(mbedtls_mpi_shift_r(&V2, 1));
        }

        if (mbedtls_mpi_cmp_mpi(&TU, &TV) >= 0)
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&TU, &TU, &TV));
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&U1, &U1, &V1));
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&U2, &U2, &V2));
        }
        else
        {
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&TV, &TV, &TU));
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&V1, &V1, &U1));
            MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&V2, &V2, &U2));
        }
    } while (mbedtls_mpi_cmp_int(&TU, 0) != 0);

    while (mbedtls_mpi_cmp_int(&V1, 0) < 0)
        MBEDTLS_MPI_CHK(mbedtls_mpi_add_mpi(&V1, &V1, N));

    while (mbedtls_mpi_cmp_mpi(&V1, N) >= 0)
        MBEDTLS_MPI_CHK(mbedtls_mpi_sub_mpi(&V1, &V1, N));

    MBEDTLS_MPI_CHK(mbedtls_mpi_copy(X, &V1));

cleanup:
    mbedtls_mpi_free(&TA);
    mbedtls_mpi_free(&TU);
    mbedtls_mpi_free(&U1);
    mbedtls_mpi_free(&U2);
    mbedtls_mpi_free(&G);
    mbedtls_mpi_free(&TB);
    mbedtls_mpi_free(&TV);
    mbedtls_mpi_free(&V1);
    mbedtls_mpi_free(&V2);
    return ret;
}

static void mbedtls_rsa_free(mbedtls_rsa_context* ctx)
{
    if (ctx == NULL_PTR)
        return;

    mbedtls_mpi_free(&ctx->Vi);
    mbedtls_mpi_free(&ctx->Vf);
    mbedtls_mpi_free(&ctx->RN);
    mbedtls_mpi_free(&ctx->D);
    mbedtls_mpi_free(&ctx->Q);
    mbedtls_mpi_free(&ctx->P);
    mbedtls_mpi_free(&ctx->E);
    mbedtls_mpi_free(&ctx->N);

#if !defined(MBEDTLS_RSA_NO_CRT)
    mbedtls_mpi_free(&ctx->RQ);
    mbedtls_mpi_free(&ctx->RP);
    mbedtls_mpi_free(&ctx->QP);
    mbedtls_mpi_free(&ctx->DQ);
    mbedtls_mpi_free(&ctx->DP);
#endif /* MBEDTLS_RSA_NO_CRT */
}

/*
 * Count leading zero bits in a given integer
 */
static uint32 mbedtls_clz(const mbedtls_mpi_uint x)
{
    uint32 j;
    mbedtls_mpi_uint mask = (mbedtls_mpi_uint)1 << (biL - 1);

    for (j = 0; j < biL; j++)
    {
        if (x & mask)
            break;

        mask >>= 1;
    }

    return j;
}

/*
 * Fast Montgomery initialization (thanks to Tom St Denis)
 */
static void mpi_montg_init(mbedtls_mpi_uint* mm, const mbedtls_mpi* N)
{
    mbedtls_mpi_uint x, m0 = N->p[0];
    uint32 i;

    x = m0;
    x += ((m0 + 2) & 4) << 1;

    for (i = biL; i >= 8; i /= 2)
        x *= (2 - (m0 * x));

    *mm = ~x + 1;
}

/*
 * Montgomery multiplication: A = A * B * R^-1 mod N  (HAC 14.36)
 */
static int mpi_montmul(
    mbedtls_mpi* A,
    const mbedtls_mpi* B,
    const mbedtls_mpi* N,
    mbedtls_mpi_uint mm,
    const mbedtls_mpi* T)
{
    uint32 i, n, m;
    mbedtls_mpi_uint u0, u1, *d;

    Crypto_memset(T->p, T->n * ciL);

    d = T->p;
    n = N->n;
    m = (B->n < n) ? B->n : n;

    for (i = 0; i < n; i++)
    {
        /*
         * T = (T + u0*B + u1*N) / 2^biL
         */
        u0 = A->p[i];
        u1 = (d[0] + u0 * B->p[0]) * mm;

        mpi_mul_hlp(m, B->p, d, u0);
        mpi_mul_hlp(n, N->p, d, u1);

        *d++ = u0;
        d[n + 1] = 0;
    }

    Crypto_memcpy(A->p, d, (n + 1) * ciL);

    if (mbedtls_mpi_cmp_abs(A, N) >= 0)
        mpi_sub_hlp(n, N->p, A->p);
    else
        /* prevent timing attacks */
        mpi_sub_hlp(n, A->p, T->p);

    return (0);
}

/*
 * Montgomery reduction: A = A * R^-1 mod N
 */
static int mpi_montred(mbedtls_mpi* A, const mbedtls_mpi* N, mbedtls_mpi_uint mm, const mbedtls_mpi* T)
{
    mbedtls_mpi_uint z = 1;
    mbedtls_mpi U;

    U.n = U.s = (int)z;
    U.p = &z;

    return (mpi_montmul(A, &U, N, mm, T));
}

/*
 * Helper for mbedtls_mpi subtraction
 */
static void mpi_sub_hlp(uint32 n, mbedtls_mpi_uint* s, mbedtls_mpi_uint* d)
{
    uint32 i;
    mbedtls_mpi_uint c, z;

    for (i = c = 0; i < n; i++, s++, d++)
    {
        z = (*d < c);
        *d -= c;
        c = (*d < *s) + z;
        *d -= *s;
    }

    while (c != 0)
    {
        z = (*d < c);
        *d -= c;
        c = z;
        d++;
    }
}

/*
 * Unsigned integer divide - double mbedtls_mpi_uint dividend, u1/u0, and
 * mbedtls_mpi_uint divisor, d
 */
static mbedtls_mpi_uint mbedtls_int_div_int(
    mbedtls_mpi_uint u1,
    mbedtls_mpi_uint u0,
    mbedtls_mpi_uint d,
    mbedtls_mpi_uint* r)
{

    const mbedtls_mpi_uint radix = (mbedtls_mpi_uint)1 << biH;
    const mbedtls_mpi_uint uint_halfword_mask = ((mbedtls_mpi_uint)1 << biH) - 1;
    mbedtls_mpi_uint d0, d1, q0, q1, rAX, r0, quotient;
    mbedtls_mpi_uint u0_msw, u0_lsw;
    uint32 s;

    /*
     * Check for overflow
     */
    if (0 == d || u1 >= d)
    {
        if (r != NULL_PTR)
            *r = ~0;

        return (~0);
    }

    s = mbedtls_clz(d);
    d = d << s;

    u1 = u1 << s;
    u1 |= (u0 >> (biL - s)) & (-(mbedtls_mpi_sint)s >> (biL - 1));
    u0 = u0 << s;

    d1 = d >> biH;
    d0 = d & uint_halfword_mask;

    u0_msw = u0 >> biH;
    u0_lsw = u0 & uint_halfword_mask;

    q1 = u1 / d1;
    r0 = u1 - d1 * q1;

    while (q1 >= radix || (q1 * d0 > radix * r0 + u0_msw))
    {
        q1 -= 1;
        r0 += d1;

        if (r0 >= radix)
            break;
    }

    rAX = (u1 * radix) + (u0_msw - q1 * d);
    q0 = rAX / d1;
    r0 = rAX - q0 * d1;

    while (q0 >= radix || (q0 * d0 > radix * r0 + u0_lsw))
    {
        q0 -= 1;
        r0 += d1;

        if (r0 >= radix)
            break;
    }

    if (r != NULL_PTR)
        *r = (rAX * radix + u0_lsw - q0 * d) >> s;

    quotient = q1 * radix + q0;

    return quotient;
}

/** Select between two sign values without branches.
 *
 * This is functionally equivalent to `condition ? if1 : if0` but uses only bit
 * operations in order to avoid branches.
 *
 * \note if1 and if0 must be either 1 or -1, otherwise the result
 *       is undefined.
 *
 * \param condition     Condition to test.
 * \param if1           The first sign; must be either +1 or -1.
 * \param if0           The second sign; must be either +1 or -1.
 *
 * \return  \c if1 if \p condition is nonzero, otherwise \c if0.
 * */
static int mbedtls_ct_cond_select_sign(uint8 condition, int if1, int if0)
{
    /* In order to avoid questions about what we can reasonably assume about
     * the representations of signed integers, move everything to unsigned
     * by taking advantage of the fact that if1 and if0 are either +1 or -1. */
    unsigned uif1 = if1 + 1;
    unsigned uif0 = if0 + 1;

    /* condition was 0 or 1, mask is 0 or 2 as are uif1 and uif0 */
    const unsigned mask = condition << 1;

    /* select uif1 or uif0 */
    unsigned ur = (uif0 & ~mask) | (uif1 & mask);

    /* ur is now 0 or 2, convert back to -1 or +1 */
    return ((int)ur - 1);
}

static int mbedtls_mpi_safe_cond_assign(mbedtls_mpi* X, const mbedtls_mpi* Y, uint8 assign)
{
    int ret = 0;
    uint32 i;
    mbedtls_mpi_uint limb_mask;

    /* all-bits 1 if assign is 1, all-bits 0 if assign is 0 */
    limb_mask = mbedtls_ct_mpi_uint_mask(assign);
    ;

    MBEDTLS_MPI_CHK(mbedtls_mpi_grow(X, Y->n));

    X->s = mbedtls_ct_cond_select_sign(assign, Y->s, X->s);

    mbedtls_ct_mpi_uint_cond_assign(Y->n, X->p, Y->p, assign);

    for (i = Y->n; i < X->n; i++)
        X->p[i] &= ~limb_mask;

cleanup:
    return (ret);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif /* CRYPTO_ALGORITHM_RSA == STD_ON */
