#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于qsort
int compare_floats(const void *a, const void *b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

int main() {
    float *numbers = NULL;  // 动态数组指针
    int count = 0;          // 当前元素数量
    int capacity = 10;      // 初始容量
    float input;

    // 初始分配内存
    numbers = (float*)malloc(capacity * sizeof(float));//mallo返回指向分配内存 起始 地址的void*类型指针，需通过类型转换匹配目标类型‌

    if (numbers == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    printf("please inpute\n");

    while (scanf("%f", &input) == 1) {
        // 如果数组已满，扩大容量
        if (count >= capacity) {
            capacity *= 2;
            float *temp = (float*)realloc(numbers, capacity * sizeof(float));//re alloc保留原有数据，重新分配内存
            if (temp == NULL) {
                printf("内存分配失败！\n");
                free(numbers);
                return 1;
            }
            numbers = temp;//直接赋值无法处理分配失败的情况，程序可能继续使用无效的NULL指针，导致崩溃
        }
        numbers[count++] = input;//*(numbers + 1)？取地址？
    }

    // 清除输入缓冲区
    while (getchar() != '\n');

    // 使用qsort排序
    qsort(numbers, count, sizeof(float), compare_floats);

    // 输出排序结果
    printf("\nresult:\n");
    for (int i = 0; i < count; i++) {
        printf("%g ", numbers[i]);
    }
    printf("\n");

    // 释放内存
    free(numbers);

    return 0;
}