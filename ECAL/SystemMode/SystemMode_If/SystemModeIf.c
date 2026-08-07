/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      SystemModeIf.c                                                           */
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

#include "global_var.h"
#include "SystemModeIf.h"
//#include "Ecal_SystemMode.h"
//#include "WatchDogIf.h"
#include "Ecal_PORT.h"
//#include "Srmc_Drv_Types.h"


#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "Det.h"
#include "Port.h"
#include "Interrupt_Drv.h"
#if (WDG_DIRECT_SERVICE == STD_ON)

#include "Wdg.h"
#endif
#include "Srmc_Drv.h"
#include "Srmc_Drv_PBcfg.h"
#include "Parcc_Drv.h"
#include "Port_Drv.h"
#include "Dio.h"
//#if (defined(WAKEUP_INTERRUPT_HANDLER))
#include "Srmc_Drv_PBcfg.h"
//#endif


#include "Adc.h"

#include "Spi.h"

#if ((CAR_PUB_NET_COM_MEOD == NET_COM_CAN)||(CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN))

#include "Can.h"
#endif



#define UART_NUM_ALL     6U
#define PORT_TOTAL_NUM   5U
#define TIM_NUM_ALL      4U
#define CMU_NUM_ALL      3U
#define MCPWM_NUM_ALL    2U
#define TDG_NUM_ALL      2U

#if (defined(DEV_Z20K148M))
#define I2S_NUM_ALL      2U
#elif (defined(DEV_Z20K146M))
#define I2S_NUM_ALL      1U
#elif (defined(DEV_Z20K144M))
#define I2S_NUM_ALL      1U
#else
    #error "No valid CPU defined!"
#endif

uint8_t Sleep_Status=0u;

uint32_t SystemModeRstSrc =0u;


#define WAKEUP_INTERRUPT_HANDLER


/************************* Configuration Field Start *************************/


/*************************  Configuration Field End  *************************/

static Z20_SysTickType *const SysTickPtr = (Z20_SysTickType *) Z20_SYSTICK_BASE;
static Z20_SCBType *const SCBRegPtr = (Z20_SCBType *) Z20_SCB_BASE;
static Z20_FPUType *const FPURegPtr = (Z20_FPUType *) Z20_FPU_BASE;
static Reg_Cmp_WType *const cmpRegWPtr   = (Reg_Cmp_WType *) CMP_BASE_ADDR;
static Reg_Dma_WType *const dmaRegWPtr = (Reg_Dma_WType *) DMA_BASE_ADDR; 
static Reg_Pmu_WType *const pmuRegWPtr = (Reg_Pmu_WType *) PMU_BASE_ADDR;
static Reg_Pmu_BfType *const pmuRegPtr = (Reg_Pmu_BfType *) PMU_BASE_ADDR;
static Reg_Flash_WType *const flsRegWPtr  = (Reg_Flash_WType*) FLASHC_BASE_ADDR;
static Reg_Flash_BfType *const flsRegPtr  = (Reg_Flash_BfType*) FLASHC_BASE_ADDR;
static Reg_Srmc_WType *const  srmcRegWPtr = (Reg_Srmc_WType*) SRMC_BASE_ADDR;
static Reg_Stim_BfType *const stimRegPtr = (Reg_Stim_BfType *) STIM_BASE_ADDR;
static Reg_Wdog_WType * const wdogRegWPtr = (Reg_Wdog_WType *)WDOG_BASE_ADDR;
static Reg_Parcc_BfType *const parccRegPtr = (Reg_Parcc_BfType *) PARCC_BASE_ADDR;
static Reg_Rtc_BfType *const rtcRegPtr   = (Reg_Rtc_BfType *) RTC_BASE_ADDR;
static Reg_Rtc_WType *const rtcRegWPtr   = (Reg_Rtc_WType *) RTC_BASE_ADDR;
static Reg_Scc_BfType *const sccRegBfPtr = (Reg_Scc_BfType *)SCC_BASE_ADDR;
static Reg_Scc_WType *const sccRegWPtr = (Reg_Scc_WType *)SCC_BASE_ADDR;
static Reg_Seru_WType *const seruRegWPtr = (Reg_Seru_WType *)SERU_BASE_ADDR;
static Reg_Seru_BfType *const seruRegPtr = (Reg_Seru_BfType *)SERU_BASE_ADDR;
static Reg_Scm_BfType *const ScmRegPtr = (Reg_Scm_BfType*)SCM_BASE_ADDR;
extern const Srmc_Drv_PowerModeConfigType Srmc_Drv_PowerModeConfig;

static Reg_Port_WType * const portRegWPtr[PORT_TOTAL_NUM] =
{
    (Reg_Port_WType *)PORTA_BASE_ADDR, /*!< Port A base address */
    (Reg_Port_WType *)PORTB_BASE_ADDR, /*!< Port B base address */
    (Reg_Port_WType *)PORTC_BASE_ADDR, /*!< Port C base address */
    (Reg_Port_WType *)PORTD_BASE_ADDR, /*!< Port D base address */
    (Reg_Port_WType *)PORTE_BASE_ADDR  /*!< Port E base address */
};

static Reg_Port_BfType * const portRegPtr[PORT_TOTAL_NUM] =
{
    (Reg_Port_BfType *)PORTA_BASE_ADDR, /*!< Port A base address */
    (Reg_Port_BfType *)PORTB_BASE_ADDR, /*!< Port B base address */
    (Reg_Port_BfType *)PORTC_BASE_ADDR, /*!< Port C base address */
    (Reg_Port_BfType *)PORTD_BASE_ADDR, /*!< Port D base address */
    (Reg_Port_BfType *)PORTE_BASE_ADDR  /*!< Port E base address */
};

static Reg_Tim_BfType *const timRegPtr[TIM_NUM_ALL] = 
{
    (Reg_Tim_BfType *)TIM0_BASE_ADDR, 
    (Reg_Tim_BfType *)TIM1_BASE_ADDR,
    (Reg_Tim_BfType *)TIM2_BASE_ADDR,
    (Reg_Tim_BfType *)TIM3_BASE_ADDR
};

