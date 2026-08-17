# ChipOn Microcontroller Abstract Layer Users Manual - I2C Driver
Release V0.1 - May 2024  
Published by ChipOn 

---

## 变更记录


| 时间       | 版本 | 变更记录    |
| :--------- | :--- | :---------- |
| 2024-08-08 | 0.1  | 初       版 |


----

<a name="br4"></a> 



## 目录
- [ChipOn Microcontroller Abstract Layer Users Manual - I2C Driver](#chipon-microcontroller-abstract-layer-users-manual---i2c-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 I2C Driver概述](#第2章-i2c-driver概述)
    - [2.1 I2C](#21-i2c)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 I2CGeneral](#43-i2cgeneral)
    - [4.3.1 I2C\_PB\_FIXEDADDR](#431-i2c_pb_fixedaddr)
    - [4.3.2 I2C\_DEV\_ERROR\_DETECT](#432-i2c_dev_error_detect)
    - [4.3.3 I2C\_ASYNC\_READ\_OR\_WRITE](#433-i2c_async_read_or_write)
    - [4.3.4 I2C\_VERSION\_INFO\_API](#434-i2c_version_info_api)
  - [4.4 I2cChannel](#44-i2cchannel)
    - [4.4.1 I2c\_DataType](#441-i2c_datatype)
    - [4.4.2 I2c\_DeviceRegAddrLenType](#442-i2c_deviceregaddrlentype)
    - [4.4.3 I2c\_DeviceDataNumberType](#443-i2c_devicedatanumbertype)
    - [4.4.4 I2c\_DeviceRegAddrType](#444-i2c_deviceregaddrtype)
    - [4.4.5 I2c\_DeviceAddrType](#445-i2c_deviceaddrtype)
    - [4.4.6 I2c\_HwUnitType](#446-i2c_hwunittype)
    - [4.4.7 I2c\_PacketType](#447-i2c_packettype)
    - [4.4.8 I2c\_IndexType](#448-i2c_indextype)
    - [4.4.9 I2C\_MasterEventType](#449-i2c_mastereventtype)
    - [4.4.10 I2c\_ConfigClockSourceType](#4410-i2c_configclocksourcetype)
    - [4.4.11 I2c\_ConfigClockDriverType](#4411-i2c_configclockdrivertype)
    - [4.4.12 I2c\_ConfigModeType](#4412-i2c_configmodetype)
    - [4.4.12 I2c\_ConfigModeType](#4412-i2c_configmodetype-1)
    - [4.4.13 I2c\_StatusType](#4413-i2c_statustype)
    - [4.4.14 I2c\_PacketResultType](#4414-i2c_packetresulttype)
    - [4.4.15 I2c\_CommModeType](#4415-i2c_commmodetype)
    - [4.4.16 I2c\_OperationType](#4416-i2c_operationtype)
    - [4.4.17 I2c\_PacketOperationType](#4417-i2c_packetoperationtype)
    - [4.4.18 I2c\_DeviceAddrModeType](#4418-i2c_deviceaddrmodetype)
    - [4.4.19 I2c\_PacketRegAddrInfoType](#4419-i2c_packetregaddrinfotype)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 SwMajorVersion](#53-swmajorversion)
  - [5.4 SwMinorVersion](#54-swminorversion)
  - [5.5 SwPatchVersion](#55-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 I2c\_ConfigType](#611-类型定义-i2c_configtype)
    - [6.1.2 类型定义 I2c\_PacketConfigType](#612-类型定义-i2c_packetconfigtype)
    - [6.1.3 类型定义 I2c\_HWModuleConfigType](#613-类型定义-i2c_hwmoduleconfigtype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 I2c\_Init](#621-i2c_init)
    - [6.2.2 I2c\_DeInit](#622-i2c_deinit)
    - [6.2.3 I2c\_SetupPacket](#623-i2c_setuppacket)
    - [6.2.4 I2c\_SyncOperation](#624-i2c_syncoperation)
    - [6.2.5 I2c\_AsyncOperation](#625-i2c_asyncoperation)
    - [6.2.6 I2c\_GetStatus](#626-i2c_getstatus)
    - [6.2.7 I2c\_GetPacketResult](#627-i2c_getpacketresult)
    - [6.2.8 I2c\_GetVersionInfo](#628-i2c_getversioninfo)
    - [6.2.9 I2c\_UpdatePacketRegInfo](#629-i2c_updatepacketreginfo)
    - [6.2.10 I2c\_GetPacketRegInfo](#6210-i2c_getpacketreginfo)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 I2c\_IsrProtocol](#631-i2c_isrprotocol)
      - [表79 服务请求节点 - I2C硬件资源](#表79-服务请求节点---i2c硬件资源)
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
  - [9.3 接口使用示例](#93-接口使用示例)
      - [9.3.1 同步操作](#931-同步操作)
      - [9.3.2 异步操作](#932-异步操作)
  - [9.4 配置示例](#94-配置示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)
    - [10.2.1](#1021)

---

# 第1章 引言

本用户手册提供了I2C驱动程序的功能和API实现的相关信息。本用户手册旨在帮助用户熟悉I2C驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用I2C驱动程序的文档。

## 1.1 范围

本文档介绍I2C驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- I2C Driver的文件结构
- 由I2C Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于I2C Driver

## 1.2 缩写

| 缩写 | 解释                 |
| :--- | :------------------- |
|      | 汽车汽车开放系统架构 |
| API  | 应用程序接口         |
| I2C  | 内部集成电路总线     |
| ALU  | 算术逻辑单元         |
| DEM  | 诊断事件管理器       |
| DET  | 开发错误跟踪器       |
| BSW  | 基础软件             |
| HW   | 硬件                 |
| ID   | 标识符               |
| MCAL | 微控制器抽象层       |
| MCU  | 微控制器             |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] KF32A158xxxSF用户手册V1.0
- [2] KF32A158xxxSF数据手册V1.3

-----
# 第2章 I2C Driver概述
KF32微控制器提供I2C操作方式。

### 2.1 I2C
I2C使用的引脚需要由Port驱动程序配置。
有关PORT配置的详细信息，参考PORT用户手册

-----

# 第3章 文件结构
本节提供了有关I2C Driver文件和其他相关文件的详细信息。
| Name              | Description                             |
| :---------------- | :-------------------------------------- |
| I2c.c             | 此文件包含I2C驱动程序的通用功能         |
| I2c.h             | 此头文件输出I2C驱动程序的宏和函数原型   |
| I2c_Im.c          | 模块芯片适配层接口实现文件              |
| I2c_Im.h          | 模块芯片适配层接口文件                  |
| I2c_Types.h       | 类型定义                                |
| I2c_IrqProtocol.c | I2C异步接口函数功能                     |
| I2c_IrqProtocol.h | I2C异步接口函数声明                     |
| I2c_LCfg.c        | I2C配置示例                             |
| I2c_Cfg.h         | 本文在这里声明了I2C驱动程序的配置数据。 |


-----

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
本节描述了相对于支持的微控制器的配置参数的变化。I2C Driver在支持的微控制器上没有变化的参数。

## 4.3 I2CGeneral

### 4.3.1 I2C_PB_FIXEDADDR
- **名称**: I2C_PB_FIXEDADDR
- **来源**: 
- **文件**: I2c_Cfg.h
- **范围**: 值：STD_ON/STD_OFF ，默认值：STD_OFF
- **配置类别**: 预编译时 
- **描述**: 选择I2C驱动程序是否支持预编译时

### 4.3.2 I2C_DEV_ERROR_DETECT
- **名称**: I2C_DEV_ERROR_DETECT
- **来源**: 
- **文件**: I2c_Cfg.h
- **范围**: 值：STD_ON – 使能检查和通知，STD_OFF – 使能检查和通知 ，默认值：STD_OFF
- **配置类别**: 预编译时 
- **描述**: 使能开发错误检测和通知

### 4.3.3 I2C_ASYNC_READ_OR_WRITE
- **名称**: I2C_ASYNC_READ_OR_WRITE
- **来源**: 
- **文件**: I2c_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时 
- **描述**: 异步接口开关

### 4.3.4 I2C_VERSION_INFO_API
- **名称**: I2C_VERSION_INFO_API
- **来源**: 
- **文件**: I2c_Cfg.h
- **范围**: 值：使能API – STD_ON，不使能API – STD_OFF，默认值：STD_ON
- **配置类别**: 预编译时 
- **描述**: I2c_GetVersionInfo函数开关

## 4.4 I2cChannel

### 4.4.1 I2c_DataType
- **名称**: I2c_DataType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：0 .. 255
- **配置类别**: 预编译时 
- **描述**: I2C数据类型

### 4.4.2 I2c_DeviceRegAddrLenType
- **名称**: I2c_DeviceRegAddrLenType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：0 .. 255
- **配置类别**: 预编译时/构建后
- **描述**: I2C寄存器地址长度类型

### 4.4.3 I2c_DeviceDataNumberType
- **名称**: I2c_DeviceDataNumberType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：0 .. 65535
- **配置类别**: 预编译时 /构建后
- **描述**: I2C数据长度类型

### 4.4.4 I2c_DeviceRegAddrType
- **名称**: I2c_DeviceRegAddrType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：0 .. 4,294,967,295
- **配置类别**: 预编译时/构建后
- **描述**: I2C外设和寄存器地址类型

### 4.4.5 I2c_DeviceAddrType
- **名称**: I2c_DeviceAddrType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：0 .. 65535
- **配置类别**: 预编译时/构建后 
- **描述**: 信号通知函数

### 4.4.6 I2c_HwUnitType
- **名称**: I2c_HwUnitType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：0 .. 255
- **配置类别**: 预编译时/构建后 
- **描述**: I2C硬件单元

### 4.4.7 I2c_PacketType
- **名称**: I2c_PacketType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：0 .. 255
- **配置类别**: 预编译时/构建后 
- **描述**: I2C发送Packet类型
  
### 4.4.8 I2c_IndexType
- **名称**: I2c_IndexType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：I2C_INDEX_0/I2C_INDEX_1/I2C_INDEX_2
- **配置类别**: 预编译时/构建后 
- **描述**: I2C硬件单元类型

### 4.4.9 I2C_MasterEventType
- **名称**: I2C_MasterEventType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：I2C_MASTER_EVENT_NACK/I2C_MASTER_EVENT_ARBITRATION_LOST/I2C_MASTER_EVENT_BUS_ERROR/I2C_MASTER_EVENT_END_WRITE/I2C_MASTER_EVENT_END_READ
- **配置类别**: 预编译时/构建后 
- **描述**: I2C事件类型

### 4.4.10 I2c_ConfigClockSourceType
- **名称**: I2c_ConfigClockSourceType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：CLOCK_CFG_SELECT_SCLK/CLOCK_CFG_SELECT_HFCLK/CLOCK_CFG_SELECT_LFCLK
- **配置类别**: 预编译时/构建后 
- **描述**: I2C时钟类型 

### 4.4.11 I2c_ConfigClockDriverType
- **名称**: I2c_ConfigClockDriverType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：CLOCK_CFG_DIV_1/CLOCK_CFG_DIV_2/CLOCK_CFG_SELECT_LFCLK
- **配置类别**: 预编译时/构建后 
- **描述**: I2C时钟分频类型 

### 4.4.12 I2c_ConfigModeType
- **名称**: I2c_ConfigModeType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：HW_MODE_CFG_I2C/HW_MODE_CFG_SMBUS
- **配置类别**: 预编译时/构建后 
- **描述**: 硬件单元类型 

### 4.4.12 I2c_ConfigModeType
- **名称**: I2c_ConfigModeType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：HW_MODE_CFG_I2C/HW_MODE_CFG_SMBUS
- **配置类别**: 预编译时/构建后 
- **描述**: 硬件单元类型 
  
### 4.4.13 I2c_StatusType
- **名称**: I2c_StatusType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：I2C_UNINIT/I2C_IDLE/I2C_BUSY
- **配置类别**: 预编译时/构建后 
- **描述**: I2C初始化状态

### 4.4.14 I2c_PacketResultType
- **名称**: I2c_PacketResultType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：I2C_PACKET_RESULT_OK/I2C_PACKET_RESULT_PENDING/I2C_PACKET_RESULT_FAILED
- **配置类别**: 预编译时/构建后 
- **描述**: I2C发送结果状态

### 4.4.15 I2c_CommModeType
- **名称**: I2c_CommModeType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：I2C_COMMUNICATION_SYNC/I2C_COMMUNICATION_ASYNC/I2C_COMMUNICATION_INVALID
- **配置类别**: 预编译时/构建后 
- **描述**: I2C通讯类型，同步或异步

### 4.4.16 I2c_OperationType
- **名称**: I2c_OperationType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：I2C_WRITE/I2C_READ/I2C_DUMMY_WRITE/I2C_NO_OPERATION
- **配置类别**: 预编译时/构建后 
- **描述**: I2C读写操作

### 4.4.17 I2c_PacketOperationType
- **名称**: I2c_PacketOperationType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: --
- **配置类别**: 预编译时/构建后 
- **描述**: I2C读写操作结构体

### 4.4.18 I2c_DeviceAddrModeType
- **名称**: I2c_DeviceAddrModeType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: 值：I2C_ADDRTYPE_7BIT/I2C_ADDRTYPE_10BIT
- **配置类别**: 预编译时/构建后 
- **描述**: I2C地址类型

### 4.4.19 I2c_PacketRegAddrInfoType
- **名称**: I2c_PacketRegAddrInfoType
- **来源**: 
- **文件**: I2c_Types.h
- **范围**: --
- **配置类别**: 预编译时/构建后 
- **描述**: I2C发送Packet结构体信息

-----

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: I2C_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: I2c.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: I2C_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: I2c.h
- **值**: 255
- **描述**: 这个宏给出了I2C驱动模块ID，如所述

## 5.3 SwMajorVersion
- **语法**: I2C_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: I2c.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.4 SwMinorVersion
- **语法**: I2C_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: I2c.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.5 SwPatchVersion
- **语法**: I2C_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: I2c.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

-----

# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 I2c_ConfigType
- **语法**: I2c_ConfigType
- **类型**: struct
- **文件**: I2c_Types.h
- **范围**:
  - **I2c_PacketConfigType**
    - I2cPacketConfigPtr - Packet配置信息
  - **I2c_HWModuleConfigType** 
    - HwModuleConfigPtr - 硬件配置信息
  - **I2c_HwUnitType**
    - HwUnitNum - 硬件单元个数
- **描述**: 此类型定义用于配置I2C的整体配置。此类型的指针在I2c_Init API中用于初始化I2C驱动程序。

### 6.1.2 类型定义 I2c_PacketConfigType
- **语法**: I2c_PacketConfigType
- **类型**: struct
- **文件**: I2c_Types.h
- **范围**:
  - **I2c_DeviceAddrType**
    - ExtDeviceAddress - 外设地址
  - **I2c_HwUnitType** 
    - HwUnit - 使用I2C硬件单元
- **描述**: 这是包含Packet配置信息数据结构类型。

### 6.1.3 类型定义 I2c_HWModuleConfigType
- **语法**: I2c_HWModuleConfigType
- **类型**: struct
- **文件**: I2c_Types.h
- **范围**:
  - **I2c_HwUnitType**
    - HwUnit - 硬件单元
  - **uint32** 
    - HwClkSource - 时钟源
  - **uint32**
    - HwClkDriver - 分频
  - **uint16**
    - HwBaudRateLo - SCL低电平时钟周期数
  - **uint16** 
    - HwBaudRateHi - SCL高电平时钟周期数
  - **uint32**
    - HwMode - 硬件模式，目前仅支持I2C
  - **I2c_DeviceAddrModeType** 
    - HwAddrMoe - 地址模式，目前仅支持7位地址外设
  - **I2c_NotifyFcnTyp**
    - MasterCallback - 事件回调函数
  - **uint8** 
    - CallbackParam - 回调函数返回参数标明硬件单元号
- **描述**: 这是包含I2C硬件参数配置信息数据结构类型。

## 6.2 API函数

### 6.2.1 I2c_Init
- **服务名称**: `I2c_Init`
- **语法**: `void I2c_Init(const I2c_ConfigType *ConfigPtr)`
- **来源**: 此API由。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: ConfigPtr - 配置信息
- **参数(输出)**: 无
- **返回值**: 校验值
- **描述**: I2C初始化
- **注意事项**: 无

### 6.2.2 I2c_DeInit
- **服务名称**: `I2c_DeInit`
- **语法**: `Std_ReturnType I2c_DeInit(void)`
- **来源**: 此API由。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: E_OK - 反初始化成功
- **返回值**: E_NOT_OK - 反初始化失败
- **描述**: I2C反初始化
- **注意事项**: 无

### 6.2.3 I2c_SetupPacket
- **服务名称**: `I2c_SetupPacket`
- **语法**: `Std_ReturnType I2c_SetupPacket(I2c_PacketType Packet, I2c_DataType *NativeDataPtr)`
- **来源**: 此API由。
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Packet - Packet索引号
- **参数(输入)**: NativeDataPtr - 数据缓冲区
- **参数(输出)**: 无
- **返回值**: E_OK - 设置Packet信息成功
- **返回值**: E_NOT_OK - 设置Packet信息失败
- **描述**: I2C设置Packet读或写缓冲区
- **注意事项**: 无

### 6.2.4 I2c_SyncOperation
- **服务名称**: `I2c_SyncOperation`
- **语法**: `Std_ReturnType I2c_SyncOperation(I2c_PacketType Packet, I2c_OperationType Operation)`
- **来源**: 此API由。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Packet - Packet索引号
- **参数(输入)**: Operation - 读或写指令
- **参数(输出)**: 无
- **返回值**: E_OK - 同步读或写操作成功
- **返回值**: E_NOT_OK - 同步读或写操作失败
- **描述**: I2C同步写或同步读操作
- **注意事项**: 无

### 6.2.5 I2c_AsyncOperation
- **服务名称**: `I2c_AsyncOperation`
- **语法**: `Std_ReturnType I2c_AsyncOperation(I2c_PacketType Packet, I2c_OperationType Operation)`
- **来源**: 此API由。
- **服务ID**: 0x04
- **同步/异步**: 异步
- **可重入**: 可重入
- **参数(输入)**: Packet - Packet索引号
- **参数(输入)**: Operation - 读或写指令
- **参数(输出)**: 无
- **返回值**: E_OK - 同步读或写指令下发成功
- **返回值**: E_NOT_OK - 同步读或写指令下发失败
- **描述**: I2C异步写或同步读操作
- **注意事项**: 通过I2c_GetStatus获取异步操作状态

### 6.2.6 I2c_GetStatus
- **服务名称**: `I2c_GetStatus`
- **语法**: `I2c_StatusType I2c_GetStatus(void)`
- **来源**: 此API由。
- **服务ID**: 0x05
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: I2C_UNINIT - 未初始化
- **返回值**: I2C_IDLE - 当前空闲
- **返回值**: I2C_BUSY - 当前忙碌
- **描述**: 获取I2C单元状态
- **注意事项**: 无

### 6.2.7 I2c_GetPacketResult
- **服务名称**: `I2c_GetPacketResult`
- **语法**: `I2c_StatusType I2c_GetPacketResult(I2c_PacketType Packet)`
- **来源**: 此API由。
- **服务ID**: 0x06
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Packet - Packet索引号
- **参数(输出)**: 无
- **返回值**: I2C_PACKET_RESULT_OK - 读写成功
- **返回值**: I2C_PACKET_RESULT_PENDING - 正在读或写
- **返回值**: I2C_PACKET_RESULT_FAILED - 读写失败
- **描述**: 获取Packet操作状态
- **注意事项**: 无
  
### 6.2.8 I2c_GetVersionInfo
- **服务名称**: `I2c_GetVersionInfo`
- **语法**: `void I2c_GetVersionInfo (Std_VersionInfoType* VersionInfo)`
- **来源**: 此API由。
- **服务ID**:0x07
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**:无
- **参数(输出)**: VersionInfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无

### 6.2.9 I2c_UpdatePacketRegInfo
- **服务名称**: `I2c_UpdatePacketRegInfo`
- **语法**: `Std_ReturnType I2c_UpdatePacketRegInfo(I2c_PacketType Packet, I2c_DeviceRegAddrType DeviceRegAddr, I2c_DeviceRegAddrLenType DeviceRegLen, I2c_DeviceDataNumberType DeviceDataLength)`
- **来源**: 此API由。
- **服务ID**: 0x06
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: Packet - Packet索引号
- **参数(输入)**: DeviceRegAddr - 寄存器地址
- **参数(输入)**: DeviceRegLen - 寄存器长度
- **参数(输入)**: DeviceDataLength - 操作数据长度
- **参数(输出)**: 无
- **返回值**: E_OK - 设置成功
- **返回值**: E_NOT_OK - 设置失败
- **描述**: 设置Packet要操作的地址信息
- **注意事项**: 无

### 6.2.10 I2c_GetPacketRegInfo
- **服务名称**: `I2c_GetPacketRegInfo`
- **语法**: `Std_ReturnType I2c_GetPacketRegInfo(I2c_PacketType Packet, I2c_DeviceRegAddrType *pRegAddr, I2c_DeviceRegAddrLenType *pRegLen,I2c_DeviceDataNumberType *pLength)`
- **来源**: 此API由。
- **服务ID**: 0x06
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: Packet - Packet索引号
- **参数(输出)**: pRegAddr - 寄存器地址
- **参数(输出)**: pRegLen - 寄存器地址长度
- **参数(输出)**: pLength - 操作数据长度
- **返回值**: E_OK - 获取信息成功
- **返回值**: E_NOT_OK - 获取信息失败
- **描述**: 获取Packet要操作的地址信息
- **注意事项**: 无

-----

## 6.3 中断处理

中断服务例程在I2C Driver中用于通知、完成读或写流程。

### 6.3.1 I2c_IsrProtocol
- **服务名称**: I2c_IsrProtocol
- **语法**：`void I2c_IsrProtocol(I2c_HwUnitType hwUnit)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：hwUnit - I2C通道编号
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
   - 调用通知
   - 完成I2C读写协议时序操作
- **警告**：无
- **配置**：如果需要从中断例程通知，则应将I2C_ASYNC_READ_OR_WRITE设置为STD_ON。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有3个SRN（服务请求节点）用于服务I2C通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 表79 服务请求节点 - I2C硬件资源

| 硬件资源    | SRN编号                |
| ----------- | ---------------------- |
| I2C_INDEX_0 | IIC0_UNIFIED_INTERRUPT |
| I2C_INDEX_1 | IIC1_UNIFIED_INTERRUPT |
| I2C_INDEX_2 | IIC2_UNIFIED_INTERRUPT |

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

I2C Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是I2C Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                    | 类型/范围               | 描述              |
| ----------------------- | ----------------------- | ----------------- |
| I2c_PacketResult        | I2c_PacketResultType    | Packet操作结果    |
| I2c_PacketOperationInfo | I2c_PacketOperationType | Packet操作信息    |
| I2cBaseAddr             | I2c_RegisterMap_t       | I2C地址           |
| I2c_HwUnitStatus        | uint8                   | I2C单元初始化状态 |
| I2c_IntrInfo            | I2c_InformationType     | 异步发送状态信息  |
| I2c_RegAddr             | I2c_DataType            | 寄存器保存信息    |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是I2C Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                     | 错误描述                | 值（十六进制） |
| ---------------------------- | ----------------------- | -------------- |
| I2C_E_PARAM_CONFIG           | 初始化参数错误          | 0x00           |
| I2C_E_PARAM_PACKET           | Packet超出配置范围      | 0x01           |
| I2C_E_PARAM_OPERATION        | 执行指令出错            | 0x02           |
| I2C_E_PARAM_UNIT             | 空闲                    | 0x03           |
| I2C_E_PARAM_POINTER          | 无效指针                | 0x04           |
| I2C_E_UNINIT                 | 未初始化                | 0x05           |
| I2C_E_PACKET_UNDER_PROCESS   | 异步操作未执行完        | 0x06           |
| I2C_E_ALREADY_INITIALIZED    | 重复初始化              | 0x07           |
| I2C_E_PACKET_NOT_INITIALIZED | 操作未配置Packet信息    | 0x08           |
| I2C_E_HW_UNIT_BUSY           | I2C忙碌中，未执行完指令 | 0x09           |


-----
# 第9章 示例用法
本章描述了如何在应用程序中使用I2C驱动器提供的不同的API。

## 9.1 系统时钟配置注意事项

按照以下指南正确配置I2C驱动器：
- MCU驱动器：配置系统时钟。(只能选系统时钟)
- 如果使用异步函数，中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级
- I2C驱动器：选择所需的API配置开关。
- 初始化顺序需要先初始化I2C然后在初始化PORT

## 9.2 宏配置

```c
#define I2C_DEV_ERROR_DETECT (STD_OFF)
#define I2C_PB_FIXEDADDR (STD_OFF)
#define I2C_VERSION_INFO_API (STD_ON)
/* 如果需要使用异步函数，需要打开配置 */
#define I2C_ASYNC_READ_OR_WRITE (STD_ON)
#define I2C_MAX_PACKET_NUM (1U)
```
## 9.3 接口使用示例

#### 9.3.1 同步操作

```c
/* 设置寄存器地址，寄存器长度，写操作数据长度 */
if (I2c_UpdatePacketRegInfo(PacketNum, Eeprom_AddrTmp, 2, data_len))
{
  kf_printf("I2c_UpdatePacketRegInfo set error!!!!\r\n");
}
/* 设置写数据缓冲区 */
I2c_SetupPacket(PacketNum, &I2c0_WriteBuffer[0]);
/* 开始写操作 */
Result = I2c_SyncOperation(PacketNum, I2C_WRITE);

if (Result != E_OK)
{
  kf_printf("Writing into EEPROM failed\r\n");
}

/* 写EEPROM后要等待再去读 */
System_Delay(0x8FFF);

/* 做写后读校验，所以不需要再设置寄存器信息 */

/* 设置读数据缓冲区 */
I2c_SetupPacket(PacketNum, &I2c0_ReadBuffer[0]);
/* 开始读操作 */
Result = I2c_SyncOperation(PacketNum, I2C_READ);
```

#### 9.3.2 异步操作

```c
/* 设置寄存器地址，寄存器长度，写操作数据长度 */
if (I2c_UpdatePacketRegInfo(PacketNum, Eeprom_AddrTmp, 2, data_len))
{
  kf_printf("I2c_UpdatePacketRegInfo set error!!!!\r\n");
}
/* 设置写数据缓冲区 */
I2c_SetupPacket(PacketNum, &I2c0_WriteBuffer[0]);
/* 开始写操作 */
Result = I2c_AsyncOperation(PacketNum, I2C_WRITE);

if (Result != E_OK)
{
  kf_printf("Writing into EEPROM failed\r\n");
}

/* 等待异步操作结束 */
while (I2c_GetPacketResult(PacketNum) != I2C_PACKET_RESULT_OK)
{
/* Wait for Async Operation completion*/
}

/* 写EEPROM后要等待再去读 */
System_Delay(0x8FFF);

/* 做写后读校验，所以不需要再设置寄存器信息 */

/* 设置读数据缓冲区 */
I2c_SetupPacket(PacketNum, &I2c0_ReadBuffer[0]);
/* 开始读操作 */
Result = I2c_SyncOperation(PacketNum, I2C_READ);

if (Result != E_OK)
{
  kf_printf("Reading from EEPROM failed\r\n");
}

/* 等待异步操作结束 */
while (I2c_GetPacketResult(PacketNum) != I2C_PACKET_RESULT_OK)
{
/* Wait for Async Operation completion*/
}
```

## 9.4 配置示例

配置外设地址0xA0（需要配置左移后的值），外设7位地址；配置使用I2C0硬件单元，硬件单元配置100K

```c

static void I2c0Example_CallBack(I2c_PacketType Packet, I2C_MasterEventType Event, uint8 UserData);

/**
 * @brief config information
 */
static const I2c_ConfigType I2cExample_Config = {
  .I2cPacketConfigPtr =
    (I2c_PacketConfigType[I2C_MAX_PACKET_NUM]){
      [0U].ExtDeviceAddress = 0xA0U,
      [0U].HwUnit           = I2C_INDEX_0,
    },
  .HwUnitNum = 1U,
  .HwModuleConfigPtr =
    (I2c_HWModuleConfigType[]){
      /* I2C0 CONFIG 100K */
      [0U].HwUnit         = I2C_INDEX_0,
      [0U].HwClkSource    = (uint32)CLOCK_CFG_SELECT_SCLK,
      [0U].HwClkDriver    = (uint32)CLOCK_CFG_DIV_1,
      [0U].HwBaudRateLo   = 600U,
      [0U].HwBaudRateHi   = 600U,
      [0U].HwMode         = (uint32)HW_MODE_CFG_I2C_MASTER,
      [0U].HwAddrMoe      = (uint32)I2C_ADDRTYPE_7BIT,
      [0U].MasterCallback = I2c0Example_CallBack,
      [0U].CallbackParam  = I2C_INDEX_0,
    },
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


## 10.2 限制

### 10.2.1




