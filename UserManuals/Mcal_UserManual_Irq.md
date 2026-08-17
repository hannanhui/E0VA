# ChipOn Microcontroller Abstract Layer Users Manual - Irq Driver
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

- [ChipOn Microcontroller Abstract Layer Users Manual - Irq Driver](#chipon-microcontroller-abstract-layer-users-manual---irq-driver)
  - [变更记录](#变更记录)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考](#13-参考)
- [第2章 IRQ Driver概述](#第2章-irq-driver概述)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [无](#无)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Irq\_ConfigType](#611-类型定义-irq_configtype)
    - [6.1.2 类型定义 PriorityType](#612-类型定义-prioritytype)
  - [6.2 API函数](#62-api函数)
    - [6.2.1 Irq\_Init](#621-irq_init)
    - [6.2.2 Irq\_Deinit](#622-irq_deinit)
    - [6.2.32 Irq\_Enable](#6232-irq_enable)
    - [6.2.4 Irq\_Disable](#624-irq_disable)
  - [6.3 中断处理](#63-中断处理)
  - [6.4 专有区域（EA）信息](#64-专有区域ea信息)
    - [6.4.1 专有区域信息](#641-专有区域信息)
- [第7章 数据描述](#第7章-数据描述)
      - [表80 全局数据描述](#表80-全局数据描述)
- [第8章 错误分类](#第8章-错误分类)
- [第9章 示例用法](#第9章-示例用法)
  - [9.1 系统时钟配置注意事项](#91-系统时钟配置注意事项)
  - [9.2 宏配置](#92-宏配置)
  - [9.3 接口使用示例](#93-接口使用示例)
      - [9.3.1 初始化](#931-初始化)
      - [9.3.2 反初始化](#932-反初始化)
      - [9.3.3 使能全局中断](#933-使能全局中断)
      - [9.3.4 关闭全局中断](#934-关闭全局中断)
  - [9.4 配置示例](#94-配置示例)
- [第10章 限制和假设](#第10章-限制和假设)
  - [10.1 假设和与软件规格的偏差](#101-假设和与软件规格的偏差)
    - [表82 假设](#表82-假设)
    - [偏差](#偏差)
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)


---

# 第1章 引言

本用户手册提供了AUTOSAR CP R22-11的IRQ驱动程序的功能和API实现的相关信息。IRQ的驱动程序初始化并提供对微控制器的访问。本用户手册旨在帮助用户熟悉IRQ驱动程序的实现KF32A1X8SF硬件平台。它是描述如何使用IRQ驱动程序的文档。

## 1.1 范围

本文档介绍IRQ驱动程序实现的以下特性：
- KF32A1X8实现硬件外设的驱动程序
- IRQ Driver的文件结构
- Driver的配置参数
- 由IRQ Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于IRQ Driver

## 1.2 缩写

| 缩写    | 解释                 |
| :------ | :------------------- |
| AUTOSAR | 汽车汽车开放系统架构 |
| API     | 应用程序接口         |
| IRQ     | 中断请求             |
| DEM     | 诊断事件管理器       |
| DET     | 开发错误跟踪器       |
| GPIO    | 通用输入输出         |
| BSW     | 基础软件             |
| HW      | 硬件                 |
| ID      | 标识符               |
| MCAL    | 微控制器抽象层       |
| MCU     | 微控制器             |

## 1.3 参考

本节列出了与本用户手册相关的所有文档：
- [1] KF32A158xxxSF用户手册V1.0
- [2] KF32A158xxxSF数据手册V1.3

-----
# 第2章 IRQ Driver概述
KF32微控制器提供IRQ操作方式。有关IRQ配置的详细信息，参考PORT用户手册

-----

# 第3章 文件结构
本节提供了有关IRQ Driver文件和其他相关文件的详细信息。
| Name        | Description                                     |
| :---------- | :---------------------------------------------- |
| Irq.c       | 此文件包含IRQ驱动程序的通用功能                 |
| Irq.h       | 此头文件输出IRQ驱动程序的宏、类型定义和函数原型 |
| Irq_Cfg.h   | 本文在这里声明了IRQ驱动程序的配置数据。         |
| Irq_LCfg.c  | 初始化参数配置                                  |
| Irq_LCfg.h  | 初始化参数声明                                  |
| Irq_Types.h | 初始化结构体定义                                |

-----

# 第4章 配置文档

无
-----

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: IRQ_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Irq_Cfg.h
- **值**: 88
- **描述**: 

## 5.2 ModuleId
- **语法**: IRQ_MODULE_ID
- **类型**: 宏定义 (#define)
- **文件**: Irq_Cfg.h
- **值**: 188
- **描述**: 这个宏给出了IRQ驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: IRQ_INSTANCE_ID
- **类型**: 宏定义 (#define)
- **文件**: Irq_Cfg.h
- **值**: 0
- **描述**: 这个宏给出了IRQ驱动实例ID，如AUTOSAR所述

---
# 第6章 API文档

## 6.1 API类型定义

### 6.1.1 类型定义 Irq_ConfigType
- **语法**: Irq_ConfigType
- **类型**: Struct
- **文件**: Irq_Types.h
- **范围**: 
  - **uint32**
    - PriorityGroup - 优先级分组类型    
  - **PriorityType**
    - xxx_Priority - 所有外设的优先级配置            
- **描述**: 此类型定义用于Irq_Init使用。

### 6.1.2 类型定义 PriorityType
- **语法**: PriorityType
- **类型**: Struct
- **文件**: Irq_Types.h
- **范围**: 
  - **uint8**
    - Preemption_Priority - 抢占优先级    
  - **uint8**
    - Sub_Priority - 子优先级            
- **描述**: 每个外设优先级具体设置

---
## 6.2 API函数

### 6.2.1 Irq_Init
- **服务名称**: `Irq_Init`
- **语法**: `void Irq_Init(const Irq_ConfigType* Config)`
- **来源**: 
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: Config - IRQ配置参数
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 初始化外设中断，优先级和中断使能状态
- **注意事项**: 无

### 6.2.2 Irq_Deinit
- **服务名称**: `Irq_Deinit`
- **语法**: `void Irq_Deinit(void)`
- **来源**: 
- **服务ID**: 无
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 将配置的中断关闭
- **注意事项**: 无

### 6.2.32 Irq_Enable
- **服务名称**: `Irq_Enable`
- **语法**: `#define Irq_Enable()  __asm volatile("ENI")`
- **来源**: 
- **服务ID**: 无
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 使能全局中断
- **注意事项**: 无

### 6.2.4 Irq_Disable
- **服务名称**: `Irq_Disable`
- **语法**: `#define Irq_Disable() __asm volatile("DSI")`
- **来源**: 
- **服务ID**: 无
- **同步/异步**: 同步
- **可重入**: 不可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 关闭全局中断
- **注意事项**: 无
-----

## 6.3 中断处理

无

-----
## 6.4 专有区域（EA）信息

### 6.4.1 专有区域信息

IRQ Driver没有提供专有区域。

-----
# 第7章 数据描述

无

-----
#### 表80 全局数据描述

无

-------
# 第8章 错误分类

无

-----
# 第9章 示例用法
本章描述了如何配置IRQ驱动器以及如何在应用程序中API使用。

## 9.1 系统时钟配置注意事项

无

## 9.2 宏配置

XXX_UNIFIED_INTERRUPT是配置各个外设中断是否启用，根据需求配置STD_ON、STD_OFF
```c
#define IRQ_DEV_ERROR_DETECT_API (STD_ON)
#define IRQ_CAT1  (0U)
#define IRQ_CAT23 (1U)

#define IRQ_CAT_T0         IRQ_CAT1
#define IRQ_CAT_T1         IRQ_CAT1
#define IRQ_CAT_T2         IRQ_CAT1
#define IRQ_CAT_T3         IRQ_CAT1
#define IRQ_CAT_T4         IRQ_CAT1
#define IRQ_CAT_T5         IRQ_CAT1
#define IRQ_CAT_T6         IRQ_CAT1
#define IRQ_CAT_T9         IRQ_CAT1
#define IRQ_CAT_T10        IRQ_CAT1
#define IRQ_CAT_T11        IRQ_CAT1
#define IRQ_CAT_T12        IRQ_CAT1
#define IRQ_CAT_T13        IRQ_CAT1
#define IRQ_CAT_T14        IRQ_CAT1
#define IRQ_CAT_T16        IRQ_CAT1
#define IRQ_CAT_T20        IRQ_CAT1
#define IRQ_CAT_T21        IRQ_CAT1
#define IRQ_CAT_T31        IRQ_CAT1
#define IRQ_CAT_T32        IRQ_CAT1
#define IRQ_CAT_T33        IRQ_CAT1
#define IRQ_CAT_T36        IRQ_CAT1
#define IRQ_CAT_DMA0       IRQ_CAT1
#define IRQ_CAT_DMA1       IRQ_CAT1
#define IRQ_CAT_I2C0       IRQ_CAT1
#define IRQ_CAT_I2C1       IRQ_CAT1
#define IRQ_CAT_I2C2       IRQ_CAT1
#define IRQ_CAT_USART0     IRQ_CAT1
#define IRQ_CAT_USART1     IRQ_CAT1
#define IRQ_CAT_USART2     IRQ_CAT1
#define IRQ_CAT_USART3     IRQ_CAT1
#define IRQ_CAT_USART6     IRQ_CAT1
#define IRQ_CAT_SPI0       IRQ_CAT1
#define IRQ_CAT_SPI1       IRQ_CAT1
#define IRQ_CAT_SPI2       IRQ_CAT1
#define IRQ_CAT_ADC0       IRQ_CAT1
#define IRQ_CAT_ADC1       IRQ_CAT1
#define IRQ_CAT_EINTA      IRQ_CAT1
#define IRQ_CAT_EINTB      IRQ_CAT1
#define IRQ_CAT_EINTC      IRQ_CAT1
#define IRQ_CAT_EINTD      IRQ_CAT1
#define IRQ_CAT_EINTE      IRQ_CAT1
#define IRQ_CAT_EINTF      IRQ_CAT1
#define IRQ_CAT_EINTX      IRQ_CAT1
#define IRQ_CAT_SRAMECC    IRQ_CAT1
#define IRQ_CAT_FLASHECC   IRQ_CAT1
#define IRQ_CAT_EINT19TO17 IRQ_CAT1
#define IRQ_CAT_CANFD6     IRQ_CAT1
#define IRQ_CAT_CANFD7     IRQ_CAT1
#define IRQ_CAT_CANFD8     IRQ_CAT1
#define IRQ_CAT_CANFD9     IRQ_CAT1

#define SYSTICK_UNIFIED_INTERRUPT         (STD_OFF)
#define WWDT_UNIFIED_INTERRUPT            (STD_OFF)
#define EINT16_UNIFIED_INTERRUPT          (STD_OFF)
#define PA_UNIFIED_INTERRUPT              (STD_OFF)
#define PB_UNIFIED_INTERRUPT              (STD_OFF)
#define PC_UNIFIED_INTERRUPT              (STD_OFF)
#define PD_UNIFIED_INTERRUPT              (STD_ON)
#define PE_UNIFIED_INTERRUPT              (STD_OFF)
#define PF_UNIFIED_INTERRUPT              (STD_OFF)
#define PX_UNIFIED_INTERRUPT              (STD_OFF)
#define T1_UNIFIED_INTERRUPT              (STD_ON)
#define T3_UNIFIED_INTERRUPT              (STD_OFF)
#define T5_UNIFIED_INTERRUPT              (STD_OFF)
#define T6_UNIFIED_INTERRUPT              (STD_OFF)
#define CANFD6MB15TO0_UNIFIED_INTERRUPT   (STD_ON)
#define CANFD6MB31TO16_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD6MB47TO32_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD6MB63TO48_UNIFIED_INTERRUPT  (STD_ON)
#define T14_UNIFIED_INTERRUPT             (STD_ON)
#define RNG_UNIFIED_INTERRUPT             (STD_OFF)
#define CANFD7MB15TO0_UNIFIED_INTERRUPT   (STD_ON)
#define CANFD7MB31TO16_UNIFIED_INTERRUPT  (STD_ON)
#define ADC0_UNIFIED_INTERRUPT            (STD_OFF)
#define ADC1_UNIFIED_INTERRUPT            (STD_OFF)
#define CANFD6_BUSERR_UNIFIED_INTERRUPT   (STD_ON)
#define T11_UNIFIED_INTERRUPT             (STD_OFF)
#define T0_UNIFIED_INTERRUPT              (STD_OFF)
#define DMA0_UNIFIED_INTERRUPT            (STD_ON)
#define CMP_UNIFIED_INTERRUPT             (STD_OFF)
#define USART0_UNIFIED_INTERRUPT          (STD_OFF)
#define USART1_UNIFIED_INTERRUPT          (STD_ON)
#define SPI0_UNIFIED_INTERRUPT            (STD_OFF)
#define SPI1_UNIFIED_INTERRUPT            (STD_OFF)
#define DMA1_UNIFIED_INTERRUPT            (STD_ON)
#define EINT19_17_UNIFIED_INTERRUPT       (STD_ON)
#define CANFD6_CANFDGEN_UNIFIED_INTERRUPT (STD_ON)
#define CANFD7_CANFDGEN_UNIFIED_INTERRUPT (STD_ON)
#define CANFD7MB47TO32_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD7MB63TO48_UNIFIED_INTERRUPT  (STD_ON)
#define EINT31_20_UNIFIED_INTERRUPT       (STD_OFF)
#define CMU_UNIFIED_INTERRUPT             (STD_OFF)
#define OSC_UNIFIED_INTERRUPT             (STD_OFF)
#define CLK_UNIFIED_INTERRUPT             (STD_OFF)
#define IIC0_UNIFIED_INTERRUPT            (STD_ON)
#define IIC1_UNIFIED_INTERRUPT            (STD_OFF)
#define IIC2_UNIFIED_INTERRUPT            (STD_OFF)
#define T12_UNIFIED_INTERRUPT             (STD_OFF)
#define T2_UNIFIED_INTERRUPT              (STD_ON)
#define T4_UNIFIED_INTERRUPT              (STD_ON)
#define T13_UNIFIED_INTERRUPT             (STD_OFF)
#define USART2_UNIFIED_INTERRUPT          (STD_ON)
#define T16_UNIFIED_INTERRUPT             (STD_ON)
#define USART6_UNIFIED_INTERRUPT          (STD_ON)
#define SPI2_UNIFIED_INTERRUPT            (STD_OFF)
#define CANFD7_BUSERR_UNIFIED_INTERRUPT   (STD_ON)
#define WKP_UNIFIED_INTERRUPT             (STD_OFF)
#define CANFD8_BUSERR_UNIFIED_INTERRUPT   (STD_ON)
#define T20_UNIFIED_INTERRUPT             (STD_ON)
#define USART3_UNIFIED_INTERRUPT          (STD_ON)
#define SHA_UNIFIED_INTERRUPT             (STD_OFF)
#define RSA_UNIFIED_INTERRUPT             (STD_OFF)
#define FIRSTK_PROG_UNIFIED_INTERRUPT     (STD_OFF)
#define FIRSTK_SERA_UNIFIED_INTERRUPT     (STD_OFF)
#define CANFD8MB15TO0_UNIFIED_INTERRUPT   (STD_ON)
#define CANFD8MB31TO16_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD8MB47TO32_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD8MB63TO48_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD8_CANFDGEN_UNIFIED_INTERRUPT (STD_ON)
#define CANFD9_CANFDGEN_UNIFIED_INTERRUPT (STD_ON)
#define T31_UNIFIED_INTERRUPT             (STD_OFF)
#define T32_UNIFIED_INTERRUPT             (STD_OFF)
#define T33_UNIFIED_INTERRUPT             (STD_OFF)
#define T36_UNIFIED_INTERRUPT             (STD_OFF)
#define T9_UNIFIED_INTERRUPT              (STD_OFF)
#define T10_UNIFIED_INTERRUPT             (STD_OFF)
#define CANFD9_BUSERR_UNIFIED_INTERRUPT   (STD_ON)
#define STOPWATCHTICK_UNIFIED_INTERRUPT   (STD_OFF)
#define T21_UNIFIED_INTERRUPT             (STD_OFF)
#define A_BUSY_UNIFIED_INTERRUPT          (STD_OFF)
#define B_BUSY_UNIFIED_INTERRUPT          (STD_OFF)
#define SRAMECC_UNIFIED_INTERRUPT         (STD_OFF)
#define DRAMECC_UNIFIED_INTERRUPT         (STD_OFF)
#define CACHEECC_UNIFIED_INTERRUPT        (STD_OFF)
#define FLASHECC_UNIFIED_INTERRUPT        (STD_OFF)
#define ISMU_UNIFIED_INTERRUPT            (STD_OFF)
#define CANFD9MB15TO0_UNIFIED_INTERRUPT   (STD_ON)
#define CANFD9MB31TO16_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD9MB47TO32_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD9MB63TO48_UNIFIED_INTERRUPT  (STD_ON)
#define AES_UNIFIED_INTERRUPT             (STD_OFF)
```
## 9.3 接口使用示例

#### 9.3.1 初始化

```c
	Irq_Init(&Irq_ConfigPredefined);
```

#### 9.3.2 反初始化

```c
	Irq_Deinit();
```

#### 9.3.3 使能全局中断

```c
	Irq_Enable();
```

#### 9.3.4 关闭全局中断

```c
	Irq_Disable();
```
---

## 9.4 配置示例

中断优先级根据功能需求配置

```c
CONST(Irq_ConfigType, IRQ_CONST)
Irq_ConfigPredefined = {
  .PriorityGroup = IRQ_INTR_PREEMP_3,
#if (SYSTICK_UNIFIED_INTERRUPT == STD_ON)
  .Systick_Priority = {0, 0},
#endif
#if (EINT16_UNIFIED_INTERRUPT == STD_ON)
  .Eint16_Priority = {0, 0},
#endif
#if (WWDT_UNIFIED_INTERRUPT == STD_ON)
  .WWDT_Priority = {0, 0},
#endif
#if (PA_UNIFIED_INTERRUPT == STD_ON)
  .PA_Priority = {0, 0},
#endif
#if (PB_UNIFIED_INTERRUPT == STD_ON)
  .PB_Priority = {0, 0},
#endif
#if (PC_UNIFIED_INTERRUPT == STD_ON)
  .PC_Priority = {0, 0},
#endif
#if (PD_UNIFIED_INTERRUPT == STD_ON)
  .PD_Priority = {0, 0},
#endif
#if (PE_UNIFIED_INTERRUPT == STD_ON)
  .PE_Priority = {0, 0},
#endif
#if (PF_UNIFIED_INTERRUPT == STD_ON)
  .PF_Priority = {0, 0},
#endif
#if (PX_UNIFIED_INTERRUPT == STD_ON)
  .PX_Priority = {0, 0},
#endif
#if (T1_UNIFIED_INTERRUPT == STD_ON)
  .Timer1_Priority = {0, 0},
#endif
#if (T3_UNIFIED_INTERRUPT == STD_ON)
  .Timer3_Priority = {0, 0},
#endif
#if (T5_UNIFIED_INTERRUPT == STD_ON)
  .Timer5_Priority = {0, 0},
#endif
#if (T6_UNIFIED_INTERRUPT == STD_ON)
  .Timer6_Priority = {0, 0},
#endif
#if (T14_UNIFIED_INTERRUPT == STD_ON)
  .Timer14_Priority = {0, 0},
#endif
#if (ADC0_UNIFIED_INTERRUPT == STD_ON)
  .Adc0_Priority = {0, 0},
#endif
#if (ADC1_UNIFIED_INTERRUPT == STD_ON)
  .Adc1_Priority = {0, 0},
#endif
#if (T11_UNIFIED_INTERRUPT == STD_ON)
  .Timer11_Priority = {0, 0},
#endif
#if (T0_UNIFIED_INTERRUPT == STD_ON)
  .Timer0_Priority = {0, 0},
#endif
#if (DMA0_UNIFIED_INTERRUPT == STD_ON)
  .Dma0_Priority = {0, 0},
#endif
#if (USART0_UNIFIED_INTERRUPT == STD_ON)
  .Usart0_Priority = {0, 0},
#endif
#if (USART1_UNIFIED_INTERRUPT == STD_ON)
  .Usart1_Priority = {0, 0},
#endif
#if (SPI0_UNIFIED_INTERRUPT == STD_ON)
  .Spi0_Priority = {0, 0},
#endif
#if (SPI1_UNIFIED_INTERRUPT == STD_ON)
  .Spi1_Priority = {0, 0},
#endif
#if (DMA1_UNIFIED_INTERRUPT == STD_ON)
  .Dma1_Priority = {0, 0},
#endif
#if (EINT19_17_UNIFIED_INTERRUPT == STD_ON)
  .Eint19_17_Priority = {0, 0},
#endif
#if (CANFD6_UNIFIED_INTERRUPT == STD_ON)
  .Canfd6_Priority = {0, 0},
#endif
#if (CANFD7_UNIFIED_INTERRUPT == STD_ON)
  .Canfd7_Priority = {3, 0},
#endif
#if (EINT31_20_UNIFIED_INTERRUPT == STD_ON)
  .Eint31_20_Priority = {0, 0},
#endif
#if (CMU_UNIFIED_INTERRUPT == STD_ON)
  .Cmu_Priority = {0, 0},
#endif
#if (OSC_UNIFIED_INTERRUPT == STD_ON)
  .Osc_Priority = {0, 0},
#endif
#if (CLK_UNIFIED_INTERRUPT == STD_ON)
  .Clk_Priority = {0, 0},
#endif
#if (IIC0_UNIFIED_INTERRUPT == STD_ON)
  .IIC0_Priority = {0, 0},
#endif
#if (IIC1_UNIFIED_INTERRUPT == STD_ON)
  .IIC1_Priority = {0, 0},
#endif
#if (IIC2_UNIFIED_INTERRUPT == STD_ON)
  .IIC2_Priority = {0, 0},
#endif
#if (T12_UNIFIED_INTERRUPT == STD_ON)
  .Timer12_Priority = {0, 0},
#endif
#if (T2_UNIFIED_INTERRUPT == STD_ON)
  .Timer2_Priority = {0, 0},
#endif
#if (T4_UNIFIED_INTERRUPT == STD_ON)
  .Timer4_Priority = {0, 0},
#endif
#if (T13_UNIFIED_INTERRUPT == STD_ON)
  .Timer13_Priority = {0, 0},
#endif
#if (USART2_UNIFIED_INTERRUPT == STD_ON)
  .Usart2_Priority = {0, 0},
#endif
#if (T16_UNIFIED_INTERRUPT == STD_ON)
  .Timer16_Priority = {0, 0},
#endif
#if (SPI2_UNIFIED_INTERRUPT == STD_ON)
  .Spi2_Priority = {0, 0},
#endif
#if (ADC2_UNIFIED_INTERRUPT == STD_ON)
  .Adc2_Priority = {0, 0},
#endif
#if (T18_UNIFIED_INTERRUPT == STD_ON)
  .Timer18_Priority = {0, 0},
#endif
#if (T19_UNIFIED_INTERRUPT == STD_ON)
  .Timer19_Priority = {0, 0},
#endif
#if (WKP_UNIFIED_INTERRUPT == STD_ON)
  .Wkp_Priority = {0, 0},
#endif
#if (T21_UNIFIED_INTERRUPT == STD_ON)
  .Timer21_Priority = {0, 0},
#endif
#if (USART3_UNIFIED_INTERRUPT == STD_ON)
  .Usart3_Priority = {0, 0},
#endif
#if (USART6_UNIFIED_INTERRUPT == STD_ON)
  .Usart6_Priority = {0, 0},
#endif
#if (USART7_UNIFIED_INTERRUPT == STD_ON)
  .Usart7_Priority = {0, 0},
#endif
#if (CANFD8_UNIFIED_INTERRUPT == STD_ON)
  .Canfd8_Priority = {0, 0},
#endif
#if (CANFD9_UNIFIED_INTERRUPT == STD_ON)
  .Canfd9_Priority = {0, 0},
#endif
#if (T31_UNIFIED_INTERRUPT == STD_ON)
  .Timer31_Priority = {0, 0},
#endif
#if (T32_UNIFIED_INTERRUPT == STD_ON)
  .Timer32_Priority = {0, 0},
#endif
#if (T33_UNIFIED_INTERRUPT == STD_ON)
  .Timer33_Priority = {0, 0},
#endif
#if (T36_UNIFIED_INTERRUPT == STD_ON)
  .Timer36_Priority = {0, 0},
#endif
#if (T9_UNIFIED_INTERRUPT == STD_ON)
  .Timer9_Priority = {0, 0},
#endif
#if (T10_UNIFIED_INTERRUPT == STD_ON)
  .Timer10_Priority = {0, 0},
#endif
#if (T25_UNIFIED_INTERRUPT == STD_ON)
  .Timer25_Priority = {0, 0},
#endif
#if (T26_UNIFIED_INTERRUPT == STD_ON)
  .Timer26_Priority = {0, 0},
#endif
#if (T22_UNIFIED_INTERRUPT == STD_ON)
  .Timer22_Priority = {0, 0},
#endif
#if (T23_UNIFIED_INTERRUPT == STD_ON)
  .Timer23_Priority = {0, 0},
#endif
#if (SRAMECC_UNIFIED_INTERRUPT == STD_ON)
  .SramEcc_Priority = {0, 0},
#endif
#if (DRAMECC_UNIFIED_INTERRUPT == STD_ON)
  .DramEcc_Priority = {0, 0},
#endif
#if (CACHEECC_UNIFIED_INTERRUPT == STD_ON)
  .CacheEcc_Priority = {0, 0},
#endif
#if (FLASHECC_UNIFIED_INTERRUPT == STD_ON)
  .FlashEcc_Priority = {0, 0},
#endif
#if (ISMU_UNIFIED_INTERRUPT == STD_ON)
  .Mpu_Priority = {0, 0},
#endif
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





