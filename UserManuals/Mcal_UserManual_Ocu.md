# ChipOn Microcontroller Abstract Layer Users Manual - OCU Driver
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

- [ChipOn Microcontroller Abstract Layer Users Manual - OCU Driver](#chipon-microcontroller-abstract-layer-users-manual---ocu-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 OCU Driver概述](#第2章-ocu-driver概述)
    - [2.1 系统时钟](#21-系统时钟)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 OcuGenera](#43-ocugenera)
    - [4.3.1 OcuDevErrorDetect](#431-ocudeverrordetect)
  - [4.4 OcuConfigurationOfOptionalApis](#44-ocuconfigurationofoptionalapis)
    - [4.4.1 OcuDeInitApi](#441-ocudeinitapi)
    - [4.4.2 OcuGetCounterApi](#442-ocugetcounterapi)
    - [4.4.3 OcuNotificationSupported](#443-ocunotificationsupported)
    - [4.4.4 OcuSetAbsoluteThresholdApi](#444-ocusetabsolutethresholdapi)
    - [4.4.5 OcuSetPinActionApi](#445-ocusetpinactionapi)
    - [4.4.6 OcuSetPinStateApi](#446-ocusetpinstateapi)
    - [4.4.7 OcuSetRelativeThresholdApi](#447-ocusetrelativethresholdapi)
    - [4.4.8 OcuVersionInfoApi](#448-ocuversioninfoapi)
  - [4.5 OcuConfigSet](#45-ocuconfigset)
    - [4.5.1 OcuCountdirection](#451-ocucountdirection)
  - [4.6 OcuChannel](#46-ocuchannel)
    - [4.6.1 OcuAssignedHardwareChannel](#461-ocuassignedhardwarechannel)
    - [4.6.2 OcuChannelId](#462-ocuchannelid)
    - [4.6.3 OcuChannelTickDuration](#463-ocuchanneltickduration)
    - [4.6.4 OcuDefaultThreshold](#464-ocudefaultthreshold)
    - [4.6.5 OcuMaxCounterValue](#465-ocumaxcountervalue)
    - [4.6.6 OcuNotification](#466-ocunotification)
    - [4.6.7 OcuOutputPinDefaultState](#467-ocuoutputpindefaultstate)
  - [4.7 OcuHWSpecificSettings](#47-ocuhwspecificsettings)
    - [4.7.1 OcuClockSource](#471-ocuclocksource)
    - [4.7.2 OcuPrescale](#472-ocuprescale)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Ocu\_ConfigType](#611-类型定义-ocu_configtype)
    - [6.1.2 类型定义 Ocu\_ChannelConfigType](#612-类型定义-ocu_channelconfigtype)
    - [6.1.3 类型定义 Ocu\_ImConfigType](#613-类型定义-ocu_imconfigtype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Ocu\_Init](#621-ocu_init)
    - [6.2.2 Ocu\_DeInit](#622-ocu_deinit)
    - [6.2.3 Ocu\_StartChannel](#623-ocu_startchannel)
    - [6.2.4 Ocu\_StopChannel](#624-ocu_stopchannel)
    - [6.2.5 Ocu\_SetPinState](#625-ocu_setpinstate)
    - [6.2.6 Ocu\_SetPinAction](#626-ocu_setpinaction)
    - [6.2.7 Ocu\_GetCounter](#627-ocu_getcounter)
    - [6.2.8 Ocu\_SetAbsoluteThreshold](#628-ocu_setabsolutethreshold)
    - [6.2.9 Ocu\_SetRelativeThreshold](#629-ocu_setrelativethreshold)
    - [6.2.10 Ocu\_DisableNotification](#6210-ocu_disablenotification)
    - [6.2.11 Ocu\_EnableNotification](#6211-ocu_enablenotification)
    - [6.2.12 Ocu\_GetVersionInfo](#6212-ocu_getversioninfo)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Ocu\_Isr](#631-ocu_isr)
      - [表79 服务请求节点 - OCU硬件资源](#表79-服务请求节点---ocu硬件资源)
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
  - [9.4 启动通道输出](#94-启动通道输出)
  - [9.5 停止通道输出](#95-停止通道输出)
  - [9.6 设置PIN当前输出状态](#96-设置pin当前输出状态)
  - [9.7 设置PIN周期时有效输出状态](#97-设置pin周期时有效输出状态)
  - [9.8 获取当前通道的计数值](#98-获取当前通道的计数值)
  - [9.9 设置绝对阈值](#99-设置绝对阈值)
  - [9.10 设置相对阈值](#910-设置相对阈值)
  - [9.11 使能和关闭通知功能](#911-使能和关闭通知功能)
  - [9.12 配置示例](#912-配置示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)
    - [10.2.1](#1021)

---

# 第1章 引言

本用户手册提供了AUTOSAR CP R22-11的OCU驱动程序的功能、配置参数和API实现的相关信息。OCU的驱动程序初始化并提供对微控制器的访问。本用户手册旨在帮助用户熟悉OCU驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用OCU驱动程序的文档。

## 1.1 范围

本文档介绍OCU驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- OCU Driver的文件结构
- Driver的配置参数
- 由OCU Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于OCU Driver

## 1.2 缩写

| 缩写    | 解释                 |
| :------ | :------------------- |
| AUTOSAR | 汽车汽车开放系统架构 |
| DEM     | 诊断事件管理器       |
| DET     | 开发错误跟踪器       |
| MCU     | 微控制器             |
| OCU     | 输出比较单元         |
| ISR     | 中断服务例程         |
| OCU     | 输出比较单元通道     |
| DMA     | 直接内存访问         |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of OCUDriver, AUTOSAR_SWS_OCUDriver.pdf Release R22-11
- [2] Requirements of OCUDriver, AUTOSAR_SRS_OCUDriver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 OCU Driver概述
KF32微控制器提供OCU操作方式。配置OCU输出模式，周期。

### 2.1 系统时钟
系统时钟通过MCU驱动程序设置。配置主频最高120M，参考用户手册。

---

# 第3章 文件结构
本节提供了有关OCU Driver文件和其他相关文件的详细信息。
| Name       | Description                                           |
| :--------- | :---------------------------------------------------- |
| Ocu.c      | 此文件包含OCU驱动程序的通用功能                       |
| Ocu.h      | 此头文件输出OCU驱动程序的宏、类型定义和函数原型       |
| Ocu_Lcfg.h | 本文在这里声明了OCU驱动程序的配置数据。               |
| Ocu_Im.c   | 此文件包含OCU定时器模块所需要的硬件驱动程序           |
| Ocu_Im.h   | 此头文件输出OCU定时器驱动程序的宏、类型定义和函数原型 |
| Ocu_LCfg.c | 初始化变量定义                                        |

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
本节描述了相对于支持的微控制器的配置参数的变化。OCU Driver在支持的微控制器上没有变化的参数。

## 4.3 OcuGenera
本节详细描述了OCU Driver提供的配置，包括AUTOSAR OCU Driver规范[1]中描述的配置以及特定于微控制器的配置。

### 4.3.1 OcuDevErrorDetect
- **名称**: OcuDevErrorDetect
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开DET检测，STD_OFF – 不打开DET检测 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体
---

## 4.4 OcuConfigurationOfOptionalApis

### 4.4.1 OcuDeInitApi
- **名称**: OcuDeInitApi
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开反初始化函数功能，STD_OFF – 关闭反初始化函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.2 OcuGetCounterApi
- **名称**: OcuGetCounterApi
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开获取当前计数函数功能，STD_OFF – 关闭获取当前计数函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.3 OcuNotificationSupported
- **名称**: OcuNotificationSupported
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开设置通知功能函数功能，STD_OFF – 关闭设置通知功能函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.4 OcuSetAbsoluteThresholdApi
- **名称**: OcuSetAbsoluteThresholdApi
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开设置使用绝对输入数据设置通道阈值函数功能，STD_OFF – 关闭设置使用绝对输入数据设置通道阈值函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.5 OcuSetPinActionApi
- **名称**: OcuSetPinActionApi
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开设置达到周期时pin状态函数功能，STD_OFF – 关闭设置达到周期时pin状态函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.6 OcuSetPinStateApi
- **名称**: OcuSetPinStateApi
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开设置pin状态函数功能，STD_OFF – 关闭设置pin状态函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.7 OcuSetRelativeThresholdApi
- **名称**: OcuSetRelativeThresholdApi
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开设置设置通道阈值相对于计数器函数功能，STD_OFF – 关闭设置设置通道阈值相对于计数器函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.4.8 OcuVersionInfoApi
- **名称**: OcuVersionInfoApi
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 值：STD_ON – 打开获取版本号函数功能，STD_OFF – 关闭获取版本号函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体
---
## 4.5 OcuConfigSet

### 4.5.1 OcuCountdirection
- **名称**: OcuCountdirection
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: OCU_DOWN_COUNTING – 向下计数
            OCU_UP_COUNTING – 向上计数
            OCU_UP_DOWN_COUNTING - 向上向下计数
- **配置类别**: 预编译时间 X 所有变体

---
## 4.6 OcuChannel

### 4.6.1 OcuAssignedHardwareChannel
- **名称**: OcuAssignedHardwareChannel
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: 值：0...255
- **配置类别**: 预编译时间 X 所有变体

### 4.6.2 OcuChannelId
- **名称**: OcuChannelId
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: 0...255
- **配置类别**: 预编译时间 X 所有变体

### 4.6.3 OcuChannelTickDuration
- **名称**: PwmIdleStatOcuChannelTickDuratione
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: 0...32768
- **配置类别**: 预编译时间 X 所有变体

### 4.6.4 OcuDefaultThreshold
- **名称**: OcuDefaultThreshold
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: 0...4294967295
- **配置类别**: 预编译时间 X 所有变体

### 4.6.5 OcuMaxCounterValue
- **名称**: OcuMaxCounterValue
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: 0...4294967295
- **配置类别**: 预编译时间 X 所有变体

### 4.6.6 OcuNotification
- **名称**: OcuNotification
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: 0，1
- **配置类别**: 预编译时间 X 所有变体

### 4.6.7 OcuOutputPinDefaultState
- **名称**: OcuOutputPinDefaultState
- **来源**: AUTOSAR定义
- **文件**: Ocu.h
- **范围**: OCU_HIGH - 输出高电平，OCU_LOW - 输出低电平
- **配置类别**: 预编译时间 X 所有变体

---
## 4.7 OcuHWSpecificSettings

### 4.7.1 OcuClockSource
- **名称**: OcuClockSource
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 0...3
- **配置类别**: 预编译时间 X 所有变体

### 4.7.2 OcuPrescale
- **名称**: OcuPrescale
- **来源**: AUTOSAR定义
- **文件**: Ocu_Cfg.h
- **范围**: 0...65535
- **配置类别**: 预编译时间 X 所有变体

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: OCU_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Ocu.h
- **值**: 43
- **描述**: 

## 5.2 ModuleId
- **语法**: OCU_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: Ocu.h
- **值**: 125
- **描述**: 这个宏给出了PWM驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: OCU_INSTANCE_ID
- **类型**: 宏定义 (#define)
- **文件**: Ocu.h
- **值**: 0
- **描述**: 这个宏给出了PWM驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: OCU_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Ocu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: OCU_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Ocu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: OCU_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Ocu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Ocu_ConfigType
- **语法**: Ocu_ConfigType
- **类型**: Struct
- **文件**: Ocu.h
- **范围**: 
  - **uint8**
    - NumChannel - 配置的通道数量
  - **Ocu_ChannelConfigType**
    - ChannelConfigPtr - 通道配置         
  - **uint8**
    - NumHwUnit - 配置硬件单元数量
  - **Ocu_ImConfigType**
    - HwUnitConfigPtr - 硬件单元配置     
  - **Ocu_CountDirectionType**
    - CountDirection - 计数类型                  
- **描述**: 此类型定义用于配置OCU的整体配置。此类型的指针在Ocu_Init API中用于初始化OCU驱动程序。

### 6.1.2 类型定义 Ocu_ChannelConfigType
- **语法**: Ocu_ChannelConfigType
- **类型**: Struct
- **文件**: Ocu.h
- **范围**: 
  - **Ocu_ModuleInstanceType**
    - ModuleIndex - 硬件单元序号
  - **uint8**
    - AssignedHwChannel - channel配置信息    
  - **boolean**
    - OutputPinEnabled - 是否使能输出
  - **Pwm_AdvanceModuleConfigType**
    - Ocu_MaxCountValue - 最大计数，暂未使用    
  - **Ocu_ValueType**
    - Ocu_MinCountValue - 最小计数，暂未使用 
  - **Ocu_ValueType**
    - DefaultThreshold - 比较值      
  - **Ocu_PinActionType**
    - PinAction - 达到比较值，pin输出状态
  - **Ocu_NotificationFcnType**
    - NotifyFcn - 达到比较值时产生中断回调       
- **描述**: 此类型定义通道信息。

### 6.1.3 类型定义 Ocu_ImConfigType
- **语法**: Ocu_ImConfigType
- **类型**: Struct
- **文件**: Ocu.h
- **范围**: 
  - **uint8**
    - ModuleType - 硬件单元类型
  - **Ocu_ModuleInstanceType**
    - ModuleInstance - 硬件单元序号    
  - **Ocu_ValueType**
    - ClockSource - 时钟源
  - **Ocu_ValueType**
    - Prescale - 分频系数    
  - **Ocu_ValueType**
    - MaxCounter - 周期值        
- **描述**: 此类型定义硬件单元具体配置信息。

---
## 6.2 API函数

### 6.2.1 Ocu_Init
- **服务名称**: `Ocu_Init`
- **语法**: `void Ocu_Init (const Ocu_ConfigType* ConfigPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: ConfigPtr: 配置参数指针
- **返回值**: 无
- **描述**: OCU初始化
- **注意事项**: 无

### 6.2.2 Ocu_DeInit
- **服务名称**: `Ocu_DeInit`
- **语法**: `void Ocu_DeInit (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: OCU反初始化
- **注意事项**: 无

### 6.2.3 Ocu_StartChannel
- **服务名称**: `Ocu_StartChannel`
- **语法**: `Std_ReturnType Ocu_StartChannel (Ocu_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输出)**: E_OK - 通道已经开始
- **参数(输出)**: E_NOT_OK - 通道未开始
- **返回值**: 无
- **描述**: 开始通道启动
- **注意事项**: 无

### 6.2.4 Ocu_StopChannel
- **服务名称**: `Ocu_StopChannel`
- **语法**: `void Ocu_StopChannel (Ocu_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 停止通道
- **注意事项**: 无

### 6.2.5 Ocu_SetPinState
- **服务名称**: `Ocu_SetPinState`
- **语法**: `void Ocu_SetPinState (Ocu_ChannelType ChannelNumber,Ocu_PinStateType PinState)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输入)**: PinState - OCU_LOW, OCU_HIGH
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 立即设置与OCU通道相关联的引脚电平
- **注意事项**: 停止状态的通道使用该功能

### 6.2.6 Ocu_SetPinAction
- **服务名称**: `Ocu_SetPinAction`
- **语法**: `void Ocu_SetPinAction (Ocu_ChannelType ChannelNumber,Ocu_PinActionType PinAction)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x05
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输入)**: PinAction - OCU_SET_LOW, OCU_SET_HIGH, OCU_TOGGLE, OCU_DISABLE
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 指示驱动程序在比较匹配时由硬件(如果支持)自动完成的服务。
- **注意事项**: 无

### 6.2.7 Ocu_GetCounter
- **服务名称**: `Ocu_GetCounter`
- **语法**: `Ocu_ValueType Ocu_GetCounter (Ocu_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x06
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 读取当前计数值
- **注意事项**: 无

### 6.2.8 Ocu_SetAbsoluteThreshold
- **服务名称**: `Ocu_SetAbsoluteThreshold`
- **语法**: `Ocu_ReturnType Ocu_SetAbsoluteThreshold (Ocu_ChannelType ChannelNumber,Ocu_ValueType ReferenceValue,Ocu_ValueType AbsoluteValue)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x07
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输入)**: ReferenceValue - 由上层给出的值，用作决定是否在函数退出之前调用通知的基础
- **参数(输入)**: AbsoluteValue - 值与计数器的内容进行比较。该值以tick为单位
- **参数(输出)**: 无
- **返回值**: 告诉调用者比较匹配是否会在当前引用间隔期间发生(或已经发生)，因为设置了新的阈值
- **描述**: 使用绝对输入数据设置通道阈值的服务
- **注意事项**: 不支持边沿类型设置，只支持周期中断通知

### 6.2.9 Ocu_SetRelativeThreshold
- **服务名称**: `Ocu_SetRelativeThreshold`
- **语法**: `Ocu_ReturnType Ocu_SetRelativeThreshold (Ocu_ChannelType ChannelNumber,Ocu_ValueType RelativeValue)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x08
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输入)**: RelativeValue - 用于计算新的阈值
- **参数(输出)**: 无
- **返回值**: 告诉调用者比较匹配是否会在当前引用间隔期间发生(或已经发生)，因为设置了新的阈值。
- **描述**: 设置通道阈值相对于计数器的当前值的值
- **注意事项**: 无

### 6.2.10 Ocu_DisableNotification
- **服务名称**: `Ocu_DisableNotification`
- **语法**: `void Ocu_DisableNotification (Ocu_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0A
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**:无
- **参数(输出)**: ChannelNumber - 通道索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此服务用于禁用来自OCU通道的通知
- **注意事项**: 无

### 6.2.11 Ocu_EnableNotification
- **服务名称**: `Ocu_EnableNotification`
- **语法**: `void Ocu_EnableNotification (Ocu_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0B
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**:无
- **参数(输出)**: ChannelNumber - 通道索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此服务用于启用来自OCU通道的通知
- **注意事项**: 无

### 6.2.12 Ocu_GetVersionInfo
- **服务名称**: `Ocu_GetVersionInfo`
- **语法**: `void Ocu_GetVersionInfo (Std_VersionInfoType* versioninfo)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x09
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:无
- **参数(输出)**: versioninfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无

-----
## 6.3 中断处理

### 6.3.1 Ocu_Isr
- **服务名称**: Ocu_Isr
- **语法**：`FUNC(void, OCU_CODE) Ocu_Isr(VAR(uint8, OCU_VAR) Module)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：不可重入
- **参数（输入）**：Module - OCU硬件单元
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 清除ICU使用的CCP模块的中断标志
  - 查询指定通道的测量模式
  - ICU输入信号的测量
- **警告**：无
- **配置**：如果需要从中断例程调用通知，则应将OCU_NOTIFICATION_SUPPORTED设置为STD_ON。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有10个SRN（服务请求节点）用于服务OCU通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - OCU硬件资源

| 硬件资源      | SRN编号               |
| ------------- | --------------------- |
| OCU_MODULE_0  | T0_UNIFIED_INTERRUPT  |
| OCU_MODULE_1  | T1_UNIFIED_INTERRUPT  |
| OCU_MODULE_2  | T2_UNIFIED_INTERRUPT  |
| OCU_MODULE_3  | T3_UNIFIED_INTERRUPT  |
| OCU_MODULE_4  | T4_UNIFIED_INTERRUPT  |
| OCU_MODULE_18 | T18_UNIFIED_INTERRUPT |
| OCU_MODULE_19 | T19_UNIFIED_INTERRUPT |
| OCU_MODULE_21 | T21_UNIFIED_INTERRUPT |
| OCU_MODULE_22 | T22_UNIFIED_INTERRUPT |
| OCU_MODULE_23 | T23_UNIFIED_INTERRUPT |

-----

## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

OCU Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是OCU Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                    | 类型/范围                  | 描述                                |
| ----------------------- | -------------------------- | ----------------------------------- |
| kpOcu_ConfigPtr         | Ocu_ConfigType             | 保存配置参数指针                    |
| kvOcu_assignedHwChannel | uint8                      | 保存模块和通道对应的channel配置索引 |
| kvOcu_ChanRunInfo       | Ocu_ChannelRunningInfoType | 通道运行状态                        |
| kpOcu_CcpUnitPtr        | kpCcpRegM                  | 通用定时器指针                      |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是OCU Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                    | 错误描述                   | 值（十六进制） |
| --------------------------- | -------------------------- | -------------- |
| OCU_E_UNINIT                | 未初始化                   | 0x02           |
| OCU_E_PARAM_INVALID_CHANNEL | 通道参数超出配置范围       | 0x03           |
| OCU_E_PARAM_INVALID_STATE   | 状态状态不符合预期         | 0x04           |
| OCU_E_PARAM_INVALID_ACTION  | 设置有效状态不符合预期     | 0x05           |
| OCU_E_NO_VALID_NOTIF        | 通知函数配置空指针         | 0x06           |
| OCU_E_ALREADY_INITIALIZED   | 重复初始化                 | 0x07           |
| OCU_E_PARAM_POINTER         | 获取版本号入参空指针       | 0x08           |
| OCU_E_BUSY                  | 通道已经启动，再次调用启动 | 0x09           |
| OCU_E_PARAM_NO_PIN          | PIN配置不是输出状态        | 0x0A           |
| OCU_E_INIT_FAILED           | 初始化失败                 | 0x0B           |
| OCU_E_NOT_MATCHED           | 模块和通道配置不匹配       | 0x10           |

-----
# 第9章 示例用法
本章描述了如何配置OCU驱动器以及如何在应用程序中使用OCU驱动器提供的不同的API。

## 9.1 系统时钟配置注意事项

- 配置注意事项
 - 一个模块使用一个通道
 - 常规通道，设置的周期值MaxCounter不能大于0xFFFF

## 9.2 宏配置

```c
#define OCU_DEV_ERROR_DETECT_API (STD_OFF)
#define OCU_PB_FIXED_ADDRESS (STD_OFF)

#define OCU_DE_INIT_API (STD_ON)
#define OCU_SET_PIN_STATE_API (STD_ON)
#define OCU_SET_PIN_ACTION_API (STD_ON)
#define OCU_GET_COUNTER_API (STD_ON)
#define OCU_SET_ABSOLUTE_THRESHOLD_API (STD_ON)
#define OCU_SET_RELATIVE_THRESHOLD_API (STD_ON)
#define OCU_VERSION_INFO_API (STD_ON)
#define OCU_NOTIFICATION_SUPPORTED (STD_ON)
```
## 9.3 初始化

- 关闭固定配置情
```c
#define OCU_PB_FIXED_ADDRESS (STD_OFF)

Ocu_Init(&Ocu_ConfigPredefined);

```
- 打开固定配置
```c
#define OCU_PB_FIXED_ADDRESS (STD_ON)

Ocu_Init(NULL_PTR);
```

## 9.4 启动通道输出

```c
Ocu_StartChannel(0U);
```

## 9.5 停止通道输出

```c
Ocu_StopChannel(0U);
```

## 9.6 设置PIN当前输出状态

 - 需要在通道停止情况下，使用该功能

```c
Ocu_SetPinState(0U,OCU_LOW);
```

## 9.7 设置PIN周期时有效输出状态

 - 需要在通道停止情况下，使用该功能

```c
Ocu_SetPinAction(0U,OCU_TOGGLE);
```

## 9.8 获取当前通道的计数值

 - 需要在通道停止情况下，使用该功能

```c
Ocu_ValueType running_counter;
running_counter = Ocu_GetCounter(0U);
```

## 9.9 设置绝对阈值

```c
Ocu_ReturnType retValue;
retValue = Ocu_SetAbsoluteThreshold(0U,20,50);
```

## 9.10 设置相对阈值

```c
Ocu_ReturnType retValue;
retValue = Ocu_SetRelativeThreshold(0U,50);
```

## 9.11 使能和关闭通知功能

 - 需要配置通知函数

```c
Ocu_DisableNotification(0U);
Ocu_EnableNotification(0U);
```

## 9.12 配置示例

- 一共配置了2个通道
- 使用通用定时器T4
 - 使用通道3，时钟源高频外设，边沿对齐，分频16000，周期值1000(即周期为2s)
 - 阈值是50,达到阈值进行管脚翻转
- 使用通用定时器T19
 - 使用通道3，时钟源高频外设，边沿对齐，分频16，周期值65535(即周期为130ms)
 - 阈值是50,达到阈值进行管脚翻转

```c
/**
 * @brief User's hardware Configurations
 */
/* PRQA S 3408 ,4424 ++*/
static CONST(Ocu_ImConfigType, OCU_VAR) Ocu_ImConfigs[OCU_USER_CFG_HARDWARE_NUM] = {
  [0U] = {.ModuleInstance = OCU_MODULE_19, .ClockSource = OCU_TXCLOCK_HFCLK, .Prescale = 16000U, .MaxCounter = 1000U},
  [1U] = {.ModuleInstance = OCU_MODULE_4, .ClockSource = OCU_TXCLOCK_HFCLK, .Prescale = 16U, .MaxCounter = 0xFFFFU}};

/**
 * @brief User's notification function example
 */
FUNC(void, OCU_CODE) Func_1(void) {}

/**
 * @brief User's notification function example
 */
FUNC(void, OCU_CODE) Func_2(void) {}

/**
 * @brief User's channel Configurations
 */
static CONST(Ocu_ChannelConfigType, OCU_VAR) Ocu_ChannelConfigs[OCU_USER_CFG_CHANNEL_NUM] = {
  [0U] = {.ModuleIndex       = OCU_MODULE_19,
          .AssignedHwChannel = OCU_CHANNEL3_CFG_INDEX,
          .OutputPinEnabled  = TRUE,
          .Ocu_MaxCountValue = OCU_USER_CFG_MAX_NUM,
          .Ocu_MinCountValue = OCU_USER_CFG_MIN_NUM,
          .DefaultThreshold  = 50U,
          .PinAction         = OCU_TOGGLE,
          .NotifyFcn         = Func_1},
  [1U] = {
    .ModuleIndex       = OCU_MODULE_4,
    .AssignedHwChannel = OCU_CHANNEL1_CFG_INDEX,
    .OutputPinEnabled  = TRUE,
    .Ocu_MaxCountValue = OCU_USER_CFG_MAX_NUM,
    .Ocu_MinCountValue = OCU_USER_CFG_MIN_NUM,
    .DefaultThreshold  = 50U,
    .PinAction         = OCU_TOGGLE,
    .NotifyFcn         = Func_2}};

/**
 * @brief User's Ocu Configurations
 */
CONST(Ocu_ConfigType, OCU_VAR)
Ocu_ConfigPredefined = {
   .NumChannel       = sizeof(Ocu_ChannelConfigs) / sizeof(Ocu_ChannelConfigType),
   .ChannelConfigPtr = &Ocu_ChannelConfigs[0U],
   .NumHwUnit        = sizeof(Ocu_ImConfigs) / sizeof(Ocu_ImConfigType),
   .HwUnitConfigPtr  = &Ocu_ImConfigs[0U],
   .CountDirection   = OCU_UP_COUNTING};

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

- 不支持一个单元内多通道。
- Ocu_GetCounter获取参数不建议频繁使用，影响系统性能
- Ocu_StopChannel不支持在周期结束停止，是立刻停止


## 10.2 限制

### 10.2.1




