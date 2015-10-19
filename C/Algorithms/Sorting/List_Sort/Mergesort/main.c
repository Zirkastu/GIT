#include <time.h>
#include "Functions.h"

int Sortkey(Item*,Item*);
void Mergesort(List*,int (*)(Item*,Item*));

int main(void)
{    
    List* li;
    double time;
    int t1,t2;      
    
    li=Li_Create();
    FGen("input.txt",1000);
    Li_fScan(li,"input.txt",1000);
    //Li_Print(li);
    t1=clock();        
    Mergesort(li,*Sortkey);
    t2=clock();     
    time=(double)(t2-t1)/CLOCKS_PER_SEC;
    //printf("--------- \n");    
    //Li_Print(li);
    
    //printf("--------- \n");
   
    Check(li,*Sortkey);
    printf("Sorting time: %.16f\n",time); 
    Li_Destroy(li);     
    return 0;
}

int Sortkey(Item* a,Item* b)
{
    if (a->value > b->value)
    {
        return 1; 
    }
    if (a->value < b->value)
    {
        return -1; 
    }
    return 0;
}

