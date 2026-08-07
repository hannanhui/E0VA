
/*****************************************************************************************************************************
*
* 文件名称：LIN_Phy.c
* 文件描述：LIN 硬件层实现
* 开发环境：KungFu32 IDE  V1.0.19.1
* 编译器  ： 自带
* 注意事项：无
*
*****************************************************************************************************************************/

#include "include.h"

#define LIN_M_RXTXBUF_LEN 16
#define USART_M_TX_DATA_SIZE 11
//#define USART_M_RX_DMA_CHANNAL

volatile uint8_t LIN_M_RxBuffer[LIN_M_RXTXBUF_LEN] = {0,0,0,0,0,0,0,0,0};
static uint8_t LIN_M_TxBuffer[USART_M_TX_DATA_SIZE] = {0};

uint8_t LIN_M_RxIndex = 0;
uint8_t LIN_M_TxIndex = 0;
uint8_t LIN_M_Status = LIN_INITIAL;

uint8_t Private_Lin_GetParityValue(uint32_t u32id)
{
    uint32_t u32Res = 0u, ID[6], p_Bit[2], mask = 0u;

    /* Store ID in ID[0:5] */
    for (mask = 0u; mask < 6u; mask++)
    {
        ID[mask] = (u32id & (1 << mask)) >> mask;
    }
    /* ID6 (p_Bit[0]) is the odd parity of ID0, ID1, ID2, and ID4
        ID7(p_Bit[1]) is the even parity of ID1, ID3, ID4, ID5 */
    p_Bit[0] = (ID[0] + ID[1] + ID[2] + ID[4]) % 2u;
    p_Bit[1] = (!((ID[1] + ID[3] + ID[4] + ID[5]) % 2u));
    /* Get the ID domain value u32Res
    (the first 6 bits are ID, and the upper two bits are parity bits) */
    u32Res = u32id + (p_Bit[0] << 6u) + (p_Bit[1] << 7u);
    /* Return ID filed value */
    return u32Res;
}
uint8_t Private_Lin_GetEnhanceCheckSumValue(uint8_t Pid, uint8_t* Data, uint8_t Len)
{
	uint8_t  i;
	uint16_t CheckSum = Pid;

	for(i=0; i<Len; i++)
	{
		CheckSum += Data[i];

		if (CheckSum >= 0x100)
		{
			CheckSum &= 0x00FF;
			CheckSum += 1;
		}
	}

	CheckSum ^= 0xFF;		// 取反

	return (uint8_t)CheckSum;
}

uint8_t Private_Lin_Phy_RxStatusGet(void)
{
	return LIN_M_Status;
}
void Private_Lin_Phy_RxStatusSet(uint8_t opStatus)
{
	LIN_M_Status = opStatus;
}


void Private_Lin_Phy_Master_Recv(uint8_t *Recv_Buf, uint8_t Msg_Len)
{
	
}
void Private_Lin_Phy_Master_Send(uint8_t SlaveID, uint8_t *Databuf, uint32_t Length)
{

}

void Private_Lin_Phy_Master_Send_Head( uint8_t SlaveID)
{

}

void Private_Lin_Phy_Init(void)
{

}

