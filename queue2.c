#include<stdio.h>
#include "queue2.h"

void createQueue(Queue *q)
{
    q->front=0;
    q->rear=MAX-1;
    q->size=0;
}
int isQueueEmpty (Queue q)
{
    return(q.size==0);
}

int  isQueueFull (Queue q)
{
    return(q.size==MAX);
}

void Enqueue(Type item,Queue *q)
{   if(isQueueFull(*q))
       printf("Error: the queue is full.\n");

    else
    {
         q->rear=(q->rear+1)%MAX;
         q->entry[q->rear]=item ;
         q->size++ ;
    }
}

Type Dequeue(Queue *q)
{
    Type item;
    if(isQueueEmpty(*q))
        printf("Error: the queue is Empty.\n");

    else
    {
         item =q->entry[q->front] ;
         q->front=(q->front+1)%MAX;
         q->size--;
    }

    return item ;
}
//Question 2`
Type returnLastElement (Queue *q)
{

    if (isQueueEmpty( *q)){
        printf("Error: the Queue is Empty.\n");
        return -1;
    }

    return q->entry[q->rear];


}
//Question 3
Type copyFirstElement (Queue *q)
{

    if (isQueueEmpty(*q)){
        printf("Error: the Queue is Empty.\n");
        return -1;
    }

    return q->entry[q->front];

}
//Question  4
void destroyQueue(Queue *q)
{     q->front=0;
      q->rear=MAX-1;
      q->size=0;
}

//Question  5
void copyQueue( Queue *q1 ,Queue *q2 )
{
      q2->front=q1->front;
      q2->rear=q1->rear;
      q2->size=q1->size;
for(int i=0 ;i < MAX; i++)
{
  q2->entry[i]=q1->entry[i];
}
}

//Question 6
int returnSize(Queue *q )
{
    return q->size ;
}


//Question 7
Type getLastElement_UserLevel(Queue *q)
{    Queue tempQ;
     createQueue(&tempQ);

     Type currentElement;
     Type lastElement = -1;


    if (isQueueEmpty(*q)) {
        printf("Error: the Queue is Empty.\n");
        return -1;
    }


    while (!isQueueEmpty(*q)) {
        currentElement=Dequeue(q);
        Enqueue(currentElement,&tempQ);
        lastElement = currentElement;
    }

    while (!isQueueEmpty(tempQ)) {
        currentElement=Dequeue(&tempQ);
        Enqueue(currentElement,q);
    }

    return lastElement;
}


Type getFirstElement_UserLevel(Queue *q) {
    Queue tempQ;
    createQueue(&tempQ);

    Type firstElement = -1;
    Type currentElement;

    if (isQueueEmpty(*q)) {
        printf("Error: the Queue is Empty.\n");
        return -1;
    }

    currentElement = Dequeue(q);
    firstElement = currentElement;

    Enqueue(firstElement, &tempQ);

    while (!isQueueEmpty(*q)) {
        currentElement = Dequeue(q);
        Enqueue(currentElement, &tempQ);
    }

    while (!isQueueEmpty(tempQ)) {
        currentElement = Dequeue(&tempQ);
        Enqueue(currentElement, q);
    }

    return firstElement;
}


//Question 9

void destroyQueue_User(Queue *q){

    while(!isQueueEmpty(*q)){
        Type element=Dequeue(q);
    }

}

//Question 10

void copyQueue_User(Queue *src, Queue *dst) {
    Queue tempQ;
    Type currentElement;

    createQueue(&tempQ);
    createQueue(dst);

    while (!isQueueEmpty(*src)) {
        currentElement=Dequeue(src);
        Enqueue(currentElement, dst);
        Enqueue(currentElement, &tempQ);
    }

    while (!isQueueEmpty(tempQ)) {
        currentElement=Dequeue(&tempQ);
        Enqueue(currentElement, src);
    }
}

//Question 11

int sizeQueue_User(Queue *q){

  Queue tempQ;
  Type currentElement;
  int count=0;

  createQueue(&tempQ);


  while (!isQueueEmpty(*q)) {
        currentElement=Dequeue(q);
        Enqueue(currentElement, &tempQ);
        count++;
    }

    while (!isQueueEmpty(tempQ)) {
        currentElement=Dequeue(&tempQ);
        Enqueue(currentElement, q);
    }

    return count ;
}















//Question 13
Queue mergeQueues(Queue sectionCodes, Queue groupCodes) {
    Queue mergedQueue;
    createQueue(&mergedQueue);

    Type secCode, grpCode, mergedCode;

    Queue tempSec = sectionCodes;
    Queue tempGrp = groupCodes;


    while (!isQueueEmpty(tempSec) && !isQueueEmpty(tempGrp)) {

        secCode = Dequeue(&tempSec);
        grpCode = Dequeue(&tempGrp);

        mergedCode = (secCode * 10) + grpCode;

        Enqueue(mergedCode,&mergedQueue);
    }

    return mergedQueue;
}

