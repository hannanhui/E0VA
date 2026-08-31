
//Lib_Version, 				        "V2.1.2.240723"
    .text

//###############################################################################	
    .EQU  __FLASH_MAX_SIZE__,	(2080 << 10)
    // Must match FLS_MIN_OPERABLE_ADDRESS in Fls_Cfg.h (1KB).
    // Do NOT use ".extern __Flash_Min_Size__" + LD/LD.W from .indata:
    // absolute reloc of that symbol in RAM code can bind to a wrong flash
    // address (observed: 0x17D0C inside LinTp_TxNSduCfg instead of the real
    // __Flash_Min_Size__), then the min-address check returns PARAM_ERROR(0x0C).
    .EQU  __FLASH_MIN_SIZE__,	0x400

//###############################################################################
.macro __FLASH_Function__ name
    .section .text$\name
    .align	1
    .export	\name
    .type	\name, @function
    .func \name
\name:
.endm

.macro __RAM_Function__ name
    .section .indata$\name
    .align	1
    .export	\name
    .type	\name, @function
    .func \name
\name:
.endm

.macro __End_Function__ name
        .size	\name, .-\name
        .endfunc
.endm

//###############################################################################  
    .EQU  Function_Parameter_Validate,   	0x5A5A6688
    .EQU  CMD_SUCCESS, 				  		0x00
    .EQU  CMD_ERROR,					  	0xAA
    .EQU  PARAM_ERROR,					  	0x0C
    .EQU  TimeOutCountValue, 				50000

//###############################################################################
    .SET  __PAGE_SIZE__		                , 0x400
    .SET  __HALF_PAGE_SIZE__		        , 0x200
    .SET  __PAGE_SIZE_MASK__		        , 0x3FF
    .SET  __HALF_PAGE_SIZE_MASK__	        , 0x1FF
    .SET  __FOUR_WORD_MASK__		        , 0x3
    .SET  __ROW_SIZE_IN_WORD__		        , 0x2
    .SET  __ROW_SIZE_IN_BYTE__		        , 0x8
    .SET  __ROW_SIZE_MASK_IN_BYTE__		    , 0x7
    .SET  __ROW_NUM__		                , 0x40
    
    .SET  __SOFT_KEY1_INDEX__		        , 0x0
    .SET  __UNLOCK_KEY1_INDEX__		        , 0x1
    .SET  __UNLOCK_KEY2_INDEX__		        , 0x2
    .SET  __SOFT_KEY2_INDEX__		        , 0x3

//###############################################################################
    .SET  FLASH_ISPCMD_ERASEPAGE		    , 0x7FB
    .SET  FLASH_ISPCMD_WRITE_HALF_PAGE      , 0x7E5
    .SET  FLASH_ISPCMD_WRITE_ONE_WORD       , 0x15
    
    .SET  FLASH_ISPTRG_TRIGGER              , 0x50AF0001
    .SET  FLASH_NVMUNLOCK_KEY1              , 0x27654330
    .SET  FLASH_NVMUNLOCK_KEY2              , 0x81040304
    
    .SET  FLASH_ISPCON0_HIGH                , 0x50AF0000
    .SET  FLASH_ISPCON0_LOW_MSK             , 0x0000FFFF
    
    .EQU  FLASH_DATA_START_ADDR  		    , 0x00200000
    .EQU  FLASH_PROGRAM_END_ADDR  		    , 0x000F0000 

//###############################################################################
    .SET  FLASH_ISPCON0		                , 0x40200100
    .SET  FLASH_ISPCON1		                , 0x40200104
    .SET  FLASH_ISPCMD		                , 0x40200108
    .SET  FLASH_ISPTRG		                , 0x4020010C
    .SET  FLASH_ISPADDR		                , 0x4020011C
    .SET  FLASH_STATE		                , 0x40200120
    .SET  FLASH_NVMUNLOCK	                , 0x40200128
    .SET  FLASH_PROUNLOCK	                , 0x4020012C

//###############################################################################
    .SET  INT_CTL0                          , 0x40200000

//###############################################################################

