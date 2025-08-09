#include <stdio.h>
#include "matrix.h"

int main() {
    printf("frist matrix:\n");
    Matrix mat = input_matrix();
    if (!mat) return 1;
    
    printf("\ninitial matrix:\n");
    print_matrix(mat);
    
    Matrix transposed = transpose_matrix(mat);
    if (!transposed) {
        free_matrix(mat);
        return 1;
    }
    
    printf("\nmatrix_T:\n");
    print_matrix(transposed);
    
    Matrix product = multiply_matrix(mat, transposed);
    if (!product) {
        free_matrix(mat);
        free_matrix(transposed);
        return 1;
    }
    
    printf("\nmatrix * matrix_T:\n");
    print_matrix(product);
    
    // 释放内存
    free_matrix(mat);
    free_matrix(transposed);
    free_matrix(product);
    
    return 0;
}