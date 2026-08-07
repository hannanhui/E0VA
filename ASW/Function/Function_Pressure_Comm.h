

#ifndef FUNCTION_PRESSURE_COMM_H_
#define FUNCTION_PRESSURE_COMM_H_


#define APP_LUMBAR_NUM  2U

#define APP_Flank_NUM  2U


extern uint32_t get_filtered_value(int sensor_id, uint32_t raw_value);


extern void init_all_filters(void);
extern void Func_Pressure_Init(void);
extern	uint16_t Func_Get_Pressure_To_LIN(Digital_Pressure_Index opIndex);
extern uint32_t Func_Get_Pressure_To_MBD(Digital_Pressure_Index opIndex);

extern uint8_t Func_Get_PressureTemperature(Digital_Pressure_Index opIndex);
extern uint8_t Func_Get_NTC_Temperature(void);


extern void Func_Pressure_Task(void);








#endif



