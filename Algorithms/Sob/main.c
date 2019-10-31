#include "solve.h"
#include "inverse.h"
#include "operations.h"
#include "zeidel.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int size=4;
    double** A,B;
    double* B4;
    B4 = (double*)malloc(size* sizeof(double));
    A = (double**)malloc(size* sizeof(double*));
    B = (double**)malloc(size* sizeof(double*));     
    if( A == NULL || B == NULL)
    {
        printf("Can't allocate the memory");
        return 1;
    }
    for (i = 0; i<size; i++) 
    {         
        A[i] = (double*)malloc(size * sizeof(double));
        B[i] = (double*)malloc(size * sizeof(double));        
    }
    A[0][0]=2.2;A[0][1]=1;A[0][2]=0.5;A[0][3]=2;A[1][0]=1;A[1][1]=1.3;A[1][2]=2;A[1][3]=1;A[2][0]=0.5;A[2][1]=2;A[2][2]=0.5;A[2][3]=1.6;A[3][0]=2;A[3][1]=1;A[3][2]=1.6;A[3][3]=2;       
    B[0][3]=1;B[1][3]=1;B[2][3]=1;B[3][3]=1;
    Multiply(A,B,0);
    return 0;
}


