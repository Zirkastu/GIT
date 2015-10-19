#ifndef QUEUE_H
#define QUEUE_H

typedef int QUEUE_TYPE;

typedef struct Queue
{
    int size;
    QUEUE_TYPE *mem,*head,*endmem;
}Queue;

Queue * Qu_Create(int maxsize);
void Qu_Push(Queue *qu,QUEUE_TYPE value);
void Qu_Pop(Queue *qu,QUEUE_TYPE *dst);
void Qu_destroy(Queue *qu);

#endif



