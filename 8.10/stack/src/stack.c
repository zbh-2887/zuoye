#include "stack.h"

void Stack_Init(stack *s,int size)
{
    s->base = (char *)malloc(size * sizeof(char));//先创建空间
    s->top = s->base;
    s->size = size;
}

bool Stack_IsEmpty(stack *s)
{
    return(s->base == s->top);
}

bool Stack_IsFull(stack *s)
{
    return(s->top + s->size <= s->base);//top < base
}

bool Stack_Push(stack *s,void *value,int size)
{
    if(Stack_IsFull(s))
        return false;
    s->top -= size;
    memcpy(s->top,value,size);//复制函数void *memcpy(void *destin目标, const void *source来源, size_t n多少字节
    //这是写入，目标是栈
    return true;
}

bool Stack_Pop(stack *s,void *value,int size)
{
    if(s->top + size > s->base)//剩下的不够提取也不行，注意区分
        return false;
    memcpy(value,s->top,size);
    s->top +=size;//注意顺序，与Push不同
    return true;
}

void Stack_Free(stack *s)//清空
{
    free(s->base);
    s->base = NULL;
    s->top = NULL;
}

