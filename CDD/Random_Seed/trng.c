#include "Z20K144M.h"
#include <string.h>
#include "trng.h"
#include "sysctrl_drv.h"

#define TRNG_BASE    TRNG_BASE_ADDR

#define TRNG_STATUS_OFF        0X08
#define TRNG_CONFIG_OFF					0X0C
#define TRNG_CTR_DRBG_CONTROL_OFF	0X10
#define TRNG_CTR_DRBG_REQUEST_SIZE_OFF	0X14
#define TRNG_CTR_DRBG_CONFIG_1_OFF	0X18
#define TRNG_CTR_DRBG_CONFIG_2_OFF	0X1C
#define TRNG_CTR_DRBG_RANDOM_DATA_OFF	0X30
#define TRNG_ADDITIONAN_CONFIG_0_OFF	0X34
#define TRNG_ADDITIONAN_CONFIG_1_OFF	0X38
#define TRNG_ADDITIONAN_CONFIG_2_OFF	0X3C

#define TRNG_REG(off) (*(volatile uint32_t *)(TRNG_BASE_ADDR+(off)))
	

	

#define TRNG_STATUS_RD      (1<<0)
#define TRNG_STATUS_IN      (1<<1)
#define TRNG_DATA_VA				(1<<16)
#define TRNG_DATA_MASK      (0xffff)



#define TRNG_TIMEOUT  (500000)


static void Trng_RegWrite(uint32_t off,uint32_t val)
{
	TRNG_REG(off)=val;
}

static uint32_t Trng_RegRead(uint32_t off)
{
	return TRNG_REG(off);
}



void Trng_Init(void)
{
    SYSCTRL_EnableModule(SYSCTRL_TRNG);
	
		Trng_RegWrite(TRNG_CTR_DRBG_CONFIG_1_OFF,0xffff);
		Trng_RegWrite(TRNG_ADDITIONAN_CONFIG_0_OFF,0x3c0);
	Trng_RegWrite(TRNG_ADDITIONAN_CONFIG_1_OFF,0x400);
	Trng_RegWrite(TRNG_ADDITIONAN_CONFIG_2_OFF,0xffffffff);
	Trng_RegWrite(TRNG_CTR_DRBG_CONFIG_2_OFF,0xffff);
	Trng_RegWrite(TRNG_CTR_DRBG_REQUEST_SIZE_OFF,0xff);
	
    Trng_RegWrite(TRNG_CONFIG_OFF,0xa3);
}

static int Trng_ReadU16(uint16_t *out)
{
    uint32_t t= TRNG_TIMEOUT;
	uint32_t reg;
while(t -- >0)
{
	reg=Trng_RegRead(TRNG_CTR_DRBG_RANDOM_DATA_OFF);
	if((reg&TRNG_DATA_VA)!=0)
	{
		*out = (uint16_t)(reg & TRNG_DATA_MASK);
		return 0;
	}
}

    return -1;
}

int Trng_GetRandom(uint8_t *buf,uint32_t len)
{
    uint32_t i=0;
    if((buf == NULL)||(len == 0))
    return -1;
    
    while(i < len)
    {
				uint16_t w;
        uint32_t n;
       if ( Trng_ReadU16(&w)!=0)
        return -1;
				
        n=(len - i>2)? 2: 1;
				buf[i]=(uint8_t)(w & 0xff);
				i++;
				if(n == 2)
				{
					buf[i]=(uint8_t) (w>>8);
					i++;
				}
			
    }
    return TRNG_OK;
}