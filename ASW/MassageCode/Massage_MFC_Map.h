

#ifndef __MASSAGE_MAP_H_
#define __MASSAGE_MAP_H_

#define SET_BIT(n) (1UL << (n)) //32�?
#define GET_BIT(var, n) (((var) >> (n)) & 1U)

#define BAG_NULL				(0UL)

#define Knock_PRE_Time				{300, 300, 300}
#define Knock_Inflate_Time				{13, 16, 23}
#define Knock_Deflate_Time				{12, 18, 27}

#define Knock_Async_Inflate_Time	{32, 38, 45}

#define Default_Time				{200, 400, 600}

// #define MassageStepSum(Array) sizeof(Array)/sizeof(Array[0])

typedef enum
{
	BAG_INDEX0=0,
    BAG_INDEX1,		
    BAG_INDEX2,		
    BAG_INDEX3,		
    BAG_INDEX4,
    BAG_INDEX5,		
    BAG_INDEX6,		
    BAG_INDEX7,		
    BAG_INDEX8,
    BAG_INDEX9,		
    BAG_INDEX10,
    BAG_INDEX11,	
    BAG_INDEX12,
    BAG_INDEX13,
    BAG_INDEX14,		
}BAG_INDEX_TYPE;

typedef enum
{
	MSSG_MODE1=0,
    MSSG_MODE2,		
    MSSG_MODE3,		
    MSSG_MODE4,
    MSSG_MODE5,	
    MSSG_MODE6,	
    MSSG_MODE7,	
    MSSG_MODE8,	
    MSSG_MODE_MAX,					
}Massage_Mode_Type;




typedef enum {
	MSSG_ONLY_SINGLE = 0,     //Only Single Run
	MSSG_GROUP_REPEAT_START,       // group repet start Run 
    MSSG_GROUP_REPEAT_MID,       // group repet start Run     
    MSSG_GROUP_REPEAT_END,       // group repet start Run    
    MSSG_INFO_IDLE,       // group repet start Run               
} MassageActiveEvent;

typedef enum
{
	Massage_Strength_1 = 0,		//按摩强度--500ms
	Massage_Strength_2,			//按摩强度--1000ms
	Massage_Strength_3,			//按摩强度--1500ms
	// Massage_Strength_4,			//按摩强度--2000ms
	// Massage_Strength_5,			//按摩强度--2500ms
	// Massage_Strength_6,			//按摩强度--3000ms

	Massage_Strength_Max
} Massage_Strength;

typedef struct 
{
    uint32_t Mapping;
    MassageActiveEvent Action_ID;
    uint16_t KeepTime[Massage_Strength_Max];
    uint8_t RepeatCnt;
}Massage_Parameter;



typedef struct 
{
    Massage_Parameter *pMode;
    uint8_t StepSum;
}Massage_Mode_Info_Type;





#endif