static Reg_Tdg_BfType * const tdgRegPtr[TDG_NUM_ALL] = 
{
    (Reg_Tdg_BfType *)TDG0_BASE_ADDR, 
    (Reg_Tdg_BfType *)TDG1_BASE_ADDR
};

static Reg_Tdg_WType * const tdgRegWPtr[TDG_NUM_ALL] = 
{
    (Reg_Tdg_WType *)TDG0_BASE_ADDR, 
    (Reg_Tdg_WType *)TDG1_BASE_ADDR
};

static Reg_I2s_WType *const i2sRegWPtr[I2S_NUM_ALL] = 
{
   (Reg_I2s_WType *)I2S0_BASE_ADDR
#if (defined(DEV_Z20K148M))
   ,(Reg_I2s_WType *)I2S1_BASE_ADDR
#endif
};

static Reg_Cmu_WType * const cmuRegWPtr[CMU_NUM_ALL] = 
{
    (Reg_Cmu_WType *)CMU0_BASE_ADDR,
    (Reg_Cmu_WType *)CMU1_BASE_ADDR,
    (Reg_Cmu_WType *)CMU2_BASE_ADDR
};

static Reg_Uart_WType *const uartRegPtr[UART_NUM_ALL] = 
{
    (Reg_Uart_WType *)UART0_BASE_ADDR,
    (Reg_Uart_WType *)UART1_BASE_ADDR,
    (Reg_Uart_WType *)UART2_BASE_ADDR,
    (Reg_Uart_WType *)UART3_BASE_ADDR,
    (Reg_Uart_WType *)UART4_BASE_ADDR,
    (Reg_Uart_WType *)UART5_BASE_ADDR
};

static Reg_Mcpwm_BfType *const mcpwmRegPtr[MCPWM_NUM_ALL] = 
{
    (Reg_Mcpwm_BfType *)MCPWM0_BASE_ADDR, 
    (Reg_Mcpwm_BfType *)MCPWM1_BASE_ADDR
};


static volatile Mcu_IrqFlagType Mcu_Irq_Flag;

static void Mcu_PortIrqHandler(void);
static void Mcu_CmpIrqHandler(void);
static void Mcu_DmaIrqHandler(void);
static void Mcu_FlsIrqHandler(void);
//#if (WDG_DIRECT_SERVICE == STD_ON)

static void Mcu_EwdtIrqHandler(void);
//#endif
static void Mcu_I2cIrqHandler(void);

static void Mcu_SrmcIrqHandler(void);
static void Mcu_PmuIrqHandler(void);
static void Mcu_StimIrqHandler(void);

static void Mcu_SpiIrqHandler(void);
#if ((CAR_PUB_NET_COM_MEOD == NET_COM_CAN)||(CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN))

static void Mcu_CanIrqHandler(void);
#endif
static void Mcu_TimIrqHandler(void);
static void Mcu_TdgIrqHandler(void);
static void Mcu_I2sIrqHandler(void);
static void Mcu_RtcIrqHandler(void);
static void Mcu_AesIrqHandler(void);
static void Mcu_TrngIrqHandler(void);
static void Mcu_CmuIrqHandler(void);
static void Mcu_SeruIrqHandler(void);
static void Mcu_SccIrqHandler(void);
static void Mcu_UartIrqHandler(void);
static void Mcu_McpwmIrqHandler(void);

static void Mcu_AdcIrqHandler(void);

static void Mcu_FpuIrqHandler(void);
static void Mcu_CacheIrqHandler(void);

static const Interrupt_Drv_StandbyIrqHandlerType Mcu_StandbyIrqHandler[25U] = 
{
    Mcu_DmaIrqHandler,             //DMA_IRQn
    NULL_PTR,//Mcu_FlsIrqHandler,             //FLASH_IRQn
    Mcu_PmuIrqHandler,             //PMU_IRQn
    //#if (WDG_DIRECT_SERVICE == STD_ON)
    Mcu_EwdtIrqHandler,            //EWDT_IRQn
    //#else
    //NULL_PTR,
	//#endif
    Mcu_SrmcIrqHandler,            //SRMC_IRQn
    NULL_PTR,             //I2C_IRQn

    Mcu_SpiIrqHandler,             //SPI_IRQn

    Mcu_UartIrqHandler,            //UART_IRQn
#if ((CAR_PUB_NET_COM_MEOD == NET_COM_CAN)||(CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN))

    NULL_PTR,//Mcu_CanIrqHandler,             //CAN_IRQn
#else
    NULL_PTR,
#endif
    Mcu_TimIrqHandler,             //TIM_IRQn
    Mcu_TdgIrqHandler,             //TDG_IRQn
    NULL_PTR,//Mcu_I2sIrqHandler,             //I2S_IRQn
    Mcu_PortIrqHandler,            //PORT_IRQn
    Mcu_StimIrqHandler,            //STIM_IRQn
    NULL_PTR,//Mcu_RtcIrqHandler,             //RTC_IRQn
    NULL_PTR,//Mcu_AesIrqHandler,             //AES_IRQn
    Mcu_TrngIrqHandler,            //TRNG_IRQn
    Mcu_CmuIrqHandler,             //CMU_IRQn
    Mcu_SeruIrqHandler,            //SERU_IRQn
    Mcu_SccIrqHandler,             //SCC_IRQn
    Mcu_McpwmIrqHandler,           //MCPWM_IRQn
    Mcu_AdcIrqHandler,             //ADC_IRQn
    Mcu_CmpIrqHandler,             //CMP_IRQn
    Mcu_FpuIrqHandler,             //FPU_IRQn
    NULL_PTR,//Mcu_CacheIrqHandler,           //CACHE_IRQn
};



static void DMA_IntMask(void)
{
    dmaRegWPtr->DMA_EIE = 0x0U;
}

static void DMA_AllChannelIntClear(void)
{
    dmaRegWPtr->DMA_GCC = 0x00008080U | 0x40400000U;
}

