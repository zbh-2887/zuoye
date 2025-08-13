#include "MSG.h"

// 16位整数转字节数组
void MSG_Int162Byte(int16_t data, uint8_t *buff, uint8_t i) {
    buff[i]     = (uint8_t)(data & 0xFF);
    buff[i + 1] = (uint8_t)(data >> 8);
}

// 32位整数转字节数组
void MSG_Int322Byte(int32_t data, uint8_t *buff, uint8_t i) {
    buff[i]     = (uint8_t)(data & 0xFF);
    buff[i + 1] = (uint8_t)((uint32_t)data >> 8 & 0xFF);
    buff[i + 2] = (uint8_t)((uint32_t)data >> 16 & 0xFF);
    buff[i + 3] = (uint8_t)((uint32_t)data >> 24);
}

// 浮点数转字节数组
void MSG_Float2Byte(float data, uint8_t *buff, uint8_t i) {
    uint8_t *p = (uint8_t*)&data;
    buff[i]     = p[0];
    buff[i + 1] = p[1];
    buff[i + 2] = p[2];
    buff[i + 3] = p[3];
}

// 字节数组转16位有符号整数
int16_t MSG_Byte2Int16(uint8_t *buff, uint8_t i) {
    return (int16_t)((buff[i + 1] << 8) | buff[i]);
}

// 字节数组转16位无符号整数
uint16_t MSG_Byte2UInt16(uint8_t *buff, uint8_t i) {
    return (uint16_t)((buff[i + 1] << 8) | buff[i]);
}

// 字节数组转32位有符号整数
int32_t MSG_Byte2Int32(uint8_t *buff, uint8_t i) {
    return (int32_t)((buff[i + 3] << 24) | (buff[i + 2] << 16) | (buff[i + 1] << 8) | buff[i]);
}

// 半精度浮点转单精度浮点
float MSG_Byte2Float16(uint8_t *buff, uint8_t i) {
    uint16_t half = (buff[i + 1] << 8) | buff[i];
    uint16_t sign = (half >> 15) & 0x0001;
    uint16_t exp  = (half >> 10) & 0x001F;
    uint16_t frac = half & 0x03FF;
    float result;

    if (exp == 0) {
        // 次正规数
        result = (frac ? (frac / 1024.0f) * (1.0f / (1 << 14)) : 0.0f);
    } else if (exp == 31) {
        // 无穷大 或 NaN
        result = (frac ? (0.0f / 0.0f) : (1.0f / 0.0f)); 
    } else {
        // 正常数
        result = (1.0f + frac / 1024.0f) * (1 << (exp - 15));
    }

    return sign ? -result : result;
}

// 单精度浮点转 float
float MSG_Byte2Float32(uint8_t *buff, uint8_t i) {
    float f;
    uint8_t *p = (uint8_t*)&f;
    p[0] = buff[i];
    p[1] = buff[i + 1];
    p[2] = buff[i + 2];
    p[3] = buff[i + 3];
    return f;
}

// 32位整数大小端交换
int32_t MSG_SwapEndian32(int32_t data) {
    return ((data & 0x000000FF) << 24) |
           ((data & 0x0000FF00) << 8)  |
           ((data & 0x00FF0000) >> 8)  |
           ((data & 0xFF000000) >> 24);
}

// 16位整数大小端交换
int16_t MSG_SwapEndian16(int16_t data) {
    return (int16_t)(((data & 0x00FF) << 8) | ((data & 0xFF00) >> 8));
}

// 字节数组指定元素大小端交换
void MSG_SwapEndianByte(uint8_t *buff, uint8_t elementsize, uint8_t i) //elementsize：要交换的元素大小，比如 2 表示 2 字节
{
    uint8_t temp;
    for (uint8_t j = 0; j < elementsize / 2; j++) {
        temp = buff[i + j];
        buff[i + j] = buff[i + elementsize - 1 - j];
        buff[i + elementsize - 1 - j] = temp;
    }
}
