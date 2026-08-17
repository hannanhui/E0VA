# ChipOn Microcontroller Abstract Layer Users Manual - UART Driver
Release V0.0 - May 2024  
Published by ChipOn 

---

## 变更记录


| 时间       | 版本 | 变更记录    |
| :--------- | :--- | :---------- |
| 2024-07-10 | 0.1  | 初       版 |


----

<a name="br4"></a> 



## 目录

- [ChipOn Microcontroller Abstract Layer Users Manual - UART Driver](#chipon-microcontroller-abstract-layer-users-manual---uart-driver)
	- [变更记录](#变更记录)
	- [目录](#目录)
- [第1章 引言](#第1章-引言)
	- [1.1 范围](#11-范围)
	- [1.2 缩写](#12-缩写)
	- [1.3 参考](#13-参考)
- [第2章 UART Driver概述](#第2章-uart-driver概述)
		- [2.1 软件硬件模块映射](#21-软件硬件模块映射)
			- [2.1.1 UART硬件原理框图](#211-uart硬件原理框图)
		- [2.2 功能描述](#22-功能描述)
		- [2.3 操作模式](#23-操作模式)
		- [2.4 错误处理](#24-错误处理)
		- [2.5 版本信息](#25-版本信息)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
	- [4.1 配置概念](#41-配置概念)
		- [4.1.1 配置类](#411-配置类)
	- [4.2 配置参数变化](#42-配置参数变化)
	- [4.3 UARTGeneral](#43-uartgeneral)
		- [4.3.1 UART\_PRECOMPILE\_SUPPORT](#431-uart_precompile_support)
		- [4.3.2 UART\_DEV\_ERROR\_DETECT](#432-uart_dev_error_detect)
		- [4.3.3 UART\_MULTICORE\_SUPPORT](#433-uart_multicore_support)
		- [4.3.4 UART\_RUNTIME\_ERROR\_DETECT](#434-uart_runtime_error_detect)
		- [4.3.5 UART\_TIMEOUT\_VALUE\_US](#435-uart_timeout_value_us)
		- [4.3.6 UART\_VERSION\_INFO\_API](#436-uart_version_info_api)
		- [4.3.7 UART\_DMA\_USED](#437-uart_dma_used)
		- [4.3.8 UART\_RX\_DATA\_MAX\_SIZE](#438-uart_rx_data_max_size)
	- [4.4 UartChannelConfig](#44-uartchannelconfig)
		- [4.4.1 Module](#441-module)
		- [4.4.2 BaudRateClkSrc](#442-baudrateclksrc)
		- [4.4.3 BaudRateInteger](#443-baudrateinteger)
		- [4.4.4 BaudRateNumerator](#444-baudratenumerator)
		- [4.4.5 BaudRateDenominator](#445-baudratedenominator)
		- [4.4.6 StopBit](#446-stopbit)
		- [4.4.7 ParityMode](#447-paritymode)
		- [4.4.8 ReceiveOrder](#448-receiveorder)
		- [4.4.9 SendOrder](#449-sendorder)
		- [4.4.10 TxSelect](#4410-txselect)
		- [4.4.11 DmaConfigPtr](#4411-dmaconfigptr)
		- [4.4.12 ReceiveCompleteCallback](#4412-receivecompletecallback)
		- [4.4.13 SendCompleteCallback](#4413-sendcompletecallback)
- [第5章 发布的参数](#第5章-发布的参数)
	- [5.1 VendorId](#51-vendorid)
	- [5.2 ModuleId](#52-moduleid)
	- [5.3 InstanceId](#53-instanceid)
	- [5.4 SwMajorVersion](#54-swmajorversion)
	- [5.5 SwMinorVersion](#55-swminorversion)
	- [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
	- [6.1 API类型定义](#61-api类型定义)
		- [6.1.1 类型定义 Uart\_ConfigType](#611-类型定义-uart_configtype)
		- [6.1.2 类型定义 Uart\_ChannelConfigType](#612-类型定义-uart_channelconfigtype)
		- [6.1.3 类型定义 Uart\_DmaSourceConfigType](#613-类型定义-uart_dmasourceconfigtype)
	- [6.2 API函数](#62-api函数)
		- [6.2.1 Uart\_Init](#621-uart_init)
		- [6.2.2 Uart\_Deinit](#622-uart_deinit)
		- [6.2.3 Uart\_SyncSend](#623-uart_syncsend)
		- [6.2.4 Uart\_SyncReceive](#624-uart_syncreceive)
		- [6.2.5 Uart\_AsyncSend](#625-uart_asyncsend)
		- [6.2.6 Uart\_AsyncPollingSend](#626-uart_asyncpollingsend)
		- [6.2.7 Uart\_GetAsyncPollingSendStatus](#627-uart_getasyncpollingsendstatus)
		- [6.2.8 Uart\_AsyncReceive](#628-uart_asyncreceive)
		- [6.2.9 Uart\_Abort](#629-uart_abort)
		- [6.2.10 Uart\_GetBusStatus](#6210-uart_getbusstatus)
		- [6.2.11 Uart\_GetVersionInfo](#6211-uart_getversioninfo)
	- [6.3 中断处理](#63-中断处理)
		- [6.3.1 Uart\_Im\_InterruptHandler](#631-uart_im_interrupthandler)
			- [表79 服务请求节点 - UART硬件资源](#表79-服务请求节点---uart硬件资源)
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
				- [UART头文件配置示例](#uart头文件配置示例)
				- [UART通道配置示例](#uart通道配置示例)
				- [UART配置结构体配置示例](#uart配置结构体配置示例)
				- [UART驱动器初始化示例](#uart驱动器初始化示例)
		- [9.1.2 API用法示例](#912-api用法示例)
- [第10章 限制和假设](#第10章-限制和假设)
	- [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
		- [假设](#假设)
		- [偏差](#偏差)
		- [考虑的Bugzilla](#考虑的bugzilla)
	- [10.2 限制](#102-限制)


---

# 第1章 引言

本用户手册提供了有关UART驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的UART驱动程序实现。
## 1.1 范围

本文档涉及UART Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- UART Driver的文件结构
- Driver的配置参数
- 由UART Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于UART Driver

## 1.2 缩写

MCAL: Microcontroller Abstract Layer，微控制器抽象层
UART: Universal Asynchronous Receiver/Transmitter 异步串行通信

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of UART Driver AUTOSAR CP R22-11
- [2] Requirements on UART Driver AUTOSAR CP R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 UART Driver概述

UART Driver为应用程序提供了与KungFu微控制器平台上的通用异步接收/发送（UART）硬件外设交互的能力。本章介绍了UART Driver的工作原理、功能和主要组件。

### 2.1 软件硬件模块映射

本节介绍了软件模块如何映射到UART硬件模块，以及它们之间的交互方式。

#### 2.1.1 UART硬件原理框图
UART硬件原理框图提供了硬件组件的可视化表示，包括串行通信接口、数据发送和接收线路、控制信号等。
详见用户手册。

### 2.2 功能描述
UART Driver支持以下主要功能：

- **初始化和去初始化**：配置UART硬件并准备其使用，以及释放相关资源。
- **发送和接收数据**：通过同步和异步方式发送和接收数据。
- **中断处理**：管理UART中断，包括接收和发送完成中断。
- **DMA支持**：如果硬件支持，使用直接内存访问（DMA）来提高数据传输效率。
- **配置参数**：允许用户根据需要配置UART的各种参数，如波特率、停止位、校验等。

### 2.3 操作模式
UART Driver支持多种操作模式，包括：

- **轮询模式**：软件通过查询硬件状态来管理数据传输。
- **中断模式**：通过中断服务例程来处理数据传输事件。
- **DMA模式**：使用DMA来实现高效的数据传输，减少CPU负载。

### 2.4 错误处理
驱动程序能够检测和报告常见的UART错误，如：

- 帧错误
- 奇偶校验错误
- 接收溢出错误
- 传输超时

### 2.5 版本信息
UART Driver提供了版本信息，包括供应商ID、模块ID、实例ID和软件版本号，以便于管理和跟踪。

---

# 第3章 文件结构
本节提供了有关UART Driver文件和其他相关文件的详细信息。
| Name        | Description                                      |
| :---------- | :----------------------------------------------- |
| Uart.c      | 此文件包含UART驱动程序的通用接口                 |
| Uart.h      | 此头文件输出UART驱动程序的类型定义和对外接口声明 |
| Uart_Type.h | 次头文件定义了UART驱动程序所有的数据类型         |
| Uart_Cfg.h  | 次头文件声明了UART驱动程序的配置数据             |
| Uart_Im.c   | 此文件包含UART模块所需要的硬件驱动程序           |
| Uart_Im.h   | 此头文件输出UART驱动程序的类型定义和函数原型     |

---

# 第4章 配置文档

## 4.1 配置概念

### 4.1.1 配置类
开发基本软件驱动涉及以下开发周期：
- 编译
- 链接
- 下载可执行文件到ECU存储器

根据配置参数的配置类别，配置类如下分类：
- 预编译时时：通过编译器开关或影响整个构建过程的变量实现。
- 链接时：不影响编译阶段，但影响链接和定位阶段。
- 构建后：不影响构建过程，因此构建后时间配置在运行时应用于驱动器。


## 4.2 配置参数变化
本节描述了相对于支持的微控制器的配置参数的变化。UART Driver在支持的微控制器上没有变化的参数。

## 4.3 UARTGeneral

### 4.3.1 UART_PRECOMPILE_SUPPORT
- **名称**: UART_PRECOMPILE_SUPPORT
- **来源**: 
- **文件**: Uart_Cfg.h
- **范围**: 值：STD_ON/STD_OFF ，默认值：STD_OFF
- **配置类别**: 预编译时 
- **描述**: Enables / Disables PreCompile support when there is a single configuration

### 4.3.2 UART_DEV_ERROR_DETECT
- **名称**: UART_DEV_ERROR_DETECT
- **来源**: AUTOSAR
- **文件**: Uart_Cfg.h
- **范围**: 值：STD_ON – 使能检查和通知，STD_OFF – 使能检查和通知 ，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Enables / Disables DET development errors detection and reporting

### 4.3.3 UART_MULTICORE_SUPPORT
- **名称**: UART_MULTICORE_SUPPORT
- **来源**: AUTOSAR
- **文件**: Uart_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Enables / Disables multicore support

### 4.3.4 UART_RUNTIME_ERROR_DETECT
- **名称**: UART_RUNTIME_ERROR_DETECT
- **来源**: AUTOSAR
- **文件**: Uart_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Enables / Disables Runtime errors detection and reporting

### 4.3.5 UART_TIMEOUT_VALUE_US
- **名称**: UART_TIMEOUT_VALUE_US
- **来源**: AUTOSAR
- **文件**: Uart_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Number of loops before returning Timeout status

### 4.3.6 UART_VERSION_INFO_API
- **名称**: UART_VERSION_INFO_API
- **来源**: AUTOSAR
- **文件**: Uart_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Switches the Uart_GetVersionInfo() API ON or OFF. Support for version info API

### 4.3.7 UART_DMA_USED
- **名称**: UART_DMA_USED
- **来源**: AUTOSAR
- **文件**: Uart_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Uart use DMA or not

### 4.3.8 UART_RX_DATA_MAX_SIZE
- **名称**: UART_RX_DATA_MAX_SIZE
- **来源**: AUTOSAR
- **文件**: Uart_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: Uart max receive size

---
## 4.4 UartChannelConfig

### 4.4.1 Module
- **名称**: Module
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_ModuleType，
- **配置类别**: 预编译时 
- **描述**: USART模块

### 4.4.2 BaudRateClkSrc
- **名称**: BaudRateClkSrc
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_ClockSourceType
- **配置类别**: 预编译时/构建后
- **描述**: 时钟源

### 4.4.3 BaudRateInteger
- **名称**: BaudRateInteger
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: uint16
- **配置类别**: 预编译时
- **描述**: 波特率的整数部分，用于确定UART的通信速率。

### 4.4.4 BaudRateNumerator
- **名称**: BaudRateNumerator
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: uint8
- **配置类别**: 预编译时
- **描述**: 波特率的分子部分，与分母共同决定波特率的分数部分。

### 4.4.5 BaudRateDenominator
- **名称**: BaudRateDenominator
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: uint8
- **配置类别**: 预编译时
- **描述**: 波特率的分母部分，与分子共同决定波特率的分数部分。

### 4.4.6 StopBit
- **名称**: StopBit
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_StopBitType
- **配置类别**: 预编译时
- **描述**: 指定UART通信中停止位的长度，可以是1或2位。

### 4.4.7 ParityMode
- **名称**: ParityMode
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_ParityType
- **配置类别**: 预编译时
- **描述**: 指定UART通信的校验位类型，可以是无校验、奇校验或偶校验。

### 4.4.8 ReceiveOrder
- **名称**: ReceiveOrder
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_ByteOrderType
- **配置类别**: 预编译时
- **描述**: 指定接收数据的字节序，可以是最低有效字节优先或最高有效字节优先。

### 4.4.9 SendOrder
- **名称**: SendOrder
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_ByteOrderType
- **配置类别**: 预编译时
- **描述**: 指定发送数据的字节序，可以是最低有效字节优先或最高有效字节优先。

### 4.4.10 TxSelect
- **名称**: TxSelect
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_TxSelectType
- **配置类别**: 预编译时
- **描述**: 选择UART的发送线路，可以是TX0或TX1。

### 4.4.11 DmaConfigPtr
- **名称**: DmaConfigPtr
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: 指向Uart_DmaSourceConfigType的结构体
- **配置类别**: 预编译时
- **描述**: 指向UART DMA源配置的结构体，用于配置DMA相关的参数。

### 4.4.12 ReceiveCompleteCallback
- **名称**: ReceiveCompleteCallback
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_ReceiveCompleteFcnType
- **配置类别**: 预编译时
- **描述**: 接收完成时调用的回调函数，用于通知上层应用接收操作已完成。

### 4.4.13 SendCompleteCallback
- **名称**: SendCompleteCallback
- **来源**: AUTOSAR定义
- **文件**: Uart_LCfg.h
- **范围**: Uart_SendCompleteFcnType
- **配置类别**: 预编译时
- **描述**: 发送完成时调用的回调函数，用于通知上层应用发送操作已完成。

这些配置参数定义了UART通道的行为和特性，包括通信参数、数据顺序、校验方式、DMA配置和回调函数等。开发者在配置时应根据具体的通信需求和硬件能力进行选择和调整。

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: UART_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Uart.h
- **值**: 43
- **描述**: 

## 5.2 ModuleId
- **语法**: UART_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Uart.h
- **值**: 255
- **描述**: 这个宏给出了UART驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: UART_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Uart.h
- **值**: 0
- **描述**: 这个宏给出了UART驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: UART_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Uart.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: UART_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Uart.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: UART_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Uart.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Uart_ConfigType
- **语法**: Uart_ConfigType
- **类型**: struct
- **文件**: Uart_Types.h
- **范围**:
  - **uint8**
    - UartChannelNum - UART配置个数
  - **Uart_ChannelConfigType** 
    - UartChannelConfigPtr - UART配置
- **描述**: 此类型定义用于配置UART的整体配置。此类型的指针在Uart_Init API中用于初始化UART驱动程序。

### 6.1.2 类型定义 Uart_ChannelConfigType
- **语法**: Uart_ChannelConfigType
- **类型**: struct
- **文件**: Uart_Types.h
- **范围**:
  - **Uart_ModuleType**
    - Module - UART索引号
  - **Uart_ClockSourceType** 
    - BaudRateClkSrc - 时钟源
  - **uint16**
    - BaudRateInteger - 波特率整数部分
  - **uint8**
    - BaudRateNumerator - 小数部分分子
  - **uint8**
    - BaudRateDenominator - 小数部分分母
  - **Uart_StopBitType**
    - StopBit - 停止位个数
  - **Uart_ParityType**
    - ParityMode - 校验模式
  - **Uart_ByteOrderType**
    - ReceiveOrder - 接收时序
 - **Uart_ByteOrderType**
    - SendOrder - 发送时序
 - **Uart_TxSelectType**
    - TxSelect - 发送T0和TX1选择
- **Uart_DmaSourceConfigType**
    - DmaConfigPtr - DMA配置信息
- **Uart_ReceiveCompleteFcnType**
    - ReceiveCompleteCallback - 接收完成回调
- **Uart_SendCompleteFcnType**
    - SendCompleteCallback - 发送完成回调 
- **描述**: 这是包含UART硬件参数具体配置配置信息数据结构类型。

### 6.1.3 类型定义 Uart_DmaSourceConfigType
- **语法**: Uart_DmaSourceConfigType
- **类型**: struct
- **文件**: Uart_Types.h
- **范围**:
  - **uint8**
    - ReceiveDmaSwitch - 接收DMA开关
  - **uint8** 
    - SendDmaSwitch - 发送DMA开关
  - **Uart_DmaSourceType**
    - TxDmaSource - 发送DMA通道选择
  - **Uart_DmaSourceType**
    - RxDmaSource - 接收DMA通道选择
- **描述**: DAM具体配置信息结构体

## 6.2 API函数

### 6.2.1 Uart_Init
- **服务名称**: Uart_Init
- **语法**: `void Uart_Init(const Uart_ConfigType *UartConfigPtr)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: UartConfigPtr - 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化UART驱动程序的服务。

### 6.2.2 Uart_Deinit
- **服务名称**: Uart_Deinit
- **语法**: `void Uart_Deinit(void)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数**: 无
- **返回值**: 无
- **描述**: 去初始化UART驱动程序，释放相关资源。

### 6.2.3 Uart_SyncSend
- **服务名称**: Uart_SyncSend
- **语法**: `Std_ReturnType Uart_SyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize, uint32 Timeout)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号
- **参数(输入)**: Buffer - 要发送的数据缓冲区
- **参数(输入)**: BufferSize - 数据大小；Timeout - 超时时间。
- **参数(输出)**: 无
- **返回值**: Std_ReturnType - 操作结果。
- **描述**: 启动同步发送操作，以同步方式发送指定数量的字节。

### 6.2.4 Uart_SyncReceive
- **服务名称**: Uart_SyncReceive
- **语法**: `Std_ReturnType Uart_SyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize, uint32 Timeout)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号
- **参数(输入)**: Buffer - 接收数据的缓冲区
- **参数(输入)**: BufferSize - 缓冲区大小
- **参数(输入)**: Timeout - 超时时间。
- **参数(输出)**: 无
- **返回值**: Std_ReturnType - 操作结果。
- **描述**: 启动同步接收操作，以同步方式接收指定数量的字节。

### 6.2.5 Uart_AsyncSend
- **服务名称**: Uart_AsyncSend
- **语法**: `Std_ReturnType Uart_AsyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号
- **参数(输入)**: Buffer - 要发送的数据缓冲区
- **参数(输入)**: BufferSize - 数据大小
- **参数(输出)**: 无
- **返回值**: Std_ReturnType - 操作结果。
- **描述**: 启动异步发送操作，使用DMA或中断（根据配置）以异步方式发送数据。

### 6.2.6 Uart_AsyncPollingSend
- **服务名称**: Uart_AsyncPollingSend
- **语法**: `Std_ReturnType Uart_AsyncPollingSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号
- **参数(输入)**: Buffer - 要发送的数据缓冲区
- **参数(输入)**: BufferSize - 数据大小。
- **参数(输出)**: 无
- **返回值**: Std_ReturnType - 操作结果。
- **描述**: 启动DMA方式的异步轮询发送操作。

### 6.2.7 Uart_GetAsyncPollingSendStatus
- **服务名称**: Uart_GetAsyncPollingSendStatus
- **语法**: `Std_ReturnType Uart_GetAsyncPollingSendStatus(uint8 Channel)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号。
- **参数(输出)**: 无
- **返回值**: Std_ReturnType - 发送状态。
- **描述**: 获取异步轮询发送操作的状态。

### 6.2.8 Uart_AsyncReceive
- **服务名称**: Uart_AsyncReceive
- **语法**: `Std_ReturnType Uart_AsyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号
- **参数(输入)**：Buffer - 接收数据的缓冲区
- **参数(输入)**：BufferSize - 缓冲区大小。
- **参数(输出)**: 无
- **返回值**: Std_ReturnType - 操作结果。
- **描述**: 启动异步接收操作，使用DMA或中断（根据配置）以异步方式接收数据。

### 6.2.9 Uart_Abort
- **服务名称**: Uart_Abort
- **语法**: `Std_ReturnType Uart_Abort(uint8 Channel, Uart_DataDirectionType TransmissionType)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号；TransmissionType - 中断传输的类型。
- **参数(输出)**: 无
- **返回值**: Std_ReturnType - 操作结果。
- **描述**: 中止正在进行的接收或传输操作。

### 6.2.10 Uart_GetBusStatus
- **服务名称**: Uart_GetBusStatus
- **语法**: `Uart_StatusType Uart_GetBusStatus(uint8 Channel, Uart_DataDirectionType TransferType)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - UART通道号
- **参数(输入)**: TransferType - 传输类型
- **参数(输出)**: 无
- **返回值**: Uart_StatusType - UART总线状态
- **描述**: 获取UART总线上一次传输的状态。

### 6.2.11 Uart_GetVersionInfo
- **服务名称**: Uart_GetVersionInfo
- **语法**: `void Uart_GetVersionInfo(Std_VersionInfoType *VersionInfo)`
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 根据实际定义
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: VersionInfo - 存储版本信息的结构体指针
- **返回值**: 无
- **描述**: 返回UART驱动模块的版本信息。

-----

## 6.3 中断处理

### 6.3.1 Uart_Im_InterruptHandler
- **服务名称**: Uart_Im_InterruptHandler
- **语法**：`Uart_Im_InterruptHandler(Uart_ModuleType Module)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：不可重入
- **参数（输入）**：Module - UART硬件单元
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 异步收发过程数据处理
  - 接收数据完成回调
  - 发送数据完成回调
- **警告**：无
- **配置**：无
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有5个SRN（服务请求节点）用于服务UART中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - UART硬件资源

| 硬件资源      | SRN编号                  |
| ------------- | ------------------------ |
| UART_MODULE_0 | USART0_UNIFIED_INTERRUPT |
| UART_MODULE_1 | USART1_UNIFIED_INTERRUPT |
| UART_MODULE_2 | USART2_UNIFIED_INTERRUPT |
| UART_MODULE_3 | USART3_UNIFIED_INTERRUPT |
| UART_MODULE_6 | USART6_UNIFIED_INTERRUPT |
| UART_MODULE_7 | USART7_UNIFIED_INTERRUPT |

-----

## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

UART Driver没有提供专有区域。


-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是UART Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数              | 类型/范围          | 描述                        |
| ----------------- | ------------------ | --------------------------- |
| Uart_ConfigPtr    | Uart_ConfigType    | UART Driver配置结构体的指针 |
| Uart_DriverStatus | Uart_DrvStatusType | 驱动状态（是否已初始化）    |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是UART Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                   | 错误描述                               | 值（十六进制） |
| -------------------------- | -------------------------------------- | -------------- |
| UART_E_UNINIT              | 驱动未初始化                           | 0x01U          |
| UART_E_INVALID_CHANNEL     | 作为参数给定的通道无效                 | 0x02U          |
| UART_E_INVALID_POINTER     | 作为参数给定的指针无效                 | 0x03U          |
| UART_E_ALREADY_INITIALIZED | 驱动已初始化                           | 0x04U          |
| UART_E_PARAM_CONFIG        | 无效的核心ID                           | 0x05U          |
| UART_E_CHANNEL_BUSY        | 通道忙，因此无法执行服务               | 0x06U          |
| UART_E_INVALID_PARAMETER   | 参数有错误的值                         | 0x07U          |
| UART_E_TIMEOUT             | 超时发生                               | 0x08U          |
| UART_E_INIT_FAILED         | 初始化函数参数无效                     | 0x09U          |
| UART_E_DEINIT_FAILED       | 特定硬件通道的去初始化函数未能成功完成 | 0x10U          |

-----
# 第9章 示例用法
本章描述了如何配置UART驱动器以及如何在应用程序中使用UART驱动器提供的不同的API。

## 9.1 驱动器配置
按照以下指南正确配置UART驱动器：
1. 系统时钟：配置系统时钟。
2. 中断：在中断请求（IRQ）驱动器中使能中断
3. PORT：配置硬件管脚的复用功能为UART

### 9.1.1 驱动器的示例配置
##### UART头文件配置示例
```c
/** @brief Enables / Disables multicore support */
#define UART_MULTICORE_SUPPORT STD_OFF

/** @brief Enables / Disables PreCompile support when there is a single configuration */
#define UART_PRECOMPILE_SUPPORT STD_OFF

/** @brief Enables / Disables DET development errors detection and reporting */
#define UART_DEV_ERROR_DETECT STD_ON

/** @brief Enables / Disables Runtime errors detection and reporting */
#define UART_RUNTIME_ERROR_DETECT STD_ON

/** @brief Number of loops before returning Timeout status */
#define UART_TIMEOUT_VALUE_US (100U)

/** @brief Switches the Uart_GetVersionInfo() API ON or OFF. Support for version info API. */
#define UART_VERSION_INFO_API STD_ON

/** @brief Uart use DMA or not */
#define UART_DMA_USED STD_ON

/** @brief Uart max receive size */
#define UART_RX_DATA_MAX_SIZE ((uint16)4096U)
```

##### UART通道配置示例
```c
static const Uart_DmaSourceConfigType UsartDmaConfig = {
	.ReceiveDmaSwitch = UART_DMA_ENABLE,
	.SendDmaSwitch = UART_DMA_ENABLE,
	.RxDmaSource = UART_DMA1_CHANNEL_2,
	.TxDmaSource = UART_DMA1_CHANNEL_1,
};

static const Uart_ChannelConfigType UsartChannelConfig = {
	.Module = UART_MODULE_0,
	/** @brief clock source */
	.BaudRateClkSrc = UART_CLOCK_SCLK,
	/* BaudRate = 115200 */
	/** @brief BRGM */
	.BaudRateInteger = 0x41U,
	/** @brief BRGF1 */
	.BaudRateNumerator = 0U,
	/** @brief BRGF2 */
	.BaudRateDenominator = 1U,
	.StopBit = UART_STOP_BIT_1,
	.ParityMode = UART_PARITY_NONE,
	.ReceiveOrder = UART_LSB_FIRST,
	.SendOrder = UART_LSB_FIRST,
	.TxSelect = 0,
	.DmaConfigPtr = &UsartDmaConfig,
	.ReceiveCompleteCallback = Usart_ReceiveComplete,
	.SendCompleteCallback = Usart_SendComplete,
};
```

##### UART配置结构体配置示例
```c
static const Uart_ConfigType UartConfig = {
	.UartChannelNum = 1U,
	.UartChannelConfigPtr = &UsartChannelConfig,
};
```

##### UART驱动器初始化示例
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
// 初始化UART驱动器
Uart_Init(&UartConfig);

```
### 9.1.2 API用法示例
以下是UART驱动器提供的API用法示例
```c
/* 设置PIN脚（正式代码通过Port_Init入参进行配置） */
Gpio_LL_WriteModeDirectionState(GPIOB_PTR, GPIO_PIN_INDEX_4, GPIO_PIN_MODE_REMAP);
Gpio_LL_WriteModeDirectionState(GPIOB_PTR, GPIO_PIN_INDEX_3, GPIO_PIN_MODE_REMAP);
Gpio_LL_WriteRemapCtrlState(GPIOB_PTR, GPIO_PIN_INDEX_4, GPIO_PIN_RMP_PAGE1_AF3);
Gpio_LL_WriteRemapCtrlState(GPIOB_PTR, GPIO_PIN_INDEX_3, GPIO_PIN_RMP_PAGE1_AF3);

/* 使用MCAL接口初始化UART */
Uart_Init(&Uart_Config);

/* 等待接收8个字节的串口数据，
* 同步接口将一直在这里死等，需要用户在PC端开启串口调试助手，手动发送8个字节 */
Uart_SyncReceive(0, rxdata, 8U, 0U);
/* 将刚才收到的数据发回给PC */
Uart_SyncSend(0, rxdata, 8U, 0U);

/* 以0x55填充数组data2 */
memset(data2, 0x55, sizeof(data2));

/* 异步轮询发送data2，必须开启DMA，并确认DMA通道未被其他资源占用 */
if (Uart_AsyncPollingSend(0U, data2, sizeof(data2)) == E_OK)
{
	/* 轮询发送状态，等待发送完成，
		* 发送完成返回E_OK，否则返回E_NOT_OK，程序一直停在这里 */
	while (Uart_GetAsyncPollingSendStatus(0) == E_NOT_OK)
	{
		/* do nothing */
	}
}
else
{
	/* error */
	while (1)
		;
}

/* 以下为异步接口演示，
* 默认采用DMA方式(ReceiveDmaSwitch = USART_DMA_ENABLE, SendDmaSwitch = USART_DMA_ENABLE)
* 需要设置 UART_DMA_USED 为 STD_ON，并确保 Dma_Irq.c 中DMA中断为UART模块使用
*
* 若用户修改DMA配置为USART_DMA_DISABLE, 需要将 Usart_Irq.c 中涉及的宏开启，确保可以进入相应通道的中断
* */

/* 异步方式发送数组data0，
* 发送完成后触发发送完成中断回调 */
Uart_AsyncSend(0U, data0, 8U);

/* 异步方式接收数据，接收完成后触发接收完成中断，
* 该接口没有阻塞，什么时候收到数据，什么时候触发中断回调，
*
* 参数BufferSize=0表示不指定数据长度，通过空闲帧判断接收完成并进行回调，需要开启UART中断
* 参数BufferSize>0表示收到BufferSize个字节的数据即完成接收 */
Uart_AsyncReceive(0U, rxdata, 0U);

/* 等待异步接收数据，成功收到数据，总线状态切换为IDLE，否则一直为ONGOING */
while (Uart_GetBusStatus(0U, UART_RECEIVE) == UART_STATUS_OPERATION_ONGOING)
{
	/* do nothing */
}
``` 

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 假设

| 序号 | 参考 | 假设                                               |
| ---- | ---- | -------------------------------------------------- |
| 1    | 通用 | 确保UART使用的USART硬件模块未与MCAL的LIN组件冲突   |
| 2    | 通用 | 确保UART使用的USART中断未与LIN组件冲突             |
| 3    | 通用 | 确保UART使用的DMA通道未与其他驱动使用的DMA通道冲突 |

### 偏差
1. UART模块同步接收只支持确定长度的数据，不支持不定长数据。
2. UART模块不能通过软件计算波特率参数，需要用户手动计算整数、分子与分母。

### 考虑的Bugzilla
  无
## 10.2 限制
1. 支持最大5个UART通道，
2. 支持常用标准波特率，若为任意值则误差过大
---



