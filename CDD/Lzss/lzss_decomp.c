/*
* IDENTIFICATION
*
* Product Name: General ECU
* Module Abbr : Bootloader Decompression
* File Name : lzss_decomp.c
* Date : 2007-06-14
* Revision : 1.0
*
*-------------------------------------------------------------------------------
* CONTENTS
*
*1 DESCRIPTION
*
*2 DEFINITIONS
* 2.1 Constants
* 2.2 Variables
* 2.3 Macros
*
*3 GLOBAL FUNCTIONS
* 3.1 LZSS_ExpandData
*
*-------------------------------------------------------------------------------
*/
/*
*-------------------------------------------------------------------------------
*1 DESCRIPTION
*-------------------------------------------------------------------------------
*
* This file implements the LZSS decompression used in ECU bootloaders.
* LZSS is a dictionary compression method and uses a sliding window as
* dictionary. Compression is achieved by replacing byte arrays found in
* previously read data with position/length-pairs pointing in to the sliding
* window. If the position/length-pair takes up more bits than the byte array
* that it tries to compress, the data is left uncompressed. This is indicated
* with a single bit flag, '1' indicates that data to follow is uncompressed and
* '0' indicates that data to follow is a position/length-pair.
*
* Code in this module is based on the code examples in the book "The Data
* Compression Book" by Mark Nelson, ISBN 1-55851-434-1
*
*/
//#include <bitio.h> /* Data IO functions */
//#include <aptypes.h> /* MISRA type definitions */
#include <lzss_decomp.h>
//#include <stdint.h>
#include <string.h>
/*
*-------------------------------------------------------------------------------
*2 DEFINITIONS
*-------------------------------------------------------------------------------
*/
static uint16 EnqueueCompData(const uint8 *data, uint16 len);

static int DequeueCompByte(void);

static int ReadBit(void);

static int ReadBits(uint8 numberofBits);

static void OutputBuffer_Pack(void);

static int OutputByteToBuf(uint8 byte);

static void DecompressChunk(void);


static int End_ReadBits(void);
/*
*-------------------------------------------------------------------------------
*2.1 Constants
*-------------------------------------------------------------------------------
*/
/*
* Number of bits allocated to indices into the text window
*/
#define LZSS_INDEX_BIT_COUNT (uint8)10
/*
* Number of bits allocated for the length of an encode phrase
*/
#define LZSS_LENGTH_BIT_COUNT (uint8)4
/*
* Size of the sliding window
*/
#define LZSS_WINDOW_SIZE (uint16)( 1 << LZSS_INDEX_BIT_COUNT )
/*
* Number of bytes to encode a byte array.
* Used to calculate if compression should be done or not
*/
#define LZSS_BREAK_EVEN (uint8)( ( 1 + LZSS_INDEX_BIT_COUNT + \
                                LZSS_LENGTH_BIT_COUNT ) / 9 )
/*
* End of stream indicator
*/
#define LZSS_END_OF_STREAM (uint8)0
/*
*-------------------------------------------------------------------------------
*2.2 Variables
*-------------------------------------------------------------------------------
*/
/*
* The sliding window used by the decompression algorithm
*/
uint8 LZSS_decomp_window[ LZSS_WINDOW_SIZE ];

/** Current window position */
uint16 winPos = 1;

/*
*-------------------------------------------------------------------------------
*2.3 Macros
*-------------------------------------------------------------------------------
*/
/*
* Arithmetic modulo to get the correct index in the sliding window
*/
#define LZSS_MOD_WINDOW( a ) (uint16)( ( a ) & \
                            ( LZSS_WINDOW_SIZE - 1 ) )

/*
*-------------------------------------------------------------------------------
*2.4 
*-------------------------------------------------------------------------------
*/
#define LZSS_LOOK_AHEAD_SIZE         17

#define COMP_QUEUE_SIZE         (4096 + 256)
static uint8 comp_queue[COMP_QUEUE_SIZE];
static uint16 comp_rd = 0;
static uint16 comp_wr = 0;
static uint16 comp_count = 0;

static struct{
    uint8 bitBuf;
    sint8 bitsLeft;
} br;

