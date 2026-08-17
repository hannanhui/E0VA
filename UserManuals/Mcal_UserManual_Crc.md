# ChipOn Microcontroller Abstract Layer Users Manual - CRC Driver
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
- [ChipOn Microcontroller Abstract Layer Users Manual - CRC Driver](#chipon-microcontroller-abstract-layer-users-manual---crc-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 CRC Driver概述](#第2章-crc-driver概述)
    - [2.1 CRC](#21-crc)
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
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Crc\_CalculateCRC8](#621-crc_calculatecrc8)
    - [6.2.2 Crc\_CalculateCRC8H2F](#622-crc_calculatecrc8h2f)
    - [6.2.3 Crc\_CalculateCRC16](#623-crc_calculatecrc16)
    - [6.2.4 Crc\_CalculateCRC16ARC](#624-crc_calculatecrc16arc)
    - [6.2.5 Crc\_CalculateCRC32](#625-crc_calculatecrc32)
    - [6.2.6 Crc\_CalculateCRC32P4](#626-crc_calculatecrc32p4)
    - [6.2.7 Crc\_GetVersionInfo](#627-crc_getversioninfo)
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
      - [9.3.1 Crc\_CalculateCRC8 分步计算](#931-crc_calculatecrc8-分步计算)
      - [9.3.2 Crc\_CalculateCRC8 一步计算](#932-crc_calculatecrc8-一步计算)
      - [9.3.3 Crc\_CalculateCRC8H2F 分步计算](#933-crc_calculatecrc8h2f-分步计算)
      - [9.3.4 Crc\_CalculateCRC8H2F 一步计算](#934-crc_calculatecrc8h2f-一步计算)
      - [9.3.5 Crc\_CalculateCRC16 分步计算](#935-crc_calculatecrc16-分步计算)
      - [9.3.6 Crc\_CalculateCRC16 一步计算](#936-crc_calculatecrc16-一步计算)
      - [9.3.7 Crc\_CalculateCRC16ARC 分步计算](#937-crc_calculatecrc16arc-分步计算)
      - [9.3.8 Crc\_CalculateCRC16ARC 一步计算](#938-crc_calculatecrc16arc-一步计算)
      - [9.3.9 Crc\_CalculateCRC32 分步计算](#939-crc_calculatecrc32-分步计算)
      - [9.3.10 Crc\_CalculateCRC32 一步计算](#9310-crc_calculatecrc32-一步计算)
      - [9.3.11 Crc\_CalculateCRC32P4 分步计算](#9311-crc_calculatecrc32p4-分步计算)
      - [9.3.12 Crc\_CalculateCRC32P4 一步计算](#9312-crc_calculatecrc32p4-一步计算)
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

本用户手册提供了AUTOSAR CP R22-11的CRC驱动程序的功能和API实现的相关信息。本用户手册旨在帮助用户熟悉CRC驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用CRC驱动程序的文档。

## 1.1 范围

本文档介绍CRC驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- CRC Driver的文件结构
- 由CRC Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于CRC Driver

## 1.2 缩写

| 缩写    | 解释                 |
| :------ | :------------------- |
| AUTOSAR | 汽车汽车开放系统架构 |
| API     | 应用程序接口         |
| CRC     | 循环冗余码校验       |
| ALU     | 算术逻辑单元         |
| DEM     | 诊断事件管理器       |
| DET     | 开发错误跟踪器       |
| BSW     | 基础软件             |
| HW      | 硬件                 |
| ID      | 标识符               |
| MCAL    | 微控制器抽象层       |
| MCU     | 微控制器             |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of CRCDriver, AUTOSAR_SWS_CRCLibrary.pdf Release R22-11
- [2] KF32A158xxxSF用户手册V1.0
- [3] KF32A158xxxSF数据手册V1.3

-----
# 第2章 CRC Driver概述
KF32微控制器提供CRC操作方式。

### 2.1 CRC
CRC使用的硬件单元计算。

-----

# 第3章 文件结构
本节提供了有关CRC Driver文件和其他相关文件的详细信息。
| Name       | Description                                     |
| :--------- | :---------------------------------------------- |
| Crc.c      | 此文件包含获取版本号函数                        |
| Crc.h      | 此头文件输出CRC驱动程序的宏、类型定义和函数原型 |
| Crc_Im.c   | 模块芯片适配层接口实现文件                      |
| Crc_Im.h   | 模块芯片适配层接口文件                          |
| Crc8.c     | Crc_CalculateCRC8算法实现                       |
| Crc8H2F.c  | Crc_CalculateCRC8H2F算法实现                    |
| Crc16.c    | Crc_CalculateCRC16算法实现                      |
| Crc16ARC.c | Crc_CalculateCRC16ARC算法实现                   |
| Crc32.c    | Crc_CalculateCRC32算法实现                      |
| Crc32P4.c  | Crc_CalculateCRC32P4算法实现                    |
| Crc_Cfg.h  | 本文在这里声明了CRC驱动程序的配置数据。         |


-----

# 第4章 配置文档

无
-----

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: CRC_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Crc.h
- **值**: 76
- **描述**: 

## 5.2 ModuleId
- **语法**: CRC_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: Crc.h
- **值**: 123
- **描述**: 这个宏给出了CRC驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: CRC_INSTANCE_ID
- **类型**: 宏定义 (#define)
- **文件**: Crc.h
- **值**: 0
- **描述**: 这个宏给出了CRC驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: CRC_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Crc.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: CRC_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Crc.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: CRC_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Crc.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

无

---
## 6.2 API函数

### 6.2.1 Crc_CalculateCRC8
- **服务名称**: `Crc_CalculateCRC8`
- **语法**: `uint8 Crc_CalculateCRC8(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Crc_DataPtr - 计算数据指针
- **参数(输入)**: Crc_Length - 计算数据长度
- **参数(输入)**: Crc_StartValue8 - 输入参数
- **参数(输入)**: Crc_IsFirstCall - 是否第一次调用，true时，参数Crc_StartValue8无效；false时，参数Crc_StartValue8使用
- **参数(输出)**: 无
- **返回值**: 校验值
- **描述**: 8位SAE-J1850，CRC计算
- **注意事项**: 无

### 6.2.2 Crc_CalculateCRC8H2F
- **服务名称**: `Crc_CalculateCRC8H2F`
- **语法**: `uint8 Crc_CalculateCRC8H2F(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x05
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Crc_DataPtr - 计算数据指针
- **参数(输入)**: Crc_Length - 计算数据长度
- **参数(输入)**: Crc_StartValue8 - 输入参数
- **参数(输入)**: Crc_IsFirstCall - 是否第一次调用，true时，参数Crc_StartValue8无效；false时，参数Crc_StartValue8使用
- **参数(输出)**: 无
- **返回值**: 校验值
- **描述**: 8位0x2F多项式，CRC计算
- **注意事项**: 无

### 6.2.3 Crc_CalculateCRC16
- **服务名称**: `Crc_CalculateCRC16`
- **语法**: `uint16 Crc_CalculateCRC16(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Crc_DataPtr - 计算数据指针
- **参数(输入)**: Crc_Length - 计算数据长度
- **参数(输入)**: Crc_StartValue16 - 输入参数
- **参数(输入)**: Crc_IsFirstCall - 是否第一次调用，true时，参数Crc_StartValue8无效；false时，参数Crc_StartValue8使用
- **参数(输出)**: 无
- **返回值**: 校验值
- **描述**: 16位CCITT-FALSE，CRC计算
- **注意事项**: 无

### 6.2.4 Crc_CalculateCRC16ARC
- **服务名称**: `Crc_CalculateCRC16ARC`
- **语法**: `uint16 Crc_CalculateCRC16ARC(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x08
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Crc_DataPtr - 计算数据指针
- **参数(输入)**: Crc_Length - 计算数据长度
- **参数(输入)**: Crc_StartValue16 - 输入参数
- **参数(输入)**: Crc_IsFirstCall - 是否第一次调用，true时，参数Crc_StartValue8无效；false时，参数Crc_StartValue8使用
- **参数(输出)**: 无
- **返回值**: 校验值
- **描述**: 16位多项式0x8005，CRC计算
- **注意事项**: 无

### 6.2.5 Crc_CalculateCRC32
- **服务名称**: `Crc_CalculateCRC32`
- **语法**: `uint32 Crc_CalculateCRC32(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Crc_DataPtr - 计算数据指针
- **参数(输入)**: Crc_Length - 计算数据长度
- **参数(输入)**: Crc_StartValue32 - 输入参数
- **参数(输入)**: Crc_IsFirstCall - 是否第一次调用，true时，参数Crc_StartValue8无效；false时，参数Crc_StartValue8使用
- **参数(输出)**: 无
- **返回值**: 校验值
- **描述**: 32位以太网，CRC计算
- **注意事项**: 无

### 6.2.6 Crc_CalculateCRC32P4
- **服务名称**: `Crc_CalculateCRC32P4`
- **语法**: `uint32 Crc_CalculateCRC32P4(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Crc_DataPtr - 计算数据指针
- **参数(输入)**: Crc_Length - 计算数据长度
- **参数(输入)**: Crc_StartValue32 - 输入参数
- **参数(输入)**: Crc_IsFirstCall - 是否第一次调用，true时，参数Crc_StartValue8无效；false时，参数Crc_StartValue8使用
- **参数(输出)**: 无
- **返回值**: 校验值
- **描述**: 32位多项式0xF4ACFB13，CRC计算
- **注意事项**: 无

### 6.2.7 Crc_GetVersionInfo
- **服务名称**: `Crc_GetVersionInfo`
- **语法**: `void Crc_GetVersionInfo (Std_VersionInfoType* VersionInfo)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x04
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**:无
- **参数(输出)**: VersionInfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无
  
-----

## 6.3 中断处理

无

-----

## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

CRC Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是CRC Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                      | 类型/范围      | 描述                            |
| ------------------------- | -------------- | ------------------------------- |
| Crc8_ConfigInformation    | Crc_ConfigType | Crc_CalculateCRC8多项式信息     |
| Crc8_H2FConfigInformation | Crc_ConfigType | Crc_CalculateCRC8H2F多项式信息  |
| Crc16_ConfigInformation   | Crc_ConfigType | Crc_CalculateCRC16多项式信息    |
| Crc16_ConfigInformation   | Crc_ConfigType | Crc_CalculateCRC16ARC多项式信息 |
| Crc32_ConfigInformation   | Crc_ConfigType | Crc_CalculateCRC32多项式信息    |
| Crc32P4_ConfigInformation | Crc_ConfigType | Crc_CalculateCRC32P4多项式信息  |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
无

#### 表81 错误分类

无

-----
# 第9章 示例用法
本章描述了如何在应用程序中使用CRC驱动器提供的不同的API。

## 9.1 系统时钟配置注意事项

无

## 9.2 宏配置

```c
#define CRC_VERSION_INFO_API (STD_OFF)
```
## 9.3 接口使用示例

#### 9.3.1 Crc_CalculateCRC8 分步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint8_t ignored_val = 0x01;
uint8_t resultSAE1;
uint8_t resultSAE2;

resultSAE2 = Crc_CalculateCRC8(&Crc_TestData6[0], 2U, ignored_val, TRUE);
resultSAE2 = Crc_CalculateCRC8(&Crc_TestData6[2], 1U, resultSAE2, FALSE);
resultSAE2 = Crc_CalculateCRC8(&Crc_TestData6[3], 1U, resultSAE2, FALSE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.2 Crc_CalculateCRC8 一步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint8_t ignored_val = 0x01;
uint8_t resultSAE1;
uint8_t resultSAE2;

resultSAE1 = Crc_CalculateCRC8(&Crc_TestData6[0], 4U, ignored_val, TRUE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.3 Crc_CalculateCRC8H2F 分步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint8_t ignored_val = 0x01;
uint8_t resultSAE1;
uint8_t resultSAE2;

resultSAE2 = Crc_CalculateCRC8H2F(&Crc_TestData6[0], 2U, ignored_val, TRUE);
resultSAE2 = Crc_CalculateCRC8H2F(&Crc_TestData6[2], 1U, resultSAE2, FALSE);
resultSAE2 = Crc_CalculateCRC8H2F(&Crc_TestData6[3], 1U, resultSAE2, FALSE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.4 Crc_CalculateCRC8H2F 一步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint8_t ignored_val = 0x01;
uint8_t resultSAE1;
uint8_t resultSAE2;

resultSAE1 = Crc_CalculateCRC8H2F(&Crc_TestData6[0], 4U, ignored_val, TRUE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.5 Crc_CalculateCRC16 分步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint16_t ignored_val = 0x01;
uint16_t resultSAE1;
uint16_t resultSAE2;

resultSAE2 = Crc_CalculateCRC16(&Crc_TestData6[0], 2U, ignored_val, TRUE);
resultSAE2 = Crc_CalculateCRC16(&Crc_TestData6[2], 1U, resultSAE2, FALSE);
resultSAE2 = Crc_CalculateCRC16(&Crc_TestData6[3], 1U, resultSAE2, FALSE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.6 Crc_CalculateCRC16 一步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint16_t ignored_val = 0x01;
uint16_t resultSAE1;
uint16_t resultSAE2;

resultSAE1 = Crc_CalculateCRC16(&Crc_TestData6[0], 4U, ignored_val, TRUE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.7 Crc_CalculateCRC16ARC 分步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint16_t ignored_val = 0x01;
uint16_t resultSAE1;
uint16_t resultSAE2;

resultSAE2 = Crc_CalculateCRC16ARC(&Crc_TestData6[0], 2U, ignored_val, TRUE);
resultSAE2 = Crc_CalculateCRC16ARC(&Crc_TestData6[2], 1U, resultSAE2, FALSE);
resultSAE2 = Crc_CalculateCRC16ARC(&Crc_TestData6[3], 1U, resultSAE2, FALSE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.8 Crc_CalculateCRC16ARC 一步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint16_t ignored_val = 0x01;
uint16_t resultSAE1;
uint16_t resultSAE2;

resultSAE1 = Crc_CalculateCRC16ARC(&Crc_TestData6[0], 4U, ignored_val, TRUE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```


#### 9.3.9 Crc_CalculateCRC32 分步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint32_t ignored_val = 0x01;
uint32_t resultSAE1;
uint32_t resultSAE2;

resultSAE2 = Crc_CalculateCRC32(&Crc_TestData6[0], 2U, ignored_val, TRUE);
resultSAE2 = Crc_CalculateCRC32(&Crc_TestData6[2], 1U, resultSAE2, FALSE);
resultSAE2 = Crc_CalculateCRC32(&Crc_TestData6[3], 1U, resultSAE2, FALSE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.10 Crc_CalculateCRC32 一步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint32_t ignored_val = 0x01;
uint32_t resultSAE1;
uint32_t resultSAE2;

resultSAE1 = Crc_CalculateCRC32(&Crc_TestData6[0], 4U, ignored_val, TRUE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.11 Crc_CalculateCRC32P4 分步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint32_t ignored_val = 0x01;
uint32_t resultSAE1;
uint32_t resultSAE2;

resultSAE2 = Crc_CalculateCRC32P4(&Crc_TestData6[0], 2U, ignored_val, TRUE);
resultSAE2 = Crc_CalculateCRC32P4(&Crc_TestData6[2], 1U, resultSAE2, FALSE);
resultSAE2 = Crc_CalculateCRC32P4(&Crc_TestData6[3], 1U, resultSAE2, FALSE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
```

#### 9.3.12 Crc_CalculateCRC32P4 一步计算

```c
static uint8_t Crc_TestData6[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};

uint32_t ignored_val = 0x01;
uint32_t resultSAE1;
uint32_t resultSAE2;

resultSAE1 = Crc_CalculateCRC32P4(&Crc_TestData6[0], 4U, ignored_val, TRUE);
kf_printf("CRC8 several step result:0x%02x\r\n", resultSAE2);
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

- Crc_CalculateCRC64函数未实现。

## 10.2 限制

### 10.2.1




