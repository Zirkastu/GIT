#include "queue.h"
#include <stdio.h>
#include <assert.h>
int main(void)
{
  
  Queue* s;
  QUEUE_TYPE d;    
  s=Qu_Create (3);  
  assert(s);
  Qu_Push(s,3);  
  Qu_Push(s,2);  
  Qu_Pop(s,&d);  
  Qu_Pop(s,&d);  
  Qu_destroy(s);
  printf("Dst= %d",d);
  return 0;
}
