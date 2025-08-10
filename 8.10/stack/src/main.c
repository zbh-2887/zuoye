#include <stdio.h>
#include "stack.h"

stack As;
int size = 20;
float val1 = 3.14;
float val2 = 114.514;
float result = 0;
int main(void)
{
    Stack_Init(&As,size);
    Stack_Push(&As,&val1,sizeof(float));
    Stack_Push(&As,&val2,sizeof(float));
    Stack_Pop(&As,&result,sizeof(float));//后入先出
    printf("%.3f",result);
    return 0;
}