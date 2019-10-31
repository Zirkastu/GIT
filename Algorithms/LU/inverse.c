#include "solve.h"
#include <stdlib.h>
void inverse(double** a, int size,double** inv)
{
    int i,j,k;
    double* b;
    double* x;
   
    b = (double*)malloc (size* sizeof(double));
    x = (double*)malloc (size* sizeof(double));
   
    for (i=0;i<size;i++)
    {
        b[i]=0;
    }    
    for (i=0;i<size;i++)
    {
        b[i]=1;
        if (i!=0)
            b[i-1]=0;        
        Solve(a,b,x,size); 
        for (j=0;j<size;j++)
        {
            inv[j][i]=x[j];       
        } 
        
    }
} 
