#include <stdio.h>
#include "Functions.h"




int Key(Tree* ,Tree* );

int main(void)
{   
    Tree*elem1,*elem2,*root;
    int i,value;
    int a[10];  
    a[0]=rand(0);
    root=Tr_Create(a[0]);  
    for (i=1;i<10;i=i+1)
    {
       // printf("%d \n",i);
        a[i]=rand();
        elem1=Tr_Create(a[i]);
        ST_Add(root,elem1,Key);        
    }
    for (i=0; i<5; i=i+1)
    {
       // printf("%d \n",i);
        elem1=Tr_Create(a[i]);
        elem2=ST_Search(elem1,root,Key);
        if (elem2==NULL)
        {
            printf("ERROR 1\n");
            return 1;
        }        
        root=ST_Cut(elem2,root);
        if ( ST_Search(elem1,root,Key)!=NULL )
        {
            printf("ERROR2 \n");
            return 1;
        }
        Tr_Delete(elem1);
        Tr_Delete(elem2);
    }
    for (i=5; i<10; i=i+1)
    {
        printf("%d \n",i);
        elem1=Tr_Create(a[i]);
        if ( ST_Search(elem1,root,Key)==NULL )
        {
            printf("%d",elem1->value);
            printf("ERROR3 \n");
            return 1;
        }
    }
    for (i=5; i<10; i=i+1)
    {
        elem1=Tr_Create(a[i]);
        elem2=ST_Search(elem1,root,Key);
        if (elem2==NULL)
        {
            printf("ERROR4 \n");
            return 1;
        }        
        root=ST_Cut(elem2,root);
        if ( ST_Search(elem1,root,Key)!=NULL )
        {
            printf("ERROR 5\n");
            return 1;
        }
        Tr_Delete(elem1);
        Tr_Delete(elem2);
     }          
     if (root==NULL)
     {
         printf("It's ok \n");
     }
    
    
    

 
    return 0;   
}
int Key(Tree* a,Tree* b)
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
