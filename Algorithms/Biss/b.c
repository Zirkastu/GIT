#include "findroot.h"
int sign(double x)
{
   if (x > 0)
   {
        return 1;
   }  
   return -1; 
     
}

double biss(double a, double b, double eps, double f(double) )
{
    double s = 0.;
    int sign1 = sign( f( a ) ), sign2 = sign( f( b ) ),sgn = 0;
    while ( fabs(a - b ) >= eps ) 
    {
        s = ( a + b )/2;
        sgn = sign ( f( s ) );
        if (sign1 != sgn )
        {
           b = s;
           sign2 = sgn;
        }
        else
        {
           a = s;
           sign1 = sgn;
        }
    
    }
    return (a + b)/2;
}


