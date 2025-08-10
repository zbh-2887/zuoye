#include <stdio.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

int main(void)
{
    int num[32];
    uint32_t number = 0;
    for(int i = 0 ; i < 32 ; i++)
    {
        num[i] = rand() % 101;//rand直接随机数
        // printf("%d\n",num[i]);
    }
    for(int i = 0 ; i < 32 ; i++)
    {
        if(num[i] > 50)
            number |= (1 << i);
    }
    printf("%d\n",number);//十进制
    for (int i = 31; i >= 0; i--) //二进制
    {
        printf("%d", (number >> i) & 1);
        if (i % 8 == 0) printf(" "); // 每8位加个空格
    }
}