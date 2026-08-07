/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Crypto_GeneralTypes.h                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Type header for CSM                                         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>      <DATE>      <AUTHOR>        <REVISION LOG>
 *    V1.0.0      2019-10-18   qinchun.yang     Initial version
 *    V1.1.0      2020-07-16   yuzhe.zhang      R19-11
 *    V2.0.0      2023-02-06   jie.gu           R19-11
 */
#ifndef CRYPTO_GENERALTYPES_H
#define CRYPTO_GENERALTYPES_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Rte_Csm_Type.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*
 * Enumeration of the algorithm family.
 * */
typedef uint8 Crypto_AlgorithmFamilyType;

/*Algorithm family is not set*/
#define CRYPTO_ALGOFAM_NOT_SET ((uint8)0x00u)
/*SHA1 hash*/
#define CRYPTO_ALGOFAM_SHA1 ((uint8)0x01u)
/*SHA2-224 hash*/
#define CRYPTO_ALGOFAM_SHA2_224 ((uint8)0x02u)
/*SHA2-256 hash*/
#define CRYPTO_ALGOFAM_SHA2_256 ((uint8)0x03u)
/*SHA2-384 hash*/
#define CRYPTO_ALGOFAM_SHA2_384 ((uint8)0x04u)
/*SHA2-512 hash*/
#define CRYPTO_ALGOFAM_SHA2_512 ((uint8)0x05u)
/*SHA2-512/224 hash*/
#define CRYPTO_ALGOFAM_SHA2_512_224 ((uint8)0x06u)
/*SHA2-512/256 hash*/
#define CRYPTO_ALGOFAM_SHA2_512_256 ((uint8)0x07u)
/*SHA3-224 hash*/
#define CRYPTO_ALGOFAM_SHA3_224 ((uint8)0x08u)
/*SHA3-256 hash*/
#define CRYPTO_ALGOFAM_SHA3_256 ((uint8)0x09u)
/*SHA3-384 hash*/
#define CRYPTO_ALGOFAM_SHA3_384 ((uint8)0x0au)
/*SHA3-512 hash*/
#define CRYPTO_ALGOFAM_SHA3_512 ((uint8)0x0bu)
/*SHAKE128 hash*/
#define CRYPTO_ALGOFAM_SHAKE128 ((uint8)0x0cu)
/*SHAKE256 hash*/
#define CRYPTO_ALGOFAM_SHAKE256 ((uint8)0x0du)
/*RIPEMD hash*/
#define CRYPTO_ALGOFAM_RIPEMD160 ((uint8)0x0eu)
/*BLAKE-1-256 hash*/
#define CRYPTO_ALGOFAM_BLAKE_1_256 ((uint8)0x0fu)
/*BLAKE-1-512 hash*/
#define CRYPTO_ALGOFAM_BLAKE_1_512 ((uint8)0x10u)
/*BLAKE-2s-256 hash*/
#define CRYPTO_ALGOFAM_BLAKE_2s_256 ((uint8)0x11u)
/*BLAKE-2s-512 hash*/
#define CRYPTO_ALGOFAM_BLAKE_2s_512 ((uint8)0x12u)
/*3DES cipher*/
#define CRYPTO_ALGOFAM_3DES ((uint8)0x13u)
/*AES cipher*/
#define CRYPTO_ALGOFAM_AES ((uint8)0x14u)
/*ChaCha cipher*/
#define CRYPTO_ALGOFAM_CHACHA ((uint8)0x15u)
/*RSA cipher*/
#define CRYPTO_ALGOFAM_RSA ((uint8)0x16u)
/*ED22518 elliptic curve*/
#define CRYPTO_ALGOFAM_ED25519 ((uint8)0x17u)
/*Brainpool elliptic curve*/
#define CRYPTO_ALGOFAM_BRAINPOOL ((uint8)0x18u)
/*NIST ECC elliptic curves*/
#define CRYPTO_ALGOFAM_ECCNIST ((uint8)0x19u)
/*Secure Counter*/
#define CRYPTO_ALGOFAM_SECURECOUNTER ((uint8)0x1au)
/*Random Number Generator*/
#define CRYPTO_ALGOFAM_RNG ((uint8)0x1bu)
/*SipHash*/
#define CRYPTO_ALGOFAM_SIPHASH ((uint8)0x1cu)
/*ECIES Cipher*/
#define CRYPTO_ALGOFAM_ECIES ((uint8)0x1du)
/*Elliptic curve according to ANSI X9.62*/
#define CRYPTO_ALGOFAM_ECCANSI ((uint8)0x1eu)
/*Elliptic curve according to SECG*/
#define CRYPTO_ALGOFAM_ECCSEC ((uint8)0x1fu)
/*Random number generator according to NIST SP800- 90A*/
#define CRYPTO_ALGOFAM_DRBG ((uint8)0x20u)
/* Random number generator according to FIPS 186.*/
#define CRYPTO_ALGOFAM_FIPS186 ((uint8)0x21u)
/*Cipher padding according to PKCS.7*/
#define CRYPTO_ALGOFAM_PADDING_PKCS7 ((uint8)0x22u)
/*Cipher padding mode. Fill/verify data with 0, but first bit
 * after the data is 1. Eg. "DATA" & 0x80 & 0x00...*/
