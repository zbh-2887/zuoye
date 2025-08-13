#ifndef __MSG_H
#define __MSG_H

#include <stdint.h>

// 16λ����ת�ֽ�����
void MSG_Int162Byte(int16_t data, uint8_t *buff, uint8_t i);

// 32λ����ת�ֽ�����
void MSG_Int322Byte(int32_t data, uint8_t *buff, uint8_t i);

// ������ת�ֽ�����
void MSG_Float2Byte(float data, uint8_t *buff, uint8_t i);

// �ֽ�����ת16λ�з�������
int16_t MSG_Byte2Int16(uint8_t *buff, uint8_t i);

// �ֽ�����ת16λ�޷�������
uint16_t MSG_Byte2UInt16(uint8_t *buff, uint8_t i);

// �ֽ�����ת32λ�з�������
int32_t MSG_Byte2Int32(uint8_t *buff, uint8_t i);

// �뾫�ȸ��㣨2�ֽڣ�ת�����ȸ���
float MSG_Byte2Float16(uint8_t *buff, uint8_t i);

// �����ȸ��㣨4�ֽڣ�ת����
float MSG_Byte2Float32(uint8_t *buff, uint8_t i);

// 32λ������С�˽���
int32_t MSG_SwapEndian32(int32_t data);

// 16λ������С�˽���
int16_t MSG_SwapEndian16(int16_t data);

// �ֽ�����ָ��Ԫ�ش�С�˽���
void MSG_SwapEndianByte(uint8_t *buff, uint8_t elementsize, uint8_t i);

#endif
