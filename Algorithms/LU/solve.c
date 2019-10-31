    #include "LU.h"
    #include <stdlib.h>
    void Solve(double** a,double* b,double* x,int size)
    {   
        double* y;  
        double**U;
        double**L;   
        L = (double**)malloc(size* sizeof(double*));
        U = (double**)malloc(size* sizeof(double*));        
        y = (double*)malloc (size* sizeof(double));
        int i,j;
        double s;
        for (i = 0; i<size; i++)  
        {
            L[i] = (double*)malloc((size)* sizeof(double));
        }
    
        for (i = 0; i<size; i++)  
        {
            U[i] = (double*)malloc((size) * sizeof(double));     
        }
        LU(a, L, U, size);
        for (i=0;i<size;i++)
        {
            for (j=0;j<i;j++)
            {
                s=s+L[i][j]*y[j];
            }           
            y[i]=(b[i]-s);
            s=0.;
        }
        s=0.;
        for (i=size-1;i>=0;i--)
        {
            for (j=size-1;j>i;j--)
            {
                s=s+U[i][j]*x[j];
            }           
            x[i]=(y[i]-s)/U[i][i];
            s=0.;
        }
}

