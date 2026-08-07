/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Flash_Cfg.h                                                              */
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
#ifndef _FLASH_CFG_H_
#define _FLASH_CFG_H_


#define BUFFERS_AUTO_ALIGN_ENABLE   1


/** @defgroup FLASHEx_Page_Size FLASHEx Page Size
* @{
*/
#define FLASH_PAGE_SIZE          FLASH_ONE_SECTOR_SIZE
/**
* @}
*/


/* Exported constants --------------------------------------------------------*/
/* Base address of the Flash sectors */
#define ADDR_DATA_FLASH_SECTOR_0    ((uint32_t)0x101A000) /* Base @ of sector 0, 512 bytes */
#define ADDR_DATA_FLASH_SECTOR_1    ((uint32_t)0x101C000) /* Base @ of sector 1, 512 bytes */
#define ADDR_DATA_FLASH_SECTOR_2    ((uint32_t)0x101E000) /* Base @ of sector 2, 512 bytes */

#define ADDR_DATA_FLASH_FLS_SECTOR_0    ((uint32_t)0x001A000) /* Base @ of sector 0, 512 bytes */
#define ADDR_DATA_FLASH_FLS_SECTOR_1    ((uint32_t)0x001C000) /* Base @ of sector 1, 512 bytes */
#define ADDR_DATA_FLASH_FLS_SECTOR_2    ((uint32_t)0x001E000) /* Base @ of sector 2, 512 bytes */



#define BOOT_MODE_FLAG     0X5AA5AA55		//Data is asymmetrical, preventing  error between big-endian and little-endian about byte order
#define APP_MODE_FLAG      0XC66CCC66		//Data is asymmetrical, preventing  error between big-endian and little-endian about byte order

#define UPDATE_FLAG_BASE_ADDRESS	ADDR_DATA_FLASH_FLS_SECTOR_0


/* Define the size of the sectors to be used */
#define PAGE_SIZE               (uint32_t)FLASH_PAGE_SIZE  /* Page size */



#endif /* _FLASH_CFG_H_ */
