#include "integrate.h"
double f(double);
double method_simpsona(double a, double b, int N, double f(double))
{
    double h = (b - a)/N, J =f(a) + 4*f(a + h/2) + f(a+h) , S1=f(a+h), S2;
    int i;
    for (i = 1; i < N; i=i+1)
    {
        S2=f(a + (i+1)*h);  
        J = J + S1 + S2 + 4*f(a+i*h+h/2);
        S1=S2;        
    }
    J = J * h/6;
    return J;	
}


