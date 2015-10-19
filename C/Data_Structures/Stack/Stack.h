#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <assert.h>

typedef int STACK_TYPE;

typedef struct Stack
{
    int size;
    STACK_TYPE *mem,*top;
}Stack;

Stack * St_Create(int);
void St_Push(Stack* ,STACK_TYPE );
void St_Pop(Stack* ,STACK_TYPE* );
void St_destroy(Stack*);

#endif



