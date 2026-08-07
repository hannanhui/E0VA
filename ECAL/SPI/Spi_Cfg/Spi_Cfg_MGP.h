/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Spi_Cfg_MGP.h                                                            */
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



#ifndef SPI_CFG_MGP_H_
#define SPI_CFG_MGP_H_

typedef enum
{
	SPI_ConfigList_SPI0 = 0,
	SPI_ConfigList_SPI1,	
	SPI_ConfigList_SPI2,
	SPI_ConfigList_SPI3,
	SPI_ConfigList_Num

}SPI_ConfigList_Index;

typedef enum
{
	SPI_ConfigList_CS0= 0,
	SPI_ConfigList_CS1,
	SPI_ConfigList_CS2,
	SPI_ConfigList_CS3,
	SPI_ConfigList_CS4,
	SPI_ConfigList_CS5,
	SPI_ConfigList_CS6,
	SPI_ConfigList_CS7,
	SPI_ConfigList_CS8,
	SPI_ConfigList_CS9,
	SPI_ConfigList_CS_MAX_NUM
}SPI_ConfigList_CS_Index;



#endif /* SPI_CFG_MGP_H_ */
