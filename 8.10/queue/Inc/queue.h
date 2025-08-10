#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

#define QUEUE_MAX 4
typedef struct Queue
{
    int data[QUEUE_MAX];
    uint8_t Front;
    uint8_t Rear;
}queue;

void Queue_Init(queue *q);
bool Queue_IsEmpty(queue *q);
bool Queue_IsFull(queue *q);
bool Queue_Enqueue(queue *q,int value);
bool Queue_Dequeue(queue *q,int *value);


#endif