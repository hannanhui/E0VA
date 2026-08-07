/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

#ifndef CIRQ_BUFFER_H_
#define CIRQ_BUFFER_H_

#include "Platform_Types.h"
#include "Std_Types.h"

typedef struct {
	/* The max number of elements in the list */
	uint8 maxCnt;
	uint8 currCnt;

	/* Size of the elements in the list */
	uint32 dataSize;
	/* List head and tail */
	void *head;
	void *tail;

	/* Buffer start/stop */
	void *bufStart;
	void *bufEnd;
}CirqBufferType;

/* Static implementation */
CirqBufferType CirqBuffStatCreate(void *buffer, uint8 maxCnt, uint32 dataSize);
Std_ReturnType CirqBuffPush(CirqBufferType *cPtr, void *dataPtr );
Std_ReturnType CirqBuffPop(CirqBufferType *cPtr, void *dataPtr );
void CirqBuff_Init(CirqBufferType *cirqbuffer, void *buffer, uint8 maxCnt, uint32 dataSize);

#endif /* CIRQ_BUFFER_H_ */
