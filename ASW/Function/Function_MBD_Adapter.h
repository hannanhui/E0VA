

#ifndef FUNCTION_MBD_ADAPTER_H_
#define FUNCTION_MBD_ADAPTER_H_



typedef enum
{
	GasStoragePressure_Init=0,
    GasStoragePressure_Up,		
    GasStoragePressure_Dowm,
}GasStoragePressure_Type;






extern void MBD_Adapter_HW(void);
extern void MBD_Task(void);





#endif





