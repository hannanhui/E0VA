#include "Action.h"
#include "m_flash_drv.h"
void NvM_ReadAll_Action()
{

}
uint8 data[10]={0x6,0x54,0x7,0x4,0x7,0x18};
uint8 Data[10]={0};
uint8 data1[10]={0x1,0x2,0x3,0x4,0x7,0x19};
uint8 Data1[10]={0};
uint8 data2[10]={0x6,0x45,0x2,0x9,0x8,0x18};
uint8 Data2[10]={0};
uint8 data3[10]={0x10,0x23,0x5,0x4,0x7,0x18};
uint8 Data3[10]={0};
uint8 data4[10]={0x5,0x4,0x3,0x1,0x7,0x18};
uint8 Data4[10]={0};
uint8 len;

void Memory_All_Init()
{
	   Fls_Init(&Fls_Config);
	   FLASH_Init();	
	   Eep_Init();

}

void Communication_All_Init()
{

	LinIf_Wakeup(0);	
	LinIf_Init(&LinIf_Config);
	LinTp_Init(&LinTp_Config);
	PduR_Init(&PduR_Config);
	ComM_Init(&ComM_Config);
	Com_Init(&Com_Config);

}

void Callout_Action()
{

}