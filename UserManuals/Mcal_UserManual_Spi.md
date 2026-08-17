# ChipOn Microcontroller Abstract Layer Users Manual - SPI Driver
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

- [ChipOn Microcontroller Abstract Layer Users Manual - SPI Driver](#chipon-microcontroller-abstract-layer-users-manual---spi-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 SPI Driver概述](#第2章-spi-driver概述)
    - [2.1 软件硬件模块映射](#21-软件硬件模块映射)
    - [2.1.1 SPI硬件原理框图](#211-spi硬件原理框图)
    - [2.1.2 IRQ](#212-irq)
    - [2.1.3 系统时钟](#213-系统时钟)
    - [2.1.4 软件驱动程序描述](#214-软件驱动程序描述)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 SpiGeneral](#43-spigeneral)
    - [4.3.1 SpiCancelApi](#431-spicancelapi)
    - [4.3.2 SpiChannelBuffersAllowed](#432-spichannelbuffersallowed)
    - [4.3.3 SpiDevErrorDetect](#433-spideverrordetect)
    - [4.3.4 SpiHwStatusApi](#434-spihwstatusapi)
    - [4.3.5 SpiInterruptibleSeqAllowed](#435-spiinterruptibleseqallowed)
    - [4.3.6 SpiLevelDelivered](#436-spileveldelivered)
    - [4.3.7 SpiMainFunctionPeriod](#437-spimainfunctionperiod)
    - [4.3.8 SpiSupportConcurrentSyncTransmit](#438-spisupportconcurrentsynctransmit)
    - [4.3.4 SpiVersionInfoApi](#434-spiversioninfoapi)
  - [4.4 SpiSequence](#44-spisequence)
    - [4.4.1 SpiInterruptibleSequence](#441-spiinterruptiblesequence)
    - [4.4.2 SpiSeqEndNotification](#442-spiseqendnotification)
    - [4.4.3 SpiSequenceId](#443-spisequenceid)
  - [4.5 SpiChannel](#45-spichannel)
      - [4.5.1 SpiChannelId](#451-spichannelid)
      - [4.5.2 SpiChannelType](#452-spichanneltype)
      - [4.5.3 SpiDataWidth](#453-spidatawidth)
      - [4.5.4 SpiDefaultData](#454-spidefaultdata)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 SPI\_ConfigType](#611-类型定义-spi_configtype)
    - [6.1.2 类型定义 Spi\_ChannelConfigType](#612-类型定义-spi_channelconfigtype)
    - [6.1.3 类型定义 Spi\_JobConfigType](#613-类型定义-spi_jobconfigtype)
    - [6.1.3 类型定义 Spi\_SequenceConfigType](#613-类型定义-spi_sequenceconfigtype)
    - [6.1.4 类型定义 Spi\_StatusType](#614-类型定义-spi_statustype)
    - [6.1.5 类型定义 Spi\_JobResultType](#615-类型定义-spi_jobresulttype)
    - [6.1.6 类型定义 Spi\_SeqResultType](#616-类型定义-spi_seqresulttype)
    - [6.1.7 类型定义 Spi\_BufferType](#617-类型定义-spi_buffertype)
    - [6.1.8 类型定义 Spi\_NumberOfDataType](#618-类型定义-spi_numberofdatatype)
    - [6.1.9类型定义 Spi\_HWUnitType](#619类型定义-spi_hwunittype)
    - [6.1.10 类型定义 Spi\_ChannelType](#6110-类型定义-spi_channeltype)
    - [6.1.11 类型定义 Spi\_JobType](#6111-类型定义-spi_jobtype)
    - [6.1.12 类型定义 Spi\_SequenceType](#6112-类型定义-spi_sequencetype)
    - [6.1.13 类型定义 Spi\_DataBufferType](#6113-类型定义-spi_databuffertype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Spi\_Init](#621-spi_init)
    - [6.2.2 Spi\_DeInit](#622-spi_deinit)
    - [6.2.3 Spi\_WriteIB](#623-spi_writeib)
    - [6.2.4 Spi\_AsyncTransmit](#624-spi_asynctransmit)
    - [6.2.5 Spi\_ReadIB](#625-spi_readib)
    - [6.2.6 Spi\_SetupEB](#626-spi_setupeb)
    - [6.2.7 Spi\_GetStatus](#627-spi_getstatus)
    - [6.2.8 Spi\_GetJobResult](#628-spi_getjobresult)
    - [6.2.9 Spi\_GetSequenceResult](#629-spi_getsequenceresult)
    - [6.2.10 Spi\_GetVersionInfo](#6210-spi_getversioninfo)
    - [6.2.11 Spi\_SyncTransmit](#6211-spi_synctransmit)
    - [6.2.12 Spi\_GetHWUnitStatus](#6212-spi_gethwunitstatus)
    - [6.2.13 Spi\_Cancel](#6213-spi_cancel)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Spi\_Dma\_Isr](#631-spi_dma_isr)
      - [表79 服务请求节点 - DMA硬件资源](#表79-服务请求节点---dma硬件资源)
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
        - [SPI头文件配置示例](#spi头文件配置示例)
        - [Channel配置示例](#channel配置示例)
        - [Job配置示例](#job配置示例)
        - [Sequence配置示例](#sequence配置示例)
        - [SPI配置结构体及硬件单元配置示例](#spi配置结构体及硬件单元配置示例)
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

本用户手册提供了有关SPI驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的SPI驱动程序实现。该文档描述了如何使用SPI驱动程序
## 1.1 范围

本文档涉及SPI Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- SPI Driver的文件结构
- Driver的配置参数
- 由SPI Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于SPI Driver

## 1.2 缩写

MCAL: Microcontroller Abstract Layer，微控制器抽象层
SPI: Serial Peripheral Interface，串行外设接口
CS: Chip Select
MISO: Master Input Slave Output
MOSI: Master Output Slave Input
EB: Externally buffered channels
IB: Internally buffered channels

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of SPI Handler/Driver AUTOSAR CP R22-11
- [2] Requirements on SPI Handler/Driver AUTOSAR CP R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 SPI Driver概述
SPI 模块支持 SPI 协议，SPI 模式主要特征：
- 3 线或者 4 线数据传输
- 8/16/32 位传输帧格式
- MSB/LSB 先发送可选
- 时钟频率可设
- 可编程的时钟极性和相位
- DMA 读写

### 2.1 软件硬件模块映射
本节向用户介绍了实现中使用的硬件特性。图1展示了KungFu硬件外设及其与驱动程序的交互。

### 2.1.1 SPI硬件原理框图

### 2.1.2 IRQ
IRQ Driver负责初始化通用定时器所需的中断优先级。见表79

### 2.1.3 系统时钟
系统时钟通过MCU Driver设置。必须设置适当的系统时钟。

### 2.1.4 软件驱动程序描述


---

# 第3章 文件结构
本节提供了有关SPI Driver文件和其他相关文件的详细信息。
| Name      | Description                                     |
| :-------- | :---------------------------------------------- |
| SPI.c     | 此文件包含SPI驱动程序的通用功能                 |
| SPI.h     | 此头文件输出SPI驱动程序的宏、类型定义和函数原型 |
| SPI_Cfg.h | 本文在这里声明了SPI驱动程序的配置数据。         |
| SPI_Im.c  | 此文件包含SPI模块所需要的硬件驱动程序           |
| SPI_Im.h  | 此头文件输出SPI驱动程序的宏、类型定义和函数原型 |


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
本节描述了相对于支持的微控制器的配置参数的变化。SPI Driver在支持的微控制器上没有变化的参数。

## 4.3 SpiGeneral

### 4.3.1 SpiCancelApi
- **名称**: SpiCancelApi
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体
- **描述**: Spi_Cancel函数开关

### 4.3.2 SpiChannelBuffersAllowed
- **名称**: SpiChannelBuffersAllowed
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：IB = 0; EB = 1; IB/EB = 2; 默认值：2
- **配置类别**: 预编译时间 X 所有变体
- **描述**: 选择SPI驱动程序的通道可使用的缓冲区类型

### 4.3.3 SpiDevErrorDetect
- **名称**: SpiDevErrorDetect
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：STD_ON – 使能检查和通知，STD_OFF – 使能检查和通知 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体
- **描述**: 使能开发错误检测和通知

### 4.3.4 SpiHwStatusApi
- **名称**: SpiHwStatusApi
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体
- **描述**: Spi_GetHWUnitStatus函数开关

### 4.3.5 SpiInterruptibleSeqAllowed
- **名称**: SpiInterruptibleSeqAllowed
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：使能可中断Sequence – STD_ON，不使能可中断Sequence – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体
- **描述**: 切换是否支持可中断Sequence功能

### 4.3.6 SpiLevelDelivered
- **名称**: SpiLevelDelivered
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：0 .. 2，默认值：2
- **配置类别**: 预编译时间 X 所有变体
- **描述**: Selects the SPI Handler/Driver level of scalable functionality that is available and delivered

### 4.3.7 SpiMainFunctionPeriod
- **名称**: SpiMainFunctionPeriod
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：0 .. 1，默认值：1
- **配置类别**: 预编译时间 X 所有变体
- **描述**: Spi_MainFunction_Handling函数调用周期

### 4.3.8 SpiSupportConcurrentSyncTransmit
- **名称**: SpiSupportConcurrentSyncTransmit
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：支持并行同步发送 – STD_ON，不支持并行同步发送 – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体
- **描述**:  Specifies whether concurrent Spi_SyncTransmit() calls for different sequences shall be configurable.

### 4.3.4 SpiVersionInfoApi
- **名称**: SpiVersionInfoApi
- **来源**: AUTOSAR定义
- **文件**: SPI_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体
- **描述**:  Spi_GetVersionInfo函数开关

---
## 4.4 SpiSequence

### 4.4.1 SpiInterruptibleSequence
- **名称**: SpiInterruptibleSequence
- **来源**: AUTOSAR定义
- **文件**: Spi_LCfg.c
- **范围**: 值：允许Sequence被打断 – TRUE，不允许Sequence被打断 – FALSE，默认值：FALSE
- **配置类别**: 预编译时间 X 所有变体
- **描述**:  This parameter allows or not this Sequence to be suspended by another one

### 4.4.2 SpiSeqEndNotification
- **名称**: SpiSeqEndNotification
- **来源**: AUTOSAR定义
- **文件**: Spi_LCfg.c
- **范围**: 值：通知函数指针，默认值：NULL_PTR
- **配置类别**: 预编译时间 X 所有变体
- **描述**:  This parameter is a reference to a notification function

### 4.4.3 SpiSequenceId
- **名称**: SpiSequenceId
- **来源**: AUTOSAR定义
- **文件**: Spi_LCfg.c
- **范围**: 值：0..255，默认值：-
- **配置类别**: 预编译时间 X 所有变体
- **描述**:  SPI Sequence ID

----
## 4.5 SpiChannel

#### 4.5.1 SpiChannelId
- **名称**: SpiChannelId
- **来源**: AUTOSAR定义
- **文件**: Spi_LCfg.c
- **范围**: 值：0 .. 255
- **配置类别**: 预编译时间 X 变体PC
- **描述**: SPI Channel ID

#### 4.5.2 SpiChannelType
- **名称**: SpiChannelType
- **来源**: AUTOSAR定义
- **文件**: Spi_LCfg.c
- **范围**: 值：EB/IB
- **配置类别**: 预编译时间 X 变体PC
- **描述**: Channel缓冲区类型

#### 4.5.3 SpiDataWidth
- **名称**: SpiDataWidth
- **来源**: AUTOSAR定义
- **文件**: Spi_LCfg.c
- **范围**: 值：1 .. 64
- **配置类别**: 预编译时间 X 变体PC
- **描述**: SPI 发送数据位宽

#### 4.5.4 SpiDefaultData
- **名称**: SpiDefaultData
- **来源**: AUTOSAR定义
- **文件**: Spi_LCfg.c
- **范围**: 值：0 .. 4294967295
- **配置类别**: 预编译时间 X 变体PC
- **描述**: SPI 发送数据位宽
------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: SPI_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: SPI.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: SPI_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: SPI.h
- **值**: 100
- **描述**: 这个宏给出了SPI驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: SPI_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: SPI.h
- **值**: 0
- **描述**: 这个宏给出了SPI驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: SPI_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: SPI.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: SPI_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: SPI.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: SPI_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: SPI.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 SPI_ConfigType
- **语法**: SPI_ConfigType
- **类型**: Struct
- **文件**: SPI.h
- **范围**: 
  - ChannelConfig (Spi_ChannelConfigType*)
  - 指向SPI_ChannelConfigType 
  - JobConfig (Spi_JobConfigType*)
  - 指向Spi_JobConfigType
  -  SequenceConfig(Spi_SequenceConfigType*)
  -  指向Spi_SequenceConfigType
  -  HwUnitConfig(Spi_HwUnitConfigType*)
  -  指向Spi_HwUnitConfigType
- **NumOfHwUnit** (uint8)
  - SPI硬件单元数量
- **NumOfChannel** (uint8)
  - SPI驱动可配置的Channel数量
- **NumOfJob** (uint8)
  - SPI驱动可配置的Job数量
- **NumOfSequence** (uint8)
  - SPI驱动可配置的Sequence数量
- **描述**: 此类型定义用于配置SPI的整体配置。此类型的指针在SPI_Init API中用于初始化SPI驱动程序。

### 6.1.2 类型定义 Spi_ChannelConfigType 
- **语法**: Spi_ChannelConfigType
- **类型**: struct
- **文件**: Spi.h
- **范围**:
  -  BufferDescriptor (Spi_BufferDescriptorType *)
  - 指向Spi_BufferDescriptorType
- **Length** (Spi_NumberOfDataType)
  - 数据长度
- **DefaultTransmitValue**(uint32)
  - 默认发送数据
- **BitOrder**(Spi_BitOrderType)
  - 数据方向
- **DataWidth**(Spi_DataWidthType)
  - 数据宽度
- **BufferType**(Spi_BufferType)
  - 数据缓冲区类型
- **描述**: 这是包含SPI Channel特定参数的数据结构类型。

### 6.1.3 类型定义 Spi_JobConfigType 
- **语法**: Spi_JobConfigType
- **类型**: struct
- **文件**: Spi.h
- **范围**:
  -  ExtDeviceConfig (Spi_ExternalDeviceConfigType *)
  - 指向Spi_ExternalDeviceConfigType
- **HwUnit** (Spi_HWUnitType)
  - SPI硬件单元
- **Priority**(sint8)
  - Job 优先级
- **JobEndNotification**(Spi_NotifyFcnType)
  - Job 结束通知函数指针
- **ChannelIndexList**(Spi_ChannelType*)
  - Job包含的通道索引
- **NumChannels**(uint8)
  - Job包含的通道数量
- **描述**: 这是包含SPI Job特定参数的数据结构类型。

### 6.1.3 类型定义 Spi_SequenceConfigType 
- **语法**: Spi_SequenceConfigType
- **类型**: struct
- **文件**: Spi.h
- **范围**:
- **Interruptable** (boolean)
  - Sequence是否可被中断的设置
- **SeqEndNotification**(Spi_NotifyFcnType)
  - Sequence通知函数指针
- **JobIndexList**(Spi_JobType*)
  - Sequence包含的Job索引
- **NumJobs**(Spi_JobType)
  - Sequence包含的Job数量
- **描述**: 这是包含SPI Sequence特定参数的数据结构类型。

### 6.1.4 类型定义 Spi_StatusType
- **语法**: Spi_StatusType
- **类型**: Enum
- **文件**: Spi.h
- **范围**: SPI_UNINIT/SPI_IDLE/SPI_BUSY
- **描述**: SPI驱动的状态

### 6.1.5 类型定义 Spi_JobResultType
- **语法**: Spi_JobResultType
- **类型**: Enum
- **文件**: Spi.h
- **范围**: SPI_JOB_OK/SPI_JOB_PENDING/SPI_JOB_FAILED/SPI_JOB_QUEUED
- **描述**: SPI Job的状态

### 6.1.6 类型定义 Spi_SeqResultType
- **语法**: Spi_SeqResultType
- **类型**: Enum
- **文件**: Spi.h
- **范围**: SPI_SEQ_OK/SPI_SEQ_PENDING/SPI_SEQ_FAILED/SPI_SEQ_CANCELED
- **描述**: SPI Sequence的状态

### 6.1.7 类型定义 Spi_BufferType
- **语法**: Spi_BufferType
- **类型**: Enum
- **文件**: Spi.h
- **范围**: SPI_BUFFER_IB/SPI_BUFFER_EB
- **描述**: SPI 通道使用的buffer类型

### 6.1.8 类型定义 Spi_NumberOfDataType
- **语法**: Spi_NumberOfDataType
- **类型**: uint16
- **文件**: Spi.h
- **范围**: 0到0xFFFF
- **描述**: 数据缓冲区元素的类型。

### 6.1.9类型定义 Spi_HWUnitType
- **语法**: Spi_HWUnitType
- **类型**: uint8
- **文件**: Spi.h
- **范围**: 0到0xFF
- **描述**: SPI硬件单元的ID类型。

### 6.1.10 类型定义 Spi_ChannelType
- **语法**: Spi_ChannelType
- **类型**: uint8
- **文件**: Spi.h
- **范围**: 0到0xFF
- **描述**: Channel的ID类型。

### 6.1.11 类型定义 Spi_JobType
- **语法**: Spi_JobType
- **类型**: uint16
- **文件**: Spi.h
- **范围**: 0到0xFF
- **描述**: Job的ID类型。

### 6.1.12 类型定义 Spi_SequenceType
- **语法**: Spi_SequenceType
- **类型**: uint8
- **文件**: Spi.h
- **范围**: 0到0xFF
- **描述**: Sequence的ID类型。

### 6.1.13 类型定义 Spi_DataBufferType
- **语法**: Spi_DataBufferType
- **类型**: uint8
- **文件**: Spi.h
- **范围**: 0到0xFF
- **描述**: 应用程序数据缓冲区元素的类型。
---
## 6.2 API函数

### 6.2.1 Spi_Init
- **服务名称**: Spi_Init
- **语法**: void Spi_Init (const Spi_ConfigType* ConfigPtr ) 
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: ConfigPtr - 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化SPI驱动程序的服务。

### 6.2.2 Spi_DeInit
- **服务名称**: Spi_DeInit
- **语法**: Std_ReturnType Spi_DeInit (void)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 去初始化SPI驱动程序。

### 6.2.3 Spi_WriteIB
- **服务名称**: Spi_WriteIB
- **语法**: Std_ReturnType Spi_WriteIB (Spi_ChannelType Channel,const Spi_DataBufferType* DataBufferPtr)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 
- Channel - Channel ID
- DataBufferPtr - 数据源缓冲区指针
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 提供了通过相应的参数向SPI驱动通道的IB写入一个或多个数据的服务

### 6.2.4 Spi_AsyncTransmit
- **服务名称**: Spi_AsyncTransmit
- **语法**: Std_ReturnType Spi_AsyncTransmit (Spi_SequenceType Sequence)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x03
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Sequence - Sequence ID
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 提供了SPI总线发送数据的服务。

### 6.2.5 Spi_ReadIB
- **服务名称**: Spi_ReadIB
- **语法**: Std_ReturnType Spi_ReadIB (Spi_ChannelType Channel,Spi_DataBufferType* DataBufferPointer)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Channel - Channel ID
- **参数(输出)**: DataBufferPointer - 接收数据缓冲区指针
- **返回值**: Std_ReturnType
- **描述**: 提供了从参数指定的SPI驱动通道的IB 同步读取一个或多个数据的服务

### 6.2.6 Spi_SetupEB
- **服务名称**: Spi_SetupEB
- **语法**: Std_ReturnType Spi_SetupEB (Spi_ChannelType Channel,const Spi_DataBufferType* SrcDataBufferPtr,Spi_DataBufferType* DesDataBufferPtr,Spi_NumberOfDataType Length)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x05
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 
- Channel-Channel ID
- SrcDataBufferPtr - 发送数据缓冲区指针
- Length-发送数据长度
- **参数(输出)**: DataBufferPointer - 接收数据缓冲区指针
- **返回值**: Std_ReturnType
- **描述**: 提供了为指定的EB SPI驱动程序通道设置缓冲区和数据长度的服务

### 6.2.7 Spi_GetStatus
- **服务名称**: Spi_GetStatus
- **语法**: Spi_StatusType Spi_GetStatus (void)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x6
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: Spi_StatusType
- **描述**: 返回SPI驱动程序的软件模块状态

### 6.2.8 Spi_GetJobResult
- **服务名称**: Spi_GetJobResult
- **语法**: Spi_JobResultType Spi_GetJobResult (Spi_JobType Job)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x7
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Job - Job ID
- **参数(输出)**: 无
- **返回值**: Spi_JobResultType
- **描述**: 返回指定Job的最后一次传输结果

### 6.2.9 Spi_GetSequenceResult
- **服务名称**: Spi_GetSequenceResult
- **语法**: Spi_SeqResultType Spi_GetSequenceResult (Spi_SequenceType Sequence)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x8
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Sequence - Sequence ID
- **参数(输出)**: 无
- **返回值**: Spi_SeqResultType
- **描述**: 返回指定Sequence的最后一次传输结果

### 6.2.10 Spi_GetVersionInfo
- **服务名称**: Spi_GetVersionInfo
- **语法**: void Spi_GetVersionInfo (Std_VersionInfoType *Versioninfo)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x09
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: Versioninfo - 存储驱动版本信息的指针
- **返回值**: 无
- **描述**: 返回驱动的版本信息的服务

### 6.2.11 Spi_SyncTransmit
- **服务名称**: Spi_SyncTransmit
- **语法**: Std_ReturnType Spi_SyncTransmit (Spi_SequenceType Sequence)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x0a
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Sequence - Sequence ID
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 提供了SPI总线发送数据的服务

### 6.2.12 Spi_GetHWUnitStatus
- **服务名称**: Spi_GetHWUnitStatus
- **语法**: Spi_StatusType Spi_GetHWUnitStatus (Spi_HWUnitType HWUnit)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x0b
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: HWUnit - SPI硬件单元ID
- **参数(输出)**: 无
- **返回值**: Spi_StatusType
- **描述**: 提供了SPI总线发送数据的服务

### 6.2.13 Spi_Cancel
- **服务名称**: Spi_GetHWUnitStatus
- **语法**: void Spi_Cancel (Spi_SequenceType Sequence)
- **来源**: 此API由AUTOSAR定义
- **服务ID**: 0x0c
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Sequence - Sequence ID
- **参数(输出)**: 无
- **返回值**: Spi_StatusType
- **描述**: 取消指定的正在进行的序列传输
---
## 6.3 中断处理

### 6.3.1 Spi_Dma_Isr
- **服务名称**：Spi_Dma_Isr
- **语法**：`void Spi_Dma_Isr(uint8 Module, uint8 Mode, uint8 IntrFlag)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：不可重入
- **参数（输入）**：Module - SPI模块编号
- **参数（输入）**: IntrFlag  - 中断标志
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 按Channel队列触发DMA发送
  - 通知上层Job状态
- **警告**：无
- **配置**：无
- **DET**：无
- **DEM**：无
- **实施注释**：无
 - **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有2个SRN（服务请求节点）用于服务SPI中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - DMA硬件资源

| 硬件资源 | SRN编号                |
| -------- | ---------------------- |
| DMA0     | DMA0_UNIFIED_INTERRUPT |
| DMA1     | DMA1_UNIFIED_INTERRUPT |

 
-----

## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

SPI Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是SPI Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                        | 类型/范围             | 描述                            |
| --------------------------- | --------------------- | ------------------------------- |
| kvSpi_ConfigPtr             | Spi_ConfigType        | SPI Driver配置结构的指针。      |
| kvSpi_HwUnitQueueArray      | Spi_HwUnitQueue       | SPI硬件单元队列                 |
| kvSpi_SequenceState         | Spi_SequenceStateType | SPI Sequence 状态               |
| kvSpi_JobState              | Spi_JobStateType      | SPI Job 状态                    |
| kvSpi_ChannelState          | Spi_ChannelStateType  | SPI Channel状态                 |
| kvSpi_SeqUsedHWUnits        | uint32                | 每个Sequence使用的硬件单元      |
| kvSpi_BusySyncHWUnitsStatus | uint32                | SPI同步发送时硬件单元的运行状态 |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是SPI Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                  | 错误描述                                 | 值（十六进制） |
| ------------------------- | ---------------------------------------- | -------------- |
| SPI_E_PARAM_CHANNEL       | 错误Channel参数                          | 0x0A           |
| SPI_E_PARAM_JOB           | 错误Job参数                              | 0x0B           |
| SPI_E_PARAM_SEQ           | 错误Sequence参数                         | 0x0C           |
| SPI_E_PARAM_LENGTH        | 错误长度参数                             | 0x0D           |
| SPI_E_PARAM_UNIT          | 错误硬件单元                             | 0x0E           |
| SPI_E_PARAM_POINTER       | 错误指针                                 | 0x10           |
| SPI_E_UNINIT              | SPI未初始化                              | 0x1A           |
| SPI_E_SEQ_PENDING         | 异步发送的Sequence正在运行               | 0x2A           |
| SPI_E_SEQ_IN_PROCESS      | 同步发送Sequence正在运行                 | 0x3A           |
| SPI_E_ALREADY_INITIALIZED | SPI重复初始化                            | 0x4A           |
| SPI_E_CONFIG_OUT_OF_RANGE | Channel、Job或Sequence超过最大可配置范围 | 0x5A           |
| SPI_E_PARAM_EB_UNIT       | EB未初始化                               | 0x5B           |
| SPI_E_SEQ_EMPTY           | Sequence中未配置Job                      | 0x5C           |
| SPI_E_JOB_EMPTY           | Job中未配置Channel                       | 0x5D           |
| SPI_E_INIT_FAILED         | SPI初始化失败                            | 0x6A           |

-----
# 第9章 示例用法
本章描述了如何配置SPI驱动器以及如何在应用程序中使用SPI驱动器提供的不同的API。

## 9.1 驱动器配置
按照以下指南正确配置SPI驱动器：
1. MCU驱动器：配置系统时钟。
2. 中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级

### 9.1.1 驱动器的示例配置
##### SPI头文件配置示例
```c
#define SPI_CHANNEL_BUFFERS_ALLOWED SPI_USAGE2
#define SPI_VERSION_INFO_API STD_ON
#define SPI_CANCEL_API STD_ON
#define SPI_HW_STATUS_API STD_ON
#define SPI_TRANS_MAX_TIMEOUT ((uint32)0xFFFFFU)
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_DMA_USED STD_ON
#else
#define SPI_DMA_USED STD_OFF
#endif
#define SPI_MAX_HWUNIT (3U)
#define SPI_MAX_JOB      (2U)
#define SPI_MAX_CHANNEL  (6U)
#define SPI_MAX_SEQUENCE (2U)
#define SPI_DEV_ERROR_DETECT STD_ON
#define SPI_INTERRUPTABLE_SEQ_ALLOWED STD_OFF
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT STD_OFF
#define SPI_IB_MAX_LENGTH (10U)
#define SPI_PRECOMPILE_SUPPORT (STD_OFF)
```

##### Channel配置示例
```c
uint8 Spi_Test_BufferTx_Channel2[6];
uint8 Spi_Test_BufferRx_Channel2[6];
uint8 Spi_Test_BufferTx_Channel3[6];
uint8 Spi_Test_BufferRx_Channel3[6];

Spi_ChannelConfigType g_spi_channel_config[SPI_MAX_CHANNEL] = {
  {
    .BufferType           = SPI_BUFFER_EB,
    .DataWidth            = 8U,
    .BitOrder             = SPI_BIT_MSB,
    .DefaultTransmitValue = 0xAAU,
    .Length               = 6,
    .BufferDescriptor =
      &(Spi_BufferDescriptorType){
        .BufferTX = NULL_PTR,
        .BufferRX = NULL_PTR,
      },
  },
  {
    .BufferType           = SPI_BUFFER_EB,
    .DataWidth            = 8U,
    .BitOrder             = SPI_BIT_MSB,
    .DefaultTransmitValue = 0xAAU,
    .Length               = 6U,
    .BufferDescriptor =
      &(Spi_BufferDescriptorType){
        .BufferTX = NULL_PTR,
        .BufferRX = NULL_PTR,
      },
  },
  {
    .BufferType           = SPI_BUFFER_IB,
    .DataWidth            = 8U,
    .BitOrder             = SPI_BIT_MSB,
    .DefaultTransmitValue = 0xAAU,
    .Length               = 6U,
    .BufferDescriptor =
      &(Spi_BufferDescriptorType){
        .BufferTX = Spi_Test_BufferTx_Channel2,
        .BufferRX = Spi_Test_BufferRx_Channel2,
      },
  },
  {
    .BufferType           = SPI_BUFFER_IB,
    .DataWidth            = 8U,
    .BitOrder             = SPI_BIT_MSB,
    .DefaultTransmitValue = 0xAAU,
    .Length               = 6U,
    .BufferDescriptor =
      &(Spi_BufferDescriptorType){
        .BufferTX = Spi_Test_BufferTx_Channel3,
        .BufferRX = Spi_Test_BufferRx_Channel3,
      },
  },
};
```
##### Job配置示例
```c
const Spi_JobConfigType g_spi_job_config[SPI_MAX_JOB] = {
  {
    .NumChannels        = 2U,
    .ChannelIndexList   = (Spi_ChannelType[]){0, 1},
    .JobEndNotification = &JobEnd_0,
    .Priority           = 1,
    .HwUnit             = SPI_HW_UNIT_0,
    .ExtDeviceConfig =
      &(Spi_ExternalDeviceConfigType){
        .BaudRatePrescaler = 14,
        .ClkMode           = SPI_CPOL_0_CPHA_1,
        .CsSelection       = SPI_CSS_VIA_GPIO,
        .CsPin             = SPI_CS_PIN_SS0,
        .DisableCSFcn      = &JobCsOff,
        .EnableCSFcn       = &JobCsOn,
      },
  },
  {
    .NumChannels        = 2U,
    .ChannelIndexList   = (Spi_ChannelType[]){2, 3},
    .JobEndNotification = &JobEnd_1,
    .Priority           = 2,
    .HwUnit             = SPI_HW_UNIT_0,
    .ExtDeviceConfig =
      &(Spi_ExternalDeviceConfigType){
        .BaudRatePrescaler = 14,
        .ClkMode           = SPI_CPOL_0_CPHA_1,
        .CsSelection       = SPI_CSS_VIA_GPIO,
        .CsPin             = SPI_CS_PIN_SS0,
        .DisableCSFcn      = &JobCsOff,
        .EnableCSFcn       = &JobCsOn,
      },
  }};
```
##### Sequence配置示例
```c
/* Sequence配置 */
const Spi_SequenceConfigType g_spi_seq_config[SPI_MAX_SEQUENCE] = {
  {
    .Interruptable      = FALSE,
    .JobIndexList       = (Spi_JobType[]){0, 1},
    .NumJobs            = 2,
    .SeqEndNotification = NULL_PTR,
  },
  {
    .Interruptable      = FALSE,
    .JobIndexList       = (Spi_JobType[]){1, 0},
    .NumJobs            = 2,
    .SeqEndNotification = NULL_PTR,
  }};
```
##### SPI配置结构体及硬件单元配置示例
```c
/* SPI配置结构体及硬件单元配置 */
Spi_ConfigType g_spi_config[1U] = {
  {
    .NumOfChannel   = 4,
    .NumOfJob       = 2,
    .NumOfSequence  = 2,
    .ChannelConfig  = g_spi_channel_config,
    .JobConfig      = g_spi_job_config,
    .SequenceConfig = g_spi_seq_config,
    .NumOfHwUnit    = 2U,
    .HwUnitConfig =
      (Spi_HwUnitConfigType[]){
        [0].HwUnitID   = SPI_HW_UNIT_0,
        [0].HwClkSrc   = SPI_HW_SCLK,
        [0].HwClkDiv   = SPI_CLK_DIV_4,
        [0].HwLineMode = SPI_LINE_MODE_CROSS,
#if (SPI_DMA_USED == STD_ON)
        [0].DmaConfig = {.RxPriority = 3U, .TxPriority = 3U},
#endif

        [1].HwUnitID   = SPI_HW_UNIT_1,
        [1].HwClkSrc   = SPI_HW_SCLK,
        [1].HwClkDiv   = SPI_CLK_DIV_4,
        [1].HwLineMode = SPI_LINE_MODE_CROSS,
#if (SPI_DMA_USED == STD_ON)
        [1].DmaConfig = {.RxPriority = 1U, .TxPriority = 1U},
#endif
      },
  },
};
```

#### 9.1.11 驱动器初始化
代码清单3展示了初始化SPI驱动器所涉及的步骤。注意：用户必须确保在调用SPI_Init之前调用Mcu_Init
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
// 初始化SPI驱动器
SPI_Init(&g_spi_config[0]);
```
### 9.1.2 API用法示例
以下是SPI驱动器提供的API用法示例：
```c
//配置EB
Spi_SetupEB(CHANNEL_ID_3, (Spi_DataBufferType *)&Channel3_TX[0], (Spi_DataBufferType*)&Channel3_RX[0], 2U);
// 写入IB数据
Spi_WriteIB(CHANNEL_ID_0, (Spi_DataBufferType *)&Dma_8bit_test_W);
//SPI同步传输
Spi_SyncTransmit(0);
//SPI读取Job状态
job0Result = Spi_GetJobResult(0);
//SPI读取Sequence状态
Spi_SeqResult=Spi_GetSequenceResult(0);
//读SPI软件模块状态
Spi_Status = Spi_GetStatus();
//读取IB数据
Spi_ReadIB(CHANNEL_ID_0, (Spi_DataBufferType *)&Dma_8bit_test_R[0]);
//SPI异步传输
Spi_AsyncTransmit(0);
//SPI取消Sequence0发送
Spi_Cancel(0U);
//SPI反初始化
Spi_DeInit();
``` 

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 假设

| 序号 | 参考 | 假设                                                                      |
| ---- | ---- | ------------------------------------------------------------------------- |
| 1    | 通用 | SPI在调用Spi_AsyncTransmit之后，应在SPI状态置为IDLE后读取接收缓冲区数据。 |
| 2    | 通用 | 确保SPI使用的DMA通道未和其他驱动使用的DMA通道冲突                         |

### 偏差

### 考虑的Bugzilla

1. Spi模块异步发送只实现了中断模式，轮询模式未实现。
2. Spi_MainFunction_Handling函数未实现。

## 10.2 限制
1. 根据Autosar规范。最大Sequence数量为255，最大Channel数量为255，最大Job数量为65535。
2. 支持最大3个SPI硬件模块。
3. SPI驱动暂不支持从机模式。
---



