# ChipOn Microcontroller Abstract Layer Users Manual - CAN Driver
Release V0.1 - May 2024  
Published by ChipOn 


---

## 变更记录
| 日期       | 版本 | 变更记录 |
| ---------- | ---- | :------- |
| 2024.05.14 | 0.1  | 初版创建 |
---


## 目录

- [ChipOn Microcontroller Abstract Layer Users Manual - CAN Driver](#chipon-microcontroller-abstract-layer-users-manual---can-driver)
  - [变更记录](#变更记录)
  - [| 2024.05.14 | 0.1  | 初版创建 |](#-20240514--01---初版创建-)
  - [目录](#目录)
- [第1章 引言](#第1章-引言)
  - [1.1 范围](#11-范围)
  - [1.2 缩写](#12-缩写)
  - [1.3 参考资料](#13-参考资料)
- [第2章 Can Driver概述](#第2章-can-driver概述)
  - [2.1 CAN](#21-can)
  - [2.2 IRQ](#22-irq)
  - [2.3 系统时钟](#23-系统时钟)
- [第3章 文件结构](#第3章-文件结构)
- [第4章 配置文档](#第4章-配置文档)
  - [4.1 配置概念](#41-配置概念)
    - [4.1.1 配置类](#411-配置类)
  - [4.2 配置参数变化](#42-配置参数变化)
  - [4.3 Can\_Cfg.h文件配置说明](#43-can_cfgh文件配置说明)
  - [4.4 can\_LCfgc.c文件配置说明](#44-can_lcfgcc文件配置说明)
- [第5章 发布的参数](#第5章-发布的参数)
  - [5.1 VendorId](#51-vendorid)
  - [5.2 ModuleId](#52-moduleid)
  - [5.3 InstanceId](#53-instanceid)
  - [5.4 SwMajorVersion](#54-swmajorversion)
  - [5.5 SwMinorVersion](#55-swminorversion)
  - [5.6 SwPatchVersion](#56-swpatchversion)
- [第6章 API文档](#第6章-api文档)
  - [6.1 API类型定义](#61-api类型定义)
    - [6.1.1 类型定义 Can\_ConfigType](#611-类型定义-can_configtype)
    - [6.1.2 类型定义 Can\_PduType](#612-类型定义-can_pdutype)
    - [6.1.3 类型定义 Can\_IdType](#613-类型定义-can_idtype)
    - [6.1.4 类型定义 Can\_HwHandleType](#614-类型定义-can_hwhandletype)
    - [6.1.5 类型定义 Can\_HwType](#615-类型定义-can_hwtype)
    - [6.1.6 类型定义 Std\_ReturnType](#616-类型定义-std_returntype)
    - [6.1.7 类型定义 Can\_ErrorStateType](#617-类型定义-can_errorstatetype)
    - [6.1.8 类型定义 Can\_ControllerStateType](#618-类型定义-can_controllerstatetype)
    - [6.1.9 类型定义 Can\_TimeStampType](#619-类型定义-can_timestamptype)
  - [6.2 API接口](#62-api接口)
    - [6.2.1 Can\_GetVersionInfo](#621-can_getversioninfo)
    - [6.2.2 Can\_Init](#622-can_init)
    - [6.2.3 Can\_DeInit](#623-can_deinit)
    - [6.2.4 Can\_SetBaudrate](#624-can_setbaudrate)
    - [6.2.5 Can\_SetControllerMode](#625-can_setcontrollermode)
    - [6.2.6 Can\_DisableControllerInterrupts](#626-can_disablecontrollerinterrupts)
    - [6.2.7 Can\_EnableControllerInterrupts](#627-can_enablecontrollerinterrupts)
    - [6.2.8 Can\_CheckWakeup](#628-can_checkwakeup)
    - [6.2.9 Can\_GetControllerErrorState](#629-can_getcontrollererrorstate)
    - [6.2.10 Can\_GetControllerMode](#6210-can_getcontrollermode)
    - [6.2.11 Can\_GetControllerRxErrorCounter](#6211-can_getcontrollerrxerrorcounter)
    - [6.2.12 Can\_GetControllerTxErrorCounter](#6212-can_getcontrollertxerrorcounter)
    - [6.2.13 Can\_GetCurrentTime](#6213-can_getcurrenttime)
    - [6.2.14 Can\_EnableEgressTimeStamp](#6214-can_enableegresstimestamp)
    - [6.2.15 Can\_GetEgressTimeStamp](#6215-can_getegresstimestamp)
    - [6.2.16 Can\_GetIngressTimeStamp](#6216-can_getingresstimestamp)
    - [6.2.17 Can\_Write](#6217-can_write)
    - [6.2.18 Can\_MainFunction\_Write](#6218-can_mainfunction_write)
    - [6.2.19 Can\_MainFunction\_Read](#6219-can_mainfunction_read)
    - [6.2.20 Can\_MainFunction\_BusOff](#6220-can_mainfunction_busoff)
    - [6.2.21 Can\_MainFunction\_Wakeup](#6221-can_mainfunction_wakeup)
    - [6.2.22 Can\_MainFunction\_Mode](#6222-can_mainfunction_mode)
    - [6.2.23 FullCan\_SetControllerToWakeupMode](#6223-fullcan_setcontrollertowakeupmode)
    - [6.2.24 Can\_AbortHTH](#6224-can_aborthth)
  - [6.3 中断处理](#63-中断处理)
    - [6.3.1 Can\_Isr\_Mb](#631-can_isr_mb)
    - [6.3.2 Can\_Isr\_Err](#632-can_isr_err)
    - [6.3.3 Can\_Isr\_Off](#633-can_isr_off)
      - [服务请求节点 - Can硬件资源](#服务请求节点---can硬件资源)
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
    - [考虑的Bugzilla](#考虑的bugzilla)
  - [10.2 限制](#102-限制)


---

# 第1章 引言

本用户手册提供了有关Can驱动程序的功能、配置参数和API实现的信息。本用户手册旨在帮助用户熟悉KungFu硬件平台的Can驱动程序实现。该文档描述了如何使用Can驱动程序
 

## 1.1 范围
本文档涉及Can Driver实现的以下特性：
- KungFu微控制器硬件外设，用于实现Driver
- Can Driver的文件结构
- Driver的配置参数
- 由Can Driver发布的参数
- API规范
- 说明常见用例的代码段
- 限制和假设

本文档适用于Can Driver

## 1.2 缩写

- MCAL : Microcontroller Abstract Layer，微控制器抽象层  
- ISR  : Interrupt Service Routine，中断服务程序        
- CAN  : Control Area Network，控制器局域网        
- CANFD: Control Area Network with Flexible Data rate，数据速率可变控制器局域网 

## 1.3 参考资料
- KF32A158xxxSF用户手册V1.0
- KF32A158xxxSF数据手册V1.3
- CAN_Design_Report.md
- AUTOSAR_SWS_CANDriver.pdf
---


# 第2章 Can Driver概述

Can Driver使用KungFu平台的增强型控制器局域网总线外设(CANFD)。Driver可以配置多个Can通道。它同时支持 CANFD（CAN with Flexible Data rate）
协议和CAN 2.0B协议，两种协议下均可收发标准帧和扩展帧。在收发CAN FD帧时，帧数据长度最大可以达到 64 字节，发送速率可以达到 4Mb/s。每个通道都可以进行以下操作：

- 发送/接收报文
- 发送、接收、总线关闭中断通知
- 切换通道运行模式
- 切换通讯波特率

## 2.1 CAN
使用芯片的CANFD6、CANFD7、CANFD8、CANFD9资源来实现Can Driver

## 2.2 IRQ 
IRQ Driver负责初始化Can Driver所需的中断优先级。

## 2.3 系统时钟
系统时钟通过MCU Driver设置。必须设置适当的系统时钟。

---

# 第3章 文件结构
本节提供了有关Can Driver文件和其他相关文件的详细信息。

| 文件名      | 说明                          | 是否需要配置   |
| ----------- | ----------------------------- | -------------- |
| Can_Types.h | Can模块类型定义文件           | 无需配置       |
| Can_Irq.h   | Can模块的中断处理文件         | 无需配置       |
| Can.h       | Can模块外部接口文件           | 无需配置       |
| Can.c       | Can模块接口实现文件           | 无需配置       |
| Canfd_Im.h  | Can模块芯片适配层接口文件     | 无需配置       |
| Canfd_Im.c  | Can模块芯片适配层接口实现文件 | 无需配置       |
| Can_Cfg.h   | Can模块功能配置文件           | ***需要配置*** |
| Can_Cfg.c   | Can模块功能配置文件           | 无需配置       |
| Can_LCfg.h  | Can模块参数宏封装文件         | 无需配置       |
| can_LCfgc.c | Can模块配置变量存储文件       | ***需要配置*** |


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
本节描述了相对于支持的微控制器的配置参数的变化。Can Driver在支持的微控制器上没有变化的参数。

## 4.3 Can_Cfg.h文件配置说明
+ ID定义(无需修改)
``` 
#define CAN_INSTANCE_ID ((uint8)0U)
#define CAN_VENDOR_ID   ((uint16)88U)
#define CAN_MODULE_ID   ((uint16)80U)
```
+ 错误类型定义(无需修改)
``` 
#define CAN_E_NO_ERROR           ((uint8)0x00U)
#define CAN_E_PARAM_POINTER      ((uint8)0x01U)
#define CAN_E_PARAM_HANDLE       ((uint8)0x02U)
#define CAN_E_PARAM_DATA_LENGTH  ((uint8)0x03U)
#define CAN_E_PARAM_CONTROLLER   ((uint8)0x04U)
#define CAN_E_UNINIT             ((uint8)0x05U)
#define CAN_E_TRANSITION         ((uint8)0x06U)
#define CAN_E_PARAM_BAUDRATE     ((uint8)0x07U)
#define CAN_E_INIT_FAILED        ((uint8)0x09U)
#define CAN_E_PARAM_LPDU         ((uint8)0x0AU)
#define CAN_E_INVALID_CONTROLLER ((uint8)0x0BU)
#define CAN_E_PARAM_HOH          ((uint8)0x0CU)
#define CAN_E_DATALOST           ((uint8)0x0DU)
```
+ API ID定义(无需修改)
``` 
#define CAN_SID_DEINIT                          ((uint8)0x10U)
#define CAN_SID_INIT                            ((uint8)0x00U)
#define CAN_SID_MAIN_FUNCTION_WRITE             ((uint8)0x01U)
#define CAN_SID_SET_CONTROLLER_MODE             ((uint8)0x03U)
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS   ((uint8)0x04U)
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS    ((uint8)0x05U)
#define CAN_SID_WRITE                           ((uint8)0x06U)
#define CAN_SID_GET_VERSION_INFO                ((uint8)0x07U)
#define CAN_SID_MAIN_FUNCTION_READ              ((uint8)0x08U)
#define CAN_SID_MAIN_FUNCTION_BUS_OFF           ((uint8)0x09U)
#define CAN_SID_MAIN_FUNCTION_WAKEUP            ((uint8)0x0AU)
#define CAN_SID_CHECK_WAKEUP                    ((uint8)0x0BU)
#define CAN_SID_MAIN_FUNCTION_MODE              ((uint8)0x0CU)
#define CAN_SID_SET_BAUDRATE                    ((uint8)0x0FU)
#define CAN_SID_GET_CONTROLLER_ERROR_STATE      ((uint8)0x11U)
#define CAN_SID_GET_CONTROLLER_MODE             ((uint8)0x12U)
#define CAN_SID_ABORT_HTH                       ((uint8)0x13U)
#define CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER ((uint8)0x30U)
#define CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER ((uint8)0x31U)
#define CAN_SID_GET_CURRENT_TIME                ((uint8)0x32U)
#define CAN_SID_ENABLE_EGRESS_TIMESTAMP         ((uint8)0x33U)
#define CAN_SID_GET_EGRESS_TIMESTAMP            ((uint8)0x34U)
#define CAN_SID_GET_INGRESS_TIMESTAMP           ((uint8)0x35U)
```
+ Error Mask定义(无需修改)
``` 
#define CANFD_ERROR_ACTIVE_MASK  ((uint32)0x11U)
#define CANFD_ERROR_PASSIVE_MASK ((uint32)0x16U)
```
+ CAN_PRECOMPILE_SUPPORT(需要配置)
>配置是否使用预编译的配置

>STD_ON:默认使用Can_ConfigPredefined的配置初始化CAN驱动
>``` 
>#define CAN_PRECOMPILE_SUPPORT (STD_ON)
>
>影响Can_Init函数的调用，如：
>Can_Init(NULL_PTR);
>此时Can_Init传入的其他参数将不会起作用，默认将Can_ConfigPredefined作为参数进行初始化
>```

>STD_OFF:不使用默认的参数配置初始化CAN驱动，配置参数需要自行传入
>``` 
>#define CAN_PRECOMPILE_SUPPORT (STD_OFF)
>
>影响Can_Init函数的调用，如：
>Can_Init(&UserCanCfg);
>此时Can_Init需要传入一个Can_ConfigType类型的配置参数UserCanCfg
>```

+ CAN_DEV_ERROR_DETECT(需要配置)
> 配置是否检测错误，当使能后，运行过程中检测到的错误将从Can_Det_ReportError接口上报。Can_Det_ReportError接口需要用户自定义
>```
>STD_ON  开启错误检测
>STD_OFF 关闭错误检测
>```

+ CAN_MAINFUNCTION_MODE_PERIOD(需要配置)
> 配置是否检测错误，当使能后，运行过程中检测到的错误将从Can_Det_ReportError接口上报。Can_Det_ReportError接口需要用户自定义
>```
>STD_ON  开启错误检测
>STD_OFF 关闭错误检测
>```

+ CAN_DEINIT_CONTROLLER_API(需要配置)
> 配置Can_DeInit函数是否使用，此接口用于反初始化Can驱动
>```
>STD_ON  使用，函数将被编译进固件
>STD_OFF 不使用，函数将不被编译
>```

+ CAN_SET_BAUDRATE_API(需要配置)
> 配置Can_SetBaudrate函数是否使用，此接口用于设置指定Can控制器的波特率
>```
>STD_ON  使用，函数将被编译进固件
>STD_OFF 不使用，函数将不被编译
>```

+ CAN_VERSION_INFO_API(需要配置)
> 配置Can_GetVersionInfo函数是否使用，此接口用于获取Can驱动软件的版本号
>```
>STD_ON  使用，函数将被编译进固件
>STD_OFF 不使用，函数将不被编译
>```

+ CAN_ENABLE_WAKEUP_SUPPORT(需要配置)
> 配置Can模块是否支持唤醒功能
>```
> STD_OFF Can模块不支持唤醒
> STD_ON  Can模块支持唤醒。此时需要用户定义EcuM_SetWakeupEvent函数。并且需要配置CAN_WUINT_SUPPORTED或
> CAN_WUPOLL_SUPPORTED任一个为STD_ON
>```

+ CAN_TRIGGER_TRANSMIT_EN(需要配置)
> 配置Can模块是否支持触发发送功能
>```
> STD_OFF Can模块不支持触发发送，此时调用Can_Write发送数据时，将会检查传入的PduInfo中是否存在数据域，无数据域的话将发送失败
> STD_ON  Can模块支持触发发送。此时调用Can_Write发送数据时，将不检查传入的PduInfo中是否存在数据域，都可以发送成功
>```

+ CAN_API_ENABLE_ABORT_HTH(需要配置)
> 配置Can_AbortHTH函数是否使用，取消发送某一条报文
>```
>STD_ON  使用，函数将被编译进固件
>STD_OFF 不使用，函数将不被编译
>```

> 控制波特率配置的数量，如下：
>```
>CONST(Can_ArbitrateBDRConfigType,CAN_CONST) Can_ControllerCanBDRConfig[CAN_CFG_MAX_CONTROLLER][2U]
>CONST(Can_FdDataBDRConfigType,CAN_CONST) Can_ControllerFdBDRConfig[CAN_CFG_MAX_CONTROLLER][2U]
>```

+ CAN_TX_NOTIFICATION(需要配置)
> 控制报文发送成功后是否调用用户通知函数
>```
>STD_ON  使用，报文发送后将调用用户通知函数，必须配置Can_ControllerDescriptor中的TxConfirmationNotification
>STD_OFF 关闭此功能
>```

+ CAN_RX_INDICATION(需要配置)
> 控制接收到一条报文后是否调用用户通知函数
>```
>STD_ON  使用，接收到一条报文后将调用用户通知函数，必须配置Can_ControllerDescriptor中的RxIndicationNotification
>STD_OFF 关闭此功能
>```

+ CAN_ERROR_NOTIFICATION(需要配置)
> 控制检测到错误后是否调用用户通知函数
>```
>STD_ON  使用，检测到错误后将调用用户通知函数，必须配置Can_ControllerDescriptor中的BusErrorNotification
>STD_OFF 关闭此功能
>```

+ CAN_OFF_NOTIFICATION(需要配置)
> 控制检测到Bus Off事件后是否调用用户通知函数
>```
>STD_ON  使用，Bus Off事件发生后将调用用户通知函数，必须配置Can_ControllerDescriptor中的BusOffNotification
>STD_OFF 关闭此功能
>```

+ CAN_WAKEUP_NOTIFICATION(需要配置)
> 控制检测到Wakeup后是否调用用户通知函数
>```
>STD_ON  使用，检测到Wakeup后将调用用户通知函数，必须配置Can_ControllerDescriptor中的Can_WakeUpNotification
>必须使能CAN_ENABLE_WAKEUP_SUPPORT
>STD_OFF 关闭此功能
>```

+ CAN_BUSOFF_SOFTWARE_RECOVERY(需要配置)
> 设置是否通过软件实现Busoff自恢复机制，该配置应和CAN_BUSOFF_HARDWARE_RECOVERY的配置相反
>```
>STD_ON  使用软件Busoff自恢复功能
>STD_OFF 不使用软件Busoff自恢复功能
>```

+ CAN_BUSOFF_HARDWARE_RECOVERY(需要配置)
> 控制是否使能Can控制器硬件自带的Bus off自恢复机制，若用户需要使用上层软件实现的Busoff恢复机制，此处应配置为STD_OFF。
> 该配置应和CAN_BUSOFF_SOFTWARE_RECOVERY的配置相反
>```
>STD_ON  使用Can控制器硬件自带的Busoff机制
>STD_OFF 关闭Busoff硬件自恢复功能
>```

+ CAN_WAKEUP_TOSTART(需要配置)
> 控制Can控制器wakeup后，是否自动进入Start Mode
> 使用该配置的前提是CAN_WAKEUP_SUPPORT应配置为STD_ON
>```
>STD_ON  使用Can控制器硬件自带的Busoff机制
>STD_OFF 关闭Busoff硬件自恢复功能
>```
+ CAN_GLOBAL_TIME_SUPPORT(需要配置)
> 控制时间相关的Api是否使用，如Can_EnableEgressTimeStamp、Can_GetCurrentTime、Can_GetEgressTimeStamp、Can_GetIngressTimeStamp
>```
>STD_ON  使用
>STD_OFF 不使用
>```

+ CAN_CANFD_MODE(需要配置)
> 控制是否使用CANFD协议
>```
>STD_ON    使用
>STD_OFF   不使用
>```

+ CAN_HARDWARE_FILTER(需要配置)
> 控制报文接收是否使用硬件过滤机制
>```
>STD_ON    使用
>STD_OFF   不使用
>```

+ CAN_MASK_IF_API(需要配置)
> 控制是否屏蔽CanIf层的通知函数
>```
>STD_ON    屏蔽
>STD_OFF   不屏蔽
>```

+ CAN_NACKERRINT_SUPPORTED(需要配置)
> 控制开启未收到ACK事件由中断软件处理
>```
>STD_ON    开启
>STD_OFF   不开启
>```

+ CAN_TXPOLL_SUPPORTED(需要配置)
> 控制开启报文发送事件由轮询软件处理
>```
>STD_ON    开启
>STD_OFF   不开启
>```


+ CAN_RXPOLL_SUPPORTED(需要配置)
> 控制开启报文接收事件由轮询软件处理
>```
>STD_ON    开启
>STD_OFF   不开启
>```

+ CAN_BOPOLL_SUPPORTED(需要配置)
> 控制开启BusOFF通知由轮询软件处理
>```
>STD_ON    开启
>STD_OFF   不开启
>```

+ CAN_CFG_MAX_CONTROLLER(需要配置)
> 配置使用的Can控制器的数量（1-3）
>```
>STD_ON    开启
>STD_OFF   不开启
>```

+ CAN_CFG_MAX_MAILBOX_NUMBER(无需配置)
> 提供该芯片最大MailBox的数量
>```
>#define CAN_CFG_MAX_MAILBOX_NUMBER  (51U)
>```

+ 不同PayLoad时，Mailbox的数量(无需配置)
> 提供该芯片Can Mailbox配置不同Payload size时，最大MailBox的数量
>```
>#define CAN_MAX_8MAILBOX_NUMBER  (51U)
>#define CAN_MAX_16MAILBOX_NUMBER (36U)
>#define CAN_MAX_32MAILBOX_NUMBER (23U)
>#define CAN_MAX_64MAILBOX_NUMBER (13U)
>```

+ CANDRIVER_INTERNAL_TRACE_LOGGER(需要配置)
> 配置是否开启Can Driver内部的Trace输出功能
>```
>STD_ON    开启
>STD_OFF   不开启
>```

+ 控制器各Can控制器是否激活使用(需要配置)
>```
>STD_ON    开启
>STD_OFF   不开启
>#define CAN_0_CONTROLLER_ACTIVATION (STD_ON)
>#define CAN_1_CONTROLLER_ACTIVATION (STD_ON)
>#define CAN_2_CONTROLLER_ACTIVATION (STD_ON)
>```


## 4.4 can_LCfgc.c文件配置说明

+ Can控制器0-2的事件处理方式配置选择(需要配置)
> 下方Can_ControllerDescriptor中Can控制器0-2的配置量会根据这里的配置自动选择正确的配置项。以下以Can0举例：

+ 各个Can控制器的物理映射(无需配置)
>```

>#define CAN_HW_CONTROLLER_CANFD6 (CANFD6)
>#define CAN_HW_CONTROLLER_CANFD7 (CANFD7)
>#define CAN_HW_CONTROLLER_CANFD8 (CANFD8)
>#define CAN_HW_CONTROLLER_CANFD9 (CANFD9)
>```

+ 各个Can控制器通知函数声明(无需配置)
```
#if (CAN_0_CONTROLLER_ACTIVATION == STD_ON)
void __attribute__((weak)) Can0_UserErrorNotification(void);
void __attribute__((weak)) Can0_UserOffNotification(void);
#if (CAN_WAKEUP_NOTIFICATION == STD_ON)
void __attribute__((weak)) Can0_WakeUpNotification(void);
#endif
void __attribute__((weak)) Can0_TxNotification(Can_HwHandleType Hth);
void __attribute__((weak)) Can0_RxNotification(Can_PduType *PduInfoPtr);
#endif

#if (CAN_1_CONTROLLER_ACTIVATION == STD_ON)
void __attribute__((weak)) Can1_UserErrorNotification(void);
void __attribute__((weak)) Can1_UserOffNotification(void);
#if (CAN_WAKEUP_NOTIFICATION == STD_ON)
void __attribute__((weak)) Can1_WakeUpNotification(void);
#endif
void __attribute__((weak)) Can1_TxNotification(Can_HwHandleType Hth);
void __attribute__((weak)) Can1_RxNotification(Can_PduType *PduInfoPtr);
#endif

#if (CAN_2_CONTROLLER_ACTIVATION == STD_ON)
void __attribute__((weak)) Can2_UserErrorNotification(void);
void __attribute__((weak)) Can2_UserOffNotification(void);
#if (CAN_WAKEUP_NOTIFICATION == STD_ON)
void __attribute__((weak)) Can2_WakeUpNotification(void);
#endif
void __attribute__((weak)) Can2_TxNotification(Can_HwHandleType Hth);
void __attribute__((weak)) Can2_RxNotification(Can_PduType *PduInfoPtr);
#endif
```

+ 仲裁段波特率配置数组(需要配置)
> 这里定义了每个控制器将要使用到的仲裁段波特率，用户使用时可以根据波特率配置ID来引用，每组波特率使用Can_ArbitrateBDRConfigType结构体来配置参数
>```
>static CONST(Can_ArbitrateBDRConfigType,CAN_CONST) Can_ControllerCanBDRConfig[CAN_CFG_MAX_CONTROLLER][2U];
>   举例：
>      {
    /* Set FD baudrate to 500Khz bps 75% sample point */
    /** @brief BaudRate Id */
    .BaudRateConfigID = 0U,
    /** @brief baud rate */
    .CanControllerFdBaudRate = 500U,
    /** @brief Tx Arbitration start delay */
    .TxArbitrationDelay = 0U,
    /** @brief PreScale */
    .PreScale = 3U,
    /** @brief PropSeg */
    .PropSeg = 8U,
    /** @brief TSeg1 */
    .TSeg1 = 4U,
    /** @brief TSeg2 */
    .TSeg2 = 4U,
    /** @brief Sjw */
    .Sjw = 4U,
    /** @brief Sample time */
    .SampleTimes = CAN_SAMPLE_ONCE,
>      }
>```
> | 配置名称             | 说明                                              |
> |------------------|-------------------------------------------------|
> | BaudRateConfigID | 该波特率的ID，用户调用Can_SetBaudrate时，将检查传入的id与这个ID是否一致  |
> | PreScale         | 波特率预分频系数，此值需要根据实际需要的波特率及查询寄存器定义配置合适的值           |
> | TSeg1            | 时间段1配置，此值需要根据实际需要的波特率及查询寄存器定义配置合适的值             |
> | TSeg2            | 时间段2配置，此值需要根据实际需要的波特率及查询寄存器定义配置合适的值             |
> | Sjw              | 同步跳转宽度，此值需要根据实际需要查询寄存器定义配置合适的值                  |
> | SampleTimes      | 采样次数，可选CAN_SAMPLE_ONCE或CAN_SAMPLE_THREE_TIMES   |

+ 数据段波特率配置数组(需要配置)
> 这里定义了每个控制器将要使用到的数据段的波特率配置，用户使用时可以根据波特率配置ID来引用，每组波特率使用Can_ArbitrateBDRConfigType结构体来配置参数
>```
>static CONST(Can_FdDataBDRConfigType,CAN_CONST) Can_ControllerFdBDRConfig[CAN_CFG_MAX_CONTROLLER][2U];
>   举例：
>       {
      /* Set FD baudrate to 2Mhz bps 80% sample point */
      /** @brief baud rate */
      .CanControllerFdBaudRate = 2000U,
      /** @brief BrsPrescale */
      .BrsPrescale = 1U,
      /** @brief HSjw */
      .HSjw = 1U,
      /** @brief PropSeg */
      .PropSeg = 5U,
      /** @brief HtSeg1 */
      .HtSeg1 = 1U,
      /** @brief HtSeg2 */
      .HtSeg2 = 1U,
      /** @brief TDC */
      .EnableTdc = FALSE,
      /** @brief TDC offset */
      .TdcOffset = 0U,
>       }, 
>```
> | 配置名称        | 说明                                     |
> |-------------|----------------------------------------|
> | BrsPrescale | 高速段预分频，此值需要根据实际需要的波特率及查询寄存器定义配置合适的值    |
> | HtSeg1      | 高速段时间段1配置，此值需要根据实际需要的波特率及查询寄存器定义配置合适的值 |
> | HtSeg2      | 高速段时间段2配置，此值需要根据实际需要的波特率及查询寄存器定义配置合适的值 |
> | HSjw        | 高速段同步跳转宽度，此值需要根据实际需要查询寄存器定义配置合适的值      |

+ 配置各Can控制器可用的仲裁段波特率配置指针(需要配置)
> 这里定义了每个Can控制器可用的第一个波特率配置的指针，用户将通过索引，调用Can控制器可用的波特率配置
>```
>static CONST(Can_ArbitrateBDRArrayConfigType, CAN_CONST) Can_BDRArrayConfig[CAN_CFG_MAX_CONTROLLER] = 
>   {
>     [0U] =
>       {
>         /** @brief controller BaudRate array config */
>         .ArbitrateBDRConfigPtr = &Can_ControllerCanBDRConfig[0U][0U],
>       },
>     [1U] =
>       {
>         /** @brief controller BaudRate array config */
>         .ArbitrateBDRConfigPtr = &Can_ControllerCanBDRConfig[1U][0U],
>       },
>     [2U] = 
>       {
>          /** @brief controller BaudRate array config */
>          .ArbitrateBDRConfigPtr = &Can_ControllerCanBDRConfig[2U][0U],
>       }
>   }；
>```
> | 配置名称                   | 说明                     |
> |------------------------|------------------------|
> | ArbitrateBDRConfigPtr  | 该控制器可用的第一个波特率配置数组元素的指针 |

+ 各控制器CanFD配置(需要配置)
> 这里定义了每个Can控制器的CanFD协议参数
>```
>static CONST(Can_FDConfigType, CAN_CONST) Can_ControllerFdConfig[CAN_CFG_MAX_CONTROLLER];
>   举例：
>       {
>         /** @brief CanFd status */
>         .CanFdEnable = TRUE,
>         /** @brief CanFd BRS status */
>         .CanFdTxBitRateSwitch = TRUE,
>         /** @brief CanFd frame mode */
>         .CanFdFrameMode = CAN_FD_ISOMODE,
>         /** @brief CanFd data BaudRate config */
>         .CanFdDataBDRConfigPtr = &Can_ControllerFdBDRConfig[0U][0U],
>       },
>       
>```
> | 配置名称                  | 说明                                            |
> |-----------------------|-----------------------------------------------|
> | CanFdEnable           | 配置此控制器是否使用CanFD协议(TRUE\FALSE)                 |
> | CanFdTxBitRateSwitch  | 位速率转换开关使能(TRUE\FALSE)                         |
> | CanFdFrameMode        | CanFD帧类型定义（CAN_FD_ISOMODE\CAN_FD_NON_ISOMODE） |
> | CanFdDataBDRConfigPtr | 数据段波特率配置指针                                    |

+ 各控制器事件通知配置Can_ControllerDescriptor(无需配置)
> 这里的配置值已根据宏定义自动选择正确的值，无需配置
>
> static CONST(Can_DescriptorType, CAN_CONST) Can_ControllerDescriptor[CAN_CFG_MAX_CONTROLLER];

+ 各控制器接收Buff索引范围配置(需要配置)
> 这里定义了每个控制器接收Buff的起止索引值，由于接收报文总是定义在Can_ControllerHOHConfig数组的最前面，所以接收Buff的索引就是它在Can_ControllerHOHConfig中的索引
>```
>static CONST(Can_HRHRangeType, CAN_CONST) Can_ControllerHRHRangeConfig[CAN_CFG_MAX_CONTROLLER];
>   举例：
>      {
>        /** @brief HRH start index of HOH config */
>        .StartHrh = 0U,
>        /** @brief HRH end index of HOH config */
>        .EndHrh = 8U,
>      },
>```
> | 配置名称       | 说明                                               |
> |------------|--------------------------------------------------|
> | StartHrh   | Can_ControllerHOHConfig中定义的属于该控制器的第一个接收Buff的索引值  |
> | EndHrh     | Can_ControllerHOHConfig中定义的属于该控制器的最后一个接收Buff的索引值 |

+ 各控制器发送Buff索引范围配置(需要配置)
> 这里定义了每个控制器发送Buff的起止索引值，（必须从0开始，Buff在Can_ControllerHOHConfig数组中的索引值-该数组中第一个发送报文配置的索引值即CanFirstHTHNumber
>```
>static CONST(Can_HTHRangeType, CAN_CONST) Can_ControllerHTHRangeConfig[CAN_CFG_MAX_CONTROLLER];
>   举例：
>       {
>         /** @brief can controller 0 HTH start index of HOH config */
>         .StartHth = 0U,
>         /** @brief can controller 0 HTH end index of HOH config */
>         .EndHth = 11U,
>       },
>```
> | 配置名称     | 说明                                               |
> |----------|--------------------------------------------------|
> | StartHth | Can_ControllerHOHConfig中定义的属于该控制器的第一个发送Buff的索引值  |
> | EndHth   | Can_ControllerHOHConfig中定义的属于该控制器的最后一个发送Buff的索引值 |


+ 定义所有控制器发送、接收的报文配置数组(需要配置)
> 这里定义了所有控制器发送、接收报文的配置，需要注意：
- 同一个控制器定义的报文接收配置数组元素必须是连续的放在一块、发送报文同样如此。
- 所有控制器的接收报文必须统一放在Can_ControllerHOHConfig数组前面，接收报文定义完毕后，再定义发送报文的配置
>```
>static CONST(Can_HOHType, CAN_CONST) Can_ControllerHOHConfig[];
>   接收举例：
>      {
>        /** @brief receive or write */
>        .HOHType = CAN_RECEIVE,
>        /** @brief filter status */
>        .bFilterEnable = FALSE,
>        /** @brief receive frame Id */
>        .HRHType.FullCan_HRH.Id = 0x193F31U,
>        /** @brief receive frame type */
>        .HRHType.FullCan_HRH.IdType = CAN_DATA_EXTENDED,
>        /** @brief mailbox start index */
>        .StartMbIndex = 0U,
>        /** @brief mailbox end index */
>        .EndMbIndex = 1U,
>        /** @brief api HOH index find controller */
>        .CfgId = CONTROLLER_0,
>      },
>   发送举例：
>      {
>        .HOHType           = CAN_TRANSMIT,
>        .StartMbIndex      = 8U,
>        .EndMbIndex        = 9U,
>        .CfgId             = CONTROLLER_0,
>  #if (CAN_CANFD_MODE == STD_ON)
>        .CanFdPaddingValue = 0xFFU,
>  #endif
>      }, 
>```
> | 配置名称                            | 说明                                                                  |
> |---------------------------------|---------------------------------------------------------------------|
> | HOHType                         | 配置该条Buff配置是接收还是发送类型（CAN_RECEIVE、CAN_TRANSMIT）                       |
> | bFilterEnable                   | 配置该条Buff配置是否需要使能硬件Filter，此选项只有在HOHType是CAN_RECEIVE才有意义（仅接收Buff需要配置） |
> | HRHType.FullCan_HRH.Id          | 配置该条Buff配置的ID（仅接收Buff需要配置）                                          |
> | HRHType.FullCan_HRH.IdType      | 配置该条Buff配置的ID类型（仅接收Buff需要配置） （CAN_DATA_EXTENDED、CAN_DATA_STANDARD）  |
> | StartMbIndex                    | 配置该条Buff配置使用的硬件Mailbox起始索引                                          |
> | EndMbIndex                      | 配置该条Buff配置使用的硬件Mailbox结束索引                                          |
> | CfgId                           | 配置该条Buff配置所归属的Can控制器ID                                              |
> | CanFdPaddingValue               | 配置CanFd数据域需要填充的默认值 （仅发送Buff需要配置）                                    |

+ 定义所有控制器配置数组(需要配置)
> 这里定义了所有控制器的配置，一部分配置需要用户自己配置，一部分配置无需修改。
>```
>static CONST(Can_ControllerType, CAN_CONST) Can_ControllerConfig[CAN_CFG_MAX_CONTROLLER];
>   举例：
>      {
>        /** @brief can id */
>        .HardwareID = CAN_HW_CONTROLLER_CANFD8,
>        /** @brief can work mode */
>        .WorkMode = CAN_NORMAL_MODE,
>  #if (CAN_BUSOFF_HARDWARE_RECOVERY == STD_ON)
>        /** @brief hardware recovery */
>        .HBORecovery = STD_ON,
>  #endif
>        /** @brief clock source */
>        .ClockSource = CAN_CLOCKSOURCE_HFCLK,
>  #if (CAN_CANFD_MODE == STD_ON)
>        /** @brief CanFd mail box size */
>        .MailBoxBlockSize = CAN_PAYLOAD_8BYTE,
>  #endif
>        /** @brief Interrupt config */
>        .InterruptConfigPtr = NULL_PTR,
>        /** @brief Arbitrate Segment Baudrate Config */
>        .ArbitrateBDRArrayConfigPtr = &Can_BDRArrayConfig[0U],
>  #if (CAN_CANFD_MODE == STD_ON)
>        /** @brief CanFd config */
>        .CanFdConfigPtr = &Can_ControllerFdConfig[0U],
>  #endif
>        /** @brief can controller information */
>        .DescriptorPtr = &Can_ControllerDescriptor[0U],
>      },
>  
>```
> | 配置名称                       | 说明                                                                |
> |----------------------------|-------------------------------------------------------------------|
> | HardwareID                 | 配置该控制器对应的物理Can控制器索引（CAN_HW_CONTROLLER_CANFD6-8）                   |
> | WorkMode                   | 配置该控制器默认工作模式（可取枚举Can_WorkModeType中的范围）                            |
> | HBORecovery                | 配置该控制器是否开启Busoff硬件自恢复功能（使能该功能时需要先开启宏CAN_BUSOFF_HARDWARE_RECOVERY） |
> | ClockSource                | 配置该控制器的时钟源（可选取枚举Can_ClockSourceType中的范围）                          |
> | MailBoxBlockSize           | 配置该控制器最大的数据域大小（可选取枚举Can_PayLoadSizeType中的范围）                      |
> | InterruptConfigPtr         | 配置该控制器的中断事件使能配置数据指针（无需修改）                                         |
> | ArbitrateBDRArrayConfigPtr | 配置该控制器仲裁段波特率配置数据指针（无需修改）                                          |
> | CanFdConfigPtr             | 配置该控制器CanFD功能配置数据指针（无需修改）                                         |
> | DescriptorPtr              | 配置该控制器事件通知功能配置数据指针（无需修改）                                          |

+ 定义Can驱动配置总数据(无需配置)
> 这里定义了一个总的Can_ConfigType类型配置变量Can_ConfigPredefined，此变量集合了该Can驱动的所有配置数据，用户初始化时将调用此配置数据进行Can初始化
>```
>   举例：
>      CONST(Can_ConfigType, CAN_CONST)
>      Can_ConfigPredefined = {
>        /** @brief can controller config */
>        .CanControllerSets = &Can_ControllerConfig,
>        /** @brief can HOH information config */
>        .CanHOHSets = &Can_ControllerHOHConfig,
>        /** @brief HOH config number */
>        .CanHOHNumber = sizeof(Can_ControllerHOHConfig) / sizeof(Can_HOHType),
>      };
>  
>```
> | 配置名称              | 说明                                 |
> |-------------------|------------------------------------|
> | CanControllerSets | 该Can驱动所有Can控制器配置的指针                |
> | CanHOHSets        | 该Can驱动所有Can Object Hardware配置的指针   |
> | CanHRHRangeSets   | 该Can驱动所有Can控制器对应的起止接收Mailbox范围     |
> | CanHTHRangeSets   | 该Can驱动所有Can控制器对应的起止发送Mailbox范围     |
> | CanHOHNumber      | 该Can驱动包含的Can Object Hardware数量     |

+ 预定义函数(无需修改)
> 以下定义了驱动中使用的一些预定义函数，这些函数使用了weak修饰，用户可以自定义此函数的实现，而不用修改此处
``` 
#define CAN_SID_DEINIT                          ((uint8)0x10U)
#define CAN_SID_INIT                            ((uint8)0x00U)
#define CAN_SID_MAIN_FUNCTION_WRITE             ((uint8)0x01U)
#define CAN_SID_SET_CONTROLLER_MODE             ((uint8)0x03U)
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS   ((uint8)0x04U)
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS    ((uint8)0x05U)
#define CAN_SID_WRITE                           ((uint8)0x06U)
#define CAN_SID_GET_VERSION_INFO                ((uint8)0x07U)
#define CAN_SID_MAIN_FUNCTION_READ              ((uint8)0x08U)
#define CAN_SID_MAIN_FUNCTION_BUS_OFF           ((uint8)0x09U)
#define CAN_SID_MAIN_FUNCTION_WAKEUP            ((uint8)0x0AU)
#define CAN_SID_CHECK_WAKEUP                    ((uint8)0x0BU)
#define CAN_SID_MAIN_FUNCTION_MODE              ((uint8)0x0CU)
#define CAN_SID_SET_BAUDRATE                    ((uint8)0x0FU)
#define CAN_SID_GET_CONTROLLER_ERROR_STATE      ((uint8)0x11U)
#define CAN_SID_GET_CONTROLLER_MODE             ((uint8)0x12U)
#define CAN_SID_ABORT_HTH                       ((uint8)0x13U)
#define CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER ((uint8)0x30U)
#define CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER ((uint8)0x31U)
#define CAN_SID_GET_CURRENT_TIME                ((uint8)0x32U)
#define CAN_SID_ENABLE_EGRESS_TIMESTAMP         ((uint8)0x33U)
#define CAN_SID_GET_EGRESS_TIMESTAMP            ((uint8)0x34U)
#define CAN_SID_GET_INGRESS_TIMESTAMP           ((uint8)0x35U)
```
---

# 第5章 发布的参数

## 5.1 VendorId
- **语法**: CAN_VENDOR_ID
- **类型**: 宏定义 (#define)
- **文件**: Can.h
- **值**: 43
- **描述**: 这个宏给出了CAN驱动厂商ID，如AUTOSAR所述

## 5.2 ModuleId
- **语法**: CAN_MODULE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint16
- **文件**: Can.h
- **值**: 80
- **描述**: 这个宏给出了CAN驱动模块ID，如AUTOSAR所述

## 5.3 InstanceId
- **语法**: CAN_INSTANCE_ID
- **类型**: 宏定义 (#define)，类型转换为 uint8
- **文件**: Can.h
- **值**: 0
- **描述**: 这个宏给出了CAN驱动实例ID，如AUTOSAR所述

## 5.4 SwMajorVersion
- **语法**: CAN_SW_MAJOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Can.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的主要版本号。如果驱动程序不再向下兼容（例如，现有API已更改），则增加MAJOR_VERSION

## 5.5 SwMinorVersion
- **语法**: CAN_SW_MINOR_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Can.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的次要版本号。如果驱动程序仍然向下兼容（例如，添加了新功能），则增加MINOR_VERSION

## 5.6 SwPatchVersion
- **语法**: CAN_SW_PATCH_VERSION
- **类型**: 宏定义 (#define)
- **文件**: Can.h
- **值**: 取决于交付
- **描述**: 供应商特定实现的补丁级别版本号。如果驱动程序仍然向上和向下兼容（例如，已修复的错误），则增加PATCH_VERSION

---

# 第6章 API文档
## 6.1 API类型定义

### 6.1.1 类型定义 Can_ConfigType
- **语法**: Can_ConfigType
- **类型**: Struct
- **文件**: Can_Types.h
- **范围**:
  - CanControllerSets (Can_ControllerType*)
    - 指向指向各Can控制器的配置数据
  - CanHOHSets (Can_HOHType*)
    - 指向所有的报文配置数据
  - CanHOHNumber（uint32）
    - CanHOHSets的个数
- **描述**: 此类型定义用于配置Can Driver的整体配置。此类型的指针在Can_Init API中用于初始化Can驱动程序。

### 6.1.2 类型定义 Can_PduType
- **语法**: Can_PduType
- **类型**: Struct
- **文件**: Can_GeneralTypes.h
- **范围**:
  - swPduHandle (PduIdType)
    - 调用者发送报文的协议层ID
  - length (uint8)
    - 报文的数据长度
  - id (Can_IdType)
    - 报文的id
  - sdu（uint8*）
    - 报文的数据指针
- **描述**: 此类型定义用于定义一个PDU的内部具体变量。此类型在Can_Write API中用于发送Can报文。

### 6.1.3 类型定义 Can_IdType
- **语法**: Can_IdType
- **类型**: uint16/uint32
- **文件**: Can_GeneralTypes.h
- **范围**: 标准帧uint16：0..0x7FF/扩展帧：0..0x1FFFFFFF
- **描述**: 报文的ID值。


### 6.1.4 类型定义 Can_HwHandleType
- **语法**: Can_HwHandleType
- **类型**: uint8/uint16
- **文件**: Can_GeneralTypes.h
- **范围**: 标准模式uint16：0..0xFF/扩展模式：0..0xFFFF
- **描述**: 报文的配置Hoh索引类型。


### 6.1.5 类型定义 Can_HwType
- **语法**: Can_HwType
- **类型**: Struct
- **文件**: Can_GeneralTypes.h
- **范围**:
  - CanId (Can_IdType)
    - 报文的ID
  - Hoh (Can_HwHandleType)
    - 报文的Hoh配置索引
  - ControllerId（uint8）
    - 报文所归属的Can控制器
- **描述**: 此类型定义了一个硬件对象句柄，用于在不同软件层之间传递数据，此类型在CanIf_RxIndication中用于传递一个硬件对象。

### 6.1.6 类型定义 Std_ReturnType
- **语法**: Std_ReturnType
- **类型**: enum
- **文件**: Can_GeneralTypes.h
- **范围**:
  - E_OK
    - 操作成功
  - E_NOT_OK
    - 操作失败
  - CAN_BUSY
    - 硬件忙导致操作失败
- **描述**: 此类型定义了Can Driver Api的返回值类型。

### 6.1.7 类型定义 Can_ErrorStateType
- **语法**: Can_ErrorStateType
- **类型**: enum
- **文件**: Can_GeneralTypes.h
- **范围**:
  - CAN_ERRORSTATE_ACTIVE
    - Can控制器处于主动错误状态
  - CAN_ERRORSTATE_PASSIVE
    - Can控制器处于被动错误状态
  - CAN_ERRORSTATE_BUSOFF
    - Can控制器处于总线关闭状态
- **描述**: 此类型定义了Can 控制器当前的错误状态。

### 6.1.8 类型定义 Can_ControllerStateType
- **语法**: Can_ControllerStateType
- **类型**: enum
- **文件**: Can_GeneralTypes.h
- **范围**:
  - CAN_CS_UNINIT
    - 未初始化
  - CAN_CS_STARTED
    - 已启动
  - CAN_CS_STOPPED
    - 已停止
  - CAN_CS_SLEEP
    - 已睡眠
- **描述**: 此类型定义了Can 控制器当前的运行状态。

### 6.1.9 类型定义 Can_TimeStampType
- **语法**: Can_TimeStampType
- **类型**: struct
- **文件**: Can_GeneralTypes.h
- **范围**:
  - nanoseconds (uint32)
    - 时间戳纳秒部分
  - seconds (uint32)
    - 时间戳秒部分
- **描述**: 此类型定义Can驱动时间戳的结构。

## 6.2 API接口
> 以下接口为AutoSAR标准接口，请查阅《AUTOSAR_SWS_CANDriver.pdf》查看功能说明。

### 6.2.1 Can_GetVersionInfo
- **服务名称**: Can_GetVersionInfo
- **语法**: void Can_GetVersionInfo ( Std_VersionInfoType *VersionInfoPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x07
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: VersionInfoPtr: 存储驱动版本信息的指针。
- **返回值**: 无
- **描述**: 获取驱动的版本信息的服务。

### 6.2.2 Can_Init
- **服务名称**: Can_Init
- **语法**: void Can_Init (const Can_ConfigType *ConfigPtr )
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x00
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: ConfigPtr 指向配置集的指针。
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 根据给定配置初始化Can驱动程序的服务。

### 6.2.3 Can_DeInit
- **服务名称**: Can_DeInit
- **语法**: void Can_DeInit (void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x10
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 将所有硬件定时器通道初始化为其上电复位状态的服务。此服务还禁用通知和唤醒事件。

### 6.2.4 Can_SetBaudrate
- **服务名称**: Can_SetBaudrate
- **语法**: Std_ReturnType Can_SetBaudrate (uint8 Controller, uint16 BaudRateConfigID)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x0F
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,要切换波特率的控制器ID。BaudRateConfigID,要切换的波特率配置ID
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 此服务将切换指定Can控制器的波特率。

### 6.2.5 Can_SetControllerMode
- **服务名称**: Can_SetControllerMode
- **语法**: Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x03
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,要切换运行状态的控制器ID。Transition，要切换到的运行状态
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 此服务将切换指定Can控制器的运行状态。

### 6.2.6 Can_DisableControllerInterrupts
- **服务名称**: Can_DisableControllerInterrupts
- **语法**: void Can_DisableControllerInterrupts(uint8 Controller)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x04
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,要关闭中断的控制器ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此服务将关闭该控制器的所有中断。

### 6.2.7 Can_EnableControllerInterrupts
- **服务名称**: Can_EnableControllerInterrupts
- **语法**: void Can_EnableControllerInterrupts(uint8 Controller)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x05
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,要开启中断的控制器ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此服务将使能该控制器的所有中断。

### 6.2.8 Can_CheckWakeup
- **服务名称**: Can_CheckWakeup
- **语法**: Std_ReturnType Can_CheckWakeup(uint8 Controller)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x0B
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: 无
- **返回值**: 无
- **描述**: 此服务将该控制器是否产生了唤醒事件。

### 6.2.9 Can_GetControllerErrorState
- **服务名称**: Can_GetControllerErrorState
- **语法**: Std_ReturnType Can_GetControllerErrorState(uint8 Controller, Can_ErrorStateType *ErrorStatePtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x11
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: ErrorStatePtr，输出的错误状态
- **返回值**: Std_ReturnType
- **描述**: 此服务可以获取该控制器的错误状态。

### 6.2.10 Can_GetControllerMode
- **服务名称**: Can_GetControllerMode
- **语法**: Std_ReturnType Can_GetControllerMode(uint8 Controller, Can_ControllerStateType *ControllerModePtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x12
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: ControllerModePtr，输出当前的运行模式
- **返回值**: Std_ReturnType
- **描述**: 此服务可以获取该控制器当前的运行模式。

### 6.2.11 Can_GetControllerRxErrorCounter
- **服务名称**: Can_GetControllerRxErrorCounter
- **语法**: Std_ReturnType Can_GetControllerRxErrorCounter(uint8 Controller, uint8* RxErrorCounterPtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x30
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: RxErrorCounterPtr，输出当前接收错误计数器值
- **返回值**: Std_ReturnType
- **描述**: 此服务可以获取该控制器当前的接收错误计数器值

### 6.2.12 Can_GetControllerTxErrorCounter
- **服务名称**: Can_GetControllerTxErrorCounter
- **语法**: Std_ReturnType Can_GetControllerTxErrorCounter(uint8 Controller, uint8* TxErrorCounterPtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x31
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: TxErrorCounterPtr，输出当前发送错误计数器值
- **返回值**: Std_ReturnType
- **描述**: 此服务可以获取该控制器当前的发送错误计数器值

### 6.2.13 Can_GetCurrentTime
- **服务名称**: Can_GetCurrentTime
- **语法**: Std_ReturnType Can_GetCurrentTime(uint8 Controller, Can_TimeStampType* timeStampPtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x32
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller,控制器ID
- **参数(输出)**: timeStampPtr，输出当前时间戳计数器值
- **返回值**: Std_ReturnType
- **描述**: 此服务可以获取该控制器当前的时间戳

### 6.2.14 Can_EnableEgressTimeStamp
- **服务名称**: Can_EnableEgressTimeStamp
- **语法**: void Can_EnableEgressTimeStamp(Can_HwHandleType Hth)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x33
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Hth,发送报文的配置索引
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 此服务可以使能指定Hth的发送时间戳计数（注意：目前仅实现了该接口，无对应硬件功能）

### 6.2.15 Can_GetEgressTimeStamp
- **服务名称**: Can_GetEgressTimeStamp
- **语法**: Std_ReturnType Can_GetEgressTimeStamp(PduIdType TxPduId, Can_HwHandleType Hth, Can_TimeStampType* timeStampPtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x34
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: TxPduId，要获取时间戳的PduID。Hth,发送报文的配置索引
- **参数(输出)**: timeStampPtr，输出当前时间戳计数器值
- **返回值**: Std_ReturnType
- **描述**: 此服务可以获取指定TxPduId的发送时间戳计数（注意：目前仅实现了该接口，无对应硬件功能）

### 6.2.16 Can_GetIngressTimeStamp
- **服务名称**: Can_GetIngressTimeStamp
- **语法**: Std_ReturnType Can_GetIngressTimeStamp(Can_HwHandleType Hrh, Can_TimeStampType* timeStampPtr)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x35
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Hrh,接收报文的配置索引
- **参数(输出)**: timeStampPtr，输出当前时间戳计数器值
- **返回值**: Std_ReturnType
- **描述**: 此服务可以获取指定Hrh的接收时间戳计数（注意：目前仅实现了该接口，无对应硬件功能）

### 6.2.17 Can_Write
- **服务名称**: Can_Write
- **语法**: Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x06
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Hth,发送报文的配置索引。PduInfo，要发送的报文信息。
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 此服务一般由CanIf层调用，发送一条报文到CAN总线

### 6.2.18 Can_MainFunction_Write
- **服务名称**: Can_MainFunction_Write
- **语法**: void Can_MainFunction_Write(void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x01
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 当CAN_TX_PROCESSING设置为POLLING，此服务用于执行Polling状态下的发送确认通知

### 6.2.19 Can_MainFunction_Read
- **服务名称**: Can_MainFunction_Read
- **语法**: void Can_MainFunction_Read(void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x08
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 当CAN_RX_PROCESSING设置为POLLING，此服务用于执行Polling状态下的接收指示通知

### 6.2.20 Can_MainFunction_BusOff
- **服务名称**: Can_MainFunction_BusOff
- **语法**: void Can_MainFunction_BusOff(void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x09
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 当CAN_BOPOLL_SUPPORTED设置为POLLING，此服务用于执行Polling状态下的Bus off的处理以及通知到CanIf层

### 6.2.21 Can_MainFunction_Wakeup
- **服务名称**: Can_MainFunction_Wakeup
- **语法**: void Can_MainFunction_Wakeup(void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x0A
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 当CAN_WUPOLL_SUPPORTED设置为POLLING，此服务用于执行Polling状态下的Wakeup事件的处理以及通知到EcuM层

### 6.2.22 Can_MainFunction_Mode
- **服务名称**: Can_MainFunction_Mode
- **语法**: void Can_MainFunction_Mode(void)
- **来源**: 此API由AUTOSAR定义。
- **服务ID**: 0x0C
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: 无
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 当CAN_MDPOLL_SUPPORTED设置为POLLING，此服务用于执行Polling状态下的模式切换以及通知

> 以下接口为厂家自定义的扩展接口

### 6.2.23 FullCan_SetControllerToWakeupMode
- **服务名称**: FullCan_SetControllerToWakeupMode
- **语法**: Std_ReturnType FullCan_SetControllerToWakeupMode(uint32 Controller，boolean CanifNotificationRequired)
- **来源**: 此API由厂商定义。
- **服务ID**: 无
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Controller，要控制器的Can控制器。CanifNotificationRequired，切换成功后是否通知到CanIf层
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 此服务将触发指定Can控制器到唤醒模式

### 6.2.24 Can_AbortHTH
- **服务名称**: Can_AbortHTH
- **语法**: Std_ReturnType Can_AbortHTH(Can_HwHandleType Hth)
- **来源**: 此API由厂商定义。
- **服务ID**: 无
- **同步/异步**: 同步
- **可重入**: 非可重入
- **参数(输入)**: Hth,发送报文的配置索引
- **参数(输出)**: 无
- **返回值**: Std_ReturnType
- **描述**: 此服务将取消指定Hth报文的发送。
                                                 
---
## 6.3 中断处理
中断服务程序在Can Driver中用于通知、报告错误事件。

### 6.3.1 Can_Isr_Mb

- **服务名称**：Can_Isr_Mb
- **语法**：`void Can_Isr_Mb (uint32 Controller)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：`Controller` - Can控制器ID
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 判断是否使用中断处理发送、接收事件
  - 判断是否存在发送事件，调用发送确认通知
  - 判断是否存在接收事件，调用报文读取函数
- **警告**：无
- **配置**：若要使用中断发送事件，则CAN_TXINT_SUPPORTED应配置为STD_ON，并且Can_ConfigPredefined->CanControllerSets->DescriptorPtr->PollingOptions需要附加CAN_TXINT_EN_U32掩码。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有3个SRN（服务请求节点）用于服务Can通道中断请求。
- 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保在Irq_Cfg.h中相应的中断源被启用。

### 6.3.2 Can_Isr_Err

- **服务名称**：Can_Isr_Err
- **语法**：`void Can_Isr_Err (uint32 Controller)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：`Controller` - Can控制器ID
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 判断该控制器是否产生错误事件
  - 调用错误通知函数
- **警告**：无
- **配置**：若要使用错误处理中断，则CAN_ERROR_NOTIFICATION应配置为STD_ON，并且Can_ConfigPredefined->CanControllerSets->DescriptorPtr->PollingOptions需要附加CAN_ERNTY_EN_U32掩码。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有3个SRN（服务请求节点）用于服务Can通道中断请求。
- 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保在Irq_Cfg.h中相应的中断源被启用。

### 6.3.3 Can_Isr_Off

- **服务名称**：Can_Isr_Off
- **语法**：`void Can_Isr_Off (uint32 Controller)`
- **服务ID**：无
- **同步/异步**：同步
- **可重入性**：可重入
- **参数（输入）**：`Controller` - Can控制器ID
- **参数（输出）**：无
- **返回值**：无
- **描述**：ISR执行以下操作：
  - 判断是否产生了总线关闭事件
  - 切换控制器状态到STOP模式
  - 根据选项决定是否调用总线关闭恢复程序
  - 根据选项决定是否调用总线关闭通知函数
- **警告**：无
- **配置**：若要使用中断处理总线关闭事件，则CAN_BOINT_SUPPORTED应配置为STD_ON，并且Can_ConfigPredefined->CanControllerSets->DescriptorPtr->PollingOptions需要附加CAN_BOINT_EN_U32掩码。
- **DET**：无
- **DEM**：无
- **实施注释**：无
- **I/O模式**：此API可以在CPU处于用户-1模式或超级管理员模式时调用。
- **通用注释**：有3个SRN（服务请求节点）用于服务Can通道中断请求。
  - 每应在提供的Irq_LCfg.c中提供有效的优先级，并确保在Irq_Cfg.h中相应的中断源被启用。

> 下表显示了SRN编号和相关的通道资源。

#### 服务请求节点 - Can硬件资源

| 硬件资源 | SRN编号                  |
| -------- | ------------------------ |
| CANFD6   | CANFD6_UNIFIED_INTERRUPT |
| CANFD7   | CANFD7_UNIFIED_INTERRUPT |
| CANFD8   | CANFD8_UNIFIED_INTERRUPT |
| CANFD9   | CANFD9_UNIFIED_INTERRUPT |


-----

# 第7章 数据描述

## 7.1 全局数据描述
以下是Can Driver中使用的所有全局和静态变量的列表。

#### 全局数据描述

| 参数                   | 类型/范围                | 描述                         |
| ---------------------- | ------------------------ | ---------------------------- |
| Can_CurrentConfigPtr   | Can_ConfigType           | Can Driver的配置结构体指针   |
| Can_ControllerStatuses | Can_ControllerStatusType | 存储驱动器当前模式状态的变量 |
| Can_DriverStatus       | Can_StatusType           | 存储Can Driver的初始化状态   |


-------
# 第8章 错误分类

## 8.1 错误代码和描述
以下是Can Driver中定义的错误代码及其描述。

#### 错误分类

| 错误代码                 | 错误描述           | 值（十六进制） |
| ------------------------ | ------------------ | -------------- |
| CAN_E_NO_ERROR           | 无错误             | 0x00U          |
| CAN_E_PARAM_POINTER      | 参数指针错误       | 0x01U          |
| CAN_E_PARAM_HANDLE       | 参数索引值错误     | 0x02U          |
| CAN_E_PARAM_DATA_LENGTH  | 参数数据长度错误   | 0x03U          |
| CAN_E_PARAM_CONTROLLER   | 参数的控制器ID错误 | 0x04U          |
| CAN_E_UNINIT             | 驱动未初始化       | 0x05U          |
| CAN_E_TRANSITION         | 传输错误           | 0x06U          |
| CAN_E_PARAM_BAUDRATE     | 波特率配置错误     | 0x07U          |
| CAN_E_INIT_FAILED        | 初始化失败         | 0x09U          |
| CAN_E_PARAM_LPDU         | PDU参数错误        | 0x0AU          |
| CAN_E_INVALID_CONTROLLER | 控制器初始化错误   | 0x0BU          |
| CAN_E_PARAM_HOH          | HOH值错误          | 0x0CU          |
| CAN_E_DATALOST           | 数据丢失           | 0x0DU          |


-----
# 第9章 示例用法
本章描述了如何配置Can驱动器以及如何在应用程序中使用Can驱动器提供的不同的API。

## 9.1 集成说明

> 添加以下文件到工程
```
   ComStack_Cfg.h
   ComStack_Types.h
   Can_GeneralTypes.h
   Can_Types.h
   Can.h      
   Can.c      
   Canfd_Im.h
   Canfd_Im.c
   Can_Cfg.h  
   Can_Cfg.c  
   Can_LCfg.h
   Can_LCfg.c
```

## 9.2 驱动配置  
   按照以下指南以及实际应用场景正确配置Can驱动器：
- MCU驱动器：配置系统时钟。
- 中断优先级初始化：在中断请求（IRQ）驱动模块中配置中断优先级。
- 选择所需的API配置开关，唤醒能力，报文定义，Can控制器配置等。


```
Can_Cfg.h 文件示例配置
   
#define CAN_PRECOMPILE_SUPPORT (STD_ON)
#define CAN_DEV_ERROR_DETECT (STD_OFF)
#define CAN_MAINFUNCTION_MODE_PERIOD (STD_ON)
#define CAN_MULTIPLEXED_TRANSMISSION (STD_OFF)
#define CAN_DEINIT_CONTROLLER_API (STD_ON)
#define CAN_SET_BAUDRATE_API (STD_OFF)
#define CAN_VERSION_INFO_API (STD_ON)
#define CAN_ENABLE_WAKEUP_SUPPORT (STD_OFF)
#define CAN_TRIGGER_TRANSMIT_EN (STD_OFF)
#define CAN_API_ENABLE_ABORT_HTH (STD_ON)
#define CAN_LPDU_NOTIFICATION_ENABLE (STD_OFF)
#define CAN_TX_NOTIFICATION (STD_ON)
#define CAN_RX_INDICATION (STD_ON)
#define CAN_ERROR_NOTIFICATION (STD_ON)
#define CAN_OFF_NOTIFICATION (STD_ON)
#define CAN_WAKEUP_NOTIFICATION (STD_OFF)
#define CAN_BUSOFF_HARDWARE_RECOVERY (STD_OFF)
#define CAN_GLOBAL_TIME_SUPPORT (STD_OFF)
#define CAN_CANFD_MODE (STD_ON)
#define CAN_HARDWARE_FILTER (STD_ON)
#define CAN_MASK_IF_API (STD_ON)

#define CAN_NACKERRINT_SUPPORTED (STD_ON)
#define CAN_SOFERRINT_SUPPORTED  (STD_ON)

#define CAN_CFG_MAX_CONTROLLER (3)
#define CAN_CFG_MAX_MAILBOX_NUMBER (51U)

#define CAN_MAX_8MAILBOX_NUMBER  (51U)
#define CAN_MAX_16MAILBOX_NUMBER (36U)
#define CAN_MAX_32MAILBOX_NUMBER (23U)
#define CAN_MAX_64MAILBOX_NUMBER (13U)

#define CANDRIVER_INTERNAL_TRACE_LOGGER (STD_OFF)

#define CAN_0_CONTROLLER_ACTIVATION (STD_ON)
#define CAN_1_CONTROLLER_ACTIVATION (STD_ON)
#define CAN_2_CONTROLLER_ACTIVATION (STD_ON)

#define CAN_MAINFUNCTION_MULTIPLE_WRITE (STD_ON)
#define CAN_MAINFUNCTION_MULTIPLE_READ  (STD_ON)
```

```
Can_LCfg.c文件示例配置

static CONST(Can_ArbitrateBDRConfigType,CAN_CONST) Can_ControllerCanBDRConfig[CAN_CFG_MAX_CONTROLLER][2U] = {
  [0U] =
    {
      {
        .BaudRateConfigID = 0U,
        .PreScale = 1U,
        .TSeg1 = 11U,
        .TSeg2 = 2U,
        .Sjw = 1U,
        .SampleTimes = CAN_SAMPLE_ONCE,
      },
      {
        .BaudRateConfigID = 1U,
        .PreScale = 0U,
        .TSeg1 = 11U,
        .TSeg2 = 2U,
        .Sjw = 1U,
        .SampleTimes = CAN_SAMPLE_ONCE,
      },
    },
  [1U] =
    {
      {
        .BaudRateConfigID = 0U,
        .PreScale = 1U,
        .TSeg1 = 11U,
        .TSeg2 = 2U,
        .Sjw = 1U,
        .SampleTimes = CAN_SAMPLE_ONCE,
      },
      {
        .BaudRateConfigID = 1U,
        .PreScale = 0U,
        .TSeg1 = 11U,
        .TSeg2 = 2U,
        .Sjw = 1U,
        .SampleTimes = CAN_SAMPLE_ONCE,
      },
    },
  [2U] = {
    {
      .BaudRateConfigID = 0U,
      .PreScale = 1U,
      .TSeg1 = 11U,
      .TSeg2 = 2U,
      .Sjw = 1U,
      .SampleTimes = CAN_SAMPLE_ONCE,
    },
    {
      .BaudRateConfigID = 1U,
      .PreScale = 0U,
      .TSeg1 = 11U,
      .TSeg2 = 2U,
      .Sjw = 1U,
      .SampleTimes = CAN_SAMPLE_ONCE,
    },
  }};


static CONST(Can_FdDataBDRConfigType,CAN_CONST) Can_ControllerFdBDRConfig[CAN_CFG_MAX_CONTROLLER][2U] = {
  [0U] =
    {[0U] =
       {
         .BrsPrescale = 0U,
         .HSjw = 1U,
         .HtSeg1 = 5U,
         .HtSeg2 = 0U,
       },
     [1U] =
       {
         .BrsPrescale = 0U,
         .HSjw = 1U,
         .HtSeg1 = 1U,
         .HtSeg2 = 0U,
       }},
  [1U] =
    {[0U] =
       {
         .BrsPrescale = 0U,
         .HSjw = 1U,
         .HtSeg1 = 5U,
         .HtSeg2 = 0U,
       },
     [1U] =
       {
         .BrsPrescale = 0U,
         .HSjw = 1U,
         .HtSeg1 = 1U,
         .HtSeg2 = 0U,
       }},
  [2U] =
    {[0U] =
       {
         .BrsPrescale = 0U,
         .HSjw = 1U,
         .HtSeg1 = 5U,
         .HtSeg2 = 0U,
       },
     [1U] = {
       .BrsPrescale = 0U,
       .HSjw = 1U,
       .HtSeg1 = 1U,
       .HtSeg2 = 0U,
     }}};

 

#if (CAN_CANFD_MODE == STD_ON)
 
static CONST(Can_FDConfigType, CAN_CONST) Can_ControllerFdConfig[CAN_CFG_MAX_CONTROLLER] = {
  [0U] =
    {
      
      .CanFdEnable = TRUE,
      .CanFdTxBitRateSwitch = TRUE,
      .CanFdFrameMode = CAN_FD_ISOMODE,
      .CanFdDataBDRConfigPtr = &Can_ControllerFdBDRConfig[0U][0U],
    },
  [1U] =
    {
      
      .CanFdEnable = TRUE,
      .CanFdTxBitRateSwitch = TRUE,
      .CanFdFrameMode = CAN_FD_ISOMODE,
      .CanFdDataBDRConfigPtr = &Can_ControllerFdBDRConfig[1U][0U],
    },
  [2U] =
    {
      
      .CanFdEnable = TRUE,
      .CanFdTxBitRateSwitch = TRUE,
      .CanFdFrameMode = CAN_FD_ISOMODE,
      .CanFdDataBDRConfigPtr = &Can_ControllerFdBDRConfig[2U][0U],
    },
};

 
static CONST(Can_HRHRangeType, CAN_CONST) Can_ControllerHRHRangeConfig[CAN_CFG_MAX_CONTROLLER] = {
  [0U] =
    {
      /** @brief HRH start index of HOH config */
      .StartHrh = 0U,
      /** @brief HRH end index of HOH config */
      .EndHrh = 8U,
    },
  [1U] =
    {
      /** @brief HRH start index of HOH config */
      .StartHrh = 8U,
      /** @brief HRH end index of HOH config */
      .EndHrh = 9U,
    },
  [2U] =
    {
      /** @brief HRH start index of HOH config */
      .StartHrh = 9U,
      /** @brief HRH end index of HOH config */
      .EndHrh = 10U,
    },
};


/**
 * @brief can controller HTH config
 * @details
 * StartHth + first HTH num == start HTH index in HOH Sets: CanHOHSets
 * EndHth + first HTH num end HTH index in HOH Sets: CanHOHSets
 */
static CONST(Can_HTHRangeType, CAN_CONST) Can_ControllerHTHRangeConfig[CAN_CFG_MAX_CONTROLLER] = {
  [0] =
    {
      /** @brief can controller 0 HTH start index of HOH config */
      .StartHth = 0U,
      /** @brief can controller 0 HTH end index of HOH config */
      .EndHth = 11U,
    },
  [1] =
    {
      /** @brief can controller 1 HTH start index of HOH config */
      .StartHth = 11U,
      /** @brief can controller 1 HTH end index of HOH config */
      .EndHth = 12U,
    },
  [2] =
    {
      /** @brief can controller 2 HTH start index of HOH config */
      .StartHth = 12U,
      /** @brief can controller 2 HTH end index of HOH config */
      .EndHth = 13U,
    },
};

 
static CONST(Can_HOHType, CAN_CONST) Can_ControllerHOHConfig[] = {
  /* HRH config */
  [0U] =
    {
      /** @brief receive or write */
      .HOHType = CAN_RECEIVE,
      /** @brief filter status */
      .bFilterEnable = TRUE,
      /** @brief Full-CAN or Basic-CAN */
      .HRHType.CanHandleType = CAN_TYPE_FULL,
      /** @brief receive frame Id */
      .HRHType.FullCan_HRH.Id = 0x193F31U,
      /** @brief receive frame type */
      .HRHType.FullCan_HRH.IdType = CAN_DATA_EXTENDED,
      /** @brief filter mask */
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      /** @brief mailbox start index */
      .StartMbIndex = 0U,
      /** @brief mailbox end index */
      .EndMbIndex = 1U,
      /** @brief api HOH index find controller */
      .CfgId = CONTROLLER_0,
      /** @brief Enables polling of this hardware object */
      .bPolling = FALSE,
      /** @brief Reference to CanMainFunctionPeriod */
      .MainfunctionId = 0U,
    },
  [1U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x193F41U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_EXTENDED,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 1U,
      .EndMbIndex                        = 2U,
      .CfgId                             = CONTROLLER_0,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [2U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x193F51U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_EXTENDED,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 2U,
      .EndMbIndex                        = 3U,
      .CfgId                             = CONTROLLER_0,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [3U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x193F61U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_EXTENDED,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 3U,
      .EndMbIndex                        = 4U,
      .CfgId                             = CONTROLLER_0,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [4U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x193F71U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_EXTENDED,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 4U,
      .EndMbIndex                        = 5U,
      .CfgId                             = CONTROLLER_0,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [5U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x7F0U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_STANDARD,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 5U,
      .EndMbIndex                        = 6U,
      .CfgId                             = CONTROLLER_0,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [6U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x7F1U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_STANDARD,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 6U,
      .EndMbIndex                        = 7U,
      .CfgId                             = CONTROLLER_0,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [7U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x125U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_STANDARD,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 7U,
      .EndMbIndex                        = 8U,
      .CfgId                             = CONTROLLER_0,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [8U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x124U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_STANDARD,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 0U,
      .EndMbIndex                        = 10U,
      .CfgId                             = CONTROLLER_1,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  [9U] =
    {
      .HOHType                           = CAN_RECEIVE,
      .bFilterEnable                     = TRUE,
      .HRHType.CanHandleType             = CAN_TYPE_FULL,
      .HRHType.FullCan_HRH.Id            = 0x123U,
      .HRHType.FullCan_HRH.IdType        = CAN_DATA_STANDARD,
      .HRHType.FullCan_HRH.CanFilterMask = 0x0U,
      .StartMbIndex                      = 0U,
      .EndMbIndex                        = 10U,
      .CfgId                             = CONTROLLER_2,
      .bPolling                          = FALSE,
      .MainfunctionId                    = 0U,
    },
  /* HTH config */
  [10U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 8U,
      .EndMbIndex   = 9U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [11U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 9U,
      .EndMbIndex   = 10U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [12U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 10U,
      .EndMbIndex   = 11U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [13U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 11U,
      .EndMbIndex   = 12U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [14U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 12U,
      .EndMbIndex   = 13U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [15U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 13U,
      .EndMbIndex   = 14U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [16U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 14U,
      .EndMbIndex   = 15U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [17U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 15U,
      .EndMbIndex   = 16U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [18U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 16U,
      .EndMbIndex   = 17U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [19U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 17U,
      .EndMbIndex   = 18U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [20U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 18U,
      .EndMbIndex   = 19U,
      .CfgId        = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [21U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 10U,
      .EndMbIndex   = 13U,
      .CfgId        = CONTROLLER_1,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
  [22U] =
    {
      .HOHType      = CAN_TRANSMIT,
      .StartMbIndex = 10U,
      .EndMbIndex   = 11U,
      .CfgId        = CONTROLLER_2,
#if (CAN_CANFD_MODE == STD_ON)
      .CanFdPaddingValue = 0xFFU,
#endif
    },
};

/**
 * @brief can controller config
 */
/*PRQA S  4424++*/
static CONST(Can_ControllerType, CAN_CONST) Can_ControllerConfig[CAN_CFG_MAX_CONTROLLER] = {
  /* Can 1 Config */
  [0U] =
    {
      /** @brief can id */
      .HardwareID = CAN_HW_CONTROLLER_CANFD8,
      /** @brief can work mode */
      .WorkMode = CAN_NORMAL_MODE,
#if (CAN_BUSOFF_HARDWARE_RECOVERY == STD_ON)
      /** @brief hardware recovery */
      .HBORecovery = STD_ON,
#endif
      /** @brief clock source */
      .ClockSource = CAN_CLOCKSOURCE_HFCLK,
#if (CAN_CANFD_MODE == STD_ON)
      /** @brief CanFd mail box size */
      .MailBoxBlockSize = CAN_PAYLOAD_8BYTE,
#endif
      /** @brief Interrupt config */
      .InterruptConfigPtr = NULL_PTR,
      /** @brief Arbitrate Segment Baudrate Config */
      .ArbitrateBDRArrayConfigPtr = &Can_BDRArrayConfig[0U],
#if (CAN_CANFD_MODE == STD_ON)
      /** @brief CanFd config */
      .CanFdConfigPtr = &Can_ControllerFdConfig[0U],
#endif
      /** @brief can controller information */
      .DescriptorPtr = &Can_ControllerDescriptor[0U],
    },
  /* Can 2 Config */
  [1U] =
    {
      /** @brief can id */
      .HardwareID = CAN_HW_CONTROLLER_CANFD7,
      /** @brief can work mode */
      .WorkMode = CAN_NORMAL_MODE,
#if (CAN_BUSOFF_HARDWARE_RECOVERY == STD_ON)
      /** @brief hardware recovery */
      .HBORecovery = STD_ON,
#endif
      /** @brief clock source */
      .ClockSource = CAN_CLOCKSOURCE_HFCLK,
#if (CAN_CANFD_MODE == STD_ON)
      /** @brief CanFd mail box size */
      .MailBoxBlockSize = CAN_PAYLOAD_8BYTE,
#endif
      /** @brief Interrupt config */
      .InterruptConfigPtr = NULL_PTR,
      /** @brief Arbitrate Segment Baudrate Config */
      .ArbitrateBDRArrayConfigPtr = &Can_BDRArrayConfig[1U],
#if (CAN_CANFD_MODE == STD_ON)
      /** @brief CanFd config */
      .CanFdConfigPtr = &Can_ControllerFdConfig[1U],
#endif
      /** @brief can controller information */
      .DescriptorPtr = &Can_ControllerDescriptor[1U],
    },
  /* Can 3 Config */
  [2U] =
    {
      /** @brief can id */
      .HardwareID = CAN_HW_CONTROLLER_CANFD6,
      /** @brief can work mode */
      .WorkMode = CAN_NORMAL_MODE,
#if (CAN_BUSOFF_HARDWARE_RECOVERY == STD_ON)
      /** @brief hardware recovery */
      .HBORecovery = STD_ON,
#endif
      /** @brief clock source */
      .ClockSource = CAN_CLOCKSOURCE_HFCLK,
#if (CAN_CANFD_MODE == STD_ON)
      /** @brief CanFd mail box size */
      .MailBoxBlockSize = CAN_PAYLOAD_8BYTE,
#endif
      /** @brief Interrupt config */
      .InterruptConfigPtr = NULL_PTR,
      /** @brief Arbitrate Segment Baudrate Config */
      .ArbitrateBDRArrayConfigPtr = &Can_BDRArrayConfig[2U],
#if (CAN_CANFD_MODE == STD_ON)
      /** @brief CanFd config */
      .CanFdConfigPtr = &Can_ControllerFdConfig[2U],
#endif
      /** @brief can controller information */
      .DescriptorPtr = &Can_ControllerDescriptor[2U],
    },
};
```
## 9.3 驱动初始化

```
    /* 包含Can驱动接口头文件 */
    #include "Can.h"
    
    /* 初始化Can驱动 */
    Can_Init(&Can_ConfigPredefined);
    /* 反初始化Can驱动 */
    Can_DeInit();
```
## 9.4 API使用

```
    /* 包含Can驱动接口头文件 */
    #include "Can.h"
    
    Can_PduType msg1;
    uint8 data[8]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
    Std_VersionInfoType canDriverVersionInfo;
    Can_ControllerStateType canControllerState；
    Can_ErrorStateType canErrorState；
    uint8 rxErrorCounter；
    uint8 txErrorCounter；
    Can_TimeStampType canTimeStamp;
    
    /* 切换Can控制器工作状态 */
    Can_SetControllerMode(CONTROLLER_0,CAN_CS_STARTED);
    
    /* 定义Can报文 */
    msg1.id=0x123;
    msg1.swPduHandle=0;
    msg1.length=8;
    msg1.sdu=data;
    /* 发送Can报文 */
    Can_Write(10,&msg1);
    
    /* 取消发送Hth 10的报文 */
    Can_AbortHTH(10);
    /* 获取Can驱动软件版本信息 */
    Can_GetVersionInfo(&canDriverVersionInfo);
    /* 切换控制器0的波特率到Can_ControllerCanBDRConfig[0][1] */
    Can_SetBaudrate(CONTROLLER_0,1);
    /* 关闭控制器0的中断响应 */
    Can_DisableControllerInterrupts(CONTROLLER_0);
    /* 开启控制器0的中断响应 */
    Can_EnableControllerInterrupts(CONTROLLER_0);
    /* 检查唤醒事件 */
    Can_CheckWakeup(CONTROLLER_0);
    /* 获取当前控制器状态到canControllerState中 */
    Can_GetControllerMode(CONTROLLER_0,&canControllerState);
    /* 获取当前控制器错误状态到canErrorState中 */
    Can_GetControllerErrorState(CONTROLLER_0,&canErrorState);
    /* 获取当前控制器接收错误计数器的值到rxErrorCounterPtr中 */
    Can_GetControllerRxErrorCounter(CONTROLLER_0,&rxErrorCounter);
    /* 获取当前控制器发送错误计数器的值到txErrorCounterPtr中 */
    Can_GetControllerRxErrorCounter(CONTROLLER_0,&txErrorCounter);
    
    /* Polling 循环调度 */
    Can_MainFunction_Write();
    Can_MainFunction_Read();
    Can_MainFunction_BusOff();
    Can_MainFunction_Wakeup();
    Can_MainFunction_Mode();
    
    /* 获取当前控制器时间 */
    Can_GetCurrentTime(CONTROLLER_0,&canTimeStamp);
    /* 使能发送报文的时间戳 */
    Can_EnableEgressTimeStamp(10);
    /* 获取发送报文的时间戳 */
    Can_GetEgressTimeStamp(0,10,&canTimeStamp);
    /* 获取接收报文的时间戳 */
    Can_GetIngressTimeStamp(0,&canTimeStamp);
    
```

# 第10章 限制和假设

## 10.1 假设和与软件规格的偏差

### 假设

- 中断的全局配置（中断仲裁周期、优先级设置）将由用户处理
- 每个Can通道的Rx、Tx的端口配置由用户初始化
- 单片机时钟设置的多重性配置为1-*
- KF32A1x8支持的最大频率为120MHz

### 考虑的Bugzilla

- 需求 SWS_Can_00504、SWS_Can_00505、SWS_Can_00506 由于硬件不支持未实现。


## 10.2 限制

- Dem功能暂不支持
- Memmap暂未实现
- SchM暂未实现
- 由于硬件限制仅可使用独立Mailbox的方式接收报文，不能使用FIFO的方式。
- Can驱动程序只支持Can_MainFunction_Write()的API名称处理发送的MBs，未实现Can_MainFunction_Write_0...Can_MainFunction_Write_x
- Can驱动程序只支持Can_MainFunction_Read()的API名称处理发送的MBs，未实现Can_MainFunction_Read_0...Can_MainFunction_Read_x

 


