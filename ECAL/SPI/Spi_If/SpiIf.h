/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SpiIf.h                                                                  */
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
/* ************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                         					  */
/*   Type         :      H source file                                       					  */
/*   Name         :      SpiIf.h                                                                  */
/*   Instance     :     					  					  					  			  */
/*   Author       :       Chang Shicheng			  					  					  	  */
/*   Creation date:       					  					  					  			  */
/*   Description  :   					  					  					  			      */
/*                                                                                                */
/*                          			  					  					  			      */
/* 	 Compiler    : 		 ChipON KungFu IDE  [Version: V1.0.19.6]                              	  */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQT]                        */
/*   Version     :       V1.0	                                                                  */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/* ************************************************************************************************/


#ifndef SPI_IF_H_
#define SPI_IF_H_

extern void SPI_IF_Init(void);
extern void SPI_IF_DeInit(void);
extern uint8_t SpiIf_SpiReadWrite_aByte(SPI_ConfigList_Index SpiIndex,uint8_t Send);
extern void SpiIf_Spi_Device_Nss_Set(SPI_ConfigList_CS_Index opIndex,uint8_t SetVal);




#endif /* SPI_IF_H_ */
