#ifndef _TRNG_H_
#define _TRNG_H_


#include <stdint.h>

#define TRNG_OK     (0)
#define TRNG_FAIL   (-1)

void Trng_Init(void);
int Trng_GetRandom(uint8_t *buf,uint32_t len);

#endif