static void Flash_IntMask(void)
{
    flsRegWPtr->FLASH_FCNFG &= ~(0x00030080U);
}

static void Flash_IntClear(void)
{
    flsRegWPtr->FLASH_FSTAT = 0x00030000U;
    flsRegPtr->FLASH_FCNFG.CCIE = 0U;
}

static void SRMC_IntMask(void)
{
    srmcRegWPtr->SRMC_SRIE &= ~(0x0000B664UL);

    if (0U == (srmcRegWPtr->SRMC_SRIE & (0x0000B664UL)))
    {
        /* If all interrupts are disabled, clear global enable bit. */
        srmcRegWPtr->SRMC_SRIE &= ~(0x80UL);
    }
}

static void SRMC_IntClear(void)
{
    return;
}

static void PORT_IntMask(uint8 portId)
{
    Reg_Port_WType * PORTx = (Reg_Port_WType *)(portRegWPtr[portId]);
    PORTx->PORTx_GLBDAT = 0x0;
    PORTx->PORTx_GLBCTL = 0xFFFFFFFFU;
}

static void PORT_ClearPinsInt(uint8 portId, uint32 clrPins)
{
    Reg_Port_WType * PORTxw = (Reg_Port_WType *)(portRegWPtr[portId]);

    PORTxw->PORTx_IRQFLG = clrPins;
}

static void CMP_IntMask(void)
{
    cmpRegWPtr->CMP_IER &= ~(0x00000003U);
}

static void CMP_IntClear(void)
{
    uint32 intstatus = cmpRegWPtr->CMP_CSR;
    intstatus |= 0x00000003U;
    cmpRegWPtr->CMP_CSR = intstatus;
}

static void PMU_IntMask(void)
{
    if(1U == pmuRegPtr->PMU_LOCK.LOCK)
    {
        pmuRegWPtr->PMU_LOCK = 0x94730000U;
    }
    pmuRegWPtr->PMU_CSR = ~(0x00000024U);
    
    pmuRegPtr->PMU_LOCK.LOCK = 1U;
}

static void PMU_IntClear(void)
{
    pmuRegWPtr->PMU_LOCK = 0x94730000U;
    pmuRegWPtr->PMU_CSR = pmuRegWPtr->PMU_CSR | 0x000000C0U;
    pmuRegPtr->PMU_LOCK.LOCK = 1U;
}

static void STIM_IntMask(uint8 stimId)
{
    Reg_Stim_WType * stimRegWPtr = (Reg_Stim_WType *)(STIM_BASE_ADDR);
    /* Mask/Unmask the timer interrupt */
    stimRegWPtr->STIM_SCn[stimId] = (uint32)((stimRegWPtr->STIM_SCn[stimId]) & (~(0x0000A000U)));
}

static void STIM_IntClear(uint8 stimId)
{
    /* Write 1 to clear interrupt */
    stimRegPtr->STIM_SCn[stimId].FLAG = 1U;
}

static void TIM_IntMask(uint8 timId)
{
    Reg_Tim_BfType * TIMx = timRegPtr[timId];
    TIMx->TIM_CMCn[0].CHIE = 0U;
    TIMx->TIM_CMCn[1].CHIE = 0U;
    TIMx->TIM_CMCn[2].CHIE = 0U;
    TIMx->TIM_CMCn[3].CHIE = 0U;
    TIMx->TIM_CMCn[4].CHIE = 0U;
    TIMx->TIM_CMCn[5].CHIE = 0U;
    TIMx->TIM_CMCn[6].CHIE = 0U;
    TIMx->TIM_CMCn[7].CHIE = 0U;
    TIMx->TIM_GLBCR.RLDIE = 0U;
    TIMx->TIM_GLBCR.TOIE = 0U;
    TIMx->TIM_FLTCR.FLTIE = 0U;
}

static void TIM_IntClear(uint8 timId)
{
    Reg_Tim_BfType * TIMx = timRegPtr[timId];
    TIMx->TIM_CMCn[0].CHF = 0U;
    TIMx->TIM_CMCn[1].CHF = 0U;
    TIMx->TIM_CMCn[2].CHF = 0U;
    TIMx->TIM_CMCn[3].CHF = 0U;
    TIMx->TIM_CMCn[4].CHF = 0U;
    TIMx->TIM_CMCn[5].CHF = 0U;
    TIMx->TIM_CMCn[6].CHF = 0U;
    TIMx->TIM_CMCn[7].CHF = 0U;
    TIMx->TIM_GLBSR.RLDF = 0U;
    TIMx->TIM_GLBSR.TOF = 0U;
    TIMx->TIM_FLTSR.FAULTF = 0U;
}

static void TDG_IntMask(uint8 tdgId)
{
    Reg_Tdg_BfType* TDGx = (Reg_Tdg_BfType *)(tdgRegPtr[tdgId]);
    TDGx->TDG_CTRL2.CDO0IE = (uint32)0U;
    TDGx->TDG_CTRL2.CDO1IE = (uint32)0U;
    TDGx->TDG_CTRL2.CDO2IE = (uint32)0U;
    TDGx->TDG_CTRL2.CDO3IE = (uint32)0U;
    TDGx->TDG_CTRL2.CDO4IE = (uint32)0U;
    TDGx->TDG_CTRL2.CDO5IE = (uint32)0U;
    TDGx->TDG_CTRL2.ERRIE = (uint32)0U;
}

static void TDG_IntClear(uint8 tdgId)
{
   Reg_Tdg_WType * TDGxw = (Reg_Tdg_WType *)(tdgRegWPtr[tdgId]);
   TDGxw->TDG_STAT = 0x0000013FU;
}

static void I2S_IntMask(uint8 i2sId)
{   
    uint8 channelId = 0U;
    Reg_I2s_WType * I2Sxw = (Reg_I2s_WType *)(i2sRegWPtr[i2sId]);
    for(channelId = 0U; channelId < 4U; channelId++)
    {
        I2Sxw->I2S_CHANNEL_REG[channelId].I2S_CHn_INT_CFG = 
        (I2Sxw->I2S_CHANNEL_REG[channelId].I2S_CHn_INT_CFG & (~(0x0000000FU)) & 0xFU);
    }

}

