/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Common.c                                                                 */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/

#include "Common.h"
#define COMMON_C__
/**** The following table is the common ccitt 16, generated 1021 query form, the top of the front ****/

const uint16_t crc16_ccitt_table[256]=
{             
    0x0000U, 0x1021U, 0x2042U, 0x3063U, 0x4084U, 0x50a5U, 0x60c6U, 0x70e7U,
    0x8108U, 0x9129U, 0xa14aU, 0xb16bU, 0xc18cU, 0xd1adU, 0xe1ceU, 0xf1efU,
    0x1231U, 0x0210U, 0x3273U, 0x2252U, 0x52b5U, 0x4294U, 0x72f7U, 0x62d6U,
    0x9339U, 0x8318U, 0xb37bU, 0xa35aU, 0xd3bdU, 0xc39cU, 0xf3ffU, 0xe3deU,
    0x2462U, 0x3443U, 0x0420U, 0x1401U, 0x64e6U, 0x74c7U, 0x44a4U, 0x5485U,
    0xa56aU, 0xb54bU, 0x8528U, 0x9509U, 0xe5eeU, 0xf5cfU, 0xc5acU, 0xd58dU,
    0x3653U, 0x2672U, 0x1611U, 0x0630U, 0x76d7U, 0x66f6U, 0x5695U, 0x46b4U,
    0xb75bU, 0xa77aU, 0x9719U, 0x8738U, 0xf7dfU, 0xe7feU, 0xd79dU, 0xc7bcU,
    0x48c4U, 0x58e5U, 0x6886U, 0x78a7U, 0x0840U, 0x1861U, 0x2802U, 0x3823U,
    0xc9ccU, 0xd9edU, 0xe98eU, 0xf9afU, 0x8948U, 0x9969U, 0xa90aU, 0xb92bU,
    0x5af5U, 0x4ad4U, 0x7ab7U, 0x6a96U, 0x1a71U, 0x0a50U, 0x3a33U, 0x2a12U,
    0xdbfdU, 0xcbdcU, 0xfbbfU, 0xeb9eU, 0x9b79U, 0x8b58U, 0xbb3bU, 0xab1aU,
    0x6ca6U, 0x7c87U, 0x4ce4U, 0x5cc5U, 0x2c22U, 0x3c03U, 0x0c60U, 0x1c41U,
    0xedaeU, 0xfd8fU, 0xcdecU, 0xddcdU, 0xad2aU, 0xbd0bU, 0x8d68U, 0x9d49U,
    0x7e97U, 0x6eb6U, 0x5ed5U, 0x4ef4U, 0x3e13U, 0x2e32U, 0x1e51U, 0x0e70U,
    0xff9fU, 0xefbeU, 0xdfddU, 0xcffcU, 0xbf1bU, 0xaf3aU, 0x9f59U, 0x8f78U,
    0x9188U, 0x81a9U, 0xb1caU, 0xa1ebU, 0xd10cU, 0xc12dU, 0xf14eU, 0xe16fU,
    0x1080U, 0x00a1U, 0x30c2U, 0x20e3U, 0x5004U, 0x4025U, 0x7046U, 0x6067U,
    0x83b9U, 0x9398U, 0xa3fbU, 0xb3daU, 0xc33dU, 0xd31cU, 0xe37fU, 0xf35eU,
    0x02b1U, 0x1290U, 0x22f3U, 0x32d2U, 0x4235U, 0x5214U, 0x6277U, 0x7256U,
    0xb5eaU, 0xa5cbU, 0x95a8U, 0x8589U, 0xf56eU, 0xe54fU, 0xd52cU, 0xc50dU,
    0x34e2U, 0x24c3U, 0x14a0U, 0x0481U, 0x7466U, 0x6447U, 0x5424U, 0x4405U,
    0xa7dbU, 0xb7faU, 0x8799U, 0x97b8U, 0xe75fU, 0xf77eU, 0xc71dU, 0xd73cU,
    0x26d3U, 0x36f2U, 0x0691U, 0x16b0U, 0x6657U, 0x7676U, 0x4615U, 0x5634U,
    0xd94cU, 0xc96dU, 0xf90eU, 0xe92fU, 0x99c8U, 0x89e9U, 0xb98aU, 0xa9abU,
    0x5844U, 0x4865U, 0x7806U, 0x6827U, 0x18c0U, 0x08e1U, 0x3882U, 0x28a3U,
    0xcb7dU, 0xdb5cU, 0xeb3fU, 0xfb1eU, 0x8bf9U, 0x9bd8U, 0xabbbU, 0xbb9aU,
    0x4a75U, 0x5a54U, 0x6a37U, 0x7a16U, 0x0af1U, 0x1ad0U, 0x2ab3U, 0x3a92U,
    0xfd2eU, 0xed0fU, 0xdd6cU, 0xcd4dU, 0xbdaaU, 0xad8bU, 0x9de8U, 0x8dc9U,
    0x7c26U, 0x6c07U, 0x5c64U, 0x4c45U, 0x3ca2U, 0x2c83U, 0x1ce0U, 0x0cc1U,
    0xef1fU, 0xff3eU, 0xcf5dU, 0xdf7cU, 0xaf9bU, 0xbfbaU, 0x8fd9U, 0x9ff8U,
    0x6e17U, 0x7e36U, 0x4e55U, 0x5e74U, 0x2e93U, 0x3eb2U, 0x0ed1U, 0x1ef0U
};
/* Lookup table to convert HEX to BCD */
const uint8 hex2bcd[100u] = 
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, /* 00-09 */
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, /* 10-19 */
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, /* 20-29 */
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, /* 30-39 */
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, /* 40-49 */
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, /* 50-59 */
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, /* 60-69 */
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, /* 70-79 */
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, /* 80-89 */
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, /* 90-99 */
};

