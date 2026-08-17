# ChipOn Microcontroller Abstract Layer Users Manual - MCU Driver
Release V0.1 - May 2024  
Published by ChipOn 


---

## 变更记录


| 时间       | 版本 | 变更记录    |
| :--------- | :--- | :---------- |
| 2024-05-22 | 0.1  | 初       版 |


----

<a name="br4"></a> 



## 目录

- [ChipOn Microcontroller Abstract Layer Users Manual - MCU Driver](#chipon-microcontroller-abstract-layer-users-manual---mcu-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 MCU Driver概述](#第2章-mcu-driver概述)
    - [2.1 系统时钟](#21-系统时钟)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 McuGeneralConfiguration](#43-mcugeneralconfiguration)
    - [4.3.1 McuDevErrorDetect](#431-mcudeverrordetect)
    - [4.3.2 McuGetRamStateApi](#432-mcugetramstateapi)
    - [4.3.3 McuInitClock](#433-mcuinitclock)
    - [4.3.4 McuNoPll](#434-mcunopll)
    - [4.3.5 McuPerformResetApi](#435-mcuperformresetapi)
    - [4.3.6 McuVersionInfoApi](#436-mcuversioninfoapi)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Mcu\_ConfigType](#611-类型定义-mcu_configtype)
    - [6.1.2 类型定义 Mcu\_RamConfigType](#612-类型定义-mcu_ramconfigtype)
    - [6.1.3 类型定义 Mcu\_ClockConfigType](#613-类型定义-mcu_clockconfigtype)
    - [6.1.4 类型定义 Osc\_FreqConfigType](#614-类型定义-osc_freqconfigtype)
    - [6.1.5 类型定义 Sclk\_ConfigType](#615-类型定义-sclk_configtype)
    - [6.1.6 类型定义 Pll\_ConfigType](#616-类型定义-pll_configtype)
    - [6.1.7 类型定义 Pll\_CtrlParamType](#617-类型定义-pll_ctrlparamtype)
    - [6.1.8 类型定义 HSPclk\_ConfigType](#618-类型定义-hspclk_configtype)
    - [6.1.9 类型定义 LSPclk\_ConfigType](#619-类型定义-lspclk_configtype)
    - [6.1.10 类型定义 Peripheral\_ClockEnableType](#6110-类型定义-peripheral_clockenabletype)
    - [6.1.11 类型定义 Mcu\_HwConfigType](#6111-类型定义-mcu_hwconfigtype)
    - [6.1.12 类型定义 Mcu\_PowerConfigType](#6112-类型定义-mcu_powerconfigtype)
    - [6.1.13 类型定义 Mcu\_WakeupConfig](#6113-类型定义-mcu_wakeupconfig)
    - [6.1.14 类型定义 Mcu\_WakeupPinConfig](#6114-类型定义-mcu_wakeuppinconfig)
    - [6.1.15 类型定义 Mcu\_SystemConfigType](#6115-类型定义-mcu_systemconfigtype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Mcu\_Init](#621-mcu_init)
    - [6.2.2 Mcu\_InitRamSection](#622-mcu_initramsection)
    - [6.2.3 Mcu\_InitClock](#623-mcu_initclock)
    - [6.2.4 Mcu\_DistributePllClock](#624-mcu_distributepllclock)
    - [6.2.5 Mcu\_GetPllStatus](#625-mcu_getpllstatus)
    - [6.2.6 Mcu\_GetResetReason](#626-mcu_getresetreason)
    - [6.2.7 Mcu\_GetResetRawValue](#627-mcu_getresetrawvalue)
    - [6.2.8 Mcu\_PerformReset](#628-mcu_performreset)
    - [6.2.9 Mcu\_SetMode](#629-mcu_setmode)
    - [6.2.10 Mcu\_GetVersionInfo](#6210-mcu_getversioninfo)
    - [6.2.11 Mcu\_GetRamState](#6211-mcu_getramstate)
    - [6.2.12 Mcu\_LatchIO](#6212-mcu_latchio)
  - [6.3 中断处理](#63-中断处理)
  - [6.4 专有区域（EA）信息](#64-专有区域ea信息)
    - [6.4.1 专有区域信息](#641-专有区域信息)
- [第7章 数据描述](#第7章-数据描述)
  - [7.1 全局数据描述](#71-全局数据描述)
      - [表80 全局数据描述](#表80-全局数据描述)
- [第8章 错误分类](#第8章-错误分类)
  - [8.1 错误代码和描述](#81-错误代码和描述)
      - [表81 错误分类](#表81-错误分类)
- [第9章 示例用法](#第9章-示例用法)
  - [9.1 系统时钟配置注意事项](#91-系统时钟配置注意事项)
  - [9.2 宏配置](#92-宏配置)
  - [9.3 初始化](#93-初始化)
  - [9.4 IO 锁存示例](#94-io-锁存示例)
  - [9.5 配置示例](#95-配置示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)
    - [10.2.1](#1021)

---

# 第1章 引言

本用户手册提供了AUTOSAR CP R22-11的MCU驱动程序的功能、配置参数和API实现的相关信息。MCU的驱动程序初始化并提供对微控制器的访问。本用户手册旨在帮助用户熟悉MCU驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用MCU驱动程序的文档。

## 1.1 范围

本文档介绍MCU驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- MCU Driver的文件结构
- Driver的配置参数
- 由MCU Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于MCU Driver

## 1.2 缩写

| 缩写    | 解释                 |
| :------ | :------------------- |
| AUTOSAR | 汽车汽车开放系统架构 |
| DEM     | 诊断事件管理器       |
| DET     | 开发错误跟踪器       |
| MCU     | 微控制器             |
| OSC     | 振荡器               |
| PLL     | 锁相环               |
| RAM     | 随机存取存储器       |
| API     | 应用程序编程接口     |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of MCUDriver, AUTOSAR_SWS_MCUDriver.pdf Release R22-11
- [2] Requirements of MCUDriver, AUTOSAR_SRS_MCUDriver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 MCU Driver概述
KF32微控制器提供MCU操作方式。提供外设时钟配置、系统时钟配置、时钟源配置、设备休眠、RAM数据初始化默认值。

### 2.1 系统时钟
系统时钟通过MCU驱动程序设置。配置主频最高120M，参考用户手册。

---

# 第3章 文件结构
本节提供了有关MCU Driver文件和其他相关文件的详细信息。
| Name                  | Description                                     |
| :-------------------- | :---------------------------------------------- |
| Mcu.c                 | 此文件包含MCU驱动程序的通用功能                 |
| Mcu.h                 | 此头文件输出MCU驱动程序的宏、类型定义和函数原型 |
| Mcu_Cfg.h             | 本文在这里声明了MCU驱动程序的配置数据。         |
| Mcu_Im.c              | 此文件包含MCU模块所需要的硬件驱动程序           |
| Mcu_Im.h              | 此头文件输出MCU驱动程序的宏、类型定义和函数原型 |
| Mcu_Types.h           | 结构体定义                                      |
| Mcu_Lcfg.c            | 初始化变量定义                                  |
| Stop0_Wakeup_Vector.c | 休眠唤醒中断处理                                |
| Reload_Kernel.a       | 休眠函数处理库                                  |
| Reload_Kernel.h       | 休眠函数声明                                    |

---

# 第4章 配置文档

## 4.1 配置概念

### 4.1.1 配置类
开发基本软件驱动涉及以下开发周期：
- 编译
- 链接
- 下载可执行文件到ECU内存

根据配置参数的配置类别，配置类如下分类：
- 预编译时间：通过编译器开关或影响整个构建过程的变量实现。
- 链接时间：不影响编译阶段，但影响链接和定位阶段。
- 构建后时间：不会影响构建过程，因此构建后时间配置在运行时应用于驱动器。


## 4.2 配置参数变化
本节描述了相对于支持的微控制器的配置参数的变化。MCU Driver在支持的微控制器上没有变化的参数。

## 4.3 McuGeneralConfiguration
本节详细描述了MCU Driver提供的配置，包括AUTOSAR MCU Driver规范[1]中描述的配置以及特定于微控制器的配置。

### 4.3.1 McuDevErrorDetect
- **名称**: McuDevErrorDetect
- **来源**: AUTOSAR定义
- **文件**: Mcu_Cfg.h
- **范围**: 值：STD_ON – 打开检测，STD_OFF – 不打开检测 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.2 McuGetRamStateApi
- **名称**: McuGetRamStateApi
- **来源**: AUTOSAR定义
- **文件**: Mcu_Cfg.h
- **范围**: 值：STD_ON – 支持获取RAM状态，STD_OFF – 不支持获取RAM状态 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.3 McuInitClock
- **名称**: McuInitClock
- **来源**: AUTOSAR定义
- **文件**: Mcu_Cfg.h
- **范围**: 值：STD_ON – 支持时钟初始化，STD_OFF – 不支持时钟初始化 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.4 McuNoPll
- **名称**: McuNoPll
- **来源**: AUTOSAR定义
- **文件**: Mcu_Cfg.h
- **范围**: 值：STD_ON – 无锁相环，STD_OFF – 有锁相环 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.5 McuPerformResetApi
- **名称**: McuPerformResetApi
- **来源**: AUTOSAR定义
- **文件**: Mcu_Cfg.h
- **范围**: 值：STD_ON – 支持软件复位功能，STD_OFF – 不支持软件复位功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.6 McuVersionInfoApi
- **名称**: McuVersionInfoApi
- **来源**: AUTOSAR定义
- **文件**: Mcu_Cfg.h
- **范围**: 值：STD_ON – 支持获取版本号，STD_OFF – 不支持获取版本号 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: MCU_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Mcu.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: MCU_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: Mcu.h
- **值**: 101
- **描述**: 这个宏给出了MCU驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: MCU_INSTANCE_ID
- **类型**: 宏定义 (#define)
- **文件**: Mcu.h
- **值**: 0
- **描述**: 这个宏给出了MCU驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: MCU_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Mcu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: MCU_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Mcu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: MCU_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Mcu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Mcu_ConfigType
- **语法**: Mcu_ConfigType
- **类型**: Struct
- **文件**: Mcu.h
- **范围**: 
  - **Mcu_ClockNotificationType**
    - ClkSrcFailureNotification - 时钟起振错误，默认关闭
  - **uint8**
    - NumOfRamConfigs - RAM初始化数量    
  - **uint8**
    - NumOfClkConfigs - 时钟配置个数
  - **Mcu_RamConfigType (*RamConfigPtr)[MCU_MAX_RAMCONFIGS]**
    - RamConfigPtr - RAM测试配置    
  - **Mcu_ClockConfigType (*ClockConfigPtr)[MCU_MAX_CLOCKCONFIGS]**
    - ClockConfigPtr - 时钟配置
  - **Mcu_HwConfigType**
    - HwConfigPtr - 低功耗配置                 
- **描述**: 此类型定义用于配置MCU的整体配置。此类型的指针在Mcu_Init API中用于初始化MCU时钟驱动程序。

### 6.1.2 类型定义 Mcu_RamConfigType
- **语法**: Mcu_RamConfigType
- **类型**: Struct
- **文件**: Mcu.h
- **范围**: 
  - **Mcu_RamSectionType**
    - Mcu_RamSectorId - RAM序号
  - **uint64**
    - Mcu_RamBaseAddress - RAM初始化地址    
  - **uint32**
    - Mcu_RamSize - 初始化大小
  - **uint64**
    - Mcu_RamDefaultValue - 初始化值    
  - **uint32**
    - Mcu_RamWriteSize - 初始化数据每组数据大小         
- **描述**: 此类型定义用于配置RAM测试配置。在Mcu_InitRamSection API中用于初始化RAM默认数据。

### 6.1.3 类型定义 Mcu_ClockConfigType
- **语法**: Mcu_ClockConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **Osc_InnerLFConfigType**
    - InnerLFConfig - 内部低频配置
  - **Osc_InnerHFConfigType**
    - InnerHFConfig - 内部高频配置    
  - **Osc_OuterLFConfigType**
    - OuterLFConfig - 外部低频配置
  - **Osc_OuterHFConfigType**
    - OuterHFConfig - 外部高频配置    
  - **Sclk_ConfigType**
    - SclkConfig - 系统时钟配置
  - **Pll_ConfigType**
    - PllConfig - pll配置        
  - **HSPclk_ConfigType**
    - HSPclkConfig - 高频外设配置      
  - **LSPclk_ConfigType**
    - LSPclkConfig - 低频外设配置   
  - **Peripheral_ClockEnableType**
    - PclkEnConfig - 外设模块时钟配置          
- **描述**: 此类型定义用于配置MCU时钟的整体配置。

### 6.1.4 类型定义 Osc_FreqConfigType
- **语法**: Osc_FreqConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **boolean**
    - Enabled - 是否启用时钟配置
  - **boolean**
    - AllowIntr - 未使用    
  - **uint32**
    - Delay - 延时时间配置         
- **描述**: 此类型定义用于配置MCU时钟的选择配置。

### 6.1.5 类型定义 Sclk_ConfigType
- **语法**: Sclk_ConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **Sclk_SourceType**
    - ClockSource - 系统时钟源
  - **Sclk_DivisionFactorType**
    - Division - 分频系数        
- **描述**: 此类型定义用于配置MCU系统时钟源配置。

### 6.1.6 类型定义 Pll_ConfigType
- **语法**: Pll_ConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **Pll_SourceType**
    - ClockSource - PLL时钟源
  - **uint8**
    - Delay - 延时时间      
  - **boolean**
    - IsClockDivBy2 - 分频系数
  - **Pll_CtrlParamType**
    - Control - PLL配置参数         
- **描述**: 此类型定义用于PLL配置。

### 6.1.7 类型定义 Pll_CtrlParamType
- **语法**: Pll_CtrlParamType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **uint32**
    - OD - PLL时钟源
  - **uint32**
    - N - 延时时间      
  - **uint32**
    - M - 分频系数    
- **描述**: 此类型定义用于PLL具体参数配置。

### 6.1.8 类型定义 HSPclk_ConfigType
- **语法**: HSPclk_ConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **boolean**
    - Enabled - 是否启用高频外设
  - **HFclk_SourceType**
    - ClockSource - 高频外设时钟源      
  - **uint8**
    - Division - 分频系数    
- **描述**: 此类型定义用于高频外设具体参数配置。

### 6.1.9 类型定义 LSPclk_ConfigType
- **语法**: LSPclk_ConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **boolean**
    - Enabled - 是否启用低频外设
  - **LFclk_SourceType**
    - ClockSource - 低频外设时钟源      
  - **uint8**
    - Division - 分频系数    
- **描述**: 此类型定义用于低频外设具体参数配置。

### 6.1.10 类型定义 Peripheral_ClockEnableType
- **语法**: Peripheral_ClockEnableType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **uint32**
    - PclkCtrlGroup_0 - 外设时钟配置0
  - **uint32**
    - PclkCtrlGroup_1 - 外设时钟配置1      
  - **uint32**
    - PclkCtrlGroup_2 - 外设时钟配置2    
  - **uint32**
    - PclkCtrlGroup_3 - 外设时钟配置3     
  - **uint32**
    - PclkCtrlGroup_4 - 外设时钟配置4         
- **描述**: 此类型定义用于外设时钟源具体参数配置。

### 6.1.11 类型定义 Mcu_HwConfigType
- **语法**: Mcu_HwConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **Mcu_PowerConfigType**
    - PMConfig - 外设时钟配置0
  - **Mcu_SystemConfigType**
    - SMConfig - 外设时钟配置1            
- **描述**: 此类型定义用于低功耗具体参数配置。

### 6.1.12 类型定义 Mcu_PowerConfigType
- **语法**: Mcu_PowerConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **boolean**
    - Mcu_PinWkupEnableSta - 是否启用pin唤醒
  - **Mcu_WakeupConfig**
    - Mcu_WkupConfig - 管脚唤醒配置   
  - **boolean**
    - Mcu_T0WkupEnableSta - T0唤醒，只有STOP0模式支持
  - **uint32**
    - Mcu_T0WkupTime - 唤醒时间，单位毫秒     
  - **Mcu_SleepConfigType**
    - Mcu_SleepType - 休眠类型                   
- **描述**: 此类型定义用于休眠具体参数配置。

### 6.1.13 类型定义 Mcu_WakeupConfig
- **语法**: Mcu_WakeupConfig
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **uint32**
    - WakeupNumber - 唤醒个数
  - **Mcu_WakeupPinConfig**
    - WakeupPinConfig - 管脚唤醒具体参数                   
- **描述**: 此类型定义用于管脚具体参数配置。

### 6.1.14 类型定义 Mcu_WakeupPinConfig
- **语法**: Mcu_WakeupPinConfig
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **Mcu_WkupIndexType**
    - WakeupIndex - 唤醒PIN
  - **Mcu_WakeupEdgeType**
    - WakeupEdge - 管脚唤醒边沿类型      
  - **boolean**
    - WakeupFixLvEnable - 休眠前是否配置管脚状态                         
- **描述**: 此类型定义用于休眠唤醒管脚具体参数配置。

### 6.1.15 类型定义 Mcu_SystemConfigType
- **语法**: Mcu_SystemConfigType
- **类型**: Struct
- **文件**: Mcu_Types.h
- **范围**: 
  - **uint32**
    - EnableCache - CACHE使能状态
  - **uint32**
    - EnableRamEcc - RAMECC使能状态      
  - **uint32**
    - EnableCacheEccIntr - CACHEECC中断使能状态    
  - **uint32**
    - EnableRamEccIntr - RAMECC中断使能状态      
  - **uint32**
    - EnableFlashEccIntr - FLASHECC中断使能状态                          
- **描述**: 此类型定义用于硬件参数具体参数配置。

---
## 6.2 API函数

### 6.2.1 Mcu_Init
- **服务名称**: `Mcu_Init`
- **语法**: `void Mcu_Init (const Mcu_ConfigType* ConfigPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: ConfigPtr: 配置参数指针
- **返回值**: 无
- **描述**: MCU初始化
- **注意事项**: 无

### 6.2.2 Mcu_InitRamSection
- **服务名称**: `Mcu_InitRamSection`
- **语法**: `Std_ReturnType Mcu_InitRamSection (Mcu_RamSectionType RamSection)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 异步
- **可重入**: 不可重入
- **参数(输入)**: RamSection-索引号
- **参数(输出)**: 无
- **返回值**: E_OK-RAM默认值初始化成功
- **返回值**: E_NOT_OK-RAM默认值初始化失败
- **描述**: 初始化RAM默认参数
- **注意事项**: 无

### 6.2.3 Mcu_InitClock
- **服务名称**: `Mcu_InitClock`
- **语法**: `Std_ReturnType Mcu_InitClock (Mcu_ClockType ClockSetting)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: ClockSetting-索引号
- **参数(输出)**: 无
- **返回值**: E_OK-时钟初始化成功
- **返回值**: E_NOT_OK-时钟初始化出错
- **描述**: 系统时钟初始化
- **注意事项**: 无 

### 6.2.4 Mcu_DistributePllClock
- **服务名称**: `Mcu_DistributePllClock`
- **语法**: `Std_ReturnType Mcu_DistributePllClock (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: E_OK-时钟分频成功
- **返回值**: E_NOT_OK-时钟分频出错
- **描述**: PLL分频
- **注意事项**: 无

### 6.2.5 Mcu_GetPllStatus
- **服务名称**: `Mcu_GetPllStatus`
- **语法**: `Mcu_PllStatusType Mcu_GetPllStatus (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: MCU_PLL_STATUS_UNDEFINED-PLL状态出错
- **返回值**: MCU_PLL_LOCKED-PLL锁定
- **返回值**: MCU_PLL_UNLOCKED-PLL未锁定
- **描述**: 获取PLL状态
- **注意事项**: 无

### 6.2.6 Mcu_GetResetReason
- **服务名称**: `Mcu_GetResetReason`
- **语法**: `Mcu_ResetType Mcu_GetResetReason (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x05
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: MCU_WATCHDOG_RESET-看门狗复位
- **返回值**: MCU_POR_RESET-上电复位
- **返回值**: MCU_BOR_RESET-低电复位
- **返回值**: MCU_SW_RESET-软件复位
- **描述**: 获取复位原因
- **注意事项**: 无

### 6.2.7 Mcu_GetResetRawValue
- **服务名称**: `Mcu_GetResetRawValue`
- **语法**: `Mcu_RawResetType Mcu_GetResetRawValue (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x06
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 复位原因原始值
- **描述**: 复位原因原始值
- **注意事项**: 无

### 6.2.8 Mcu_PerformReset
- **服务名称**: `Mcu_PerformReset`
- **语法**: `void Mcu_PerformReset (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x07
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 执行复位
- **注意事项**: 无

### 6.2.9 Mcu_SetMode
- **服务名称**: `Mcu_SetMode`
- **语法**: `void Mcu_SetMode (Mcu_ModeType McuMode)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x08
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: McuMode-休眠索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 进入休眠
- **注意事项**: 无

### 6.2.10 Mcu_GetVersionInfo
- **服务名称**: `Mcu_GetVersionInfo`
- **语法**: `void Mcu_GetVersionInfo (Std_VersionInfoType* versioninfo)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x09
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:无
- **参数(输出)**: versioninfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无

### 6.2.11 Mcu_GetRamState
- **服务名称**: `Mcu_GetRamState`
- **语法**: `Mcu_RamStateType Mcu_GetRamState (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0A
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: MCU_RAMSTATE_INVALID-RAM状态无效
- **返回值**: MCU_RAMSTATE_VALID-RAM状态有效
- **描述**: 获取RAM状态
- **注意事项**: 无

### 6.2.12 Mcu_LatchIO
- **服务名称**: `Mcu_LatchIO`
- **语法**: `void Mcu_LatchIO (bool)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: true or false
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置IO锁存状态，true-锁存IO,false-不锁存IO
- **注意事项**: 无
-----

## 6.3 中断处理

无

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

MCU Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是MCU Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                     | 类型/范围          | 描述                   |
| ------------------------ | ------------------ | ---------------------- |
| Mcu_ConfigPtr            | Mcu_ConfigType     | 保存配置参数指针       |
| Mcu_CurrentClockIndex    | Mcu_ClockType      | 使用时钟配置索引号     |
| Mcu_Wkp_Port             | GPIO_RegisterMap_t | PORT指针               |
| Mcu_Wkp_Pin              | Gpio_PinIndex_t    | 休眠唤醒管脚           |
| Mcu_ModeConfiguredStatus | boolean            | 记录是否为Normal Sleep |
| Mcu_ModeCfgRecorder      | Mcu_ModeCfgType    | 休眠信息记录           |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是MCU Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                  | 错误描述                 | 值（十六进制） |
| ------------------------- | ------------------------ | -------------- |
| MCU_E_PARAM_CONFIG        | 未使用                   | 0x0A           |
| MCU_E_PARAM_CLOCK         | 时钟索引入参号错误       | 0x0B           |
| MCU_E_PARAM_MODE          | 休眠索引号入参错误       | 0x0C           |
| MCU_E_PARAM_RAMSECTION    | 未使用                   | 0x0D           |
| MCU_E_PLL_NOT_LOCKED      | 未使用                   | 0x0E           |
| MCU_E_UNINIT              | MCU未初始化              | 0x0F           |
| MCU_E_PARAM_POINTER       | 配置参数内硬件参数空指针 | 0x10           |
| MCU_E_INIT_FAILED         | 初始化参数不符合要求     | 0x11           |
| MCU_E_ALREADY_INITIALIZED | 重复初始化               | 0x13           |

-----
# 第9章 示例用法
本章描述了如何配置MCU驱动器以及如何在应用程序中使用MCU驱动器提供的不同的API。

## 9.1 系统时钟配置注意事项

- 配置注意事项
 - 1MHz≤(FREF/N)≤50MHz
 - 200MHz≤(FREF×M/N)≤400MHz
 - M≥4
 - N≥1 

## 9.2 宏配置

```c
#define MCU_HSRUN_FREQUENCY_HZ (120000000U)
#define MCU_MAX_SUPPORTED_MODE (2U)
#define MCU_DEV_ERROR_DETECT (STD_OFF)
#define MCU_VERSION_INFO_API (STD_ON)
#define MCU_GET_RAM_STATE_API (STD_OFF)
#define MCU_INIT_CLOCK (STD_ON)
#define MCU_NO_PLL (STD_OFF)
#define MCU_PERFORM_RESET_API (STD_ON)
#define MCU_POWERMODE_STATE_API (STD_OFF)
#define MCU_DISABLE_DEM_REPORT_ERROR_STATUS (STD_ON)
#define MCU_MAX_CLOCKCONFIGS ((uint32)1U)
#define MCU_MAX_RAMCONFIGS ((uint32)1U)
#define MCU_PRECOMPILE_SUPPORT (STD_OFF)
#define MCU_RAW_RESET_DEFAULT ((uint32)0xFFFFFFFFU)
#define MCU_INNER_LOW_FREQ_IN_LOW_POWER_MODE (STD_OFF)
#define MCU_INNER_HIGH_FREQ_IN_LOW_POWER_MODE (STD_OFF)
#define MCU_OUTER_LOW_FREQ_IN_LOW_POWER_MODE (STD_OFF)
#define PVD_DETECT_VDD_TIMES ((uint32)30U)
#define WAIT_VDD_TIME ((uint32)1000U)
```
## 9.3 初始化

```c
  Mcu_Init(&Mcu_ConfigPredefined);
  Mcu_InitClock(0);
  while (Mcu_GetPllStatus() == 0)
        ;
  Mcu_DistributePllClock();
```

## 9.4 IO 锁存示例

使用前提，配置'#define MCU_IO_LATCH_STATE_IN_STANDBY (STD_ON)',Mcu_LatchIo需要配对使用，休眠前使能锁存，唤醒后初始化完port后关闭锁存。
```c
  Port_Init(&Port_ConfigPredefined);
  /* port初始化后，解锁锁存状态 */
  Mcu_LatchIO(FALSE);

  ....

  /* 进入低功耗模式前锁存IO */
  Mcu_LatchIO(TRUE);
  Mcu_SetMode(1);
```

## 9.5 配置示例

- 时钟计算公式(手册有详细说明)
 - PLLCLK = FREF * (1/NO) * (M/N)
 - 示例中PLLCLK = 16 * (1/2) * (15/1) = 120;

配置系统时钟120M(配置时钟时候，)；系统时钟源PLL；使能高频外设；RAM开启默认值初始化区域；休眠支持MCU_SLEEP_NORMAL、MCU_SLEEP_STANDBY(MCU_WKUP2唤醒)和MCU_SLEEP_STOP0(6秒后唤醒或MCU_WKUP2唤醒)；配置外设模块时钟使能

```c
#define PCLK_CTRL0_VALUE                                                                                               \
    ((uint32)((0U) | (GPIOAPCLKEN << 0U) | (GPIOBPCLKEN << 1U) | (GPIOCPCLKEN << 2U) | (GPIODPCLKEN << 3U) |           \
              (GPIOEPCLKEN << 4U) | (GPIOFPCLKEN << 5U) | (GPIOGPCLKEN << 6U) | (GPIOHPCLKEN << 7U) |                  \
              (GPIOJPCLKEN << 8U) | (GPIOKPCLKEN << 9U)))

#define PCLK_CTRL1_VALUE                                                                                               \
    (uint32)(                                                                                                          \
      (0U) | (T1PCLKEN << 2U) | (T2PCLKEN << 3U) | (T3PCLKEN << 4U) | (T4PCLKEN << 5U) | (T5T6PCLKEN << 6U) |          \
      (T9T10PCLKEN << 8U) | (T25T26PCLKEN << 9U) | (ADC0PCLKEN << 11U) | (ADC1PCLKEN << 12U) | (ADC2PCLKEN << 13U) |   \
      (T0PCLKEN << 17U) | (USART0PCLKEN << 19U) | (USART1PCLKEN << 20U) | (USART2PCLKEN << 21U) |                      \
      (USART3PCLKEN << 22U) | (SPI0PCLKEN << 24U) | (SPI1PCLKEN << 25U) | (I2C0PCLKEN << 26U) | (I2C1PCLKEN << 27U) |  \
      (I2C2PCLKEN << 28U) | (MPUPCLKEN << 30U))

#define PCLK_CTRL2_VALUE                                                                                               \
    (uint32)(                                                                                                          \
      (0U) | (ISMUTESTPCLKEN << 4U) | (WWDTPCLKEN << 5U) | (EPWM11PCLKEN << 8U) | (EPWM12PCLKEN << 9U) |               \
      (EPWM13PCLKEN << 10U) | (EPWM16PCLKEN << 11U) | (DMA0PCLKEN << 12U) | (AES1PCLKEN << 13U) |                      \
      (DMA1PCLKEN << 14U) | (ECC18PCLKEN << 15U) | (T14PCLKEN << 16U) | (ECC17PCLKEN << 18U) | (ECC16PCLKEN << 19U) |  \
      (T18PCLKEN << 21U) | (T19PCLKEN << 22U) | (T21PCLKEN << 24U) | (T22PCLKEN << 25U) | (T23PCLKEN << 26U))

#define PCLK_CTRL3_VALUE                                                                                               \
    (uint32)((0U) | (SPI2PCLKEN << 1U) | (CMUPCLKEN << 12U) | (CRCPCLKEN << 13U) | (AESPCLKEN << 14U) |                \
             (FLEXRMPCLKEN << 25U) | (EWDTPCLKEN << 27U) | (CANFD6PCLKEN << 29U) | (CANFD7PCLKEN << 30U) |             \
             (ECC15PCLKEN << 31U))

/* PRQA S 1504  ++  */
/**
 * @brief ram init data
 */
uint8 RamInitData[140] = {0U};

/**
 * @brief wake up pin configuration
 */
static const Mcu_WakeupPinConfig Stop0_WakeupPinConfig[] = {
  {
    /** KEY1 */
    .WakeupIndex       = MCU_WKUP3,
    .WakeupEdge        = MCU_WAKEUP_EDGE_FALL,
    .WakeupFixLvEnable = FALSE,
  },
  {
    /** PC0 */
    .WakeupIndex       = MCU_WKUP2,
    .WakeupEdge        = MCU_WAKEUP_EDGE_FALL,
    .WakeupFixLvEnable = TRUE,
  },
};

/**
 * @brief wake up configuration
 */
/* PRQA S 0311 ++ */
static const Mcu_WakeupConfig Stop0_WakeupConfig = {
  .WakeupPinConfig = (Mcu_WakeupPinConfig *)Stop0_WakeupPinConfig,
  .WakeupNumber    = (sizeof(Stop0_WakeupPinConfig) / sizeof(Mcu_WakeupPinConfig)),
};

/**
 * @brief wake up pin configuration
 */
static const Mcu_WakeupPinConfig Standby_WakeupPinConfig[] = {
  {
    .WakeupIndex       = MCU_WKUP3,
    .WakeupEdge        = MCU_WAKEUP_EDGE_FALL,
    .WakeupFixLvEnable = FALSE,
  },
  {
    /** PC0 */
    .WakeupIndex       = MCU_WKUP2,
    .WakeupEdge        = MCU_WAKEUP_EDGE_FALL,
    .WakeupFixLvEnable = TRUE,
  },
};

/**
 * @brief wake up configuration
 */
static const Mcu_WakeupConfig Standby_WakeupConfig = {
  .WakeupPinConfig = (Mcu_WakeupPinConfig *)Standby_WakeupPinConfig,
  .WakeupNumber    = (sizeof(Standby_WakeupPinConfig) / sizeof(Mcu_WakeupPinConfig)),
};

/**
 * @brief Initialization mcu pmc register.
 * @details Static configuration realized by calling Mcu_Init() API.
 *
 */
const Mcu_PowerConfigType Mcu_PmcConfigData[3U] = {
  [0U] =
    {
      .Mcu_SleepType = MCU_SLEEP_NORMAL,
    },
  [1U] =
    {
      .Mcu_PinWkupEnableSta = TRUE,
      .Mcu_WkupConfig       = (Mcu_WakeupConfig *)&Standby_WakeupConfig,
      /* Used in STOP0 only */
      .Mcu_T0WkupEnableSta = FALSE,
      .Mcu_T0WkupTime      = 0U,
      .Mcu_SleepType       = MCU_SLEEP_STANDBY,
    },
  [2U] =
    {
      .Mcu_PinWkupEnableSta = TRUE,
      .Mcu_WkupConfig       = (Mcu_WakeupConfig *)&Stop0_WakeupConfig,
      /* Used in STOP0 only */
      .Mcu_T0WkupEnableSta = TRUE,
      /* config 6second wake up */
      .Mcu_T0WkupTime = 6000U,
      .Mcu_SleepType  = MCU_SLEEP_STOP0,
    },
};

/**
 * @brief Initialization mcu Cache register.
 * @details Static configuration realized by calling Mcu_Init() API.
 *
 */
const Mcu_SystemConfigType Mcu_SystemConfigData = {
  .EnableCache        = STD_OFF,
  .EnableRamEcc       = STD_OFF,
  .EnableCacheEccIntr = STD_OFF,
  .EnableFlashEccIntr = STD_OFF,
  .EnableRamEccIntr   = STD_OFF,
};
/* PRQA S 0310,3305 ++ */
const Mcu_RamConfigType Mcu_RamSectionData[MCU_MAX_RAMCONFIGS] = {
  [0U] = {
    .Mcu_RamSectorId     = 0U,
    .Mcu_RamBaseAddress  = (uint64 *)&RamInitData[0U],
    .Mcu_RamSize         = 128U,
    .Mcu_RamDefaultValue = 0x5A5A5A5A5A5A5A5A,
    .Mcu_RamWriteSize    = 4U,
  }};

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief Initialization clock data.
 * @details Static configuration realized by calling Mcu_InitClock() API.
 *
 */
const Mcu_ClockConfigType Mcu_ClockConfigData[MCU_MAX_CLOCKCONFIGS] = {
  [0U] =
    {
      .InnerLFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 0U,
          .Enabled   = STD_OFF,
        },
      .InnerHFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 0U,
          .Enabled   = STD_OFF,
        },
      .OuterLFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 0U,
          .Enabled   = STD_OFF,
        },
      .OuterHFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 0U,
          .Enabled   = STD_ON,
        },
      .SclkConfig =
        {
          .ClockSource = SCLK_SOURCE_PLL,
          .Division    = SCLK_DIVISION_1,
        },
      .LSPclkConfig =
        {
          .ClockSource = LFCLK_INPUT_INTLF,
          .Division    = 0U,
          .Enabled     = STD_OFF,
        },
      .HSPclkConfig =
        {
          .ClockSource = HFCLK_SOURCE_EXTHF,
          .Division    = 0U,
          .Enabled     = STD_ON,
        },
      .PllConfig =
        {
          /* External HF */
          .ClockSource   = PLL_SOURCE_EXTHF,
          .IsClockDivBy2 = (boolean)FALSE,
          .Control =
            {
              .M  = 15U,
              .N  = 1U,
              .OD = 1U,
            },
          .Delay = 0U,
        },
      .PclkEnConfig =
        {
          .PclkCtrlGroup_0 = (uint32)PCLK_CTRL0_VALUE,
          .PclkCtrlGroup_1 = (uint32)PCLK_CTRL1_VALUE,
          .PclkCtrlGroup_2 = (uint32)PCLK_CTRL2_VALUE,
          .PclkCtrlGroup_3 = (uint32)PCLK_CTRL3_VALUE,
        },
    },
};
#endif

/**
 * @brief Initialization data for different hw IPs.
 * @details Static configuration realized at statup by calling Mcu_Init()
 * API.
 *
 */
const Mcu_HwConfigType Mcu_HwConfig = {
  /* Configuration for PMC.  */
  .PMConfig = &Mcu_PmcConfigData[0U],
  /*Configuration for CACHE . */
  .SMConfig = &Mcu_SystemConfigData,
};

/**
 * @brief Initialization data for the MCU driver.
 * @details A pointer to such a structure is provided to the MCU
 * initialization routines for configuration.
 *
 */
/* PRQA S 3211 2 */ /* The global identifier 'Mcu_ConfigPredefined' is defined
                       here but is not used in this translation unit. */
const Mcu_ConfigType Mcu_ConfigPredefined = {
#if (MCU_INIT_CLOCK == STD_ON)
  .ClkSrcFailureNotification = MCU_CLK_NOTIF_DISABLE,
#endif
  /* Number of RAM Sections configurations. */
  .NumOfRamConfigs = (uint8)1U,
#if (MCU_INIT_CLOCK == STD_ON)
  /* Number of Clock Setting configurations. */
  .NumOfClkConfigs = (uint8)1U,
#endif
  /* ram data configuration */
  .RamConfigPtr = &Mcu_RamSectionData,
#if (MCU_INIT_CLOCK == STD_ON)
  /* Pointer to Clock configurations. */
  .ClockConfigPtr = &Mcu_ClockConfigData,
#endif
  /* Pointer to Low Level Mcu driver configuration. */
  .HwConfigPtr = &Mcu_HwConfig,
};
```
---

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 表82 假设

| 序号 | 参考 | 假设 |
| ---- | ---- | ---- |
| 1    | 通用 |      |
| 2    | 通用 |      |

### 偏差


### 考虑的Bugzilla

- 不支持取消操作。
- 不支持异步读写。


## 10.2 限制

### 10.2.1




