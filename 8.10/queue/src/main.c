#include <stdio.h>
#include "queue.h"

queue Aq;
int result = 0;
int main()
{
    Queue_Init(&Aq);
    for(int i = 0 ; i < QUEUE_MAX ; i++)
    {
        Queue_Enqueue(&Aq,i + 1);
    }
    Queue_Dequeue(&Aq,&result);
    printf("%d",result);
    Queue_Dequeue(&Aq,&result);
    printf("%d",result);
    Queue_Dequeue(&Aq,&result);//提取完了
    printf("%d",result);
    Queue_Dequeue(&Aq,&result);//空
    printf("%d",result);
    return 0;
}