#define OUT_BUF_SIZE            4096
static uint8 out_buf[OUT_BUF_SIZE + 16];
static uint16 out_wr = 0;
static uint16 out_rd = 0;

static uint8 stream_ended = 0;



static struct{
    uint8 bitBuf;
    sint8 bitsLeft;
} End_br;
/*
*-------------------------------------------------------------------------------
*3 GLOBAL FUNCTIONS
*-------------------------------------------------------------------------------
*/
static uint16 EnqueueCompData(const uint8 *data, uint16 len)
{
    uint16 space = COMP_QUEUE_SIZE - comp_count;
    uint16 to_write = (len > space) ? space : len;
    for(uint16 i = 0; i < to_write; i++)
    {
        comp_queue[comp_wr] = data[i];
        comp_wr = (comp_wr + 1) % COMP_QUEUE_SIZE;
    }
    comp_count += to_write;
    return to_write;
}

static int DequeueCompByte(void)
{
    if(comp_count == 0)
    {
        return -1;
    }
    uint8 byte = comp_queue[comp_rd];
    comp_rd = (comp_rd + 1) % COMP_QUEUE_SIZE;
    comp_count--;
    return byte;
}

static int ReadBit(void)
{
    if(br.bitsLeft == 0)
    {
        int byte = DequeueCompByte();
        if(byte < 0)
        {
            return -1;
        }
        br.bitBuf = (uint8)byte;
        br.bitsLeft = 8;
    }
    int bit = (br.bitBuf >> (br.bitsLeft - 1)) & 1;
    br.bitsLeft--;
    return bit;
}

static int ReadBits(uint8 numberofBits)
{
    uint32 value = 0;
    for(uint8 i = 0; i < numberofBits; i++)
    {
        int bit = ReadBit();
        if(bit < 0)
        {
            return -1;
        }
        value = (value << 1) | bit;
    }
    return (int)value;
}

static int End_ReadBits(void)
{
    uint32 value = 0;
	uint16 end_comp_rd = comp_rd;
	uint16 end_comp_count = comp_count;
	End_br.bitBuf = br.bitBuf;
	End_br.bitsLeft = br.bitsLeft;
	
    for(uint8 i = 0; i < 10; i++)
    {
        int bit;
		if(End_br.bitsLeft == 0)
		{		
			if(end_comp_count == 0)
			{
				return -1;
			}
			uint8 byte_1 = comp_queue[end_comp_rd];
			end_comp_rd = (end_comp_rd + 1) % COMP_QUEUE_SIZE;
			end_comp_count--;
			
			End_br.bitBuf = (uint8)byte_1;
			End_br.bitsLeft = 8;
		}
		bit = (End_br.bitBuf >> (End_br.bitsLeft - 1)) & 1;
		End_br.bitsLeft--;
		
        value = (value << 1) | bit;
    }
    return (int)value;
}

static void OutputBuffer_Pack(void)
{
    if(out_rd > 0)
    {
        uint16 len = out_wr - out_rd;
        if(len > 0)
        {
            memmove(out_buf, &out_buf[out_rd], len);
        }
        out_wr = len;
        out_rd = 0;
    }
}

static int OutputByteToBuf(uint8 byte)
{
    if(out_wr >= 4113)
    {
        OutputBuffer_Pack();
        if(out_wr >= 4113)
        {
            return 0;
        }
    }
    out_buf[out_wr++] = byte;
    return 1;
}