static void I2S_IntClear(uint8 i2sId)
{
    uint8 channelId = 0U;
    Reg_I2s_WType * I2Sxw = (Reg_I2s_WType *)(i2sRegWPtr[i2sId]);
    for(channelId = 0U; channelId < 4U; channelId++)
    {
        I2Sxw->I2S_CHANNEL_REG[channelId].I2S_CHn_INT_CFG = 
        ((I2Sxw->I2S_CHANNEL_REG[channelId].I2S_CHn_INT_CFG & 0xFU) | 0x000000F0U);       
    }
}

static void RTC_IntMask(void)
{
    if(rtcRegPtr->RTC_LOCKR.LOCK != 0U)
    {
        rtcRegWPtr->RTC_LOCKR = 0x98670000U;
    }
    rtcRegWPtr->RTC_IER &= (~(0x00000038U));
    rtcRegPtr->RTC_LOCKR.LOCK = 0x1U;
}

static void RTC_IntClear(void)
{
    uint32 tempVal = 0U;
    if(rtcRegPtr->RTC_LOCKR.LOCK != 0U)
    {
        rtcRegWPtr->RTC_LOCKR = 0x98670000U;
    }
    rtcRegPtr->RTC_ONE_SECOND_CNTR.ONE_SECOND_CNT = 0U;
    rtcRegPtr->RTC_MATCH_CNTR.MATCH_CNT = 0xFFFFFFFFU;
    /* SECONDS_INT_FLAG = 1, PERIODIC_MATCH_FLG = 1 */
    tempVal = (rtcRegWPtr->RTC_CSR & (0x0000147FU)) | (0x1UL << 11U) | (0x1UL << 13U);
    rtcRegWPtr->RTC_CSR = tempVal;
    rtcRegPtr->RTC_LOCKR.LOCK = 1U;
}

static void TRNG_IntMask(void)
{
    Reg_Trng_WType *const trngRegWPtr = (Reg_Trng_WType *)TRNG_BASE_ADDR;
    trngRegWPtr->TRNG_IRQ_CONFIG &= ~(0x0000000FU);
}

static void TRNG_IntClear(void)
{
    Reg_Trng_WType *const trngRegWPtr = (Reg_Trng_WType *)TRNG_BASE_ADDR;
    trngRegWPtr->TRNG_IRQ_CONFIG = 0x0000000FU;
}

static void CMU_IntMask(uint8 cmuId)
{
    Reg_Cmu_WType * CMUxw = cmuRegWPtr[cmuId];
    CMUxw->CMU_CTRL &= ~(0x00030000U);
}

static void CMU_IntClear(uint8 cmuId)
{
    Reg_Cmu_WType * CMUxw = cmuRegWPtr[cmuId];
    CMUxw->CMU_STAT = 0x00030000U;
}

static void SERU_IntMask(void)
{
    uint8 channelId = 0U;
    seruRegWPtr->SERU_CFG_KEY = 0x7F1A2dFEU;
    seruRegPtr->SERU_CSR.CRPAR_INT_EN = (uint32)0U;
    for(channelId = 0U;channelId < 17U;channelId++)
    {
        seruRegPtr->SERU_CFG_CHn[channelId].CH_INT_CFG = (uint32)0U;
    }
    seruRegWPtr->SERU_CFG_KEY = 0x6CC92DD9U;
}

static void SERU_IntClear(void)
{
    seruRegWPtr->SERU_CH_FLAG = 0x1FFFF;
    seruRegPtr->SERU_INTF.S_CRPAR_ERR = 0x1U;
}

static void SCC_IntMask(void)
{
    if(sccRegBfPtr->SCC_OSCCS.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_OSCCS = 0x5B000000U;
    }
    else
    {
        /* do nothing */
    }
    // Disable the OSCLOCINTEN interrupt function
    sccRegBfPtr->SCC_OSCCS.OSCLOCINTEN = 0U;
    /* clear int status and lock */
    sccRegBfPtr->SCC_OSCCS.LOCK = 1U;
    if(sccRegBfPtr->SCC_FIRCCS.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_FIRCCS = 0x5B000000U;
    }
    else
    {
        /* do nothing */
    }
    // Disable the FIRCLOCINTEN interrupt function
    sccRegBfPtr->SCC_FIRCCS.FIRCLOCINTEN = 0U;
    /* clear int status and lock */
    sccRegBfPtr->SCC_FIRCCS.LOCK = 1U;    
}

static void SCC_IntClear(void)
{
    if(sccRegBfPtr->SCC_OSCCS.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_OSCCS = 0x5B000000U;
    }
    else
    {
        /* do nothing */
    }
    /* clear int status and lock */
    sccRegBfPtr->SCC_OSCCS.OSCLOC = 1U;
    sccRegBfPtr->SCC_OSCCS.LOCK = 1U;
    if(sccRegBfPtr->SCC_FIRCCS.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_FIRCCS = 0x5B000000U;
    }
    else
    {
        /* do nothing */
    }
    /* clear int status and lock */
    sccRegBfPtr->SCC_FIRCCS.FIRCLOC = 1U;
    sccRegBfPtr->SCC_FIRCCS.LOCK = 1U;
}

static void UART_IntMask(uint8 uartId)
{
    Reg_Uart_WType * UARTx = (Reg_Uart_WType *)(uartRegPtr[uartId]);
    UARTx->UART_DLH_IER.UART_IER &= ~(0x0000078FU);
}

static void UART_IntClear(uint8 uartId)
{
    uint32 dummyData = 0U;
    Reg_Uart_WType * UARTx = (Reg_Uart_WType *)(uartRegPtr[uartId]);
    dummyData = UARTx->UART_LSR;
    (void)dummyData;
}

