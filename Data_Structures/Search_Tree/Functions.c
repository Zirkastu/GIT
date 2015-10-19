#include "Search_Tree.h"
#include "Functions.h"



void Tr_Scan(Tree*tr, int n,int (*cmp)(Tree*,Tree*))
{
    Tree *elem;
    TREE_TYPE value=0;
    int i;    
    for (i = 0; i < n; i = i + 1)
    {        
        scanf("%d",&value);               
        elem=Tr_Create(value);
        ST_Add(tr,elem,cmp);     
    }
    

}

void Tr_fScan(Tree* tr,char fname[10],int n,int (*cmp)(Tree*,Tree*))
{
    FILE* in;
    TREE_TYPE value;
    Tree* elem;
    int i;
    
    in=fopen(fname,"r");
    if (in==NULL)
    {
        printf("Can't open the file\n");
    }    
    for ( i=0; i<n; i=i+1 )
    {        
        if (fscanf(in, "%d", &value)==EOF)
        {           
           break;           
        }
        elem=Tr_Create(value);
        if ( ST_Search(elem, tr, cmp) == NULL )
        {
            ST_Add(tr,elem,cmp);
        }
        else
        {
            i=i-1;       
        }
    }
    fclose(in);     
}
void FGen(char fname[10],int n)
{
    FILE* out;
    int i;
    int rand(void);
    TREE_TYPE value;

    out=fopen(fname,"w");
    if (out==NULL)
    {
        printf("Can't open the file\n");
    }

    for (i = 0;i < n; i = i + 1 )
    {
        value=rand();
        fprintf(out,"%d \n",value);
    }
    fclose(out);    
}
