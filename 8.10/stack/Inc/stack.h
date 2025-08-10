#ifndef __STACK_H
#define __STACK_H

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

typedef struct Stack
{
    char *base;//栈底
    char *top;//栈顶
    int size;
}stack;

void Stack_Init(stack *s,int size);
bool Stack_IsEmpty(stack *s);
bool Stack_IsFull(stack *s);
bool Stack_Push(stack *s,void *value,int size);
bool Stack_Pop(stack *s,void *value,int size);
void Stack_Free(stack *s);

#endif
