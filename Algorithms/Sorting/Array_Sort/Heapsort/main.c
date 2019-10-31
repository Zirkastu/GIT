#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Heapsort.h"

int main(void)
{
         FILE* in,*out;
         int size,i;
         ARRTYPE* a;
         int Sortkey(ARRTYPE ,ARRTYPE );
         double time;
         int t1,t2;

    in=fopen("input9.txt","r");
    if (in==NULL)
    {
        perror("Can't open input.txt");
        return 1;  
    }
    out=fopen("output.txt","w");
    if (out==NULL)
    {
        perror("Can't open output.txt");
        return 1;  
    }
    if (!(fscanf(in, "%d", &size)==1))
    {
        perror("Can't read size of array");
        return 1;
    }
    a=(ARRTYPE*)malloc(size*sizeof(ARRTYPE));
    if(a == NULL)
    {
        printf("Can't allocate the memory");
        return 1;
    }
    
    for (i=0; i<size; i=i+1)
    {
        fscanf(in, "%d", &a[i]);		
    } 
    t1=clock();
    Heapsort(a,size,*Sortkey);
    t2=clock();   
    time=(double)(t2-t1)/CLOCKS_PER_SEC;    
    printf("%.16f\n",time);    
    for (i=0; i<size; i=i+1)
    {        
        fprintf(out,"%d \n", a[i]);
    }
    fclose(in);
    fclose(out);
    free(a);    
    return 0;
}

int Sortkey(ARRTYPE a,ARRTYPE b) //Сортировка по возрастанию
{
    if (a>b)
    {
        return 0;
    }
    return 1;
}