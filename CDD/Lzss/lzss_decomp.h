#ifndef LZSS_DECOMP_H
#define LZSS_DECOMP_H

#ifdef __cplusplus
extern "C"{
#endif

#include "std_types.h"

typedef enum{
    LZSS_GET_SUCCESS_MORE = 0,
    LZSS_GET_FAIL_NOT_ENOUGH,
    LZSS_GET_END_OF_STREAM
} LZSS_GetStatus;

typedef enum{
    INJECT_OK = 0,
    INJECT_QUEUE_FULL,
    INJECT_STREAM_ALREADY_ENDED
} InjectStatus; 
  
InjectStatus LZSS_InjectCompressedData(const uint8 *data, uint16 len);

void LZSS_GetDecompressedData(uint8 **outData, uint16 *outlen, LZSS_GetStatus *status);

void LZSS_ContinueDecompress(LZSS_GetStatus *status);

void LZSS_Reset(void);
  
#ifdef __cplusplus
}
#endif

#endif /* LZSS_DECOMP_H */
/** @} */