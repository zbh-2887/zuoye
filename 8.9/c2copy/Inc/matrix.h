#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct MParam {
    uint8_t row;
    uint8_t column;
    float **data;
} *Matrix;

// 创建矩阵
Matrix create_matrix(uint8_t row, uint8_t column);

// 从键盘输入矩阵
Matrix input_matrix();

// 打印矩阵
void print_matrix(Matrix mat);

// 矩阵转置
Matrix transpose_matrix(Matrix mat);

// 矩阵乘法
Matrix multiply_matrix(Matrix mat1, Matrix mat2);

// 释放矩阵内存
void free_matrix(Matrix mat);

#endif