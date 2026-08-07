/**
* @file        Com_Cfg.h
* @brief       Implementation for Com
* @version     1.2.0
* @addtogroup  Com
* @{
*/

/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifndef  COM_CFG_H
#define  COM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define COM_CFG_VENDOR_ID                       0U
#define COM_CFG_AR_RELEASE_MAJOR_VERSION        4U
#define COM_CFG_AR_RELEASE_MINOR_VERSION        2U
#define COM_CFG_AR_RELEASE_REVISION_VERSION     2U
#define COM_CFG_SW_MAJOR_VERSION                1U
#define COM_CFG_SW_MINOR_VERSION                2U
#define COM_CFG_SW_PATCH_VERSION                0U
/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/
#define COM_CONF_PB extern const Com_ConfigType Com_Config;

#define COM_CANCELLATION_SUPPORT                         STD_OFF
#define COM_DEV_ERROR_DETECT                             STD_OFF
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API                STD_OFF
#define COM_VERSION_INFO_API                             STD_OFF
#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION           STD_ON
#define COM_METADATA_SUPPORT                             STD_OFF
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS               STD_OFF

#define COM_NUMBER_OF_IPDUGROUP                        0u

/**
* @brief receive Pdu
*/
#define COM_NUMBER_OF_RXIPDU                    2
#define ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_1_Rx      0  
#define ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_2_Rx      1  

/**
* @brief send Pdu
*/
#define COM_NUMBER_OF_TXIPDU                    1
#define ComConf_ComIPdu_LinPdu_ComToPduR_DSMM_1_Tx      2  

#define COM_LENGTH_OF_RXIPDUBUFFER              16
#define COM_LENGTH_OF_TXIPDUBUFFER              8

#define COM_NUMBER_OF_BOOLSIGNAL                10
#define COM_NUMBER_OF_RXGROUPBOOLSIGNAL         0
#define COM_NUMBER_OF_NVALID_BOOLSIGNAL         0

#define COM_NUMBER_OF_8BITSIGNAL                18
#define COM_NUMBER_OF_RXGROUP8BITSIGNAL         0
#define COM_NUMBER_OF_NVALID_8BITSIGNAL         0

#define COM_NUMBER_OF_16BITSIGNAL               0
#define COM_NUMBER_OF_RXGROUP16BITSIGNAL        0
#define COM_NUMBER_OF_NVALID_16BITSIGNAL        0

#define COM_NUMBER_OF_32BITSIGNAL               0
#define COM_NUMBER_OF_RXGROUP32BITSIGNAL        0
#define COM_NUMBER_OF_NVALID_32BITSIGNAL        0

#define COM_NUMBER_OF_64BITSIGNAL               0
#define COM_NUMBER_OF_RXGROUP64BITSIGNAL        0
#define COM_NUMBER_OF_NVALID_64BITSIGNAL        0

#define COM_TMCTXSIGNAL_NUMBER                  0
#define COM_TMCTXGROUPSIGNAL_NUMBER             0

#define COM_NUMBER_OF_TIMEOUT_SIGNAL            0

#define COM_NUMBER_OF_TXSIGNALGROUP             0

#define COM_NUMBER_OF_RXSIGNALGROUP 			0

#define COM_NUMBER_OF_TXSIGNAL                  21
#define ComConf_ComSignal_SoftwareVersion_Tx            0
#define ComConf_ComSignal_HardwareVersion_Tx            1
#define ComConf_ComSignal_DriveSeatMsgStr_Lvlsts_Tx            2
#define ComConf_ComSignal_DriverSeatMsg_ModeSts_Tx            3
#define ComConf_ComSignal_DSMM_Rsp_Error_Tx            4
#define ComConf_ComSignal_DrvLumSpprtSwtFct_Tx            5
#define ComConf_ComSignal_DrvSeatLeSideBolsterFltSt_Tx            6
#define ComConf_ComSignal_DrvSeatRiSideBolsterFltSt_Tx            7
#define ComConf_ComSignal_DrvSeatLeSideBolsterNTCOverT_Tx            8
#define ComConf_ComSignal_DrvSeatRiSideBolsterNTCOverT_Tx            9
#define ComConf_ComSignal_DrvSeatMainAirwayPSnsrFlt_Tx            10
#define ComConf_ComSignal_DrvSeatLeSideBolsterPSnsrFlt_Tx            11
#define ComConf_ComSignal_DrvSeatRiSideBolsterPSnsrFlt_Tx            12
#define ComConf_ComSignal_AirPotPressure_Tx            13
#define ComConf_ComSignal_AirPotPressureSnsFlt_Tx            14
#define ComConf_ComSignal_VoltageState_Tx            15
#define ComConf_ComSignal_PumFlt_Tx            16
#define ComConf_ComSignal_ValveFlt_Tx            17
#define ComConf_ComSignal_EnvPressureSnsFlt_Tx            18
#define ComConf_ComSignal_DrvSeatLeSidBolsterInflatuinSts_Tx            19
#define ComConf_ComSignal_DrvSeatRiSideBolsterInflationSts_Tx            20

#define COM_NUMBER_OF_RXSIGNAL                  7
#define ComConf_ComSignal_FuelVehPowerMode_Rx            0
#define ComConf_ComSignal_DriverSeatMsgStr_Lvlcmd_Rx            1
#define ComConf_ComSignal_DriveSeatMsg_ModeCmd_Rx            2
#define ComConf_ComSignal_PowerMode_Rx            3
#define ComConf_ComSignal_APC_Level_Limit_Rx            4
#define ComConf_ComSignal_DrvSeatLeSideBolsterInflationReq_Rx            5
#define ComConf_ComSignal_DrvSeatRisSideBolsterInflationReq_Rx            6

#define COM_NUMBER_OF_TXGROUPSIGNAL             0

#define COM_NUMBER_OF_RXGROUPSIGNAL             0

#define COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL 	        0
#define COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL 	        0
#define COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL       0

#define COM_LENGTH_OF_GWBOOLSIGNALBUFFER        0
#define COM_LENGTH_OF_GW8BITSIGNALBUFFER        0
#define COM_LENGTH_OF_GW16BITSIGNALBUFFER       0
#define COM_LENGTH_OF_GW32BITSIGNALBUFFER       0
#define COM_LENGTH_OF_GW64BITSIGNALBUFFER       0

#define COM_NUMBER_OF_GWMAPPING                 0
#define COM_NUMBER_OF_SOURCE_SIGNAL             0
#define COM_NUMBER_OF_DEST_SIGNAL               0


/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* COM_CFG_H */
/** @} */


