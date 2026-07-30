#ifndef RSA3072_H
#define RSA3072_H
#include <stdint.h>
int Rsa3072PssVerify(const uint8_t *hash, uint32_t hashLen,
                     const uint8_t *signature, uint32_t sigLen,
                     const uint8_t *pubKeyN, uint32_t nLen,
                     const uint8_t *pubKeyE, uint32_t eLen,
                     void *rngState,
                     int (*f_rng)(void *, uint8_t *, uint32_t),
                     uint8_t *outHash);
int Rsa3072_DebugPublic(const uint8_t *sig, const uint8_t *Nbytes, uint8_t *out);
#endif