#define CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS ((uint8)0x23u)
/*Password-Based Key Derivation Function 2*/
#define CRYPTO_ALGOFAM_PBKDF2 ((uint8)0x24u)
/*ANSI X9.63 Public Key Cryptography*/
#define CRYPTO_ALGOFAM_KDFX963 ((uint8)0x25u)
/*Diffie-Hellman*/
#define CRYPTO_ALGOFAM_DH ((uint8)0x26u)
/*Custom algorithm family*/
#define CRYPTO_ALGOFAM_CUSTOM ((uint8)0xffu)

/*
 * Enumeration of the algorithm mode
 * */
typedef uint8 Crypto_AlgorithmModeType;
/*Algorithm key is not set*/
#define CRYPTO_ALGOMODE_NOT_SET ((uint8)0x00u)
/*Blockmode: Electronic Code Book*/
#define CRYPTO_ALGOMODE_ECB ((uint8)0x01u)
/*Blockmode: Cipher Block Chaining*/
#define CRYPTO_ALGOMODE_CBC ((uint8)0x02u)
/*Blockmode: Cipher Feedback Mode*/
#define CRYPTO_ALGOMODE_CFB ((uint8)0x03u)
/*Blockmode: Output Feedback Mode*/
#define CRYPTO_ALGOMODE_OFB ((uint8)0x04u)
/*Blockmode: Counter Modex*/
#define CRYPTO_ALGOMODE_CTR ((uint8)0x05u)
/*Blockmode: Galois/Counter Mode*/
#define CRYPTO_ALGOMODE_GCM ((uint8)0x06u)
/*XOR-encryption-based tweaked-codebook mode with ciphertext stealing*/
#define CRYPTO_ALGOMODE_XTS ((uint8)0x07u)
/*RSA Optimal Asymmetric Encryption Padding*/
#define CRYPTO_ALGOMODE_RSAES_OAEP ((uint8)0x08u)
/*RSA encryption/decryption with PKCS#1 v1.5 padding*/
#define CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 ((uint8)0x09u)
/*RSA Probabilistic Signature Scheme*/
#define CRYPTO_ALGOMODE_RSASSA_PSS ((uint8)0x0au)
/*RSA signature with PKCS#1 v1.5*/
#define CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 ((uint8)0x0bu)
/*8 rounds (e.g. ChaCha8)*/
#define CRYPTO_ALGOMODE_8ROUNDS ((uint8)0x0cu)
/*12 rounds (e.g. ChaCha12)*/
#define CRYPTO_ALGOMODE_12ROUNDS ((uint8)0x0du)
/*20 rounds (e.g. ChaCha20)*/
#define CRYPTO_ALGOMODE_20ROUNDS ((uint8)0x0eu)
/*Hashed-based MAC*/
#define CRYPTO_ALGOMODE_HMAC ((uint8)0x0fu)
/*Cipher-based MAC*/
#define CRYPTO_ALGOMODE_CMAC ((uint8)0x10u)
/*Galois MAC*/
#define CRYPTO_ALGOMODE_GMAC ((uint8)0x11u)
/*Counter-based Deterministic Random Bit Generator*/
#define CRYPTO_ALGOMODE_CTRDRBG ((uint8)0x12u)
/*Siphash-2-4*/
#define CRYPTO_ALGOMODE_SIPHASH_2_4 ((uint8)0x13u)
/*Siphash-4-8*/
#define CRYPTO_ALGOMODE_SIPHASH_4_8 ((uint8)0x14u)
/*ANSI R1 Curve*/
#define CRYPTO_ALGOMODE_PXXXR1 ((uint8)0x15u)
/*Custom algorithm mode*/
#define CRYPTO_ALGOMODE_CUSTOM ((uint8)0xffu)
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*
 * Defines which of the input/output parameters are re-directed to a key element.
 *  The values can be combined to define a bit field.
 * */
