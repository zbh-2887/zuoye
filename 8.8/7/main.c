#include <stdio.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

// 大小端转换函数 0x  12  25  36  47，两个一字节
uint32_t swap_endian(uint32_t num) {
    return ((num >> 24) & 0xFF)        |  // 移动最高字节到最低位
           ((num >> 8)  & 0xFF00)      |  // 移动次高字节到次低位
           ((num << 8)  & 0xFF0000)    |  // 移动次低字节到次高位
           ((num << 24) & 0xFF000000);    // 移动最低字节到最高位
}

int main() {
    uint32_t num = 0x12253647;

    // 检测本机字节序
    if (*(uint8_t *)&num == 0x47) {
        printf("little-endian PC\n");
    } else {
        printf("big-endian PC\n");
    }

    // 打印本机字节序下的数据
    printf("origin number: 0x%08X\n", num);

    // 转换为大端模式并打印
    uint32_t big_endian = swap_endian(num);
    printf("big-endian:0x%08X\n", big_endian);

    // 转换为小端模式并打印（如果本机是大端，转换后就是小端）
    uint32_t little_endian = swap_endian(big_endian);
    printf("little-endian:0x%08X\n", little_endian);

    return 0;
}