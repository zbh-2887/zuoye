#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 创建矩阵
Matrix create_matrix(uint8_t row, uint8_t column) {
    Matrix mat = (Matrix)malloc(sizeof(struct MParam));//创建空间
    if (!mat) return NULL;
    
    mat->row = row;//赋值，->为结构体语法
    mat->column = column;
    
    mat->data = (float **)malloc(row * sizeof(float *));//分配row个float*指针的空间，将 malloc 返回的 void* 转换为 float** 类型
    if (!mat->data) {
        free(mat);
        return NULL;
    }
    
    for (uint8_t i = 0; i < row; i++) {
        mat->data[i] = (float *)malloc(column * sizeof(float));//为第i行分配column个float的空间
        if (!mat->data[i]) {
            // 如果分配失败，释放之前分配的内存
            for (uint8_t j = 0; j < i; j++) {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            return NULL;
        }
    }
    
    return mat;
}

// 从键盘输入矩阵
Matrix input_matrix() {
    uint8_t row, column;
    printf("row:");
    scanf("%hhu", &row);
    printf("column:");
    scanf("%hhu", &column);
    
    Matrix mat = create_matrix(row, column);
    if (!mat) {
        printf("1!\n");
        return NULL;
    }
    
    printf("volume:\n");
    for (uint8_t i = 0; i < row; i++) {
        for (uint8_t j = 0; j < column; j++) {
            scanf("%f", &mat->data[i][j]);
        }
    }
    
    return mat;
}

// 打印矩阵
void print_matrix(Matrix mat) {
    if (!mat) {
        printf("矩阵为空!\n");
        return;
    }
    
    for (uint8_t i = 0; i < mat->row; i++) {
        for (uint8_t j = 0; j < mat->column; j++) {
            printf("%8.2f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// 矩阵转置
Matrix transpose_matrix(Matrix mat) {
    if (!mat) return NULL;
    
    Matrix transposed = create_matrix(mat->column, mat->row);
    if (!transposed) return NULL;
    
    for (uint8_t i = 0; i < mat->row; i++) {
        for (uint8_t j = 0; j < mat->column; j++) {
            transposed->data[j][i] = mat->data[i][j];
        }
    }
    
    return transposed;
}

// 矩阵乘法
Matrix multiply_matrix(Matrix mat1, Matrix mat2) {
    if (!mat1 || !mat2) return NULL;
    if (mat1->column != mat2->row) {
        printf("矩阵维度不匹配，无法相乘!\n");
        return NULL;
    }
    
    Matrix result = create_matrix(mat1->row, mat2->column);
    if (!result) return NULL;
    
    for (uint8_t i = 0; i < mat1->row; i++) {
        for (uint8_t j = 0; j < mat2->column; j++) {
            result->data[i][j] = 0.0f;
            for (uint8_t k = 0; k < mat1->column; k++) {
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
    
    return result;
}

// 释放矩阵内存
void free_matrix(Matrix mat) {
    if (!mat) return;
    
    for (uint8_t i = 0; i < mat->row; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}