typedef enum
{
    CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT = 0x01u,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT = 0x02u,
    CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT = 0x04u,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT = 0x10u,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT = 0x20u
} Crypto_InputOutputRedirectionConfigType;

/*Enumeration of the current job state*/
typedef enum
{

    CRYPTO_JOBSTATE_IDLE = 0x00u,  /*Job is in the state "idle".*/
    CRYPTO_JOBSTATE_ACTIVE = 0x01u /*Job is in the state "active".*/
} Crypto_JobStateType;

/*Structure which contains input and output information depending on the job and
 * the crypto primitive.,ref@01009*/
typedef struct
{
    P2CONST(uint8, TYPEDEF, CSM_APPL_DATA) inputPtr;
    uint32 inputLength;
    P2CONST(uint8, TYPEDEF, CSM_APPL_DATA) secondaryInputPtr;
    uint32 secondaryInputLength;
    P2CONST(uint8, TYPEDEF, CSM_APPL_DATA) tertiaryInputPtr;
    uint32 tertiaryInputLength;
    P2VAR(uint8, TYPEDEF, CSM_APPL_DATA) outputPtr;
    P2VAR(uint32, TYPEDEF, CSM_APPL_DATA) outputLengthPtr;
    P2VAR(uint8, TYPEDEF, CSM_APPL_DATA) secondaryOutputPtr;
    P2VAR(uint32, TYPEDEF, CSM_APPL_DATA) secondaryOutputLengthPtr;
    uint64 input64;
    P2VAR(Crypto_VerifyResultType, TYPEDEF, CSM_APPL_DATA) verifyPtr;
    P2VAR(uint64, TYPEDEF, CSM_APPL_DATA) output64Ptr;
    Crypto_OperationModeType mode;
    uint32 cryIfKeyId;
    uint32 targetCryIfKeyId;
} Crypto_JobPrimitiveInputOutputType;

