/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kflog.c
 *  @Date             : 2025-02-10
 *  @Version          : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-07-24  |V1.0     |Zhou Jie     |New Create
 *****************************************************************************/

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

#ifdef KF_INTERNAL_PRINT
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "__Kungfu32_chipmodel_define.h"

#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "kf_types.h"
#include "kflog.h"
#include "kf32a158sf_drv_usart.h"
#include "kf32a158sf_drv_rst.h"
#include "kf32a158sf_drv_pclk.h"
#include "kf32a158sf_drv_gpio.h"
#include "kf32a158sf_drv_bkp.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        user config
 ******************************************************************************/
#define UART0_INDEX (0U)
#define UART1_INDEX (1U)
#define UART2_INDEX (2U)
#define UART3_INDEX (3U)
#define UART6_INDEX (6U)

/**
 * @brief debugging Log Configuration
 * the default configuration is UART0, baud rate is 921600U
 * the maximum configuration is 921600,the minimum baud rate 1200
 */
#ifndef KFLOG_UART_IDX_H
#define KFLOG_UART_IDX UART0_INDEX
#endif

#if (KFLOG_UART_IDX == UART0_INDEX)
#define KFLOG_UART_DEV USART0_PTR
#elif (KFLOG_UART_IDX == UART1_INDEX)
#define KFLOG_UART_DEV USART1_PTR
#elif (KFLOG_UART_IDX == UART2_INDEX)
#define KFLOG_UART_DEV USART2_PTR
#elif (KFLOG_UART_IDX == UART3_INDEX)
#define KFLOG_UART_DEV USART3_PTR
#elif (KFLOG_UART_IDX == UART6_INDEX)
#define KFLOG_UART_DEV USART6_PTR
#else
#error "This UART Device is not supported"
#endif

#if (defined(KF32A158NQVSF) || defined(KF32A158MQVSF) || defined(KF32A158NQTSF) || defined(KF32A158MQTSF))
#define KF32A158SF_120M
#else
#error Wrong chip model!!!
#endif
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/* wait maxtime */
#define UART_TRANSMIT_TIMEOUT ((uint32_t)0xFFFFU)
/* uart select clock */
#define BASE_CLOCK_1MHz 1000000U

#ifdef KF32A58SF_80M
#define KFLOG_UART_CLOCK (80U * BASE_CLOCK_1MHz)
#elif defined(KF32A158SF_120M)
#define KFLOG_UART_CLOCK (120U * BASE_CLOCK_1MHz)
#endif

#define KFLOG_UART_MAX_DATA_LEN ((uint32_t)256U)
#define KFLOG_UART_MAX_LINE_NUM ((uint32_t)12U)

#define KFLOG_UART_FREQUENCY (921600U)

#ifndef KFLOG_UART_FREQUENCY
#define KFLOG_UART_FREQUENCY (921600U)
#else
#if (KFLOG_UART_FREQUENCY > 921600U) || (KFLOG_UART_FREQUENCY < 9600U)
#error "UART Frequency is out of range"
#endif
#endif

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
**                     Variable Declarations
******************************************************************************/

/**
 * @brief log output buffer
 */
static char kvLog_SendData[KFLOG_UART_MAX_DATA_LEN] = {0};
static char kvLog_LineNum[KFLOG_UART_MAX_LINE_NUM]  = {0};

/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/* PRQA S 2889,0771 ++ */ /* This function has more than one 'return' path. */
/* PRQA S 2934 ++ */      /* Possible: Computing an invalid pointer value. */
/**
 * @brief Log information output
 * @param plog_module-Information about the registered module
 * LogLevel-Print level
 * pfun-function name
 * line-line num
 * pfile-The file path
 * format,...-varargs
 * @retval None
 */
