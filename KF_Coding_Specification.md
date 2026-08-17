# <p style="text-align:center;">ChipON 编码规范</p>
<div style="text-align:center; margin-top:30%">
<div style="display:inline-block">
<p style="text-align:left">版本:0.3</p>
<p style="text-align:left">作者:翟宇</p>
<p style="text-align:left">日期:2024.04.18</p>
</div>
</div>
<!-- pagebreak -->

<h2>目录</h2> 

- [软件开发宣言](#软件开发宣言)
- [一.推荐工具](#一推荐工具)
- [二.注释规范](#二注释规范)
- [三.命名规范](#三命名规范)
- [四.编码规范](#四编码规范)
- [五.测试规范](#五测试规范)
- [六.参考文档](#六参考文档)

<!-- pagebreak -->

| 版本  |   日期    | 作者  | 描述  |
| :---: | :-------: | :---: | :---: |
|  0.1  | 2023/09/28 | 翟宇  | 初版  |
|  0.2  | 2024/02/21 | 翟宇  | 加入LLD的编码规范  |
|  0.3  | 2024/04/18 | 翟宇  | 内容布局调整  |

<!-- pagebreak -->

## 软件开发宣言
软件接口 (API) 的设计, 内部实现, 数据结构的规划, 应遵循以下设计原则或特征：
- 可理解性 (comprehensibility)
>    接口的设计应当直观，避免复杂的结构和不必要的抽象。每个接口的功能和用法应该清晰明了，使得开发者能快速理解其目的和工作方式
- 一致性 (consistency)
- 简单性 (simplicity)
- 可验证性 (verifiability)
- 模块化 (modularity)
- 抽象化 (abstraction)
- 封装化 (encapsulation)
- 可维护性 (maintainability)
- **不得假设 (no-assumptions)**

## 一.推荐工具
- 开发工具  
    推荐使用最新版本的vscode作为统一的代码编辑工具。方便自动补全、颜色高亮、格式对齐、以及定义查询。可以有效的避免当前IDE编辑中容易出现的变量名写错, 函数引用忘记声明等操作失误。推荐安装以下几个vscode插件:
    - C/C++
    - Todo Tree
    - Doxygen Documentation Generator
    - Markdown Preview Enhanced
    - Markdown All in One
    - Code Spell Checker
    - TONGYI Lingma

- git  
    借助git版本控制工具, 可以方便追溯开发过程。建议开发人员创建个人git仓库, 从服务器分支fork后进行开发。合并前提交pull request并进行不少于三人的内容评审。一致同意后合并入主仓库。Git的本地提交推荐细粒化, 独立性, 一次更改提交只限定在有限的逻辑关联的范围内, 便于文件的更改回溯查询

- 编码字符集   
    - **所有文件编码格式均必须使用UTF-8格式**
    - 代码编辑器中的字体推荐使用等宽字体, 避免混淆`1`和`l`, `2`和`Z`, `5`和`S`, `0`和`O` , `n`和`h`等等。如“Titillium Web”, “Open Sans”等免费可商用的字体

- .clang-format
   - **使用统一的格式工具, 避免协同开放时因格式导致的大量合并冲突**
   - 建议使能vscode的`format on save`设置
  
-  Code Spell Checker
   -  **用于检查代码段的语法拼写等错误**
   -  工程根目录下应使用`cspell.json`配置文件
- TONGYI Lingma  
    - 提供AI的编码建议


<!-- pagebreak -->

## 二.注释规范  
- 源文件和头文件的注释方式参考Doxygen注释规范中的`@`格式
    ```c
        /**
          * @brief Get Current Item Count base on itemsize
          * 
          * @param queue pointer to Queue Struct
          * @return size_t Total num of Item in Queue
          * @retval size_t Total num of Item in Queue
          */
    ```
- 行注释建议使用，行注释建议放于注释对象的上方，减少行的长度
    ```c
        /** ...... */ 
        /*…... */
    ```
- Doxygen常用注释命令，具体可查阅[Doxygen命令手册](https://www.doxygen.nl/manual/commands.html)
    ```
        @warning    注意事项
        @bug    缺陷
        @see    引用注释及链接
        @pre    代码项的前提条件
        @post   代码项之后的使用条件
        @brief  概要信息
        @detail 详细描述
        @param  表示参数类型及意义
        @return 返回类型及意义
        @retval 返回值的意义
        @implements 实现的需求编号
    ```
- 源程序注释内容需简洁，易懂，无歧义
- **注释中不得出现源码** (MISRA C 2004 Rule 2.4)，建议使用条件编译#if 0来注释掉无用的代码
- 注释不允许出现嵌套 (MISRA C 2004 Rule 2.3)
- 注释应尽量放在对应代码的上方
- 所有enum和struct类型中的变量均需要在上方提供注释说明，以及位置偏移
- 对于switch中的case语句，如果需要处理连续的case选择，则必须在case之间加上明确的注释
- 避免在表达式中间，或者宏定义换行中插入注释
- 变量及函数的注释在头文件及源文件中都必须体现出来，并且内容和格式保持一致。这样做在源码不便于交付时仍可为用户提供注释帮助
- **所有函数的声明和定义前都必须要有函数注释**
- **所有判断语句中，条件判断的分支需要写出注释**
- **Mcal**代码中应注释出详细的SWS需求编号，用于追踪需求实现
- 源文件末尾使用`/* EOF */`，并在下方预留一个空行


<!-- pagebreak -->

## 三.命名规范  
- 规范中使用到的宏，枚举定义方式如下，宏和枚举的内容均使用大写，前缀为模块简称
    ```c
    // <MODULE>_E_<SN>
    #define GPT_E_BUSY          ((uint8)0x0BU)
    // <MODULE>_<SN>
    #define GPT_INIT_ID                 ((uint8)0x01U)
    // <MODULE>_<CONTENT1>_<CONTENT2>...
    typedef enum
    {
        GPT_MODE_NORMAL,
        GPT_MODE_SLEEP
    } Gpt_ModeType;
    ```
- **LLD库/Hw模块**中的struct，enum，union，使用`Type`作为后缀，便于和Drv中的相同类型做隔离区别
    ```c
    typedef enum
    {
        /* content */
    } exampleType;
    ```
- **LLD库/Drv和Reg**中的结构体，枚举，联合体的定义以`_t`作为后缀
    ```c
    typedef struct 
    {
        /* content */
    } example_struct_t;

    typedef enum 
    {
        /* content */
    } example_enum_t;

    typedef union 
    {
        /* content */
    } example_union_t;
    ```
- **LLD库**使用Set*xxx*Enabled来处理Enable和Disable的寄存器设置函数, 如
    ```c
    Adc_LL_SetEnabled(ADCx, true); //代替Adc_LL_Enable(ADCx)
    Adc_LL_SetEnabled(ADCx, false); //代替Adc_LL_Disable(ADCx)
    ```
- **LLD库**中共享使用的静态变量，全局变量前加入`kv`前缀, 共享使用的指针变量前加入`kp`前缀
- **HLI库**函数指针的命名方式后缀统一为`FcnType`, 如
    ```c
    typedef void (*HLI_Usart_ReceiveIdleFcnType)(void);
    ```
- 为避免中断处理函数被误用，不得在头文件中对中断处理函数做声明。且中断处理函数应位于源文件的最尾端
- 宏定义应全部使用大写
- 标识符命名需清晰明了，尽量使用完整的或常用的缩写，避免误解
- 用正确的反义词组命名具有互斥意义的变量或表示动作的函数
    ```
    add/remove|delete  begin/end   create/destroy  insert/delete   first/last  get/set  inc/dec  push/pop    
    lock/unlock open/close  min/max next/prev   start/stop  src/des send/receive   init/deinit  read/write
    ```
- 应尽量避免局部变量命名与全局变量命名重复
- 命名长度不超过31个字符 (MISRA C)
- typedef，struct或union的tag名称必须保持唯一，不能重复使用

- 位字段只能定义为`unsigned int`。(MISRA C 2004 Rule 6.4) 使用其他类型时需进行测试并注释，因为该行为与具体编译器有关，C标准未定义。芯片驱动不建议使用`signed int`此类有符号整型
- **函数应具有原型声明，且原型应在函数定义和调用时可见。函数原型的使用使编译器能够检查函数定义和调用的完整性。(MISRA C 2004 Rule 8.1)**
- 中断处理函数中存在共享可能的变量，或是访问外设寄存器的指针，以及局部循环变量。需要添加`volatile`限定符
- 所有编程相关的命名严禁使用拼音与英文混合的方式，更不允许直接使用中文拼音的方式
- 尽可能减少头文件中对其他头文件的引用，可在源文件中引入需要的头文件。降低头文件之间的耦合度
- `#include`语句中不得出现绝对路径或相对路径的文件引用
- 如果仅操作一个标志位，则建议使用一个bool参数做形参，用于该位的赋值操作(0/1)

- **LLD库/Drv**函数命名应由**模块名+LL+具体动作**三部分组成，之间用下划线间隔
    ```c
    void Adc_LL_SetClockSource(Adc_RegisterMap_t* const Adcx, Adc_Source_t ClockSource)
    ```
- **LLD库/Hw**函数命名应由**模块名+Hw+具体动作**三部分组成，之间用下划线间隔
    ```c
    void Adc_Hw_Enable(Adc_RegisterMap_t* Adcx, bool Enabled);
    ```
- 模块名称首字母大写，具体动作若由多个词汇组成，则其每个单词首字母也应采用大写字母形式
- 示例如下:
   ```c
    /* 标准库 */
    Spi_Init() -> Spi_Hw_Init() - > {Spi_LL_SetDataWidth(), Spi_LL_SetBaudRate().....}
    ```
- **LLD库**在底层驱动代码中应使用更具有表意的动作原语，如Set, Get, Config, Write, Read, Toggle, Enable, Select等

<!-- pagebreak -->

## 四.编码规范

- 代码质量保证的原则  
    > 1. 正确性, 代码要实现设计需要的功能
    > 2. 稳定性, 代码稳定可靠, 逻辑清晰
    > 3. 可测试性, 代码具有良好的可测试性, 返回的路径清晰
    > 4. 规范性, 代码书写风格优秀, 代码格式整齐
- **函数的形参全部使用首字母大写的方式**
- **函数内部的局部变量全部使用首字母小写的方式**
- 排版。使用缩进风格编写, 缩进<text style="color:red">不得使用tab</text>, 应使用**4个空格**
- 使用clang-format工具保证格式统一
- 禁止一行内出现多条语句, 例如:  
    ```c
    init.m_Mode = GPIO_MODE_OUT;    init.m_OpenDrain = GPIO_POD_OD;
    ```

- if，for，do，while等需要语句块表达的，无论行数多少都必须带{}，大括号独占一行且无缩进
    ```c
    while(true)
    {
    }
    ```
- 应分别定义变量，不得在同一行内书写
    ```c
    int a, b, c;  //不容许这样的定义
    ```

- 头文件中需要增加编译开关防止被多次重复引用，宏定义格式参考如下示例，不得使用双下划线 (C标准默认的内置数据定义方式冲突) 
    ```c
    #ifndef ADC_HW_H
    #define ADC_HW_H
    /* code */
    #endif
    ```
-   使用括号来明确表达式的操作顺序，避免使用语言的默认优先级  
    ```c
    /* 建议 */
    word = (high << 8) | low;
    if ((a | b) && (c & d))
    {
    }
    /* 避免 */
    word = high << 8 | low;
    if (a | b && c & d)
    {
    }
    ```
- 避免使用技巧性很高，但是很难懂的语句。必要时需添加详细的注释  
    ```c
    *stat++ += 1;
    /* 应写为 */
    *stat += 1;
    stat++;
    ```
- 编码时减少非必要的全局共享变量，源文件内尽量使用`static`保持变量的独立性，通过函数接口提供对外访问的路径
- 尽管编译器支持C99语法，但对于局部变量的定义规则仍然建议参考C90的方式，即**先声明，再使用**
    ```c
    for(uint8_t i = 0; i < 8; i++)
    {
        /* code */
    }
    /* 建议写作 */
    uint8_t i;
    for(i = 0; i < 8; i++)
    {
        /* code */
    }
    ```
- 单独函数代码不宜过长，可考虑通过宏定义或inline函数，static函数等方式进行功能或流程上的分解
- 当数据类型需要发生转换时，应使用明确的**类型强制转换**写法
- 编写可重入函数时，应注意局部变量的使用。不建议在函数内使用`static`局部变量
- 对可重入函数中涉及到的全局变量使用，应考虑原子保护。否则，该函数就不能被用作可重入函数
- 函数需要对传入的形参做合法性检查，应通过条件编译的方式引入`dev_assert.h`头文件
- 建议在头文件中使用`static inline`内联函数或宏定义来封装硬件寄存器的组合逻辑操作。例如:  
    ```c
    static inline void Can4_cancel_transmit()
    {
        /* 取消发送状态 */
        xCAN4_CTRL.bits.ATX = 1u;
        NOP();
        xCAN4_CTRL.bits.ATX = 0u;
    }
    /* 或者 */
    #define CAN4_CANCLE_TRANSMIT() do{
        /* 取消发送状态 */
        xCAN4_CTRL.bits.ATX = 1u;
        NOP();
        xCAN4_CTRL.bits.ATX = 0u;
    }while(0)
    ```
- 库函数应只完成一项具体的功能，函数的目的单一明确。必须保证**输入相同的数据则产生的输出也相同的**。如果无法满足则需要重新设计划分该函数的功能及实现
- 函数形参个数不宜超过4个
- 严禁使用函数递归调用，不利于调试以及潜在的系统资源耗尽
- 尽量使用断言来发现定位问题，提高代码的可测性。统一的断言语句包含在`dev_assert.h`头文件中  
    ```c
    #if defined(KF_DEV_ERROR_DETECT)
    /* Implement default assert macro */
    static inline void DevAssert(volatile bool x)
    {
        if (!x)
        {
            asm("DSI");
            asm("NOP");
            asm("BREAK");
            for (;;)
            {
            }
        }
    }
    #define KF_DEV_ASSERT(x) DevAssert(x)
    #else
    /* Assert macro does nothing */
    #define KF_DEV_ASSERT(x) ((void)0)
    #endif
    ```
- 断言函数不应用来处理函数正常的错误返回或其他可预测的错误情况
- 编程时要随时留心代码效率，并在优化代码时，要周全考虑
- 应时刻警惕结构体的字节对齐情况
- 强制要求在所有涉及到**除法操作的代码**前做非0处理。(预防性编程)
- `switch`语句中必须包含`default`项。(预防性编程)
- 使用`union`联合体对数据做变体共享字段处理可提高代码效率及可读性
- 尽量避免在条件判断中使用`<=`或`>=`符合进行比较操作
- 尽量避免`goto`语句的使用，如有需要，则必须将跳转范围控制在同一个函数体内。对MISRA Rules告警的地方需要显式的注明Derivation原因
- 尽量避免嵌入式汇编代码的混用，需要有明确的封装以便于隔离使用
    ```c
    #define NOP() asm volatile("nop")
    ```
- 使用位字段时应注意字节对齐(PACK)，字节序(LE/BE)，以及位序(MSB/LSB)
- 不得使用八进制常数(零除外)和八进制转义序列。(MISRA C 2004 Rule 7.1)
- 函数只能在文件范围内声明，不得在块范围内声明。(MISRA C 2004 Rule 8.6)
- 只从单个函数内访问的对象，则应在该函数范围内进行定义。避免污染全局或静态变量环境。(MISRA C 2004 Rule 8.7)
- 只在源文件范围内使用的变量或函数，建议都使用`static`来约束。(MISRA C 2004 Rule 8.10/8.11)
- 所有局部变量在读取之前都必须进行初始化。(MISRA C 2004 Rule 9.1)。避免**使用栈上的随机内容**
- 非0初始化的数组或结构体应使用大括号来明确作用范围 。零或零初始化只能应用于数组或结构体的顶层(MISRA C 2004 Rule 9.2)
    ```c
    int16_t y[3][2] = { 1, 2, 3, 4, 5, 6 }; /* Not Compliant */
    int16_t y[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } }; /* Compliant */
    int16_t array1[5] = { 1, 2, 3, 0, 0 }; /* Compliant - non-zero initialization */
    int16_t array2[5] = { 0 }; /* Compliant- zero initialization */
    int16_t array3[5] = { 1, 2, 3 };   /* Not Compliant - non-zero initialization */
    int16_t array4[2][2] = { 0 };  /* Compliant - zero initialization at top-level */
    int16_t array5[2][2] = { { 0 }, { 1, 2 }}; /* Not Compliant - zero initialization at sub-level */
    ```
- 在枚举类型中，`=`赋值不得用于显式初始化除第一个之外的成员，除非所有项都显式初始化。(MISRA C 2004 Rule 9.3)
    ```c
    enum color { red, blue, green, yellow=5 }; /* non compliant */
    /* green and yellow represent the same value - this is duplication */
    enum color { red=3, blue=4, green=5, yellow=6 }; /* compliant */
    /* green and yellow represent the same value - this is duplication */
    ```
- 为提高代码效率，建议尽量将局部变量定义为处理器位宽的类型，例如`uint32`或是`int32`
- 隐式类型转换需遵循以下原则:
    - 有符号和无符号类型之间不得隐式转换
    - 整型和浮点型之间不得隐式转换
    - 宽字节类型到窄字节类型不得隐式转换
    - 函数参数不得隐式转换
    - 函数返回表达式不得隐式转换
    - 复杂表达式不得隐式转换
- 复杂表达式中所有的运算应尽量保持完全相同的算术类型。需提供必要的强制类型转换
    ```c
    /* both additions will notionally be performed in type uint32_t */
    uint32_t a;
    uint16_t b;
    uint16_t c;
    a + b + c /* Compliant */

    uint16_t a;
    uint16_t b;
    uint32_t c;
    a + b + c /* Not Compliant */       
    ```
- 如果位运算符`~`和`<<`应用于基础类型`unsigned char`或`unsigned short`的操作数，则结果应立即转换为基础类型的操作数。(MISRA C 2004 Rule 10.5)
    ```c
    uint8_t port = 0x5Au;
    uint8_t result_8;
    uint16_t result_16;
    uint16_t mode;
    result_8 = (~port) >> 4u; /* not compliant */
    result_8 = ((uint8_t)(~port)) >> 4u; /* compliant */
    result_16 = ((uint16_t)(~(uint16_t)port)) >> 4u; /* compliant */
    result_16 = ((port << 4u) & mode) >> 6u; /* not compliant */
    result_16 = ((uint16_t)((uint16_t)port << 4u) & mode) >> 6u;  /* compliant */
    ```
- 所有无符号整型的常数都必须添加`U`后缀
- 所有浮点类型的常数都必须添加`F`后缀
- 用16进制表示常数时除前缀`0x`外其他字符必须使用大写的形式。如:`0xDEADBEEF`
- `char`和`char*`关键字仅限于使用在操作字符或字符串上
- 不得直接使用`short`或`long`以及`float`关键字
- 不得执行从指针寻址的类型中移除任何`const`或`volatile`限定的转换。(MISRA C 2004 Rule 11.5)
    ```c
    const uint16_t* pci; /* pointer to const */
    volatile uint16_t* pvi; /* pointer to volatile */
    uint16_t* pi;
    pi = (uint16_t*)pci; /* Not compliant */
    pi = (uint16_t*)pvi; /* Not compliant */
    ```
- 位运算符不得应用于有符号类型的操作数。(MISRA C 2004 Rule 12.7)
- 移位运算符的右操作数应介于0和小于左操作数基本类型位宽度减去1之间。(MISRA C 2004 Rule 12.8)
    ```c
    u8a = (uint8_t) (u8a << 7); /* compliant */
    u8a = (uint8_t) (u8a << 9); /* not compliant */
    u16a = (uint16_t)((uint16_t) u8a << 9); /* compliant */
    ```
- 不得使用逗号运算符。通常不利于代码的可读性，通过其他方法也可以达到同样的效果。(MISRA C 2004 Rule 12.10)
- 尽量避免在宏定义中出现整数运算或求值。因为编译器一般不会检测到常量无符号整数表达式的溢出情况。(MISRA C 2004 Rule 12.11)
- 赋值运算符不得用于布尔型的表达式中。(MISRA C 2004 Rule 13.1)
- **严禁使用类似非0为真的判断条件**。(MISRA C 2004 Rule 13.2)
    ```c
    uint8_t num = 10;
    if (num)
    {
        /* code */
    }
    /* 应改为 */
    if (num > 0)
    {
        /* code */
    }
    ```
- 浮点类型的表达式不能用作相等或不相等判断。(MISRA C 2004 Rule 13.3)
- `for`循环语句的控制表达式不得包含任何浮点类型的变量。(MISRA C 2004 Rule 13.4)
- `for`循环语句的三个表达式应仅与循环控制相关。(MISRA C 2004 Rule 13.5)
- `for`循环中用于迭代计数的数值变量不得在循环体中修改。(MISRA C 2004 Rule 13.6)
    ```c
    uint8_t flag = 1;
    for ( i = 0; (i < 5) && (flag == 1); i++ )
    {
        /* ... */
        flag = 0; /* Compliant - allows early termination of loop */
        i = i + 3; /* Not compliant - altering the loop counter */
    }
    ```

- 迭代循环体中出现多于一个`break`语句时，应加以旁注声明。该条例容许违背(MISRA C 2004 Rule 14.6)规则。**禁止使用return退出循环体。**
- 尽量保证函数只有一个返回点(return 语句)。(MISRA C 2004 Rule 14.7)
- 多个返回点的例外是在合适的地方使用**卫语句**避免过深的嵌套的条件表达式
- if...else if 语句必须以一个 else 语句作为结束。(MISRA C 2004 Rule 14.10)
- `switch`语句建议统一使用下述格式
    ```c
    switch(condition)
    {
        case 1:
        {
            /* code */
        }
        break;
        case 2:
        {
            /* code */
        }
        break;
        case 3:
        case 4:
        case 5:
        {
            /* code */
        }
        break;
        /* ...... */
        default:    /* default clause is the final clause(MISRA C 2004 Rule 15.3) */
        {
            /* code */
        }
        break;
    }
    ```
- 函数形参不应使用可变数量的参数定义。例外，kfprintf(MISRA C 2004 Rule 16.1)
- 函数不得直接或间接地调用自身。禁止使用函数递归，存在堆栈溢出的风险(MISRA C 2004 Rule 16.2)
- 出于兼容性、清晰性和可维护性的考虑，应为功能声明中的所有参数提供名称。(MISRA C 2004 Rule 16.3)
    ```c
    extern uint16_t add(uint16_t a, uint16_t b);    /* Compliant */
    extern uint16_t add(uint16_t, uint16_t);    /* Not Compliant */
    ```
- 无参数的函数需要使用`void`作为形参列表。(MISRA C 2004 Rule 16.5)
    ```c
    extern void send_signal(void);    /* Compliant */
    extern void send_signal();    /* Not Compliant */
    ```
- 如果函数形参中的指针变量不会在函数内被修改的话，尽量使用`const`限定符。(MISRA C 2004 Rule 16.7)
- 如果函数返回错误信息，则不应忽略该错误信息。(MISRA C 2004 Rule 16.10)
- 指针算法仅适用于寻址数组或数组元素的指针。(MISRA C 2004 Rule 17.1)除指向同一数组外，指针之间不得进行大小比较或相减。(MISRA C 2004 Rule 17.2/17.3)
- 不建议超过两级的多重指针。(MISRA C 2004 Rule 17.4)
- 函数不得返回局部变量的指针，函数不能返回指针
- 谨慎使用`union`联合体，该条例背离了(MISRA C 2004 Rule 18.4)规则。尽管在实际应用中可以接受，但需注意以下几个方面:
    - 填充。联合体的尾部如何被填充
    - 对齐。联合体内的结构如何被对齐
    - 字节序。存储在最低或最高内存地址的字的最高有效字节
    - 位序。字节内的位是如何编号的，位是如何分配给位字段的
    - 移植性。联合体的布局受内核架构以及编译器的影响，可移植性不高
    - 执行效率。当高执行速度或低内存使用率比可移植性更重要时，使用联合体应该是首选
- 尽量将所有的`#include`语句放置于文件头位置，该语句前只能是其他预处理指令或注释。(MISRA C 2004 Rule 19.1)
- 宏定义只能扩展到带括号的初始化器、常量、字符串文字、括号表达式、类型限定符、存储类说明符或`do{...}while(0)`构造。(MISRA C 2004 Rule 19.4)
- 优先使用函数或内联函数，而不是宏定义来实现多行语句。因为前者提供了更安全、更健壮的编译器审查机制
- 宏定义中的参数应包含在括号中，除非是使用`#`或`##`操作数。(MISRA C 2004 Rule 19.10)
- **注意未定义的宏标识符会被默认为0，应在使用前进行定义。(MISRA C 2004 Rule 19.11)**
    ```c
    /* 以下预处理条件成立 */
    #if (x == 0) /* x assumed to be zero if not defined */
    ```
- 所有#else、#elif和#endif预处理器指令应与它们相关的#if或#ifdef指令位于同一文件中。(MISRA C 2004 Rule 19.17)
- 尽量降低或避免对标准库函数的依赖。**建议不使用编译器自带的C标准库函数**
- 若函数内部存在循环等待，则需要在函数注释中注明`caution`，该函数不推荐在中断处理函数中使用
- 代码中尽量不直接使用常数，建议使用宏定义或`const`变量来替换。例如:
    ```c
    /* 不建议 */
    for(int i = 0; i < 100; i++)
    {
        /* code */
    }
    /* 建议 */
    #define MAX_SIZE 100
    for(int i = 0; i < MAX_SIZE; i++)
    {
        /* code */
    }
    ```
- 比较表达式中，尽量将常数放置在操作符左边
- 除局部循环常用的i，j，k变量外，不得在其他地方使用单字符标识符命名
- 代码中的立即数，应显式的指明类型signed或unsigned
- 使用宏定义常数时，应明确该常数的数据类型
    ```c
        /* 建议 */
        #define MAX_NUM ((uint32_t)255)
        /* 不建议 */
        #define MAX_NUM (0xFFU)
    ```
- **源文件与头文件中需要加入version审核判定，保证版本一致性，避免引用源不同导致的异常bug**
- **除LowLevel层外，禁止直接访问寄存器，或是强制类型转换地址进行的寄存器操作**
- 建议使用静态断言`_Static_assert`对枚举类型，结构体大小等做编译器的审查
    ```c
    #define KF_STATIC_ASSERT(cond, msg) _Static_assert((cond), msg)
    typedef enum
    {
        PCLK_ADC_0,
        PCLK_ADC_1,
        PCLK_ADC_2,
    } Pclk_AdcEnum_t;
    KF_STATIC_ASSERT(PCLK_ADC_2 == 2, "Pclk_AdcEnum_t Integrity Broken");
    ```
- 建议使用GNU的扩展语法`__attribute__((deprecated))`管理函数的更新，保证该接口向下兼容或移除前提示
- 循环体中不得直接使用或修改引用类型的形参
- 中断处理程序中，除了判断flag置起状态，还需要考虑是否开启了相应的中断使能位
- *无论作用域如何，系统中的任何源文件都尽量不要重复使用具有static属性的标识符。这包括具有外部链接的对象或函数，以及具有静态存储类说明符的任何对象或函数。(MISRA C 2004 Rule 5.5)*


<!-- pagebreak -->

## 五.测试规范
- 不少于三人的代码Review过程，制定人工Review的内容条例
- 单元测试要求达到所有语句的覆盖度
- 测试包括所有编译器优化级别
- 编译后不得出现`warning`报警，如该处符合设计要求，则需要使用显示的关闭告警编译器语法
- 使用QAC工具进行代码审查，按要求对代码做改进或显式的告警抑制
- **代码自身需保证逻辑自洽验证**
- 检查头文件的`#define`互斥包含是否正确
- **代码圈复杂度不得大于15，驱动代码应控制在10以内为优**
- 按照QAC最新的内部规则库来审查代码状态



<!-- pagebreak -->

## 六.参考文档
- [《MISRA-C:2004 Guidelines for the use of the C language in critical systems》](https://soapbubble.cn/pdf/misra%20c2004.pdf)
- [《Doxygen Manual》](https://soapbubble.cn/pdf/doxygen_manual-1.9.3.pdf)
- [《Netrino Embedded C Coding Standard》](https://soapbubble.cn/pdf/Code_Rules.pdf)

<!-- pagebreak -->

