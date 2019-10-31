#include "solve.h"
#include "inverse.h"
#include "operations.h"
#include "zeidel.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{   
    double** a;   
    double** inv;
    double** L;
    double** U;
    double* x;
    double* y;
    double* b;
    double s,Lyamin,Lyamax,s1,s2;
    int size=2,i,j;



    a = (double**)malloc(size* sizeof(double*));   
    b = (double*)malloc (size* sizeof(double));
    x = (double*)malloc (size* sizeof(double));
    y = (double*)malloc (size* sizeof(double));
    inv = (double**)malloc(size* sizeof(double*)); 
    
    
    if(a == NULL || b == NULL || x ==NULL || y == NULL || inv == NULL)
    {
        printf("Can't allocate the memory");
        return 1;
    }
    for (i = 0; i<size; i++) 
    {         
        inv[i] = (double*)malloc(size * sizeof(double));        
    }
    for (i = 0; i<size; i++) 
    {
        
        a[i] = (double*)malloc(size * sizeof(double));
        b[i]=i;
        for (j = 0; j<size; j++)  
        {            
            switch (i-j)
            {
                case 0:
                    a[i][j]=10; //c
                    break;
                case -1:
                    a[i][j]=1; //d
                    break;
                case -2:
                    a[i][j]=0.1;//e
                    break;
                case 2:
                    a[i][j]=0.1;//a
                    break;
                case 1:
                    a[i][j]=1;//b
                    break;        
                default:
                    a[i][j]=0;
                    break;
            }
            
        }
    }
    inverse(a, size,inv);
    L = (double**)malloc(size* sizeof(double*));
    U = (double**)malloc(size* sizeof(double*));
    for (i = 0; i<size; i++) 
    {         
        L[i] = (double*)malloc(size * sizeof(double));
        U[i] = (double*)malloc(size * sizeof(double));         
    }
    LU(a, L,U, size);
    s1=1;
    for (i=0;i<size;i++)        
        s1=s1*U[i][i];
    LU(inv, L,U, size);
    s2=1;
    for (i=0;i<size;i++)
        s2=s2*U[i][i];  
    printf("Число обусловленностей %e",s1*s2);
    printf("\n");
    Solve(a,b,x,size);    
    printf ("Прямой метод\n");    
    printf("---------------------\n");
    for (i = 0; i<size; i++)  
    {
        y[i]=0.;        
        for (j = 0; j<size; j++)  
        {            
           y[i]=y[i]+a[i][j]*x[j] ; 
        }
        printf("R[%d]=",i); 
        printf("%e \n", y[i]-b[i]);
     }
     Zeidel(a,size,x,b);
     printf("Метод Зейделя\n");    
     printf("---------------------\n");
     for (i = 0; i<size; i++)  
     {
        y[i]=0.;        
        for (j = 0; j<size; j++)  
        {            
           y[i]=y[i]+a[i][j]*x[j] ; 
        }
        printf("R[%d]=",i); 
        printf("%e \n", y[i]-b[i]);
     }
     printf("---------\n");
     printf("Лямбды\n");
     Lyamin=1/lmax(inv,size);
     Lyamax=lmax(a,size);
     printf("%e\n",Lyamin);
     printf("%e\n",Lyamax);
     
     /* 
     for (i = 0; i<size; i++)  
     {         
        for (j = 0; j<size; j++)  
        {            
           printf("%le", inv[i][j]);   // Вывод обратной  
        }
		printf("\n");
     }
     */
     inverse(a, size,inv); 
     
            
     return 0;
}