void kfLog_Printf(const Log_PrintfType *const plog_module, const char *pfun, uint32_t line, const char *pfile,
                  const char *format, ...)
{
    va_list  args;
    uint16_t TmpLen = 0U;

    if ((NULL_PTR == pfile) || (NULL_PTR == pfun) || (NULL_PTR == format))
    {
        return;
    }

    (void)memset(kvLog_SendData, 0, sizeof(kvLog_SendData));
    (void)memset(kvLog_LineNum, 0, sizeof(kvLog_LineNum));

    do
    {
        /* module name */
        if ((NULL_PTR != plog_module) && (NULL_PTR != plog_module->name))
        {
            if ((strlen(plog_module->name) + 2U) > (sizeof(kvLog_SendData) - 1U))
            {
                break;
            }
            (void)sprintf(kvLog_SendData, "[%s]", plog_module->name);
            TmpLen = (uint16_t)strlen(kvLog_SendData);
            /* PRQA S 3344,4399 1 */ /* MISRA RULE 14.4 */
            if (plog_module->opt & KF_LOG_OPT_FUNC)
            {
                /* PRQA S 3383 1 */ /* Arithmetic won't wraparound */
                if ((TmpLen + strlen(pfun) + 2U) > (sizeof(kvLog_SendData) - 1U))
                {
                    break;
                }
                (void)sprintf(&kvLog_SendData[strlen(kvLog_SendData)], "[%s]", pfun);
                TmpLen = (uint16_t)strlen(kvLog_SendData);
            }
            /* PRQA S 3344,4399 1 */ /* MISRA RULE 14.4 */
            if (plog_module->opt & KF_LOG_OPT_LINE)
            {
                (void)sprintf(kvLog_LineNum, "%d", line);
                if ((TmpLen + strlen(kvLog_LineNum) + 2U) > (sizeof(kvLog_SendData) - 1U))
                {
                    break;
                }
                (void)sprintf(&kvLog_SendData[strlen(kvLog_SendData)], "[%d]", line);
                TmpLen = (uint16_t)strlen(kvLog_SendData);
            }
            /* PRQA S 3344,4399 1 */ /* MISRA RULE 14.4 */
            if (plog_module->opt & KF_LOG_OPT_FILE)
            {
                if ((TmpLen + strlen(pfile) + 2U) > (sizeof(kvLog_SendData) - 1U))
                {
                    break;
                }
                (void)sprintf(&kvLog_SendData[strlen(kvLog_SendData)], "[%s]", pfile);
                TmpLen = (uint16_t)strlen(kvLog_SendData);
            }
        }
        /* PRQA S 3432 ++ */     /* Simple macro argument expression is not
                           parenthesized. */
        /* PRQA S 0488,0751 1 */ /* Performing pointer arithmetic. */
        va_start(args, format);
#if 0
        /* PRQA S 0432 2 */ /* Function argument is not of compatible pointer
                               type. */
        if ((TmpLen + strlen(format) + strlen(args)) > (sizeof(kvLog_SendData) - 1U))
        {
            /* PRQA S 2983 1 */ /* This assignment is redundant */
            va_end(args);
            break;
        }
#endif
        (void)vsprintf(&kvLog_SendData[strlen(kvLog_SendData)], format, args);
        /* PRQA S 2983 1 */ /* This assignment is redundant */
        va_end(args);
        /* PRQA S 3432 -- */
    } while (0);

    /* send data */
    kfLog_UartSend((uint8_t *)kvLog_SendData, (uint16_t)strlen(kvLog_SendData));
}
/* PRQA S 2934 -- */
/**
 * @brief Send a byte of data
 * @param Uartx-pointer to the USART memory structure
 * Data-send byte
 * @retval None
 */
static uint8_t kfLog_UartSendData(Usart_RegisterMap_t *Uartx, uint8_t Data)
{
    uint32_t LoopCounter;
    LoopCounter = UART_TRANSMIT_TIMEOUT;
    while ((!Usart_LL_GetIntrFlag(Uartx, USART_INT_GET_TFEIF1)) && (LoopCounter != 0U))
    {
        LoopCounter--;
    }

    if (LoopCounter == 0U)
    {
        /* error */
        return 0U;
    }

    Usart_LL_SetTxBufferData(Uartx, Data);

    return 1U;
}

/**
 * @brief send data and waits for completion
 * @param pSendData-send data point
 * SendLen-send data length
 * @retval None
 */
void kfLog_UartSend(const uint8_t *pSendData, uint16_t SendLen)
{
    uint8_t  ret;
    uint16_t Loop;

    if (((uint8_t *)0U == pSendData) || (0U == SendLen))
    {
        return;
    }

    for (Loop = 0U; Loop < SendLen; Loop++)
    {
        ret = kfLog_UartSendData(KFLOG_UART_DEV, pSendData[Loop]);
        if (ret == 0U)
        {
            return;
        }
    }
}
/* PRQA S 2889,0771 -- */

/**
 * @brief Reset and initialize the clock
 * @param None
 * @retval None
 */
static void kfLog_ResetAndEnableClock(void)
{
#if (KFLOG_UART_IDX == UART0_INDEX)
    Pclk_LL_SetUsartEnabled(PCLK_USART0, true);
    Rst_LL_SetUsartEnabled(RST_USART0, false);
    Rst_LL_SetUsartEnabled(RST_USART0, true);
#elif (KFLOG_UART_IDX == UART1_INDEX)
    Pclk_LL_SetUsartEnabled(PCLK_USART1, true);
    Rst_LL_SetUsartEnabled(RST_USART1, false);
    Rst_LL_SetUsartEnabled(RST_USART1, true);
#elif (KFLOG_UART_IDX == UART2_INDEX)
    Pclk_LL_SetUsartEnabled(PCLK_USART2, true);
    Rst_LL_SetUsartEnabled(RST_USART2, false);
    Rst_LL_SetUsartEnabled(RST_USART2, true);
#endif
}

/**
 * @brief Pin configuration of uart. PA3 and PE7 are used by default. If other
 * pins are used, you can copy this function in the file used, without using a
 * weak definition
 * @param None
 * @retval None
 */
