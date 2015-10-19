#include "List.h"
#include "Functions.h"
int Check(List* li,int (*cmp)(Item*,Item*))
{
    Li_ToBegin(li);
    Li_StepForward(li);
    while(Li_AtEnd(li) == 1)
    {    
        if ( cmp(li->pos,li->pos->next) == 1 )
        {
            printf("It's not OK \n");
            printf("%d",li->pos->value);
            return 1;        
        }
        Li_StepForward(li);
    }
    printf("It's OK \n");
    return 0;
}

void Li_Print(List* li)
{
    Li_ToBegin(li);   
    while( Li_AtEnd(li) == 1 )
    {
        Li_StepForward(li);
        printf("%d \n",li->pos->value);
    }
}
void Li_Scan(List* li,int n)
{
    Item *it,*tmp;
    LIST_TYPE value=0;
    int i;
    tmp=li->pos;
    for (i = 0; i < n; i = i + 1)
    {        
        scanf("%d",&value);               
        it=It_Create(value);
        Li_InsAfter(li,it);
        Li_StepForward(li);
    }
    li->pos=tmp;

}
void Li_fScan(List* li,char fname[10],int n)
{
    FILE* in;
    LIST_TYPE value;
    Item* tmp,*it;
    int i;
    
    in=fopen(fname,"r");
    if (in==NULL)
    {
        printf("Can't open the file\n");
    }
    tmp=li->pos;
    for (i=0;i<n;i=i+1)
    {
        fscanf(in, "%d", &value);
        it=It_Create(value);
        Li_InsAfter(li,it);
        Li_StepForward(li);        
    }
    li->pos=tmp;
    fclose(in);     
}
void FGen(char fname[10],int n)
{
    FILE* out;
    int i;
    int rand(void);
    LIST_TYPE value;

    out=fopen(fname,"w");
    if (out==NULL)
    {
        printf("Can't open the file\n");
    }

    for (i = 0;i < n; i = i + 1 )
    {
        value=rand()%100 +1;
        fprintf(out,"%d \n",value);
    }
    fclose(out);    
}
