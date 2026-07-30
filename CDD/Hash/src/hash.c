/*=================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *=================================================================================================*/


#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "stdlib.h"
#include "hash.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

#if (SHA224_WORKING == SHA_STN_ON) || ((SHA256_WORKING == SHA_STN_ON))
#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))          

#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))      
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))    
#else
#define LSR(x,n) (x >> n)
#define ROTRIGHT(x,n) (LSR(x,n) | (x << (64 - n)))

#define CH(x,y,z)  (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define SIG0(x)  (ROTRIGHT(x, 1) ^ ROTRIGHT(x, 8) ^  LSR(x, 7))
#define SIG1(x)  (ROTRIGHT(x,19) ^ ROTRIGHT(x,61) ^  LSR(x, 6))
#define EP0(x)     (ROTRIGHT(x,28) ^ ROTRIGHT(x,34) ^ ROTRIGHT(x,39))
#define EP1(x)     (ROTRIGHT(x,14) ^ ROTRIGHT(x,18) ^ ROTRIGHT(x,41))
#endif

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*
 * SHA256�㷨����ʹ�õ���64������, ȡ����Ȼ����ǰ��64����������������С�����ֵ�ǰ32λ, ��16���Ʊ�ʾ
 */
#if (SHA224_WORKING == SHA_STN_ON) || ((SHA256_WORKING == SHA_STN_ON))
static const uint32_t k[64] =
{
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
#else
static const uint64_t k[80] =
{
    0x428A2F98D728AE22ULL,  0x7137449123EF65CDULL, 0xB5C0FBCFEC4D3B2FULL,  0xE9B5DBA58189DBBCULL,
    0x3956C25BF348B538ULL,  0x59F111F1B605D019ULL, 0x923F82A4AF194F9BULL,  0xAB1C5ED5DA6D8118ULL,
    0xD807AA98A3030242ULL,  0x12835B0145706FBEULL, 0x243185BE4EE4B28CULL,  0x550C7DC3D5FFB4E2ULL,
    0x72BE5D74F27B896FULL,  0x80DEB1FE3B1696B1ULL, 0x9BDC06A725C71235ULL,  0xC19BF174CF692694ULL,
    0xE49B69C19EF14AD2ULL,  0xEFBE4786384F25E3ULL, 0x0FC19DC68B8CD5B5ULL,  0x240CA1CC77AC9C65ULL,
    0x2DE92C6F592B0275ULL,  0x4A7484AA6EA6E483ULL, 0x5CB0A9DCBD41FBD4ULL,  0x76F988DA831153B5ULL,
    0x983E5152EE66DFABULL,  0xA831C66D2DB43210ULL, 0xB00327C898FB213FULL,  0xBF597FC7BEEF0EE4ULL,
    0xC6E00BF33DA88FC2ULL,  0xD5A79147930AA725ULL, 0x06CA6351E003826FULL,  0x142929670A0E6E70ULL,
    0x27B70A8546D22FFCULL,  0x2E1B21385C26C926ULL, 0x4D2C6DFC5AC42AEDULL,  0x53380D139D95B3DFULL,
    0x650A73548BAF63DEULL,  0x766A0ABB3C77B2A8ULL, 0x81C2C92E47EDAEE6ULL,  0x92722C851482353BULL,
    0xA2BFE8A14CF10364ULL,  0xA81A664BBC423001ULL, 0xC24B8B70D0F89791ULL,  0xC76C51A30654BE30ULL,
    0xD192E819D6EF5218ULL,  0xD69906245565A910ULL, 0xF40E35855771202AULL,  0x106AA07032BBD1B8ULL,
    0x19A4C116B8D2D0C8ULL,  0x1E376C085141AB53ULL, 0x2748774CDF8EEB99ULL,  0x34B0BCB5E19B48A8ULL,
    0x391C0CB3C5C95A63ULL,  0x4ED8AA4AE3418ACBULL, 0x5B9CCA4F7763E373ULL,  0x682E6FF3D6B2B8A3ULL,
    0x748F82EE5DEFB2FCULL,  0x78A5636F43172F60ULL, 0x84C87814A1F0AB72ULL,  0x8CC702081A6439ECULL,
    0x90BEFFFA23631E28ULL,  0xA4506CEBDE82BDE9ULL, 0xBEF9A3F7B2C67915ULL,  0xC67178F2E372532BULL,
    0xCA273ECEEA26619CULL,  0xD186B8C721C0C207ULL, 0xEADA7DD6CDE0EB1EULL,  0xF57D4F7FEE6ED178ULL,
    0x06F067AA72176FBAULL,  0x0A637DC5A2C898A6ULL, 0x113F9804BEF90DAEULL,  0x1B710B35131C471BULL,
    0x28DB77F523047D84ULL,  0x32CAAB7B40C72493ULL, 0x3C9EBE0A15C9BEBCULL,  0x431D67C49C100D4CULL,
    0x4CC5D4BECB3E42B6ULL,  0x597F299CFC657E2AULL, 0x5FCB6FAB3AD6FAECULL,  0x6C44198C4A475817ULL
};
#endif

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

#if (SHA384_WORKING == SHA_STN_ON) || ((SHA512_WORKING == SHA_STN_ON))
static inline void sha512_decode(uint64_t *output, uint8_t *input, uint32_t idx);
#endif

static void sha256_transform(sha256_ctx_t *ctx, const uint8_t data[]);

#if (SHA384_WORKING == SHA_STN_ON) || ((SHA512_WORKING == SHA_STN_ON))
static void inline sha512_encode(uint64_t input, uint8_t *output, uint32_t idx);
static inline void sha512_memcpy(uint8_t *src, uint8_t *dst, uint32_t size);
#endif

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

#if (SHA384_WORKING == SHA_STN_ON) || ((SHA512_WORKING == SHA_STN_ON))
static inline void sha512_decode(uint64_t *output, uint8_t *input, uint32_t idx)
{
    *output = ((uint64_t)input[idx + 0] << 56)
            | ((uint64_t)input[idx + 1] << 48)
            | ((uint64_t)input[idx + 2] << 40)
            | ((uint64_t)input[idx + 3] << 32)
            | ((uint64_t)input[idx + 4] << 24)
            | ((uint64_t)input[idx + 5] << 16)
            | ((uint64_t)input[idx + 6] <<  8)
            | ((uint64_t)input[idx + 7] <<  0);
}
#endif

/*
 * ���HASH����
 * */
static void sha256_transform(sha256_ctx_t *ctx, const uint8_t data[])
{
#if (SHA224_WORKING == SHA_STN_ON) || ((SHA256_WORKING == SHA_STN_ON))
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

    for(i = 0, j = 0; i < 16; ++i, j += 4)   // �̶��㷨
    {
        m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);   // ��uint8_t����ת����uint32_t����
    }
#else
    uint64_t a, b, c, d, e, f, g, h, i, t1, t2, m[80];
    for(i = 0; i < 16; i++) {
        sha512_decode(&m[i] , (uint8_t *)data , i << 3);
    }
#endif
    for(; i < SHA_WHEEL_COUNT; i++)   // �̶��㷨
    {
        m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
    }

    // �̶��㷨
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    for(i = 0; i < SHA_WHEEL_COUNT; i++)    // �̶��㷨
    {
        t1 = h + EP1(e) + CH(e, f, g) + k[i] + m[i];
        t2 = EP0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }
    // �̶��㷨
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

#if (SHA384_WORKING == SHA_STN_ON) || ((SHA512_WORKING == SHA_STN_ON))
static void inline sha512_encode(uint64_t input, uint8_t *output, uint32_t idx)
{
    output[idx + 0] = (uint8_t)(input >> 56);
    output[idx + 1] = (uint8_t)(input >> 48);
    output[idx + 2] = (uint8_t)(input >> 40);
    output[idx + 3] = (uint8_t)(input >> 32);
    output[idx + 4] = (uint8_t)(input >> 24);
    output[idx + 5] = (uint8_t)(input >> 16);
    output[idx + 6] = (uint8_t)(input >>  8);
    output[idx + 7] = (uint8_t)(input >>  0);
}

static inline void sha512_memcpy(uint8_t *src, uint8_t *dst, uint32_t size)
{
    uint32_t i = 0;
    for (;i < size;i++) {
        *dst++ = *src++;
    }
}
#endif

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

/*
 * ��ʼ����ʼ��ϣֵ
 * ȡ����Ȼ����ǰ��8������(2,3,5,7,11,13,17,19)��ƽ������С������, ����ȡǰ���32λ
 */
void sha_init(sha256_ctx_t *ctx)
{
    ctx->datalen = 0;
    ctx->bitlen = 0;
    // ��ʼhashֵ��ֵ
#if (SHA224_WORKING == SHA_STN_ON)
    ctx->state[0] = 0xc1059ed8;   
    ctx->state[1] = 0x367cd507;   
    ctx->state[2] = 0x3070dd17;  
    ctx->state[3] = 0xf70e5939;  
    ctx->state[4] = 0xffc00b31;   
    ctx->state[5] = 0x68581511;   
    ctx->state[6] = 0x64f98fa7;  
    ctx->state[7] = 0xbefa4fa4; 
#elif (SHA256_WORKING == SHA_STN_ON)
    ctx->state[0] = 0x6a09e667;   // ����2
    ctx->state[1] = 0xbb67ae85;   // ����3
    ctx->state[2] = 0x3c6ef372;   // ����5
    ctx->state[3] = 0xa54ff53a;   // ����7
    ctx->state[4] = 0x510e527f;   // ����11
    ctx->state[5] = 0x9b05688c;   // ����13
    ctx->state[6] = 0x1f83d9ab;   // ����17
    ctx->state[7] = 0x5be0cd19;   // ����19
#elif (SHA384_WORKING == SHA_STN_ON)
    ctx->state[0] = 0xcbbb9d5dc1059ed8ULL;   
    ctx->state[1] = 0x629a292a367cd507ULL;   
    ctx->state[2] = 0x9159015a3070dd17ULL;  
    ctx->state[3] = 0x152fecd8f70e5939ULL;  
    ctx->state[4] = 0x67332667ffc00b31ULL;   
    ctx->state[5] = 0x8eb44a8768581511ULL;   
    ctx->state[6] = 0xdb0c2e0d64f98fa7ULL;  
    ctx->state[7] = 0x47b5481dbefa4fa4ULL;
#elif (SHA512_WORKING == SHA_STN_ON)
    ctx->state[0] = 0x6A09E667F3BCC908ULL;
    ctx->state[1] = 0xBB67AE8584CAA73BULL;
    ctx->state[2] = 0x3C6EF372FE94F82BULL;
    ctx->state[3] = 0xA54FF53A5F1D36F1ULL;
    ctx->state[4] = 0x510E527FADE682D1ULL;
    ctx->state[5] = 0x9B05688C2B3E6C1FULL;
    ctx->state[6] = 0x1F83D9ABFB41BD6BULL;
    ctx->state[7] = 0x5BE0CD19137E2179ULL;
#endif    
}

/*
 * ������������
 * */
void sha_update(sha256_ctx_t *ctx, const uint8_t data[], uint64_t len)
{
    uint32_t i;

    for(i = 0; i < len; ++i)
    {
        ctx->data[ctx->datalen] = data[i];   // �洢��������ԭʼ���ݿ�
        ctx->datalen++;                      // ��¼���ȴ洢��������ԭʼ���ݿ�ĳ��ȣ��� update ��¼������Ϊ64�ֽ�ʱ���̽��д���
        if(ctx->datalen == SHA_BLOCK_SIZE)
        {
            sha256_transform(ctx, ctx->data);
#if (SHA224_WORKING == SHA_STN_ON) || ((SHA256_WORKING == SHA_STN_ON))
            ctx->bitlen += 512;              // ��¼�Ѵ������ݵ��ܱ��س��ȣ����������ѹ�ϣ�Ŀ�͵�ǰ����������
#else
            ctx->bitlen += 128;
#endif
            ctx->datalen = 0;
        }
    }
}

/*
 * ������䣬�����ϣֵ
 * */
/*pxc*/
void sha_final(sha256_ctx_t *ctx, uint8_t* hash)
{
    uint32_t i;

#if (SHA384_WORKING == SHA_STN_ON) || ((SHA512_WORKING == SHA_STN_ON))
    uint64_t bitlen_128[2] = {0,0};
    uint8_t len_be[16] = {0};
#endif
    i = ctx->datalen;

    // Pad whatever data is left in the buffer.
    // ����������ʣ����������ݽ�����䴦��
    if(ctx->datalen < (SHA_BLOCK_SIZE - SHA_DATA_LEN))   // ʣ������ֽ���������ݳ���
    {
        ctx->data[i++] = 0x80;   // �̶��������������1
        while(i < (SHA_BLOCK_SIZE - SHA_DATA_LEN))
        {
            ctx->data[i++] = 0x00;  // ��� 0 ֱ�� �ܳ���Ϊ
        }
    }
    else    // ʣ���ֽڲ����Դ�����ݳ���
    {
        ctx->data[i++] = 0x80;  // �̶��������������1
        while(i < SHA_BLOCK_SIZE)
        {
            ctx->data[i++] = 0x00;
        }
        sha256_transform(ctx, ctx->data);    // ����hash����
        memset(ctx->data, 0, (SHA_BLOCK_SIZE - SHA_DATA_LEN));    // ��һ�����ǰ56�ֽ�ȫ������Ϊ0
    }

    // Append to the padding the total message's length in bits and transform.
    // ����䲿��������Ϣ���ܳ��ȣ��Ա���Ϊ��λ��������ת����
#if (SHA224_WORKING == SHA_STN_ON) || ((SHA256_WORKING == SHA_STN_ON))
    ctx->bitlen   += ctx->datalen * 8;   // ���������ܳ��ȣ�������������ݣ�
    // 
    ctx->data[63]  = ctx->bitlen;
    ctx->data[62]  = ctx->bitlen >> 8;
    ctx->data[61]  = ctx->bitlen >> 16;
    ctx->data[60]  = ctx->bitlen >> 24;
    ctx->data[59]  = ctx->bitlen >> 32;
    ctx->data[58]  = ctx->bitlen >> 40;
    ctx->data[57]  = ctx->bitlen >> 48;
    ctx->data[56]  = ctx->bitlen >> 56;
#else
    ctx->bitlen   += ctx->datalen;   // ���������ܳ��ȣ�������������ݣ�

    bitlen_128[0] = ctx->bitlen << 3;
    bitlen_128[1] = ctx->bitlen >> 61;

    sha512_encode(bitlen_128[1], len_be, 0); 
    sha512_encode(bitlen_128[0], len_be, 8);

    sha512_memcpy(len_be, &ctx->data[112], 16);
#endif
    sha256_transform(ctx, ctx->data);    // ����hash����

    // Since this implementation uses little endian byte ordering and SHA uses big endian,
    // reverse all the bytes when copying the final state to the output hash.
    // ���ڴ�ʵ�ֲ��õ���С���ֽ��򣬶� SHA ����õ��Ǵ���ֽ���
    // ����ڽ�����״̬���Ƶ������ϣֵʱ���轫�����ֽڽ��з�ת��
    // С��ģʽ�ǵʹ�ͣ��ߴ��
    // ���ģʽ�ǵʹ�ߣ��ߴ��
#if (SHA224_WORKING == SHA_STN_ON) || ((SHA256_WORKING == SHA_STN_ON))
    for(i = 0; i < 4; ++i)
    {
        hash[i]      = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 4]  = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 8]  = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 20] = (ctx->state[5] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 24] = (ctx->state[6] >> (24 - i * 8)) & 0x000000ff;
#if (SHA256_WORKING == SHA_STN_ON)
        hash[i + 28] = (ctx->state[7] >> (24 - i * 8)) & 0x000000ff;
#endif
    }
#elif (SHA384_WORKING == SHA_STN_ON)
    for (i = 0; i < 6; i++) {
        sha512_encode(ctx->state[i], hash, i * 8);   // ����ϣֵ����Ϊ����ֽ�����
    }
#elif (SHA512_WORKING == SHA_STN_ON)
    for (i = 0; i < 8; i++) {
        sha512_encode(ctx->state[i], hash, i * 8);   // ����ϣֵ����Ϊ����ֽ�����
    }
#endif
}

#ifdef __cplusplus
}
#endif
/** @} */
