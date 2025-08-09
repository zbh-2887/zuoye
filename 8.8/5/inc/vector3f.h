#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <math.h>

// 定义三维向量结构体
typedef struct {
    float x, y, z;
} vector3f;

// 向量加法
vector3f vector_add(vector3f v1, vector3f v2);

// 向量减法
vector3f vector_sub(vector3f v1, vector3f v2);

// 向量点乘
float vector_dot(vector3f v1, vector3f v2);

// 向量叉乘
vector3f vector_cross(vector3f v1, vector3f v2);

// 向量模长
float vector_magnitude(vector3f v);

// 向量单位化
vector3f vector_normalize(vector3f v);

// 向量数乘
vector3f vector_scale(vector3f v, float k);

// 点到直线的距离
float distance_point_to_line(vector3f point, vector3f line_point, vector3f line_direction);

// 直线到平面的距离
float distance_line_to_plane(vector3f line_point, vector3f line_direction, 
                           vector3f plane_point, vector3f plane_normal);

#endif