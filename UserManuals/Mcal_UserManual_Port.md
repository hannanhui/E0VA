# ChipOn Microcontroller Abstract Layer Users Manual - PORT Driver
Release V0.1 - May 2024  
Published by ChipOn


---

## 变更记录
| 日期       | 版本 | 变更记录 |
| ---------- | ---- | :------- |
| 2024.05.14 | 0.1  | 初版创建 |
---

## 目录

- [ChipOn Microcontroller Abstract Layer Users Manual - PORT Driver](#chipon-microcontroller-abstract-layer-users-manual---port-driver)
  - [变更记录](#变更记录)
  - [| 2024.05.14 | 0.1  | 初版创建 |](#-20240514--01---初版创建-)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
- [1.3 参考资料](#13-参考资料)
- [第2章 Port Driver概述](#第2章-port-driver概述)
  - [2.1 PORT](#21-port)
  - [2.2 IRQ](#22-irq)
  - [2.3 系统时钟](#23-系统时钟)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 Port\_Cfg.h文件配置说明](#43-port_cfgh文件配置说明)
  - [4.4 Port\_LCfg.c文件配置说明](#44-port_lcfgc文件配置说明)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Port\_ConfigType](#611-类型定义-port_configtype)
    - [6.1.2 类型定义 Port\_PinConfigType](#612-类型定义-port_pinconfigtype)
    - [6.1.3 类型定义 Port\_PinModeType](#613-类型定义-port_pinmodetype)
    - [6.1.4 类型定义 Port\_PinDirectionType](#614-类型定义-port_pindirectiontype)
    - [6.1.5 类型定义 Port\_PinType](#615-类型定义-port_pintype)
  - [6.2 API接口](#62-api接口)
    - [6.2.1 Port\_GetVersionInfo](#621-port_getversioninfo)
    - [6.2.2 Port\_Init](#622-port_init)
    - [6.2.3 Port\_SetPinDirection](#623-port_setpindirection)
    - [6.2.4 Port\_RefreshPortDirection](#624-port_refreshportdirection)
    - [6.2.5 Port\_SetPinMode](#625-port_setpinmode)
  - [6.3 中断处理](#63-中断处理)
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

本用户手册提供了有关Port驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的Port驱动程序实现。该文档描述了如何使用Port驱动程序
 

## 1.1 范围
本文档涉及Port Driver实现的以下特性：
-KungFu微控制器硬件外设，用于实现Driver
- Port Driver的文件结构
- Driver的配置参数
- 由Port Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于Port Driver

## 1.2 缩写

- MCAL : Microcontroller Abstract Layer，微控制器抽象层  
- ISR  : Interrupt Service Routine，中断服务程序        

# 1.3 参考资料
- KF32A158xxxSF用户手册V1.0
- KF32A158xxxSF数据手册V1.3
- KF32 系列 ChipON IDE C 语言开发手册 V1.1
- KF32 系列 ChipON IDE 汇编语言开发手册 V1.0
- PORT_Design_Report.md
- AUTOSAR_SWS_PortDriver.pdf
---


# 第2章 Port Driver概述

Port Driver使用KungFu平台的通用同步/异步收发器外设(USART)。Driver可以配置多个Port通道。它同时支持主模式。在收发PORT帧时，帧数据长度最大可以达到8字节，发送速率可以达到 4Mb/s。每个通道都可以进行以下操作：

- 设置Pin脚方向
- 设置Pin脚工作模式
- 错误检测
- 可配置通讯波特率

## 2.1 PORT
使用芯片的GPIO及FlexRM来实现Port Driver

## 2.2 IRQ 
IRQ Driver负责初始化Port Driver所需的中断优先级。

## 2.3 系统时钟
系统时钟通过MCU Driver设置。必须设置适当的系统时钟。

---

# 第3章 文件结构
本节提供了有关Port Driver文件和其他相关文件的详细信息。

| Name         | Description                                          | 是否需要配置 |
| :----------- | :--------------------------------------------------- | ------------ |
| Port.c       | 此文件包含Port驱动程序的通用功能                     | 无需配置     |
| Port.h       | 此头文件输出Port驱动程序的宏、类型定义和函数原型     | 无需配置     |
| FlexRm.c     | 此文件包含 FlexRm 驱动程序的通用功能                 | 无需配置     |
| FlexRm.h     | 此头文件输出 FlexRm 驱动程序的宏、类型定义和函数原型 | 无需配置     |
| FlexRm_Cfg.h | 本文在这里声明了 FlexRm驱动程序的配置数据。          | 无需配置     |
| Port_Cfg.h   | 本文在这里声明了Port驱动程序的配置数据。             | 需要配置     |
| Port_LCfg.c  | 这里定义了Port驱动程序的配置数据                     | 无需配置     |
| Port_Im.c    | 芯片具体实现的API定义                                | 无需配置     |
| Port_Im.h    | 芯片具体实现API声明                                  | 无需配置     |

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
本节描述了相对于支持的微控制器的配置参数的变化。Port Driver在支持的微控制器上没有变化的参数。

## 4.3 Port_Cfg.h文件配置说明

+ PORT_DEV_ERROR_DETECT(需要配置)
> 配置是否检测错误，当使能后，运行过程中检测到的错误将从Det_ReportError接口上报。
>```
>STD_ON  开启错误检测
>STD_OFF 关闭错误检测
>```

+ PORT_PRECOMPILE_SUPPORT(需要配置)
>配置是否使用预编译的配置

>STD_ON:默认使用Port_Config的配置初始化PORT驱动
>``` 
>#define PORT_PRECOMPILE_SUPPORT (STD_ON)
>
>影响Port_Init函数的调用，如：
>Port_Init(NULL_PTR);
>此时Port_Init传入的其他参数将不会起作用，默认将Port_Config作为参数进行初始化
>```

>STD_OFF:不使用默认的参数配置初始化PORT驱动，配置参数需要自行传入
>``` 
>#define PORT_PRECOMPILE_SUPPORT (STD_OFF)
>
>影响Port_Init函数的调用，如：
>Port_Init(&UserPortCfg);
>此时Port_Init需要传入一个Port_ConfigType类型的配置参数UserPortCfg
>```

+ PORT_SET_PIN_DIRECTION_API(需要配置)
> 配置Port_SetPinDirection函数是否使用，此接口用于获取Port驱动软件的版本号
>```
>STD_ON  开启错误检测
>STD_OFF 关闭错误检测
>```

+ PORT_SET_PIN_MODE_API(需要配置)
> 配置Port_SetPinMode函数是否使用，此接口用于获取Port驱动软件的版本号
>```
>STD_ON  使用，函数将被编译进固件
>STD_OFF 不使用，函数将不被编译
>```

+ PORT_VERSION_INFO_API(需要配置)
> 配置Port_GetVersionInfo函数是否使用，此接口用于获取Port驱动软件的版本号
>```
>STD_ON  使用，函数将被编译进固件
>STD_OFF 不使用，函数将不被编译
>```

+ PORT_PIN_TOTAL_NUMBER(需要配置)
> 定义每个Port口最多支持的引脚数量，对于KF32A1x8MQV固定为16
>```
>#define PORT_PIN_TOTAL_NUMBER (16U)
>```

+ 各Port的Pin脚是否可以的配置(需要配置)
> 定义每个Port所有Pin的可用状态
> 0-可用，1-不可用
>```
>默认配置
>#define MASK_PORTA (0x0000U)
>#define MASK_PORTB (0x0000U)
>#define MASK_PORTC (0x8000U)
>#define MASK_PORTD (0x0003U)
>#define MASK_PORTE (0x0000U)
>#define MASK_PORTF (0x0000U)
>#define MASK_PORTG (0x0000U)
>#define MASK_PORTH (0x0804U)
>#define MASK_PORTJ (0x0000U)
>#define MASK_PORTK (0x0000U)
>```

+ Pin脚翻转速率类型宏封装(无需配置)
> 用于区分Pin脚不同的翻转速率
>```
>#define SLEWR_LS ((uint32)0x00U) 低速率
>#define SLEWR_HS ((uint32)0x01U) 高速率
>```

+ Pin脚输出类型宏封装(无需配置)
> 用于区分Pin脚不同的输出类型
>```
>#define POD_PP ((uint32)0x00U) 推挽输出
>#define POD_OD ((uint32)0x01U) 开漏输出
>```

+ Pin脚上下拉类型宏封装(无需配置)
> 用于区分Pin脚不同的上下拉型
>```
>#define PULL_NONE ((uint32)0x00U) 悬空
>#define PULL_UP   ((uint32)0x01U) 上拉
>#define PULL_DOWN ((uint32)0x02U) 下拉
>```

+ Pin脚端口重映射类型宏封装(无需配置)
> 用于区分Pin脚端口的不同重映射功能
>```
>#define GPIO_REMAP_AF0  ((uint32)0x00U)
>#define GPIO_REMAP_AF1  ((uint32)0x01U)
>#define GPIO_REMAP_AF2  ((uint32)0x02U)
>#define GPIO_REMAP_AF3  ((uint32)0x03U)
>#define GPIO_REMAP_AF4  ((uint32)0x04U)
>#define GPIO_REMAP_AF5  ((uint32)0x05U)
>#define GPIO_REMAP_AF6  ((uint32)0x06U)
>#define GPIO_REMAP_AF7  ((uint32)0x07U)
>#define GPIO_REMAP_AF8  ((uint32)0x08U)
>#define GPIO_REMAP_AF9  ((uint32)0x09U)
>#define GPIO_REMAP_AF10 ((uint32)0x0AU)
>#define GPIO_REMAP_AF11 ((uint32)0x0BU)
>#define GPIO_REMAP_AF12 ((uint32)0x0CU)
>#define GPIO_REMAP_AF13 ((uint32)0x0DU)
>#define GPIO_REMAP_AF14 ((uint32)0x0EU)
>
>```

+ Pin脚索引宏封装(无需配置)
> 提供每个Pin脚的宏封装
>```
>#define GPIO_PIN_0  ((uint8)0x00U)
>#define GPIO_PIN_1  ((uint8)0x01U)
>#define GPIO_PIN_2  ((uint8)0x02U)
>#define GPIO_PIN_3  ((uint8)0x03U)
>#define GPIO_PIN_4  ((uint8)0x04U)
>#define GPIO_PIN_5  ((uint8)0x05U)
>#define GPIO_PIN_6  ((uint8)0x06U)
>#define GPIO_PIN_7  ((uint8)0x07U)
>#define GPIO_PIN_8  ((uint8)0x08U)
>#define GPIO_PIN_9  ((uint8)0x09U)
>#define GPIO_PIN_10 ((uint8)0x0AU)
>#define GPIO_PIN_11 ((uint8)0x0BU)
>#define GPIO_PIN_12 ((uint8)0x0CU)
>#define GPIO_PIN_13 ((uint8)0x0DU)
>#define GPIO_PIN_14 ((uint8)0x0EU)
>#define GPIO_PIN_15 ((uint8)0x0FU)
>```

+ Port端口索引宏封装(无需配置)
> 提供MCU每个Port端口的宏封装
>```
>#define GPIO_PORT_A ((uint8)0x00U)
>#define GPIO_PORT_B ((uint8)0x01U)
>#define GPIO_PORT_C ((uint8)0x02U)
>#define GPIO_PORT_D ((uint8)0x03U)
>#define GPIO_PORT_E ((uint8)0x04U)
>#define GPIO_PORT_F ((uint8)0x05U)
>#define GPIO_PORT_G ((uint8)0x06U)
>#define GPIO_PORT_H ((uint8)0x07U)
>```

+ Pin脚工作模式宏封装(无需配置)
> 提供Pin脚工作模式的宏封装
>```
>#define MODE_GPIO_IN ((uint32)0x00U) 输入模式
>#define MODE_GPIO_OUT ((uint32)0x01U) 输出模式
>#define MODE_RMP ((uint32)0x02U) 重映射模式
>#define MODE_AN ((uint32)0x03U) 模拟模式
>```

+ Pin脚方向可修改选项宏封装(无需配置)
> 结构体Port_ConfigType成员IsDirChangeable的可选参数值
>```
>#define DIR_NOT_CHANGEABLE (0x00U) 不可修改
>#define DIR_CHANGEABLE     (0x01U) 可以修改
>```

+ Pin脚初始电平宏封装(无需配置)
> 结构体Port_ConfigType成员PinsLevel的可选参数值
>```
>#define LEVEL_LOW      (0x00U) 输出低电平
>#define LEVEL_HIGH     (0x01U) 输出高电平
>```

+ Pin工作模式可修改选项宏封装(无需配置)
> 结构体Port_ConfigType成员IsPinsModeChangeable的可选参数值
>```
>#define MODE_NOT_CHANGEABLE (0x00U) 不可修改
>#define MODE_CHANGEABLE     (0x01U) 可以修改
>```

+ Pin工作模式可修改选项宏封装(无需配置)
> 结构体Port_ConfigType成员PinsLockSts的可选参数值
>```
>#define MODE_NOT_CHANGEABLE (0x00U) 不可修改
>#define MODE_CHANGEABLE     (0x01U) 可以修改
>```

## 4.4 Port_LCfg.c文件配置说明
 
+ 所有使用到的Pin脚配置数组(需要配置)
> 这里定义了每个使用到的Pin脚的配置参数。
>```
>static const Port_PinConfigType Port_PinInitArr0[];
>   举例：
>        {
>          .PortBase    = GPIO_PORT_E,
>          .PinIndex    = GPIO_PIN_11,
>          .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
>                                        FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
>      #if (PORT_SET_PIN_MODE_API == STD_ON)
>          .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
>      #endif
>          .IsDirChangeable = DIR_NOT_CHANGEABLE,
>         }
>      
>```
> | 配置名称                 | 说明                           |
> |----------------------|------------------------------|
> | PortBase             | 配置该引脚所在Port的索引               |
> | PinIndex             | 配置该引脚在该Port中的Pin索引           |
> | PinsControl          | 配置该引脚的属性，例如上拉、下拉、重映射模式、推挽输出等 |
> | IsPinsModeChangeable | 配置该引脚的工作模式在运行时是否可以修改         |
> | IsDirChangeable      | 配置该引脚的信号方向在运行时是否可以修改         |

+ Port Driver的配置参数(无需配置)
> 这里定义整个Port驱动的配置参数
>```
>const Port_ConfigType Port_ConfigPredefined;
>   举例：
>      {
>        (sizeof(Port_PinInitArr0) / sizeof(Port_PinConfigType)), &Port_PinInitArr0[0U]
>      };
>```
> | 配置名称             | 说明         |
> |------------------|------------|
> | NumConfig        | 存储已配置引脚的数量 |
> | PortPinConfigPtr | 存储引脚配置数组指针 |
 
---

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: PORT_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Port.h
- **值**: 88
- **描述**: 这个宏给出了PORT驱动厂商ID，如AUTOSAR所述

## 5.2 ModuleId
- **语法**: PORT_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Port.h
- **值**: 124
- **描述**: 这个宏给出了PORT驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: PORT_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Port.h
- **值**: 0
- **描述**: 这个宏给出了PORT驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: PORT_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Port.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: PORT_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Port.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: PORT_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Port.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---

# 第6章 API文档
## 6.1 API类型定义

### 6.1.1 类型定义 Port_ConfigType
- **语法**: Port_ConfigType
- **类型**: Struct
- **文件**: Port.h
- **范围**:
  - NumConfig (uint8)
    - 存储已配置引脚的数量
  - PortPinConfigPtr (Port_PinConfigType*)
    - 存储引脚配置数组指针
- **描述**: 此类型定义用于配置Port Driver的整体配置。此类型的指针在Port_Init API中用于初始化Port驱动程序。

### 6.1.2 类型定义 Port_PinConfigType
- **语法**: Port_PinConfigType
- **类型**: Struct
- **文件**: Port.h
- **范围**:
  - PortBase (Port_PinType)
    - 配置该引脚所在Port的索引
  - PinIndex (Port_PinType)
    - 配置该引脚在该Port中的Pin索引
  - PinsControl (uint32)
    - 配置该引脚的属性，例如上拉、下拉、重映射模式、推挽输出等
  - IsPinsModeChangeable（uint8）
    - 配置该引脚的工作模式在运行时是否可以修改
  - IsDirChangeable（uint8）
    - 配置该引脚的信号方向在运行时是否可以修改
- **描述**: 此类型定义用于定义一个Port帧。此类型在Port帧传输Api中使用。
 
### 6.1.3 类型定义 Port_PinModeType
- **语法**: Port_PinModeType
- **类型**: uint16
- **文件**: Port.h
- **描述**: 定义Pin的各种模式，高4位存储功能模式，低4位存储引脚方向。

### 6.1.4 类型定义 Port_PinDirectionType
- **语法**: Port_PinDirectionType
- **类型**: enum
- **文件**: Port.h
  - PORT_PIN_IN
    - 引脚方向为输入
  - PORT_PIN_OUT
    - 引脚方向为输出
- **描述**: 定义Pin脚的方向类型。

### 6.1.5 类型定义 Port_PinType
- **语法**: Port_PinType
- **类型**: uint8
- **文件**: Port.h
- **描述**: Port端口或Pin脚的索引类型,高4位存储Port索引，低4位存储Pin索引。
 
## 6.2 API接口
> 以下接口为AutoSAR标准接口，请查阅《AUTOSAR_SWS_PORTDriver.pdf》查看功能说明。

### 6.2.1 Port_GetVersionInfo
- **服务名称**: Port_GetVersionInfo
- **语法**: void Port_GetVersionInfo ( Std_VersionInfoType *VersionInfoPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: VersionInfoPtr: 存储驱动版本信息的指针。
- **返回值**: 无
- **描述**: 获取驱动的版本信息的服务。

### 6.2.2 Port_Init
- **服务名称**: Port_Init
- **语法**: void Port_Init (const Port_ConfigType *ConfigPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: ConfigPtr 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化Port驱动程序的服务。

### 6.2.3 Port_SetPinDirection
- **服务名称**: Port_SetPinDirection
- **语法**: void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x08
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Pin，Pin脚的索引。Direction，该Pin脚要设置的信号方向
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此接口可以更改Pin脚的信号方向。

### 6.2.4 Port_RefreshPortDirection
- **服务名称**: Port_RefreshPortDirection
- **语法**: void Port_RefreshPortDirection(void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x06
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此接口将刷新所有已配置的引脚的方向到用户配置的方向。

### 6.2.5 Port_SetPinMode
- **服务名称**: Port_SetPinMode
- **语法**: void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x09
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Pin,要更改工作模式的Pin脚，Mode，引脚要切换到的工作模式
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此接口用于设置指定Pin脚的工作模式。
 
-----

## 6.3 中断处理

无

Pin脚的中断处理不在Port Driver中提供，由Irq Driver直接操作LL库实现。

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

PORT Driver没有提供专有区域。

-----

# 第7章 数据描述

## 7.1 全局数据描述
以下是Port Driver中使用的所有全局和静态变量的列表。

#### 全局数据描述

| 参数           | 类型/范围       | 描述                        |
| -------------- | --------------- | --------------------------- |
| Port_ConfigPtr | Port_ConfigType | Port Driver的配置结构体指针 |

-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是GPT Driver中定义的错误代码及其描述。

#### 错误分类

| 错误代码                      | 错误描述                     | 值（十六进制） |
| ----------------------------- | ---------------------------- | -------------- |
| PORT_E_UNINIT                 | 驱动未初始化错误             | 0x0FU          |
| PORT_E_PARAM_PIN              | 无效的Pin索引                | 0x0AU          |
| PORT_E_DIRECTION_UNCHANGEABLE | 该引脚配置为不能改变信号方向 | 0x0BU          |
| PORT_E_INIT_FAILED            | 驱动初始化错误               | 0x0CU          |
| PORT_E_PARAM_INVALID_MODE     | 参数错误，无效的工作模式     | 0x0DU          |
| PORT_E_MODE_UNCHANGEABLE      | 该引脚配置为不能改变工作模式 | 0x0EU          |
| PORT_E_PARAM_POINTER          | 参数错误，无效的指针         | 0x10U          |
| PORT_E_PARAM_INVALID_RANGE    | 参数错误，超出范围           | 0x20U          |


-----
# 第9章 示例用法
本章描述了如何配置Port驱动器以及如何在应用程序中使用Port驱动器提供的不同的API。

## 9.1 集成说明

> 添加以下文件到工程
```
   FlexRM_Cfg.h
   FlexRM.h
   FlexRM.c
   Port.h      
   Port.c      
   Portfd_Im.h
   Portfd_Im.c
   Port_Cfg.h  
   Port_LCfg.c
```

## 9.2 驱动配置  
   按照以下指南以及实际应用场景正确配置Port驱动器：
- MCU驱动器：配置系统时钟。
- 中断优先级初始化：在中断请求（IRQ）驱动器中配置中断优先级。
- 选择所需的API配置开关，要配置的Pin脚，工作模式等。


```
Port_Cfg.h 文件示例配置
/**
 * @brief Switches the Det detection and notification ON or OFF
 */
#define PORT_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_SetPinDirection()
 */
#define PORT_SET_PIN_DIRECTION_API (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
 */
#define PORT_SET_PIN_MODE_API (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_GetVersionInfo().
 */
#define PORT_VERSION_INFO_API (STD_ON)

/**
 * @brief Port config fixed address usage
 */
#define PORT_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief Total port defined in the mcu : for KF32A1x8MQV port A~H,J,K all defined
 */
#define PORT_TOTAL_NUMBER (10U)

/**
 * @brief Total pin each port defined in the mcu : for KF32A1x8MQV pin0~pin15
 * all defined
 */
#define PORT_PIN_TOTAL_NUMBER (16U)

/**
 * @brief Definitions to specify the pins available in the port, defined by the MCU serial and package type
 * bitX = 0 - pin X available
 * bitX = 1 - pin X not available
 * For KF32A1x8MQV
 */
/* all available */
#define MASK_PORTA (0x0000U)

/* all available */
#define MASK_PORTB (0x0000U)

/* PC15(DPI_CLK) not available on KF32A1x8MQV */
#define MASK_PORTC (0x8000U)

/* PD0(NRST),PD1(DPI_DAT),not available on KF32A1x8MQV  */
#define MASK_PORTD (0x0003U)

/* all available  */
#define MASK_PORTE (0x0000U)

/* all available */
#define MASK_PORTF (0x0000U)

/* all available */
#define MASK_PORTG (0x0000U)

/* PH2(OSC_OUT),PH11(OSC_IN) not available on kf32a1x8MQV */
#define MASK_PORTH (0x0804U)

/* all available */
#define MASK_PORTJ (0x0000U)

/* all available */
#define MASK_PORTK (0x0000U)

/**
 * @brief Pin_ConfigType PageRemap
 */
#define PAGEMP_PAGE1 ((uint32)0x00U)
#define PAGEMP_PAGE2 ((uint32)0x01U)
#define PAGEMP_PAGE3 ((uint32)0x02U)

/**
 * @brief Pin_ConfigType SlewRate Low Speed
 */
#define SLEWR_LS ((uint32)0x00U)
/**
 * @brief Pin_ConfigType SlewRate High Speed
 */
#define SLEWR_HS ((uint32)0x01U)

/**
 * @brief Pin_ConfigType Push-Pull
 */
#define POD_PP ((uint32)0x00U)
/**
 * @brief Pin_ConfigType Open-Drain
 */
#define POD_OD ((uint32)0x01U)

/**
 * @brief Pin_ConfigType PushStatus
 */
#define PULL_NONE ((uint32)0x00U)
#define PULL_UP   ((uint32)0x01U)
#define PULL_DOWN ((uint32)0x02U)

/**
 * @brief Pin_ConfigType Remap
 */
#define GPIO_REMAP_AF0  ((uint32)0x00U)
#define GPIO_REMAP_AF1  ((uint32)0x01U)
#define GPIO_REMAP_AF2  ((uint32)0x02U)
#define GPIO_REMAP_AF3  ((uint32)0x03U)
#define GPIO_REMAP_AF4  ((uint32)0x04U)
#define GPIO_REMAP_AF5  ((uint32)0x05U)
#define GPIO_REMAP_AF6  ((uint32)0x06U)
#define GPIO_REMAP_AF7  ((uint32)0x07U)
#define GPIO_REMAP_AF8  ((uint32)0x08U)
#define GPIO_REMAP_AF9  ((uint32)0x09U)
#define GPIO_REMAP_AF10 ((uint32)0x0AU)
#define GPIO_REMAP_AF11 ((uint32)0x0BU)
#define GPIO_REMAP_AF12 ((uint32)0x0CU)
#define GPIO_REMAP_AF13 ((uint32)0x0DU)
#define GPIO_REMAP_AF14 ((uint32)0x0EU)

/**
 * @brief PIN Index
 */
#define GPIO_PIN_0  ((uint8)0x00U)
#define GPIO_PIN_1  ((uint8)0x01U)
#define GPIO_PIN_2  ((uint8)0x02U)
#define GPIO_PIN_3  ((uint8)0x03U)
#define GPIO_PIN_4  ((uint8)0x04U)
#define GPIO_PIN_5  ((uint8)0x05U)
#define GPIO_PIN_6  ((uint8)0x06U)
#define GPIO_PIN_7  ((uint8)0x07U)
#define GPIO_PIN_8  ((uint8)0x08U)
#define GPIO_PIN_9  ((uint8)0x09U)
#define GPIO_PIN_10 ((uint8)0x0AU)
#define GPIO_PIN_11 ((uint8)0x0BU)
#define GPIO_PIN_12 ((uint8)0x0CU)
#define GPIO_PIN_13 ((uint8)0x0DU)
#define GPIO_PIN_14 ((uint8)0x0EU)
#define GPIO_PIN_15 ((uint8)0x0FU)

/**
 * @brief PORT Index
 */
#define GPIO_PORT_A ((uint8)0x00U)
#define GPIO_PORT_B ((uint8)0x01U)
#define GPIO_PORT_C ((uint8)0x02U)
#define GPIO_PORT_D ((uint8)0x03U)
#define GPIO_PORT_E ((uint8)0x04U)
#define GPIO_PORT_F ((uint8)0x05U)
#define GPIO_PORT_G ((uint8)0x06U)
#define GPIO_PORT_H ((uint8)0x07U)

/** @brief Pin Mode Gpio In  */
#define MODE_GPIO_IN ((uint32)0x00U)
/** @brief Pin Mode Gpio Out  */
#define MODE_GPIO_OUT ((uint32)0x01U)
/** @brief Pin Mode Gpio Remap  */
#define MODE_RMP ((uint32)0x02U)
/** @brief Pin Mode Gpio Analog  */
#define MODE_AN ((uint32)0x03U)

/**
 * @brief Port_ConfigType IsDirChangeable,Pin direction changeable define.
 */
#define DIR_NOT_CHANGEABLE (0x00U)
#define DIR_CHANGEABLE     (0x01U)

/**
 * @brief Port_ConfigType PinsLevel Type definition-port pin level value from Port pin list
 */
#define LEVEL_HIGH (0x01U)
#define LEVEL_LOW  (0x00U)

#if (PORT_SET_PIN_MODE_API == STD_ON)
/**
 * @brief Port_ConfigType IsPinsModeChangeable,pin during runtime
 */
#define MODE_NOT_CHANGEABLE (0x00U)
#define MODE_CHANGEABLE     (0x01U)
#endif

/**
 * @brief Port_ConfigType PinsLockSts
 */
#define GPIO_UNLOCK (0x00U)
#define GPIO_LOCK   (0x01U)

```

```
Port_LCfg.c文件示例配置

/**
 * @brief all port pins config
 * @details
 * LED1:PF14\LED2:PF15\LED3:PG0\LED4:PG2
 * USART0:PB3\PB4
 */
/*PRQA S 499,3397,3432  ++*/
static const Port_PinConfigType Port_PinInitArr0[] = {
  /* PE_11*/
  /* ADC_CH72 */
  {
    .PortBase    = GPIO_PORT_E,
    .PinIndex    = GPIO_PIN_11,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PF_11*/
  /* ADC_CH112 */
  {
    .PortBase    = GPIO_PORT_F,
    .PinIndex    = GPIO_PIN_11,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PE_10*/
  /* ADC_CH71 */
  {
    .PortBase    = GPIO_PORT_E,
    .PinIndex    = GPIO_PIN_10,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PB_8*/
  /* ADC_CH114 */
  {
    .PortBase    = GPIO_PORT_B,
    .PinIndex    = GPIO_PIN_8,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PF_14 */
  /* LED_1 */
  {
    .PortBase    = GPIO_PORT_F,
    .PinIndex    = GPIO_PIN_14,
    .PinsControl = PORT_CFG_MACRO(
      GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_HIGH, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15, FLEXRM_CFG_PORT15,
      FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PF_15 */
  /* LED_2 */
  {
    .PortBase    = GPIO_PORT_F,
    .PinIndex    = GPIO_PIN_15,
    .PinsControl = PORT_CFG_MACRO(
      GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_HIGH, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15, FLEXRM_CFG_PORT15,
      FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PG_0 */
  /* LED_3 */
  {
    .PortBase    = GPIO_PORT_G,
    .PinIndex    = GPIO_PIN_0,
    .PinsControl = PORT_CFG_MACRO(
      GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_HIGH, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15, FLEXRM_CFG_PORT15,
      FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PG_2 */
  /* LED_4 */
  {
    .PortBase    = GPIO_PORT_G,
    .PinIndex    = GPIO_PIN_2,
    .PinsControl = PORT_CFG_MACRO(
      GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_HIGH, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15, FLEXRM_CFG_PORT15,
      FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PD_5 */
  /* ocu:ccp21ch1 */
  {
    .PortBase    = GPIO_PORT_D,
    .PinIndex    = GPIO_PIN_5,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PB_3 */
  /* USART0_TX */
  {
    .PortBase    = GPIO_PORT_B,
    .PinIndex    = GPIO_PIN_3,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF3, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PB_4 */
  /* USART0_RX */
  {
    .PortBase    = GPIO_PORT_B,
    .PinIndex    = GPIO_PIN_4,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF3, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PC_0 */
  /* WKP2 */
  {
    .PortBase    = GPIO_PORT_C,
    .PinIndex    = GPIO_PIN_0,
    .PinsControl = PORT_CFG_MACRO(
      GPIO_REMAP_AF0, MODE_GPIO_IN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15, FLEXRM_CFG_PORT15,
      FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PD_15 */
  {
    .PortBase    = GPIO_PORT_D,
    .PinIndex    = GPIO_PIN_15,
    .PinsControl = PORT_CFG_MACRO(
      GPIO_REMAP_AF0, MODE_GPIO_IN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15, FLEXRM_CFG_PORT15,
      FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PF_10 */
  /* I2C0_SCL */
  {
    .PortBase    = GPIO_PORT_F,
    .PinIndex    = GPIO_PIN_10,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF5, MODE_RMP, STD_LOW, PULL_UP, POD_OD, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PF_12 */
  /* I2C0_SDA */
  {
    .PortBase    = GPIO_PORT_F,
    .PinIndex    = GPIO_PIN_12,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF5, MODE_RMP, STD_LOW, PULL_UP, POD_OD, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PF_3 */
  /* CAN8_RX */
  {
    .PortBase    = GPIO_PORT_F,
    .PinIndex    = GPIO_PIN_3,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PF_2 */
  /* CAN8_TX */
  {
    .PortBase    = GPIO_PORT_F,
    .PinIndex    = GPIO_PIN_2,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },

  /* PA_3 */
  /* CAN6_TX */
  {
    .PortBase    = GPIO_PORT_A,
    .PinIndex    = GPIO_PIN_3,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },

  /* PE_7 */
  /* CAN6_RX */
  {
    .PortBase    = GPIO_PORT_E,
    .PinIndex    = GPIO_PIN_7,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },

  /* PC_2 */
  /* CAN7_TX */
  {
    .PortBase    = GPIO_PORT_C,
    .PinIndex    = GPIO_PIN_2,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },
  /* PG_9 */
  /* CAN7_RX */
  {
    .PortBase    = GPIO_PORT_G,
    .PinIndex    = GPIO_PIN_9,
    .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS, FLEXRM_CFG_GROUP15,
                                  FLEXRM_CFG_PORT15, FLEXRM_CFG_CHANNEL15, FLEXRM_CFG_OUT, FLEXRM_CFG_DISABLE),
#if (PORT_SET_PIN_MODE_API == STD_ON)
    .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
#endif
    .IsDirChangeable = DIR_NOT_CHANGEABLE,
  },

};

/**
 * @brief This table contains the Configured Port Pin parameters
 */
const Port_ConfigType Port_ConfigPredefined = 
{
  (sizeof(Port_PinInitArr0) / sizeof(Port_PinConfigType)), &Port_PinInitArr0[0U]
};
```
## 9.3 驱动初始化

```
    /* 包含Port驱动接口头文件 */
    #include "Port.h"
    
    /* 初始化Port驱动 */
    Port_Init(&Port_Config);
```
## 9.4 API使用

```
    /* 包含Port驱动接口头文件 */
    #include "Port.h"
    
    Std_VersionInfoType driverVersionInfo;
    
    /* 获取Port驱动软件版本信息 */
    Port_GetVersionInfo(&driverVersionInfo);
    
    /* 设置PH15引脚方向为输出 */
    Port_SetPinDirection((GPIO_PORT_D<<4)|GPIO_PIN_15,PORT_PIN_OUT)
    /* 设置PH15引脚工作模式为CLK_OUT模式 */
    Port_SetPinMode((GPIO_PORT_D<<4)|GPIO_PIN_15,(GPIO_PIN_RMP_PAGE1_AF0<<4)|GPIO_PIN_MODE_REMAP);
    /* 重置所有引脚到配置的模式 */
    Port_RefreshPortDirection();
       
```

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 假设

- 中断的全局配置（中断仲裁周期、优先级设置）将由用户处理
- Mcu驱动在Port驱动之前进行初始化
- 单片机时钟设置的多重性配置为1-*
- KF32A1x8支持的最大频率为120MHz


## 10.2 限制

- Port_SetMode接口设置重映射功能时，只能设置PAGE1中的功能



