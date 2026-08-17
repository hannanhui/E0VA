# ChipOn Microcontroller Abstract Layer Users Manual - ICU Driver
Release V0.0 - May 2024  
Published by ChipOn 

---

## 变更记录


| 时间       | 版本 | 变更记录    |
| :--------- | :--- | :---------- |
| 2024-05-15 | 0.1  | 初       版 |


----

<a name="br4"></a> 



## 目录

- [ChipOn Microcontroller Abstract Layer Users Manual - ICU Driver](#chipon-microcontroller-abstract-layer-users-manual---icu-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 ICU Driver概述](#第2章-icu-driver概述)
    - [2.1 软件硬件模块映射](#21-软件硬件模块映射)
    - [2.1.1 ICU硬件原理框图](#211-icu硬件原理框图)
    - [2.1.2 IRQ](#212-irq)
    - [2.1.3 系统时钟](#213-系统时钟)
    - [2.1.4 软件驱动程序描述](#214-软件驱动程序描述)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 ICUGeneral](#43-icugeneral)
    - [4.3.1 ICU\_PRECOMPILE\_SUPPORT](#431-icu_precompile_support)
    - [4.3.2 IcuDevErrorDetect](#432-icudeverrordetect)
    - [4.3.3 IcuDeInitApi](#433-icudeinitapi)
    - [4.3.4 IcuSetModeApi](#434-icusetmodeapi)
    - [4.3.5 IcuDisableWakeupApi](#435-icudisablewakeupapi)
    - [4.3.6 IcuEnableWakeupApi](#436-icuenablewakeupapi)
    - [4.3.7 IcuWakeupFunctionalityApi](#437-icuwakeupfunctionalityapi)
    - [4.3.98 IcuGetInputStateApi](#4398-icugetinputstateapi)
    - [4.3.9 IcuTimestampApi](#439-icutimestampapi)
    - [4.3.10 IcuEdgeCountApi](#4310-icuedgecountapi)
    - [4.3.11 IcuEdgeDetectApi](#4311-icuedgedetectapi)
    - [4.3.12 IcuGetTimeElapsedApi](#4312-icugettimeelapsedapi)
    - [4.3.13 IcuGetDutyCycleValuesApi](#4313-icugetdutycyclevaluesapi)
    - [4.3.14 IcuSignalMeasurementApi](#4314-icusignalmeasurementapi)
    - [4.3.15 IcuGetVersionInfoApi](#4315-icugetversioninfoapi)
  - [4.4 IcuChannel](#44-icuchannel)
    - [4.4.1 IcuChannelId](#441-icuchannelid)
    - [4.4.2 IcuDefaultStartEdge](#442-icudefaultstartedge)
    - [4.4.3 IcuMeasurementMode](#443-icumeasurementmode)
    - [4.4.4 IcuWakeupCapability](#444-icuwakeupcapability)
    - [4.4.5 IcuSignalNotification](#445-icusignalnotification)
    - [4.4.6 IcuSignalMeasurement](#446-icusignalmeasurement)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Icu\_ConfigType](#611-类型定义-icu_configtype)
    - [6.1.2 类型定义 Icu\_ChannelConfigType](#612-类型定义-icu_channelconfigtype)
    - [6.1.3 类型定义 Icu\_ImUnitConfigType](#613-类型定义-icu_imunitconfigtype)
    - [6.1.4 类型定义 Ccp\_ClkSourceType](#614-类型定义-ccp_clksourcetype)
    - [6.1.5 类型定义 Icu\_ModuleType](#615-类型定义-icu_moduletype)
    - [6.1.6 类型定义 Icu\_ModuleChannelType](#616-类型定义-icu_modulechanneltype)
    - [6.1.7 类型定义 Icu\_MeasurementModeType](#617-类型定义-icu_measurementmodetype)
    - [6.1.8 类型定义 Icu\_SignalMeasurementPropertyType](#618-类型定义-icu_signalmeasurementpropertytype)
    - [6.1.9类型定义 Icu\_DutyCycleType](#619类型定义-icu_dutycycletype)
    - [6.1.10 类型定义 Icu\_ModeType](#6110-类型定义-icu_modetype)
    - [6.1.11 类型定义 Icu\_InputStateType](#6111-类型定义-icu_inputstatetype)
    - [6.1.12 类型定义 Icu\_ActivationType](#6112-类型定义-icu_activationtype)
    - [6.1.13 类型定义 Icu\_IndexType](#6113-类型定义-icu_indextype)
    - [6.1.14 类型定义 Icu\_EdgeNumberType](#6114-类型定义-icu_edgenumbertype)
    - [6.1.15 类型定义 Icu\_ValueType](#6115-类型定义-icu_valuetype)
    - [6.1.15 类型定义 Icu\_ChannelType](#6115-类型定义-icu_channeltype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Icu\_Init](#621-icu_init)
    - [6.2.2 Icu\_DeInit](#622-icu_deinit)
    - [6.2.3 Icu\_SetMode](#623-icu_setmode)
    - [6.2.4 Icu\_DisableWakeup](#624-icu_disablewakeup)
    - [6.2.5 Icu\_EnableWakeup](#625-icu_enablewakeup)
    - [6.2.6 Icu\_CheckWakeup](#626-icu_checkwakeup)
    - [6.2.7 Icu\_SetActivationCondition](#627-icu_setactivationcondition)
    - [6.2.8 Icu\_DisableNotification](#628-icu_disablenotification)
    - [6.2.9 Icu\_EnableNotification](#629-icu_enablenotification)
    - [6.2.10 Icu\_GetInputState](#6210-icu_getinputstate)
    - [6.2.11 Icu\_ResetEdgeCount](#6211-icu_resetedgecount)
    - [6.2.12 Icu\_EnableEdgeCount](#6212-icu_enableedgecount)
    - [6.2.13 Icu\_EnableEdgeDetection](#6213-icu_enableedgedetection)
    - [6.2.14 Icu\_DisableEdgeDetection](#6214-icu_disableedgedetection)
    - [6.2.15 Icu\_DisableEdgeCount](#6215-icu_disableedgecount)
    - [6.2.16 Icu\_GetEdgeNumbers](#6216-icu_getedgenumbers)
    - [6.2.17 Icu\_StartSignalMeasurement](#6217-icu_startsignalmeasurement)
    - [6.2.18 Icu\_StopSignalMeasurement](#6218-icu_stopsignalmeasurement)
    - [6.2.19 Icu\_GetDutyCycleValues](#6219-icu_getdutycyclevalues)
    - [6.2.20 Icu\_GetVersionInfo](#6220-icu_getversioninfo)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Icu\_Isr](#631-icu_isr)
      - [表79 服务请求节点 - ICU硬件资源](#表79-服务请求节点---icu硬件资源)
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
        - [ICU头文件配置示例](#icu头文件配置示例)
        - [ICU通道配置示例](#icu通道配置示例)
        - [ICU硬件配置示例](#icu硬件配置示例)
        - [ICU配置结构体配置示例](#icu配置结构体配置示例)
      - [9.1.11 驱动器初始化](#9111-驱动器初始化)
    - [9.1.2 API用法示例](#912-api用法示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [假设](#假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)


---

# 第1章 引言

本用户手册提供了有关ICU驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的ICU驱动程序实现。该文档描述了如何使用ICU驱动程序
## 1.1 范围

本文档涉及ICU Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- ICU Driver的文件结构
- Driver的配置参数
- 由ICU Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于ICU Driver

## 1.2 缩写

MCAL: Microcontroller Abstract Layer，微控制器抽象层
ICU: Input Capture Unit，输入捕获单元
CCP: Capture/Compare/PWM

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of ICU Driver AUTOSAR CP R22-11
- [2] Requirements on ICU Driver AUTOSAR CP R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 ICU Driver概述
ICU Driver使用KungFu平台的通用捕捉/比较模块。Driver可以配置多个通道。每个通道由一个CCP通道组成，需要为其配置捕获模式和测量模式：
- 下降沿/上升沿/每4次上升沿/每16次上升沿
- 边沿检测/信号测量/时间戳测量/边沿计数
- 低电平时间/高电平时间/周期/占空比
- 通知函数

### 2.1 软件硬件模块映射
本节向用户介绍了实现中使用的硬件特性。图1展示了KungFu硬件外设及其与驱动程序的交互。

### 2.1.1 ICU硬件原理框图

### 2.1.2 IRQ
IRQ Driver负责初始化通用定时器所需的中断优先级。见表79

### 2.1.3 系统时钟
系统时钟通过MCU Driver设置。必须设置适当的系统时钟。

### 2.1.4 软件驱动程序描述

---

# 第3章 文件结构
本节提供了有关ICU Driver文件和其他相关文件的详细信息。
| Name      | Description                                     |
| :-------- | :---------------------------------------------- |
| Icu.c     | 此文件包含ICU驱动程序的通用功能                 |
| Icu.h     | 此头文件输出ICU驱动程序的宏、类型定义和函数原型 |
| Icu_Cfg.h | 本文在这里声明了ICU驱动程序的配置数据。         |
| Icu_Im.c  | 此文件包含ICU模块所需要的硬件驱动程序           |
| Icu_Im.h  | 此头文件输出ICU驱动程序的宏、类型定义和函数原型 |

---

# 第4章 配置文档

## 4.1 配置概念

### 4.1.1 配置类
开发基本软件驱动涉及以下开发周期：
- 编译
- 链接
- 下载可执行文件到ECU内存

根据配置参数的配置类别，配置类如下分类：
- 预编译时时：通过编译器开关或影响整个构建过程的变量实现。
- 链接时：不影响编译阶段，但影响链接和定位阶段。
- 构建后：不会影响构建过程，因此构建后时间配置在运行时应用于驱动器。


## 4.2 配置参数变化
本节描述了相对于支持的微控制器的配置参数的变化。ICU Driver在支持的微控制器上没有变化的参数。

## 4.3 ICUGeneral

### 4.3.1 ICU_PRECOMPILE_SUPPORT
- **名称**: ICU_PRECOMPILE_SUPPORT
- **来源**: 
- **文件**: Icu_Cfg.h
- **范围**: 值：STD_ON/STD_OFF ，默认值：STD_OFF
- **配置类别**: 预编译时 
- **描述**: 选择ICU驱动程序是否支持预编译时

### 4.3.2 IcuDevErrorDetect
- **名称**: IcuDevErrorDetect
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：STD_ON – 使能检查和通知，STD_OFF – 使能检查和通知 ，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: 使能开发错误检测和通知

### 4.3.3 IcuDeInitApi
- **名称**: IcuDeInitApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_DeInit函数开关

### 4.3.4 IcuSetModeApi
- **名称**: IcuSetModeApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_SetMode函数开关

### 4.3.5 IcuDisableWakeupApi
- **名称**: IcuDisableWakeupApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_DisableWakeup函数开关

### 4.3.6 IcuEnableWakeupApi
- **名称**: IcuEnableWakeupApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_EnableWakeup函数开关

### 4.3.7 IcuWakeupFunctionalityApi
- **名称**: IcuWakeupFunctionalityApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_CheckWakeup函数开关

### 4.3.98 IcuGetInputStateApi
- **名称**: IcuGetInputStateApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_GetInputState函数开关

### 4.3.9 IcuTimestampApi
- **名称**: IcuTimestampApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_StartTimestamp、Icu_StopTimestamp、Icu_GetTimestampIndex函数开关

### 4.3.10 IcuEdgeCountApi
- **名称**: IcuEdgeCountApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_ResetEdgeCount、Icu_EnableEdgeCount、Icu_DisableEdgeCount、Icu_GetEdgeNumbers函数开关

### 4.3.11 IcuEdgeDetectApi
- **名称**: IcuEdgeDetectApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_EnableEdgeDetection、Icu_DisableEdgeDetection函数开关

### 4.3.12 IcuGetTimeElapsedApi
- **名称**: IcuGetTimeElapsedApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_GetTimeElapsed函数开关

### 4.3.13 IcuGetDutyCycleValuesApi
- **名称**: IcuGetDutyCycleValuesApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_GetDutyCycleValues函数开关

### 4.3.14 IcuSignalMeasurementApi
- **名称**: IcuSignalMeasurementApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_StartSignalMeasurement和Icu_StopSignalMeasurement函数开关

### 4.3.15 IcuGetVersionInfoApi
- **名称**: IcuGetVersionInfoApi
- **来源**: AUTOSAR
- **文件**: Icu_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Icu_GetVersionInfo函数开关
---
## 4.4 IcuChannel

### 4.4.1 IcuChannelId
- **名称**: IcuChannelId
- **来源**: AUTOSAR定义
- **文件**: Icu_LCfg.h
- **范围**: 值：0 .. 255，
- **配置类别**: 预编译时 
- **描述**: ICU通道的ID

### 4.4.2 IcuDefaultStartEdge
- **名称**: IcuDefaultStartEdge
- **来源**: AUTOSAR定义
- **文件**: Icu_LCfg.h
- **范围**: 值：ICU_BOTH_EDGES/ICU_FALLING_EDGE/ICU_RISING_EDGE
- **配置类别**: 预编译时/构建后
- **描述**: ICU默认触发边沿配置

### 4.4.3 IcuMeasurementMode
- **名称**: IcuMeasurementMode
- **来源**: AUTOSAR定义
- **文件**: Icu_LCfg.h
- **范围**: 值：ICU_MODE_EDGE_COUNTER/ICU_MODE_SIGNAL_EDGE_DETECT/ICU_MODE_SIGNAL_MEASUREMENT/ICU_MODE_TIMESTAMP
- **配置类别**: 预编译时 /构建后
- **描述**: ICU通道的测量模式

### 4.4.4 IcuWakeupCapability
- **名称**: IcuWakeupCapability
- **来源**: AUTOSAR定义
- **文件**: Icu_LCfg.h
- **范围**: 值： true: 通道可唤醒. false: 通道不可唤醒
- **配置类别**: 预编译时/构建后
- **描述**: ICU通道是否可唤醒配置

### 4.4.5 IcuSignalNotification
- **名称**: IcuSignalNotification
- **来源**: AUTOSAR定义
- **文件**: Icu_LCfg.h
- **范围**: --
- **配置类别**: 预编译时/构建后 
- **描述**: 信号通知函数

### 4.4.6 IcuSignalMeasurement
- **名称**: IcuSignalMeasurement
- **来源**: AUTOSAR定义
- **文件**: Icu_LCfg.h
- **范围**: 值：ICU_DUTY_CYCLE/ICU_HIGH_TIME/ICU_LOW_TIME/ICU_PERIOD_TIME
- **配置类别**: 预编译时/构建后 
- **描述**: 包含测量模式为IcuSignalMeasurement时的配置参数

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: ICU_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Icu.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: ICU_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Icu.h
- **值**: 100
- **描述**: 这个宏给出了ICU驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: ICU_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Icu.h
- **值**: 0
- **描述**: 这个宏给出了ICU驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: ICU_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Icu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: ICU_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Icu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: ICU_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Icu.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Icu_ConfigType
- **语法**: Icu_ConfigType
- **类型**: Struct
- **文件**: Icu.h
- **范围**: 
  - ChannelConfigArray (Icu_ChannelConfigType*)
  - 指向Icu_ChannelConfigType
  - HwUnitConfigArray (Icu_ImUnitConfigType*)
  - 指向Icu_ImUnitConfigType
- **NumChannels** (uint8)
  - ICU通道数量
- **NumHwUnits** (uint8)
  - ICU硬件单元数量
- **描述**: 此类型定义用于配置ICU的整体配置。此类型的指针在Icu_Init API中用于初始化ICU驱动程序。

### 6.1.2 类型定义 Icu_ChannelConfigType 
- **语法**: Icu_ChannelConfigType
- **类型**: struct
- **文件**: Icu.h
- **范围**:
- **HwUnitIndex** (uint8)
  - 硬件单元索引
- **PhysicalChannelIndex**(Icu_ModuleChannelType)
  - 物理通道索引
- **DefaultEdge**(Icu_ActivationType)
  - 默认边沿触发方式配置
- **WakeupValue**(Icu_WakeupValueType)
  - EcuM 唤醒源ID
- **MeasurementMode**(Icu_MeasurementModeType)
  - 测量模式配置
- **SignalProperty**(Icu_SignalMeasurementPropertyType)
  - 测量属性配置
- **NotifyFcn**(Icu_NotifyFcnType)
  - 通知函数
- **描述**: 这是包含ICU Channel特定参数的数据结构类型。

### 6.1.3 类型定义 Icu_ImUnitConfigType 
- **语法**: Icu_ImUnitConfigType
- **类型**: struct
- **文件**: Icu.h
- **范围**:
- **HwModuleType** (uint8)
  - ICU硬件单元类型，CCP/ECCP
- **HwModule**(Icu_ModuleType)
  - ICU硬件模块
- **ClockSource**(Ccp_ClkSourceType)
  - ICU硬件模块时钟源
- **uint8**(Prescaler*)
  - ICU硬件模块时钟源分频系数
- **MaxPeriodCounter**(uint32)
  - CU硬件模块最大周期计数值
- **描述**: 这是包含ICU 硬件单元特定参数的数据结构类型。

### 6.1.4 类型定义 Ccp_ClkSourceType
- **语法**: Ccp_ClkSourceType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: CCP_SCLK/CCP_HFCLK
- **描述**: CCP时钟源

### 6.1.5 类型定义 Icu_ModuleType
- **语法**: Icu_ModuleType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: ICU_MODULE_0/ICU_MODULE_1/ICU_MODULE_2/ICU_MODULE_3/ICU_MODULE_4/ICU_MODULE_18/ICU_MODULE_19/ICU_MODULE_20/ICU_MODULE_21/ICU_MODULE_22/ICU_MODULE_23
- **描述**: ICU硬件单元索引

### 6.1.6 类型定义 Icu_ModuleChannelType
- **语法**: Icu_ModuleChannelType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: ICU_MODULECHANNEL_1/ICU_MODULECHANNEL_2/ICU_MODULECHANNEL_3/ICU_MODULECHANNEL_4
- **描述**: ICU物理通道索引

### 6.1.7 类型定义 Icu_MeasurementModeType
- **语法**: Icu_MeasurementModeType
- **类型**: Enum
- **文件**: Icu.h
- **范围**:     ICU_MODE_SIGNAL_EDGE_DETECT/ICU_MODE_SIGNAL_MEASUREMENT/ICU_MODE_TIMESTAMP/ICU_MODE_EDGE_COUNTER
- **描述**: ICU测量模式

### 6.1.8 类型定义 Icu_SignalMeasurementPropertyType
- **语法**: Icu_SignalMeasurementPropertyType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: ICU_LOW_TIME/ICU_HIGH_TIME/ICU_PERIOD_TIME/ICU_DUTY_CYCLE
- **描述**: ICU测量属性

### 6.1.9类型定义 Icu_DutyCycleType
- **语法**: Icu_DutyCycleType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: ActiveTime/PeriodTime
- **描述**: 包含计算占空比所需的值

### 6.1.10 类型定义 Icu_ModeType
- **语法**: Icu_ModeType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: ICU_MODE_NORMAL/ICU_MODE_SLEEP
- **描述**: ICU模式选择

### 6.1.11 类型定义 Icu_InputStateType
- **语法**: Icu_InputStateType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: ICU_ACTIVE/ICU_IDLE
- **描述**: ICU通道的输入状态

### 6.1.12 类型定义 Icu_ActivationType
- **语法**: Icu_ActivationType
- **类型**: Enum
- **文件**: Icu.h
- **范围**: ICU_FALLING_EDGE/ICU_RISING_EDGE/ICU_RISING4_EDGES/ICU_RISING16_EDGES
- **描述**: ICU通道触发边沿类型

### 6.1.13 类型定义 Icu_IndexType
- **语法**: Icu_IndexType
- **类型**: uint16
- **文件**: Icu.h
- **范围**: 0到65535
- **描述**: Icu_GetTimestampIndex的返回值类型

### 6.1.14 类型定义 Icu_EdgeNumberType
- **语法**: Icu_EdgeNumberType
- **类型**: uint16
- **文件**: Icu.h
- **范围**: 0到65535
- **描述**: Icu_GetEdgeNumbers的返回值类型

### 6.1.15 类型定义 Icu_ValueType
- **语法**: Icu_ValueType
- **类型**: uint32
- **文件**: Icu.h
- **范围**: 0到0xFFFFFFFF
- **描述**: 时间戳和测量时间的缓冲区宽度

### 6.1.15 类型定义 Icu_ChannelType
- **语法**: Icu_ChannelType
- **类型**: uint8
- **文件**: Icu.h
- **范围**: 0到255
- **描述**: ICU通道的ID类型
---
## 6.2 API函数

### 6.2.1 Icu_Init
- **服务名称**: Icu_Init
- **语法**: void Icu_Init (const Icu_ConfigType* ConfigPtr ) 
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: ConfigPtr - 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化ICU驱动程序的服务。

### 6.2.2 Icu_DeInit
- **服务名称**: Icu_DeInit
- **语法**: void Icu_DeInit (void)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 去初始化ICU驱动程序。

### 6.2.3 Icu_SetMode
- **服务名称**: Icu_SetMode
- **语法**: void Icu_SetMode (Icu_ModeType Mode)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**:  Mode - ICU工作模式
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置ICU模式

### 6.2.4 Icu_DisableWakeup
- **服务名称**: Icu_DisableWakeup
- **语法**: void Icu_DisableWakeup (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x03
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 函数禁用单个ICU通道的唤醒功能

### 6.2.5 Icu_EnableWakeup
- **服务名称**: Icu_EnableWakeup
- **语法**: void Icu_EnableWakeup (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 函数使能单个ICU通道的唤醒功能

### 6.2.6 Icu_CheckWakeup
- **服务名称**: Icu_CheckWakeup
- **语法**: void Icu_CheckWakeup (EcuM_WakeupSourceType WakeupSource)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x15
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: WakeupSource - 被检查的唤醒源信息
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 函数应检查具有唤醒能力的ICU通道是否是唤醒事件的来源，并呼叫EcuM_SetWakeupEvent向ECU状态管理器指示有效的定时器唤醒事件

### 6.2.7 Icu_SetActivationCondition
- **服务名称**: Icu_SetActivationCondition
- **语法**: void Icu_SetActivationCondition (Icu_ChannelType Channel,Icu_ActivationType Activation)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x05
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 
  - Channel - ICU通道ID
  - Activation - 边沿类型
- **参数(输出)**: 无
- **返回值**: ICU_StatusType
- **描述**: 根据给定通道的激活参数设置激活边沿

### 6.2.8 Icu_DisableNotification
- **服务名称**: Icu_DisableNotification
- **语法**: void Icu_DisableNotification (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x06
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 返函数将禁用给定通道上的通知

### 6.2.9 Icu_EnableNotification
- **服务名称**: Icu_EnableNotification
- **语法**: void Icu_EnableNotification (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x07
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 返函数将使能给定通道上的通知

### 6.2.10 Icu_GetInputState
- **服务名称**: Icu_GetInputState
- **语法**: Icu_InputStateType Icu_GetInputState (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x08
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: InputStateType - ICU输入状态
- **描述**: 函数I将返回ICU输入的状态

### 6.2.11 Icu_ResetEdgeCount
- **服务名称**: Icu_ResetEdgeCount
- **语法**: void Icu_ResetEdgeCount (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x0c
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 函数复位边沿计数值为0

### 6.2.12 Icu_EnableEdgeCount
- **服务名称**: Icu_EnableEdgeCount
- **语法**: void Icu_EnableEdgeCount (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x0d
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 返函数将使能给定通道上的边沿计数

### 6.2.13 Icu_EnableEdgeDetection
- **服务名称**: 6 Icu_EnableEdgeDetection
- **语法**: void 6 Icu_EnableEdgeDetection (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x16
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 返函数将使能给定通道上的边沿检测

### 6.2.14 Icu_DisableEdgeDetection
- **服务名称**: Icu_DisableEdgeDetection
- **语法**: void Icu_DisableEdgeDetection (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x17
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 返函数将禁止给定通道上的边沿检测

### 6.2.15 Icu_DisableEdgeCount
- **服务名称**: Icu_DisableEdgeCount
- **语法**: void Icu_DisableEdgeCount (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x0e
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 返函数将禁止给定通道上的边沿计数

### 6.2.16 Icu_GetEdgeNumbers
- **服务名称**: Icu_GetEdgeNumbers
- **语法**: Icu_EdgeNumberType Icu_GetEdgeNumbers (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x0f
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: Icu_EdgeNumberType - 边沿计数的计数值
- **描述**: 函数将读取边沿计数的计数值

### 6.2.17 Icu_StartSignalMeasurement
- **服务名称**: Icu_StartSignalMeasurement
- **语法**: void Icu_StartSignalMeasurement (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x13
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 函数将开始测量从配置的默认起始边沿开始的信号

### 6.2.18 Icu_StopSignalMeasurement
- **服务名称**: Icu_StopSignalMeasurement
- **语法**: void Icu_StopSignalMeasurement (Icu_ChannelType Channel)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x14
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 函数应停止测量给定通道的信号

### 6.2.19 Icu_GetDutyCycleValues
- **服务名称**: Icu_GetDutyCycleValues
- **语法**: void Icu_GetDutyCycleValues (Icu_ChannelType Channel,Icu_DutyCycleType* DutyCycleValues)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x11
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - ICU通道ID
- **参数(输出)**: DutyCycleValues - 存储占空比信息的buffer指针
- **返回值**: 无
- **描述**: 函数将读取给定ICU通道的有效时间和周期

### 6.2.20 Icu_GetVersionInfo
- **服务名称**: Icu_GetVersionInfo
- **语法**: void Icu_GetVersionInfo (Std_VersionInfoType* versioninfo)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x12
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: versioninfo - 存储驱动版本信息的指针
- **返回值**: 无
- **描述**: 返回驱动的版本信息的服务
---
## 6.3 中断处理

### 6.3.1 Icu_Isr
- **服务名称**: Icu_Isr
- **语法**：`FUNC(void, ICU_CODE) Icu_Isr(CONST(uint8, ICU_VAR) Module)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：不可重入
- **参数（输入）**：Module - ICU硬件单元
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 通知功能
  - 记录边沿计数
  - 记录PWM周期占空比
- **警告**：无
- **配置**：无
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有10个SRN（服务请求节点）用于服务ICU通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - ICU硬件资源

| 硬件资源      | SRN编号               |
| ------------- | --------------------- |
| ICU_MODULE_0  | T0_UNIFIED_INTERRUPT  |
| ICU_MODULE_1  | T1_UNIFIED_INTERRUPT  |
| ICU_MODULE_2  | T2_UNIFIED_INTERRUPT  |
| ICU_MODULE_3  | T3_UNIFIED_INTERRUPT  |
| ICU_MODULE_4  | T4_UNIFIED_INTERRUPT  |
| ICU_MODULE_18 | T18_UNIFIED_INTERRUPT |
| ICU_MODULE_19 | T19_UNIFIED_INTERRUPT |
| ICU_MODULE_21 | T21_UNIFIED_INTERRUPT |
| ICU_MODULE_22 | T22_UNIFIED_INTERRUPT |
| ICU_MODULE_23 | T23_UNIFIED_INTERRUPT |

---
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

ICU Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是ICU Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                     | 类型/范围              | 描述                            |
| ------------------------ | ---------------------- | ------------------------------- |
| kpIcu_ConfigPtr          | Icu_ConfigType         | ICU Driver配置结构的指针。      |
| kvIcu_CurrentMode        | Icu_ModeType           | 存储ICU当前模式                 |
| kvIcu_MapTable           | uint8                  | 存储硬件模块和通道的Icu通道索引 |
| kvIcu_ChannelInformation | Icu_ChannelInformation | 存储ICU 当前通道测量信息        |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是ICU Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                    | 错误描述                                         | 值（十六进制） |
| --------------------------- | ------------------------------------------------ | -------------- |
| ICU_E_PARAM_POINTER         | API传入无效指针                                  | 0x0A           |
| ICU_E_PARAM_CHANNEL         | API传入无效通道ID                                | 0x0B           |
| ICU_E_PARAM_ACTIVATION      | API传入无效边沿触发方式                          | 0x0C           |
| ICU_E_INIT_FAILED           | ICU初始化失败                                    | 0x0D           |
| ICU_E_PARAM_BUFFER_SIZE     | API传入错误的buffer大小                          | 0x0E           |
| ICU_E_PARAM_MODE            | Icu_SetMode传入错误模式                          | 0x0F           |
| ICU_E_UNINIT                | ICU未初始化                                      | 0x14           |
| ICU_E_BUSY_OPERATION        | Icu_SetMode在运行时调用                          | 0x16           |
| ICU_E_ALREADY_INITIALIZED   | Icu_Init在初始化后重复调用                       | 0x17           |
| ICU_E_PARAM_NOTIFY_INTERVAL | Icu_StartTimeStamp调用错误的NotifyInterval擦参数 | 0x18           |
| ICU_E_PARAM_VINFO           | Icu_GetVersionInfo传入Versioninfo参数错误        | 0x19           |
| ICU_E_NOT_STARTED           | Icu_StopTimestamp在通道未开始时调用              | 0x15           |

-----
# 第9章 示例用法
本章描述了如何配置ICU驱动器以及如何在应用程序中使用ICU驱动器提供的不同的API。

## 9.1 驱动器配置
按照以下指南正确配置ICU驱动器：
1. MCU驱动器：配置系统时钟。
2. 中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级

### 9.1.1 驱动器的示例配置
##### ICU头文件配置示例
```c
#define ICU_DEV_ERROR_DETECT STD_ON
#define ICU_PRECOMPILE_SUPPORT STD_OFF
#define ICU_DE_INIT_API STD_ON
#define ICU_SET_MODE_API STD_ON
#define ICU_DISABLE_WAKEUP_API STD_ON
#define ICU_ENABLE_WAKEUP_API STD_ON
#define ICU_WAKEUP_FUNCTIONALITY_API STD_ON
#define ICU_GET_INPUT_STATE_API STD_ON
#define ICU_TIMESTAMP_API STD_ON
#define ICU_EDGE_COUNT_API STD_ON
#define ICU_EDGE_DETECT_API STD_ON
#define ICU_SIGNAL_MEASUREMENT_API STD_ON
#define ICU_GET_TIME_ELAPSED_API STD_ON
#define ICU_GET_DUTY_CYCLE_VALUES_API STD_ON
#define ICU_VERSION_INFO_API STD_ON
#define ICU_CONFIGED_CHANNEL 2
```

##### ICU通道配置示例
```c
static CONST(Icu_ChannelConfigType, ICU_VAR) kvIcu_IpChannelConfig_PB[ICU_CONFIGED_CHANNEL] = {
  [0U] =
    {
      .HwUnitIndex          = 0U,
      .PhysicalChannelIndex = ICU_MODULECHANNEL_1,
      .WakeupCapable        = 0U,
      .DefaultEdge          = ICU_RISING_EDGE,
#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
      .WakeupValue = 0U,
#endif
      .MeasurementMode = ICU_MODE_SIGNAL_MEASUREMENT,
      .SignalProperty  = ICU_DUTY_CYCLE,
      .NotifyFcn       = Icu_Notification_0,
    },
  [1U] = {
    .HwUnitIndex          = 1U,
    .PhysicalChannelIndex = ICU_MODULECHANNEL_4,
    .WakeupCapable        = 0U,
    .DefaultEdge          = ICU_RISING_EDGE,
#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
    .WakeupValue = 0U,
#endif
    .MeasurementMode = ICU_MODE_EDGE_COUNTER,
    .SignalProperty  = ICU_LOW_TIME,
    .NotifyFcn       = NULL_PTR,
  }};
```
##### ICU硬件配置示例
```c
static CONST(Icu_ImUnitConfigType, ICU_VAR) kvIcu_Base_ModuleConfig_PB[] = {
  [0U] =
    {
      .HwModuleType     = 0U,
      .HwModule         = ICU_MODULE_18,
      .ClockSource      = CCP_HFCLK,
      .Prescaler        = 16000U,
      .MaxPeriodCounter = 0xFFFFU,
    },
  [1U] = {
    .HwModuleType     = 0U,
    .HwModule         = ICU_MODULE_23,
    .ClockSource      = CCP_HFCLK,
    .Prescaler        = 16000U,
    .MaxPeriodCounter = 0xFFFFU,
  }};
```
##### ICU配置结构体配置示例
```c
CONST(Icu_ConfigType, ICU_VAR)
IcuConfig[1] = {{
  .NumChannels        = sizeof(kvIcu_IpChannelConfig_PB) / sizeof(Icu_ChannelConfigType),
  .ChannelConfigArray = &kvIcu_IpChannelConfig_PB[0U],
  .NumHwUnits         = sizeof(kvIcu_Base_ModuleConfig_PB) / sizeof(Icu_ImUnitConfigType),
  .HwUnitConfigArray  = &kvIcu_Base_ModuleConfig_PB[0U],
}};
```

#### 9.1.11 驱动器初始化
代码清单3展示了初始化ICU驱动器所涉及的步骤。注意：用户必须确保在调用ICU_Init之前调用Mcu_Init
```c
// 初始化MCU驱动器
Mcu_Init(&Mcu_ConfigRoot[0]);
//初始化时钟
Mcu_InitClock(0);
while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
{
}
Mcu_DistributePllClock();
// 初始化MCU端口
Port_Init(&Port_ConfigPredefined);
// 初始化中断
Irq_Init(&Irq_ConfigPredefined);
// 初始化ICU驱动器
Icu_Init(&Icu_ConfigPredefined);

```
### 9.1.2 API用法示例
以下是ICU驱动器提供的API用法示例
```c

//使能给定通道的边沿计数
Icu_EnableEdgeCount(0);
//复位边沿计数值
Icu_ResetEdgeCount(0);
//使能给定通道边沿采样
Icu_EnableEdgeDetection(0);
//停止给定通道边沿采样
Icu_DisableEdgeDetection(0);
//使能给定通道的测量
Icu_StartSignalMeasurement(0);
//停止给定通道的测量
Icu_StopSignalMeasurement(0);
//获取给定通道的占空比信息
Icu_DutyCycleType pwmInfo = {0, 0};
Icu_GetDutyCycleValues(0, &pwmInfo);
//获取给定通道的边沿计数
Icu_GetEdgeNumbers(0);
//获取给定通道的脉宽时间
Icu_GetTimeElapsed(0);
``` 

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 假设

| 序号 | 参考 | 假设 |
| ---- | ---- | ---- |
| 1    | 通用 |      |
| 2    | 通用 |      |

### 偏差

### 考虑的Bugzilla

1. Icu_StartTimestamp、Icu_StopTimestamp、Icu_GetTimestampIndex函数未实现。

## 10.2 限制
1. 支持最大6个ICU硬件模块，每个硬件单元支持4个通道。
2. ICU使用的CCP单元不支持同时检测上升沿和下降沿。
---



