/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-kungfu32-little", "elf32-kungfu32-big","elf32-kungfu32-little")
OUTPUT_ARCH(kungfu32)
ENTRY(_start)
SEARCH_DIR(".");

MEMORY
{ 
  flash      : ORIGIN =  0x00000000, LENGTH = 128K  /* chip flash */
  ram        : ORIGIN =  0x10000000, LENGTH = 63K  /* chip ram */
  da_mem     : ORIGIN =  0x00200000, LENGTH = 32K  /* Flash Data Limit */

  mode_mem   : ORIGIN =  0x0C001420, LENGTH = 0x00000004  /* mode config*/
  pro_mem    : ORIGIN =  0x0C001000, LENGTH = 0x00000004  /* protect config */

}

SECTIONS
{
/*#############################################################*/
  .text : 
  { 
    . = 0x0000;
    KEEP (*vector.o(.text*))   /* chip interrupt vector ,writed in file named vector.s or vector.c */
    KEEP (*vector.obj(.text*))   /*compatible*/
    KEEP (*vector.c.obj(.text*))      /*compatible*/
     . = ALIGN(4);
    __vec_end__ = .;
    /*-------------------------------------*/
    /* Fixed boot version information. Reserve these locations before
       placing normal code so the location counter never moves backwards. */
    . = 0x00000400;
    . = (. + 3) & (-4);
    KEEP (*(.ECU_CUSTOMER_MAIN_VERSION*))

    . = 0x00000430;
    . = (. + 3) & (-4);
    KEEP (*(.ECU_CONFIG_MAIN_VERSION*))

    /* Keep normal code outside the fixed version-information area. */
    . = 0x00000460;
    *(.text*)     /* default function code space */
    /*--------------------------------------------------*/
     *(.ctors*)
     *(.dtors*)
    /*--------------------------------------------------*/
     . = ALIGN(4);
     PROVIDE_HIDDEN ( __preinit_array_start = .);
       KEEP (*(.preinit_array*))     /* class init function list space */
     PROVIDE_HIDDEN ( __preinit_array_end = .);
     . = ALIGN(4);
    /*--------------------------------------------------*/
     . = ALIGN(4);
    __init_class_start = ALIGN(4);
     PROVIDE_HIDDEN ( __init_array_start = .);
       KEEP (*(SORT(.init_array.*))) 
       KEEP (*(.init_array*))     /* class init function list space */
     PROVIDE_HIDDEN ( __init_array_end = .);
    __init_class_end = .;
     . = ALIGN(4);
    /*--------------------------------------------------*/
     . = ALIGN(4);
     PROVIDE_HIDDEN ( __fini_array_start = .);
       KEEP (*(SORT(.fini_array.*))) 
       KEEP (*(.fini_array*)) 
     PROVIDE_HIDDEN ( __fini_array_end = .);
     . = ALIGN(4);
    /*--------------------------------------------------*/
     . = ALIGN(4);
     *(.gcc_except_table*)

    /*--------------------------------------------------*/
     . = ALIGN(4);
     *(.init*)
     *(.fini*)
    /*--------------------------------------------------*/
     . = ALIGN(4);
    *(.rdata*)     /* global const variable space */
    *(.rodata*)     /* auto const variable space */
    /*--------------------------------------------------*/
    . = 0x15800;
    . = (. + 3) & (-4);
    KEEP (*(.ECU_SOFTWARE_VERSION*))
    /*--------------------------------------------------*/    
     . = ALIGN(4);
    __text_end__ = .;
    /*record: global variable value of initialization,size .data before __data_end__ */

  } > flash  
/*#############################################################*/
  /*
   * Initialized RAM image (incl. .indata Flash API).
   * Must use AT > flash so startup copy from __text_end__ loads the
   * relocated code. Without AT>flash, LMA==VMA(ram) and the flash
   * bytes after __text_end__ are not the linked .indata image — then
   * LD R4,#__Flash_Min_Size__ inside __FLASH_Erase__ can become a
   * wrong absolute (observed 0x17D0C inside LinTp_TxNSduCfg) and
   * return PARAM_ERROR(0x0C).
   */
  .data :
  {
  __data_start__ = .;    /*  address must aligned by 4 bytes under zero offset */
    /*--------------------------------------------------*/
    KEEP (*(.ramvector*))       /* default server for vector writed in ram */
    /*--------------------------------------------------*/
  __lpdata_start__ = ALIGN(4);
    *(.lpdata*)      /* Reset but Keep Space  */
    /* . = 0x8000 ;  */                      /* Max length limit is 32K byte ,if need 32K all config ,delete comment symbol*/
  __lpdata_end__ =  ALIGN(4);
    /*--------------------------------------------------*/
        . = ALIGN(4);
    *(.indata*)     /* server space for ram function */
    *(.inrdata*)
    *(.inrodata*)
    /*--------------------------------------------------*/
     . = ALIGN(4);
    *(.data*)     /* global variable with  initialization */
     . = ALIGN(4);
  __data_end__ = .;
  } > ram AT > flash

  __data_load_start__ = LOADADDR(.data);

/*#############################################################*/
  .bss :
  {
     . = ALIGN(4);
  __bss_start__ = .;    /* global variable with no initialization */
    *(COMMON*)
    *(.bss*)
     . = ALIGN(4);
  __bss_end__ = .;
    /*--------------------------------------------------*/
     . = ALIGN(4);
  __allot_end__ = .;  /* heap and stack space*/
  __Heap_Start__ = __allot_end__ ;
     PROVIDE_HIDDEN ( __heap_start = .);
     KEEP( *(.heap_mem*)  )
     . = ALIGN(4);
  __Logic_Heap_End__ = . ;

    . = DEFINED(Heap_Mem) ? ALIGN(4)  : ( __Logic_Heap_End__ + __Heap_length__ ) ;
     . = ALIGN(4);
     PROVIDE_HIDDEN ( __heap_end = .);
  __Heap_End__ = . ;
    /*--------------------------------------------------*/
          __MAX_Stack_LIMITS__ =  ALIGN(4);
    /*--------------------------------------------------*/
     . = ALIGN(4);
         __LMA_STACK_LIMITS__ = DEFINED(Stack_Mem)? (__initial_sp - ( __Logic_Stack_Start__  - __Logic_Stack_End__ )): (. );
   . = __LMA_STACK_LIMITS__ ;

  __Logic_Stack_End__  = . ;
       KEEP( *(.stack_mem*)  )
  __Logic_Stack_Start__ = . ;
    /*--------------------------------------------------*/
  __initial_sp = LENGTH(ram);
  PROVIDE(__Heap_length__ = 0x400 );/* defautl size */
    /*--------------------------------------------------*/
  } > ram

/*#############################################################*/
  .flashdata :
  {
    KEEP (*(.flashdata*))  /* Flash Data */
    . =  LENGTH(da_mem);/* length  limit */
  } > da_mem
/*#############################################################*/
  .debugormode :
  {
    KEEP (*(.modeconfig*))  /* Mode */
  } > mode_mem

  .protectmode :
  {
    KEEP (*(.protectconfig*))  /* Protect */
  } > pro_mem

/*#############################################################*/

  /* Stabs debugging sections.  */
  .stab          0 : { *(.stab) }
  .stabstr       0 : { *(.stabstr) }
  .stab.excl     0 : { *(.stab.excl) }
  .stab.exclstr  0 : { *(.stab.exclstr) }
  .stab.index    0 : { *(.stab.index) }
  .stab.indexstr 0 : { *(.stab.indexstr) }
  .comment       0 : { *(.comment) }
/*#############################################################*/
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
/*#############################################################*/
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
/*#############################################################*/
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line .debug_line.* .debug_line_end ) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
/*#############################################################*/
  /* DWARF 3 */
  .debug_pubtypes 0 : { *(.debug_pubtypes) }
  .debug_ranges   0 : { *(.debug_ranges) }
  /* DWARF Extension.  */
  .debug_macro    0 : { *(.debug_macro) }
  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) }
/*#############################################################*/
  /* DWARF 4 */
  .debug_types 0 : { *(.debug_types) }
/*#############################################################*/

}
