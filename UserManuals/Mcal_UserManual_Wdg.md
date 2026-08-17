# ChipOn Microcontroller Abstract Layer Users Manual - WDG Driver
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

- [ChipOn Microcontroller Abstract Layer Users Manual - WDG Driver](#chipon-microcontroller-abstract-layer-users-manual---wdg-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 WDG Driver概述](#第2章-wdg-driver概述)
    - [2.1 软件硬件模块映射](#21-软件硬件模块映射)
    - [2.1.1 通用定时器](#211-通用定时器)
    - [2.1.2 WDG](#212-wdg)
    - [2.1.3 IRQ](#213-irq)
    - [2.1.4 系统时钟](#214-系统时钟)
    - [2.1.4.1 软件驱动程序描述](#2141-软件驱动程序描述)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 WdgDriverConfiguration](#43-wdgdriverconfiguration)
    - [4.3.1 WDG\_DEV\_ERROR\_DETECT](#431-wdg_dev_error_detect)
    - [4.3.2 WDG\_DISABLE\_ALLOWED](#432-wdg_disable_allowed)
    - [4.3.3 WDG\_PRECOMPILE\_SUPPORT](#433-wdg_precompile_support)
    - [4.3.4 WDG\_MAX\_TIMEOUT](#434-wdg_max_timeout)
    - [4.3.5 WDG\_INITIAL\_TIMEOUT](#435-wdg_initial_timeout)
    - [4.3.6 GPT\_GPTIMER\_CHAN\_T14](#436-gpt_gptimer_chan_t14)
    - [4.3.7 WDG\_MAX\_RELOAD](#437-wdg_max_reload)
  - [4.4 WdgConfigurationOfOptApiServices](#44-wdgconfigurationofoptapiservices)
    - [4.4.1 WDG\_VERSION\_INFO\_API](#441-wdg_version_info_api)
  - [4.5 Wdg\_ConfigPredefined](#45-wdg_configpredefined)
    - [4.5.1 GptConf](#451-gptconf)
      - [4.5.1.1 GptModuleForService](#4511-gptmoduleforservice)
      - [4.5.1.5 FastServiceGptCbkTime](#4515-fastservicegptcbktime)
      - [4.5.1.6 SlowServiceGptCbkTime](#4516-slowservicegptcbktime)
      - [4.5.1.7 Prescaler](#4517-prescaler)
      - [4.5.1.8 WorkMode](#4518-workmode)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Wdg\_ConfigType](#611-类型定义-wdg_configtype)
    - [6.1.2 类型定义 Wdg\_GptSettingsType](#612-类型定义-wdg_gptsettingstype)
    - [6.1.3 类型定义 WdgIf\_ModeType](#613-类型定义-wdgif_modetype)
    - [6.1.4 类型定义 Wdg\_ValueType](#614-类型定义-wdg_valuetype)
    - [6.1.5 类型定义 Wdg\_StatusType](#615-类型定义-wdg_statustype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Wdg\_GetVersionInfo](#621-wdg_getversioninfo)
    - [6.2.2 Wdg\_Init](#622-wdg_init)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Wdg\_Isr](#631-wdg_isr)
      - [表79 服务请求节点 - T14硬件资源](#表79-服务请求节点---t14硬件资源)
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


---

# 第1章 引言

本用户手册提供了有关WDG驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的 WDG 驱动程序实现。该文档描述了如何使用 WDG 驱动程序
## 1.1 范围

本文档涉及WDG WDG
-KungFu微控制器硬件外设，用于实现Driver
- WDG Driver的文件结构
- Driver的配置参数
- 由 WDG Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于WDG Driver

## 1.2 缩写

MCAL: Microcontroller Abstract Layer，微控制器抽象层
WDG: Watch Dog，看门狗

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of WDG Driver, AUTOSAR_SWS_WDG_Driver.pdf Release R22-11
- [2] Requirements of WDG Driver, AUTOSAR_SRS_WDG_Driver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 WDG Driver概述
WDG Driver使用KungFu平台的独立看门狗外设
### 2.1 软件硬件模块映射
本节向用户介绍了实现中使用的硬件特性。图1展示了KungFu硬件外设及其与驱动程序的交互。

### 2.1.1 通用定时器
独立看门狗硬件块图示见图2，用作硬件资源的基础。本章的目的仅关注WDG Driver使用的资源

### 2.1.2 WDG


### 2.1.3 IRQ
IRQ Driver负责初始化通用定时器所需的中断优先级。见表79

### 2.1.4 系统时钟
系统时钟通过MCU Driver设置。必须设置适当的系统时钟。

### 2.1.4.1 软件驱动程序描述
图3显示了WDG Driver的应用程序编程接口（API）及其与其他软件模块的交互。

---

# 第3章 文件结构
本节提供了有关WDG Driver文件和其他相关文件的详细信息。
| Name       | Description                                     |
| :--------- | :---------------------------------------------- |
| Wdg.c      | 此文件包含WDG驱动程序的通用功能                 |
| Wdg.h      | 此头文件输出WDG驱动程序的宏、类型定义和函数原型 |
| Wdg_Cfg.h  | 本文在这里声明了WDG驱动程序的配置数据           |
| Wdg_Hw.c   | 芯片具体实现的API定义                           |
| Wdg_Hw.h   | 芯片具体实现API声明                             |
| Wdg_LCfg.c | WDG Driver 所有PostBuild 变量                   |
| Wdg_Irq.c  | 此文件包含WDG驱动程序的中断信息                 |

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
本节描述了相对于支持的微控制器的配置参数的变化。WDG Driver在支持的微控制器上没有变化的参数。

## 4.3 WdgDriverConfiguration
本节详细描述了WDG Driver提供的配置，包括AUTOSAR WDG Driver规范[1]中描述的配置以及特定于微控制器的配置。

### 4.3.1 WDG_DEV_ERROR_DETECT
- **名称**: WDG_DEV_ERROR_DETECT
- **来源**: AUTOSAR定义
- **文件**: Wdg_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.2 WDG_DISABLE_ALLOWED
- **名称**: WDG_DISABLE_ALLOWED
- **来源**: AUTOSAR定义
- **文件**: Wdg_Cfg.h
- **范围**: 值：STD_ON – 启用，STD_OFF – 禁用，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.3 WDG_PRECOMPILE_SUPPORT
- **名称**: WDG_PRECOMPILE_SUPPORT
- **来源**: AUTOSAR定义
- **文件**: Wdg_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体
- 
### 4.3.4 WDG_MAX_TIMEOUT
- **名称**: WDG_MAX_TIMEOUT
- **来源**: AUTOSAR定义
- **文件**: Wdg_Cfg.h
- **范围**: 值 : 20000
- **配置类别**: 预编译时间 X 所有变体

### 4.3.5 WDG_INITIAL_TIMEOUT
- **名称**: WDG_INITIAL_TIMEOUT
- **来源**: AUTOSAR定义
- **文件**: Wdg_Cfg.h
- **范围**: 值 :1000
- **配置类别**: 预编译时间 X 所有变体

### 4.3.6 GPT_GPTIMER_CHAN_T14
- **名称**: GPT_GPTIMER_CHAN_T14
- **来源**: CHIPON定义
- **文件**: Wdg_Cfg.h
- **范围**: 值 :0
- **配置类别**: 预编译时间 X 所有变体


### 4.3.7 WDG_MAX_RELOAD
- **名称**: WDG_MAX_RELOAD
- **来源**: CHIPON定义
- **文件**: Wdg_Cfg.h
- **范围**: 值 :0XFFFF
- **配置类别**: 预编译时间 X 所有变体

---
## 4.4 WdgConfigurationOfOptApiServices

### 4.4.1 WDG_VERSION_INFO_API
- **名称**: WDG_VERSION_INFO_API
- **来源**: AUTOSAR定义
- **文件**: Wdg_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体
----
## 4.5 Wdg_ConfigPredefined

### 4.5.1 GptConf
这个容器包含WDG Driver范围配置（参数）。

#### 4.5.1.1 GptModuleForService
- **名称**: GptModuleForService
- **来源**: KungFu定义
- **文件**: Wdg_LCfg.c
- **范围**: 所选定时器编号
- **配置类别**: 预编译时间 X 变体PC

- **配置类别**: 预编译时间 X 变体PC
- **描述**: 指定定时器信号类型。

#### 4.5.1.5 FastServiceGptCbkTime
- **名称**: PreFastServiceGptCbkTimescale
- **来源**: KungFu定义
- **文件**: Wdg_LCfg.c
- **范围**: 值：-快速模式下定时器周期值
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 指定定时器通周期。

#### 4.5.1.6 SlowServiceGptCbkTime
- **名称**: SlowServiceGptCbkTime
- **来源**: KungFu定义
- **文件**: Wdg_LCfg.c
- **范围**: 值：-慢速模式下定时器的周期值
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 指定定时器通周期。

#### 4.5.1.7 Prescaler
- **名称**: Prescaler
- **来源**: KungFu定义
- **文件**: Wdg_LCfg.c
- **范围**: 值：- 定时器的分频值
- **配置类别**: 预编译时间 X 变体PC
- **描述**: 指定定时器的分频系数
- 
#### 4.5.1.8 WorkMode
- **名称**: WorkMode
- **来源**: KungFu定义
- **文件**: Wdg_LCfg.c
- **范围**: 值：-
- **配置类别**: 预编译时间 X 变体PC
- **描述**: WDG的模式。

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: WDG_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Wdg.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: WDG_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Wdg.h
- **值**: 102
- **描述**: 这个宏给出了WDG驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: WDG_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Wdg.h
- **值**: 0
- **描述**: 这个宏给出了WDG驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: WDG_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Wdg.h
- **值**: 1
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: WDG_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Wdg.h
- **值**: 0
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: WDG_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Wdg.h
- **值**: 0
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Wdg_ConfigType
- **语法**: Wdg_ConfigType
- **类型**: struct
- **文件**: Wdg.h
- **范围**:
  - **Wdg_GptSettingsType**
    - GptConf - 定时器配置的结构体
  - **Wdg_ClkSourceType** 
    - WdgClkSource - 时钟源
  - **Wdg_DivisionType**
    - WdgPrescale - 分频
  - **Wdg_ValueType**
    - WdgOverflowValue - 溢出值
  - **Wdg_ValueType**
    - FastModeWdgReloadValue - 快速模式，超时时间
  - **Wdg_ValueType**
    - SlowModeWdgReloadValue - 慢速模式，超时时间
  - **WdgIf_ModeType**
    - WorkMode - 工作模式
- **描述**: 此类型定义用于配置WDG的整体配置。此类型的指针在Wdg_Init API中用于初始化WDG驱动程序。
  
### 6.1.2 类型定义 Wdg_GptSettingsType
- **语法**: Wdg_GptSettingsType
- **类型**: struct
- **文件**: Wdg.h
- **范围**: 
  - **uint8**
    - GptModuleForService - 定时器选择
  - **Wdg_ValueType**
    - FastServiceGptCbkTime - 快速模式的定时器周期。
  - **Wdg_ValueType**
    - SlowServiceGptCbkTime - 慢速模式的定时器周期
  - **Wdg_ValueType** 
    - Prescaler - 定时器分频
- **描述**: 这是包含定时器通道特定参数的数据结构类型。WDG配置由一个定时器组成。

### 6.1.3 类型定义 WdgIf_ModeType
- **语法**: WdgIf_ModeType
- **类型**: Enum
- **文件**: Wdg.h
- **范围**: WDGIF_OFF_MODE/WDGIF_SLOW_MODE/WDGIF_SLOW_MODE
- **描述**: 此类型定义用WDG的模式配置

### 6.1.4 类型定义 Wdg_ValueType
- **语法**: Wdg_ValueType
- **类型**: uint16
- **文件**: Wdg.h
- **范围**: 0-0xFFFF
- **描述**: 配置WDG的时间值的类型

### 6.1.5 类型定义 Wdg_StatusType
- **语法**: Wdg_StatusType
- **类型**: Enum
- **文件**: Wdg.h
- **范围**:WDG_UNINIT/WDG_IDLE/WDG_BUSY
- **描述**:此类型用于WDG驱动的状态配置
  
---

## 6.2 API函数

### 6.2.1 Wdg_GetVersionInfo
- **服务名称**: Wdg_GetVersionInfo
- **语法**: void Wdg_GetVersionInfo ( Std_VersionInfoType *VersionInfoPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: VersionInfoPtr: 存储驱动版本信息的指针。
- **返回值**: 无
- **描述**: 返回驱动的版本信息的服务。实现为宏。

### 6.2.2 Wdg_Init
- **服务名称**: Wdg_Init
- **语法**: void Wdg_Init (const Wdg_ConfigType *ConfigPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: ConfigPtr 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化WDG驱动程序的服务。

- ### 6.2.8 Wdg_SetMode
- **服务名称**: Wdg_SetMode
- **语法**: void Gpt_SetMode(WdgIf_ModeType Mode)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x09
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Mode 要设置驱动的操作模式
- **参数(输出)**: 无
- **返回值**: 无

- ### 6.2.9 Wdg_SetTriggerCondition
- **服务名称**: Wdg_SetTriggerCondition
- **语法**: void Wdg_SetTriggerCondition(uint16 Timeout)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x07
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:设置触发喂狗时间
- **参数(输出)**: 无
- **返回值**: 无

---
## 6.3 中断处理

中断服务例程在WDG Driver中用于通知、报告唤醒事件以及为连续模式通道计算下一个超时值。

### 6.3.1 Wdg_Isr
- **服务名称**: Wdg_Isr
- **语法**：`void Wdg_Isr (void)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：无
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 并执行喂狗
  - 根据配置模式计算喂狗次数
  - 喂狗次数满足后停止喂狗
- **警告**：无
- **配置**：无
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有1个SRN（服务请求节点）用于服务看门狗喂狗请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - T14硬件资源

| 硬件资源 | SRN编号               |
| -------- | --------------------- |
| T14      | T14_UNIFIED_INTERRUPT |

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

WDG Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是WDG Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                  | 类型/范围      | 描述                       |
| --------------------- | -------------- | -------------------------- |
| Wdg_ConfigPtr         | Wdg_ConfigType | WDG Driver配置结构的指针。 |
| Wdg_DriverMode        | WdgIf_ModeType | 存储驱动器当前模式的变量   |
| Wdg_GptTimeOutCounter | uint16         | 存储定时器超时值的变量     |


-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是WDG Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码               | 错误描述       | 值（十六进制） |
| ---------------------- | -------------- | -------------- |
| WDG_E_DRIVER_STATE     | 已经初始化     | 0x10           |
| WDG_E_PARAM_MODE       | 无效模式       | 0x11           |
| WDG_E_PARAM_CONFIG     | 无效配置       | 0x12           |
| WDG_E_PARAM_TIMEOUT    | 无效超时时间   | 0x13           |
| WDG_E_PARAM_POINTER    | 无效指针       | 0x14           |
| WDG_E_INIT_FALED       | 初始化错误     | 0x15           |
| WDG_E_MODE_FAILED      | 模式错误       | 0x16           |
| WDG_E_DISABLE_REJECTED | 初始化模式失败 | 0x17           |


-----
# 第9章 示例用法
本章描述了如何配置WDG驱动器以及如何在应用程序中使用WDG驱动器提供的不同的API。

## 9.1 驱动器配置
按照以下指南正确配置WDG驱动器：
1. MCU驱动器：配置系统时钟。。
2. 中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级
3. WDG驱动器：选择所需的API配置开关

### 9.1.1 驱动器的示例配置

##### 通道配置实例
```c
#define WDG_DEV_ERROR_DETECT (STD_OFF)
#define WDG_DISABLE_ALLOWED (STD_ON)
#define WDG_VERSION_INFO_API (STD_ON)
#define WDG_PB_FIXED_ADDRESS (STD_OFF)
#define T14_UNIFIED_INTERRUPT (STD_ON)

/* 看门狗配置 */
const Wdg_ConfigType Wdg_ConfigPredefined = {
    /* GPT Configuration for WDG */
    .GptConf =
      {
        /* GPT timer module */
        .GptModuleForService = GPT_GPTIMER_CHAN_T14,
        /* Fast mode, timer timeout, in milliseconds */
        .FastServiceGptCbkTime = 50U,
        /*  Slow mode, timer timeout, in milliseconds */
        .SlowServiceGptCbkTime = 100U,
        /* GPT Prescaler */
        .Prescaler = 16000U,
      },
    .WdgClkSource     = WDG_CLK_INTLF,
    .WdgPrescale      = WDG_DIVISION_32,
    .WdgOverflowValue = 150U,
    /* Fast mode, watchdog timeout,2s */
    .FastModeWdgReloadValue = (uint16)2000U,
    /* Slow mode, watchdog timeout,4s */
    .SlowModeWdgReloadValue = (uint16)4000U,
    /* work mode */
    .WorkMode = WDGIF_SLOW_MODE,
};
```

#### 9.1.11 驱动器初始化
代码清单3展示了初始化WDG驱动器所涉及的步骤。注意：用户必须确保在调用Wdg_Init之前调用Mcu_Init
~~~
// 初始化MCU驱动器
Mcu_Init(&Mcu_ConfigRoot[0]);
// 初始化WDG驱动器
Wdg_Init(&Wdg_ConfigRoot[0]);
~~~
### 9.1.2 API用法示例
以下是WDG驱动器提供的API用法示例，包括启动定时器通道、停止定时器通道、启用/禁用定时器通道的通知、获取定时器通道的已流逝时间、获取定时器通道的剩余时间、设置WDG驱动器为睡眠模式、启用/禁用唤醒功能、获取WDG驱动器的版本信息以及取消初始化WDG驱动器。
~~~

设置WDG驱动器为模式
Wgd_SetMode(WDGIF_SLOW_MODE);
设置超时间时间3000毫秒
Wdg_SetTriggerCondition(3000);
获取WDG驱动器的版本信息
Wdg_GetVersionInfo(&VersionInfoPtr);
~~~ 
---

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 表82 假设



### 偏差



### 考虑的Bugzilla




## 10.2 限制

### 10.2.1 中断延迟


