#include "Math.h"

//�ǻ��Ȼ���
float Deg2Rad(float deg)
{
	return (deg * PI / 180.0f);
}

float Rad2Deg(float rad)
{
	return (rad * 180.0f / PI);
}

//����ֵ
float Abs(float x)
{
	return (x >= 0.0f) ? x : -x;
}

//ȡ����
int Sign(float x)
{
	return (x >= 0.0f) ? 1 : -1;
}

//�����С
float Max(float a, float b)
{
	return (a >= b) ? a : b;
}

float Min(float a, float b)
{
	return (a >= b) ? b : a;
}

//ƽ��
float Squ(float x)
{
	return x * x;
}
