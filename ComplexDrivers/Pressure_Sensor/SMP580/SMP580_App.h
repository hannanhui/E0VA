/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SMP580_App.h                                                             */
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

#ifndef __SMP580_APP_H__
#define __SMP580_APP_H__


typedef struct {
	uint8_t 				m_Smp580xEn; 	
	uint8_t 				Smp580xInitFlag; 
	uint32_t 				Drv_Spi_Baudrate;
	SPI_ConfigList_Index    Drv_Spi_Index;
	SPI_ConfigList_CS_Index Spi_Cs_Index;
	SMP580_16BIT_VARIANT2 	SMP580_Id;
	uint32_t 				SMP580_Pressure;				 
	int16_t 				SMP580_Temperature;			 
} P_Sensor_Smp580_str_t;

extern void SMP580_App_Init(void);
extern void SMP580_App_DeInit(void);

extern BOOL SMP580_App_PressureGet(P_SENSOR_SMP580_INDEX opIndex,uint32_t* Pressure);
extern BOOL SMP580_App_TemperatureGet(P_SENSOR_SMP580_INDEX opIndex,int16_t* Temperature);
extern void SMP580_App_RunStatus_Manage(void);

#endif /* __SMP580_APP_H__ */
