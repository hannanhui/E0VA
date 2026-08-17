# ChipOn Microcontroller Abstract Layer Users Manual - LIN Driver
Release V0.1 - May 2024  
Published by ChipOn 



---

## 变更记录
| 日期       | 版本 | 变更记录 |
| ---------- | ---- | :------- |
| 2024.05.14 | 0.1  | 初版创建 |
---



## 目录

- [ChipOn Microcontroller Abstract Layer Users Manual - LIN Driver](#chipon-microcontroller-abstract-layer-users-manual---lin-driver)
  - [变更记录](#变更记录)
  - [| 2024.05.14 | 0.1  | 初版创建 |](#-20240514--01---初版创建-)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
- [1.3 参考资料](#13-参考资料)
- [第2章 Lin Driver概述](#第2章-lin-driver概述)
  - [2.1 LIN](#21-lin)
  - [2.2 IRQ](#22-irq)
  - [2.3 系统时钟](#23-系统时钟)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 Lin\_Cfg.h文件配置说明](#43-lin_cfgh文件配置说明)
  - [4.4 Lin\_LCfg.c文件配置说明](#44-lin_lcfgc文件配置说明)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Lin\_ConfigType](#611-类型定义-lin_configtype)
    - [6.1.2 类型定义 Lin\_PduType](#612-类型定义-lin_pdutype)
    - [6.1.3 类型定义 Lin\_FrameCsModelType](#613-类型定义-lin_framecsmodeltype)
    - [6.1.4 类型定义 Lin\_FrameResponseType](#614-类型定义-lin_frameresponsetype)
    - [6.1.5 类型定义 Lin\_StatusType](#615-类型定义-lin_statustype)
    - [6.1.6 类型定义 Lin\_FrameDlType](#616-类型定义-lin_framedltype)
    - [6.1.7 类型定义 Lin\_FramePidType](#617-类型定义-lin_framepidtype)
    - [6.1.8 类型定义 Lin\_UsartModuleType](#618-类型定义-lin_usartmoduletype)
    - [6.1.6 类型定义 LinTrcv\_TrcvWakeupModeType](#616-类型定义-lintrcv_trcvwakeupmodetype)
    - [6.1.7 类型定义 LinTrcv\_TrcvWakeupReasonType](#617-类型定义-lintrcv_trcvwakeupreasontype)
    - [6.1.8 类型定义 Lin\_ChannelCfgType](#618-类型定义-lin_channelcfgtype)
  - [6.2 API接口](#62-api接口)
    - [6.2.1 Lin\_GetVersionInfo](#621-lin_getversioninfo)
    - [6.2.2 Lin\_Init](#622-lin_init)
    - [6.2.3 Lin\_GetStatus](#623-lin_getstatus)
    - [6.2.4 Lin\_GoToSleep](#624-lin_gotosleep)
    - [6.2.5 Lin\_GoToSleepInternal](#625-lin_gotosleepinternal)
    - [6.2.6 Lin\_SendFrame](#626-lin_sendframe)
    - [6.2.7 Lin\_Wakeup](#627-lin_wakeup)
    - [6.2.8 Lin\_WakeupInternal](#628-lin_wakeupinternal)
    - [6.2.9 Lin\_CheckWakeup](#629-lin_checkwakeup)
    - [6.2.10 Lin\_Slave\_Data\_Init](#6210-lin_slave_data_init)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Lin\_UsartInterruptHandler](#631-lin_usartinterrupthandler)
    - [6.3.2 Lin\_Slave\_UsartInterruptHandler](#632-lin_slave_usartinterrupthandler)
      - [服务请求节点 - Lin硬件资源](#服务请求节点---lin硬件资源)
  - [6.4 专有区域（EA）信息](#64-专有区域ea信息)
    - [6.4.1 专有区域信息](#641-专有区域信息)
- [第7章 数据描述](#第7章-数据描述)
  - [7.1 全局数据描述](#71-全局数据描述)
      - [全局数据描述](#全局数据描述)
- [第8章 错误分类](#第8章-错误分类)
  - [8.1 错误代码和描述](#81-错误代码和描述)
      - [错误分类](#错误分类)
- [第9章 示例用法](#第9章-示例用法)
  - [9.1 集成说明](#91-集成说明)
  - [9.2 驱动配置](#92-驱动配置)
  - [9.3 驱动初始化](#93-驱动初始化)
  - [9.4 API使用](#94-api使用)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [假设](#假设)
  - [10.2 限制](#102-限制)



---

# 第1章 引言

本用户手册提供了有关Lin驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的Lin驱动程序实现。该文档描述了如何使用Lin驱动程序
 

## 1.1 范围
本文档涉及Lin Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- Lin Driver的文件结构
- Driver的配置参数
- 由Lin Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于Lin Driver

## 1.2 缩写

- MCAL : Microcontroller Abstract Layer，微控制器抽象层  
- ISR  : Interrupt Service Routine，中断服务程序        
- LIN  : Local Interconnect Network，本地互联网络        

# 1.3 参考资料
- KF32A158xxxSF用户手册V1.0
- KF32A158xxxSF数据手册V1.3
- LIN_Design_Report.md
- AUTOSAR_SWS_LINDriver.pdf
---


# 第2章 Lin Driver概述

Lin Driver使用KungFu平台的通用同步/异步收发器外设(USART)。Driver可以配置多个Lin通道。它同时支持主模式。在收发LIN帧时，帧数据长度最大可以达到8字节，发送速率可以达到 4Mb/s。每个通道都可以进行以下操作：

- 发送Header、Response。
- 睡眠唤醒控制
- 错误检测
- 可配置通讯波特率

## 2.1 LIN
使用芯片的USART外设来实现Lin Driver

## 2.2 IRQ 
IRQ Driver负责初始化Lin Driver所需的中断优先级。

## 2.3 系统时钟
系统时钟通过MCU Driver设置。必须设置适当的系统时钟。

---

# 第3章 文件结构
本节提供了有关Lin Driver文件和其他相关文件的详细信息。

| 文件名     | 说明                          | 是否需要配置   |
| ---------- | ----------------------------- | -------------- |
| Lin.h      | Lin模块外部接口文件           | 无需配置       |
| Lin.c      | Lin模块接口实现文件           | 无需配置       |
| Linfd_Im.h | Lin模块芯片适配层接口文件     | 无需配置       |
| Linfd_Im.c | Lin模块芯片适配层接口实现文件 | 无需配置       |
| Lin_Cfg.h  | Lin模块功能配置文件           | ***需要配置*** |
| Irq_LCfg.h | Lin模块参数宏封装文件         | 无需配置       |
| Irq_LCfg.c | Lin模块配置变量存储文件       | ***需要配置*** |


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
本节描述了相对于支持的微控制器的配置参数的变化。Lin Driver在支持的微控制器上没有变化的参数。

## 4.3 Lin_Cfg.h文件配置说明

+ LIN_DEV_ERROR_DETECT(需要配置)
> 配置是否检测错误，当使能后，运行过程中检测到的错误将从Det_ReportError接口上报。
>```
>STD_ON  开启错误检测
>STD_OFF 关闭错误检测
>```

+ LIN_PRECOMPILE_SUPPORT(需要配置)
>配置是否使用预编译的配置

>STD_ON:默认使用Lin_Config的配置初始化LIN驱动
>``` 
>#define LIN_PRECOMPILE_SUPPORT (STD_ON)
>
>影响Lin_Init函数的调用，如：
>Lin_Init(NULL_PTR);
>此时Lin_Init传入的其他参数将不会起作用，默认将Lin_Config作为参数进行初始化
>```

>STD_OFF:不使用默认的参数配置初始化LIN驱动，配置参数需要自行传入
>``` 
>#define LIN_PRECOMPILE_SUPPORT (STD_OFF)
>
>影响Lin_Init函数的调用，如：
>Lin_Init(&UserLinCfg);
>此时Lin_Init需要传入一个Lin_ConfigType类型的配置参数UserLinCfg
>```


+ LIN_START_UP_SLEEP_STATE(需要配置)
> 配置在执行Lin_Init后，Lin是否处于睡眠模式
>```
>STD_ON  执行Lin_Init后，Lin通道处于睡眠模式
>STD_OFF 执行Lin_Init后，Lin通道处于正常通信模式
>```

+ LIN_SLAVE_MODE(需要配置)
> 配置Lin驱动是否使用从节点
>```
>STD_ON  使用
>STD_OFF 不使用
>```

+ LIN_SLAVE_OBJECT_NUM(需要配置)
> 配置Lin总线中从节点的数量
>```
>#define LIN_SLAVE_OBJECT_NUM  (3U)
>```
 
+ LIN_DISABLE_DEM_REPORT_ERROR_STATUS(需要配置)
> 配置Lin模块是否关闭Dem报文错误状态的功能
>```
> STD_OFF 使用Dem报告错误状态
> STD_ON  不使用Dem报告错误状态
>```

+ LIN_IM_MODULES(需要配置)
> 配置Lin驱动定义的通道总数
>```
>#define LIN_IM_MODULES  (3U)
>```

+ LIN_MAX_DATA_LENGTH(需要配置)
> 配置Lin驱动所有通道数据帧的最大长度（单位：字节）
>```
>#define LIN_MAX_DATA_LENGTH (8U)
>```

+ LIN_TIMEOUT_LOOPS(需要配置)
> 配置Lin Driver中的超时等待Tick计数值，如下：
>```
>#define LIN_TIMEOUT_LOOPS 1000U
>```

## 4.4 Lin_LCfg.c文件配置说明

+ LIN_NONE_ECUM_WAKEUP_SOURCE_REF(无需配置)
> 配置一个None Wakeup的源标志
>```
>#define LIN_NONE_ECUM_WAKEUP_SOURCE_REF (uint32)0U
>```
 
+ 所有Lin通道配置数组(需要配置)
> 这里定义了每个通道初始化时使用的配置参数，例如使用的USART外设、时钟、波特率参数。
>```
>Lin_ChannelCfgType ChannelCfg[LIN_IM_MODULES];
>   举例：
>      {
>         .LinHwModule                = LIN_MODULE_USART1,
>         .LinClockSelect             = 1U,
>         .LinChannelWakeupSupport    = (uint8)STD_OFF,
>         .LinChannelEcuMWakeupSource = (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF,
>         .BaudInteger                = 0x68U,
>         .BaudNumerator               = 0U,
>         .BaudDenom                  = 1U
>      }
>      
>```
> | 配置名称                       | 说明                                                                  |
> |----------------------------|---------------------------------------------------------------------|
> | LinHwModule                | 配置该通道使用的USARTx外设来实现LIN协议，可选类型Lin_UsartModuleType中的值                 |
> | LinClockSelect             | 配置该通道波特率发生器的时钟源寄存器BRCKS，可选0-SCK，1-HFCLK                             |
> | LinChannelWakeupSupport    | 配置该通道是否支持唤醒，可选STD_ON，STD_OFF                                        |
> | LinChannelEcuMWakeupSource | 配置该通道支持唤醒时的唤醒源，此唤醒源由EcuM定义，若不支持唤醒则选择LIN_NONE_ECUM_WAKEUP_SOURCE_REF |
> | BaudInteger                | 配置该通道波特率发生器的时钟分频系数寄存器BRGM值，即USARTDIV的整数部分                           |
> | BaudNumerator               | 配置该通道波特率发生器的时钟分频小数波特率分子寄存器BRGF1的值                                   |
> | BaudDenom                  | 配置该通道波特率发生器的时钟分频小数波特率分母寄存器BRGF2的值                                   |

+ Lin Driver的配置参数(无需配置)
> 这里定义整个Lin驱动的配置参数
>```
>const Lin_ConfigType Lin_ConfigPredefined;
>   举例：
>       {
>         /*all lin module number*/
>         .Lin_Channel_Num = LIN_IM_MODULES,
>         /*Configuration for Lin Channel*/
>         .Lin_ChannelPtr = &ChannelCfg[0]}
>       }, 
>```
> | 配置名称              | 说明            |
> |-------------------|---------------|
> | Lin_Channel_Num   | 存储Lin驱动的总通道数量 |
> | Lin_ChannelPtr    | 存储各通道的配置数组指针  |
 
---

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: LIN_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Lin.h
- **值**: 88
- **描述**: 这个宏给出了LIN驱动厂商ID，如AUTOSAR所述

## 5.2 ModuleId
- **语法**: LIN_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Lin.h
- **值**: 82
- **描述**: 这个宏给出了LIN驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: LIN_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Lin.h
- **值**: 0
- **描述**: 这个宏给出了LIN驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: LIN_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Lin.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: LIN_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Lin.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: LIN_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Lin.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---

# 第6章 API文档
## 6.1 API类型定义

### 6.1.1 类型定义 Lin_ConfigType
- **语法**: Lin_ConfigType
- **类型**: Struct
- **文件**: Lin.h
- **范围**:
  - Lin_Channel_Num (uint8)
    - 存储Lin驱动的总通道数量
  - Lin_ChannelPtr (Lin_ChannelCfgType*)
    - 存储各通道的配置数组指针
- **描述**: 此类型定义用于配置Lin Driver的整体配置。此类型的指针在Lin_Init API中用于初始化Lin驱动程序。

### 6.1.2 类型定义 Lin_PduType
- **语法**: Lin_PduType
- **类型**: Struct
- **文件**: Lin_GeneralTypes.h
- **范围**:
  - Pid (Lin_FramePidType)
    - Lin帧的ID
  - Cs (Lin_FrameCsModelType)
    - Lin帧的校验类型
  - Drc (Lin_FrameResponseType)
    - Lin帧的数据回复类型
  - Dl（Lin_FrameDlType）
    - Lin帧的数据长度
  - SduPtr（uint8*）
    - 报文的数据指针
- **描述**: 此类型定义用于定义一个Lin帧。此类型在Lin帧传输Api中使用。

### 6.1.3 类型定义 Lin_FrameCsModelType
- **语法**: Lin_FrameCsModelType
- **类型**: enum
- **文件**: Lin_GeneralTypes.h
  - LIN_ENHANCED_CS
    - 增强型Checksum类型
  - LIN_CLASSIC_CS
    - 传统型Checksum类型
- **描述**: 定义Lin帧的Checksum类型。


### 6.1.4 类型定义 Lin_FrameResponseType
- **语法**: Lin_FrameResponseType
- **类型**: enum
- **文件**: Lin_GeneralTypes.h
  - LIN_MASTER_RESPONSE
    - 数据域由Master发送
  - LIN_SLAVE_RESPONSE
    - 数据域由Slave发送给Master
  - LIN_SLAVE_TO_SLAVE
    - 数据域由Slave发送给Slave
- **描述**: 定义Lin帧的Response类型。

### 6.1.5 类型定义 Lin_StatusType
- **语法**: Lin_StatusType
- **类型**: enum
- **文件**: Lin_GeneralTypes.h
  - LIN_NOT_OK
    - 操作存在错误
  - LIN_TX_OK
    - 操作成功
  - LIN_TX_BUSY
    - 发送忙
  - LIN_TX_HEADER_ERROR
    - 报文头错误
  - LIN_TX_ERROR
    - 发送错误
  - LIN_RX_OK
    - 接收成功
  - LIN_RX_BUSY
    - 接收忙
  - LIN_RX_ERROR
    - 接收错误
  - LIN_RX_NO_RESPONSE
    - 发出报文头后未收到回复数据
  - LIN_OPERATIONAL
    - Normal状态
  - LIN_CH_SLEEP
    - Sleep状态
- **描述**: 定义Lin驱动中使用的状态标志类型。

### 6.1.6 类型定义 Lin_FrameDlType
- **语法**: Lin_FrameDlType
- **类型**: uint8
- **文件**: Lin_GeneralTypes.h
- **范围**: 0..8
- **描述**: Lin帧的数据长度类型。

### 6.1.7 类型定义 Lin_FramePidType
- **语法**: Lin_FramePidType
- **类型**: uint8
- **文件**: Lin_GeneralTypes.h
- **范围**: 0..0xFF
- **描述**: Lin帧的PID类型。

### 6.1.8 类型定义 Lin_UsartModuleType
- **语法**: Lin_UsartModuleType
- **类型**: enum
- **文件**: Lin.h
- **范围**:
  - USART0
    - USART模块0
  - USART1
    - USART模块1
  - USART2
    - USART模块2
  - USART3
    - USART模块3
  - USART6
    - USART模块6
- **描述**: 此类型定义了Lin驱动使用的USART外设。

### 6.1.6 类型定义 LinTrcv_TrcvWakeupModeType
- **语法**: LinTrcv_TrcvWakeupModeType
- **类型**: enum
- **文件**: Lin_GeneralTypes.h
- **范围**:
  - LINTRCV_WUMODE_ENABLE
    - 唤醒模式使能
  - LINTRCV_WUMODE_DISABLE
    - 唤醒模式禁用
  - LINTRCV_WUMODE_CLEAR
    - 唤醒模式清除
- **描述**: 此类型定义了Lin收发器唤醒模式类型。

### 6.1.7 类型定义 LinTrcv_TrcvWakeupReasonType
- **语法**: LinTrcv_TrcvWakeupReasonType
- **类型**: enum
- **文件**: Lin_GeneralTypes.h
- **范围**:
  - LINTRCV_WU_ERROR
    - Lin控制器处于主动错误状态
  - LINTRCV_WU_BY_BUS
    - Lin控制器处于被动错误状态
  - LINTRCV_WU_BY_PIN
    - Lin控制器处于总线关闭状态
  - LINTRCV_WU_INTERNALLY
    - Lin控制器处于总线关闭状态
  - LINTRCV_WU_NOT_SUPPORTED
    - Lin控制器处于总线关闭状态
  - LINTRCV_WU_POWER_ON
    - Lin控制器处于总线关闭状态
  - LINTRCV_WU_RESET
    - Lin控制器处于总线关闭状态
  - LINTRCV_WU_BY_SYSERR
    - Lin控制器处于总线关闭状态
- **描述**: 此类型定义了Lin 收发器检测到唤醒的原因。

### 6.1.8 类型定义 Lin_ChannelCfgType
- **语法**: Lin_ChannelCfgType
- **类型**: Struct
- **文件**: Lin_GeneralTypes.h
- **范围**:
  - LinHwModule (Lin_UsartModuleType)
    - 配置该通道使用的USARTx外设来实现LIN协议，可选Lin_UsartModuleType中的类型
  - LinClockSelect (uint8)
    - 配置该通道波特率发生器的时钟源寄存器BRCKS，可选0-SCK，1-HFCLK
  - LinChannelWakeupSupport (uint8)
    - 配置该通道是否支持唤醒，可选STD_ON，STD_OFF
  - LinChannelEcuMWakeupSource（EcuM_WakeupSourceType）
    - 配置该通道支持唤醒时的唤醒源，此唤醒源由EcuM定义，若不支持唤醒则选择LIN_NONE_ECUM_WAKEUP_SOURCE_REF
  - BaudInteger（uint16）
    - 配置该通道波特率发生器的时钟分频系数寄存器BRGM值，即USARTDIV的整数部分
  - BaudNumerator（uint8）
    - 配置该通道波特率发生器的时钟分频小数波特率分子寄存器BRGF1的值
  - BaudDenom（uint8）
    - 配置该通道波特率发生器的时钟分频小数波特率分母寄存器BRGF2的值
- **描述**: 此类型定义了通道初始化时使用的配置参数，例如使用的USART外设、时钟、波特率参数。
 
## 6.2 API接口
> 以下接口为AutoSAR标准接口，请查阅《AUTOSAR_SWS_LINDriver.pdf》查看功能说明。

### 6.2.1 Lin_GetVersionInfo
- **服务名称**: Lin_GetVersionInfo
- **语法**: void Lin_GetVersionInfo ( Std_VersionInfoType *VersionInfoPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: VersionInfoPtr: 存储驱动版本信息的指针。
- **返回值**: 无
- **描述**: 获取驱动的版本信息的服务。

### 6.2.2 Lin_Init
- **服务名称**: Lin_Init
- **语法**: void Lin_Init (const Lin_ConfigType *ConfigPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: ConfigPtr 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化Lin驱动程序的服务。

### 6.2.3 Lin_GetStatus
- **服务名称**: Lin_GetStatus
- **语法**: Lin_StatusType Lin_GetStatus(uint8 Channel, uint8 **Lin_SduPtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x08
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Channel，要获取状态的通道。Lin_SduPtr，如果来自从节点的回复成功接收，数据将的指针将存储在这里
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此接口可以获取当前发送、接收、操作的状态。

### 6.2.4 Lin_GoToSleep
- **服务名称**: Lin_GoToSleep
- **语法**: Std_ReturnType Lin_GoToSleep(uint8 Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x06
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Channel,要进入睡眠模式的通道
- **参数(输出)**: 无
- **返回值**: Lin_ReturnType
- **描述**: 此接口将中止指定通道的当前传输的报文，并且发送睡眠命令到总线上，之后Lin Driver将处于LIN_CH_SLEEP_STATE状态。

### 6.2.5 Lin_GoToSleepInternal
- **服务名称**: Lin_GoToSleepInternal
- **语法**: Std_ReturnType Lin_GoToSleepInternal(uint8 Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x09
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Channel,Lin通道索引
- **参数(输出)**: 无
- **返回值**: Lin_ReturnType
- **描述**: 此接口将中止指定通道的当前传输的报文，设置Lin驱动进入LIN_CH_SLEEP状态，Lin外设进入低功耗模式。

### 6.2.6 Lin_SendFrame
- **服务名称**: Lin_SendFrame
- **语法**: Std_ReturnType Lin_SendFrame(uint8 Channel, Lin_PduType *PduInfoPtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Channel,要发送报文的通道。PduInfoPtr，要发送的报文配置数据
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此接口用来发送一帧LIN报文。

### 6.2.7 Lin_Wakeup
- **服务名称**: Lin_Wakeup
- **语法**: Std_ReturnType Lin_Wakeup(uint8 Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x07
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Channel,Lin通道索引
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此接口用来在指定的Lin通道上生成一个唤醒脉冲，并将Lin通道置于LIN_CH_OPERATIONAL。

### 6.2.8 Lin_WakeupInternal
- **服务名称**: Lin_WakeupInternal
- **语法**: Std_ReturnType Lin_WakeupInternal(uint8 Channel)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x0B
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此接口用于将Lin通道置于LIN_CH_OPERATIONAL，与Lin_Wakeup不同的是它不发送唤醒脉冲。

### 6.2.9 Lin_CheckWakeup
- **服务名称**: Lin_CheckWakeup
- **语法**: Std_ReturnType Lin_CheckWakeup(uint8 Channel);
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x0A
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: ErrorStatePtr，输出的错误状态
- **返回值**: Lin_ReturnType
- **描述**: 此接口用于检查Lin通道是否被Lin总线唤醒，并通知EcuM。
 

> 以下接口为厂家自定义的扩展接口

### 6.2.10 Lin_Slave_Data_Init
- **服务名称**: Lin_Slave_Data_Init
- **语法**: void Lin_Slave_Data_Init(uint8 Channel,const Lin_PduType *SlaveDataConfig)
- **来源**: 此API由厂商定义。
- **服务ID**: 无
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller，要控制器的Lin控制器。LinifNotificationRequired，切换成功后是否通知到LinIf层
- **参数(输出)**: 无
- **返回值**: Lin_ReturnType
- **描述**: 此接口用于初始化从节点报文的初始数据
                                                 
---
## 6.3 中断处理
中断服务程序在Lin Driver中用于通知、报告错误事件。

### 6.3.1 Lin_UsartInterruptHandler

- **服务名称**：Lin_UsartInterruptHandler
- **语法**：`void Lin_UsartInterruptHandler(uint8 module_id)
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：module_id - Lin控制器ID
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 判断是否存在发送中断事件
  - 发送完整帧数据
  - 判断是否存在接收中断事件
  - 接收整帧报文
- **警告**：无
- **配置**：无需配置
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有3个SRN（服务请求节点）用于服务Lin通道中断请求。
- 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保在Irq_Cfg.h中相应的中断源被启用。

### 6.3.2 Lin_Slave_UsartInterruptHandler

- **服务名称**：Lin_Slave_UsartInterruptHandler
- **语法**：`void Lin_Slave_UsartInterruptHandler (uint8 module_id)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：module_id - Lin控制器ID
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 判断Lin Slave节点是否存在接收中断
  - 接收整帧报文
- **警告**：无
- **配置**：无
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有5个SRN（服务请求节点）用于服务Lin通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保在Irq_Cfg.h中相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 服务请求节点 - Lin硬件资源

| 硬件资源 | SRN编号                  |
| -------- | ------------------------ |
| USART0   | USART0_UNIFIED_INTERRUPT |
| USART1   | USART1_UNIFIED_INTERRUPT |
| USART2   | USART2_UNIFIED_INTERRUPT |
| USART3   | USART3_UNIFIED_INTERRUPT |
| USART6   | USART6_UNIFIED_INTERRUPT |
| USART7   | USART7_UNIFIED_INTERRUPT |


-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

LIN Driver没有提供专有区域。

-----

# 第7章 数据描述

## 7.1 全局数据描述
以下是Lin Driver中使用的所有全局和静态变量的列表。

#### 全局数据描述

| 参数                        | 类型/范围          | 描述                               |
| --------------------------- | ------------------ | ---------------------------------- |
| kpLin_ConfigPtr             | Lin_ConfigType     | Lin Driver的配置结构体指针         |
| kvLin_ModuleStatus          | uint8              | 存储驱动器当前模式状态的变量       |
| kpLin_ChannelConfigPtr      | Lin_ChannelCfgType | 存储各通道的配置结构体指针         |
| kvLin_ChStatus              | uint8              | 存储各通道当前的工作状态           |
| kvLin_SduBuffAddress        | uint8              | 提供各通道通信数据的Buff存储       |
| kvLin_ChFrameStatus         | uint8              | 存储各通道当前帧处于的阶段         |
| kvLin_ChHeaderStatus        | uint8              | 存储帧的类型                       |
| kvLin_ChFrameErrorStatus    | uint8              | 存储各通道帧错误的状态             |
| kvLin_TransmitHeaderCommand | uint8              | 存储帧头当前传输处于的阶段         |
| PduInfoPtrTemp              | Lin_PduType        | 存储各通道每个从节点当前传输帧信息 |


-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是GPT Driver中定义的错误代码及其描述。

#### 错误分类

| 错误代码               | 错误描述         | 值（十六进制） |
| ---------------------- | ---------------- | -------------- |
| LIN_E_UNINIT           | 驱动未初始化错误 | 0x00U          |
| LIN_E_INVALID_CHANNEL  | 无效的通道       | 0x02U          |
| LIN_E_INVALID_POINTER  | 无效的指针       | 0x03U          |
| LIN_E_STATE_TRANSITION | 传输状态错误     | 0x04U          |
| LIN_E_PARAM_POINTER    | 错误的参数指针   | 0x05U          |
| LIN_E_TIMEOUT          | 超时错误         | 0x0CU          |


-----
# 第9章 示例用法
本章描述了如何配置Lin驱动器以及如何在应用程序中使用Lin驱动器提供的不同的API。

## 9.1 集成说明

> 添加以下文件到工程
```
   Lin_GeneralTypes.h
   Lin.h      
   Lin.c      
   Linfd_Im.h
   Linfd_Im.c
   Lin_Cfg.h  
   Lin_LCfg.h
   Lin_LCfg.c
```

## 9.2 驱动配置  
   按照以下指南以及实际应用场景正确配置Lin驱动器：
- MCU驱动器：配置系统时钟。
- 中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级。
- 选择所需的API配置开关，唤醒能力，通知和不同类型的定时器的使用或不使用。


```
Lin_Cfg.h 文件示例配置
   
/**
 * @brief Switches the Development Error Detection and Notification ON or OFF.
 */
#define LIN_DEV_ERROR_DETECT (STD_ON)

/**
 * @brief Switches Precompile Support
 */
#define LIN_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief after Init channel state
 */
#define LIN_START_UP_SLEEP_STATE (STD_OFF)

/**
 * @brief lin slave mode (default:Master)
 */
#define LIN_SLAVE_MODE (STD_ON)

/**
 * @brief LIN SLAVE CONFIG MESSAGE NUM
 *
 */
#define LIN_SLAVE_OBJECT_NUM 3U

/**
 * @brief Switches the Production Error Detection and Notification OFF
 */
#define LIN_DISABLE_DEM_REPORT_ERROR_STATUS (STD_ON)

/**
 * @brief Total number of available hardware lin channels.
 */
#define LIN_IM_MODULES 3U

/**
 * @brief Max data length of the LIN SDU buffer to be returned.
 */
#define LIN_MAX_DATA_LENGTH 8U

/**
 * @brief   Number of loops before returning LIN_E_TIMEOUT.
 *
 * @api
 */
#define LIN_TIMEOUT_LOOPS ((uint32)1000U)

```

```
Lin_LCfg.c文件示例配置

/**
 * @brief None EcuMWakeUpSource was referred when
 * LinChannelWakeupSupport is disable
 */
#define LIN_NONE_ECUM_WAKEUP_SOURCE_REF (uint32)0U

Lin_ChannelCfgType ChannelCfg[LIN_IM_MODULES] = {
  {.LinHwModule                = USART1,
   .LinClockSelect             = 1U,
   .LinChannelWakeupSupport    = (uint8)STD_OFF,
   .LinChannelEcuMWakeupSource = (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF,
   .BaudInteger                = 0x68U,
   .BaudNumerator               = 0U,
   .BaudDenom                  = 1U},
  {.LinHwModule                = USART2,
   .LinClockSelect             = 1U,
   .LinChannelWakeupSupport    = (uint8)STD_OFF,
   .LinChannelEcuMWakeupSource = (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF,
   .BaudInteger                = 0x68U,
   .BaudNumerator               = 0U,
   .BaudDenom                  = 1U},
  {.LinHwModule                = USART3,
   .LinClockSelect             = 1U,
   .LinChannelWakeupSupport    = (uint8)STD_OFF,
   .LinChannelEcuMWakeupSource = (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF,
   .BaudInteger                = 0x68U,
   .BaudNumerator               = 0U,
   .BaudDenom                  = 1U
   }
};

#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
 * @brief DEM error parameters
 */
Lin_DemErrorType Lin_E_TimeOutCfg = {
  .id    = 0U,
  .state = 0U,
};
#endif

const Lin_ConfigType Lin_ConfigPredefined = {
  /*all lin module number*/
   .Lin_Channel_Num = LIN_IM_MODULES,

   /*Configuration for Lin Channel*/
   .Lin_ChannelPtr = &ChannelCfg[0]
};
```
## 9.3 驱动初始化

```
    /* 包含Lin驱动接口头文件 */
    #include "Lin.h"
    
    /* 初始化Lin驱动 */
    Lin_Init(&Lin_ConfigPredefined);
```
## 9.4 API使用

```
    /* 包含Lin驱动接口头文件 */
    #include "Lin.h"
    
    Lin_PduType msg1;
    uint8 data[8]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
    Std_VersionInfoType canDriverVersionInfo;
    Lin_ControllerStateType canControllerState；
    Lin_ErrorStateType canErrorState；
    Std_ReturnType result;
    
    uint8 *Lin_SduPtr;
    Lin_StatusType status;
    
    /* 定义Lin报文 */
    msg1.Pid=0x0A;
    msg1.Cs=LIN_CLASSIC_CS;
    msg1.Drc=LIN_MASTER_RESPONSE;
    msg1.Dl=8;
    msg1.SduPtr=data;
    
    /* 获取Lin驱动软件版本信息 */
    Lin_GetVersionInfo(&canDriverVersionInfo);
    
    /* 在通道0上发送Lin报文 */
    Lin_SendFrame(0,&msg1)
    /* 获取当前发送状态 */
    status = Lin_GetStatus(0,&Lin_SduPtr);
    /* 控制通道0进入睡眠模式 */
    Lin_GoToSleepInternal(0);
    /* 唤醒通道0到正常操作模式 */
    Lin_WakeupInternal(0);
    /* 发送睡眠命令到通道0，并进入睡眠模式 */
    Lin_GoToSleep(0);
    /* 发送唤醒脉冲到通道0，并进入正常操作模式 */
    Lin_Wakeup(0);
    /* 查询通道0是否存在唤醒事件 */
    result = Lin_CheckWakeup(0);
    /* 设置Slave节点数据默认值 */
    Lin_Slave_Data_Init(0,&msg1);
       
```

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 假设

- 中断的全局配置（中断仲裁周期、优先级设置）将由用户处理
- Mcu驱动在Lin驱动之前进行初始化
- 每个Lin通道的Rx、Tx的端口配置由用户初始化
- 单片机时钟设置的多重性配置为1-*
- KF32A1x8支持的最大频率为120MHz


## 10.2 限制

- DEM功能暂不支持
- Memmap暂未实现
- SchM暂未实现

