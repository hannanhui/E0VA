

#ifndef __LIN_PHY_H__
#define __LIN_PHY_H__





#define PRIVATELIN_LPUART_CHL_BASE  

#define PRIVATELIN_LPUART_CHL_INT_BASE 

enum LIN_Status
{
    LIN_INITIAL = 0,
    LIN_RECVING,
    LIN_END
};

extern void Private_Lin_Phy_Master_Recv(uint8_t *Recv_Buf, uint8_t Msg_Len);
extern void Private_Lin_Phy_Master_Send(uint8_t SlaveID, uint8_t *Databuf, uint32_t Length);
extern void Private_Lin_Phy_Master_Send_Head( uint8_t SlaveID);
extern uint8_t Private_Lin_GetParityValue(uint32_t u32id);
extern uint8_t Private_Lin_GetEnhanceCheckSumValue(uint8_t Pid, uint8_t* Data, uint8_t Len);

extern void Private_Lin_Phy_Init(void);

extern void Private_DMA_Handler(void);
extern void Private_LIN_USART_Handler(void);
uint8_t Private_Lin_Phy_RxStatusGet(void);
extern void Private_Lin_Phy_RxStatusSet(uint8_t opStatus);


#endif /* __LIN_PHY_H__ */
