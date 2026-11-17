#include<stdio.h>
#include "queue2.h"

int main()
{
    Queue q;
    createQueue(&q);
    if(!isQueueFull(q))
        Enqueue(1,&q);

    if(!isQueueFull(q))
        Enqueue(2,&q);

    if(!isQueueFull(q))
        Enqueue(3,&q);

    Type lastElement=getLastElement_UserLevel(&q);
    Type firstElement=getFirstElement_UserLevel(&q);
    printf("The Last element is :%d \n",lastElement);
    if (firstElement!=-1){
      printf("The first element is :%d \n",firstElement) ;

    }







   return 0;
}

