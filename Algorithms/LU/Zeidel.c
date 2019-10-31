#include "zeidel.h"
#include <math.h>
#include <stdlib.h>
int converge(double *xk, double *xkp,int size)

{

    double norm = 0;
    int i,j;

    for (i = 0; i < size; i++)
    {
        norm = norm + (xk[i] - xkp[i])*(xk[i] - xkp[i]);
    }
    if (sqrt(norm)<eps)
        return 0;
    else
        return 1;

}




void Zeidel(double** a,int size,double* x,double* b)
{
    double* p;
    double var;
    int i,j;
    p = (double*)malloc (size* sizeof(double));
    for (i=0;i<size;i++)
    {
       x[i]=0;       
    }
    do
    {
        for (i = 0; i < size; i++)
            p[i] = x[i];
        for (i = 0; i < size; i++)
        {
            var=0;    
            for (j = 0; j < i; j++)
            {
                var = var + (a[i][j] * x[j]);
            }
            for (j = i + 1; j < size; j++)
            {
                var = var + (a[i][j] * p[j]);
            }
            x[i] = (b[i] - var) / a[i][i];
        }
        
    }
    while (converge(x, p,size));
    free(p);
}

