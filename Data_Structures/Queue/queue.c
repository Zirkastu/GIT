#include <assert.h>
#include <stdlib.h>
#include "queue.h"

   static QUEUE_TYPE* Next(QUEUE_TYPE*,Queue*);
   static int Qu_Room(Queue*);
   static QUEUE_TYPE* Qu_Tail (Queue*);


static QUEUE_TYPE* Next(QUEUE_TYPE* pos,Queue* qu)
{
    if (pos==qu->endmem)
    {
        return qu->mem;
    }
    return pos+1;
}
static QUEUE_TYPE* Qu_Tail(Queue * qu)
{
    if (qu->size==0)
    {
        qu->head=qu->mem;
        return qu->endmem;
    }
    else
    {
        if (qu->head+qu->size-1 <= qu->endmem)
        {
            return qu->head+qu->size-1; 
        }
        else
        { 
            return qu->mem+qu->size-1-(qu->endmem-qu->head+1);
        }
    }
 }
Queue * Qu_Create(int maxsize)
{
    Queue* qu;    
    qu = (Queue*) malloc (sizeof(Queue)); 
    assert(qu);
    qu->mem=malloc(sizeof(QUEUE_TYPE)*maxsize);
    if (qu->mem == NULL)
         {             
             free(qu);
             return 0;
         }
    qu->size=0;
    qu->head=qu->mem;
    qu->endmem=qu->mem+maxsize-1;    
    return qu;
}
void Qu_Pop (Queue *qu,QUEUE_TYPE * dst)
{
    assert (qu->size);    
    *dst=*(qu->head);
    qu->head=Next(qu->head,qu);
    qu->size=qu->size-1;    
}
void Qu_Push (Queue *qu,QUEUE_TYPE value)
{
        QUEUE_TYPE *tail;

    assert(Qu_Room(qu) - 1);    
    tail=Qu_Tail(qu);
    tail=Next(tail,qu);
    *(tail)=value;
    qu->size=qu->size+1;    
}

void Qu_destroy (Queue *qu)
{
    assert(qu); 
    assert(qu->mem);
    free(qu->mem);        
    free (qu);       
}
static int Qu_Room(Queue* qu)
{     
     if (qu->endmem-qu->mem+1-qu->size==0)
     {
         return 1;
     }
     return 0;   
}    