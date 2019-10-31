#include "Stack.h"
int main(void)
{
  
  Stack* s;
  STACK_TYPE d;   
  s=St_Create (3);  
  St_Push(s,5);  
  St_Push(s,1);  
  St_Push(s,2);  
  St_Pop (s,&d);  
  St_Pop (s,&d);  
  St_Pop (s,&d); 
  printf ("d=%d \n",d); 
  St_destroy(s);   
  return 0;
}
