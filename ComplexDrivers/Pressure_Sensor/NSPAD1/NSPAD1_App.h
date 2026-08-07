/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      NSPAD1_App.h                                                             */
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

#ifndef __NSPAD1_APP_H__
#define __NSPAD1_APP_H__


typedef struct {
	uint8_t 				m_Nspad1xEn;
	uint8_t 				Nspad1xInitFlag;
	uint32_t 				Drv_Spi_Baudrate;
	SPI_ConfigList_Index    Drv_Spi_Index;
	SPI_ConfigList_CS_Index Spi_Cs_Index;
	uint32_t 				NSPAD1_Pressure;
	uint8_t Nspad1_ReadStatus;
} P_Sensor_Nspad1_str_t;

typedef enum{
	SENSOR_START_CONVERSION = 0,
	SENSOR_READ_DATA,


}SENSOR_RUN_STATUS;
extern void NSPAD1_App_Init(void);
extern void NSPAD1_App_Register_Init(void);
extern void NSPAD1_App_Register2_Init(void);
extern void NSPAD1_App_DeInit(void);
extern BOOL NSPAD1_App_PressureGet(P_SENSOR_NSPAD1_INDEX opIndex,uint32_t* Pressure);
extern BOOL NSPAD1_App_TemperatureGet(P_SENSOR_NSPAD1_INDEX opIndex,int16_t* Temperature);


#endif /* __SMP580_APP_H__ */
