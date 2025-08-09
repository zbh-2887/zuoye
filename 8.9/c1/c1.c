#include <stdio.h>
#include <string.h>
#include <stdint.h>

void storeFloats(float f1, float f2, char arr[4]) 
{
    // 将float转换为int，截取整数部分，uint16_t占2个字节，int一般占4个
	uint16_t f1_compressed = (uint16_t)(f1 * 100); // 保留2位小数精度，减小误差
    uint16_t f2_compressed = (uint16_t)(f2 * 100); 
    
    // 将两个16位整数存入4字节char数组
    arr[0] = f1_compressed >> 8;  // f1高字节
    arr[1] = f1_compressed;         // f1低字节
    arr[2] = f2_compressed >> 8;  // f2高字节
    arr[3] = f2_compressed;         // f2低字节
}

// 从4字节char数组中提取两个float
void extractFloats(char arr[4], float* f1, float* f2) //用指针直接修改，不用再返回值
{
    // 从数组中重建两个16位整数
    uint16_t f1_compressed = ((uint16_t)((uint8_t)arr[0]) << 8) | (uint8_t)arr[1];//字符转为uint8_t，再转为uint16_t，再移动，再合并
    uint16_t f2_compressed = ((uint16_t)((uint8_t)arr[2]) << 8) | (uint8_t)arr[3];//移位操作的优先级高于强制类型转换‌
    
    // 转换为float并恢复小数位
    *f1 = (float)f1_compressed * 0.01;
    *f2 = (float)f2_compressed * 0.01;
}

int main() 
{
    float original_f1 = 59.622f;
    float original_f2 = 92.6327f;
    char storage[4];
    
    // 存储两个float
    storeFloats(original_f1, original_f2, storage);
    
    // 提取两个float
    float extracted_f1, extracted_f2;
    extractFloats(storage, &extracted_f1, &extracted_f2);
    
    // 计算误差
    float error_f1 = original_f1 - extracted_f1;
    float error_f2 = original_f2 - extracted_f2;
    
    printf("原始值: %.4f, %.4f\n", original_f1, original_f2);
    printf("提取值: %.4f, %.4f\n", extracted_f1, extracted_f2);
    printf("误差: %.4f, %.4f\n", error_f1, error_f2);
    
    return 0;
}