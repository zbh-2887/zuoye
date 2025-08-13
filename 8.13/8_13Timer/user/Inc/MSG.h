#ifndef __MSG_H
#define __MSG_H

#include <stdint.h>

// 16位整数转字节数组
void MSG_Int162Byte(int16_t data, uint8_t *buff, uint8_t i);

// 32位整数转字节数组
void MSG_Int322Byte(int32_t data, uint8_t *buff, uint8_t i);

// 浮点数转字节数组
void MSG_Float2Byte(float data, uint8_t *buff, uint8_t i);

// 字节数组转16位有符号整数
int16_t MSG_Byte2Int16(uint8_t *buff, uint8_t i);

// 字节数组转16位无符号整数
uint16_t MSG_Byte2UInt16(uint8_t *buff, uint8_t i);

// 字节数组转32位有符号整数
int32_t MSG_Byte2Int32(uint8_t *buff, uint8_t i);

// 半精度浮点（2字节）转单精度浮点
float MSG_Byte2Float16(uint8_t *buff, uint8_t i);

// 单精度浮点（4字节）转浮点
float MSG_Byte2Float32(uint8_t *buff, uint8_t i);

// 32位整数大小端交换
int32_t MSG_SwapEndian32(int32_t data);

// 16位整数大小端交换
int16_t MSG_SwapEndian16(int16_t data);

// 字节数组指定元素大小端交换
void MSG_SwapEndianByte(uint8_t *buff, uint8_t elementsize, uint8_t i);

#endif
