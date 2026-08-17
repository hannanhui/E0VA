# ChipOn Microcontroller Abstract Layer Users Manual - Pwm Driver
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

- [ChipOn Microcontroller Abstract Layer Users Manual - Pwm Driver](#chipon-microcontroller-abstract-layer-users-manual---pwm-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 PWM Driver概述](#第2章-pwm-driver概述)
    - [2.1 系统时钟](#21-系统时钟)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 PwmGeneral](#43-pwmgeneral)
    - [4.3.1 PwmDevErrorDetect](#431-pwmdeverrordetect)
    - [4.3.2 PwmLowPowerStatesSupport](#432-pwmlowpowerstatessupport)
    - [4.3.3 PwmNotificationSupported](#433-pwmnotificationsupported)
    - [4.3.4 PwmIndex](#434-pwmindex)
  - [4.4 PwmChannel](#44-pwmchannel)
    - [4.4.1 PwmChannelClass](#441-pwmchannelclass)
    - [4.4.2 PwmDutycycleDefault](#442-pwmdutycycledefault)
    - [4.4.3 PwmIdleState](#443-pwmidlestate)
    - [4.4.4 PwmNotification](#444-pwmnotification)
    - [4.4.5 PwmPeriodDefault](#445-pwmperioddefault)
    - [4.4.6 PwmPolarity](#446-pwmpolarity)
  - [4.5 PwmConfigurationOfOptApiServices](#45-pwmconfigurationofoptapiservices)
    - [4.5.1 PwmDeInitApi](#451-pwmdeinitapi)
    - [4.5.2 PwmGetOutputState](#452-pwmgetoutputstate)
    - [4.5.3 PwmSetDutyCycle](#453-pwmsetdutycycle)
    - [4.5.4 PwmSetPeriodAndDuty](#454-pwmsetperiodandduty)
    - [4.5.5 PwmVersionInfoApi](#455-pwmversioninfoapi)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Pwm\_ConfigType](#611-类型定义-pwm_configtype)
    - [6.1.2 类型定义 Pwm\_ModuleAndChannelConfigType](#612-类型定义-pwm_moduleandchannelconfigtype)
    - [6.1.3 类型定义 Pwm\_ChannelConfigType](#613-类型定义-pwm_channelconfigtype)
    - [6.1.4 类型定义 Pwm\_GeneralModuleConfigType](#614-类型定义-pwm_generalmoduleconfigtype)
    - [6.1.5 类型定义 Pwm\_AdvanceModuleConfigType](#615-类型定义-pwm_advancemoduleconfigtype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Pwm\_Init](#621-pwm_init)
    - [6.2.2 Pwm\_DeInit](#622-pwm_deinit)
    - [6.2.3 Pwm\_SetDutyCycle](#623-pwm_setdutycycle)
    - [6.2.4 Pwm\_SetPeriodAndDuty](#624-pwm_setperiodandduty)
    - [6.2.5 Pwm\_SetOutputToIdle](#625-pwm_setoutputtoidle)
    - [6.2.6 Pwm\_GetOutputState](#626-pwm_getoutputstate)
    - [6.2.7 Pwm\_DisableNotification](#627-pwm_disablenotification)
    - [6.2.8 Pwm\_EnableNotification](#628-pwm_enablenotification)
    - [6.2.9 Pwm\_GetVersionInfo](#629-pwm_getversioninfo)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Pwm\_GeneralTimerIsr](#631-pwm_generaltimerisr)
    - [6.3.2 Pwm\_AdvanceTimerIsr](#632-pwm_advancetimerisr)
      - [表79 服务请求节点 - PWM硬件资源](#表79-服务请求节点---pwm硬件资源)
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
  - [9.4 设置占空比](#94-设置占空比)
  - [9.5 设置周期和占空比](#95-设置周期和占空比)
  - [9.6 设置通道输出为空闲状态，获取当前输出值](#96-设置通道输出为空闲状态获取当前输出值)
  - [9.7 打开和关闭通知功能](#97-打开和关闭通知功能)
  - [9.8 配置示例](#98-配置示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)
    - [10.2.1](#1021)


---

# 第1章 引言

本用户手册提供了AUTOSAR CP R22-11的Pwm驱动程序的功能、配置参数和API实现的相关信息。Pwm的驱动程序初始化并提供对微控制器的访问。本用户手册旨在帮助用户熟悉Pwm驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用Pwm驱动程序的文档。

## 1.1 范围

本文档介绍Pwm驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- Pwm Driver的文件结构
- Driver的配置参数
- 由Pwm Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于Pwm Driver

## 1.2 缩写

| 缩写 | 解释           |
| :--- | :------------- |
| PWM  | 脉冲宽度调制   |
| DEM  | 诊断通信管理器 |
| DET  | 默认错误跟踪器 |
| Mcu  | 微控制器       |
| PLL  | 锁相环         |
| BSW  | 基础软件       |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of PWMDriver, AUTOSAR_SWS_PWMDriver.pdf Release R22-11
- [2] Requirements of PWMDriver, AUTOSAR_SRS_PWMDriver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 PWM Driver概述
KF32微控制器提供PWM操作方式。配置PWM输出占空比，周期。

### 2.1 系统时钟
系统时钟通过PWM驱动程序设置。配置主频最高120M，参考用户手册。

---

# 第3章 文件结构
本节提供了有关PWM Driver文件和其他相关文件的详细信息。
| Name             | Description                                               |
| :--------------- | :-------------------------------------------------------- |
| Pwm.c            | 此文件包含PWM驱动程序的通用功能                           |
| Pwm.h            | 此头文件输出PWM驱动程序的宏、类型定义和函数原型           |
| Pwm_Cfg.h        | 本文在这里声明了PWM驱动程序的配置数据。                   |
| Pwm_Im_General.c | 此文件包含PWM通用定时器模块所需要的硬件驱动程序           |
| Pwm_Im_General.h | 此头文件输出PWM通用定时器驱动程序的宏、类型定义和函数原型 |
| Pwm_Im_Advance.c | 此文件包含PWM高级定时器模块所需要的硬件驱动程序           |
| Pwm_Im_Advance.h | 此头文件输出PWM高级定时器驱动程序的宏、类型定义和函数原型 |
| Pwm_LCfg.c       | 初始化变量定义                                            |

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
本节描述了相对于支持的微控制器的配置参数的变化。PWM Driver在支持的微控制器上没有变化的参数。

## 4.3 PwmGeneral
本节详细描述了PWM Driver提供的配置，包括AUTOSAR PWM Driver规范[1]中描述的配置以及特定于微控制器的配置。

### 4.3.1 PwmDevErrorDetect
- **名称**: PwmDevErrorDetect
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 打开DET检测，STD_OFF – 不打开DET检测 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.2 PwmLowPowerStatesSupport
- **名称**: PwmLowPowerStatesSupport
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 支持低功耗，STD_OFF – 不支持低功耗 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.3 PwmNotificationSupported
- **名称**: PwmNotificationSupported
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 支持通知功能，STD_OFF – 关闭通知功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.4 PwmIndex
- **名称**: PwmIndex
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：0U
- **配置类别**: 预编译时间 X 所有变体
---

## 4.4 PwmChannel

### 4.4.1 PwmChannelClass
- **名称**: PwmChannelClass
- **来源**: AUTOSAR定义
- **文件**: Pwm.h
- **范围**: 值：PWM_FIXED_PERIOD – 只能改变占空比
              PWM_FIXED_PERIOD_SHIFTED – 只能改变占空比。周期移位(仅在硬件支持的情况下)
              PWM_VARIABLE_PERIOD - 可改变占空比和周期
- **配置类别**: 预编译时间 X 所有变体

### 4.4.2 PwmDutycycleDefault
- **名称**: PwmDutycycleDefault
- **来源**: AUTOSAR定义
- **文件**: Pwm.h
- **范围**: 初始化0使用的占空比值，表示0%;0x8000表示100%
- **配置类别**: 预编译时间 X 所有变体

### 4.4.3 PwmIdleState
- **名称**: PwmIdleState
- **来源**: AUTOSAR定义
- **文件**: Pwm.h
- **范围**: PWM_HIGH – 停止后输出高，PWM_LOW – 停止后输出低
- **配置类别**: 预编译时间 X 所有变体

### 4.4.4 PwmNotification
- **名称**: PwmNotification
- **来源**: AUTOSAR定义
- **文件**: Pwm.h
- **范围**: 通知回调函数
- **配置类别**: 预编译时间 X 所有变体

### 4.4.5 PwmPeriodDefault
- **名称**: PwmPeriodDefault
- **来源**: AUTOSAR定义
- **文件**: Pwm.h
- **范围**: 占空比默认值
- **配置类别**: 预编译时间 X 所有变体

### 4.4.6 PwmPolarity
- **名称**: PwmPolarity
- **来源**: AUTOSAR定义
- **文件**: Pwm.h
- **范围**: PWM_HIGH – 第一个周期输出高，PWM_LOW – 第一个周期输出低
- **配置类别**: 预编译时间 X 所有变体
---

## 4.5 PwmConfigurationOfOptApiServices

### 4.5.1 PwmDeInitApi
- **名称**: PwmDeInitApi
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 打开反初始化函数功能，STD_OFF – 关闭反初始化函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.5.2 PwmGetOutputState
- **名称**: PwmGetOutputState
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 打开获取输出状态函数功能，STD_OFF – 关闭获取输出状态函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.5.3 PwmSetDutyCycle
- **名称**: PwmSetDutyCycle
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 打开设置占空比函数功能，STD_OFF – 关闭设置占空比函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.5.4 PwmSetPeriodAndDuty
- **名称**: PwmSetPeriodAndDuty
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 打开设置周期和占空比函数功能，STD_OFF – 关闭设置周期和占空比函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.5.5 PwmVersionInfoApi
- **名称**: PwmVersionInfoApi
- **来源**: AUTOSAR定义
- **文件**: Pwm_Cfg.h
- **范围**: 值：STD_ON – 打开获取版本号函数功能，STD_OFF – 关闭获取版本号函数功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体
---

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: PWM_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Pwm.h
- **值**: 43
- **描述**: 

## 5.2 ModuleId
- **语法**: PWM_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: Pwm.h
- **值**: 121
- **描述**: 这个宏给出了PWM驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: PWM_INSTANCE_ID
- **类型**: 宏定义 (#define)
- **文件**: Pwm.h
- **值**: 0
- **描述**: 这个宏给出了PWM驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: PWM_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Pwm.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: PWM_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Pwm.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: PWM_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Pwm.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Pwm_ConfigType
- **语法**: Pwm_ConfigType
- **类型**: Struct
- **文件**: Pwm.h
- **范围**: 
  - **Pwm_ChannelType**
    - NumChannels - 时钟起振错误，默认关闭
  - **Pwm_ModuleAndChannelConfigType**
    - ModuleAndChannelPtr - RAM初始化数量                   
- **描述**: 此类型定义用于配置PWM的整体配置。此类型的指针在Pwm_Init API中用于初始化PWM驱动程序。

### 6.1.2 类型定义 Pwm_ModuleAndChannelConfigType
- **语法**: Pwm_ModuleAndChannelConfigType
- **类型**: Struct
- **文件**: Pwm.h
- **范围**: 
  - **uint32**
    - NumChannelAndModule - channel和模块总体信息
  - **Pwm_ChannelConfigType**
    - ChannelConfigPtr - channel配置信息    
  - **Pwm_GeneralModuleConfigType**
    - GeneralConfigPtr - 通用定时器模块配置
  - **Pwm_AdvanceModuleConfigType**
    - AdvanceConfigPtr - 高级定时器模块配置    
  - **Pwm_EnhanceModuleConfigType**
    - EnhanceConfigPtr - EPWM配置，目前不支持         
- **描述**: 此类型定义模块和channel具体配置信息。

### 6.1.3 类型定义 Pwm_ChannelConfigType
- **语法**: Pwm_ChannelConfigType
- **类型**: Struct
- **文件**: Pwm.h
- **范围**: 
  - **uint8**
    - Modulelp - 由模块类型(通用或高级定时器)和模块索引号组成
  - **Pwm_ChannelType**
    - HwChannelId - 使用的模块单元通道序号    
  - **Pwm_ChannelClassType**
    - ChannelClass - 通道可修改类型
  - **Pwm_OutputStateType**
    - ChannelPolarity - 输出极性    
  - **uint32**
    - DefaultDutyCycle - 通道默认占空比        
- **描述**: 此类型定义通道具体配置信息。

### 6.1.4 类型定义 Pwm_GeneralModuleConfigType
- **语法**: Pwm_GeneralModuleConfigType
- **类型**: Struct
- **文件**: Pwm.h
- **范围**: 
  - **Pwm_GeneralModuleType**
    - ModuleId - 通用定时器模块ID
  - **uint16**
    - TimePeriod - 设置周期值    
  - **uint16**
    - TimePrescaler - 分频值    
  - **Pwm_CountModeType**
    - TxUpDownCountMode - 0/1(向下计数或向上计数)边沿对齐；其他值(向上向下计数)中心对齐    
  - **Pwm_WorkingClockType**
    - WorkingClock - 时钟源          
  - **Pwm_NotificationFcnType**
    - PwmChannelNotification - 通知函数，无具体通道通知功能，是模块周期通知           
- **描述**: 此类型定义用于配置通用定时器。

### 6.1.5 类型定义 Pwm_AdvanceModuleConfigType
- **语法**: Pwm_AdvanceModuleConfigType
- **类型**: Struct
- **文件**: Pwm.h
- **范围**: 
  - **Pwm_AdvanceModuleType**
    - ModuleId - 高级定时器模块ID
  - **uint32**
    - TimePeriod - 设置周期值    
  - **uint16**
    - TimePrescaler - 分频值    
  - **uint16**
    - TimePostscaler - Tx 后分频器（分频器 2）分频比选择位      
  - **Pwm_CountModeType**
    - TxUpDownCountMode -  0/1(向下计数或向上计数)边沿对齐；其他值(向上向下计数)中心对齐  
  - **Pwm_WorkingClockType**
    - WorkingClock - 时钟源          
  - **Pwm_NotificationFcnType**
    - PwmChannelNotification -  通知函数，无具体通道通知功能，是模块周期通知          
- **描述**: 此类型定义用于配置高级定时器。
---
## 6.2 API函数

### 6.2.1 Pwm_Init
- **服务名称**: `Pwm_Init`
- **语法**: `void Pwm_Init (const Pwm_ConfigType* ConfigPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: ConfigPtr: 配置参数指针
- **返回值**: 无
- **描述**: PWM初始化
- **注意事项**: 无

### 6.2.2 Pwm_DeInit
- **服务名称**: `Pwm_DeInit`
- **语法**: `void Pwm_DeInit (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: PWM反初始化
- **注意事项**: 无

### 6.2.3 Pwm_SetDutyCycle
- **服务名称**: `Pwm_SetDutyCycle`
- **语法**: `void Pwm_SetDutyCycle (Pwm_ChannelType ChannelNumber,uint16 DutyCycle)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 异步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输入)**: DutyCycle - 占空比，最小值0，最大值0x8000
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置通道占空比
- **注意事项**: 0~0x8000数值表示占空比0~100% 

### 6.2.4 Pwm_SetPeriodAndDuty
- **服务名称**: `Pwm_SetPeriodAndDuty`
- **语法**: `void Pwm_SetPeriodAndDuty (Pwm_ChannelType ChannelNumber,Pwm_PeriodType Period,uint16 DutyCycle)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 异步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输入)**: Period - 周期
- **参数(输入)**: DutyCycle - 占空比，最小值0，最大值0x8000
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置PWM通道的周期和占空比
- **注意事项**: 如果需要设置周期和占空比同时修改，这个通道一定独自占用一个定时器资源；一个模块配置2个通道，使用该函数会改变另外一个通道周期；

### 6.2.5 Pwm_SetOutputToIdle
- **服务名称**: `Pwm_SetOutputToIdle`
- **语法**: `void Pwm_SetOutputToIdle (Pwm_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 异步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 将PWM输出设置为已配置的Idle状态
- **注意事项**: 无

### 6.2.6 Pwm_GetOutputState
- **服务名称**: `Pwm_GetOutputState`
- **语法**: `Pwm_OutputStateType Pwm_GetOutputState (Pwm_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x05
- **同步/异步**: 同步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输出)**: 无
- **返回值**: PWM_HIGH - PWM输出状态高
- **返回值**: PWM_LOW - PWM输出状态低
- **描述**: 读取PWM输出信号的内部状态
- **注意事项**: *当前硬件不支持获取输出状*

### 6.2.7 Pwm_DisableNotification
- **服务名称**: `Pwm_DisableNotification`
- **语法**: `void Pwm_DisableNotification (Pwm_ChannelType ChannelNumber)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x06
- **同步/异步**: 异步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 关闭PWM信号边缘通知的服务
- **注意事项**: 无

### 6.2.8 Pwm_EnableNotification
- **服务名称**: `Pwm_EnableNotification`
- **语法**: `void Pwm_EnableNotification (Pwm_ChannelType ChannelNumber,Pwm_EdgeNotificationType Notification)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x07
- **同步/异步**: 异步
- **可重入**: 不同的通道可重入
- **参数(输入)**: ChannelNumber - 通道索引号
- **参数(输入)**: Notification - 通知类型PWM_RISING_EDGE或PWM_FALLING_EDGE或PWM_BOTH_EDGES
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据通知参数使能PWM信号边缘通知。
- **注意事项**: 不支持边沿类型设置，只支持周期中断通知

### 6.2.9 Pwm_GetVersionInfo
- **服务名称**: `Pwm_GetVersionInfo`
- **语法**: `void Pwm_GetVersionInfo (Std_VersionInfoType* versioninfo)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x08
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:无
- **参数(输出)**: versioninfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无

-----
## 6.3 中断处理

### 6.3.1 Pwm_GeneralTimerIsr
- **服务名称**: Pwm_GeneralTimerIsr
- **语法**：`FUNC(void, PWM_CODE) Pwm_GeneralTimerIsr(uint8 Module)`
- **服务ID**：
- **同步/异步**：同步
- **可重入性**：不可重入
- **参数（输入）**：Module - PWM硬件单元
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 通知功能
- **警告**：无
- **配置**：如果需要从中断例程调用通知，则应将PWM_NOTIFICATION_SUPPORTED设置为STD_ON。
- **DET**：无
- **DEM**：无
- **实施注释**：无

### 6.3.2 Pwm_AdvanceTimerIsr
- **服务名称**: Pwm_AdvanceTimerIsr
- **语法**：`FUNC(void, PWM_CODE) Pwm_AdvanceTimerIsr(uint8 Module)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：不可重入
- **参数（输入）**：Module - PWM硬件单元
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 通知功能
- **警告**：无
- **配置**：如果需要从中断例程调用通知，则应将PWM_NOTIFICATION_SUPPORTED设置为STD_ON。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有13个SRN（服务请求节点）用于服务PWM通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - PWM硬件资源

| 硬件资源      | SRN编号               |
| ------------- | --------------------- |
| PWM_MODULE_0  | T0_UNIFIED_INTERRUPT  |
| PWM_MODULE_1  | T1_UNIFIED_INTERRUPT  |
| PWM_MODULE_2  | T2_UNIFIED_INTERRUPT  |
| PWM_MODULE_3  | T3_UNIFIED_INTERRUPT  |
| PWM_MODULE_4  | T4_UNIFIED_INTERRUPT  |
| PWM_MODULE_18 | T18_UNIFIED_INTERRUPT |
| PWM_MODULE_19 | T19_UNIFIED_INTERRUPT |
| PWM_MODULE_21 | T21_UNIFIED_INTERRUPT |
| PWM_MODULE_22 | T22_UNIFIED_INTERRUPT |
| PWM_MODULE_23 | T23_UNIFIED_INTERRUPT |
| PWM_MODULE_5  | T5_UNIFIED_INTERRUPT  |
| PWM_MODULE_9  | T9_UNIFIED_INTERRUPT  |
| PWM_MODULE_25 | T25_UNIFIED_INTERRUPT |

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

PWM Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是PWM Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                 | 类型/范围                   | 描述             |
| -------------------- | --------------------------- | ---------------- |
| Pwm_pConfig          | Pwm_ConfigType              | 保存配置参数指针 |
| Pwm_eGlobalState     | Pwm_GlobalStateType         | PWM初始化状态    |
| Pwm_GeneralModulePtr | GeneralTimer_RegisterMap_t  | 通用定时器指针   |
| Pwm_AdvanceModulePtr | AdvancedTimer_RegisterMap_t | 高级定时器指针   |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是PWM Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                          | 错误描述                                                               | 值（十六进制） |
| --------------------------------- | ---------------------------------------------------------------------- | -------------- |
| PWM_E_INIT_FAILED                 | 初始化失败                                                             | 0x10           |
| PWM_E_UNINIT                      | PWM未初始化                                                            | 0x11           |
| PWM_E_PARAM_CHANNEL               | 入参大于配置最大可使用通道                                             | 0x12           |
| PWM_E_PERIOD_UNCHANGEABLE         | 通道配置与实际使用不符(配置为只能修改占空比，调用函数修改周期)         | 0x13           |
| PWM_E_ALREADY_INITIALIZED         | 重复初始化                                                             | 0x14           |
| PWM_E_PARAM_POINTER               | 参数空指针                                                             | 0x15           |
| PWM_E_NOT_DISENGAGED              | 配置当PWM模块仍在使用时调用Pwm_SetPowerState时生成参数内硬件参数空指针 | 0x16           |
| PWM_E_POWER_STATE_NOT_SUPPORTED   | PWM模块不支持请求的电源状态                                            | 0x17           |
| PWM_E_TRANSITION_NOT_POSSIBLE     | 请求的电源状态无法从当前状态到达                                       | 0x18           |
| PWM_E_PERIPHERAL_NOT_PREPARED     | 在调用Pwm_SetPowerState时生成，而之前没有调用API Pwm_PreparePowerState | 0x19           |
| PWM_E_PARAM_NOTIFICATION          | 为边缘通知选择的极性无效                                               | 0x30           |
| PWM_E_PARAM_NOTIFICATION_NULL     | NULL函数配置为通知回调                                                 | 0x31           |
| PWM_E_DUTYCYCLE_RANGE             | 调用Pwm_SetDutyCycle或Pwm_SetPeriodAndDuty时占空比范围无效             | 0x32           |
| PWM_E_SETOUTPUTTOIDLE_NOT_SUPPORT | 模块不支持设置输出为空闲时产生                                         | 0x3E           |

-----
# 第9章 示例用法
本章描述了如何配置PWM驱动器以及如何在应用程序中使用PWM驱动器提供的不同的API。

## 9.1 系统时钟配置注意事项

- 配置注意事项
 - 可修改周期和占空比的通道独占一个定时器资源
 - 通道类型ChannelClass配置要和预期使用要匹配
 - 常规通道，设置的周期值TimePeriod不能大于0xFFFF

- 周期说明
 - 边沿对齐周期计算公式：PWM 周期=(PPX+1)×Tsysclk×Tx预分频比
 - 中心对齐周期计算公式：PWM 周期=PPX×Tsysclk×Tx预分频比×2
 - Tsysclk为工作时钟频率的倒数

## 9.2 宏配置

```c
#define PWM_DEV_ERROR_DETECT (STD_OFF)
#define PWM_GENERAL_CHANNEL (0U)
#define PWM_ADVANCE_CHANNEL (1U)
#define PWM_ENHANCE_CHANNEL (2U)
#define PWM_MAX_ADVANCE_TIMER_NUM (3U)
#define PWM_MAX_GENERAL_TIMER_NUM (10U)
#define PWM_CONFIG_CHANNEL_1 ((uint8)0x00)
#define PWM_CONFIG_CHANNEL_2 ((uint8)0x01)
#define PWM_CONFIG_CHANNEL_3 ((uint8)0x02)
#define PWM_CONFIG_CHANNEL_4 ((uint8)0x03)
#define PWM_GENERAL_USED (STD_ON)
#define PWM_ADVANCE_USED (STD_ON)
#define PWM_ENHANCE_USED (STD_OFF)

#define PWM_DE_INIT_API (STD_ON)
#define PWM_SET_DUTY_CYCLE_API (STD_ON)
#define PWM_SET_PERIOD_AND_DUTY_API (STD_OFF)
#define PWM_SET_OUTPUT_TO_IDLE_API (STD_ON)
#define PWM_GET_OUTPUT_STATE_API (STD_ON)
#define PWM_NOTIFICATION_SUPPORTED (STD_ON)
#define PWM_VERSION_INFO_API (STD_ON)
#define PWM_PRECOMPILE_SUPPORT (STD_OFF)
#define PWM_SETOUTPUTTOIDLE_PLAUSABILITY (STD_OFF)
#define PWM_POWER_STATE_SUPPORTED (STD_OFF)
```
## 9.3 初始化

- 关闭固定配置情
```c
#define PWM_PRECOMPILE_SUPPORT (STD_OFF)

Pwm_Init(&Pwm_ConfigPredefined);

```
- 打开固定配置
```c
#define PWM_PRECOMPILE_SUPPORT (STD_ON)

Pwm_Init(NULL_PTR);
```

## 9.4 设置占空比

设置范围值是0~0x8000(对应占空比是0~100%)；示例设置占空比50%

```c
Pwm_SetDutyCycle(0U,0x4000);
```

## 9.5 设置周期和占空比

 - 设置范围值是0~0x8000(对应占空比是0~100%)；示例设置占空比50%
 - 通用定时器最大值不能超过0xFFFF
 - 该通道独占一个定时器资源

```c
Pwm_SetPeriodAndDuty(0U,3000,0x4000);
```

## 9.6 设置通道输出为空闲状态，获取当前输出值

 - 空闲状态是高还是低，需要根据配置设定

```c
Pwm_OutputStateType status;

Pwm_SetOutputToIdle(0U);

status = Pwm_GetOutputState(0U);
```

## 9.7 打开和关闭通知功能

 - 目前紧支持周期通知，不支持其他方式通知

```c

Pwm_DisableNotification(0U);

Pwm_EnableNotification(1U, PWM_BOTH_EDGES);
```
## 9.8 配置示例

- 一共配置了4个通道
- 使用通用定时器T0
 - 使用了T0通道1和通道2，时钟源系统时钟，边沿对齐，分频12000，周期值2000(即周期为200ms)
 - 通道1默认占空比50%,第一个周期输出高，仅支持修改占空比
 - 通道2默认掌控比25%,第一个周期输出高，仅支持修改占空比
- 使用高级定时器T5
 - 使用了T5通道1和通道4，时钟源系统时钟，边沿对齐，分频12000，周期值2000(即周期为200ms)
 - 通道1默认占空比50%,第一个周期输出高，仅支持修改占空比
 - 通道4默认掌控比25%,第一个周期输出高，仅支持修改占空比

```c
#if (PWM_ENHANCE_USED == STD_ON)
/**
 * @brief Number of configured enhance module
 */
#define PWM_ENHANCE_MOD_NUMBER ((uint8)0U)
#else
/** @brief config zero  */
#define PWM_ENHANCE_MOD_NUMBER ((uint8)0U)
#endif

#if (PWM_ADVANCE_USED == STD_ON)
/**
 * @brief Number of configured advance module
 */
#define PWM_ADVANCE_MOD_NUMBER ((uint8)1U)
#else
/** @brief config zero  */
#define PWM_ADVANCE_MOD_NUMBER ((uint8)0U)
#endif

#if (PWM_GENERAL_USED == STD_ON)
/**
 * @brief Number of configured general module
 */
#define PWM_GENERAL_MOD_NUMBER ((uint8)1U)
#else
/** @brief config zero  */
#define PWM_GENERAL_MOD_NUMBER ((uint8)0U)
#endif

/**
 * @brief Number of configured Pwm channels
 */
#define PWM_CONF_CHANNELS_NUMBER (4U)

/**
 * @brief module number and channel number config
 */
#define PWM_CONF_CHANNEL_AND_MODULE                                                                                    \
    ((PWM_CONF_CHANNELS_NUMBER << 12U) | (PWM_GENERAL_MOD_NUMBER) << 8U | (PWM_ADVANCE_MOD_NUMBER << 4U) |             \
     PWM_ENHANCE_MOD_NUMBER)

/**
 * @brief channel type and module index config
 */
#define PWM_CHANNEL_TYPE_AND_MODULE_INDEX(ChannelType, ModuleIndex) ((ChannelType << 4U) | ModuleIndex)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
static FUNC(void, PWM_CODE) Pwm_Notification_T0(void);
static FUNC(void, PWM_CODE) Pwm_Notification_T5(void);
/******************************************************************************
 **                        Variables
 ******************************************************************************/
#if (PWM_ADVANCE_USED == STD_ON)
/**
 * @brief Configurations for all Advance module
 *
 */
static CONST(Pwm_AdvanceModuleConfigType, PWM_CONST) Pwm_AdvanceModuleConfig[PWM_ADVANCE_MOD_NUMBER] = {
  {.ModuleId          = PWM_MODULE_5,
   .TimePeriod        = 2000U,
   .TimePrescaler     = 12000U,
   .TimePostscaler    = 0U,
   .TxUpDownCountMode = PWM_UP_FLAG,
   .WorkingClock      = PWM_SCLK
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
   ,
   .PwmChannelNotification = Pwm_Notification_T5
#endif
  }};
#endif

#if (PWM_GENERAL_USED == STD_ON)
/**
 * @brief Configurations for all general module
 *
 */
static CONST(Pwm_GeneralModuleConfigType, PWM_CONST) Pwm_GeneralModuleConfig[PWM_GENERAL_MOD_NUMBER] = {
  {.ModuleId          = PWM_MODULE_0,
   .TimePeriod        = 2000U,
   .TimePrescaler     = 12000U,
   .TxUpDownCountMode = PWM_UP_FLAG,
   .WorkingClock      = PWM_SCLK
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
   ,
   .PwmChannelNotification = Pwm_Notification_T0
#endif
  }};
#endif

/**
 * @brief Pwm channels configuration array
 */
/*PRQA S 3432  ++*/
static CONST(Pwm_ChannelConfigType, PWM_CONST) Pwm_ChannelConfig[PWM_CONF_CHANNELS_NUMBER] = {
  [0U] = {.Modulelp         = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 0U),
          .HwChannelId      = PWM_CONFIG_CHANNEL_1,
          .ChannelClass     = PWM_VARIABLE_PERIOD,
          .ChannelPolarity  = PWM_HIGH,
          .DefaultDutyCycle = 0x4000},
  [1U] = {.Modulelp         = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 0U),
          .HwChannelId      = PWM_CONFIG_CHANNEL_2,
          .ChannelClass     = PWM_VARIABLE_PERIOD,
          .ChannelPolarity  = PWM_HIGH,
          .DefaultDutyCycle = 0x2000},
  [2U] = {.Modulelp         = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_ADVANCE_CHANNEL, 0U),
          .HwChannelId      = PWM_CONFIG_CHANNEL_1,
          .ChannelClass     = PWM_VARIABLE_PERIOD,
          .ChannelPolarity  = PWM_HIGH,
          .DefaultDutyCycle = 0x4000},
  [3U] = {.Modulelp         = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_ADVANCE_CHANNEL, 0U),
          .HwChannelId      = PWM_CONFIG_CHANNEL_4,
          .ChannelClass     = PWM_VARIABLE_PERIOD,
          .ChannelPolarity  = PWM_HIGH,
          .DefaultDutyCycle = 0x2000}};

/**
 * @brief pwm module and channel config
 */
/*PRQA S 3408,0499,3397 ++*/
const Pwm_ModuleAndChannelConfigType Pwm_ModuleAndChannelConfigSet = {
  .NumChannelAndModule = PWM_CONF_CHANNEL_AND_MODULE,
  .ChannelConfigPtr    = &Pwm_ChannelConfig[0]
#if (PWM_GENERAL_USED == STD_ON)
  ,
  .GeneralConfigPtr = &Pwm_GeneralModuleConfig[0]
#endif
#if (PWM_ADVANCE_USED == STD_ON)
  ,
  .AdvanceConfigPtr = &Pwm_AdvanceModuleConfig[0]
#endif
#if (PWM_ENHANCE_USED == STD_ON)
  ,
#endif
};

/**
 * @brief pwm config information
 */
const Pwm_ConfigType Pwm_ConfigPredefined = {
  /** @brief Number of PWM configured channels */
  .NumChannels = PWM_CONF_CHANNELS_NUMBER,
  /** @brief Combined IP specific configuration structure */
  .ModuleAndChannelPtr = &Pwm_ModuleAndChannelConfigSet};
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

static FUNC(void, PWM_CODE) Pwm_Notification_T0(void)
{
    ;
}

static FUNC(void, PWM_CODE) Pwm_Notification_T5(void)
{
    ;
}
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

- 不支持一个单元内通道不同的周期。
- 不支持边沿触发回调函数，只支持周期触发。


## 10.2 限制

### 10.2.1




