#include <stdlib.h>
#include "operations.h"
#include <math.h>
void Multi(double**, double *,double *,int);
double Scalar(double* ,double* ,int);
void Multi(double**a, double*x,double* y,int size)
{
    int i,j;
    for (i = 0; i<size; i++ )  
    {
        y[i]=0.;        
        for (j = 0;j<size; j++ )  
        {            
           y[i]=y[i]+a[i][j]*x[j]; 
        }       
    
     }
  
}
double Scalar(double* a,double* b,int size)
{
    int i;
    double s=0;
    for (i=0;i<size;i++ )
    {
        s=s+a[i]*b[i];
    }
    return s;  
}


double lmax(double** a, int size)
{
    double* x;
    double* y;
    double* z;
    int i,j;
    double l,lp,s;
    x = (double*)malloc (size* sizeof(double));
    y = (double*)malloc (size* sizeof(double));
    z = (double*)malloc (size* sizeof(double));
    for (i=0;i<size;i++)
       x[i]=1.;
    lp=0.;l=1.;z[1]=1.;        
    while (fabs(lp-l)>0.0001)
    {
       Multi (a,x,y,size); 
       lp=l;              
       l=Scalar(y,x,size);
       s=Scalar(x,x,size);
       l=l/s;
       for (i=0;i<size;i++)
       {
           x[i]=y[i];
       }                 
     
    }
    return l;
}

double lmin(double** a, int size)
{
    double* x;
    double* y;
    double* z;
    int i,j;
    double l,lp,s;
    x = (double*)malloc (size* sizeof(double));
    y = (double*)malloc (size* sizeof(double));
    z = (double*)malloc (size* sizeof(double));
    for (i=0;i<size;i++)
       x[i]=1.;
    lp=0.;l=1.;z[1]=1.;        
    while (fabs(lp-l)>0.0001)
    {
       s=Scalar(x,x,size);
       Multi (a,x,y,size); 
       lp=l;              
       l=Scalar(y,x,size);       
       l=l/s;
       for (i=0;i<size;i++)
       {
           x[i]=y[i];
       }                 
     
    }
    return l;
}

