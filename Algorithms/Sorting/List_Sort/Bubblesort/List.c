#include <stdlib.h>
#include <assert.h>
#include "List.h"
List * Li_Create(void)
{
    List * li;
    li=(List*)malloc(sizeof(List));       
    li->base.next=li->base.prev=&li->base;
    Li_ToBegin(li);
    return li;
}
Item * It_Create(LIST_TYPE value)
{
 
    Item* tmp;

    tmp=(Item*)malloc(sizeof(Item));
    assert(tmp);
    tmp->value=value;
    tmp->next=NULL;
    tmp->prev=NULL;
    //printf("ALLOC: %p\n", (void*) tmp);
    return tmp;   
}

void It_Delete(Item* it)
{
    assert(it);              
    assert(it->next == NULL);              
    assert(it->prev == NULL);
    //printf("FREE: %p\n", (void*) it);
    free(it);    
}

void Li_Destroy(List *li)
{

    Item* tmp;
    assert(li->base.next);
    Li_ToBegin(li);
    while (li->pos->next!=&li->base)
    {
        tmp=Li_CutAfter(li);
        It_Delete(tmp);        
    }        
    free(li);
}

void Li_InsBefore(List*li,Item* it)
{       
      
    assert(it);
    assert(it->prev == NULL);
    assert(it->next == NULL);
    it->next=li->pos;
    it->prev=li->pos->prev;    
    li->pos->prev->next=it; 
    li->pos->prev=it;    
}

void Li_InsAfter(List*li,Item* it)
{           
    
    assert(it);
    assert(it->prev == NULL);
    assert(it->next == NULL);
    it->prev=li->pos;
    it->next=li->pos->next;
    li->pos->next->prev=it;
    li->pos->next=it;
    
}

void Li_StepForward(List*li)
{
    assert(li->pos->next - &li->base); 
    li->pos=li->pos->next;
}

void Li_StepBackward(List*li)
{
    assert(li->pos->prev - &li->base); 
    li->pos=li->pos->prev;        
}
Item* Li_TakeBefore(List*li)
{
    assert(li->pos->prev-&li->base);
    return li->pos->prev;
}
Item* Li_TakeAfter(List*li)
{
     assert(li->pos->next-&li->base);
     return li->pos->next;
}
Item* Li_CutBefore(List*li)
{
    Item* tmp;
    assert(li->pos->prev - &li->base);
    tmp = li->pos->prev;
    li->pos->prev->prev->next=li->pos;
    li->pos->prev=li->pos->prev->prev;
    tmp->next=NULL;
    tmp->prev=NULL;

    return tmp;
}   

Item* Li_CutAfter(List*li)
{   
    Item* tmp;
    
    assert(li->pos->next - &li->base);
    tmp=li->pos->next;
    li->pos->next->next->prev=li->pos;
    li->pos->next=li->pos->next->next;    
    tmp->next=NULL;
    tmp->prev=NULL;
    
    return tmp;    
}
void Li_DivideBefore(List*li1,List*li2)
{   
 
    assert(li2->base.next != NULL);
    assert(li2->base.prev != NULL);
   
    li1->base.prev->next=&li2->base;
    li2->base.prev=li1->base.prev;
    li1->pos->prev->next=&li1->base;
    li1->base.prev=li1->pos->prev;
    li1->pos->prev=&li2->base;
    li2->base.next=li1->pos;
    Li_ToBegin(li1);
    Li_ToBegin(li2);        
}
int Li_Count(List* li)
{
    Item* tmp;
    int k=0;

    tmp=li->pos;
    Li_ToBegin(li);     
    while (li->pos->next!=&li->base)
    {            
        Li_StepForward(li);       
        k=k+1;
    }
    li->pos=tmp;
    return k;
}
void Li_ToBegin(List* li)
{
assert(li);
li->pos=&li->base;
}    
int Li_AtEnd(List* li)
{
    if (li->pos->next==&li->base)
    {
        return 0;
    }
    return 1;
}    
        
        
 
        

    