/*Enumeration of the kind of the service.*/
typedef enum
{
    CRYPTO_HASH = 0x00u,                  /* Hash Service */
    CRYPTO_MACGENERATE = 0x01u,           /* MacGenerate Service */
    CRYPTO_MACVERIFY = 0x02u,             /* MacVerify Service*/
    CRYPTO_ENCRYPT = 0x03u,               /* Encrypt Service */
    CRYPTO_DECRYPT = 0x04u,               /* Decrypt Service */
    CRYPTO_AEADENCRYPT = 0x05u,           /* AEADEncrypt Service */
    CRYPTO_AEADDECRYPT = 0x06u,           /* AEADDecrypt Service */
    CRYPTO_SIGNATUREGENERATE = 0x07u,     /* SignatureGenerate Service*/
    CRYPTO_SIGNATUREVERIFY = 0x08u,       /* SignatureVerify Service */
    CRYPTO_RANDOMGENERATE = 0x0Bu,        /* RandomGenerate Service */
    CRYPTO_RANDOMSEED = 0x0Cu,            /* RandomSeed Service */
    CRYPTO_KEYGENERATE = 0x0Du,           /* KeyGenerate Service */
    CRYPTO_KEYDERIVE = 0x0Eu,             /* KeyDerive Service */
    CRYPTO_KEYEXCHANGECALCPUBVAL = 0x0Fu, /* KeyExchangeCalcPubVal Service */
    CRYPTO_KEYEXCHANGECALCSECRET = 0x10u, /* KeyExchangeCalcSecret Service */
    CRYPTO_KEYSETVALID = 0x13u,           /* KeySetValid Service */
} Crypto_ServiceInfoType;

/*Structure which determines the exact algorithm.*/
typedef struct
{
    Crypto_AlgorithmFamilyType family;
    Crypto_AlgorithmFamilyType secondaryFamily;
    uint32 keyLength;
    Crypto_AlgorithmModeType mode;
} Crypto_AlgorithmInfoType;

/*Structure which contains basic information about the crypto primitive.*/
typedef struct
{
    CONST(uint32, CSM_CONST) resultLength;
    CONST(Crypto_ServiceInfoType, CSM_CONST) service;
    CONST(Crypto_AlgorithmInfoType, CSM_CONST) algorithm;
} Crypto_PrimitiveInfoType;

/*Enumeration of the processing type.*/
typedef enum
{
    CRYPTO_PROCESSING_ASYNC = 0x00u, /* Asynchronous job processing*/
    CRYPTO_PROCESSING_SYNC = 0x01u   /* Synchronous job processing*/
} Crypto_ProcessingType;

/*Structure which contains further information, which depends on the job and
 * the crypto primitive.*/
typedef struct
{
    uint32 callbackId;
    P2CONST(Crypto_PrimitiveInfoType, TYPEDEF, CSM_CONST) primitiveInfo;
    uint32 cryIfKeyId;
    Crypto_ProcessingType processingType;
    boolean callbackUpdateNotification;
} Crypto_JobPrimitiveInfoType;

/*Structure which contains job information (job ID and job priority).*/
typedef struct
{
    CONST(uint32, CSM_CONST) jobId;
    CONST(uint32, CSM_CONST) jobPriority;
} Crypto_JobInfoType;

/*Structure which holds the identifiers of the keys and key elements which shall be used
 * as input and output for a job and a bit structure which indicates which buffers shall
 * be redirected to those key elements.*/
typedef struct
{
    uint8 redirectionConfig;
    uint32 inputKeyId;
    uint32 inputKeyElementId;
    uint32 secondaryInputKeyId;
    uint32 secondaryInputKeyElementId;
    uint32 tertiaryInputKeyId;
    uint32 tertiaryInputKeyElementId;
    uint32 outputKeyId;
    uint32 outputKeyElementId;
    uint32 secondaryOutputKeyId;
    uint32 secondaryOutputKeyElementId;
} Crypto_JobRedirectionInfoType;

/* Structure which contains further information, which depends on the job and the
 * crypto primitive.*/
typedef struct
{
    uint32 jobId;
    Crypto_JobStateType jobState;
    Crypto_JobPrimitiveInputOutputType jobPrimitiveInputOutput;
    P2CONST(Crypto_JobPrimitiveInfoType, TYPEDEF, CSM_CONST) jobPrimitiveInfo;
    P2CONST(Crypto_JobInfoType, TYPEDEF, CSM_CONST) jobInfo;
    uint32 cryptoKeyId;
    P2VAR(Crypto_JobRedirectionInfoType, TYPEDEF, CSM_APPL_DATA) jobRedirectionInfoRef;
    uint32 targetCryptoKeyId;
} Crypto_JobType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* CSM_TYPES_H */
