#include"List.h"

void swap(List*);

void Bubblesort(List* li,int (*cmp)(Item*,Item*))
{    
    int n=0,i,j; 
 
    Li_ToBegin(li);
    Li_StepForward(li);
    while ( Li_AtEnd(li) == 1 )
    {               
        n=n+1;        
        if (cmp(li->pos,li->pos->next) == 1)
        {
            swap(li);    
        }
        Li_StepForward(li); 
        
    }
    for (i = 0; i < n-1; i = i+1)
    {
        for (j = 1,Li_ToBegin(li),Li_StepForward(li) ; j < n - i ; j=j+1)
        {            
            if (cmp(li->pos,li->pos->next) ==  1)
            {
                swap(li);
            }
            Li_StepForward(li);
        }
    }    
}
void swap(List* li)
{    
    Item* tmp;
    tmp = Li_CutAfter(li);
    Li_InsBefore(li, tmp);
    li->pos=tmp;         
}
