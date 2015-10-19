#include "List.h"
    
static void Merge(List*, List*, int (*)(Item*,Item*));
void Mergesort(List* li, int (*cmp)(Item*,Item*))
{
    int i, n;
    List* l;
    Li_ToBegin(li);
    n = Li_Count(li);        
    if (n>=2)
    {
        for(i=0;i<n/2+1 ;i=i+1)
        {
            Li_StepForward(li);
        }
        l = Li_Create();
        Li_DivideBefore(li,l);
        Mergesort(li, cmp);
        Mergesort(l, cmp);
        Merge(li, l, cmp);
        Li_Destroy(l);                      
    } 
}

static void Merge(List* li1, List* li2, int (*cmp)(Item*,Item*))
{    
    Item* it;

    Li_ToBegin(li1);
    Li_ToBegin(li2);   
    

    while ( (Li_AtEnd(li1)==1 ) && (Li_AtEnd(li2) == 1) )
    {
        if ( cmp(li1->pos->next,li2->pos->next) == -1 )
        {           
            Li_StepForward(li1);            
        }
        else
        {
            it = Li_CutAfter(li2);
            Li_InsAfter(li1,it);
            Li_StepForward(li1);
            
        }
     }
     if ( Li_AtEnd(li1)==0 )
     {
        while ( Li_AtEnd(li2) == 1 )  
        {
            it = Li_CutAfter(li2);
            Li_InsAfter(li1,it);
            Li_StepForward(li1);            
        }        
     }
     Li_ToBegin(li1);
     Li_ToBegin(li2);     
}
