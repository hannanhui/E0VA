# ChipOn Microcontroller Abstract Layer Users Manual - ADC Driver
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

- [ChipOn Microcontroller Abstract Layer Users Manual - ADC Driver](#chipon-microcontroller-abstract-layer-users-manual---adc-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 ADC Driver概述](#第2章-adc-driver概述)
    - [2.1 软件硬件模块映射](#21-软件硬件模块映射)
    - [2.2 系统时钟](#22-系统时钟)
    - [2.3 PORT](#23-port)
    - [2.4 TIMER](#24-timer)
    - [2.5 DMA](#25-dma)
    - [2.6 ADC中断](#26-adc中断)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 AdcGeneral](#43-adcgeneral)
    - [4.3.1 AdcDeInitApi](#431-adcdeinitapi)
    - [4.3.2 AdcDevErrorDetect](#432-adcdeverrordetect)
    - [4.3.3 AdcEnableQueuing](#433-adcenablequeuing)
    - [4.3.4 AdcEnableStartStopGroupApi](#434-adcenablestartstopgroupapi)
    - [4.3.5 AdcGrpNotifCapability](#435-adcgrpnotifcapability)
    - [4.3.6 AdcHwTriggerApi](#436-adchwtriggerapi)
    - [4.3.7 AdcLowPowerStatesSupport](#437-adclowpowerstatessupport)
    - [4.3.8 AdcPowerStateAsynchTransitionMode](#438-adcpowerstateasynchtransitionmode)
    - [4.3.9 AdcPriorityImplementation](#439-adcpriorityimplementation)
    - [4.3.10 AdcReadGroupApi](#4310-adcreadgroupapi)
    - [4.3.11 AdcResultAlignment](#4311-adcresultalignment)
    - [4.3.12 AdcVersionInfoApi](#4312-adcversioninfoapi)
  - [4.4 AdcPowerStateConfig](#44-adcpowerstateconfig)
    - [4.4.1 AdcPowerState](#441-adcpowerstate)
    - [4.4.2 AdcPowerStateReadyCbkRef](#442-adcpowerstatereadycbkref)
  - [4.5 AdcChannel](#45-adcchannel)
    - [4.5.1 AdcGroupAccessMode](#451-adcgroupaccessmode)
    - [4.5.2 AdcGroupConversionMode](#452-adcgroupconversionmode)
    - [4.5.3 AdcGroupId](#453-adcgroupid)
    - [4.5.4 AdcGroupPriority](#454-adcgrouppriority)
    - [4.5.5 AdcGroupTriggSrc](#455-adcgrouptriggsrc)
    - [4.5.6 AdcHwTrigTimer](#456-adchwtrigtimer)
    - [4.5.7 AdcNotification](#457-adcnotification)
    - [4.5.8 AdcStreamingBufferMode](#458-adcstreamingbuffermode)
    - [4.5.9 AdcStreamingNumSamples](#459-adcstreamingnumsamples)
    - [4.5.10 AdcGroupDefinition](#4510-adcgroupdefinition)
  - [4.6 AdcHwUnit](#46-adchwunit)
    - [4.6.1 AdcClockSource](#461-adcclocksource)
    - [4.6.2 AdcHwUnitId](#462-adchwunitid)
    - [4.6.3 AdcPrescale](#463-adcprescale)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Adc\_ConfigType](#611-类型定义-adc_configtype)
    - [6.1.2 类型定义 Adc\_InitConfigType](#612-类型定义-adc_initconfigtype)
    - [6.1.3 类型定义 Adc\_HwCfgType](#613-类型定义-adc_hwcfgtype)
    - [6.1.4 类型定义 Adc\_ChannelCfgType](#614-类型定义-adc_channelcfgtype)
    - [6.1.5 类型定义 Adc\_ConChCfgType](#615-类型定义-adc_conchcfgtype)
    - [6.1.6 类型定义 Adc\_GroupCfgType](#616-类型定义-adc_groupcfgtype)
    - [6.1.7 类型定义 Adc\_GroupType](#617-类型定义-adc_grouptype)
    - [6.1.8 类型定义 Adc\_ValueGroupType](#618-类型定义-adc_valuegrouptype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Adc\_Init](#621-adc_init)
    - [6.2.2 Adc\_SetupResultBuffer](#622-adc_setupresultbuffer)
    - [6.2.3 Adc\_DeInit](#623-adc_deinit)
    - [6.2.4 Adc\_StartGroupConversion](#624-adc_startgroupconversion)
    - [6.2.5 Adc\_StopGroupConversion](#625-adc_stopgroupconversion)
    - [6.2.6 Adc\_ReadGroup](#626-adc_readgroup)
    - [6.2.7 Adc\_EnableHardwareTrigger](#627-adc_enablehardwaretrigger)
    - [6.2.8 Adc\_DisableHardwareTrigger](#628-adc_disablehardwaretrigger)
    - [6.2.9 Adc\_EnableGroupNotification](#629-adc_enablegroupnotification)
    - [6.2.10 Adc\_DisableGroupNotification](#6210-adc_disablegroupnotification)
    - [6.2.11 Adc\_GetGroupStatus](#6211-adc_getgroupstatus)
    - [6.2.12 Adc\_GetStreamLastPointer](#6212-adc_getstreamlastpointer)
    - [6.2.13 Adc\_GetVersionInfo](#6213-adc_getversioninfo)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Adc\_IsrProcess](#631-adc_isrprocess)
    - [6.3.2 Adc0\_IsrFromInterrupt](#632-adc0_isrfrominterrupt)
      - [表79 服务请求节点 - ADC硬件资源](#表79-服务请求节点---adc硬件资源)
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
  - [9.2 宏配置](#92-宏配置)
  - [9.3 初始化](#93-初始化)
  - [9.4 软件转换](#94-软件转换)
  - [9.5 硬件触发](#95-硬件触发)
  - [9.6 配置示例](#96-配置示例)
    - [9.6.1 单次转换-软件触发-单值访问](#961-单次转换-软件触发-单值访问)
    - [9.6.2 单次转换-硬件触发-单值访问](#962-单次转换-硬件触发-单值访问)
    - [9.6.3 单次转换-硬件触发-流访问-线性buffer](#963-单次转换-硬件触发-流访问-线性buffer)
    - [9.6.4 单次转换-硬件触发-流访问-环形buffer](#964-单次转换-硬件触发-流访问-环形buffer)
    - [9.6.5 连续转换-软件触发-单值访问](#965-连续转换-软件触发-单值访问)
    - [9.6.6 连续转换-软件触发-流访问-线性buffer](#966-连续转换-软件触发-流访问-线性buffer)
    - [9.6.7 连续转换-软件触发-流访问-环形buffer](#967-连续转换-软件触发-流访问-环形buffer)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)
    - [10.2.1](#1021)

---

# 第1章 引言

本用户手册提供了AUTOSAR CP R22-11的ADC驱动程序的功能、配置参数和API实现的相关信息。ADC的驱动程序初始化并提供对微控制器的通用模数转换器单元的访问。本用户手册旨在帮助用户熟悉ADC驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用ADC驱动程序的文档。
## 1.1 范围

本文档涉及ADC Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- ADC Driver的文件结构
- Driver的配置参数
- 由ADC Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于ADC Driver

## 1.2 缩写

| 缩写                                                              | 解释                                                                                                                                                                                                                                                                                                                                                               |
| :---------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| AUTOSAR                                                           | 汽车汽车开放系统架构                                                                                                                                                                                                                                                                                                                                               |
| DEM                                                               | 诊断事件管理器                                                                                                                                                                                                                                                                                                                                                     |
| DET                                                               | 开发错误跟踪器                                                                                                                                                                                                                                                                                                                                                     |
| ADC                                                               | 模拟数字转换器                                                                                                                                                                                                                                                                                                                                                     |
| MCU                                                               | 微控制器                                                                                                                                                                                                                                                                                                                                                           |
| API                                                               | 应用程序编程接口                                                                                                                                                                                                                                                                                                                                                   |
| HW                                                                | 硬件                                                                                                                                                                                                                                                                                                                                                               |
| SW                                                                | 软件                                                                                                                                                                                                                                                                                                                                                               |
| ADC HW Unit                                                       | 表示微控制器中所有具有“模拟到数字转换”能力的输入电子设备                                                                                                                                                                                                                                                                                                           |
| ADC Module                                                        | ADC基本软件模块ADC Driver，简称ADC Driver                                                                                                                                                                                                                                                                                                                          |
| ADC Channel                                                       | 表示绑定到一个端口引脚的逻辑ADC实体。多个ADC实体可以被映射到相同的端口引脚。                                                                                                                                                                                                                                                                                       |
| ADC Channel Group                                                 | 一组ADC通道连接到相同的ADC硬件单元(例如一个ADC通道，采样和保持和一个A/D转换器)。<br>整个组的转换由一个触发源触发。                                                                                                                                                                                                                                                 |
| ADC Result Buffer <br> (ADC Streaming Buffer,  ADC Stream Buffer) | ADC驱动程序的用户必须为每个组提供一个缓冲区。这个缓冲区 如果是流访问模式，<br>可以保存同一组频道的多个样本。如果选择单接入模式，每组通道一个样本保存在缓冲区中                                                                                                                                                                                                     |
| Software Trigger                                                  | 软件API调用，用于开始转换一个ADC通道组或一个连续ADC通道组转换                                                                                                                                                                                                                                                                                                      |
| Hardware Trigger                                                  | ADC内部触发信号，启动ADC通道组的一次转换。ADC硬件触发器是在ADC硬件内部生成的，<br>例如基于在ADC定时器或触发边缘信号。触发器硬件是紧密耦合的或集成在ADC硬件中。启动ADC不需要任何软件检测到硬件触发器后的通道组转换。<br>注意:如果ADC硬件不支持硬件触发，类似的行为可与GPT/ICU驱动器结合使用软件触发器实现。<br>如GPT定时器通知功能，软件触发ADC通道组可以开始转换。 |
| Conversion Mode                                                   | 单次转换:<br>ADC通道组的转换在触发器和之后执行一次结果被写入指定的结果缓冲区。触发器可以是软件API调用或硬件事件。<br>连续转换:<br>ADC通道组的转换是在a之后连续进行的软件API调用(start)，然后将结果写入指定的结果缓冲区。<br>转换本身是自动运行的(硬件/中断控制)。连续转换可以通过软件API调用停止(停止)。                                                           |
| Sampling Time,Sample Time                                         | 采样模拟值的时间(例如，加载电容，…)                                                                                                                                                                                                                                                                                                                                |
| Conversion Time                                                   | 采样模拟值转换为数字值的时间表示。                                                                                                                                                                                                                                                                                                                                 |
| Acquisition Time                                                  | 采样时间+转换时间                                                                                                                                                                                                                                                                                                                                                  |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of ADC Driver, AUTOSAR_SWS_ADC_Driver.pdf Release R22-11
- [2] Requirements of ADC Driver, AUTOSAR_SRS_ADC_Driver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 ADC Driver概述
KF32微控制器提供多个ADC硬件单元原理将模拟输入值(电压)转换为离散数字值。ADC驱动程序初始化和控制微控制器内部的通用模数转换器单元。驱动程序还为用户提供了初始化结果缓冲区位置以更新转换值的功能。ADC的驱动程序将允许为每个通道组配置队列功能(可选)。

### 2.1 软件硬件模块映射

### 2.2 系统时钟
系统时钟通过MCU驱动程序设置。注意，ADC外设时钟基本上可配置的。有关MCU配置的详细信息，参考用户手册。

### 2.3 PORT
ADC输入通道的端口引脚需要由Port驱动程序配置为模拟输入。
有关PORT配置的详细信息，参考PORT用户手册

### 2.4 TIMER
如果将定时器触发周期转换配置为ADC转换的触发器，则需要TIMER外设。请注意，用户必须确保在其他模块中没有同时使用相同的资源。

### 2.5 DMA
ADC单元配置DMA功能，采集ADC数据使用DMA搬移数据。

### 2.6 ADC中断
ADC单元未配置DMA功能，使用ADC中断，每次单个通道采集。

---

# 第3章 文件结构
本节提供了有关ADC Driver文件和其他相关文件的详细信息。
| Name      | Description                                     |
| :-------- | :---------------------------------------------- |
| Adc.c     | 此文件包含Adc驱动程序的通用功能                 |
| Adc.h     | 此头文件输出Adc驱动程序的宏、类型定义和函数原型 |
| Adc_Cfg.h | 本文在这里声明了Adc驱动程序的配置数据。         |
| Adc_Im.c  | 此文件包含Adc模块所需要的硬件驱动程序           |
| Adc_Im.h  | 此头文件输出Adc驱动程序的宏、类型定义和函数原型 |


-----

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

-----

## 4.2 配置参数变化
本节描述了相对于支持的微控制器的配置参数的变化。ADC Driver在支持的微控制器上没有变化的参数。

-----

## 4.3 AdcGeneral
本节详细描述了ADC Driver提供的配置，包括AUTOSAR ADC Driver规范[1]中描述的配置以及特定于微控制器的配置。

### 4.3.1 AdcDeInitApi
- **名称**: AdcDeInitApi
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.2 AdcDevErrorDetect
- **名称**: AdcDevErrorDetect
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 启用，STD_OFF – 禁用，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.3 AdcEnableQueuing
- **名称**: AdcEnableQueuing
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.4 AdcEnableStartStopGroupApi
- **名称**: AdcEnableStartStopGroupApi
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.5 AdcGrpNotifCapability
- **名称**: AdcGrpNotifCapability
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.6 AdcHwTriggerApi
- **名称**: AdcHwTriggerApi
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.7 AdcLowPowerStatesSupport
- **名称**: AdcLowPowerStatesSupport
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.8 AdcPowerStateAsynchTransitionMode
- **名称**: AdcPowerStateAsynchTransitionMode
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.9 AdcPriorityImplementation
- **名称**: AdcPriorityImplementation
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.10 AdcReadGroupApi
- **名称**: AdcReadGroupApi
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.11 AdcResultAlignment
- **名称**: AdcResultAlignment
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.12 AdcVersionInfoApi
- **名称**: AdcVersionInfoApi
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：STD_ON – 使用固定地址特性，STD_OFF – 不使用预处理宏开关 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

-----
## 4.4 AdcPowerStateConfig

### 4.4.1 AdcPowerState
- **名称**: AdcPowerState
- **来源**: AUTOSAR定义，
- **文件**: Adc_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.4.2 AdcPowerStateReadyCbkRef
- **名称**: AdcPowerStateReadyCbkRef
- **来源**: AUTOSAR定义
- **文件**: Adc_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

-----
## 4.5 AdcChannel

### 4.5.1 AdcGroupAccessMode
- **名称**: AdcGroupAccessMode
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: ADC_ACCESS_MODE_SINGLE –单值访问， ADC_ACCESS_MODE_STREAMING – 流访问
- **配置类别**: 预编译时间 X 所有变体

### 4.5.2 AdcGroupConversionMode
- **名称**: AdcGroupConversionMode
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: ADC_CONV_MODE_ONESHOT –单次模式， ADC_CONV_MODE_CONTINUOUS – 连续模式
- **配置类别**: 预编译时间 X 所有变体

### 4.5.3 AdcGroupId
- **名称**: AdcGroupId
- **来源**: AUTOSAR定义，
- **文件**: Adc_Cfg.h
- **范围**: 0~127
- **配置类别**: 预编译时间 X 所有变体

### 4.5.4 AdcGroupPriority
- **名称**: AdcGroupPriority
- **来源**: AUTOSAR定义，
- **文件**: Adc_Cfg.h
- **范围**: 0~255
- **配置类别**: 预编译时间 X 所有变体

### 4.5.5 AdcGroupTriggSrc
- **名称**: AdcGroupTriggSrc
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: ADC_TRIGG_SRC_HW –硬件触发， ADC_TRIGG_SRC_SW – 软件触发
- **配置类别**: 预编译时间 X 所有变体

### 4.5.6 AdcHwTrigTimer
- **名称**: AdcHwTrigTimer
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: 0~65535
- **配置类别**: 预编译时间 X 所有变体

### 4.5.7 AdcNotification
- **名称**: AdcNotification
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.5.8 AdcStreamingBufferMode
- **名称**: AdcStreamingBufferMode
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: ADC_STREAM_BUFFER_CIRCULAR – 环形buffer，ADC_STREAM_BUFFER_CIRCULAR – 线性buffer
- **配置类别**: 预编译时间 X 所有变体

### 4.5.9 AdcStreamingNumSamples
- **名称**: AdcStreamingNumSamples
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: 1~255
- **配置类别**: 预编译时间 X 所有变体

### 4.5.10 AdcGroupDefinition
- **名称**: AdcGroupDefinition
- **来源**: AUTOSAR定义，
- **文件**: Adc.h
- **范围**: 1~*
- **配置类别**: 预编译时间 X 所有变体

-----
## 4.6 AdcHwUnit

### 4.6.1 AdcClockSource
- **名称**: AdcClockSource
- **来源**: AUTOSAR定义，
- **文件**: Adc_Cfg.h
- **范围**: 0~2
- **配置类别**: 预编译时间 X 所有变体

### 4.6.2 AdcHwUnitId
- **名称**: AdcHwUnitId
- **来源**: AUTOSAR定义，
- **文件**: Adc_Cfg.h
- **范围**: 0~2
- **配置类别**: 预编译时间 X 所有变体

### 4.6.3 AdcPrescale
- **名称**: AdcPrescale
- **来源**: AUTOSAR定义，
- **文件**: Adc_Cfg.h
- **范围**: 0~5
- **配置类别**: 预编译时间 X 所有变体

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: ADC_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Adc.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: ADC_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Adc.h
- **值**: 123
- **描述**: 这个宏给出了ADC驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: ADC_MODULE_INSTANCE
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Adc.h
- **值**: 0
- **描述**: 这个宏给出了ADC驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: ADC_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Adc.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: ADC_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Adc.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: ADC_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Adc.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

-----

# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Adc_ConfigType
- **语法**: Adc_ConfigType
- **类型**: Struct
- **文件**: Adc.h
- **范围**: 
  - **Adc_InitConfigType**
    - AdcSetCfgPtr - ADC单元配置信息 
- **描述**: 此类型定义用于配置ADC的整体配置。此类型的指针在Adc_Init API中用于初始化ADC驱动程序。

### 6.1.2 类型定义 Adc_InitConfigType
- **语法**: Adc_InitConfigType
- **类型**: struct
- **文件**: Adc.h
- **范围**:
  - **Adc_HwCfgType**
    - HwCfgPtr - ADC驱动配置
  - **Adc_ChannelCfgType** 
    - ChCfgPtr - 通道属性配置
  - **Adc_GroupCfgType**
    - GrpCfgPtr - Group配置
  - **uint8**
    - TotGrpsNum - Group总数
- **描述**: 这是包含ADC硬件参数具体配置和Group配置信息数据结构类型。

### 6.1.3 类型定义 Adc_HwCfgType
- **语法**: Adc_HwCfgType
- **类型**: Struct
- **文件**: Adc.h
- **范围**: 
  - **Adc_HWType** 
    - AdcHwId-ADC硬件单元号
  - **Adc_ClockSorceType** 
    - ClkSource- 时钟源
  - **Adc_PrescaleType** 
    - ClkPrescale- 分频系数 
  - **Adc_ResultAlignmentType** 
    - DataAlign- 对齐方式 
  - **Adc_HWType** 
    - RefVol- 参考电压 
- **描述**: ADC驱动配置。

### 6.1.4 类型定义 Adc_ChannelCfgType
- **语法**: Adc_ChannelCfgType
- **类型**: Struct
- **文件**: Adc.h
- **范围**: 
  - **Adc_ConChCfgType** 
    - ConChannelPtr-常规通道配置
- **描述**: 通道属性配置

### 6.1.5 类型定义 Adc_ConChCfgType
- **语法**: Adc_ConChCfgType
- **类型**: Struct
- **文件**: Adc.h
- **范围**: 
  - **Adc_ChannelType** 
    - ConDmaSwitch-DMA开关
- **描述**: 常规通道配置

### 6.1.6 类型定义 Adc_GroupCfgType
- **语法**: Adc_GroupCfgType
- **类型**: Struct
- **文件**: Adc.h
- **范围**: 
  - **Adc_NotifyFcnType** 
    - NotifyFcnPtr-采集完成回调函数配置
  - **Adc_GroupDefType** 
    - GroupDefinition- 采集通道配置，数组0代表采集通道个数，1~N代表采集通道
  - **Adc_TriggerSourceType** 
    - ExternalTrigSource- 触发方式 
  - **Adc_ChannelType** 
    - ExternalTrigSource- 外部触发源配置 
  - **Adc_HwTriggerTimerType** 
    - SamplingIntervalTime- TIMER触发周期 
  - **Adc_HwTriggerTimerType** 
    - TimerNumber- TIMER单元 
  - **Adc_GroupConvModeType** 
    - GrpConvMode- 转换模式 
  - **Adc_GroupAccessModeType** 
    - AccessMode- 访问模式 
  - **Adc_StreamNumSampleType** 
    - StreamNumSample- 采样个数 
  - **Adc_StreamBufferModeType** 
    - StreamBufferMode- BUFFER模式 
  - **uint8** 
    - AdditionalSamplingTime- 额外采样时间 
- **描述**: Group配置

### 6.1.7 类型定义 Adc_GroupType
- **语法**: Adc_GroupType
- **类型**: uint8
- **文件**: Adc.h
- **范围**: 0~0x2F
  - 高四位标识ADC硬件单元号
  - 低四位标识Group序号
- **描述**: 描述指定硬件单元的Group序号。

### 6.1.8 类型定义 Adc_ValueGroupType
- **语法**: Adc_ValueGroupType
- **类型**: uint16
- **文件**: Adc.h
- **范围**: 0-65535
- **描述**: ADC值类型

-----

## 6.2 API函数

### 6.2.1 Adc_Init
- **服务名称**: `Adc_Init`
- **语法**: `void Adc_Init(const Adc_ConfigType *ConfigPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: VersionInfoPtr - 配置参数指针
- **返回值**: 无
- **描述**: ADC模块初始化
- **注意事项**: GrpCfgPtr的Group个数和TotGrpsNum保持一致

### 6.2.2 Adc_SetupResultBuffer
- **服务名称**: `Adc_SetupResultBuffer`
- **语法**: `Std_ReturnType Adc_SetupResultBuffer (Adc_GroupType Group,Adc_ValueGroupType* DataBufferPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x0C
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输入)**: DataBufferPtr-存储Group结果Buffer指针
- **参数(输出)**: 无
- **返回值**: E_OK-设置成功
- **返回值**: E_NOT_OK-设置失败
- **描述**: 设置Group的结果缓冲区
- **注意事项**: 开始转换前，需要先调用该函数设置存储结果；设置的存储结果要覆盖对应Group的通道个数*采样个数

### 6.2.3 Adc_DeInit
- **服务名称**: `Adc_DeInit`
- **语法**: `void Adc_DeInit (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: ADC模块反初始化
- **注意事项**: ADC模块在转换中，如果开启DET检测就不会执行反初始化，并报错；ADC反初始化应该在ADC空闲状态执行 

### 6.2.4 Adc_StartGroupConversion
- **服务名称**: `Adc_StartGroupConversion`
- **语法**: `void Adc_StartGroupConversion (Adc_GroupType Group)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 开始Group转换
- **注意事项**: 无

### 6.2.5 Adc_StopGroupConversion
- **服务名称**: `Adc_StopGroupConversion`
- **语法**: `void Adc_StopGroupConversion (Adc_GroupType Group)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 停止正在转换的Group
- **注意事项**: 如果Group未在转换，开启了DET检测情况下，停止该Group会报错且不执行动作

### 6.2.6 Adc_ReadGroup
- **服务名称**: `Adc_ReadGroup`
- **语法**: `Std_ReturnType Adc_ReadGroup (Adc_GroupType Group,Adc_ValueGroupType* DataBufferPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x04
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输入)**: DataBufferPtr-转换结果存储地址
- **参数(输出)**: 无
- **返回值**: E_OK-读取正确，DataBufferPtr中值有效
- **返回值**: E_OK-有错误，DataBufferPtr中值无效
- **描述**: 读取Group转换结果
- **注意事项**: 读取的内容是最近一次有效转换结果

### 6.2.7 Adc_EnableHardwareTrigger
- **服务名称**: `Adc_EnableHardwareTrigger`
- **语法**: `void Adc_EnableHardwareTrigger (Adc_GroupType Group)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x05
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 使能Group的硬件触发功能
- **注意事项**: Group需要配置成硬件触发源；一个ADC硬件单元触发源和软件触发源不同时存在

### 6.2.8 Adc_DisableHardwareTrigger
- **服务名称**: `Adc_DisableHardwareTrigger`
- **语法**: `void Adc_DisableHardwareTrigger (Adc_GroupType Group)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x06
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 关闭Group的硬件触发功能
- **注意事项**: Group需要配置成硬件触发源；一个ADC硬件单元触发源和软件触发源不同时存在

### 6.2.9 Adc_EnableGroupNotification
- **服务名称**: `Adc_EnableGroupNotification`
- **语法**: `void Adc_EnableGroupNotification (Adc_GroupType Group)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x07
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**:Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 使能Group的转换完成通知功能
- **注意事项**: Group需要配置通知函数

### 6.2.10 Adc_DisableGroupNotification
- **服务名称**: `Adc_DisableGroupNotification`
- **语法**: `void Adc_DisableGroupNotification (Adc_GroupType Group)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x08
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 关闭Group的转换完成通知功能
- **注意事项**: Group需要配置通知函数

### 6.2.11 Adc_GetGroupStatus
- **服务名称**: `Adc_GetGroupStatus`
- **语法**: `Adc_StatusType Adc_GetGroupStatus (Adc_GroupType Group)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x09
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**:Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: 无
- **返回值**: ADC_IDLE-空闲状态
- **返回值**: ADC_BUSY-正在转换中
- **返回值**: ADC_COMPLETED-完成一次Group所有通道转换完成
- **返回值**: ADC_STREAM_COMPLETED-完成采样个数
- **描述**: 获取Group的转换状态
- **注意事项**: 无

### 6.2.12 Adc_GetStreamLastPointer
- **服务名称**: `Adc_GetStreamLastPointer`
- **语法**: `Adc_StreamNumSampleType Adc_GetStreamLastPointer (Adc_GroupType Group,Adc_ValueGroupType** PtrToSamplePtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0B
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**:Group-高四位是ADC硬件编号，低四位是Group真实ID
- **参数(输出)**: PtrToSamplePtr-二级指针，指向的地址是Adc_SetupResultBuffer的地址值
- **返回值**: 已完成采样次数；未转换完或出错情况，返回值是0，0的时候PtrToSamplePtr是空指针
- **描述**: 获取Group的转换状态
- **注意事项**: 当Group设置1个以上采样点的时候，PtrToSamplePtr的内容是需要用户自己跳着采样点个数取值，指针内的值不是Group通道连续值

### 6.2.13 Adc_GetVersionInfo
- **服务名称**: `Adc_GetVersionInfo`
- **语法**: `void Adc_GetVersionInfo (Std_VersionInfoType* versioninfo)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0A
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:无
- **参数(输出)**: versioninfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无

-----
## 6.3 中断处理

中断服务例程在ADC Driver中用于通知、更新采集值、自动开启下一次转换。

### 6.3.1 Adc_IsrProcess
- **服务名称**Adc_IsrProcess
- **语法**：`void Adc_IsrProcess (uint8 AdcHwId)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：`AdcHwId` - ADC通道编号
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
   - 调用通知
   - 更新采集数
   - 据根据配置自动开启下一次转换
- **警告**：无
- **配置**：如果需要从中断例程通知，则应将ADC_GRP_NOTIFY_CAPABILITY设置为STD_ON。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有4个SRN（服务请求节点）用于服务ADC通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

### 6.3.2 Adc0_IsrFromInterrupt
- **服务名称**Adc0_IsrFromInterrupt
- **语法**：`void Adc0_IsrFromInterrupt(void)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：无
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
   - 调用通知
   - 更新采集数
   - 据根据配置自动开启下一次转换
- **警告**：无
- **配置**：如果需要从中断例程通知，则应将ADC_GRP_NOTIFY_CAPABILITY设置为STD_ON。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有4个SRN（服务请求节点）用于服务ADC通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - ADC硬件资源

| 硬件资源            | SRN编号                |
| ------------------- | ---------------------- |
| ADC_CONFIG_MODULE_0 | ADC0_UNIFIED_INTERRUPT |
| ADC_CONFIG_MODULE_1 | ADC1_UNIFIED_INTERRUPT |
| DMA1                | DMA1_UNIFIED_INTERRUPT |

-----

## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

ADC Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是ADC Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                  | 类型/范围                  | 描述                       |
| --------------------- | -------------------------- | -------------------------- |
| Adc_ConfigPtr         | Adc_ConfigType             | ADC Driver配置结构的指针。 |
| Adc_InitStatus        | uint8                      | ADC初始化状态              |
| Adc_StreamBufferLocal | Adc_ValueGroupType         | ADC使用DMA缓存转换值       |
| Adc_DmaInitStatus     | uint8                      | DMA使用状态                |
| Adc_TimerResetState   | uint8 []                   | TIMER复位状态              |
| Adc_CcpUnitPtr        | GeneralTimer_RegisterMap_t | TIMER单元硬件地址          |
| Adc_DmaConfig         | Adc_DmaUserInfoType        | DMA单元硬件地址            |
| Adc_AdcUnitPtr        | Adc_RegisterMap_t          | ADC单元硬件地址            |
| Adc_GroupConvertInfo  | Adc_GroupRstDataType       | ADC转换状态                |
| Adc_HwIdIndex         | uint8                      | ADC索引                    |
| Adc0_InterConut       | uint8                      | ADC0中断计数               |
| Adc1_InterConut       | uint8                      | ADC1中断计数               |
| Adc2_InterConut       | uint8                      | ADC2中断计数               |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是ADC Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                        | 错误描述                     | 值（十六进制） |
| ------------------------------- | ---------------------------- | -------------- |
| ADC_E_DET_NO_ERR                | 无错误                       | 0x00           |
| ADC_E_UNINIT                    | 未初始化                     | 0x0A           |
| ADC_E_BUSY                      | ADC忙                        | 0x0B           |
| ADC_E_IDLE                      | 空闲                         | 0x0C           |
| ADC_E_ALREADY_INITIALIZED       | 重复初始化                   | 0x0D           |
| ADC_E_PARAM_CONFIG              | 参数空错误                   | 0x0E           |
| ADC_E_PARAM_POINTER             | 无效指针                     | 0x14           |
| ADC_E_PARAM_GROUP               | Group参数错误                | 0x15           |
| ADC_E_WRONG_CONV_MODE           | 模式错误                     | 0x16           |
| ADC_E_WRONG_TRIGG_SRC           | 错误触发源                   | 0x17           |
| ADC_E_NOTIF_CAPABILITY          | 通知函数空                   | 0x18           |
| ADC_E_BUFFER_UNINIT             | 结果缓冲区未初始化           | 0x19           |
| ADC_E_NOT_DISENGAGED            | 多个Group不处于IDLE状态      | 0x1A           |
| ADC_E_POWER_STATE_NOT_SUPPORTED | 功耗不支持                   | 0x18           |
| ADC_E_STARTGROUPCONV            | Group软件使能状态不支持start | 0x1E           |
| ADC_E_STATUS_ENABLEHWTRIGGER    | Group硬件触状态不支持start   | 0x1F           |
| ADC_E_WRONG_TRIGG_CFG           | Group错误的触发配置          | 0x20           |

-----
# 第9章 示例用法
本章描述了如何配置ADC驱动器以及如何在应用程序中使用ADC驱动器提供的不同的API。

## 9.1 驱动器配置
按照以下指南正确配置ADC驱动器：
- MCU驱动器：配置系统时钟。
- 中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级
- ADC驱动器：选择所需的API配置开关。

## 9.2 宏配置

```c
#define ADC_DEV_ERROR_DETECT (STD_OFF)
#define ADC_LOW_POWER_STATES_SUPPORT (STD_OFF)
#define ADC_DEINIT_API (STD_ON)
#define ADC_GRP_NOTIFY_CAPABILITY (STD_ON)
#define ADC_HW_TRIGGER_API (STD_ON)
#define ADC_VERSION_INFO_API (STD_ON)
#define ADC_PB_FIXED_ADDRESS (STD_ON)
#define ADC_PRIORITY_IMPLEMENTATION (ADC_PRIORITY_NONE)
#define ADC_RESULT_ALIGNMENT (ADC_ALIGN_RIGHT)
#define ADC_RESET_SFR_INIT (STD_ON)

```
## 9.3 初始化

- 关闭固定配置情
```c
#define ADC_PB_FIXED_ADDRESS (STD_OFF)

Adc_Init(&Adc_ConfigPredefined);

```
- 打开固定配置
```c
#define ADC_PB_FIXED_ADDRESS (STD_ON)

Adc_Init(NULL_PTR);
```

## 9.4 软件转换

设置结果缓冲区、使能通知、开始软件转换、获取状态、读取值
```c

Adc_SetupResultBuffer(ADC_CONFIG_GROUP_ADC0_GROUP0,&AdcResultBuffer[0U]);
Adc_EnableGroupNotification(ADC_CONFIG_GROUP_ADC0_GROUP0);
Adc_StartGroupConversion(ADC_CONFIG_GROUP_ADC0_GROUP0);
while(Adc_GetGroupStatus(ADC_CONFIG_GROUP_ADC0_GROUP0) != ADC_STREAM_COMPLETED)
{
    ;
}
Adc_ReadGroup(ADC_CONFIG_GROUP_ADC0_GROUP0,&AdcReadBuffer[0U]);
```
## 9.5 硬件触发

设置结果缓冲区、使能通知、使能硬件触发、获取状态、读取值
```c

Adc_SetupResultBuffer(ADC_CONFIG_GROUP_ADC0_GROUP0,&AdcResultBuffer[0U]);
Adc_EnableGroupNotification(ADC_CONFIG_GROUP_ADC0_GROUP0);
Adc_EnableHardwareTrigger(ADC_CONFIG_GROUP_ADC0_GROUP0);
while(Adc_GetGroupStatus(ADC_CONFIG_GROUP_ADC0_GROUP0) != ADC_STREAM_COMPLETED)
{
    ;
}
Adc_ReadGroup(ADC_CONFIG_GROUP_ADC0_GROUP0,&AdcReadBuffer[0U]);
```
## 9.6 配置示例

### 9.6.1 单次转换-软件触发-单值访问
配置ADC0时钟源高频外设、64分频、数据右对齐、参考电压AVDD、使用DMA、Group0配置单次转换-软件触发-单值访问

```c

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType kvAdc_Adc0Group2[5U] = {
  4U, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_72, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_71, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112};

#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
/**
 * @brief notify function
 * @retval void
 * @return void
 */
void Adc_Adc0Group0Notify(void)
{
    ;
}
#endif

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg0[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
      /* Notification function pointer */
      .NotifyFcnPtr = Adc_Adc0Group0Notify,
#endif
      /* Assignment of channels to a channel group */
      /* First element is the number of configured channels in the group */
      /* From Second element will give the channel ID */
      .GroupDefinition = &kvAdc_Adc0Group0[0U],
      /* Group trigger source : SW / HW */
      .TriggerSrc = ADC_TRIGG_SRC_SW,
#if (ADC_HW_TRIGGER_API == STD_ON)
      /** external trigger event */
      .ExternalTrigSource = ADC_CFG_EXTTRIG_RESERVED,
      /** sampling interval timer,milliseconds */
      .SamplingIntervalTime = 0U,
      /** Timer number */
      .TimerNumber = ADC_EXTTRIG_TIMER_RESERVED,
#endif
      /* Group conversion mode */
      .GrpConvMode = ADC_CONV_MODE_ONESHOT,
      /* Single access mode */
      .AccessMode = ADC_ACCESS_MODE_SINGLE,
      /* Number of ADC values to be acquired in streaming access mode */
      .StreamNumSample = 1U,
      /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
      .StreamBufferMode = ADC_STREAM_BUFFER_LINEAR,
      /* Additional sampling time configuration */
      .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_256_ADCCLK,
    }};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg0 = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
  }};

/**
 * @brief adc 0 hw config infomation
 */
static const Adc_HwCfgType Adc_Adc0HwCfg0 = {
  .AdcHwId     = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_64,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol      = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr   = &Adc_Adc0HwCfg0,
        .ChCfgPtr   = &Adc_Adc0ChCfg0,
        .GrpCfgPtr  = &Adc_Adc0GrpCfg0[0U],
        .TotGrpsNum = 1U,
      },
    [1U] = NULL_PTR}};
```
### 9.6.2 单次转换-硬件触发-单值访问
配置ADC0时钟源高频外设、64分频、数据右对齐、参考电压AVDD、使用DMA、Group0配置单次转换-硬件触发-单值访问、使用TIMER1、100ms触发一次

```c

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType kvAdc_Adc0Group2[5U] = {
  4U, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_72, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_71, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112};

#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
/**
 * @brief notify function
 * @retval void
 * @return void
 */
void Adc_Adc0Group0Notify(void)
{
    ;
}
#endif

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg0[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
      /* Notification function pointer */
      .NotifyFcnPtr = Adc_Adc0Group0Notify,
#endif
      /* Assignment of channels to a channel group */
      /* First element is the number of configured channels in the group */
      /* From Second element will give the channel ID */
      .GroupDefinition = &kvAdc_Adc0Group0[0U],
      /* Group trigger source : SW / HW */
      .TriggerSrc = ADC_TRIGG_SRC_HW,
#if (ADC_HW_TRIGGER_API == STD_ON)
      /** external trigger event */
      .ExternalTrigSource = ADC_CFG_EXTTRIG_T1TRGO,
      /** sampling interval timer,milliseconds */
      .SamplingIntervalTime = 100U,
      /** Timer number */
      .TimerNumber = ADC_EXTTRIG_TIMER_1,
#endif
      /* Group conversion mode */
      .GrpConvMode = ADC_CONV_MODE_ONESHOT,
      /* Single access mode */
      .AccessMode = ADC_ACCESS_MODE_SINGLE,
      /* Number of ADC values to be acquired in streaming access mode */
      .StreamNumSample = 1U,
      /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
      .StreamBufferMode = ADC_STREAM_BUFFER_LINEAR,
      /* Additional sampling time configuration */
      .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_256_ADCCLK,
    }};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg0 = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
  }};

/**
 * @brief adc 0 hw config infomation
 */
static const Adc_HwCfgType Adc_Adc0HwCfg0 = {
  .AdcHwId     = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_64,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol      = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr   = &Adc_Adc0HwCfg0,
        .ChCfgPtr   = &Adc_Adc0ChCfg0,
        .GrpCfgPtr  = &Adc_Adc0GrpCfg0[0U],
        .TotGrpsNum = 1U,
      },
    [1U] = NULL_PTR}};
```

### 9.6.3 单次转换-硬件触发-流访问-线性buffer
配置ADC0时钟源高频外设、64分频、数据右对齐、参考电压AVDD、使用DMA、Group0配置单次转换-硬件触发-流访问-线性buffe、使用TIMER1、100ms触发一次、采样点个数3

```c

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType kvAdc_Adc0Group2[5U] = {
  4U, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_72, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_71, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112};

#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
/**
 * @brief notify function
 * @retval void
 * @return void
 */
void Adc_Adc0Group0Notify(void)
{
    ;
}
#endif

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg0[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
      /* Notification function pointer */
      .NotifyFcnPtr = Adc_Adc0Group0Notify,
#endif
      /* Assignment of channels to a channel group */
      /* First element is the number of configured channels in the group */
      /* From Second element will give the channel ID */
      .GroupDefinition = &kvAdc_Adc0Group0[0U],
      /* Group trigger source : SW / HW */
      .TriggerSrc = ADC_TRIGG_SRC_HW,
#if (ADC_HW_TRIGGER_API == STD_ON)
      /** external trigger event */
      .ExternalTrigSource = ADC_CFG_EXTTRIG_T1TRGO,
      /** sampling interval timer,milliseconds */
      .SamplingIntervalTime = 100U,
      /** Timer number */
      .TimerNumber = ADC_EXTTRIG_TIMER_1,
#endif
      /* Group conversion mode */
      .GrpConvMode = ADC_CONV_MODE_ONESHOT,
      /* Single access mode */
      .AccessMode = ADC_ACCESS_MODE_STREAMING,
      /* Number of ADC values to be acquired in streaming access mode */
      .StreamNumSample = 3U,
      /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
      .StreamBufferMode = ADC_STREAM_BUFFER_LINEAR,
      /* Additional sampling time configuration */
      .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_256_ADCCLK,
    }};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg0 = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
  }};

/**
 * @brief adc 0 hw config infomation
 */
static const Adc_HwCfgType Adc_Adc0HwCfg0 = {
  .AdcHwId     = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_64,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol      = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr   = &Adc_Adc0HwCfg0,
        .ChCfgPtr   = &Adc_Adc0ChCfg0,
        .GrpCfgPtr  = &Adc_Adc0GrpCfg0[0U],
        .TotGrpsNum = 1U,
      },
    [1U] = NULL_PTR}};
```
### 9.6.4 单次转换-硬件触发-流访问-环形buffer
配置ADC0时钟源高频外设、64分频、数据右对齐、参考电压AVDD、使用DMA、Group0配置单次转换-硬件触发-流访问-环形buffe、使用TIMER1、100ms触发一次、采样点个数3

```c

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType kvAdc_Adc0Group2[5U] = {
  4U, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_72, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_71, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112};

#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
/**
 * @brief notify function
 * @retval void
 * @return void
 */
void Adc_Adc0Group0Notify(void)
{
    ;
}
#endif

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg0[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
      /* Notification function pointer */
      .NotifyFcnPtr = Adc_Adc0Group0Notify,
#endif
      /* Assignment of channels to a channel group */
      /* First element is the number of configured channels in the group */
      /* From Second element will give the channel ID */
      .GroupDefinition = &kvAdc_Adc0Group0[0U],
      /* Group trigger source : SW / HW */
      .TriggerSrc = ADC_TRIGG_SRC_HW,
#if (ADC_HW_TRIGGER_API == STD_ON)
      /** external trigger event */
      .ExternalTrigSource = ADC_CFG_EXTTRIG_T1TRGO,
      /** sampling interval timer,milliseconds */
      .SamplingIntervalTime = 100U,
      /** Timer number */
      .TimerNumber = ADC_EXTTRIG_TIMER_1,
#endif
      /* Group conversion mode */
      .GrpConvMode = ADC_CONV_MODE_ONESHOT,
      /* Single access mode */
      .AccessMode = ADC_ACCESS_MODE_STREAMING,
      /* Number of ADC values to be acquired in streaming access mode */
      .StreamNumSample = 3U,
      /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
      .StreamBufferMode = ADC_STREAM_BUFFER_CIRCULAR,
      /* Additional sampling time configuration */
      .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_256_ADCCLK,
    }};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg0 = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
  }};

/**
 * @brief adc 0 hw config infomation
 */
static const Adc_HwCfgType Adc_Adc0HwCfg0 = {
  .AdcHwId     = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_64,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol      = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr   = &Adc_Adc0HwCfg0,
        .ChCfgPtr   = &Adc_Adc0ChCfg0,
        .GrpCfgPtr  = &Adc_Adc0GrpCfg0[0U],
        .TotGrpsNum = 1U,
      },
    [1U] = NULL_PTR}};
```
### 9.6.5 连续转换-软件触发-单值访问
配置ADC0时钟源高频外设、64分频、数据右对齐、参考电压AVDD、使用DMA、Group0配置连续转换-软件触发-单值访问

```c

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType kvAdc_Adc0Group2[5U] = {
  4U, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_72, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_71, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112};

#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
/**
 * @brief notify function
 * @retval void
 * @return void
 */
void Adc_Adc0Group0Notify(void)
{
    ;
}
#endif

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg0[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
      /* Notification function pointer */
      .NotifyFcnPtr = Adc_Adc0Group0Notify,
#endif
      /* Assignment of channels to a channel group */
      /* First element is the number of configured channels in the group */
      /* From Second element will give the channel ID */
      .GroupDefinition = &kvAdc_Adc0Group0[0U],
      /* Group trigger source : SW / HW */
      .TriggerSrc = ADC_TRIGG_SRC_SW,
#if (ADC_HW_TRIGGER_API == STD_ON)
      /** external trigger event */
      .ExternalTrigSource = ADC_CFG_EXTTRIG_RESERVED,
      /** sampling interval timer,milliseconds */
      .SamplingIntervalTime = 0U,
      /** Timer number */
      .TimerNumber = ADC_EXTTRIG_TIMER_RESERVED,
#endif
      /* Group conversion mode */
      .GrpConvMode = ADC_CONV_MODE_CONTINUOUS,
      /* Single access mode */
      .AccessMode = ADC_ACCESS_MODE_SINGLE,
      /* Number of ADC values to be acquired in streaming access mode */
      .StreamNumSample = 1U,
      /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
      .StreamBufferMode = ADC_STREAM_BUFFER_LINEAR,
      /* Additional sampling time configuration */
      .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_256_ADCCLK,
    }};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg0 = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
  }};

/**
 * @brief adc 0 hw config infomation
 */
static const Adc_HwCfgType Adc_Adc0HwCfg0 = {
  .AdcHwId     = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_64,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol      = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr   = &Adc_Adc0HwCfg0,
        .ChCfgPtr   = &Adc_Adc0ChCfg0,
        .GrpCfgPtr  = &Adc_Adc0GrpCfg0[0U],
        .TotGrpsNum = 1U,
      },
    [1U] = NULL_PTR}};
```
### 9.6.6 连续转换-软件触发-流访问-线性buffer
配置ADC0时钟源高频外设、64分频、数据右对齐、参考电压AVDD、使用DMA、Group0配置连续转换-软件触发--流访问-线性buffer
采样点个数3

```c

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType kvAdc_Adc0Group2[5U] = {
  4U, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_72, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_71, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112};

#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
/**
 * @brief notify function
 * @retval void
 * @return void
 */
void Adc_Adc0Group0Notify(void)
{
    ;
}
#endif

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg0[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
      /* Notification function pointer */
      .NotifyFcnPtr = Adc_Adc0Group0Notify,
#endif
      /* Assignment of channels to a channel group */
      /* First element is the number of configured channels in the group */
      /* From Second element will give the channel ID */
      .GroupDefinition = &kvAdc_Adc0Group0[0U],
      /* Group trigger source : SW / HW */
      .TriggerSrc = ADC_TRIGG_SRC_SW,
#if (ADC_HW_TRIGGER_API == STD_ON)
      /** external trigger event */
      .ExternalTrigSource = ADC_CFG_EXTTRIG_RESERVED,
      /** sampling interval timer,milliseconds */
      .SamplingIntervalTime = 0U,
      /** Timer number */
      .TimerNumber = ADC_EXTTRIG_TIMER_RESERVED,
#endif
      /* Group conversion mode */
      .GrpConvMode = ADC_CONV_MODE_CONTINUOUS,
      /* Single access mode */
      .AccessMode = ADC_ACCESS_MODE_STREAMING,
      /* Number of ADC values to be acquired in streaming access mode */
      .StreamNumSample = 3U,
      /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
      .StreamBufferMode = ADC_STREAM_BUFFER_LINEAR,
      /* Additional sampling time configuration */
      .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_256_ADCCLK,
    }};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg0 = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
  }};

/**
 * @brief adc 0 hw config infomation
 */
static const Adc_HwCfgType Adc_Adc0HwCfg0 = {
  .AdcHwId     = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_64,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol      = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr   = &Adc_Adc0HwCfg0,
        .ChCfgPtr   = &Adc_Adc0ChCfg0,
        .GrpCfgPtr  = &Adc_Adc0GrpCfg0[0U],
        .TotGrpsNum = 1U,
      },
    [1U] = NULL_PTR}};
```
### 9.6.7 连续转换-软件触发-流访问-环形buffer
配置ADC0时钟源高频外设、64分频、数据右对齐、参考电压AVDD、使用DMA、Group0配置连续转换-软件触发--流访问-环形buffer
采样点个数3

```c

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType kvAdc_Adc0Group2[5U] = {
  4U, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_72, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_71, (Adc_GroupDefType)ADC_CONFIG_CHANNEL_112};

#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
/**
 * @brief notify function
 * @retval void
 * @return void
 */
void Adc_Adc0Group0Notify(void)
{
    ;
}
#endif

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg0[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
      /* Notification function pointer */
      .NotifyFcnPtr = Adc_Adc0Group0Notify,
#endif
      /* Assignment of channels to a channel group */
      /* First element is the number of configured channels in the group */
      /* From Second element will give the channel ID */
      .GroupDefinition = &kvAdc_Adc0Group0[0U],
      /* Group trigger source : SW / HW */
      .TriggerSrc = ADC_TRIGG_SRC_SW,
#if (ADC_HW_TRIGGER_API == STD_ON)
      /** external trigger event */
      .ExternalTrigSource = ADC_CFG_EXTTRIG_RESERVED,
      /** sampling interval timer,milliseconds */
      .SamplingIntervalTime = 0U,
      /** Timer number */
      .TimerNumber = ADC_EXTTRIG_TIMER_RESERVED,
#endif
      /* Group conversion mode */
      .GrpConvMode = ADC_CONV_MODE_CONTINUOUS,
      /* Single access mode */
      .AccessMode = ADC_ACCESS_MODE_STREAMING,
      /* Number of ADC values to be acquired in streaming access mode */
      .StreamNumSample = 3U,
      /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
      .StreamBufferMode = ADC_STREAM_BUFFER_CIRCULAR,
      /* Additional sampling time configuration */
      .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_256_ADCCLK,
    }};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg0 = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
  }};

/**
 * @brief adc 0 hw config infomation
 */
static const Adc_HwCfgType Adc_Adc0HwCfg0 = {
  .AdcHwId     = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_64,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol      = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr   = &Adc_Adc0HwCfg0,
        .ChCfgPtr   = &Adc_Adc0ChCfg0,
        .GrpCfgPtr  = &Adc_Adc0GrpCfg0[0U],
        .TotGrpsNum = 1U,
      },
    [1U] = NULL_PTR}};
```

-----

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 表82 假设

| 序号 | 参考 | 假设                                                                                                                    |
| ---- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| 1    | 通用 | Adc_StartGroupConversion或Adc_EnableHardwareTrigger 仅在调用 Adc_SetupResultBuffer 后被调用，以确保转换结果有存放地址。 |
| 2    | 通用 | 如果预期持续时间的超时值非常低，并且没有足够的时间让 ISR 完成，则存在丢失事件/错误通知的更高可能性。                    |

### 偏差



### 考虑的Bugzilla

- Dem_EventStatusType 被添加到导入的类型中。
- ADC Driver 模式在 Adc_Init 执行后被设置为 ADC_INITIALIZED_STATUS
- 功耗功能未实现。
- Group优先级未实现。


## 10.2 限制

### 10.2.1 



