#include <stdio.h>
#include "vector3f.h"

int main() {
    // 定义正方体顶点坐标（棱长为1）
    vector3f A = {0.0f, 0.0f, 0.0f};
    vector3f B = {1.0f, 0.0f, 0.0f};
    vector3f C = {1.0f, 1.0f, 0.0f};
    vector3f D = {0.0f, 1.0f, 0.0f};
    vector3f A1 = {0.0f, 0.0f, 1.0f};
    vector3f B1 = {1.0f, 0.0f, 1.0f};
    vector3f C1 = {1.0f, 1.0f, 1.0f};
    vector3f D1 = {0.0f, 1.0f, 1.0f};

    // 定义中点
    vector3f E = {0.5f, 0.0f, 1.0f}; // A1B1的中点
    vector3f F = {0.5f, 0.0f, 0.0f}; // AB的中点

    // (1) 求点B到直线AC1的距离
    vector3f AC1_dir = vector_sub(C1, A); // AC1的方向向量
    float dist_B_to_AC1 = distance_point_to_line(B, A, AC1_dir);
    printf("(1) B-AC1: %.4f\n", dist_B_to_AC1);

    // (2) 求直线FC到平面AEC1的距离
    vector3f FC_dir = vector_sub(C, F); // FC的方向向量
    vector3f AE = vector_sub(E, A);
    vector3f AC1 = vector_sub(C1, A);
    vector3f plane_normal = vector_cross(AE, AC1); // 平面AEC1的法向量
    float dist_FC_to_plane = distance_line_to_plane(F, FC_dir, A, plane_normal);
    printf("(2) FC-AEC: %.4f\n", dist_FC_to_plane);

    return 0;
}