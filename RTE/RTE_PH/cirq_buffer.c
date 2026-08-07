/*
 * DESCRIPTION
 *  A circular buffer implementation.
 *
 *  This file implements the following versions:
 *  1. CirqBuffXXX
 *     - A static implementation, data is known at compile time.
 *
 */

//#include "Os.h"
#include "cirq_buffer.h"


extern void DisableAllInterrupts();
extern void EnableAllInterrupts();

static void Cirq_MemCopy(
    void * Dest,
    const void * Src,
    uint32 Size)
{
    uint8 * pDest = (uint8 *)Dest;
    const uint8 * pSrc = (const uint8 *)Src;
    while (Size > 0u)
    {
    	Size--;
        pDest[Size] = pSrc[Size];
    }
    return;
}

void CirqBuff_Init(CirqBufferType *cirqbuffer, void *buffer, uint8 maxCnt, uint32 dataSize) {
	cirqbuffer->bufStart = buffer;
	cirqbuffer->maxCnt = maxCnt;
	cirqbuffer->bufEnd = (uint8 *)cirqbuffer->bufStart + dataSize*maxCnt;
	cirqbuffer->head = cirqbuffer->bufStart;
	cirqbuffer->tail = cirqbuffer->bufStart;
	cirqbuffer->dataSize = dataSize;
	cirqbuffer->currCnt = 0;
}

/**
 *
 * @param buffer    pointer to a buffer
 * @param maxCnt    Maximum number of elements of size dataSize
 * @param dataSize  The size of the data.
 * @return
 */
CirqBufferType CirqBuffStatCreate(void *buffer, uint8 maxCnt, uint32 dataSize) {
	CirqBufferType cirqbuffer;
	cirqbuffer.bufStart = buffer;
	cirqbuffer.maxCnt = maxCnt;
	cirqbuffer.bufEnd = (uint8 *)cirqbuffer.bufStart + dataSize*maxCnt;
	cirqbuffer.head = cirqbuffer.bufStart;
	cirqbuffer.tail = cirqbuffer.bufStart;
	cirqbuffer.dataSize = dataSize;
	cirqbuffer.currCnt = 0;
	/*return whole object */
	return cirqbuffer;
}

/**
 * Push an entry into the buffer.
 *
 * @param cPtr    Pointer to the queue created with CirqBuffStatCreate, etc.
 * @param dataPtr
 * @return E_OK - if successfully pushed.
 *         E_NOT_OK - nothing pushed (it was full)
 */
Std_ReturnType CirqBuffPush(CirqBufferType *cPtr, void *dataPtr ) {
	Std_ReturnType result = E_OK;
	DisableAllInterrupts();
	if((cPtr->currCnt == cPtr->maxCnt) || (NULL_PTR == cPtr)) 
	{
		EnableAllInterrupts();
		result = E_NOT_OK;	/* No more room */
	}
	else
	{
		Cirq_MemCopy(cPtr->head,dataPtr,cPtr->dataSize);
		cPtr->head = (uint8 *)cPtr->head + cPtr->dataSize;
		if( cPtr->head == cPtr->bufEnd) {
			cPtr->head = cPtr->bufStart;
		}
		++cPtr->currCnt;
		EnableAllInterrupts();
	}
	return result;
}

/**
 * Pop an entry from the buffer.
 *
 * @param cPtr    Pointer to the queue created with CirqBuffStatCreate, etc.
 * @param dataPtr
 * @return E_OK - if successfully popped.
 *         E_NOT_OK - nothing popped (it was empty)
 */
Std_ReturnType CirqBuffPop(CirqBufferType *cPtr, void *dataPtr ) {
	Std_ReturnType result = E_OK;
	DisableAllInterrupts();
	if((cPtr->currCnt == 0) || (NULL_PTR == cPtr)) 
	{
		EnableAllInterrupts();
		result = E_NOT_OK;
	}
	else
	{
		Cirq_MemCopy(dataPtr,cPtr->tail,cPtr->dataSize);
		cPtr->tail = (uint8 *)cPtr->tail + cPtr->dataSize;
		if( cPtr->tail == cPtr->bufEnd) {
			cPtr->tail = cPtr->bufStart;
		}
		--cPtr->currCnt;
		EnableAllInterrupts();
	}
	return result;
}
