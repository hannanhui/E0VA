# ChipOn Microcontroller Abstract Layer Users Manual - DIO Driver
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
- [ChipOn Microcontroller Abstract Layer Users Manual - DIO Driver](#chipon-microcontroller-abstract-layer-users-manual---dio-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 DIO Driver概述](#第2章-dio-driver概述)
    - [2.1 PORT](#21-port)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [无](#无)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Dio\_ChannelGroupType](#611-类型定义-dio_channelgrouptype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Dio\_ReadChannel](#621-dio_readchannel)
    - [6.2.2 Dio\_WriteChannel](#622-dio_writechannel)
    - [6.2.3 Dio\_ReadPort](#623-dio_readport)
    - [6.2.4 Dio\_WritePort](#624-dio_writeport)
    - [6.2.5 Dio\_ReadChannelGroup](#625-dio_readchannelgroup)
    - [6.2.6 Dio\_WriteChannelGroup](#626-dio_writechannelgroup)
    - [6.2.7 Dio\_GetVersionInfo](#627-dio_getversioninfo)
    - [6.2.8 Dio\_FlipChannel](#628-dio_flipchannel)
    - [6.2.9 Dio\_MaskedWritePort](#629-dio_maskedwriteport)
  - [6.3 中断处理](#63-中断处理)
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
      - [9.3.1 读取PA12值](#931-读取pa12值)
      - [9.3.2 PA13输出高或低](#932-pa13输出高或低)
      - [9.3.3 读取PORTD值](#933-读取portd值)
      - [9.3.4 设置PORTE值](#934-设置porte值)
      - [9.3.5 翻转PD14](#935-翻转pd14)
      - [9.3.6 读取PORTE中bit2-bit5的值](#936-读取porte中bit2-bit5的值)
      - [9.3.7 设置PORTD中bit1-bit4的值为A](#937-设置portd中bit1-bit4的值为a)
      - [9.3.8 设置PORTD中bit1-bit4的值为5](#938-设置portd中bit1-bit4的值为5)
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

本用户手册提供了AUTOSAR CP R22-11的DIO驱动程序的功能和API实现的相关信息。DIO的驱动程序初始化并提供对微控制器的访问。本用户手册旨在帮助用户熟悉DIO驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用DIO驱动程序的文档。

## 1.1 范围

本文档介绍DIO驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- DIO Driver的文件结构
- Driver的配置参数
- 由DIO Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于DIO Driver

## 1.2 缩写

| 缩写              | 解释                                                                                                |
| :---------------- | :-------------------------------------------------------------------------------------------------- |
| AUTOSAR           | 汽车汽车开放系统架构                                                                                |
| API               | 应用程序接口                                                                                        |
| DIO               | 数字输入/输出                                                                                       |
| DIO Channel       | 一个通用的数字IO引脚表示一个DIO通道                                                                 |
| DIO Channel Group | 一个DIO端口内的几个相邻的DIO信道可以组合成一个规范<br>的逻辑信道组                                  |
| DIO Port          | 在DIO驱动程序中，可以按硬件（通常由一个硬件寄存器控制）<br>将多个DIO通道进行分组，以表示一个DIO端口 |
| DEM               | 诊断事件管理器                                                                                      |
| DET               | 开发错误跟踪器                                                                                      |
| GPIO              | 通用输入输出                                                                                        |
| BSW               | 基础软件                                                                                            |
| HW                | 硬件                                                                                                |
| ID                | 标识符                                                                                              |
| MCAL              | 微控制器抽象层                                                                                      |
| MCU               | 微控制器                                                                                            |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of DIODriver, AUTOSAR_SWS_DIODriver.pdf Release R22-11
- [2] Requirements of DIODriver, AUTOSAR_SRS_DIODriver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 DIO Driver概述
KF32微控制器提供DIO操作方式。

### 2.1 PORT
DIO使用的引脚需要由Port驱动程序配置。
有关PORT配置的详细信息，参考PORT用户手册

-----

# 第3章 文件结构
本节提供了有关DIO Driver文件和其他相关文件的详细信息。
| Name       | Description                                     |
| :--------- | :---------------------------------------------- |
| Dio.c      | 此文件包含DIO驱动程序的通用功能                 |
| Dio.h      | 此头文件输出DIO驱动程序的宏、类型定义和函数原型 |
| Dio_Cfg.h  | 本文在这里声明了DIO驱动程序的配置数据。         |
| Dio_Lcfg.c | 空                                              |

-----

# 第4章 配置文档

无
-----

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: DIO_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Dio.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: DIO_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: Dio.h
- **值**: 120
- **描述**: 这个宏给出了DIO驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: DIO_INSTANCE_ID
- **类型**: 宏定义 (#define)
- **文件**: Dio.h
- **值**: 0
- **描述**: 这个宏给出了DIO驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: DIO_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Dio.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: DIO_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Dio.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: DIO_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Dio.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Dio_ChannelGroupType
- **语法**: Dio_ChannelGroupType
- **类型**: Struct
- **文件**: Dio.h
- **范围**: 
  - **Dio_PortType**
    - Port - PORT索引号
  - **uint8**
    - Offset - 该元素应该是通道组在端口上的位置，从LSB中计算    
  - **uint16**
    - Mask - 这个元素掩码定义了通道组的位置               
- **描述**: 此类型定义用于Dio_ReadChannelGroup和Dio_WriteChannelGroup使用。

---
## 6.2 API函数

### 6.2.1 Dio_ReadChannel
- **服务名称**: `Dio_ReadChannel`
- **语法**: `Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: ChannelId - 高4位PORT索引号，低四位PIN索引号
- **参数(输出)**: 无
- **返回值**: STD_LOW - 输入状态事低电平
- **返回值**: STD_HIGH - 输入状态事高电平
- **描述**: 读取某个端口的PIN管脚输入状态
- **注意事项**: 无

### 6.2.2 Dio_WriteChannel
- **服务名称**: `Dio_WriteChannel`
- **语法**: `void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: ChannelId - 高4位PORT索引号，低四位PIN索引号
- **参数(输入)**: Level - STD_LOW或STD_HIGH
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置某个端口的PIN管脚输入状
- **注意事项**: 无

### 6.2.3 Dio_ReadPort
- **服务名称**: `Dio_ReadPort`
- **语法**: `Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: PortId - PORT索引号
- **参数(输出)**: 无
- **返回值**: 该PORT所有pin电平值
- **描述**: 读取PORT的所有pin脚值
- **注意事项**: 无 

### 6.2.4 Dio_WritePort
- **服务名称**: `Dio_WritePort`
- **语法**: `void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: PortId - PORT索引号
- **参数(输出)**: Level - 写入值
- **返回值**: 无
- **描述**: 设置PORT的所有pin脚值
- **注意事项**: 无

### 6.2.5 Dio_ReadChannelGroup
- **服务名称**: `Dio_ReadChannelGroup`
- **语法**: `Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: ChannelGroupIdPtr - 包含PORT索引号，掩码和位移
- **参数(输出)**: 无
- **返回值**: PORT掩码移位后pin电平值
- **描述**: 读取PORT某些位的值
- **注意事项**: 无

### 6.2.6 Dio_WriteChannelGroup
- **服务名称**: `Dio_WriteChannelGroup`
- **语法**: `void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level))`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x05
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: ChannelGroupIdPtr - 包含PORT索引号，掩码和位移
- **参数(输入)**: Level - 写入值，需要根据参数ChannelGroupIdPtr进行移位和掩码处理
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 更改PORT某些位的值
- **注意事项**: 无

### 6.2.7 Dio_GetVersionInfo
- **服务名称**: `Dio_GetVersionInfo`
- **语法**: `void Dio_GetVersionInfo (Std_VersionInfoType* VersionInfo)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x12
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:无
- **参数(输出)**: VersionInfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无

### 6.2.8 Dio_FlipChannel
- **服务名称**: `Dio_FlipChannel`
- **语法**: `Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x11
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: ChannelId - 高4位PORT索引号，低四位PIN索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 翻转PIN状态
- **注意事项**: 无

### 6.2.9 Dio_MaskedWritePort
- **服务名称**: `Dio_MaskedWritePort`
- **语法**: `void Dio_MaskedWritePort (Dio_PortType PortId,Dio_PortLevelType Level,Dio_PortLevelType Mask)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x13
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: PortId - PORT索引号
- **参数(输入)**: Level - 休眠索引号
- **参数(输入)**: Mask - 休眠索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置指定端口值，根据入参掩码和Level；输入pin保持不变
- **注意事项**: 无

-----
## 6.3 中断处理

无

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

DIO Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是DIO Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数         | 类型/范围          | 描述         |
| ------------ | ------------------ | ------------ |
| kvGpioHwInfo | GPIO_RegisterMap_t | PORT操作地址 |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是DIO Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                          | 错误描述                              | 值（十六进制） |
| --------------------------------- | ------------------------------------- | -------------- |
| DIO_E_PARAM_INVALID_CHANNEL_ID    | ChannelId值错误                       | 0x0A           |
| DIO_E_PARAM_CONFIG                | 未使用                                | 0x10           |
| DIO_E_PARAM_INVALID_PORT_ID       | PortId值错误                          | 0x14           |
| DIO_E_PARAM_INVALID_GROUP         | ChannelGroupIdPtr参数不正确           | 0x1F           |
| DIO_E_PARAM_POINTER               | 获取版本号入参空指针                  | 0x20           |
| DIO_E_PARAM_INVALID_CHANNEL_LEVEL | Dio_WriteChannel写入VALUE值不符合要求 | 0x0B           |

-----
# 第9章 示例用法
本章描述了如何配置DIO驱动器以及如何在应用程序中使用DIO驱动器提供的不同的API。

## 9.1 系统时钟配置注意事项

无

## 9.2 宏配置

```c
#define DIO_DEV_ERROR_DETECT (STD_OFF)
#define DIO_FLIP_CHANNEL_API (STD_ON)
#define DIO_VERSION_INFO_API (STD_ON)
```
## 9.3 接口使用示例

#### 9.3.1 读取PA12值
已在PORT中配置PA12为输入
```c
	pinLevel = Dio_ReadChannel(DIO_CHANNEL_A_12);
```

#### 9.3.2 PA13输出高或低
已在PORT中配置PA13为输出
```c
	Dio_WriteChannel(DIO_CHANNEL_A_13,STD_HIGH);
  ...
  Dio_WriteChannel(DIO_CHANNEL_A_13,STD_LOW);
```

#### 9.3.3 读取PORTD值

```c
	portValue = Dio_ReadPort(DIO_PORT_D);
```

#### 9.3.4 设置PORTE值

```c
  Dio_PortLevelType portValue = 0x1234;
  Dio_WritePort(DIO_PORT_E,portValue);
```

#### 9.3.5 翻转PD14

```c
  Dio_FlipChannel(DIO_CHANNEL_D_14);
```

#### 9.3.6 读取PORTE中bit2-bit5的值

```c
  Dio_PortLevelType portValue;
  Dio_ChannelGroupType channelGroup;

  channelGroup.Port = DIO_PORT_E;
  channelGroup.Mask = 0x3C;
  channelGroup.Offset = 2;

  portValue = Dio_ReadChannelGroup(&channelGroup);
```

#### 9.3.7 设置PORTD中bit1-bit4的值为A

```c
  Dio_PortLevelType portValue;
  Dio_ChannelGroupType channelGroup;

  portValue = 0x0A;
  channelGroup.Port = DIO_PORT_D;
  channelGroup.Mask = 0x1E;
  channelGroup.Offset = 1;

  Dio_WriteChannelGroup(&channelGroup,portValue);
```

#### 9.3.8 设置PORTD中bit1-bit4的值为5

PORTD的pin1-4为输出
```c
  Dio_MaskedWritePort(DIO_PORT_D,0x05,0x001E);
```

## 9.4 配置示例

无

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




