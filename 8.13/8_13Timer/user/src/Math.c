#include "Math.h"

//角弧度互换
float Deg2Rad(float deg)
{
	return (deg * PI / 180.0f);
}

float Rad2Deg(float rad)
{
	return (rad * 180.0f / PI);
}

//绝对值
float Abs(float x)
{
	return (x >= 0.0f) ? x : -x;
}

//取符号
int Sign(float x)
{
	return (x >= 0.0f) ? 1 : -1;
}

//最大最小
float Max(float a, float b)
{
	return (a >= b) ? a : b;
}

float Min(float a, float b)
{
	return (a >= b) ? b : a;
}

//平方
float Squ(float x)
{
	return x * x;
}
