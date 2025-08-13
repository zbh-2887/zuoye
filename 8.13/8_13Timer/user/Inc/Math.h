#ifndef __MATH_H
#define __MATH_H

#include <stdint.h>

#define PI 3.14159265358979323846f

//角弧度互换
float Deg2Rad(float deg);
float Rad2Deg(float rad);
//绝对值
float Abs(float x);
//取符号
int Sign(float x);
//限制范围
float Peak(float x, float y);
//最大最小
float Max(float a, float b);
float Min(float a, float b);
//平方
float Squ(float x);

#endif
