#define eps 0.000001
#include <math.h>
#include <stdlib.h>
double dfunc (double ,double*  , int );
double func (double ,double*  , int );
void DP (double* ,double* ,int);
double Newton(double ,double* ,int );
int ROOTS(double* p ,double* x0 ,int n)
{
    int i;
    double D;
    double p0[n-1];
    double x01[n-1];
    if (n==2)
    {
        D=p[1]*p[1] - 4*p[0]*p[2];
        x0[0]=(-p[1] - sqrt(D))/(2*p[0]);
        x0[1]=(-p[1] + sqrt(D))/(2*p[0]);
        return 0;  
    }
   // p0 = (double*)malloc((n-1)* sizeof(double));
   // x01 = (double*)malloc((n-1)* sizeof(double));
    DP (p,p0,n);
    ROOTS(p0,x01,n-1);
    D=(-10+x01[0])/2;
    x0[0]=Newton(D,p, n);
    for (i=1;i<=n-2;i++)
    {
        D=(x01[i]+x01[i-1])/2;
        x0[i]=Newton(D, p , n);
    }
    D=(x01[n-2]+10)/2;
    x0[n-1]=Newton(D, p, n);
  //  free (p0);
   // free (x01);
    return 0;     
}



double Newton(double x0,double* p,int n)  // x0 - начальное приближение ,func -функция корни которой ищем.
{ 
    
  double x1  = x0 - func(x0,p,n)/dfunc(x0,p,n); // первое приблжение
  while (fabs(x1-x0)>eps) 
  { 
    x0 = x1;
    x1 = x1 - func(x1,p,n)/dfunc(x1,p,n); // последующие приближения
  }
  return x1;
}

  
double func (double x,double* p , int n) // n -степень многочлена, p -массив коэффицентов
{
    int i;
    double l=0.0;
    for (i=0;i<=n;i++)
    {
        l=l+p[i]*pow(x,n-i);
    }
    return l;
}
double dfunc (double x,double* p , int n) // n -степень многочлена, p -массив коэффицентов
{
    int i;
    double l=0.0;
    for (i=0;i<=n-1;i++)
    {
        l=l+p[i]*pow(x,n-i-1)*(n-i);
    }
    return l;
}

void DP (double* p,double* p0,int n)
{
    int i;
    for (i=0;i<=n-1;i++)
       p0[i]=p[i]*(n-i);
}
