# ChipOn Microcontroller Abstract Layer Users Manual - GPT Driver
Release V0.1 - May 2024  
Published by ChipOn

---

## 变更记录


| 时间       | 版本 | 变更记录    |
| :--------- | :--- | :---------- |
| 2024-05-15 | 0.1  | 初       版 |


----

<a name="br4"></a> 



## 目录

- [ChipOn Microcontroller Abstract Layer Users Manual - GPT Driver](#chipon-microcontroller-abstract-layer-users-manual---gpt-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 GPT Driver概述](#第2章-gpt-driver概述)
    - [2.1 软件硬件模块映射](#21-软件硬件模块映射)
    - [2.1.1 通用定时器](#211-通用定时器)
    - [2.1.2 GPT](#212-gpt)
    - [2.1.3 IRQ](#213-irq)
    - [2.1.4 系统时钟](#214-系统时钟)
    - [2.1.4.1 软件驱动程序描述](#2141-软件驱动程序描述)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 GptDriverConfiguration](#43-gptdriverconfiguration)
    - [4.3.1 GptDevErrorDetect](#431-gptdeverrordetect)
    - [4.3.2 GptReportWakeupSource](#432-gptreportwakeupsource)
    - [4.3.3 GPT\_PRECOMPILE\_SUPPORT](#433-gpt_precompile_support)
  - [4.4 GptConfigurationOfOptApiServices](#44-gptconfigurationofoptapiservices)
    - [4.4.1 GptVersionInfoApi](#441-gptversioninfoapi)
    - [4.4.2 GptDeInitApi](#442-gptdeinitapi)
    - [4.4.3 GptTimeElapsedApi](#443-gpttimeelapsedapi)
    - [4.4.4 GptTimeRemainingApi](#444-gpttimeremainingapi)
    - [4.4.5 GptEnableDisableNotificationApi](#445-gptenabledisablenotificationapi)
    - [4.4.6 GptWakeupFunctionalityApi](#446-gptwakeupfunctionalityapi)
  - [4.5 Gpt\_ConfigPredefined](#45-gpt_configpredefined)
    - [4.5.1 g\_channel\_configs](#451-g_channel_configs)
      - [4.5.1.1 ChanHwIndex](#4511-chanhwindex)
      - [4.5.1.5 Prescale](#4515-prescale)
      - [4.5.1.6 EnableWakeUp](#4516-enablewakeup)
      - [4.5.1.7 NotifyFcn](#4517-notifyfcn)
      - [4.5.1.8 ClkSrc](#4518-clksrc)
      - [4.5.1.9 ChannelCount](#4519-channelcount)
      - [4.5.1.10 ChannelConfigPtr](#45110-channelconfigptr)
      - [4.5.1.11 PredefTimeConfig](#45111-predeftimeconfig)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Gpt\_ConfigType](#611-类型定义-gpt_configtype)
    - [6.1.2 类型定义 Gpt\_ChannelConfigType](#612-类型定义-gpt_channelconfigtype)
    - [6.1.3 类型定义 Gpt\_PredefTimeConfigType](#613-类型定义-gpt_predeftimeconfigtype)
    - [6.1.4 类型定义 Gpt\_ChannelType](#614-类型定义-gpt_channeltype)
    - [6.1.5 类型定义 Gpt\_ValueType](#615-类型定义-gpt_valuetype)
    - [6.1.6 类型定义 Gpt\_ModeType](#616-类型定义-gpt_modetype)
    - [6.1.7 类型定义 EcuM\_WakeupSourceType](#617-类型定义-ecum_wakeupsourcetype)
    - [6.1.8 类型定义 Gpt\_TimerEnumType](#618-类型定义-gpt_timerenumtype)
    - [6.1.9 类型定义 Gpt\_PredefTimerType](#619-类型定义-gpt_predeftimertype)
    - [6.1.10 类型定义 Gpt\_ChannelStatusType](#6110-类型定义-gpt_channelstatustype)
    - [6.1.11 类型定义 Gpt\_ChannelModeType](#6111-类型定义-gpt_channelmodetype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Gpt\_GetVersionInfo](#621-gpt_getversioninfo)
    - [6.2.2 Gpt\_Init](#622-gpt_init)
    - [6.2.3 Gpt\_DeInit](#623-gpt_deinit)
    - [6.2.4 Gpt\_GetTimeElapsed](#624-gpt_gettimeelapsed)
    - [6.2.5 Gpt\_GetTimeRemaining](#625-gpt_gettimeremaining)
    - [6.2.6 Gpt\_StartTimer](#626-gpt_starttimer)
    - [6.2.7 Gpt\_StopTimer](#627-gpt_stoptimer)
    - [6.2.8 Gpt\_SetMode](#628-gpt_setmode)
    - [6.2.9 Gpt\_EnableNotification](#629-gpt_enablenotification)
    - [6.2.10 Gpt\_DisableNotification](#6210-gpt_disablenotification)
    - [6.2.11 Gpt\_DisableWakeup](#6211-gpt_disablewakeup)
    - [6.2.12 Gpt\_EnableWakeup](#6212-gpt_enablewakeup)
    - [6.2.13 Gpt\_CheckWakeup](#6213-gpt_checkwakeup)
    - [6.2.14 Gpt\_GetPredefTimerValue](#6214-gpt_getpredeftimervalue)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Gpt\_Isr](#631-gpt_isr)
      - [表79 服务请求节点 - GPT硬件资源](#表79-服务请求节点---gpt硬件资源)
  - [6.4 专有区域（EA）信息](#64-专有区域ea信息)
    - [6.4.1 专有区域信息](#641-专有区域信息)
- [第7章 数据描述](#第7章-数据描述)
  - [7.1 全局数据描述](#71-全局数据描述)
      - [表80 全局数据描述](#表80-全局数据描述)
- [第8章 错误分类](#第8章-错误分类)
  - [8.1 错误代码和描述](#81-错误代码和描述)
      - [表81 错误分类](#表81-错误分类)
- [第9章 示例用法](#第9章-示例用法)
  - [9.1 驱动器配置](#91-驱动器配置)
    - [9.1.1 驱动器的示例配置](#911-驱动器的示例配置)
        - [通道配置实例](#通道配置实例)
      - [9.1.11 驱动器初始化](#9111-驱动器初始化)
    - [9.1.2 API用法示例](#912-api用法示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)
    - [10.2.1 中断延迟](#1021-中断延迟)


[**1**](#br8) [**引言**](#br8)[](#br8)[...........................................................................................................................................](#br8)

[1.1](#br8) [范围](#br8)[ ](#br8)[........................................................................................................................................](#br8)

[1.2](#br8) [缩写.........................................................................................................................................](#br8)

[1.3](#br9)  [参考.........................................................................................................................................](#br9)

[**2**](#br8) [**GPT Driver 概述**](#br8)[](#br8)[........................................................................................................................](#br8)

[2.1](#br9) [软件](#br9)[ ](#br9)[硬件](#br9)[ ](#br9)[映射........................................................................................................................](#br9)

[2.1.1](#br12) [通用定时器](#br12)[ ](#br12)[...................................................................................................](#br12)

[2.1.2](#br12) [GPT](#br12)[ ](#br12)[..................................................................................................................................](#br12)

[2.1.3](#br12) [IRQ](#br12)[ ](#br12)[..................................................................................................................................](#br12)

[2.1.4](#br10) [系统](#br10)[ ](#br10)[时钟](#br10)[ ](#br10)[](#br10)[ ](#br10)[................................................................................................................................](#br10)

[**3**](#br11) [**文件结构**](#br11)[ ](#br11)[................................................................................................................................](#br11)


[**4**](#br11) [**配置文档**](#br11)[ ](#br11)[...................................................................................................................](#br11)

[4.1](#br12) [配置](#br12)[ ](#br12)[概念](#br12)[ ](#br12)[.....................................................................................................................](#br12)

[4.1.1](#br12) [配置](#br12)[ ](#br12)[类.......................................................................................................................](#br12)

[4.2](#br13) [配置参数变化](#br13)[ ](#br13)[.......................................................................................................................](#br13)

[4.3](#br13) [](#br13)[ ](#br13)[GptDriverConfiguration](#br13)[ ](#br13)[.....................................................................................................](#br13)

[4.3.1](#br13) [](#br13)[GptDevErrorDetect................................................................................................](#br13)

[4.4](#br15) [](#br15)[ ](#br15)[GptConfigurationOfOptApiServices.......................................................................................](#br15)

[4.4.1](#br15) [GptVersionInfoApi.................................................................................................................](#br15)

[4.4.2](#br15)[GptDeInitApi..................................................................................................................](#br15)

[4.4.3](#br16) [GptTimeElapsedApi](#br16)[............................................................................................................](#br16)

[4.4.4](#br16) [GptTimeRemainingApi](#br16)[..........................................................................................................](#br16)

[4.4.5](#br16) [GptEnableDisableNotificationApi](#br16)[.................................................................................](#br16)

[4.4.6](#br17)    [GptWakeupFunctionalityApi.............................................................................................](#br17)

[4.5](#br15) [](#br15)[ ](#br15)[Gpt_ConfigPredefined............................................................................................................](#br15)

[**5**](#br18) [**发布的参数**](#br18)[..........................................................................................................................](#br18)

[5.1](#br18) [VendorId............................................................................................................................](#br18)

[5.2](#br19) [ModuleId...........................................................................................................................](#br19)

[5.3](#br19) [InstanceId............................................................................................................................](#br19)

[5.4](#br19) [SwMajorVersion........................................................................................................](#br19)

[5.5](#br19) [SwMinorVersion.........................................................................................................](#br19)

[5.6](#br19) [SwPatchVersion..........................................................................................................](#br19)

[**6**](#br19) [**API 文档**](#br19)[](#br19)[......................................................................................................................... ](#br19)

[6.1](#br19) [API](#br19)[ ](#br19)[类型](#br19)[ ](#br19)[定义..........................................................................................................](#br19)

[6.2](#br19) [API](#br19)[ ](#br19)[函数.....................................................................................................................](#br19)

[6.3](#br19) [中断](#br19)[ ](#br19)[处理.........................................................................................................................](#br19)

[6.4](#br20) [专有](#br20)[ ](#br20)[信息区](#br20)[ ](#br20)[.....................................................................................................................](#br20)

[**7**](#br20) [**数据 描述**](#br20)[](#br20)[................................................................................................................................](#br20)

[**8**](#br20) [**错误 分类**](#br20)[](#br20)[...........................................................................................................................](#br20)

[**9**](#br20) [**示例 用法**](#br20)[ ](#br20)[................................................................................................................................](#br20)

[9.1](#br20) [驱动器配置](#br20)[ ](#br20)[](#br20)[ ](#br20)[](#br20)[ ](#br20)[...................................................................................................................](#br20)

[**10**](#br21) [**假设 和 限制**](#br21)[ ](#br21)[](#br21)[](#br21)[................................................................................................................](#br21)

[10.1](#br21) [假设和与软件规格的偏差](#br21)[ ](#br21)[](#br21)[ ](#br21)[](#br21)[ ](#br21)[](#br21)[ ](#br21)[](#br21)[ ](#br21)[](#br21)[ ](#br21)[..........................................................................................](#br21)

[10.2](#br21) [限制](#br21)[ ](#br21)[................................................................................................................................](#br21)



---

# 第1章 引言

本用户手册提供了有关GPT驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的GPT驱动程序实现。该文档描述了如何使用GPT驱动程序
## 1.1 范围

本文档涉及GPT Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- GPT Driver的文件结构
- Driver的配置参数
- 由GPT Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于GPT Driver

## 1.2 缩写

MCAL: Microcontroller Abstract Layer，微控制器抽象层
GPT: General Purpose Timer，通用定时器

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of GPT Driver, AUTOSAR_SWS_GPT_Driver.pdf Release R22-11
- [2] Requirements of GPT Driver, AUTOSAR_SRS_GPT_Driver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 GPT Driver概述
GPT Driver使用KungFu平台的通用定时器外设。Driver可以配置多个通道。每个通道由一个定时器单元组成，需要为其配置时钟和超时值。每个通道可以执行以下操作：
- 启动/停止定时器
- 可用唤醒功能
- 启用/禁用通知
- 单次或连续模式操作

### 2.1 软件硬件模块映射
本节向用户介绍了实现中使用的硬件特性。图1展示了KungFu硬件外设及其与驱动程序的交互。

### 2.1.1 通用定时器

### 2.1.2 GPT
使用通用定时器资源来实现GPT通道。

### 2.1.3 IRQ
IRQ Driver负责初始化通用定时器所需的中断优先级。见表79

### 2.1.4 系统时钟
系统时钟通过MCU Driver设置。必须设置适当的系统时钟。

### 2.1.4.1 软件驱动程序描述


---

# 第3章 文件结构
本节提供了有关GPT Driver文件和其他相关文件的详细信息。
| Name      | Description                                     |
| :-------- | :---------------------------------------------- |
| Gpt.c     | 此文件包含Gpt驱动程序的通用功能                 |
| Gpt.h     | 此头文件输出Gpt驱动程序的宏、类型定义和函数原型 |
| Gpt_Cfg.h | 本文在这里声明了Gpt驱动程序的配置数据。         |
| Gpt_Im.c  | 此文件包含Gpt模块所需要的硬件驱动程序           |
| Gpt_Im.h  | 此头文件输出Gpt驱动程序的宏、类型定义和函数原型 |


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
本节描述了相对于支持的微控制器的配置参数的变化。GPT Driver在支持的微控制器上没有变化的参数。

## 4.3 GptDriverConfiguration
本节详细描述了GPT Driver提供的配置，包括AUTOSAR GPT Driver规范[1]中描述的配置以及特定于微控制器的配置。

### 4.3.1 GptDevErrorDetect
- **名称**: GptDevErrorDetect
- **来源**: AUTOSAR定义
- **文件**: Gpt_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.2 GptReportWakeupSource
- **名称**: GptReportWakeupSource
- **来源**: AUTOSAR定义
- **文件**: Gpt_Cfg.h
- **范围**: 值：STD_ON – 启用，STD_OFF – 禁用，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.3 GPT_PRECOMPILE_SUPPORT
- **名称**: GPT_PRECOMPILE_SUPPORT
- **来源**: AUTOSAR定义
- **文件**: Gpt_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

---
## 4.4 GptConfigurationOfOptApiServices

### 4.4.1 GptVersionInfoApi
- **名称**: GptVersionInfoApi
- **来源**: AUTOSAR定义，
- **文件**: Gpt_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.2 GptDeInitApi
- **名称**: GptDeInitApi
- **来源**: AUTOSAR定义
- **文件**: Gpt_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.3 GptTimeElapsedApi
- **名称**: GptTimeElapsedApi
- **来源**: AUTOSAR定义
- **文件**: Gpt_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.4 GptTimeRemainingApi
- **名称**: GptTimeRemainingApi
- **来源**: AUTOSAR定义
- **文件**: Gpt_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.4.5 GptEnableDisableNotificationApi
- **名称**: GptEnableDisableNotificationApi
- **来源**: AUTOSAR定义，
- **文件**: Gpt_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.6 GptWakeupFunctionalityApi
- **名称**: GptWakeupFunctionalityApi
- **来源**: AUTOSAR定义
- **文件**: Gpt_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体
----
## 4.5 Gpt_ConfigPredefined


### 4.5.1 g_channel_configs
这个容器包含GPT Driver的通道范围配置（参数）。

#### 4.5.1.1 ChanHwIndex
- **名称**: ChanHwIndex
- **来源**: KungFu定义
- **文件**: Gpt_LCfg.c
- **范围**: 值：容器中的唯一数字，默认值：当前通道索引
- **配置类别**: 预编译时间 X 变体PC

- **配置类别**: 预编译时间 X 变体PC
- **描述**: 指定定时器通道的信号类型。

#### 4.5.1.5 Prescale
- **名称**: Prescale
- **来源**: KungFu定义
- **文件**: Gpt_LCfg
- **范围**: 值：-
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 指定定时器通道的滴答频率（Hz）。此功能不受支持，因为时钟在通用定时器中处理。

#### 4.5.1.6 EnableWakeUp
- **名称**: EnableWakeUp
- **来源**: KungFu定义
- **文件**: Gpt_LCfg
- **范围**: 值：-
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 使能通道唤醒功能。

#### 4.5.1.7 NotifyFcn
- **名称**: NotifyFcn
- **来源**: KungFu定义
- **文件**: Gpt_LCfg
- **范围**: 值：-
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 通知指针函数或回调函数：当超时发生时，GPT驱动程序将为每个单独的通道调用此函数。如果不需要通知，则应删除此参数。
- 
#### 4.5.1.8 ClkSrc
- **名称**: ClkSrc
- **来源**: KungFu定义
- **文件**: Gpt_LCfg
- **范围**: 值：-
- **配置类别**: 预编译时间 X 变体PC
- **描述**: GPT模块所选时钟源。

#### 4.5.1.9 ChannelCount
- **名称**: ChannelCount
- **来源**: KungFu定义
- **文件**: Gpt_LCfg.c
- **范围**: 值：-
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 配置初始化GPT的通道数量

#### 4.5.1.10 ChannelConfigPtr
- **名称**: ChannelConfigPtr
- **来源**: KungFu定义
- **文件**: Gpt_LCfg.c
- **范围**: 值：-
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 指向定时器通道配置的指针

#### 4.5.1.11 PredefTimeConfig
- **名称**: PredefTimeConfig
- **来源**: AUTOSAR定义
- **文件**: Gpt_LCfg.c
- **范围**:-
- **配置类别**: 预编译时间 X 所有变体
- **描述**: 指向预定时器配置的指针
------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: GPT_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Gpt.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: GPT_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Gpt.h
- **值**: 100
- **描述**: 这个宏给出了GPT驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: GPT_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Gpt.h
- **值**: 0
- **描述**: 这个宏给出了GPT驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: GPT_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Gpt.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: GPT_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Gpt.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: GPT_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Gpt.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Gpt_ConfigType
- **语法**: Gpt_ConfigType
- **类型**: Struct
- **文件**: Gpt.h
- **范围**: ChannelConfigPtr (Gpt_ChannelConfigType*)
  - 指向Gpt_ChannelConfigType 
  - PredefTimeConfig (Gpt_PredefTimeConfigType*)
  - 指向Gpt_PredefTimeConfigType
- **ChannelCount** (uint8)
  - GPT通道在配置中的数量
- **描述**: 此类型定义用于配置GPT的整体配置。此类型的指针在Gpt_Init API中用于初始化GPT驱动程序。

### 6.1.2 类型定义 Gpt_ChannelConfigType
- **语法**: Gpt_ChannelConfigType
- **类型**: struct
- **文件**: Gpt.h
- **范围**: Gpt_NotifFunctionPtrType (Function Pointer)
  - NotifyFcn - 普通模式通知的函数指针
- **Gpt_TimerEnumType** (enum)
  - ChanHwIndex - 用于通道的硬件资源。
- **boolean**
  - EnableWakeUp - 通道唤醒能力 TRUE/FALSE
- **Gpt_ModeType**
  - ChanMode - 通道模式 - GPT_MODE_CONTINUOUS/ GPT_MODE_ONESHOT
- **uint8**
  - ChanHwType- 通道的硬件类型。
- **uint32**
  - ChanTickValueMax- 计数器能够计数的最大值（以时钟周期为单位），下一个时钟周期到来时，计数器将回零。
- **Gpt_ClkSourceType**
  - ClkSrc -时钟选择  GPT_SCLK/GPT_HFCLK
  - **uint32**
  - Prescale -时钟分频。
- **描述**: 这是包含定时器通道特定参数的数据结构类型。GPT配置由一个或多个定时器通道组成。

### 6.1.3 类型定义 Gpt_PredefTimeConfigType
- **语法**: Gpt_PredefTimeConfigType
- **类型**: Struct
- **文件**: Gpt.h
- **范围**: 
- **Gpt_TimerEnumType** 
- PredefHwChannel-预定时器的通道
- **uint16** 
- Prescaler- 时钟分频
- **Gpt_ClkSourceType** 
- ClockSource- 时钟源 
- **描述**: 此类型定义用于配置预定时器的整体配置。

### 6.1.4 类型定义 Gpt_ChannelType
- **语法**: Gpt_ChannelType
- **类型**: Uint8
- **文件**: Gpt.h
- **范围**: 0到10(可配置的最大通道数)
- **描述**: GPT通道的数字ID。

### 6.1.5 类型定义 Gpt_ValueType
- **语法**: Gpt_ValueType
- **类型**: uint32
- **文件**: Gpt.h
- **范围**: 0到0xFFFFFF
- **描述**: 用于读取当前定时器值/设置周期性定时器值（以滴答数）。

### 6.1.6 类型定义 Gpt_ModeType
- **语法**: Gpt_ModeType
- **类型**: uint8
- **文件**: Gpt.h
- **范围**: GPT_MODE_UNINITIALIZED 未初始化模式
  - GPT_MODE_NORMAL 普通模式
  - GPT_MODE_SLEEP 睡眠模式
- **描述**: 允许选择不同的电源模式GPT_MODE_UNINITIALIZED, GPT_MODE_NORMAL和GPT_MODE_SLEEP。

### 6.1.7 类型定义 EcuM_WakeupSourceType
- **语法**: EcuM_WakeupSourceType
- **类型**: uint32
- **文件**: EcuM_Types.h
- **范围**: 根据EcuM配置定义。
- **描述**: 唤醒源类型的类型定义。(从EcuM.h导入)

### 6.1.8 类型定义 Gpt_TimerEnumType
- **语法**: Gpt_TimerEnumType
- **类型**: Enum
- **文件**: Gpt.h
- **范围**: GPT_GPTIMER_CHAN_T0/GPT_GPTIMER_CHAN_T1/GPT_GPTIMER_CHAN_T2
- GPT_GPTIMER_CHAN_T3/GPT_GPTIMER_CHAN_T4/GPT_GPTIMER_CHAN_T18
- GPT_GPTIMER_CHAN_T19/GPT_GPTIMER_CHAN_T21/GPT_GPTIMER_CHAN_T22
- GPT_GPTIMER_CHAN_T23
- **描述**: GPT的通道


### 6.1.9 类型定义 Gpt_PredefTimerType
- **语法**: Gpt_PredefTimerType
- **类型**: Enum
- **文件**: Gpt.h
- **范围**: GPT_PREDEF_TIMER_1US_16BIT/GPT_PREDEF_TIMER_1US_24BIT
- GPT_PREDEF_TIMER_1US_32BIT/GPT_PREDEF_TIMER_100US_32BIT
- **描述**: 预定时器的值

### 6.1.10 类型定义 Gpt_ChannelStatusType
- **语法**: Gpt_ChannelStatusType
- **类型**: Enum
- **文件**: Gpt.h
- **范围**: GPT_CHANNEL_UNINITIALIZED/GPT_CHANNEL_INITIALIZED
- GPT_CHANNEL_STOPPED/GPT_CHANNEL_EXPIRED/GPT_CHANNEL_RUNNING
- **描述**: 通道状态
  
### 6.1.11 类型定义 Gpt_ChannelModeType
- **语法**: Gpt_ChannelModeType
- **类型**: Enum
- **文件**: Gpt.h
- **范围**: GPT_MODE_CONTINUOUS/GPT_MODE_ONE_SHOT
- **描述**: GPT的模式
---
## 6.2 API函数

### 6.2.1 Gpt_GetVersionInfo
- **服务名称**: Gpt_GetVersionInfo
- **语法**: void Gpt_GetVersionInfo ( Std_VersionInfoType *VersionInfoPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: VersionInfoPtr: 存储驱动版本信息的指针。
- **返回值**: 无
- **描述**: 返回驱动的版本信息的服务。实现为宏。

### 6.2.2 Gpt_Init
- **服务名称**: Gpt_Init
- **语法**: void Gpt_Init (const Gpt_ConfigType *ConfigPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: ConfigPtr 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化GPT驱动程序的服务。

### 6.2.3 Gpt_DeInit
- **服务名称**: Gpt_DeInit
- **语法**: void Gpt_DeInit (void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 将所有硬件定时器通道初始化为其上电复位状态的服务。此服务还禁用通知和唤醒事件。

### 6.2.4 Gpt_GetTimeElapsed
- **服务名称**: Gpt_GetTimeElapsed
- **语法**: Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel 需要计算已流逝时间的关联通道
- **参数(输出)**: 无
- **返回值**: Gpt_ValueType

### 6.2.5 Gpt_GetTimeRemaining
- **服务名称**: Gpt_GetTimeRemaining
- **语法**: Gpt_ValueType Gpt_GetTimeRemaining ( Gpt_ChannelType Channel )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel 需要计算剩余时间的关联通道
- **参数(输出)**: 无
- **返回值**: Gpt_ValueType

### 6.2.6 Gpt_StartTimer
- **服务名称**: Gpt_StartTimer
- **语法**: void Gpt_StartTimer ( Gpt_ChannelType Channel, Gpt_ValueType Value )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x05
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel 要启动的通道，Value 要设置的时间值
- **参数(输出)**: 无
- **返回值**: 无
  
### 6.2.7 Gpt_StopTimer
- **服务名称**: Gpt_StopTimer
- **语法**: void Gpt_StopTimer(Gpt_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x06
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel 要停止的的通道
- **参数(输出)**: 无
- **返回值**: 无

### 6.2.8 Gpt_SetMode
- **服务名称**: Gpt_SetMode
- **语法**: void Gpt_SetMode(Gpt_ModeType Mode)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x09
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Mode 要设置驱动的操作模式
- **参数(输出)**: 无
- **返回值**: 无

### 6.2.9 Gpt_EnableNotification
- **服务名称**: Gpt_EnableNotification
- **语法**: void Gpt_EnableNotification(Gpt_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x07
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:Channel 要使能通知功能的通道
- **参数(输出)**: 无
- **返回值**: 无

### 6.2.10 Gpt_DisableNotification
- **服务名称**: Gpt_DisableNotification
- **语法**: void Gpt_DisableNotification(Gpt_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x08
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:Channel 要禁止通知功能的通道
- **参数(输出)**: 无
- **返回值**: 无

### 6.2.11 Gpt_DisableWakeup
- **服务名称**: Gpt_DisableWakeup
- **语法**: void Gpt_DisableWakeup(Gpt_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0A
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:Channel 要禁止唤醒功能的通道
- **参数(输出)**: 无
- **返回值**: 无

### 6.2.12 Gpt_EnableWakeup
- **服务名称**: Gpt_EnableWakeup
- **语法**: void Gpt_EnableWakeup(Gpt_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0B
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:Channel 要启动唤醒功能的通道
- **参数(输出)**: 无
- **返回值**: 无

### 6.2.13 Gpt_CheckWakeup
- **服务名称**: Gpt_CheckWakeup
- **语法**: void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0C
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:WakeupSource  表示要检查的唤醒源类型
- **参数(输出)**: 无
- **返回值**: 无
  
### 6.2.14 Gpt_GetPredefTimerValue
- **服务名称**: Gpt_GetPredefTimerValue
- **语法**: void Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0d
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:PredefTimer  表示要获取值的预定义定时器类型
- **参数(输出)**: TimeValuePtr 指向一个存储预定义定时器当前值的变量的指针
- **返回值**: Std_ReturnType
---
## 6.3 中断处理

中断服务例程在GPT Driver中用于通知、报告唤醒事件以及为连续模式通道计算下一个超时值。

### 6.3.1 Gpt_Isr
- **服务名称**：Gpt_Isr
- **语法**：`void Gpt_Isr (uint8 HwChannel)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：HwChannel - GPT通道编号
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 调用通知
  - 调用唤醒事件，将为唤醒事件调用EcuM_CheckWakeup
- **警告**：无
- **配置**：如果需要从中断例程调用唤醒事件，则应将GptReportWakeupSource设置为STD_ON。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有10个SRN（服务请求节点）用于服务GPT通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - GPT硬件资源

| 硬件资源             | SRN编号               |
| -------------------- | --------------------- |
| GPT_GPTIMER_CHAN_T0  | T0_UNIFIED_INTERRUPT  |
| GPT_GPTIMER_CHAN_T1  | T1_UNIFIED_INTERRUPT  |
| GPT_GPTIMER_CHAN_T2  | T2_UNIFIED_INTERRUPT  |
| GPT_GPTIMER_CHAN_T3  | T3_UNIFIED_INTERRUPT  |
| GPT_GPTIMER_CHAN_T4  | T4_UNIFIED_INTERRUPT  |
| GPT_GPTIMER_CHAN_T18 | T18_UNIFIED_INTERRUPT |
| GPT_GPTIMER_CHAN_T19 | T19_UNIFIED_INTERRUPT |
| GPT_GPTIMER_CHAN_T21 | T21_UNIFIED_INTERRUPT |
| GPT_GPTIMER_CHAN_T22 | T22_UNIFIED_INTERRUPT |
| GPT_GPTIMER_CHAN_T23 | T23_UNIFIED_INTERRUPT |

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

GPT Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是Gpt Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                     | 类型/范围             | 描述                                      |
| ------------------------ | --------------------- | ----------------------------------------- |
| ConfigPtr                | Gpt_ConfigType        | GPT Driver配置结构的指针。                |
| Gpt_modeStatus           | Gpt_ModeType          | 存储驱动器当前模式（SLEEP/ NORMAL）的变量 |
| Gpt_ChannelStatus        | Gpt_ChannelStatusType | 存储通道的通道模式的变量                  |
| Gpt_ChannelSetTimerValue | Gpt_ValueType         | 存储所有通道起始时间的变量                |
| Gpt_assignedHwChannel    | uint8 []              | 存储通道的通道索引的变量                  |
| Gpt_channelState         | Gpt_ChannelState_t    | 存储通道的通道状态的变量                  |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是GPT Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                  | 错误描述             | 值（十六进制） |
| ------------------------- | -------------------- | -------------- |
| GPT_E_ALREADY_INITIALIZED | 已经初始化           | 0x0D           |
| GPT_E_UNINIT              | 未初始化             | 0x0A           |
| GPT_E_BUSY                | 通道忙               | 0x0B           |
| GPT_E_PARAM_CHANNEL       | 无效通道             | 0x14           |
| GPT_E_PARAM_VALUE         | 无效值               | 0x15           |
| GPT_E_PARAM_MODE          | 无效模式             | 0x1F           |
| GPT_E_PARAM_POINTER       | 无效指针             | 0x16           |
| GPT_E_MODE                | 模式错误             | 0x0C           |
| GPT_E_INIT_FAILED         | 初始化失败           | 0x0E           |
| GPT_E_PARAM_PREDEF_TIMER  | 无效预定义的时间参数 | 0x17           |
| GPT_E_PARAM_NOTIFY_FUNC   | 无效通知函数         | 0x18           |

-----
# 第9章 示例用法
本章描述了如何配置GPT驱动器以及如何在应用程序中使用GPT驱动器提供的不同的API。

## 9.1 驱动器配置
按照以下指南正确配置GPT驱动器：
1. MCU驱动器：配置系统时钟。。
2. 中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级
3. GPT驱动器：选择所需的API配置开关，唤醒能力，通知和不同类型的定时器的使用或不使用。

### 9.1.1 驱动器的示例配置

##### 通道配置实例
```c
#define GPT_DEV_ERROR_DETECT (STD_OFF)
#define GPT_REPORT_WAKEUP_SOURCE (STD_ON)
#define GPT_DEINIT_API (STD_ON)
#define GPT_VERSION_INFO_API (STD_ON)
#define GPT_TIME_ELAPSED_API (STD_ON)
#define GPT_TIME_REMAINING_API (STD_ON)
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_ON)

/* 定时器配置 */
const Gpt_ChannelConfigType g_channel_configs[2U] = {
  {
    .ChanHwIndex  = GPT_GPTIMER_CHAN_T1, /* 通道编号 */
    .ChanMode     = GPT_MODE_CONTINUOUS, /* 连续模式 */
    .ChanHwType   = 0U,
    .ChanTickValueMax = 0xFFFFU,
    .ClkSrc       = GPT_SCLK, /* 系统时钟 */
    .Prescale     = 12000U,  /* 时钟分频 */
    .EnableWakeUp = FALSE,   /* 唤醒使能 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    .NotifyFcn = &Gpt_Notification_0, /* 回调函数 */
#endif
  },
  {
    .ChanHwIndex  = GPT_GPTIMER_CHAN_T2,
    .ChanMode     = GPT_MODE_ONE_SHOT,
    .ChanHwType   = 0U,
    .ChanTickValueMax = 0xFFFFU,
    .ClkSrc       = GPT_HFCLK,
    .Prescale     = 16000U,
    .EnableWakeUp = FALSE,
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    .NotifyFcn = &Gpt_Notification_1,
#endif
  },
};
/* 预定时器配置 */
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
static const Gpt_PredefTimeConfigType g_predef_config[1U] = {
  {.ClockSource = GPT_SCLK, .PredefHwChannel = GPT_GPTIMER_CHAN_T21, .Prescaler = 120U},
};
#endif
/* 初始化配置 */
const Gpt_ConfigType Gpt_ConfigPredefined = {
  .ChannelCount     = 2U,
  .ChannelConfigPtr = g_channel_configs,
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
  .PredefTimeConfig = g_predef_config,
#endif
};

```

#### 9.1.11 驱动器初始化
代码清单3展示了初始化GPT驱动器所涉及的步骤。注意：用户必须确保在调用Gpt_Init之前调用Mcu_Init
~~~
// 初始化MCU驱动器
Mcu_Init(&Mcu_ConfigRoot[0]);
// 初始化GPT驱动器
Gpt_Init(&Gpt_ConfigRoot[0]);
~~~
### 9.1.2 API用法示例
以下是GPT驱动器提供的API用法示例，包括启动定时器通道、停止定时器通道、启用/禁用定时器通道的通知、获取定时器通道的已流逝时间、获取定时器通道的剩余时间、设置GPT驱动器为睡眠模式、启用/禁用唤醒功能、获取GPT驱动器的版本信息以及取消初始化GPT驱动器。
~~~
启动定时器通道
Gpt_StartTimer(Gpt_Channel0, Gpt_ValueType(2000));
// Gpt_Channel0是通道ID，超时值以滴答计
停止定时器通道
Gpt_StopTimer(Gpt_Channel0);
启用定时器通道的通知
Gpt_EnableNotification(Gpt_Channel0);
禁用定时器通道的通知
Gpt_DisableNotification(Gpt_Channel0);
获取定时器通道的已流逝时间
ElapsedValue = Gpt_GetTimeElapsed(Gpt_Channel0);
获取定时器通道的剩余时间
RemainingValue = Gpt_GetTimeRemaining(Gpt_Channel0);
设置GPT驱动器为睡眠模式
Gpt_SetMode(GPT_MODE_SLEEP);
启用/禁用唤醒功能
Gpt_EnableWakeup(Gpt_Channel0);
Gpt_DisableWakeup(Gpt_Channel0);
获取GPT驱动器的版本信息
Gpt_GetVersionInfo(&VersionInfoPtr);
取消初始化GPT驱动器
Gpt_DeInit();
~~~ 
---

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 表82 假设

| 序号 | 参考 | 假设                                                                                                                                            |
| ---- | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 1    | 通用 | Gpt_GetTimeElapsed 仅在调用 Gpt_StartTimer 后被调用，以确保 Gpt_StartTimer 被正确执行。                                                         |
| 2    | 通用 | 定时器分辨率应考虑 ISR 性能时间和读取时间。如果预期持续时间的超时值非常低，并且没有足够的时间让 ISR 完成，则存在丢失事件/错误通知的更高可能性。 |

### 偏差



### 考虑的Bugzilla

- GPT_MODE_UNINITIALIZED 被包含在 Gpt_ModeType 中。
- Dem_EventStatusType 被添加到导入的类型中。
- GPT Driver 模式在 Gpt_Init 执行后被设置为 GPT_MODE_NORMAL。
- 设置休眠唤醒未实现。
- 需求 SWS_Gpt_00195 未实现。


## 10.2 限制

### 10.2.1 中断延迟



