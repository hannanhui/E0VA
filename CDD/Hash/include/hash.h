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

#ifndef _HASH_H
#define _HASH_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "stdint.h"
#include "string.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

#define SHA224   224
#define SHA256   256
#define SHA384   384
#define SHA512   512

#define SHA_STN_ON   1

#define SHA_WORKING   SHA256

#if (SHA_WORKING == SHA224)
#define SHA224_WORKING   SHA_STN_ON
#define SHA_BLOCK_SIZE   64
#define SHA_WHEEL_COUNT  64
#define SHA_DATA_LEN      8
#elif (SHA_WORKING == SHA256)
#define SHA256_WORKING   SHA_STN_ON
#define SHA_BLOCK_SIZE   64
#define SHA_WHEEL_COUNT  64
#define SHA_DATA_LEN      8
#elif (SHA_WORKING == SHA384)
#define SHA384_WORKING   SHA_STN_ON
#define SHA_BLOCK_SIZE   128
#define SHA_WHEEL_COUNT  80
#define SHA_DATA_LEN     16
#elif (SHA_WORKING == SHA512)
#define SHA512_WORKING   SHA_STN_ON
#define SHA_BLOCK_SIZE   128
#define SHA_WHEEL_COUNT  80
#define SHA_DATA_LEN     16
#endif

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/*
 * �����Ĵ洢�ṹ
 */
typedef struct
{
    /*
     * �洢��������ԭʼ���ݿ飨64�ֽڻ������������ڷֿ����͵�������
     * ÿ�����СΪ512λ��64�ֽڣ�����SHA-256�㷨�Ļ���������Ԫ
     */
    uint8_t data[SHA_BLOCK_SIZE];
    /*
     * ��¼��ǰ������ data ������䵫δ�������ֽ�������Χ0~63��
     * ���ڸ������ݿ��������
     */
    uint32_t datalen;
    /*
     * ��¼�Ѵ������ݵ��ܱ��س��ȣ����������ѹ�ϣ�Ŀ�͵�ǰ���������ݣ�
     * �����������ʱ������Ϣ���ȣ�SHA-256Ҫ��ĩβ64λ��ʾ��Ϣ�ܳ���
     */
    uint64_t bitlen;
    /*
     * �洢��ϣ������м�״̬��8��32λ�޷�������������ʼֵΪSHA-256�����8����ʼ��ϣ����
     * ÿ����һ�����ݿ����´�״̬�����ս���ɴ�����
     */
    uint64_t state[8];
} sha256_ctx_t;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

extern void sha_init(sha256_ctx_t *ctx);
extern void sha_update(sha256_ctx_t *ctx, const uint8_t data[], uint64_t len);
extern void sha_final(sha256_ctx_t *ctx, uint8_t hash[]);

#ifdef __cplusplus
}
#endif

#endif /* xxx_H */
/** @} */
