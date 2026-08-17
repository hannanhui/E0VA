# Changelog

**158SF Mcal** 基于*Autosar Mcal R22-11* 适用于:
- KF32A158SF

----
## Version 1.0.0

### Features
- 无
  
### Changed
- CAN
 - 增加CAN可配2个以上硬件单元级联使用
 - 增加CAN可配置单个硬件单元配置不同邮箱大小功能
 - 通知CANIF层Controller状态，修改为R22版本要求值

- MCU
 - 禁用HSE迟滞功能与PLL锁定检测
 - 增加校准信息配置

- I2C 
 - 兼容设置寄存器长度为0特殊使用场景

- DIO
  - 修改Dio_WriteChannel实现，优化针对不同任务同时操作相同PORT下不同的PIN的读改写时序问题

- FLS
  - 增加fls底层操作状态返回
  - FLS扩展函数文件("Fls_Ex"),DFLASH和PFLASH操作分成2个函数操作

- UART
  - 初始化默认关闭接收

- DET报错
  - 修复模块DET检测顺序、关闭DET功能默认值 

- ICU
  - 增加PORT类型测试计数和中断检测 
  - 边沿检测类型对齐MCAL标准，上升沿、下降沿和双边沿
  
### Fixed
- ADC
 - 修复同一个硬件多个Group同时转换进队列，出队列后未更新Group信息问题
  
- PWM
  - EPWM模块配置通道极性LOW开始时,AB通道配置错误问题

- ICU
  - 当计数已运行时间超过0xFFFFFFFF情况时，通道信息未重置0

- FLS
  - 修复擦除函数返回值未初始化问题  

- SPI 
  - Level0模式，同步传输入参RXBUFFER为空指针，也需要把SPI BUFFER数据读走 
### Deprecated
- 无

----
## Version 0.1.0
发布适用于158SF芯片特性的版本

### Features
- 无

### Changed
- 无

### Fixed
- 无
  
### Deprecated
- 无