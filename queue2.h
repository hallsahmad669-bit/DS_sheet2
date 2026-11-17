#ifndef QUEUE2_H_INCLUDED
#define QUEUE2_H_INCLUDED
#define MAX 100

typedef int Type ;
typedef struct queue{
    int front ;
    int rear  ;
    int size  ;
    Type entry[MAX];
}Queue;

void createQueue(Queue *q);
int isQueueEmpty (Queue q);
int  isQueueFull (Queue q);
void Enqueue(Type item,Queue *q);
Type Dequeue(Queue *q);
Type returnLastElement (Queue *q);
Type copyFirstElement (Queue *q);
void destroyQueue(Queue *q);
void copyQueue( Queue *q1 ,Queue *q2 );
int returnSize(Queue *q );
Type getLastElement_UserLevel(Queue *q);
Type getFirstElement_UserLevel(Queue *q);
void destroyQueue_User(Queue *q);
void copyQueue(Queue *src, Queue *dst);
int sizeQueue_User(Queue *q);

Queue mergeQueues(Queue sectionCodes, Queue groupCodes);





#endif // QUEUE2_H_INCLUDED
