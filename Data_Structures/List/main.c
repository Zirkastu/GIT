#include "List.h"
#include <stdio.h>
int main(void)
{
  
  List* l;
  Item* it;
  Item* d;  
  l=Li_Create();
  it=It_Create(1);
  Li_InsAfter(l,it);
  it=It_Create(2);
  Li_InsAfter(l,it);
  it=It_Create(3);
  Li_InsAfter(l,it);
  it=It_Create(4);
  Li_InsAfter(l,it);  
  Li_StepForward(l);
  Li_StepForward(l);
  Li_StepForward(l);  
  
  d=Li_CutBefore(l);  
  printf ("d=%d \n",d->value);
  d=Li_CutAfter(l);
  printf ("d=%d \n",d->value);
  Li_Destroy(l); 
  return 0;
}
