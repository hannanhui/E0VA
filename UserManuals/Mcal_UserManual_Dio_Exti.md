# ChipOn Microcontroller Abstract Layer Users Manual - EXTI Driver
Release V0.1 - May 2024  
Published by ChipOn 

---

## 变更记录


| 时间       | 版本 | 变更记录    |
| :--------- | :--- | :---------- |
| 2025-01-15 | 0.1  | 初       版 |


----

<a name="br4"></a> 



## 目录
- [ChipOn Microcontroller Abstract Layer Users Manual - EXTI Driver](#chipon-microcontroller-abstract-layer-users-manual---exti-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 EXTI Driver概述](#第2章-exti-driver概述)
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
    - [6.1.1 类型定义 Dio\_ExtiCallBackFcnType](#611-类型定义-dio_exticallbackfcntype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Dio\_ExtiCallBackRegister](#621-dio_exticallbackregister)
    - [6.2.2 Dio\_ExtiPinEintEnable](#622-dio_extipineintenable)
    - [6.2.3 Dio\_ExtiPinEintDisable](#623-dio_extipineintdisable)
    - [6.2.7 Dio\_ExtiGetVersionInfo](#627-dio_extigetversioninfo)
  - [6.3 中断处理](#63-中断处理)
  - [6.4 专有区域（EA）信息](#64-专有区域ea信息)
    - [6.4.1 专有区域信息](#641-专有区域信息)
- [第7章 数据描述](#第7章-数据描述)
  - [7.1 全局数据描述](#71-全局数据描述)
      - [表80 全局数据描述](#表80-全局数据描述)
- [第8章 错误分类](#第8章-错误分类)
  - [8.1 错误代码和描述](#81-错误代码和描述)
- [第9章 示例用法](#第9章-示例用法)
  - [9.1 系统时钟配置注意事项](#91-系统时钟配置注意事项)
  - [9.2 宏配置](#92-宏配置)
  - [9.3 接口使用示例](#93-接口使用示例)
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

本用户手册提供了AUTOSAR CP R22-11的GPIO中断驱动程序的功能和API实现的相关信息。EXTI的驱动程序初始化并提供对微控制器的访问。本用户手册旨在帮助用户熟悉EXTI驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用EXTI驱动程序的文档。

## 1.1 范围

本文档介绍EXTI驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- EXTI Driver的文件结构
- Driver的配置参数
- 由EXTI Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于EXTI Driver

## 1.2 缩写

| 缩写        | 解释                                |
| :---------- | :---------------------------------- |
| AUTOSAR     | 汽车汽车开放系统架构                |
| API         | 应用程序接口                        |
| EXTI        | GPIO外部中断                        |
| DIO Channel | 一个通用的数字IO引脚表示一个DIO通道 |
| DEM         | 诊断事件管理器                      |
| DET         | 开发错误跟踪器                      |
| GPIO        | 通用输入输出                        |
| BSW         | 基础软件                            |
| HW          | 硬件                                |
| ID          | 标识符                              |
| MCAL        | 微控制器抽象层                      |
| MCU         | 微控制器                            |

## 1.3 参考

- KF32A158xxxSF用户手册V1.0
- KF32A158xxxSF数据手册V1.3

-----
# 第2章 EXTI Driver概述
KF32微控制器提供EXTI操作方式。

### 2.1 PORT
EXTI使用的引脚需要由Port驱动程序配置。
有关PORT配置的详细信息，参考PORT用户手册

-----

# 第3章 文件结构
本节提供了有关EXTI Driver文件和其他相关文件的详细信息。
| Name       | Description                                      |
| :--------- | :----------------------------------------------- |
| Dio_Exti.c | 此文件包含EXTI驱动程序的通用功能                 |
| Dio_Exti.h | 此头文件输出EXTI驱动程序的宏、类型定义和函数原型 |
| Exti_Irq.c | 中断处理函数                                     |

-----

# 第4章 配置文档

无
-----

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: DIO_EXTI_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Dio_Exti.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: DIO_EXTI_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: Dio_Exti.h
- **值**: 254
- **描述**: 这个宏给出了EXTI驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: DIO_EXTI_INSTANCE_ID
- **类型**: 宏定义 (#define)
- **文件**: Dio_Exti.h
- **值**: 0
- **描述**: 这个宏给出了EXTI驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: DIO_EXTI_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Dio_Exti.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: DIO_EXTI_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Dio_Exti.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: DIO_EXTI_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Dio_Exti.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Dio_ExtiCallBackFcnType
- **语法**: Dio_ExtiCallBackFcnType
- **类型**: 函数指针
- **文件**: Dio_Exti.h
- **范围**:             
- **描述**: 此类型定义用于注册中断回调函数使用。

---
## 6.2 API函数

### 6.2.1 Dio_ExtiCallBackRegister
- **服务名称**: `Dio_ExtiCallBackRegister`
- **语法**: `void Dio_ExtiCallBackRegister(Dio_ExtiCallBackFcnType DioExtiCallbackFunc)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: DioExtiCallbackFunc - 回调函数
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 注册回调函数
- **注意事项**: 回调函数有入参，是ChannelId，所以所有的中断处理函数一个回调函数就可以了，在函数内部根据不同管脚做处理

### 6.2.2 Dio_ExtiPinEintEnable
- **服务名称**: `Dio_ExtiPinEintEnable`
- **语法**: `void Dio_ExtiPinEintEnable(Dio_ChannelType ChannelId, Dio_ExtiPinEintType Mode)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: ChannelId - 高4位PORT索引号，低四位PIN索引号
- **参数(输入)**: Mode - 中断模式
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置某个端口的PIN管脚中断模式
- **注意事项**: 无

### 6.2.3 Dio_ExtiPinEintDisable
- **服务名称**: `Dio_ExtiPinEintDisable`
- **语法**: `void Dio_ExtiPinEintDisable(Dio_ChannelType ChannelId)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: PortId - PORT索引号
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 关闭某个端口的PIN管脚中断模式
- **注意事项**: 无 

### 6.2.7 Dio_ExtiGetVersionInfo
- **服务名称**: `Dio_ExtiGetVersionInfo`
- **语法**: `void Dio_ExtiGetVersionInfo(Std_VersionInfoType *VersionInfo)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x03
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:无
- **参数(输出)**: VersionInfo-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无


-----
## 6.3 中断处理

中断服务例程在EXTI Driver中用于通知。

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

EXTI Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是EXTI Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数              | 类型/范围              | 描述                   |
| ----------------- | ---------------------- | ---------------------- |
| Dio_ExtiModulePtr | GpioExti_RegisterMap_t | GPIO中断寄存器操作地址 |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
使用DIO中定义的错误代码及其描述。


-----
# 第9章 示例用法
本章描述了如何配置EXTI驱动器以及如何在应用程序中使用EXTI驱动器提供的不同的API。

## 9.1 系统时钟配置注意事项

无

## 9.2 宏配置

```c
#define PB_UNIFIED_INTERRUPT        (STD_ON)
```
## 9.3 接口使用示例

注册回调函数，使能PB4上升沿触发中断
```c
	  Dio_ExtiCallBackRegister(Dio_ExtiCallbackExample);
    Dio_ExtiPinEintEnable(DIO_CHANNEL_B_4, DIO_EXTI_RISE);
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




