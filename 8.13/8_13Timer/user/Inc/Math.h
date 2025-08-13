#ifndef __MATH_H
#define __MATH_H

#include <stdint.h>

#define PI 3.14159265358979323846f

//�ǻ��Ȼ���
float Deg2Rad(float deg);
float Rad2Deg(float rad);
//����ֵ
float Abs(float x);
//ȡ����
int Sign(float x);
//���Ʒ�Χ
float Peak(float x, float y);
//�����С
float Max(float a, float b);
float Min(float a, float b);
//ƽ��
float Squ(float x);

#endif