static void MCPWM_IntMask(uint8 mcpwmId)
{
    Reg_Mcpwm_BfType * MCPWMx = mcpwmRegPtr[mcpwmId];
    MCPWMx->MCPWM_CFGn[0].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_CFGn[1].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_CFGn[2].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_CFGn[3].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_CFGn[4].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_CFGn[5].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_CFGn[6].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_CFGn[7].CHIE =  (uint32)0U;
    MCPWMx->MCPWM_GLBCR.RLDIE0 = (uint32)0U;
    MCPWMx->MCPWM_GLBCR.RLDIE1 = (uint32)0U;
    MCPWMx->MCPWM_GLBCR.RLDIE2 = (uint32)0U;
    MCPWMx->MCPWM_GLBCR.RLDIE3 = (uint32)0U;
    MCPWMx->MCPWM_GLBCR.TOIE0 =  (uint32)0U;
    MCPWMx->MCPWM_GLBCR.TOIE1 =  (uint32)0U;
    MCPWMx->MCPWM_GLBCR.TOIE2 =  (uint32)0U;
    MCPWMx->MCPWM_GLBCR.TOIE3 =  (uint32)0U;
    MCPWMx->MCPWM_FLTCR.FLTIE =  (uint32)0U;
}

static void MCPWM_IntClear(uint8 mcpwmId)
{
    Reg_Mcpwm_BfType *MCPWMx = mcpwmRegPtr[mcpwmId];
    MCPWMx->MCPWM_CFGn[0].CHF = 0U;
    MCPWMx->MCPWM_CFGn[1].CHF = 0U;
    MCPWMx->MCPWM_CFGn[2].CHF = 0U;
    MCPWMx->MCPWM_CFGn[3].CHF = 0U;
    MCPWMx->MCPWM_CFGn[4].CHF = 0U;
    MCPWMx->MCPWM_CFGn[5].CHF = 0U;
    MCPWMx->MCPWM_CFGn[6].CHF = 0U;
    MCPWMx->MCPWM_CFGn[7].CHF = 0U;
    MCPWMx->MCPWM_GLBSR.RLDF0 = 0U;
    MCPWMx->MCPWM_GLBSR.RLDF1 = 0U;
    MCPWMx->MCPWM_GLBSR.RLDF2 = 0U;
    MCPWMx->MCPWM_GLBSR.RLDF3 = 0U;
    MCPWMx->MCPWM_GLBSR.TOF0 = 0U;
    MCPWMx->MCPWM_GLBSR.TOF1 = 0U;
    MCPWMx->MCPWM_GLBSR.TOF2 = 0U;
    MCPWMx->MCPWM_GLBSR.TOF3 = 0U;
    MCPWMx->MCPWM_FLTSR.FAULTFA = 0U;
    MCPWMx->MCPWM_FLTSR.FAULTFB = 0U;
}
#if 1 //(WDG_DIRECT_SERVICE == STD_ON)

static inline void WDOG_UNLOCK_CONFIG(void)
{
    uint32 Primask;
    ASMV_KEYWORD( "MRS %0, PRIMASK " : "=r"(Primask));
    if (0U == Primask)
    {
        McalLib_SuspendAllInterrupts();
    }
    __asm (
        "PUSH  {R0, R1, R2}\n"
        "LDR   R0, =0x40052014\n"
        "LDR   R1, =0xB0D9A1C4\n"
        "LDR   R2, =0x1A1E3B0F\n"

        "STR   R1, [R0]\n"
        "STR   R2, [R0]\n"
        "POP  {R0, R1, R2}\n"
            );
    if (0U == Primask)
    {
        McalLib_ResumeAllInterrupts();
    }
}

static uint8 Wdog_WaitConfigCompleted(void)
{
    volatile uint32 ULoop          = 0U;
    uint8 RetVal = 1U;
    Reg_Wdog_BfType * Wdog_RegBfPtr = (Reg_Wdog_BfType *)(wdogRegWPtr);
    while ((uint32)1U != (uint32)Wdog_RegBfPtr->WDOG_CS.CFGUF)
    {
        if (ULoop > (uint32)0xFFFFFU)
        {
            RetVal = 0U;
            break;
        }
        else
        {
            /* Do nothing*/
        }
        ULoop++;
    }

    return RetVal;
}

static Std_ReturnType WDOG_ClearIntStatus(void)
{
    Reg_Wdog_WType * wDOGxw = (Reg_Wdog_WType *)(wdogRegWPtr);
    /* unlock config update */
    WDOG_UNLOCK_CONFIG();
    uint32 intStatus = wDOGxw->WDOG_CS;
    intStatus = intStatus | 0x04000000U;
    wDOGxw->WDOG_CS = intStatus;
    return (Wdog_WaitConfigCompleted());
}
#endif
static void Systick_Disable(void)
{
    SysTickPtr->CTRL = 0U;
    SCBRegPtr->ICSR |= 1<<25;
}

