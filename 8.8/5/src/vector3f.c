#include <stdio.h>
#include "vector3f.h"

// 向量加法
vector3f vector_add(vector3f v1, vector3f v2) {
    return (vector3f){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

// 向量减法
vector3f vector_sub(vector3f v1, vector3f v2) {
    return (vector3f){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

// 向量点乘
float vector_dot(vector3f v1, vector3f v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 向量叉乘
vector3f vector_cross(vector3f v1, vector3f v2) {
    return (vector3f){
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

// 向量模长
float vector_magnitude(vector3f v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

// 向量单位化
vector3f vector_normalize(vector3f v) {
    float mag = vector_magnitude(v);
    if (mag > 0.0f) {
        return (vector3f){v.x / mag, v.y / mag, v.z / mag};
    }
    return (vector3f){0.0f, 0.0f, 0.0f}; // 零向量无法单位化
}

// 向量数乘
vector3f vector_scale(vector3f v, float k) {
    return (vector3f){v.x * k, v.y * k, v.z * k};
}

// 点到直线的距离
float distance_point_to_line(vector3f point, vector3f line_point, vector3f line_direction) {
    vector3f diff = vector_sub(point, line_point);
    vector3f cross = vector_cross(diff, line_direction);
    return vector_magnitude(cross) / vector_magnitude(line_direction);
}

// 直线到平面的距离
float distance_line_to_plane(vector3f line_point, vector3f line_direction,
                           vector3f plane_point, vector3f plane_normal) {
    vector3f diff = vector_sub(plane_point, line_point);
    float dot = vector_dot(diff, plane_normal);
    return fabsf(dot) / vector_magnitude(plane_normal); // 平行时直接计算垂直距离
}