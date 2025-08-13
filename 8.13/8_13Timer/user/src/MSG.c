#include "MSG.h"

// 16λ����ת�ֽ�����
void MSG_Int162Byte(int16_t data, uint8_t *buff, uint8_t i) {
    buff[i]     = (uint8_t)(data & 0xFF);
    buff[i + 1] = (uint8_t)(data >> 8);
}

// 32λ����ת�ֽ�����
void MSG_Int322Byte(int32_t data, uint8_t *buff, uint8_t i) {
    buff[i]     = (uint8_t)(data & 0xFF);
    buff[i + 1] = (uint8_t)((uint32_t)data >> 8 & 0xFF);
    buff[i + 2] = (uint8_t)((uint32_t)data >> 16 & 0xFF);
    buff[i + 3] = (uint8_t)((uint32_t)data >> 24);
}

// ������ת�ֽ�����
void MSG_Float2Byte(float data, uint8_t *buff, uint8_t i) {
    uint8_t *p = (uint8_t*)&data;
    buff[i]     = p[0];
    buff[i + 1] = p[1];
    buff[i + 2] = p[2];
    buff[i + 3] = p[3];
}

// �ֽ�����ת16λ�з�������
int16_t MSG_Byte2Int16(uint8_t *buff, uint8_t i) {
    return (int16_t)((buff[i + 1] << 8) | buff[i]);
}

// �ֽ�����ת16λ�޷�������
uint16_t MSG_Byte2UInt16(uint8_t *buff, uint8_t i) {
    return (uint16_t)((buff[i + 1] << 8) | buff[i]);
}

// �ֽ�����ת32λ�з�������
int32_t MSG_Byte2Int32(uint8_t *buff, uint8_t i) {
    return (int32_t)((buff[i + 3] << 24) | (buff[i + 2] << 16) | (buff[i + 1] << 8) | buff[i]);
}

// �뾫�ȸ���ת�����ȸ���
float MSG_Byte2Float16(uint8_t *buff, uint8_t i) {
    uint16_t half = (buff[i + 1] << 8) | buff[i];
    uint16_t sign = (half >> 15) & 0x0001;
    uint16_t exp  = (half >> 10) & 0x001F;
    uint16_t frac = half & 0x03FF;
    float result;

    if (exp == 0) {
        // ��������
        result = (frac ? (frac / 1024.0f) * (1.0f / (1 << 14)) : 0.0f);
    } else if (exp == 31) {
        // ����� �� NaN
        result = (frac ? (0.0f / 0.0f) : (1.0f / 0.0f)); 
    } else {
        // ������
        result = (1.0f + frac / 1024.0f) * (1 << (exp - 15));
    }

    return sign ? -result : result;
}

// �����ȸ���ת float
float MSG_Byte2Float32(uint8_t *buff, uint8_t i) {
    float f;
    uint8_t *p = (uint8_t*)&f;
    p[0] = buff[i];
    p[1] = buff[i + 1];
    p[2] = buff[i + 2];
    p[3] = buff[i + 3];
    return f;
}

// 32λ������С�˽���
int32_t MSG_SwapEndian32(int32_t data) {
    return ((data & 0x000000FF) << 24) |
           ((data & 0x0000FF00) << 8)  |
           ((data & 0x00FF0000) >> 8)  |
           ((data & 0xFF000000) >> 24);
}

// 16λ������С�˽���
int16_t MSG_SwapEndian16(int16_t data) {
    return (int16_t)(((data & 0x00FF) << 8) | ((data & 0xFF00) >> 8));
}

// �ֽ�����ָ��Ԫ�ش�С�˽���
void MSG_SwapEndianByte(uint8_t *buff, uint8_t elementsize, uint8_t i) //elementsize��Ҫ������Ԫ�ش�С������ 2 ��ʾ 2 �ֽ�
{
    uint8_t temp;
    for (uint8_t j = 0; j < elementsize / 2; j++) {
        temp = buff[i + j];
        buff[i + j] = buff[i + elementsize - 1 - j];
        buff[i + elementsize - 1 - j] = temp;
    }
}