static void DecompressChunk(void)
{
    while ( !stream_ended )
    {
        if(4113 - out_wr <= LZSS_LOOK_AHEAD_SIZE)
        {
            OutputBuffer_Pack();
            if(4113 - out_wr <= LZSS_LOOK_AHEAD_SIZE)
            {
                break;
            }
        }
        int flag = ReadBit();
        if(flag < 0)
        {
            break;
        }      

		if(comp_count == 1)
		{
			if(flag == 0)
			{
				if(br.bitsLeft < 6)
				{
				  	if(br.bitsLeft < 2)
					{
					  	br.bitsLeft++;
						break;
					}
					else
					{
					  	int end_matchPos = End_ReadBits();
						if(end_matchPos == LZSS_END_OF_STREAM)
						{
							stream_ended = 1;
							break;
						}
						else
						{
							br.bitsLeft++;
							break;
						}
					}
				}
			}
		}
		else if(comp_count == 0)
		{
		  	br.bitsLeft++;
			break;
		}
		
        if(flag == 1)
        {
            int byte = ReadBits(8);
            if(byte < 0)
            {
                break;
            }
            OutputByteToBuf((uint8)byte);
            LZSS_decomp_window[winPos] = (uint8)byte;
            winPos = (winPos + 1) & (LZSS_WINDOW_SIZE - 1);
        }
        else
        {
            int matchPos = ReadBits(LZSS_INDEX_BIT_COUNT);
            if(matchPos < 0)
            {
                break;
            }
            if(matchPos == LZSS_END_OF_STREAM)
            {
                stream_ended = 1;
                break;
            }
            int matchLenCode = ReadBits(LZSS_LENGTH_BIT_COUNT);
            if(matchLenCode < 0)
            {
                break;
            }    
            uint8 matchLen = (uint8)matchLenCode + (LZSS_BREAK_EVEN + 1); 
            for(uint8 i = 0; i < matchLen; i++)
            {
                uint8 byte = LZSS_decomp_window[(matchPos + i) & (LZSS_WINDOW_SIZE - 1)];
                if(!OutputByteToBuf(byte))
                {
                    break;
                }
                LZSS_decomp_window[ winPos ] = byte;
                winPos = (winPos + 1) & (LZSS_WINDOW_SIZE - 1);
            }
        }
    }
}

/*
*-------------------------------------------------------------------------------
* 3.1 LZSS_ExpandData
*-------------------------------------------------------------------------------
*/
InjectStatus LZSS_InjectCompressedData(const uint8 *data, uint16 len)
{
    if(stream_ended)
    {
        return INJECT_STREAM_ALREADY_ENDED;
    }
    if(EnqueueCompData(data, len) != len)
    {
        return INJECT_QUEUE_FULL;
    }
	OutputBuffer_Pack();
    DecompressChunk();
    return INJECT_OK;
}

void LZSS_GetDecompressedData(uint8 **outData, uint16 *outlen, LZSS_GetStatus *status)
{
    uint16 avail = out_wr - out_rd;

    if(avail == 0)
    {
        *outlen = 0;
        *outData = NULL_PTR;
        if(stream_ended)
        {
            *status = LZSS_GET_END_OF_STREAM;
        }
        else
        {
            *status = LZSS_GET_FAIL_NOT_ENOUGH;
        }
        return;
    }

    uint16 take = (avail >= OUT_BUF_SIZE) ? OUT_BUF_SIZE : avail;
    *outData = &out_buf[out_rd];
    *outlen = take; 

    out_rd += take;

    if(stream_ended && (out_wr - out_rd) == 0)
    {
        *status = LZSS_GET_END_OF_STREAM;
    }
    else if(take == OUT_BUF_SIZE)
    {
        *status = LZSS_GET_SUCCESS_MORE;
    }
    else
    {
        *status = LZSS_GET_FAIL_NOT_ENOUGH;
    }
}

void LZSS_ContinueDecompress(LZSS_GetStatus *status)
{
    OutputBuffer_Pack();
    if(!stream_ended)
    {
        DecompressChunk();
    }

    uint16 avail = out_wr - out_rd;
    if(stream_ended && avail == 0)
    {
        *status = LZSS_GET_END_OF_STREAM;
    }
    else if((avail >= OUT_BUF_SIZE) || (stream_ended == 1))
    {
        *status = LZSS_GET_SUCCESS_MORE;
    }
    else
    {
        *status = LZSS_GET_FAIL_NOT_ENOUGH;
    }
}

void LZSS_Reset(void)
{
    comp_rd = 0;
    comp_wr = 0;
    comp_count = 0;
    
    br.bitBuf = 0;
    br.bitsLeft = 0;
    
    memset(LZSS_decomp_window, 0, sizeof(LZSS_decomp_window));
    winPos = 1;
    
    out_rd = 0;
    out_wr = 0;
    
    stream_ended = 0;
}
/*
*-------------------------------------------------------------------------------
* End of file
*-------------------------------------------------------------------------------
*/