__attribute__((weak)) void kfLog_UartPinInit(void)
{
#if (KFLOG_UART_IDX == UART0_INDEX)
    Gpio_LL_WriteModeDirectionState(GPIOB_PTR, GPIO_PIN_INDEX_4, GPIO_PIN_MODE_REMAP);
    Gpio_LL_WriteModeDirectionState(GPIOB_PTR, GPIO_PIN_INDEX_3, GPIO_PIN_MODE_REMAP);

    Gpio_LL_WriteRemapCtrlState(GPIOB_PTR, GPIO_PIN_INDEX_4, GPIO_PIN_RMP_PAGE1_AF3);
    Gpio_LL_WriteRemapCtrlState(GPIOB_PTR, GPIO_PIN_INDEX_3, GPIO_PIN_RMP_PAGE1_AF3);

#elif (KFLOG_UART_IDX == UART3_INDEX)
    Gpio_LL_WriteModeDirectionState(GPIOA_PTR, GPIO_PIN_INDEX_0, GPIO_PIN_MODE_REMAP);
    Gpio_LL_WriteModeDirectionState(GPIOA_PTR, GPIO_PIN_INDEX_1, GPIO_PIN_MODE_REMAP);

    Gpio_LL_WriteRemapCtrlState(GPIOA_PTR, GPIO_PIN_INDEX_0, GPIO_PIN_RMP_PAGE1_AF3);
    Gpio_LL_WriteRemapCtrlState(GPIOA_PTR, GPIO_PIN_INDEX_1, GPIO_PIN_RMP_PAGE1_AF3);

#endif
}

/**
 * @brief Log output initialization
 * 1.The default value is UART0. If you need to change the value, change the
 * KFLOG_UART_DEV
 * 2.The default baud rate is 230400
 * 3.8bits Data , 1 stop bit, no flow control, Odd parity
 * @param None
 * @retval None
 */
void kfLog_Init(void)
{
    uint32_t RateInteger     = 0;
    uint32_t RateMolecular   = 1;
    uint32_t RateDenominator = 0;

    uint32_t SystemClockTmp  = 0;
    uint32_t UartBaudRateTmp = 0;
    uint32_t Coefficient     = 0;

    Usart_RegisterMap_t *pUartx = KFLOG_UART_DEV;

    /* uart pin init */
    kfLog_UartPinInit();

    /* reset uart and enable clock */
    kfLog_ResetAndEnableClock();

    /* Asynchronous mode:Full-duplex mode */
    Usart_LL_SelectSerialCommMode(pUartx, false);

    /* The clock source selects bits */
    Usart_LL_SelectClkSrc(pUartx, false);
    /* 8bits */
    Usart_LL_Disable9Data(pUartx);
    /* stop bit */
    Usart_LL_SelectStopBitLen(pUartx, false);
    /* odd parity */
    Usart_LL_SelectDataOfBit9(pUartx, false);
    Usart_LL_SelectParityCheck(pUartx, false);

    /* rx\tx lsb */
    Usart_LL_SelectSendOrder(pUartx, false);
    Usart_LL_SelectRecvOrder(pUartx, false);

    /* close baud detect */
    Usart_LL_SetAutoBaudRateDetectionEnabled(pUartx, false);

    /* rx\tx enable */
    Usart_LL_SetTransmitDataEnabled(pUartx, true);
    Usart_LL_SetReceiveDataEnabled(pUartx, true);

    /* clock select */
    Usart_LL_SelectBaudRateGeneratorClk(pUartx, USART_BR_CLK_SCLK);

    /** Use 16M clock as an example to list the following baud rates
     * 	4800    z:208    x:0    y:0
     * 	9600    z:104    x:0    y:0
     * 	19200   z:52     x:0    y:0
     * 	115200  z:8      x:1    y:13
     */
    /* Baud rate conversion */
    SystemClockTmp  = KFLOG_UART_CLOCK / 100U;
    UartBaudRateTmp = KFLOG_UART_FREQUENCY / 100U;

    RateInteger = SystemClockTmp / (16U * UartBaudRateTmp);
    Coefficient = ((SystemClockTmp * 1000U) / (16U * UartBaudRateTmp)) / ((uint32_t)RateInteger);

    if (Coefficient <= 1000U)
    {
        /* When the bit is 0, the decimal baud rate generator does not affect
         * the baud rate */

        RateMolecular   = 0U;
        RateDenominator = 0U;
    }
    else
    {
        RateDenominator = RateMolecular * 1000U / (Coefficient - 1000U);
        /* Numerator and denominator register, maximum 4bits, otherwise set to 0
         */

        if (RateDenominator > 15U)
        {
            /* When the bit is 0, the decimal baud rate generator does not
             * affect the baud rate */
            RateMolecular   = 0U;
            RateDenominator = 0U;
        }
    }

    Usart_LL_SetBaudRate(pUartx, (uint16_t)RateInteger, (uint8_t)RateMolecular, (uint8_t)RateDenominator);

    /* enable uart */
    Usart_LL_Enable(pUartx);
}
#endif
/* EOF */
