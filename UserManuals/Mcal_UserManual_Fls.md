# ChipOn Microcontroller Abstract Layer Users Manual - Fls Driver
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

- [ChipOn Microcontroller Abstract Layer Users Manual - Fls Driver](#chipon-microcontroller-abstract-layer-users-manual---fls-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 FLS Driver概述](#第2章-fls-driver概述)
    - [2.1 系统时钟](#21-系统时钟)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 FlsGeneral](#43-flsgeneral)
    - [4.3.1 FlsAcLoadOnJobStart](#431-flsacloadonjobstart)
    - [4.3.2 FlsBaseAddress](#432-flsbaseaddress)
    - [4.3.3 FlsBlankCheckApi](#433-flsblankcheckapi)
    - [4.3.4 FlsCancelApi](#434-flscancelapi)
    - [4.3.5 FlsCompareApi](#435-flscompareapi)
    - [4.3.6 FlsDevErrorDetect](#436-flsdeverrordetect)
    - [4.3.7 FlsDriverIndex](#437-flsdriverindex)
    - [4.3.8 FlsEraseVerificationEnabled](#438-flseraseverificationenabled)
    - [4.3.9 FlsGetJobResultApi](#439-flsgetjobresultapi)
    - [4.3.10 FlsGetStatusApi](#4310-flsgetstatusapi)
    - [4.3.11 FlsSetModeApi](#4311-flssetmodeapi)
    - [4.3.12 FlsTimeoutSupervisionEnabled](#4312-flstimeoutsupervisionenabled)
    - [4.3.13 FlsTotalSize](#4313-flstotalsize)
    - [4.3.14 FlsVersionInfoApi](#4314-flsversioninfoapi)
    - [4.3.15 FlsWriteVerificationEnabled](#4315-flswriteverificationenabled)
  - [4.4 Fls\_ConfigPredefined](#44-fls_configpredefined)
    - [4.4.1 Fls\_ConfigPredefined](#441-fls_configpredefined)
    - [4.4.2 FlsJobEndNotification](#442-flsjobendnotification)
    - [4.4.3 FlsJobErrorNotification](#443-flsjoberrornotification)
    - [4.4.3 FlsMaxReadFastMode](#443-flsmaxreadfastmode)
    - [4.4.3 FlsMaxReadNormalMode](#443-flsmaxreadnormalmode)
  - [4.5 FlsSector](#45-flssector)
    - [4.5.1 FlsNumberOfSectors](#451-flsnumberofsectors)
    - [4.5.2 FlsPageSize](#452-flspagesize)
    - [4.5.3 FlsSectorSize](#453-flssectorsize)
    - [4.5.4 FlsSectorStartaddress](#454-flssectorstartaddress)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Fls\_ConfigType](#611-类型定义-fls_configtype)
    - [6.1.2 宏定义 FLASH\_BASE\_ADDR](#612-宏定义-flash_base_addr)
    - [6.1.3 宏定义 FLASH\_TOTAL\_SIZE](#613-宏定义-flash_total_size)
    - [6.1.4 宏定义 FLASH\_SECTOR\_SIZE](#614-宏定义-flash_sector_size)
    - [6.1.5 宏定义 FLASH\_PAGE\_SIZE](#615-宏定义-flash_page_size)
    - [6.1.6 宏定义 FLS\_NUMBER\_OF\_SECTORS](#616-宏定义-fls_number_of_sectors)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Fls\_Init](#621-fls_init)
    - [6.2.2 Fls\_Erase](#622-fls_erase)
    - [6.2.3 Fls\_Write](#623-fls_write)
    - [6.2.4 Fls\_Cancel](#624-fls_cancel)
    - [6.2.5 Fls\_GetStatus](#625-fls_getstatus)
    - [6.2.6 Fls\_GetJobResult](#626-fls_getjobresult)
    - [6.2.7 Fls\_Read](#627-fls_read)
    - [6.2.8 Fls\_Compare](#628-fls_compare)
    - [6.2.9 Fls\_SetMode](#629-fls_setmode)
    - [6.2.10 Fls\_GetVersionInfo](#6210-fls_getversioninfo)
    - [6.2.11 Fls\_BlankCheck](#6211-fls_blankcheck)
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
  - [9.1 宏配置](#91-宏配置)
  - [9.2 初始化](#92-初始化)
  - [9.3 FLS写操作](#93-fls写操作)
  - [9.4 FLS读操作](#94-fls读操作)
  - [9.5 配置示例](#95-配置示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)
    - [10.2.1](#1021)

---

# 第1章 引言

本用户手册提供了AUTOSAR CP R22-11的FLS驱动程序的功能、配置参数和API实现的相关信息。FLS的驱动程序初始化并提供对微控制器的访问。本用户手册旨在帮助用户熟悉FLS驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用FLS驱动程序的文档。

## 1.1 范围

本文档涉及FLS Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- FLS Driver的文件结构
- Driver的配置参数
- 由FLS Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于FLS Driver

## 1.2 缩写

| 缩写    | 解释                                                 |
| :------ | :--------------------------------------------------- |
| AUTOSAR | 汽车汽车开放系统架构                                 |
| DEM     | 诊断事件管理器                                       |
| DET     | 开发错误跟踪器                                       |
| FLS     | 模块闪存驱动程序的官方自动存储器缩写                 |
| MCU     | 微控制器                                             |
| API     | 应用程序编程接口                                     |
| AC      | (Flash)访问代码-引入以保持配置参数的名称合理短的缩写 |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] Specification of FlashDriver, AUTOSAR_SWS_FlashDriver.pdf Release R22-11
- [2] Requirements of FlashDriver, AUTOSAR_SRS_FlashDriver.pdf Release R22-11
- [3] KF32A158xxxSF用户手册V1.0
- [4] KF32A158xxxSF数据手册V1.3

-----
# 第2章 FLS Driver概述
KF32微控制器提供FLS操作方式。驱动程序还为用户提供了保存数据功能。

### 2.1 系统时钟
系统时钟通过MCU驱动程序设置。有关FLS配置的详细信息，参考用户手册。

---

# 第3章 文件结构
本节提供了有关FLS Driver文件和其他相关文件的详细信息。
| Name        | Description                                     |
| :---------- | :---------------------------------------------- |
| Fls.c       | 此文件包含FLS驱动程序的通用功能                 |
| Fls.h       | 此头文件输出FLS驱动程序的宏、类型定义和函数原型 |
| Fls_Cfg.h   | 本文在这里声明了FLS驱动程序的配置数据。         |
| Fls_Im.c    | 此文件包含FLS模块所需要的硬件驱动程序           |
| Fls_Im.h    | 此头文件输出FLS驱动程序的宏、类型定义和函数原型 |
| Fls_Types.h | 结构体定义                                      |
| Fls_LCfg.c  | 初始化结构体定义                                |
| Fls_LCfg.h  | 初始化结构体声明                                |


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
本节描述了相对于支持的微控制器的配置参数的变化。FLS Driver在支持的微控制器上没有变化的参数。

## 4.3 FlsGeneral
本节详细描述了FLS Driver提供的配置，包括AUTOSAR FLS Driver规范[1]中描述的配置以及特定于微控制器的配置。

### 4.3.1 FlsAcLoadOnJobStart
- **名称**: FlsAcLoadOnJobStart
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：true – STD_ON，false – STD_OFF，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.2 FlsBaseAddress
- **名称**: FlsBaseAddress
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：0x00077800U
- **配置类别**: 预编译时间 X 所有变体

### 4.3.3 FlsBlankCheckApi
- **名称**: FlsBlankCheckApi
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开检测，STD_OFF – 不打开检测 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.4 FlsCancelApi
- **名称**: FlsCancelApi
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开取消操作，STD_OFF – 关闭取消操作 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.5 FlsCompareApi
- **名称**: FlsCompareApi
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开比较API，STD_OFF – 不使用比较API ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.6 FlsDevErrorDetect
- **名称**: FlsDevErrorDetect
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开DET检测，STD_OFF – 关闭DET检测 ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.7 FlsDriverIndex
- **名称**: FlsDriverIndex
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：0
- **配置类别**: 预编译时间 X 所有变体

### 4.3.8 FlsEraseVerificationEnabled
- **名称**: FlsEraseVerificationEnabled
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开擦除后校验，STD_OFF – 关闭擦除后校验 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.9 FlsGetJobResultApi
- **名称**: FlsGetJobResultApi
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开获取JOB操作结果API，STD_OFF – 关闭获取JOB操作结果API ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.10 FlsGetStatusApi
- **名称**: FlsGetStatusApi
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开获取状态API，STD_OFF – 关闭获取状体API ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.11 FlsSetModeApi
- **名称**: FlsSetModeApi
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开设置模式API，STD_OFF – 关闭设置模式API ，默认值：STD_OFF
- **配置类别**: 预编译时间 X 所有变体

### 4.3.12 FlsTimeoutSupervisionEnabled
- **名称**: FlsTimeoutSupervisionEnabled
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开超时检测，STD_OFF – 关闭超时检测 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.13 FlsTotalSize
- **名称**: FlsTotalSize
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 32U * 1024U
- **配置类别**: 预编译时间 X 所有变体

### 4.3.14 FlsVersionInfoApi
- **名称**: FlsVersionInfoApi
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开获取版本号API，STD_OFF – 关闭获取版本号API ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

### 4.3.15 FlsWriteVerificationEnabled
- **名称**: FlsWriteVerificationEnabled
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 值：STD_ON – 打开写校验功能，STD_OFF – 关闭写校验功能 ，默认值：STD_ON
- **配置类别**: 预编译时间 X 所有变体

---
## 4.4 Fls_ConfigPredefined

### 4.4.1 Fls_ConfigPredefined
- **名称**: Fls_ConfigPredefined
- **来源**: AUTOSAR定义，
- **文件**: Fls_Types.h

### 4.4.2 FlsJobEndNotification
- **名称**: FlsJobEndNotification
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 
- **配置类别**: 预编译时间 X 所有变体

### 4.4.3 FlsJobErrorNotification
- **名称**: FlsJobErrorNotification
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 
- **配置类别**: 预编译时间 X 所有变体

### 4.4.3 FlsMaxReadFastMode
- **名称**: FlsMaxReadFastMode
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: FLS最大空间
- **配置类别**: 预编译时间 X 所有变体

### 4.4.3 FlsMaxReadNormalMode
- **名称**: FlsMaxReadNormalMode
- **来源**: AUTOSAR定义
- **文件**: Fls_Cfg.h
- **范围**: 2048
- **配置类别**: 预编译时间 X 所有变体

---
## 4.5 FlsSector

### 4.5.1 FlsNumberOfSectors
- **名称**: FlsNumberOfSectors
- **来源**: AUTOSAR定义，
- **文件**: Fls_Cfg.h
- **范围**: 0~*，根据FLASH配置空间大小而定
- **配置类别**: 预编译时间 X 所有变体

### 4.5.2 FlsPageSize
- **名称**: FlsPageSize
- **来源**: AUTOSAR定义，
- **文件**: Fls_Cfg.h
- **范围**: 16
- **配置类别**: 预编译时间 X 所有变体

### 4.5.3 FlsSectorSize
- **名称**: FlsSectorSize
- **来源**: AUTOSAR定义，
- **文件**: Fls_Cfg.h
- **范围**: 2048
- **配置类别**: 预编译时间 X 所有变体

### 4.5.4 FlsSectorStartaddress
- **名称**: FlsSectorStartaddress
- **来源**: AUTOSAR定义，
- **文件**: Fls_Cfg.h
- **范围**: 逻辑地址是0，每个Sector根据secotor大小而定
- **配置类别**: 预编译时间 X 所有变体

------
# 第5章 发布的参数

## 5.1 VendorId
- **语法**: FLS_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Fls.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: FLS_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Fls.h
- **值**: 92
- **描述**: 这个宏给出了FLS驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: FLS_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Fls.h
- **值**: 0
- **描述**: 这个宏给出了FLS驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: FLS_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Fls.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: FLS_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Fls.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: FLS_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Fls.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Fls_ConfigType
- **语法**: Fls_ConfigType
- **类型**: Struct
- **文件**: Fls_Types.h
- **范围**: 
  - **Fls_ErasePtrType**
    - EraseProcessPtr - 擦除函数指针
  - **Fls_WritePtrType**
    - WritePageProcessPtr - 页写函数指针    
  - **Fls_WritePtrType**
    - WriteSectorProcessPtr - 扇区写函数指针
  - **Fls_NotificationPtrType**
    - JobEndNotificationPtr - 擦除完成函数指针    
  - **Fls_NotificationPtrType**
    - JobErrorNotificationPtr - JOB操作出错函数指针
  - **Fls_NotificationPtrType**
    - StartFlashAccessNotificationPtr - 开始擦除或写函数指针        
  - **Fls_NotificationPtrType**
    - FinishedFlashAccessNotificationPtr - 擦除或写结束函数指针      
  - **Fls_FeedWdgProcessPtrType**
    - FeedDogProcessPtr - 喂狗函数指针,操作外部喂狗   
  - **MemIf_ModeType**
    - DefaultMode - 默认模式   
  - **Fls_LengthType**
    - ReadFastSize - 快速读大小   
  - **Fls_LengthType**
    - WriteFastSize - 快速写大小   
  - **Fls_LengthType**
    - ReadNormalSize - 正常读大小   
  - **Fls_LengthType**
    - WriteNormalSize - 正常写大小   
  - **Fls_LengthType**
    - PhysicalStartAddr - FLASH操作起始地址   
  - **Fls_LengthType**
    - FlashTotalSize - FLASH总大小        
- **描述**: 此类型定义用于配置FLS的整体配置。此类型的指针在Fls_Init API中用于初始化FLS驱动程序。

### 6.1.2 宏定义 FLASH_BASE_ADDR
- **语法**: 
- **类型**: 
- **文件**: Fls_Cfg.h
- **范围**: 0x00077800U
- **描述**: FLS的基地址，根据需求可修改

### 6.1.3 宏定义 FLASH_TOTAL_SIZE
- **语法**: 
- **类型**: 
- **文件**: Fls_Cfg.h
- **范围**: 32U * 1024U
- **描述**: FLS的使用大小，根据需求可修改

### 6.1.4 宏定义 FLASH_SECTOR_SIZE
- **语法**: 
- **类型**: 
- **文件**: Fls_Cfg.h
- **范围**: 2048U
- **描述**: FLS的扇区大小，不可修改

### 6.1.5 宏定义 FLASH_PAGE_SIZE
- **语法**: 
- **类型**: 
- **文件**: Fls_Cfg.h
- **范围**: 2048U
- **描述**: FLS的页大小，不可修改

### 6.1.6 宏定义 FLS_NUMBER_OF_SECTORS
- **语法**: 
- **类型**: 
- **文件**: Fls_Cfg.h
- **范围**: 2048U
- **描述**: FLS的扇区个数，根据FLS大小可修改

---
## 6.2 API函数

### 6.2.1 Fls_Init
- **服务名称**: `Fls_Init`
- **语法**: `void Fls_Init (const Fls_ConfigType* ConfigPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: ConfigPtr: 配置参数指针
- **返回值**: 无
- **描述**: FLS模块初始化
- **注意事项**: 无

### 6.2.2 Fls_Erase
- **服务名称**: `Fls_Erase`
- **语法**: `Std_ReturnType Fls_Erase (Fls_AddressType TargetAddress,Fls_LengthType Length)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 异步
- **可重入**: 不可重入
- **参数(输入)**: TargetAddress-擦除地址
- **参数(输入)**: Length-擦除长度
- **参数(输出)**: 无
- **返回值**: E_OK-擦除操作可执行
- **返回值**: E_NOT_OK-擦除操作不可执行
- **描述**: 扇区擦除
- **注意事项**: TargetAddress目标地址是配置参数内扇区的起始地址；Fls_LengthType扇区大小

### 6.2.3 Fls_Write
- **服务名称**: `Fls_Write`
- **语法**: `Std_ReturnType Fls_Write (Fls_AddressType TargetAddress,const uint8* SourceAddressPtr,Fls_LengthType Length)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x02
- **同步/异步**: 异步
- **可重入**: 不可重入
- **参数(输入)**: TargetAddress-写地址
- **参数(输入)**: SourceAddressPtr-写数据指针
- **参数(输入)**: Length-写长度
- **参数(输出)**: 无
- **返回值**: E_OK-写操作可执行
- **返回值**: E_NOT_OK-写操作不可执行
- **描述**: 扇区写数据
- **注意事项**: TargetAddress目标地址是配置参数内扇区的起始地址；Fls_LengthType是页大小的整数倍 

### 6.2.4 Fls_Cancel
- **服务名称**: `Fls_Cancel`
- **语法**: `void Fls_Cancel (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 取消正在执行的JOB操作
- **注意事项**: 无

### 6.2.5 Fls_GetStatus
- **服务名称**: `Fls_GetStatus`
- **语法**: `MemIf_StatusType Fls_GetStatus (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: MEMIF_UNINIT-FLS未初始化
- **返回值**: MEMIF_IDLE-当前状态空闲，无操作
- **返回值**: MEMIF_BUSY-FLS在执行中
- **描述**: 获取FLS状态
- **注意事项**: 无

### 6.2.6 Fls_GetJobResult
- **服务名称**: `Fls_GetJobResult`
- **语法**: `MemIf_JobResultType Fls_GetJobResult (void)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x05
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: MEMIF_JOB_OK-执行成功
- **返回值**: MEMIF_JOB_FAILED-执行成功
- **返回值**: MEMIF_JOB_PENDING-执行成功
- **返回值**: MEMIF_JOB_CANCELED-执行成功
- **返回值**: MEMIF_BLOCK_INCONSISTENT-执行成功
- **描述**: 读取JOB结果状态
- **注意事项**: 无

### 6.2.7 Fls_Read
- **服务名称**: `Fls_Read`
- **语法**: `Std_ReturnType Fls_Read (Fls_AddressType SourceAddress,uint8* TargetAddressPtr,Fls_LengthType Length)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x07
- **同步/异步**: 异步
- **可重入**: 不可重入
- **参数(输入)**: SourceAddress-读地址
- **参数(输入)**: TargetAddressPtr-读取数据存放指针
- **参数(输入)**: Length-读长度
- **参数(输出)**: 无
- **返回值**: E_OK-读操作可执行
- **返回值**: E_NOT_OK-读操作不可执行
- **描述**: 读取数据
- **注意事项**: 读取地址加读长度小于FLS配置的总大小

### 6.2.8 Fls_Compare
- **服务名称**: `Fls_Compare`
- **语法**: `Std_ReturnType Fls_Compare (Fls_AddressType SourceAddress,const uint8* TargetAddressPtr,Fls_LengthType Length)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x08
- **同步/异步**: 异步
- **可重入**: 不可重入
- **参数(输入)**: SourceAddress-比较地址
- **参数(输入)**: TargetAddressPtr-比较内容指针
- **参数(输入)**: Length-比较内容长度
- **参数(输出)**: 无
- **返回值**: E_OK-比较操作可执行
- **返回值**: E_NOT_OK-比较操作不可执行
- **描述**: FLS地址数据和内存数据内容比较
- **注意事项**: 比较地址加比较长度小于FLS配置的总大小

### 6.2.9 Fls_SetMode
- **服务名称**: `Fls_SetMode`
- **语法**: `void Fls_SetMode (MemIf_ModeType Mode)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x09
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**:Mode-读模式
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 设置操作模式
- **注意事项**: 无

### 6.2.10 Fls_GetVersionInfo
- **服务名称**: `Fls_GetVersionInfo`
- **语法**: `void Fls_GetVersionInfo (Std_VersionInfoType* VersioninfoPtr)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x10
- **同步/异步**: 同步
- **可重入**: 可重入
- **参数(输入)**:无
- **参数(输出)**: VersioninfoPtr-版本信息
- **返回值**: 无
- **描述**: 获取软件版本号
- **注意事项**: 无

### 6.2.11 Fls_BlankCheck
- **服务名称**: `Fls_BlankCheck`
- **语法**: `Std_ReturnType Fls_BlankCheck (Fls_AddressType TargetAddress,Fls_LengthType Length)`
- **来源**: 此API由AUTOSAR定义。
- **服务ID**:0x0A
- **同步/异步**: 异步
- **可重入**: 不可重入
- **参数(输入)**: TargetAddress-检测地址
- **参数(输入)**: Length-检测长度
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 块检测是否为0xFF
- **注意事项**: 无

-----
## 6.3 中断处理

无

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

FLS Driver没有提供专有区域。

-----
# 第7章 数据描述

## 7.1 全局数据描述
以下是FLS Driver中使用的所有全局和静态变量的列表。

#### 表80 全局数据描述

| 参数                    | 类型/范围            | 描述             |
| ----------------------- | -------------------- | ---------------- |
| Fls_ReadAddressPtr      | Fls_DataBusWidthType | 读操作地址记录   |
| Fls_CompareAddressPtr   | Fls_DataBusWidthType | 比较地址记录     |
| Fls_TargetAddressPtr    | Fls_DataBusWidthType | 操作地址记录     |
| Fls_ErasedFaultValue    | Fls_DataAccWidthType | 擦除后默认值     |
| Fls_JobOperateAddrStart | Fls_AddressType      | JOB操作起始地址  |
| Fls_JobSectorEnd        | Fls_SectorIndexType  | JOB结束地址      |
| Fls_JobOperate          | Fls_JobOperateType   | JOB操作类型      |
| Fls_MaxRead             | Fls_LengthType       | 记录读取最大长度 |
| Fls_JobOperateAddrEnd   | Fls_AddressType      | JOB操作结束地址  |
| Fls_ModuleState         | MemIf_StatusType     | FLS初始化状态    |
| Fls_JobResult           | MemIf_JobResultType  | JOB操作结果      |
| Fls_JobDataSrcPtr       | uint8                | 操作原始地址记录 |
| Fls_JobDataDestPtr      | uint8                | 操作目标地址记录 |
| Fls_JobStartStatus      | boolean              | JOB操作开始状态  |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是FLS Driver中定义的错误代码及其描述。

#### 表81 错误分类

| 错误代码                  | 错误描述            | 值（十六进制） |
| ------------------------- | ------------------- | -------------- |
| FLS_E_PARAM_CONFIG        | 初始化参数空指针    | 0x01           |
| FLS_E_PARAM_ADDRESS       | 操作地址范围错误    | 0x02           |
| FLS_E_PARAM_LENGTH        | 操作长度错误        | 0x03           |
| FLS_E_PARAM_DATA          | 操作地址空指针      | 0x04           |
| FLS_E_UNINIT              | 未初始化            | 0x05           |
| FLS_E_PARAM_POINTER       | 获取版本号空指针    | 0x0A           |
| FLS_E_ALREADY_INITIALIZED | 重复初始化          | 0x0B           |
| FLS_E_BUSY                | JOB操作中，重入操作 | 0x06           |
| FLS_E_VERIFY_ERASE_FAILED | 擦除校验出错        | 0x07           |
| FLS_E_VERIFY_WRITE_FAILED | 写校验出错          | 0x08           |
| FLS_E_ERASE_FAILED        | 擦除失败            | 0x01           |
| FLS_E_WRITE_FAILED        | 写失败              | 0x02           |
| FLS_E_READ_FAILED         | 读失败              | 0x03           |
| FLS_E_COMPARE_FAILED      | 比较失败            | 0x18           |

-----
# 第9章 示例用法
本章描述了如何配置FLS驱动器以及如何在应用程序中使用FLS驱动器提供的不同的API。

## 9.1 宏配置

```c
#define FLS_DEV_ERROR_DETECT (STD_OFF)
#define FLS_PRECOMPILE_SUPPORT (STD_OFF)
#define FLS_AC_LOAD_ON_JOB_START (STD_OFF)
#define FLS_ASYNC_OPERATE_ENABLED (STD_OFF)
#define FLS_CANCEL_API (STD_ON)
#define FLS_COMPARE_API (STD_ON)
#define FLS_GET_JOB_RESULT_API (STD_ON)
#define FLS_GET_STATUS_API (STD_ON)
#define FLS_SET_MODE_API (STD_ON)
#define FLS_VERSION_INFO_API (STD_ON)
#define FLS_BLANK_CHECK_API (STD_ON)
#define FLS_WRITE_VERIFICATION_ENABLED (STD_ON)
#define FLS_RUNTIME_ERROR_DETECT (STD_ON)
#define FLS_WRITE_BLANK_CHECK (STD_ON)
#define FLS_ERASE_BLANK_CHECK (STD_ON)
#define FLS_TIMEOUT_ENABLED (STD_ON)

/**
 * @brief The min address of flash can be operated
 *
 * @note The minimum address unit is in bytes
 * @note "(1u << 10u)" means 1KB
 */
#define FLS_MIN_OPERABLE_ADDRESS (1U << 10U)

/**
 * @brief flash base address
 */
#define FLASH_BASE_ADDR (0x001F0000U)

/**
 * @brief The total amount of flash memory in bytes (see also SWS_Fls_00208 and SWS_Fls_00209).
 * This parameter in conjunction with FLS_BASE_ADDRESS defines the upper boundary
 * for read / write / erase and compare jobs.
 *
 * @note The size must be an integer multiple of the sector(2048)
 *
 * @details Page Size 16Byte;Sector Size 2048Byte;
 *
 * @implements #ECUC_Fls_00170
 */
#define FLASH_TOTAL_SIZE (32U * 2048U)
```
## 9.2 初始化

- 关闭固定配置情
```c
#define FLS_PRECOMPILE_SUPPORT (STD_OFF)

Fls_Init(&Fls_ConfigPredefined);

```
- 打开固定配置
```c
#define FLS_PRECOMPILE_SUPPORT (STD_ON)

Fls_Init(NULL_PTR);

```

## 9.3 FLS写操作

先擦除，在写入，写入数据长度是页大小的整数倍
```c

Fls_Erase(2048,FLASH_SECTOR_SIZE);

while(Fls_GetStatus() != MEMIF_IDLE)
{
  Fls_MainFunction();
}

Fls_Write(2048,128);

while(Fls_GetStatus() != MEMIF_IDLE)
{
  Fls_MainFunction();
}
```
## 9.4 FLS读操作

```c
Fls_Read(2048,&ReadBuffer[0U],128);

while(Fls_GetStatus() != MEMIF_IDLE)
{
  Fls_MainFunction();
}
```

## 9.5 配置示例

```c
/**
 * @brief flash config information
 *
 * @details Page Size 16Byte;Sector Size 2048Byte
 */
/* PRQA S 3211 2 # The global identifier '%1s' is defined here but is not used in this translation unit */
/* PRQA S 0313  ++*/
CONST(Fls_ConfigType, FLS_CONST)
Fls_ConfigPredefined = {
  /** @brief pointer to erase function */
  .EraseProcessPtr = (Fls_ErasePtrType)&__FLASH_Erase__,
  /** @brief pointer to write page function */
  .WritePageProcessPtr = (Fls_WritePtrType)&__FLASH_Program_NBytes__,
  /** @brief pointer to write sector function */
  .WriteSectorProcessPtr = (Fls_WritePtrType)&__FLASH_Program__,
  /** @brief function pointer for JobEndNotification */
  .JobEndNotificationPtr = NULL_PTR,
  /** @brief function pointer for JobErrorNotification */
  .JobErrorNotificationPtr = NULL_PTR,
  /** @brief function pointer for StartFlashAccessNotification */
  .StartFlashAccessNotificationPtr = NULL_PTR,
  /** @brief function pointer for FinishedFlashAccessNotification */
  .FinishedFlashAccessNotificationPtr = NULL_PTR,
  /** @brief function pointer for feed dog */
  .FeedDogProcessPtr = NULL_PTR,
  /** @brief default fls device mode */
  .DefaultMode = MEMIF_MODE_FAST,
  /** @brief fast read size */
  .ReadFastSize = FLASH_TOTAL_SIZE,
  /** @brief fast write size */
  .WriteFastSize = FLASH_FAST_WRITE_MAX_SIZE,
  /** @brief normal read size */
  .ReadNormalSize = FLASH_SECTOR_SIZE,
  /** @brief normal read size */
  .WriteNormalSize = FLASH_PAGE_SIZE,
  /** @brief physical start address */
  .PhysicalStartAddr = FLASH_BASE_ADDR,
  /** @brief flash total size */
  .FlashTotalSize = FLASH_TOTAL_SIZE,
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

- 不支持取消操作。
- 不支持异步读写。


## 10.2 限制

### 10.2.1