// __FLASH_Erase__ #########################################################################
    // uint32_t __FLASH_Erase__(volatile const uint32_t *const KeyPtr, volatile uint32_t WriteAddr)
    
    __RAM_Function__  __FLASH_Erase__
    SUB	      SP, #8
    MOV       R5, R0
    ST.W      [SP + #1], R1
    MOV       R4, #0
    ST.W      [SP], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ Pointer of key can't be NULL
    MOV       R0, #PARAM_ERROR
    CMP       R5, R4
    JZ        FLASH_Erase_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address + __PAGE_SIZE__ can't be greater than __FLASH_MAX_SIZE__
    LD.W      R3, [SP + #1]
    LD        R4, #__PAGE_SIZE__
    ADD       R3, R3, R4
    LD        R4, #__FLASH_MAX_SIZE__
    CMP       R3, R4
    JHI       FLASH_Erase_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address can't be less than __FLASH_MIN_SIZE__
    LD.W      R3, [SP + #1]
    LD        R4, #__FLASH_MIN_SIZE__
    CMP       R4, R3
    JHI       FLASH_Erase_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address should be page aligned
    LD.W      R3, [SP + #1]
    LD        R4, #__PAGE_SIZE_MASK__
    ANL       R4, R3, R4
    JNZ       FLASH_Erase_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check soft key
    LD.W      R4, [R5 + #__SOFT_KEY1_INDEX__]
    LD        R3, #Function_Parameter_Validate
    CMP       R4, R3
    JNZ       FLASH_Erase_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ NVM unlock
    LD        R3, #FLASH_ISPCON0
    LD        R2, #FLASH_NVMUNLOCK_KEY1
    ST.W      [R3 + #10], R2
    LD        R2, #FLASH_NVMUNLOCK_KEY2
    ST.W      [R3 + #10], R2
    // ++++++++++++++++++++++++++++++++++++++++++++++ NVM unlock status check
    LD.W      R1, [R3]
    MOV       R2, #1
    ANL       R2, R1, R2
    MOV       R0, #CMD_ERROR
    CMP       R2, #0
    JZ        FLASH_Erase_Lock_NVM_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check soft key2
    LD.W      R2, [R5 + #__SOFT_KEY2_INDEX__]
    LD        R4, #Function_Parameter_Validate
    MOV       R0, #PARAM_ERROR
    CMP       R2, R4
    JNZ       FLASH_Erase_Lock_NVM_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ unlock PRO
    LD.W      R4, [R5 + #__UNLOCK_KEY1_INDEX__]
    LD        R3, #FLASH_PROUNLOCK
    ST.W      [R3], R4
    LD.W      R4, [R5 + #__UNLOCK_KEY2_INDEX__]
    ST.W      [R3], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ PRO unlock status check
    LD        R3, #FLASH_ISPCON0
    LD.W      R4, [R3]
    MOV       R5, #1
    LSL       R5, #9
    ANL       R5, R4, R5
    JNZ       FLASH_Erase_PRO_Unlocked
    MOV       R5, #1
    LSL       R5, #10
    ANL       R5, R4, R5
    JNZ       FLASH_Erase_PRO_Unlocked
    MOV       R5, #1
    LSL       R5, #8
    ANL       R5, R4, R5
    JNZ       FLASH_Erase_PRO_Unlocked
    MOV       R5, #2
    ANL       R5, R4, R5
    JZ        FLASH_Erase_Lock_PRO_Return
FLASH_Erase_PRO_Unlocked:
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address + __PAGE_SIZE__ can't be greater than __FLASH_MAX_SIZE__
    LD.W      R4, [SP + #1]
    LD        R5, #__PAGE_SIZE__
    ADD       R4, R4, R5
    MOV       R0, #PARAM_ERROR
    LD        R5, #__FLASH_MAX_SIZE__
    CMP       R4, R5
    JHI       FLASH_Erase_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address can't be less than __FLASH_MIN_SIZE__
    LD.W      R4, [SP + #1]
    LD        R5, #__FLASH_MIN_SIZE__
    CMP       R5, R4
    JHI       FLASH_Erase_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address should be page aligned
    LD.W      R4, [SP + #1]
    LD        R5, #__PAGE_SIZE_MASK__
    ANL       R5, R4, R5
    JNZ       FLASH_Erase_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check DFlash/PFlash address
    LD        R5, #FLASH_ISPCON0
    LD.W      R4, [R5]
    MOV       R5, #1
    LSL       R5, #8
    ANL       R5, R4, R5
    JZ        $+5
    LD.W      R4, [SP + #1]
    LD        R5, #FLASH_DATA_START_ADDR
    CMP       R5, R4
    JHI       FLASH_Erase_Lock_PRO_Return
    LD        R5, #FLASH_ISPCON0
    LD.W      R4, [R5]
    MOV       R5, #1
    LSL       R5, #9
    ANL       R5, R4, R5
    JZ        $+8
    LD.W      R4, [SP + #1]
    LD        R5, #__PAGE_SIZE__
    ADD       R4, R4, R5
    MOV       R0, #PARAM_ERROR
    LD        R5, #FLASH_PROGRAM_END_ADDR
    CMP       R4, R5
    JHI       FLASH_Erase_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Set Address
    LD.W      R4, [SP + #1]
    LD        R5, #FLASH_ISPCON0
    ST.W      [R5 + #7], R4
    LD.W      R3, [R5 + #7]
    LD.W      R4, [SP + #1]
    MOV       R0, #CMD_ERROR
    CMP       R3, R4
    JNZ       FLASH_Erase_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Set CMD
    LD        R4, #FLASH_ISPCMD_ERASEPAGE
    ST.W      [R5 + #2], R4
    LD.W      R3, [R5 + #2]
    MOV       R0, #CMD_ERROR
    CMP       R3, R4
    JNZ       FLASH_Erase_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Save AIE
    LD        R3, #INT_CTL0
    LD.W      R3, [R3]
    DSI
    NOP
    // ++++++++++++++++++++++++++++++++++++++++++++++ Trigger
    LD        R4, #FLASH_ISPTRG_TRIGGER
    ST.W      [R5 + #3], R4
    NOP
    NOP
    NOP
    // ++++++++++++++++++++++++++++++++++++++++++++++ Resume AIE
    JNB       R3, #0
    ENI
    NOP
    // ++++++++++++++++++++++++++++++++++++++++++++++ Wait TBIT
    LD        R4, #TimeOutCountValue
    ST.W      [SP], R4
    MOV       R4, #4
    SJMP      FLASH_Erase_Read_TBIT   
FLASH_Erase_Wait_TBIT_Loop:
    LD.W      R3, [SP]
    CMP       R3, #0
    JZ        FLASH_Erase_Wait_TBIT_Loop_End
    LD.W      R3, [SP]
    SUB       R3, R3, #1
    ST.W      [SP], R3
FLASH_Erase_Read_TBIT:
    LD.W      R3, [R5 + #8]
    ANL       R3, R3, R4
    JNZ       FLASH_Erase_Wait_TBIT_Loop

FLASH_Erase_Wait_TBIT_Loop_End:
    LD.W      R5, [SP]
    CMP       R5, #0
    JZ        FLASH_Erase_Cfg_Error
    LD        R5, #FLASH_STATE
    LD.W      R4, [R5]
    MOV       R5, #1
    ANL       R5, R4, R5
    MOV       R0, #0
    CMP       R5, R0
    JZ        FLASH_Erase_Lock_PRO_Return

FLASH_Erase_Cfg_Error:
    LD        R5, #FLASH_STATE
    LD.W      R4, [R5]
    ST.W      [R5], R4
    MOV       R0, #CMD_ERROR

    // ++++++++++++++++++++++++++++++++++++++++++++++ lock PRO
FLASH_Erase_Lock_PRO_Return:
    LD        R5, #FLASH_ISPCMD
    MOV       R4, #0
    ST.W      [R5], R4
    LD        R5, #FLASH_ISPADDR
    ST.W      [R5], R4
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    ZXT.H     R3, R3
    LD        R4, #FLASH_ISPCON0_HIGH
    ORL       R4, R3, R4
    ST.W      [R5], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ lock NVM
FLASH_Erase_Lock_NVM_Return:
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    ZXT.H     R3, R3
    LD        R4, #FLASH_ISPCON0_HIGH
    ORL       R4, R3, R4
    ST.W      [R5], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ return
FLASH_Erase_Fast_Return:
    ADD       SP, #8
    JMP       LR

    __End_Function__ __FLASH_Erase__
// #########################################################################################


// __FLASH_Program__ #######################################################################
    // uint32_t __FLASH_Program__(volatile const uint32_t *const KeyPtr, uint32_t WriteAddr, const uint32_t *const WriteData)
    __RAM_Function__  __FLASH_Program__
    PUSH      {R6-R9}
    SUB	      SP, #12
    MOV       R5, R0
    ST.W      [SP + #1], R0
    MOV       R4, #0
    ST.W      [SP], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ Pointer of key can't be NULL
    MOV       R0, #PARAM_ERROR
    CMP       R5, R4
    JZ        FLASH_Program_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Buffer can't be NULL
    CMP       R2, R4
    JZ        FLASH_Program_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address + __HALF_PAGE_SIZE__ can't be greater than __FLASH_MAX_SIZE__
    LD        R4, #__HALF_PAGE_SIZE__
    ADD       R4, R1, R4
    LD        R3, #__FLASH_MAX_SIZE__
    CMP       R4, R3
    JHI       FLASH_Program_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address can't be less than __FLASH_MIN_SIZE__
    LD        R4, #__FLASH_MIN_SIZE__
    CMP       R4, R1
    JHI       FLASH_Program_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address should be half page aligned
    LD        R3, #__HALF_PAGE_SIZE_MASK__
    ANL       R3, R1, R3
    JNZ       FLASH_Program_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check soft key
    LD.W      R3, [R5 + #__SOFT_KEY1_INDEX__]
    LD        R6, #Function_Parameter_Validate
    CMP       R3, R6
    JNZ       FLASH_Program_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ NVM unlock
    LD        R6, #FLASH_ISPCON0
    LD        R0, #FLASH_NVMUNLOCK_KEY1
    ST.W      [R6 + #10], R0
    LD        R0, #FLASH_NVMUNLOCK_KEY2
    ST.W      [R6 + #10], R0
    // ++++++++++++++++++++++++++++++++++++++++++++++ NVM unlock status check
    LD.W      R7, [R6]
    MOV       R0, #1
    ANL       R7, R7, R0
    MOV       R0, #CMD_ERROR
    CMP       R7, #0
    JZ        FLASH_Program_Lock_NVM_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check soft key
    LD.W      R7, [R5 + #__SOFT_KEY2_INDEX__]
    MOV       R0, #PARAM_ERROR
    LD        R3, #Function_Parameter_Validate
    CMP       R7, R3
    JNZ       FLASH_Program_Lock_NVM_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ unlock PRO
    LD.W      R3, [R5 + #__UNLOCK_KEY1_INDEX__]
    ST.W      [R6 + #11], R3
    LD.W      R5, [R5 + #__UNLOCK_KEY2_INDEX__]
    ST.W      [R6 + #11], R5
    // ++++++++++++++++++++++++++++++++++++++++++++++ PRO unlock status check
    LD.W      R3, [R6]
    MOV       R5, #1
    LSL       R5, #9
    ANL       R5, R3, R5
    JNZ       FLASH_Program_PRO_Unlocked
    MOV       R5, #1
    LSL       R5, #10
    ANL       R5, R3, R5
    JNZ       FLASH_Program_PRO_Unlocked
    MOV       R5, #1
    LSL       R5, #8
    ANL       R5, R3, R5
    JNZ       FLASH_Program_PRO_Unlocked
    MOV       R5, #2
    MOV       R0, #CMD_ERROR
    ANL       R5, R3, R5
    JZ        FLASH_Program_Lock_PRO_Return
FLASH_Program_PRO_Unlocked:
    MOV       R4, #0
    // ++++++++++++++++++++++++++++++++++++++++++++++ Pointer of key can't be NULL
    MOV       R0, #PARAM_ERROR
    LD.W      R5, [SP + #1]
    CMP       R5, R4
    JZ        FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Buffer can't be NULL
    CMP       R2, R4
    JZ        FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address + __HALF_PAGE_SIZE__ can't be greater than __FLASH_MAX_SIZE__
    LD        R4, #__HALF_PAGE_SIZE__
    ADD       R4, R1, R4
    LD        R3, #__FLASH_MAX_SIZE__
    CMP       R4, R3
    JHI       FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address can't be less than __FLASH_MIN_SIZE__
    LD        R4, #__FLASH_MIN_SIZE__
    CMP       R4, R1
    JHI       FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address should be half page aligned
    LD        R3, #__HALF_PAGE_SIZE_MASK__
    ANL       R3, R1, R3
    JNZ       FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ buffer should be four word aligned
    MOV       R5, #__FOUR_WORD_MASK__
    ANL       R5, R2, R5
    MOV       R0, #PARAM_ERROR
    CMP       R5, #0
    JNZ       FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check DFlash/PFlash address
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    MOV       R5, #1
    LSL       R5, #8
    ANL       R5, R3, R5
    JZ        $+4
    LD        R5, #FLASH_DATA_START_ADDR
    CMP       R5, R1
    JHI       FLASH_Program_Lock_PRO_Return
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    MOV       R5, #1
    LSL       R5, #9
    ANL       R5, R3, R5
    JZ        $+5
    MOV       R0, #PARAM_ERROR
    LD        R5, #FLASH_PROGRAM_END_ADDR
    CMP       R4, R5
    JHI       FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Set CMD
    LD        R5, #FLASH_ISPCON0
    LD        R4, #FLASH_ISPCMD_WRITE_ONE_WORD
    ST.W      [R5 + #2], R4
    LD.W      R3, [R5 + #2]
    MOV       R0, #CMD_ERROR
    CMP       R3, R4
    JNZ       FLASH_Program_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Program
    LD        R3, #__ROW_NUM__
FLASH_Program_Write_Loop:
    CMP       R3, #0
    JZ        FLASH_Program_Write_Loop_end_ok
    SUB       R3, #1
    LD        R4, #__ROW_SIZE_IN_WORD__
FLASH_Program_Write_Data:
    CMP       R4, #0
    JZ        FLASH_Program_Write_Data_End
    SUB       R4, #1
    LD.W      R9,[R2++]
    ST.W      [R1++],R9
    JMP       FLASH_Program_Write_Data
FLASH_Program_Write_Data_End:
    // ++++++++++++++++++++++++++++++++++++++++++++++ Save AIE
    PUSH      R3
    LD        R3, #INT_CTL0
    LD.W      R3, [R3]
    DSI
    NOP
    LD        R4, #FLASH_ISPTRG_TRIGGER
    ST.W      [R5 + #3],R4
    NOP
    NOP
    NOP
    // ++++++++++++++++++++++++++++++++++++++++++++++ Resume AIE
    JNB       R3, #0
    ENI
    NOP
    POP       R3

    LD        R6, #TimeOutCountValue
FLASH_Program_Wait_TBIT:
    CMP       R6, #0
    JZ        FLASH_Program_Wait_TBIT_End
    SUB       R6, #1
    LD.W      R4, [R5 + #8]
    MOV       R8, #4
    ANL       R8, R4
    JNZ       FLASH_Program_Wait_TBIT
FLASH_Program_Wait_TBIT_End:
    CMP       R6, #0
    JZ        FLASH_Program_Write_Loop_end
    MOV       R8, #1
    LD.W      R4, [R5 + #8]
    ANL       R8, R4
    JNZ       FLASH_Program_Cfg_Error
    JMP       FLASH_Program_Write_Loop

FLASH_Program_Cfg_Error:
    LD.W      R4, [R5 + #8]
    ST.W      [R5 + #8], R4
    JMP       FLASH_Program_Write_Loop_end

FLASH_Program_Write_Loop_end_ok:
    MOV       R0, #0
    JMP       FLASH_Program_Lock_PRO_Return
FLASH_Program_Write_Loop_end:
    MOV       R0, #CMD_ERROR

    // ++++++++++++++++++++++++++++++++++++++++++++++ lock PRO
FLASH_Program_Lock_PRO_Return:
    LD        R5, #FLASH_ISPCON0
    MOV       R4, #0
    ST.W      [R5 + #2], R4
    ST.W      [R5 + #7], R4
    LD.W      R3, [R5]
    ZXT.H     R3, R3
    LD        R4, #FLASH_ISPCON0_HIGH
    ORL       R4, R3, R4
    ST.W      [R5], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ lock NVM
FLASH_Program_Lock_NVM_Return:
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    ZXT.H     R3, R3
    LD        R4, #FLASH_ISPCON0_HIGH
    ORL       R4, R3, R4
    ST.W      [R5], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ return
FLASH_Program_Fast_Return:
    ADD       SP, #12
    POP       {R6-R9}
    JMP       LR

    __End_Function__	__FLASH_Program__
// #########################################################################################	

// __FLASH_Program_NBytes__ ################################################################
    // uint32_t __FLASH_Program_NBytes__(volatile const uint32_t *const KeyPtr, uint32_t WriteAddr, const uint32_t *const WriteData)
    __RAM_Function__  __FLASH_Program_NBytes__

    PUSH      {R6-R7}
    SUB       SP, #8
    MOV       R5, R0
    MOV       R4, #0
    ST.W      [SP], R4
    ST.W      [SP + #1], R0
    // ++++++++++++++++++++++++++++++++++++++++++++++ Pointer of key can't be NULL
    MOV       R0, #PARAM_ERROR
    CMP       R5, R4
    JZ        FLASH_Program_NBytes_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Buffer can't be NULL
    CMP       R2, R4
    JZ        FLASH_Program_NBytes_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address + __ROW_SIZE_IN_BYTE__ can't be greater than __FLASH_MAX_SIZE__
    MOV       R3, #__ROW_SIZE_IN_BYTE__
    ADD       R4, R1, R3
    LD        R3, #__FLASH_MAX_SIZE__
    CMP       R4, R3
    JHI       FLASH_Program_NBytes_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address can't be less than __FLASH_MIN_SIZE__
    LD        R4, #__FLASH_MIN_SIZE__
    CMP       R4, R1
    JHI       FLASH_Program_NBytes_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address should be one word aligned
    MOV       R3, #__ROW_SIZE_MASK_IN_BYTE__
    ANL       R3, R1, R3
    JNZ       FLASH_Program_NBytes_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check soft key
    LD.W      R3, [R5 + #__SOFT_KEY1_INDEX__]
    LD        R6, #Function_Parameter_Validate
    CMP       R3, R6
    JNZ       FLASH_Program_NBytes_Fast_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ NVM unlock
    LD        R6, #FLASH_ISPCON0
    LD        R0, #FLASH_NVMUNLOCK_KEY1
    ST.W      [R6 + #10], R0
    LD        R0, #FLASH_NVMUNLOCK_KEY2
    ST.W      [R6 + #10], R0
    // ++++++++++++++++++++++++++++++++++++++++++++++ NVM unlock status check
    LD.W      R7, [R6]
    MOV       R0, #1
    ANL       R7, R7, R0
    MOV       R0, #CMD_ERROR
    CMP       R7, #0
    JZ        FLASH_Program_NBytes_Lock_NVM_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check soft key
    LD.W      R7, [R5 + #__SOFT_KEY2_INDEX__]
    MOV       R0, #PARAM_ERROR
    CMP       R7, R3
    JNZ       FLASH_Program_NBytes_Lock_NVM_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ unlock PRO
    LD.W      R3, [R5 + #__UNLOCK_KEY1_INDEX__]
    ST.W      [R6 + #11], R3
    LD.W      R5, [R5 + #__UNLOCK_KEY2_INDEX__]
    ST.W      [R6 + #11], R5
    // ++++++++++++++++++++++++++++++++++++++++++++++  PRO unlock status check
    LD.W      R3, [R6]
    MOV       R5, #1
    LSL       R5, #9
    ANL       R5, R3, R5
    JNZ       FLASH_Program_NBytes_PRO_Unlocked
    MOV       R5, #1
    LSL       R5, #10
    ANL       R5, R3, R5
    JNZ       FLASH_Program_NBytes_PRO_Unlocked
    LD.W      R3, [R6]
    MOV       R5, #1
    LSL       R5, #8
    ANL       R5, R3, R5
    JNZ       FLASH_Program_NBytes_PRO_Unlocked
    MOV       R5, #3
    ANL       R5, R2, R5
    JNZ       FLASH_Program_NBytes_PRO_Unlocked
    MOV       R0, #CMD_ERROR
    CMP       R5, #0
    JNZ       FLASH_Program_NBytes_Lock_PRO_Return
FLASH_Program_NBytes_PRO_Unlocked:
    // ++++++++++++++++++++++++++++++++++++++++++++++ Pointer of key can't be NULL
    MOV       R0, #PARAM_ERROR
    LD.W      R5, [SP + #1]
    MOV       R4, #0
    CMP       R5, R4
    JZ        FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Buffer can't be NULL
    CMP       R2, R4
    JZ        FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address + __ROW_SIZE_IN_BYTE__ can't be greater than __FLASH_MAX_SIZE__
    MOV       R3, #__ROW_SIZE_IN_BYTE__
    ADD       R4, R1, R3
    LD        R3, #__FLASH_MAX_SIZE__
    CMP       R4, R3
    JHI       FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address can't be less than __FLASH_MIN_SIZE__
    LD        R4, #__FLASH_MIN_SIZE__
    CMP       R4, R1
    JHI       FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Address should be one word aligned
    MOV       R3, #__ROW_SIZE_MASK_IN_BYTE__
    ANL       R3, R1, R3
    JNZ       FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ buffer should be four word aligned
    MOV       R5, #__FOUR_WORD_MASK__
    ANL       R5, R2, R5
    MOV       R0, #PARAM_ERROR
    CMP       R5, #0
    JNZ       FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Check DFlash/PFlash address
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    MOV       R5, #1
    LSL       R5, #8
    ANL       R5, R3, R5
    JZ        $+4
    LD        R5, #FLASH_DATA_START_ADDR
    CMP       R5, R1
    JHI       FLASH_Program_NBytes_Lock_PRO_Return
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    MOV       R5, #1
    LSL       R5, #9
    ANL       R5, R3, R5
    JZ        $+5
    MOV       R0, #PARAM_ERROR
    LD        R5, #FLASH_PROGRAM_END_ADDR
    CMP       R4, R5
    JHI       FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ Set CMD
    LD        R5, #FLASH_ISPCON0
    MOV       R3, #FLASH_ISPCMD_WRITE_ONE_WORD
    ST.W      [R5 + #2], R3
    LD.W      R5, [R5 + #2]
    MOV       R0, #CMD_ERROR
    CMP       R5, R3
    JNZ       FLASH_Program_NBytes_Lock_PRO_Return
    // ++++++++++++++++++++++++++++++++++++++++++++++ One word Program
    LD        R4, #__ROW_SIZE_IN_WORD__
FLASH_Program_NBytes_Write_Data:
    CMP       R4, #0
    JZ        FLASH_Program_NBytes_Write_Data_End
    SUB       R4, #1
    LD.W      R3,[R2++]
	ST.W      [R1++],R3
    JMP       FLASH_Program_NBytes_Write_Data

FLASH_Program_NBytes_Write_Data_End:
    // ++++++++++++++++++++++++++++++++++++++++++++++ Save AIE
    LD        R3, #INT_CTL0
    LD.W      R3, [R3]
    DSI
    NOP
    LD        R5, #FLASH_ISPTRG
    LD        R4, #FLASH_ISPTRG_TRIGGER
    ST.W      [R5], R4
    NOP
    NOP
    NOP
    // ++++++++++++++++++++++++++++++++++++++++++++++ Resume AIE
    JNB       R3, #0
    ENI
    NOP

    LD        R4, #TimeOutCountValue
FLASH_Program_NBytes_Wait_TBIT:
    CMP       R4, #0
    JZ        FLASH_Program_NBytes_Wait_TBIT_End
    SUB       R4, #1
    LD        R5, #FLASH_STATE
    LD.W      R5, [R5]
    MOV       R3, #4
    ANL       R3, R5
    JNZ       FLASH_Program_NBytes_Wait_TBIT
FLASH_Program_NBytes_Wait_TBIT_End:
    MOV       R0, #CMD_ERROR
    CMP       R4, #0
    JZ        FLASH_Program_NBytes_Lock_PRO_Return
    MOV       R3, #1
    LD        R5, #FLASH_STATE
    LD.W      R5, [R5]
    ANL       R3, R5
    JNZ       FLASH_Program_NBytes_Cfg_Error
    MOV       R0, #0
    JMP       FLASH_Program_NBytes_Lock_PRO_Return
FLASH_Program_NBytes_Cfg_Error:
    LD        R5, #FLASH_STATE
    LD.W      R6, [R5]
    ST.W      [R5], R6

    // ++++++++++++++++++++++++++++++++++++++++++++++ lock PRO
FLASH_Program_NBytes_Lock_PRO_Return:
    LD        R5, #FLASH_ISPCON0
    MOV       R4, #0
    ST.W      [R5 + #2], R4
    ST.W      [R5 + #7], R4
    LD.W      R3, [R5]
    ZXT.H     R3, R3
    LD        R4, #FLASH_ISPCON0_HIGH
    ORL       R4, R3, R4
    ST.W      [R5], R4
    // ++++++++++++++++++++++++++++++++++++++++++++++ lock NVM
FLASH_Program_NBytes_Lock_NVM_Return:
    LD        R5, #FLASH_ISPCON0
    LD.W      R3, [R5]
    ZXT.H     R3, R3
    LD        R4, #FLASH_ISPCON0_HIGH
    ORL       R4, R3, R4
    ST.W      [R5], R4
FLASH_Program_NBytes_Fast_Return:
    ADD       SP, #8
    POP       {R6-R7}
    JMP       LR

    __End_Function__ __FLASH_Program_NBytes__
// #########################################################################################	
