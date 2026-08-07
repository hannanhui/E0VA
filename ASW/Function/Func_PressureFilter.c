


#include "include.h"


#include <stdint.h>
//#include <string.h>

#define MAX_SENSORS Digital_Pressure_Index11
#define MAX_WINDOW_SIZE 15

// 自适应窗口滤波器结构体
typedef struct {
    uint32_t buffer[MAX_WINDOW_SIZE];    // 数据缓冲区
    uint32_t sorted[MAX_WINDOW_SIZE];    // 排序后的缓冲区
    uint32_t index;                      // 当前写入位置
    uint32_t window_size;                // 当前窗口大小
    uint32_t count;                      // 当前数据量
    uint32_t last_value;                 // 上一次滤波值
} AdaptiveWindowFilter;

// 初始化滤波器
void adaptive_filter_init(AdaptiveWindowFilter *filter) {
    memset(filter->buffer, 0, sizeof(filter->buffer));
    memset(filter->sorted, 0, sizeof(filter->sorted));
    filter->index = 0;
    filter->window_size = 15;  // 默认窗口大小
    filter->count = 0;
    filter->last_value = 0;
}

// 快速排序的分区函数
int partition(uint32_t *arr, int low, int high) {
    
}

// 快速排序
void quick_sort(uint32_t *arr, int low, int high) {
    
}

// 添加新数据并返回滤波结果
uint32_t adaptive_filter_add(AdaptiveWindowFilter *filter, uint32_t new_value) {
    // 计算与前一个值的差值
   
}

// 10个传感器的滤波器数组
AdaptiveWindowFilter sensor_filters[MAX_SENSORS];

// 初始化所有传感器滤波器
void init_all_filters(void) {
    for (int i = 0; i < MAX_SENSORS; i++) {
        adaptive_filter_init(&sensor_filters[i]);
    }
}

// 获取传感器滤波后的值
uint32_t get_filtered_value(int sensor_id, uint32_t raw_value) {
    if (sensor_id < 0 || sensor_id >= MAX_SENSORS) {
        return raw_value;  // 无效传感器ID，返回原始值
    }
    return adaptive_filter_add(&sensor_filters[sensor_id], raw_value);
}













