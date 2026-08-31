//****************************************************************************************
//*
//* File Name: startup.c 
//* Project Name: KF32A158MQVSF
//* Version: v1.0
//* Date: 2026-03-20 17:25:11
//* Author: 122905
//* 
//****************************************************************************************/
//#include <KF32A158MQVSF.h>

//asm(".include		\"KF32A158MQVSF.inc\"	");	 


#ifndef HWREG
#define HWREG(x) (*((volatile unsigned int *)(x)))
#endif
//#################     auto value variable from tool 	 #############//
extern unsigned int __text_end__;
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;
extern unsigned int __data_start__;
extern unsigned int __data_end__;
extern unsigned int __data_load_start__;

//#define Project_Type__cplusplus
#ifdef  Project_Type__cplusplus
extern unsigned int __init_class_start;
extern unsigned int __init_class_end;
#endif
//####################################################################//
int main(void);
int startup(void);

static void __start_check_ram(void);
// ####################################################################//
int startup(void)
{
    unsigned int *s;
    unsigned int *begin;
    unsigned int *end;

    volatile unsigned int oscReg  = 0U;
    volatile unsigned int tmpReg  = 0U;
    volatile unsigned int regMask = 0U;

    /** ROM Lock **/
    /*Read register*/
    tmpReg = HWREG(0x402000B8U);
    /*Set mask -- ARKEY, ROMLOCK*/
    regMask = 0xFFFF0000U | (1U << 11U);
    /*Clear ARKEY, ROMLOCK*/
    tmpReg &= ~regMask;
    /*Write ARKEY, ROMLOCK*/
    tmpReg |= 0x05FA0800U;
    /*Write SYS_ARCTL register*/
    HWREG(0x402000B8U) = tmpReg;
    asm("NOP");

#ifdef Project_Type__cplusplus
    void (*pf)(void);
#endif
//############# 		init work for the chip 		    #############//
//	HWREG(0x40003900)=1;
	HWREG(0x40003900)=0;	// cppcheck-suppress misra-c2012-11.4
//############# init variable who have initialization	#############//
	/* Prefer LOADADDR(.data) when provided by linker (AT > flash). */
	s = (unsigned int*)&__data_load_start__;
	begin = (unsigned int*)&__data_start__;
	end = (unsigned int*)&__data_end__;
	while( begin <  end) {	// cppcheck-suppress comparePointers
		*begin = *s;
		begin++;
		s++;
	}
//############# init class who have initialization(C++)	#############//
#ifdef Project_Type__cplusplus
	begin = (unsigned int*)&__init_class_start;
	end = (unsigned int*)&__init_class_end;
	while( begin < end )	// cppcheck-suppress comparePointers
	{
		pf=(void *)(*begin);
		pf();
		begin++;
	}
#endif		
//############# init variable who have no initialization	#############//
#if 1	 //  0 not init this type variable
	begin = (unsigned int*)&__bss_start__;
	end = (unsigned int*)&__bss_end__;
	while( begin < end ){	// cppcheck-suppress comparePointers
		*begin = 0;
		begin++;
	}
#endif		
//############# begin to run main function	#############//		
#if 0
    /** Set access period of BKP to 4 */
    /*Read register*/
    tmpReg = HWREG(0x402000B8U);
    /*Set mask -- ARKEY, CDMALDC<1:0>, CDMADC*/
    regMask = 0xFFFF0000U | (3U << 9U) | (1U << 7U);
    /*Clear ARKEY, CDMALDC<1:0>, CDMADC*/
    tmpReg &= ~regMask;
    /*Write ARKEY*/
    tmpReg |= 0x05FA0000U;
    /*Write SYS_ARCTL register*/
    HWREG(0x402000B8U) = tmpReg;
    asm("NOP");
#endif

    // __start_check_ram();
    main();
    while (1)
    {
        asm("NOP");
    }
}

static void __start_check_ram(void)
{
    unsigned int *s;
    unsigned int *begin;
    unsigned int *end;

    /* Check data section */
    s     = (unsigned int *)&__data_load_start__;
    begin = (unsigned int *)&__data_start__;
    end   = (unsigned int *)&__data_end__;
    while (begin < end)
    {
        if (*begin != *s)
        {
            asm volatile("RESET");
            asm volatile("NOP");
        }
        begin++;
        s++;
    }

    /* Check bss section */
    begin = (unsigned int *)&__bss_start__;
    end   = (unsigned int *)&__bss_end__;
    while (begin < end)
    {
        if (*begin != 0)
        {
            asm volatile("RESET");
            asm volatile("NOP");
        }
        begin++;
    }
}

// ####################################################################//
