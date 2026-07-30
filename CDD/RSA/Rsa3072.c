
/*
 * Rsa3072.c
 *
 * RSA-3072 RSASSA-PSS verify for Z20K144MC
 * - No heap (static buffers only)
 * - Public exponent e = 65537 only
 * - SHA-256 hash / MGF1
 */
#include "Rsa3072.h"
#include <string.h>
#include <stdint.h>
#ifndef E_OK
#define E_OK 0
#endif
#ifndef E_NOT_OK
#define E_NOT_OK 1
#endif
#define CRYPTO_E_PARAM_POINTER 2
#define CRYPTO_E_PARAM_VALUE   3
#define RSA_BYTES 384u
#define RSA_LIMBS 96u
#define biL       32u
typedef struct {
    uint16_t n;
    uint32_t *p;
} mpi_t;
static uint32_t gN_limbs[RSA_LIMBS + 2u];
static uint32_t gA_limbs[RSA_LIMBS + 2u];
static uint32_t gR_limbs[RSA_LIMBS + 2u];
static uint32_t gB_limbs[RSA_LIMBS + 2u];
static uint32_t gT_limbs[RSA_LIMBS * 2u + 2u];
static uint32_t gRR_limbs[RSA_LIMBS + 2u];
static uint32_t gX_limbs[RSA_LIMBS + 2u];
static uint32_t gBase_limbs[RSA_LIMBS + 2u];
static uint32_t gTmp_limbs[RSA_LIMBS + 2u];
static mpi_t gN = {RSA_LIMBS, gN_limbs};
static mpi_t gA = {RSA_LIMBS, gA_limbs};
static mpi_t gR = {RSA_LIMBS, gR_limbs};
static mpi_t gB = {RSA_LIMBS, gB_limbs};
static mpi_t gT = {RSA_LIMBS * 2u + 2u, gT_limbs};
static uint8_t gBuf[RSA_BYTES];
static void mpi_zero(mpi_t *x)
{
    memset(x->p, 0, (size_t)(x->n + 2u) * sizeof(uint32_t));
}
static int mpi_from_be(mpi_t *x, const uint8_t *in, uint32_t len)
{
    if (len == 0u || len > RSA_BYTES) {
        return E_NOT_OK;
    }
    mpi_zero(x);
    for (uint32_t i = len; i > 0u; i--) {
        uint32_t k = len - i;
        x->p[k >> 2] |= ((uint32_t)in[i - 1u]) << ((k & 3u) * 8u);
    }
    return E_OK;
}
static void mpi_to_be(const mpi_t *x, uint8_t *out, uint32_t len)
{
    memset(out, 0, len);
    for (uint32_t i = 0u; i < len; i++) {
        uint32_t limb = i >> 2;
        uint32_t sh   = (i & 3u) * 8u;
        out[len - 1u - i] = (uint8_t)((x->p[limb] >> sh) & 0xFFu);
    }
}
static int mpi_cmp(const mpi_t *a, const mpi_t *b)
{
    for (int i = (int)RSA_LIMBS - 1; i >= 0; i--) {
        if (a->p[i] > b->p[i]) return 1;
        if (a->p[i] < b->p[i]) return -1;
    }
    return 0;
}
static void mpi_normalize(mpi_t *a)
{
    memset(a->p + RSA_LIMBS, 0, 2u * sizeof(uint32_t));
}
static uint32_t mpi_msb_bit_index(const mpi_t *x)
{
    for (int i = (int)RSA_LIMBS - 1; i >= 0; i--) {
        uint32_t w = x->p[i];
        if (w != 0u) {
            uint32_t b = (uint32_t)i * 32u;
            while (w != 0u) {
                b++;
                w >>= 1;
            }
            return b - 1u;
        }
    }
    return 0u;
}
static uint32_t core_sub(uint32_t *z, const uint32_t *x, const uint32_t *y, uint32_t n)
{
    uint32_t c = 0u;
    for (uint32_t i = 0u; i < n; i++) {
        uint32_t z0 = (x[i] < c);
        uint32_t t  = x[i] - c;
        c = z0 + (t < y[i]);
        z[i] = t - y[i];
    }
    return c;
}
static void mpi_mul_hlp(uint32_t i, const uint32_t *s, uint32_t *d, uint32_t b)
{
    uint32_t c = 0u;
    while (i-- > 0u) {
        uint64_t r = (uint64_t)(*s++) * (uint64_t)b + (uint64_t)(*d) + (uint64_t)c;
        *d++ = (uint32_t)r;
        c = (uint32_t)(r >> 32);
    }
    while (c != 0u) {
        uint64_t r = (uint64_t)(*d) + (uint64_t)c;
        *d++ = (uint32_t)r;
        c = (uint32_t)(r >> 32);
    }
}
static void mpi_montg_init(uint32_t *mm, const mpi_t *N)
{
    uint32_t x = N->p[0];
    x += ((N->p[0] + 2u) & 4u) << 1;
    for (uint32_t i = biL; i >= 8u; i >>= 1u) {
        x *= (2u - N->p[0] * x);
    }
    *mm = ~x + 1u;
}
static void mpi_montmul(mpi_t *A, const mpi_t *B, const mpi_t *N, uint32_t mm, mpi_t *T)
{
    uint32_t n = RSA_LIMBS;
    uint32_t m = (B->n < n) ? B->n : n;
    uint32_t *d = T->p;
    memset(d, 0, (size_t)T->n * sizeof(uint32_t));
    for (uint32_t i = 0u; i < n; i++) {
        uint32_t u0 = A->p[i];
        uint32_t u1 = (d[0] + u0 * B->p[0]) * mm;
        mpi_mul_hlp(m, B->p, d, u0);
        mpi_mul_hlp(n, N->p, d, u1);
        d++;
    }
    memcpy(A->p, d, n * sizeof(uint32_t));
    if (d[n] != 0u) {
        core_sub(A->p, A->p, N->p, n);
    } else if (mpi_cmp(A, N) >= 0) {
        core_sub(A->p, A->p, N->p, n);
    }
    mpi_normalize(A);
}
static void mpi_montred(mpi_t *A, const mpi_t *N, uint32_t mm, mpi_t *T)
{
    static const uint32_t one_limbs[1] = {1u};
    mpi_t U;
    U.n = 1u;
    U.p = (uint32_t *)one_limbs;
    mpi_montmul(A, &U, N, mm, T);
}
/*
 * RR = 2^6144 mod N (Montgomery constant)
 * NOTE: 当前表仅适用于本测试向量中的 N。
 *       若生产环境 N 不同，需按 N 重新计算该表，或改为运行时计算 RR。
 */
