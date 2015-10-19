#include "stack.h"
#include <stdlib.h>
Stack * St_Create(int maxsize)
{
    Stack *st;
    st = (Stack*) malloc (sizeof(Stack)); 
    assert(st);     
    st->size=0;
    st->mem=malloc(sizeof(STACK_TYPE)*maxsize);
    if (st->mem==NULL)
    {
        free(st);
        assert(st->mem);
    }    
    st->top = st->mem+maxsize;
    return st;
}
void St_Push (Stack *st,STACK_TYPE value)
{
    assert ( st->mem - st->top );    
    st->top=st->top-1; 
    *(st->top)=value;     
    st->size=st->size+1;    
}
void St_Pop (Stack *st,STACK_TYPE * dst)
{
    assert (st->size);    
    *dst=*(st->top);
    st->top = st->top + 1;
    st->size = st->size - 1;    
}
void St_destroy (Stack *st)
{
    assert(st);
    assert(st->mem);   
    free(st->mem);     
    free (st);      
}    
    

    