static void Mcu_PortIrqHandler(void)
{
    if(Mcu_Irq_Flag.PORT == 0U)
    {
        if((parccRegPtr->PARCC_PORTA.PCKMD & 0x1U) != 0U )
        {
            PORT_IntMask(0U);
            PORT_ClearPinsInt(0U,0xFFFFFFFFU);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_PORTB.PCKMD & 0x1U) != 0U )
        {
            PORT_IntMask(1U);
            PORT_ClearPinsInt(1U,0xFFFFFFFFU);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_PORTC.PCKMD & 0x1U) != 0U )
        {
            PORT_IntMask(2U);
            PORT_ClearPinsInt(2U,0xFFFFFFFFU);
        }
        else
        {
            /* do nothing */
        }    
        if((parccRegPtr->PARCC_PORTD.PCKMD & 0x1U) != 0U )
        {
            PORT_IntMask(3U);
            PORT_ClearPinsInt(3U,0xFFFFFFFFU);
        }
        else
        {
            /* do nothing */
        }    
        if((parccRegPtr->PARCC_PORTE.PCKMD & 0x1U) != 0U )
        {
            PORT_IntMask(4U);
            PORT_ClearPinsInt(4U,0xFFFFFFFFU);
        }
        else
        {
            /* do nothing */
        }
        Mcu_Irq_Flag.PORT = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_CmpIrqHandler(void)
{
    if((Mcu_Irq_Flag.CMP == 0U) && ((parccRegPtr->PARCC_CMP0.PCKMD & 0x1U) != 0U ))
    {
        CMP_IntMask();
        CMP_IntClear();
        Mcu_Irq_Flag.CMP = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_DmaIrqHandler(void)
{
    if((Mcu_Irq_Flag.DMA == 0U) && ((parccRegPtr->PARCC_DMA.PCKMD & 0x1U) != 0U))
    {
        DMA_IntMask();
        DMA_AllChannelIntClear();
        Mcu_Irq_Flag.DMA = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_FlsIrqHandler(void)
{
    if((Mcu_Irq_Flag.FLASH == 0U) && ((parccRegPtr->PARCC_FLASH.PCKMD & 0x1U) != 0U ))
    {
        Flash_IntMask();
        Flash_IntClear();
        Mcu_Irq_Flag.FLASH = 1U;
    }
    else
    {
        /* do nothing */
    }
}
//#if (WDG_DIRECT_SERVICE == STD_ON)

static void Mcu_EwdtIrqHandler(void)
{
    uint32 intStatus = 0U;
    Reg_Ewdt_WType * eWDTxw = (Reg_Ewdt_WType *)(EWDT_BASE_ADDR);
    
    if((Mcu_Irq_Flag.EWDT == 0U) && (parccRegPtr->PARCC_EWDT.PCKMD & 0x1) != 0U)
    {
        intStatus = eWDTxw->EWDT_CS;
        intStatus = intStatus | 0x01000000U;
        eWDTxw->EWDT_CS = intStatus;
        Mcu_Irq_Flag.EWDT = 1U;
    }
    else
    {
        /* do nothing */
    }
}
//#endif

static void Mcu_I2cIrqHandler(void)
{
    if(Mcu_Irq_Flag.I2C == 0U)
    {
        if((parccRegPtr->PARCC_I2C0.PCKMD & 0x1) != 0U || 
           (parccRegPtr->PARCC_I2C1.PCKMD & 0x1) != 0U)
        {
           // I2c_DeInit();
            Mcu_Irq_Flag.I2C = 1U;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }       
}


static void Mcu_SrmcIrqHandler(void)
{
    if(Mcu_Irq_Flag.SRMC == 0U)
    {
        SRMC_IntMask();
        SRMC_IntClear();
        Mcu_Irq_Flag.SRMC = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_PmuIrqHandler(void)
{
    if(Mcu_Irq_Flag.PMU == 0U)
    {
        /* Pmu clock is on default */
        PMU_IntMask();
        PMU_IntClear();
        Mcu_Irq_Flag.PMU = 1U;
    }

}

static void Mcu_StimIrqHandler(void)
{
    uint8 i = 0U;
    if((Mcu_Irq_Flag.STIM == 0U) &&((parccRegPtr->PARCC_STIM.PCKMD & 0x1U) != 0U))
    {
        for(i = 0U; i<4U; i++)
        {
            STIM_IntMask(i);
            STIM_IntClear(i);   
        }
        Mcu_Irq_Flag.STIM = 1U;
    }
    else
    {
        /* do nothing */
    }
}


static void Mcu_SpiIrqHandler(void)
{
    if(Mcu_Irq_Flag.SPI == 0U)
    {
        if((parccRegPtr->PARCC_SPI0.PCKMD & 0x1) != 0U || 
           (parccRegPtr->PARCC_SPI1.PCKMD & 0x1) != 0U || 
           (parccRegPtr->PARCC_SPI2.PCKMD & 0x1) != 0U || 
           (parccRegPtr->PARCC_SPI3.PCKMD & 0x1) != 0U)
        {
            Spi_DeInit();
            Mcu_Irq_Flag.SPI = 1U;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }   
}


#if ((CAR_PUB_NET_COM_MEOD == NET_COM_CAN)||(CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN))

static void Mcu_CanIrqHandler(void)
{
    if(Mcu_Irq_Flag.CAN == 0U)
    {
        if((parccRegPtr->PARCC_CAN0.PCKMD & 0x1) != 0U  
           || (parccRegPtr->PARCC_CAN1.PCKMD & 0x1) != 0U 
           || (parccRegPtr->PARCC_CAN2.PCKMD & 0x1) != 0U  
           || (parccRegPtr->PARCC_CAN3.PCKMD & 0x1) != 0U
#if (defined(DEV_Z20K148M) || defined(DEV_Z20K146M))
           || (parccRegPtr->PARCC_CAN4.PCKMD & 0x1) != 0U
           || (parccRegPtr->PARCC_CAN5.PCKMD & 0x1) != 0U
#endif
#if (defined(DEV_Z20K148M))
           || (parccRegPtr->PARCC_CAN6.PCKMD & 0x1) != 0U
           || (parccRegPtr->PARCC_CAN7.PCKMD & 0x1) != 0U
#endif
           )
        {
            Can_DeInit();
            Mcu_Irq_Flag.CAN = 1U;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
}
#endif

static void Mcu_TimIrqHandler(void)
{
    if(Mcu_Irq_Flag.TIM == 0U)
    {
        if((parccRegPtr->PARCC_TIM0.PCKMD & 0x1U) != 0U)
        {
            TIM_IntMask(0U);
            TIM_IntClear(0U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_TIM1.PCKMD & 0x1U) != 0U)
        {
            TIM_IntMask(1U);
            TIM_IntClear(1U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_TIM2.PCKMD & 0x1U) != 0U)
        {
            TIM_IntMask(2U);
            TIM_IntClear(2U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_TIM3.PCKMD & 0x1U) != 0U)
        {
            TIM_IntMask(3U);
            TIM_IntClear(3U);
        }
        else
        {
            /* do nothing */
        }
        Mcu_Irq_Flag.TIM = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_TdgIrqHandler(void)
{
    if(Mcu_Irq_Flag.TDG == 0U)
    {
        if((parccRegPtr->PARCC_TDG0.PCKMD & 0x1) != 0U)
        {
            TDG_IntMask(0U);
            TDG_IntClear(0U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_TDG1.PCKMD & 0x1) != 0U)
        {
            TDG_IntMask(1U);
            TDG_IntClear(1U);
        }
        else
        {
            /* do nothing */
        }
        Mcu_Irq_Flag.TDG = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_I2sIrqHandler(void)
{
    if(Mcu_Irq_Flag.I2S == 0U)
    {
        if((parccRegPtr->PARCC_I2C0.PCKMD & 0x1) != 0U)
        {
            I2S_IntMask(0U);
            I2S_IntClear(0U);
        }
        else
        {
            /* do nothing */
        }
#if (defined(DEV_Z20K148M))
        if((parccRegPtr->PARCC_I2S1.PCKMD & 0x1) != 0U)
        {
            I2S_IntMask(1U);
            I2S_IntClear(1U);
        }
        else
        {
            /* do nothing */
        }
#endif
        Mcu_Irq_Flag.I2S = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_RtcIrqHandler(void)
{
    if(Mcu_Irq_Flag.RTC == 0U)
    {
        RTC_IntMask();
        RTC_IntClear();
        Mcu_Irq_Flag.RTC = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_AesIrqHandler(void)
{
    return;
}

static void Mcu_TrngIrqHandler(void)
{
    if((Mcu_Irq_Flag.TRNG == 0U) && ((parccRegPtr->PARCC_TRNG.PCKMD & 0x1U) != 0U))
    {
        TRNG_IntMask();
        TRNG_IntClear();
        Mcu_Irq_Flag.TRNG = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_CmuIrqHandler(void)
{
    uint8 i = 0U;
    if(Mcu_Irq_Flag.CMU == 0U)
    {
        for(i = 0U;i<3U;i++)
        {
            CMU_IntMask(i);
            CMU_IntClear(i);
        }
        Mcu_Irq_Flag.CMU = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_SeruIrqHandler(void)
{
    if(Mcu_Irq_Flag.SERU == 0U)
    {
        SERU_IntMask();
        SERU_IntClear();
        Mcu_Irq_Flag.SERU = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_SccIrqHandler(void)
{
    if(Mcu_Irq_Flag.SCC == 0U)
    {
        SCC_IntMask();
        SCC_IntClear();
        Mcu_Irq_Flag.SCC = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_UartIrqHandler(void)
{
    if(Mcu_Irq_Flag.UART == 0U)
    {
        if((parccRegPtr->PARCC_UART0.PCKMD & 0x1U) != 0U)
        {
            UART_IntMask(0U);
            UART_IntClear(0U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_UART1.PCKMD & 0x1U) != 0U)
        {
            UART_IntMask(1U);
            UART_IntClear(1U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_UART2.PCKMD & 0x1U) != 0U)
        {
            UART_IntMask(2U);
            UART_IntClear(2U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_UART3.PCKMD & 0x1U) != 0U)
        {
            UART_IntMask(3U);
            UART_IntClear(3U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_UART4.PCKMD & 0x1U) != 0U)
        {
            UART_IntMask(4U);
            UART_IntClear(4U);
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_UART5.PCKMD & 0x1U) != 0U)
        {
            UART_IntMask(5U);
            UART_IntClear(5U);
        }
        else
        {
            /* do nothing */
        }
        Mcu_Irq_Flag.UART = 1U;
    }
    else
    {
        /* do nothing */       
    }
}

static void Mcu_McpwmIrqHandler(void)
{
    if(Mcu_Irq_Flag.MCPWM == 0U)
    {
        if((parccRegPtr->PARCC_MCPWM0.PCKMD & 0x1) != 0)
        {
            MCPWM_IntMask(0U);
            MCPWM_IntClear(0U);   
        }
        else
        {
            /* do nothing */
        }
        if((parccRegPtr->PARCC_MCPWM1.PCKMD & 0x1) != 0)
        {
            MCPWM_IntMask(1U);
            MCPWM_IntClear(1U);   
        }
        else
        {
            /* do nothing */
        }
        Mcu_Irq_Flag.MCPWM = 1U;
    }    
}


static void Mcu_AdcIrqHandler(void)
{
    if(Mcu_Irq_Flag.ADC == 0U)
    {
        if(((parccRegPtr->PARCC_ADC0.PCKMD & 0x1) != 0) ||
           ((parccRegPtr->PARCC_ADC1.PCKMD & 0x1) != 0))
        {
            Adc_DeInit();
            Mcu_Irq_Flag.ADC = 1U;
        }
        else
        {
            /* do nothing */
        }
    }
}


static void Mcu_FpuIrqHandler(void)
{
    uint32 FPU_Stack_Addr = 0U;
    uint32 FPUSCR_Value = 0U;
    if(Mcu_Irq_Flag.FPU == 0U)
    {
        // Mask all fpu interrupt enable
        ScmRegPtr->SCM_MISCCTL1.FPU_INEXACT_INT_EN = 0U;
        ScmRegPtr->SCM_MISCCTL1.FPU_OVERFLOW_INT_EN = 0U;
        ScmRegPtr->SCM_MISCCTL1.FPU_UNDERFLOW_INT_EN = 0U;
        ScmRegPtr->SCM_MISCCTL1.FPU_INVALIDOP_INT_EN = 0U;
        ScmRegPtr->SCM_MISCCTL1.FPU_DIVZERO_INT_EN = 0U;
        ScmRegPtr->SCM_MISCCTL1.FPU_DENORMALIN_INT_EN = 0U;
        // Clear all FPU interrupt flags
        FPU_Stack_Addr = FPURegPtr->FPCAR;
        FPU_Stack_Addr += 64U;
        FPUSCR_Value = *(uint32 *)FPU_Stack_Addr;
        FPUSCR_Value &= ~(0x3F);
        *(uint32 *)FPU_Stack_Addr = FPUSCR_Value;
        Mcu_Irq_Flag.FPU = 1U;
    }
    else
    {
        /* do nothing */
    }
}

static void Mcu_CacheIrqHandler(void)
{
    if(Mcu_Irq_Flag.CACHE == 0U)
    {
        //Mask all CACHE interrupt enable
        ScmRegPtr->SCM_MISCCTL1.CCACHE_BE_INT_EN = 0U;
        //Clear all CACHE interrupt flags
        ScmRegPtr->SCM_MISCSTAT1.CACHE_BE_FLAG &= 0x8000;
        Mcu_Irq_Flag.CACHE = 1U;
    }
    else
    {
        /* do nothing */
    }
}



void SystemMode_Clear_External_WakeupIntFlag(void)
{
		/*In the current hardware design, the 5V power supply will be disconnected after sleep, 
			and after the LIN transceiver wakes up, the 5V power supply will be turned on, 
			and the MCU will run again, so there is no need key wake up and LIN wake up.
			*/
}
void SystemMode_WakeupPinDisable(void)
{
		/*In the current hardware design, the 5V power supply will be disconnected after sleep, 
			and after the LIN transceiver wakes up, the 5V power supply will be turned on, 
			and the MCU will run again, so there is no need key wake up and LIN wake up.
			*/
}


void SystemMode_WakeupPinEnAndEdge_Config(void)
{

}
void SystemMode_WakeupPinDisable_Config(void)
{
		/*In the current hardware design, the 5V power supply will be disconnected after sleep, 
			and after the LIN transceiver wakes up, the 5V power supply will be turned on, 
			and the MCU will run again, so there is no need key wake up and LIN wake up.
			*/
;

}

void SystemMode_WakeupIntp_Init(void)
{


		

}

void Mcu_PrepareStandby(void)
{
	uint16 IrqIndex = 0U;
	SuspendAllInterrupts();

	/* Clear all the irq handler reentrant flag */
	*(uint32*)(&Mcu_Irq_Flag) = 0U;
	#if 1
	//Clear all pheriphral interrupt interrupt flags
	for(IrqIndex = 0U; IrqIndex < 25U; IrqIndex++)
	{
		if(Mcu_StandbyIrqHandler[IrqIndex] != NULL_PTR)
		{
			Mcu_StandbyIrqHandler[IrqIndex]();
		}
		else
		{
			/* do nothing */
		}
	}
	#endif
	//#if (WDG_DIRECT_SERVICE == STD_ON)
	//Wdog not disable here in case of that pragram stop here.
	WDOG_ClearIntStatus();
	//Wdg_Service();
	//WdgM_MainFunction();
	//#endif
	//clear pending flags
	for(IrqIndex = 0U;IrqIndex < 205;IrqIndex++)
	{
		Interrupt_Drv_ClearPending((IRQn_Type)IrqIndex);
	}
	
	//Disable SystemTick
	Systick_Disable();
	
	//Enable Wakeup source interrupt
#if (defined(WAKEUP_INTERRUPT_HANDLER))
	//Mcu_WakeupInterrupt_Init();
#endif

    ResumeAllInterrupts();

	
}



void SystemMode__Entry_Standby(void)
{
	Dio_LevelType ChannelLevel = STD_LOW;
	Mcu_PrepareStandby();
	if(STD_HIGH== GET_LIN_TRANSCEIVER_INH_STATUS)
	{
		#if EXTERN_WAKEUP_LIN_EN
		//Srmc_Drv_SetWakeupSource(SRMC_DRV_WUPSRC_PTE13, TRUE);
		Mcu_SetWakeupSource(MCU_WUPSRC_PTE13,FALSE,TRUE);
		#endif

		//Ê¹ÄÜ»½ÐÑÔ´
		#if EXTERN_WAKEUP_IGN_EN
		//Srmc_Drv_SetWakeupSource(SRMC_DRV_WUPSRC_PTE1, TRUE);
		Mcu_SetWakeupSource(MCU_WUPSRC_PTE1,FALSE,TRUE);
		#endif

		//Ê¹ÄÜ»½ÐÑÔ´
		#if EXTERN_WAKEUP_KEY_EN
		Mcu_SetWakeupSource(MCU_WUPSRC_PTA9,TRUE,TRUE);
		//Srmc_Drv_SetWakeupSource(SRMC_DRV_WUPSRC_PTA9, TRUE);
		#endif
		Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_1);
	}
	//¹Ø±Õ»½ÐÑÔ´
	#if EXTERN_WAKEUP_LIN_EN
	//Srmc_Drv_SetWakeupSource(SRMC_DRV_WUPSRC_PTE13, FALSE);
	Mcu_SetWakeupSource(MCU_WUPSRC_PTE13,FALSE,FALSE);
	
	#endif

	//¹Ø±Õ»½ÐÑÔ´
	#if EXTERN_WAKEUP_IGN_EN
	//Srmc_Drv_SetWakeupSource(SRMC_DRV_WUPSRC_PTE1, FALSE);
	Mcu_SetWakeupSource(MCU_WUPSRC_PTE1,FALSE,FALSE);
	#endif

	//Ê¹ÄÜ»½ÐÑÔ´
	#if EXTERN_WAKEUP_KEY_EN
	//Srmc_Drv_SetWakeupSource(SRMC_DRV_WUPSRC_PTA9, FALSE);
	Mcu_SetWakeupSource(MCU_WUPSRC_PTA9,TRUE,FALSE);
	#endif
	Mcu_PerformReset();
}







static  bool RST_GetSrcStatusCmd(const RST_Source_names_t srcName)
{
    bool retValue;
   
    return retValue;
}

void SystemMode_CheckResetSrc(void)
{

	
}

void SystemMode_Wakeup_Init(void)
{
	Sleep_Status =0u;
}
void SystemMode_Interrupt_Init(void)
{
	Platform_Init(NULL_PTR);
}