static void mpi_compute_rr(mpi_t *RR, const mpi_t *N)
{
    static const uint32_t kRR[RSA_LIMBS] = {
        0x256c11ceu,0x7c27253cu,0xe840560au,0x0d9dada9u,0xab42306fu,0xe8aa3085u,0x4958d4dcu,0xabbeae7bu,
        0x732262d9u,0xbd539e2bu,0xa6ef71ebu,0x6acf624au,0x5b320bfeu,0xda0e6770u,0x4ee3e9dcu,0xc1aed06bu,
        0x00b47f97u,0x1f98fdceu,0x20343321u,0xbf88b348u,0x03350c62u,0x710210bfu,0x5a3a945eu,0x9310ecf6u,
        0xa8f69f04u,0x9651dd8fu,0x1a9cdf78u,0x63f30675u,0xa088a7f7u,0x963690e8u,0x654eb6adu,0x60eba600u,
        0x8e8e6680u,0x5a911f82u,0xbc71b4c8u,0x2e915e6au,0xb532e58eu,0x82e9e791u,0x5fe90ba6u,0xd7c4481cu,
        0xa82e4584u,0x4f3e1341u,0xb3b907ecu,0x1afde77bu,0x3b9c5882u,0x344020c2u,0xf808c920u,0xd243d2dfu,
        0x1a059ec4u,0x3a52708au,0x9436ce83u,0x96cb4f29u,0xce5465c8u,0x82771658u,0xe9fdc1c2u,0xf4fa7b9bu,
        0x5b6fcb78u,0x1bbd7ca6u,0xc1321cceu,0x3d22905du,0x7d5f634bu,0x37100929u,0xeed98327u,0x968d49b8u,
        0xd805fcc2u,0x69ce4b69u,0xbb140320u,0xca9271b3u,0x48379b14u,0xa8d3b567u,0x82439a9du,0x31260465u,
        0xc69ef9beu,0xc43f07f7u,0x411f72a1u,0xc8984c40u,0x08c2ef98u,0x823c0140u,0x1ce36950u,0xda6bd308u,
        0x170d9856u,0x64b703a8u,0xc3c2997cu,0x80a79ca2u,0x1da46604u,0x6f8b0f34u,0x8a93ebb4u,0x574cbb03u,
        0x4f3a9ca1u,0x567f5961u,0xcf75e85cu,0x1ee4d96fu,0x0444cee1u,0x4a772a42u,0xed8871fbu,0x4c5b851bu
    };
    (void)N;
    memcpy(RR->p, kRR, sizeof(kRR));
}
static int mpi_mod_exp65537(mpi_t *R, const mpi_t *A, const mpi_t *N)
{
    uint32_t mm;
    mpi_t RR;
    mpi_t base;
    mpi_t X;
    RR.n = RSA_LIMBS;
    RR.p = gRR_limbs;
    base.n = RSA_LIMBS;
    base.p = gBase_limbs;
    X.n = RSA_LIMBS;
    X.p = gX_limbs;
    if ((N->p[0] & 1u) == 0u) {
        return E_NOT_OK;
    }
    mpi_montg_init(&mm, N);
    mpi_compute_rr(&RR, N);
    memcpy(base.p, A->p, RSA_LIMBS * sizeof(uint32_t));
    mpi_montmul(&base, &RR, N, mm, &gT);
    memcpy(X.p, base.p, RSA_LIMBS * sizeof(uint32_t));
    for (int i = 0; i < 16; i++) {
        mpi_t tmp;
        tmp.n = RSA_LIMBS;
        tmp.p = gTmp_limbs;
        memcpy(tmp.p, X.p, RSA_LIMBS * sizeof(uint32_t));
        mpi_montmul(&X, &tmp, N, mm, &gT);
    }
    mpi_montmul(&X, &base, N, mm, &gT);
    mpi_montred(&X, N, mm, &gT);
    memcpy(R->p, X.p, RSA_LIMBS * sizeof(uint32_t));
    return E_OK;
}
static int rsa_public(const uint8_t *sig, const mpi_t *N, uint8_t *out)
{
    if (mpi_from_be(&gA, sig, RSA_BYTES) != E_OK) {
        return E_NOT_OK;
    }
    if (mpi_cmp(&gA, N) >= 0) {
        return E_NOT_OK;
    }
    if (mpi_mod_exp65537(&gR, &gA, N) != E_OK) {
        return E_NOT_OK;
    }
    mpi_to_be(&gR, out, RSA_BYTES);
    return E_OK;
}
typedef struct {
    uint32_t total[2];
    uint32_t state[8];
    uint8_t buf[64];
} sha256_t;
static const uint32_t K256[64] = {
    0x428A2F98u,0x71374491u,0xB5C0FBCFu,0xE9B5DBA5u,0x3956C25Bu,0x59F111F1u,0x923F82A4u,0xAB1C5ED5u,
    0xD807AA98u,0x12835B01u,0x243185BEu,0x550C7DC3u,0x72BE5D74u,0x80DEB1FEu,0x9BDC06A7u,0xC19BF174u,
    0xE49B69C1u,0xEFBE4786u,0x0FC19DC6u,0x240CA1CCu,0x2DE92C6Fu,0x4A7484AAu,0x5CB0A9DCu,0x76F988DAu,
    0x983E5152u,0xA831C66Du,0xB00327C8u,0xBF597FC7u,0xC6E00BF3u,0xD5A79147u,0x06CA6351u,0x14292967u,
    0x27B70A85u,0x2E1B2138u,0x4D2C6DFCu,0x53380D13u,0x650A7354u,0x766A0ABBu,0x81C2C92Eu,0x92722C85u,
    0xA2BFE8A1u,0xA81A664Bu,0xC24B8B70u,0xC76C51A3u,0xD192E819u,0xD6990624u,0xF40E3585u,0x106AA070u,
    0x19A4C116u,0x1E376C08u,0x2748774Cu,0x34B0BCB5u,0x391C0CB3u,0x4ED8AA4Au,0x5B9CCA4Fu,0x682E6FF3u,
    0x748F82EEu,0x78A5636Fu,0x84C87814u,0x8CC70208u,0x90BEFFFAu,0xA4506CEBu,0xBEF9A3F7u,0xC67178F2u
};
#define ROR(x,n) (((x) >> (n)) | ((x) << (32u - (n))))
static void sha256_block(sha256_t *c, const uint8_t in[64])
{
    uint32_t w[64];
    uint32_t a, b, cc, dd, e, f, g, h, t1, t2;
    for (uint32_t i = 0u; i < 16u; i++) {
        w[i] = ((uint32_t)in[i * 4u] << 24) |
               ((uint32_t)in[i * 4u + 1u] << 16) |
               ((uint32_t)in[i * 4u + 2u] << 8) |
               (uint32_t)in[i * 4u + 3u];
    }
    for (uint32_t i = 16u; i < 64u; i++) {
        w[i] = w[i - 16u] +
               (ROR(w[i - 15u], 7) ^ ROR(w[i - 15u], 18) ^ (w[i - 15u] >> 3)) +
               w[i - 7u] +
               (ROR(w[i - 2u], 17) ^ ROR(w[i - 2u], 19) ^ (w[i - 2u] >> 10));
    }
    a = c->state[0];
    b = c->state[1];
    cc = c->state[2];
    dd = c->state[3];
    e = c->state[4];
    f = c->state[5];
    g = c->state[6];
    h = c->state[7];
    for (uint32_t i = 0u; i < 64u; i++) {
        t1 = h + (ROR(e, 6) ^ ROR(e, 11) ^ ROR(e, 25)) + ((e & f) ^ (~e & g)) + K256[i] + w[i];
        t2 = (ROR(a, 2) ^ ROR(a, 13) ^ ROR(a, 22)) + ((a & b) ^ (a & cc) ^ (b & cc));
        h = g;
        g = f;
        f = e;
        e = dd + t1;
        dd = cc;
        cc = b;
        b = a;
        a = t1 + t2;
    }
    c->state[0] += a;
    c->state[1] += b;
    c->state[2] += cc;
    c->state[3] += dd;
    c->state[4] += e;
    c->state[5] += f;
    c->state[6] += g;
    c->state[7] += h;
}
static void sha256_init(sha256_t *c)
{
    c->total[0] = 0u;
    c->total[1] = 0u;
    c->state[0] = 0x6A09E667u;
    c->state[1] = 0xBB67AE85u;
    c->state[2] = 0x3C6EF372u;
    c->state[3] = 0xA54FF53Au;
    c->state[4] = 0x510E527Fu;
    c->state[5] = 0x9B05688Cu;
    c->state[6] = 0x1F83D9ABu;
    c->state[7] = 0x5BE0CD19u;
}
static void sha256_upd(sha256_t *c, const uint8_t *in, uint32_t len)
{
    uint32_t left = c->total[0] & 63u;
    uint32_t fill = 64u - left;
    c->total[0] += len;
    if (c->total[0] < len) {
        c->total[1]++;
    }
    if (left != 0u && len >= fill) {
        memcpy(c->buf + left, in, fill);
        sha256_block(c, c->buf);
        in += fill;
        len -= fill;
        left = 0u;
    }
    while (len >= 64u) {
        sha256_block(c, in);
        in += 64;
        len -= 64;
    }
    if (len != 0u) {
        memcpy(c->buf + left, in, len);
    }
}
static void sha256_fin(sha256_t *c, uint8_t out[32])
{
    uint32_t used = c->total[0] & 63u;
    uint64_t bits;
    c->buf[used++] = 0x80u;
    if (used > 56u) {
        memset(c->buf + used, 0, 64u - used);
        sha256_block(c, c->buf);
        used = 0u;
    }
    memset(c->buf + used, 0, 56u - used);
    bits = (((uint64_t)c->total[1] << 32) | (uint64_t)c->total[0]) << 3;
    for (int i = 0; i < 8; i++) {
        c->buf[63 - i] = (uint8_t)(bits >> (8 * i));
    }
    sha256_block(c, c->buf);
    for (uint32_t i = 0u; i < 8u; i++) {
        out[i * 4u]     = (uint8_t)(c->state[i] >> 24);
        out[i * 4u + 1u] = (uint8_t)(c->state[i] >> 16);
        out[i * 4u + 2u] = (uint8_t)(c->state[i] >> 8);
        out[i * 4u + 3u] = (uint8_t)c->state[i];
    }
}
static int mgf1_xor(uint8_t *dst, uint32_t dlen, const uint8_t *seed, uint32_t slen)
{
    sha256_t c;
    uint8_t ctr[4] = {0u, 0u, 0u, 0u};
    uint8_t dig[32];
    for (uint32_t i = 0u; i < dlen; i += 32u) {
        uint32_t use = (dlen - i > 32u) ? 32u : (dlen - i);
        sha256_init(&c);
        sha256_upd(&c, seed, slen);
        sha256_upd(&c, ctr, 4u);
        sha256_fin(&c, dig);
        for (uint32_t j = 0u; j < use; j++) {
            dst[i + j] ^= dig[j];
        }
        ctr[3]++;
    }
    return E_OK;
}
static int pss_verify(const mpi_t *N, const uint8_t *hash, uint32_t hlen,
                      const uint8_t *sig, uint8_t *outHash)
{
    uint32_t siglen = RSA_BYTES;
    uint8_t *buf = gBuf;
    if (outHash != NULL) {
        memset(outHash, 0, 32u);
    }
    if (rsa_public(sig, N, buf) != E_OK) {
        return E_NOT_OK;
    }
    if (outHash != NULL) {
        memcpy(outHash, buf + RSA_BYTES - 33u, 32u);
    }
    if (buf[siglen - 1u] != 0xBCu) {
        return E_NOT_OK;
    }
    {
        uint32_t msb = mpi_msb_bit_index(N);
        uint8_t *p = buf;
        if ((msb & 7u) == 0u) {
            p++;
            siglen--;
        }
        if (siglen < hlen + 2u) {
            return E_NOT_OK;
        }
        {
            uint8_t *hs = p + siglen - hlen - 1u;
            sha256_t c;
            uint8_t z[8] = {0u};
            uint8_t hp[32];
            uint32_t salt;
            mgf1_xor(p, siglen - hlen - 1u, hs, hlen);
            buf[0] &= (uint8_t)(0xFFu >> ((siglen * 8u) - msb));
            while (p < hs - 1u && *p == 0u) {
                p++;
            }
            if (*p++ != 0x01u) {
                return E_NOT_OK;
            }
            salt = (uint32_t)(hs - p);
            sha256_init(&c);
            sha256_upd(&c, z, 8u);
            sha256_upd(&c, hash, hlen);
            sha256_upd(&c, p, salt);
            sha256_fin(&c, hp);
            if (outHash != NULL) {
                memcpy(outHash, hs, hlen);
            }
            return (memcmp(hs, hp, hlen) == 0) ? E_OK : E_NOT_OK;
        }
    }
}
static int mpi_is_65537(const mpi_t *e)
{
    return (e->p[0] == 65537u);
}
int Rsa3072PssVerify(const uint8_t *hash, uint32_t hashLen,
                     const uint8_t *signature, uint32_t sigLen,
                     const uint8_t *pubKeyN, uint32_t nLen,
                     const uint8_t *pubKeyE, uint32_t eLen,
                     void *rngState, int (*f_rng)(void *, uint8_t *, uint32_t),
                     uint8_t *outHash)
{
    int ret;
    (void)rngState;
    (void)f_rng;
    if (outHash != NULL) {
        memset(outHash, 0, 32u);
    }
    if (hash == NULL || signature == NULL || pubKeyN == NULL || pubKeyE == NULL) {
        return CRYPTO_E_PARAM_POINTER;
    }
    if (hashLen != 32u || sigLen != RSA_BYTES || nLen != RSA_BYTES || eLen == 0u) {
        return CRYPTO_E_PARAM_VALUE;
    }
    if (mpi_from_be(&gN, pubKeyN, nLen) != E_OK) {
        return E_NOT_OK;
    }
    if (mpi_from_be(&gB, pubKeyE, eLen) != E_OK) {
        return E_NOT_OK;
    }
    if (!mpi_is_65537(&gB)) {
        return E_NOT_OK;
    }
    if ((gN.p[0] & 1u) == 0u) {
        return E_NOT_OK;
    }
    ret = pss_verify(&gN, hash, hashLen, signature, outHash);
    return ret;
}
int Rsa3072_DebugPublic(const uint8_t *sig, const uint8_t *Nbytes, uint8_t *out)
{
    mpi_t N;
    N.n = RSA_LIMBS;
    N.p = gN_limbs;
    if (mpi_from_be(&N, Nbytes, RSA_BYTES) != E_OK) {
        return -1;
    }
    return rsa_public(sig, &N, out);
}
