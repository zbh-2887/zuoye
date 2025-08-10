#include <stdio.h>
#include <queue.h>

void Queue_Init(queue *q)
{
    q->Front = q->Rear = 0;
    for(int i = 0 ; i < QUEUE_MAX ; i++)
    {
        q->data[i] = 0;
    }
}

bool Queue_IsEmpty(queue *q)
{
    return(q->Front == q->Rear);
}

bool Queue_IsFull(queue *q)
{
    return(((q->Rear + 1) % QUEUE_MAX) == q->Front);
}

bool Queue_Enqueue(queue *q,int value)//入的时候尾动
{
    if(Queue_IsFull(q))
        return false;
    q->data[q->Rear] = value;
    q->Rear = (q->Rear + 1) % QUEUE_MAX;//走完一圈再从新开始
    return true;
}

bool Queue_Dequeue(queue *q,int *value)//先入先出，出完头后移
{
    if(Queue_IsEmpty(q))
    {
        printf("Empty");
        return false;
    }
    *value = q->data[q->Front];
    q->Front = (q->Front + 1) % QUEUE_MAX;//走完一圈再从新开始
    return true;
}