uint8 Hex2Bcd(uint8 hex)
{
    if(hex<=99U)
    {
        return hex2bcd[hex];
    }
    else
    {
       return 0U;
    }
}



/**************************************************************************************************/
/* Function Name : CommCrcCout                                                                    */
/* Description   : crc16_ccittverification                                                        */
/* Inputs        :  *message��len(<=1024)                                                         */
/* Outputs       : crc_reg                                                                        */
/* Author		 :                                                                                */
/**************************************************************************************************/
uint16_t CommCrcCout(uint8_t *message, uint16_t len)
{
    uint16_t crc_reg=0x0000U;

    if (message != NULL) /* Prevents the input address from being empty */
    {
        if (len <= 1024) /* The length is limited for the limited MCU RAM, and the maximum processing length is 1k*/
    	{
            while (len>0)
            {
                crc_reg = (crc_reg << 8) ^ crc16_ccitt_table[((crc_reg>>8) ^ (*message)) & 0xFF];

				len--;
				message++;
            }
    	}
    }
    
    return crc_reg;
}

void Delay_us(void)
{
    uint8_t i;

    for(i=0U;i<32U;i++)
    {
       // NOP();
    }
}
/*
uint8 memcpy(uint8 to[], uint8 from[], uint16 size) //PRQA S 4603
{
    if((NULL == to) || (NULL == from))
    {
        return 0;
    }
    if(!((to >= (&from[size])) || (from >= (&to[size]))))
    {
        return 0;
    }
    while(size > 0u)
    {
        size--;
        to[size] = from[size];
    }
    return 1;
}

void memset(uint8 buff[],uint8 data,uint16 length) //PRQA S 4603
{
    uint16 i;
    
    for(i=0;i<length;i++)
    {
        buff[i] = data;
    }
}

int memcmp(uint8 *buf1,uint8 *buf2,uint16 count) //PRQA S 4603
{
    uint16 i=0;
    
    for(i=0; i<count; i++)
    {
        if(buf1[i] < buf2[i])
        {
            return -1;
        }
        else if(buf1[i] > buf2[i])
        {
            return 1;
        }
		else //PRQA S qac-10.1.0-2013
		{
			;
		}
    }
    return 0;
}
*/

uint8 ByteCmpAbs(uint8 buf1 ,uint8 buf2)
{
    uint8 temp=0;

    buf1 >= buf2 ? (temp=buf1-buf2) : (temp=buf2-buf1);

    return temp;
}

void SortU16FromMinToMax(uint16 * buf,uint8 size)
{
    uint8 i,j;
    uint16 temp=0u;
    
    for(j=0u;j<size;j++)
    {
        for(i=0u;i<size-j-1u;i++)
        {
            if(buf[i]>buf[i+1u])
            {
                temp=buf[i];
                buf[i]=buf[i+1u];
                buf[i+1u]=temp;
            }
        }
    }
}

void GetArrMaxAndMinVal(int arr[], int size, int* max, int* min)
{
    uint16 i = 0u;
    
    *max = arr[0u];
    for(i=0u;i<size;i++)
    {
        if(arr[i] > *max) //找出最大值
        {
            *max = arr[i];
        }
    }
    
    *min = arr[0u];
    for(i=0u;i<size;i++)
    {
        if(arr[i] < *max) //找出最小值
        {
            *min = arr[i];
        }
    }
}



