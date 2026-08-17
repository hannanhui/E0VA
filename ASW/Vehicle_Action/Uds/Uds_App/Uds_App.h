/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Uds_App.h                                                                */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#ifndef INCLUDE_UDS_APP_H_
#define INCLUDE_UDS_APP_H_
#include "model_feature.h"
#if UPGRADE_MODE == UPGRADE_MODE_FOR_UDS_LIN



#define AES_SEED_LEN 2
/*uds negative value define*/
#define NEGTIVE_ID (0x7Fu)
#define	SNS (0x11u)          /*service not support*/
#define	SFNS (0x12u)        /*subfunction not support*/
#define	IMLOIF (0x13u)       /*incorrect message length or invalid format*/
#define	BRR (0x21u)          /*busy repeat request*/
#define	CNC (0x22u)          /*conditions not correct*/
#define	RSE (0x24u)          /*request 	sequence error*/
#define	ROOR (0x31u)         /*request out of range*/
#define	SAD (0x33u)          /*security access denied*/
#define	IK (0x35u)           /*invalid key*/
#define	ENOA (0x36u)         /*exceed number of attempts*/
#define	NEGTIVEPE   0x72
#define	BNE   0x73			/*Block number err*/

#define	RCRRP (0x78u)        /*request correctly received-response pending*/

/*define session mode*/
#define DEFALUT_SESSION (1u << 0u)       /*default session*/
#define PROGRAM_SESSION (1u << 1u)       /*program session*/
#define EXTEND_SESSION (1u << 2u)        /*extend session*/

/*security request*/
#define NONE_SECURITY (1u << 0u)                          /*none security can request*/
#define SECURITY_LEVEL_1 ((1 << 1u) | NONE_SECURITY)      /*security level 1 request*/
#define SECURITY_LEVEL_2 ((1u << 2u) | SECURITY_LEVEL_1)  /*security level 2 request*/

#define DOWLOAD_DATA_ADDR_LEN (4u)      /*dowload data addr len*/
#define DOWLOAD_DATA_LEN (4u)           /*dowload data len*/

/*support function/physical ID request*/
#define ERRO_REQUEST_ID (0u)             /*received ID failled*/
#define SUPPORT_PHYSICAL_ADDR (1u << 0u) /*support physical ID request */
#define SUPPORT_FUNCTION_ADDR (1u << 1u)  /*support function ID request*/


#define DID_ECUHardwareVersionNumberDataIdentifier       0xF193
#define DID_ECUSoftwareVersionNumberDataIdentifier       0xF195

#define DID_BootSoftwareIdentification             0xF180  
#define DID_ECUSoftwareNumberIdentifier            0xF194  



typedef enum
{
    ERASE_MEMORY_ROUTINE_CONTROL,       /*check erase memory routine control*/
	STOP_ROUTINE_CONTROL,       /*check erase memory routine control*/	
    CHECK_SUM_ROUTINE_CONTROL,          /*check sum routine control*/
    ERASE_MEMORY_ROUTINE_RESULTS,       /*check erase memory routine control*/
    CHECK_SUM_ROUTINE_RESULTS,          /*check sum routine control*/

} tCheckRoutineCtlInfo;

typedef struct
{
    tUdsId xUdsId;
    tUdsLen xDataLen;
    uint8_t aDataResverd;
    uint8_t aDataResverd1;//aDataBuf[0] is Func Id  aDataBuf[1] is Pack Number Flash need 4byte align
    uint8_t aDataBuf[MAX_DATA_LEN];
    /*tx message call back*/
    void (*pfUDSTxMsgServiceCallBack)(uint8_t);
} tUdsAppMsgInfo;

typedef struct UDSServiceInfo
{
    uint8_t SerNum;     /*service num. eg 0x3e/0x87...*/
    uint8_t SessionMode;/*default session / program session / extend session*/
    uint8_t SupReqMode; /*support physical / function addr*/
    uint8_t ReqLevel;   /*request level.Lock/unlock*/
    void (*pfSerNameFun)(struct UDSServiceInfo*, tUdsAppMsgInfo *);//根据UDSServiceInfo解析将需要回应的信息装入tUdsAppMsgInfo
} tUDSService;

typedef struct
{
    uint32_t StartAddr;         /*data start address*/
	uint32_t DataWrite_Size;
    uint32_t DataLen;           /*data len*/
} tDowloadDataInfo;

extern void UDS_MainFun(void);
extern void UDS_SystemTickCtl(void);
extern void Uds_SetApp_Erase_Flag(void);
extern void Uds_SetApp_CheckMemory_Flag(void);
#endif
#endif /* INCLUDE_UDS_APP_H_ */
