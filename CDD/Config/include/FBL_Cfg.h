
#ifndef FBL_CFG_H
#define FBL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

/* Add code here */
#include "std_types.h"

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/


/* @type:uint32 range:0x0000C000~0xFFFFFFFF note:NONE */
#define FBL_BM_SOFTWARE_ADDR    	   0x00020000U   //�߼���ַ�������ַ��64k
/* @type:uint32 range:NONE note:auto generate */
#define FBL_EEPROM_INFO_ADDRESS        0x00018000U
#define FBL_EEPROM_INFO_LENGTH         0x00002000U

/* A fixed starting address of driving    */
#define FLASH_DRIVE_ADDRESS            0x20007B00U  //��fls����
/* According to the driver size change, the length of the drive   */
#define FLASH_DRIVE_LENGTH             0x00000400U
/* According to the change of the sector, the length of a erase is indicated  */
#define FLASH_ERASE_LENGTH             0x00000400U

/* The largest number of segments  */
#define SEGMENT_MAX                    2U
/* Number of blocks   */
#define LOGICAL_MAX                    2U
/* Use the enhanced check mode on-off  */
#define FBL_USE_ENHANCED_CHECK  		STD_OFF

#define FBL_USE_DEPEND_CHECK         	STD_ON

#define DataLength_DcmDspData_0xF198       0x13U
//#define DataLength_DcmDspData_0xF199       0x3U

typedef uint32 FBL_AddressType;
/* type for Flash read Length */
typedef uint32 FBL_LengthType;

/* The memory division of the app in the flash space  */
typedef struct
{
	/* data block address */
	FBL_AddressType DataBlddress;
	/* data block Length  */
	FBL_LengthType  DataBlLength;
}FBL_ProgramBlInfoType;


/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

extern const FBL_ProgramBlInfoType  FBL_ProgramBlInfo[LOGICAL_MAX];

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /* xxx_H */
/** @} */
