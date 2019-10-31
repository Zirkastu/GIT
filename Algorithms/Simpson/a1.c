#include "integrate.h"
#include <stdio.h>
#include <stdlib.h>
double f(double);
int main(int argc, char** argv)
{
    double a,b ,result;
    int N;
    if (argc < 4)
    {
        printf("Usage: %s a b N\n", argv[0]);
        return 1;    
    }
    a = atof(argv[1]);
    b = atof(argv[2]);
    N = atof(argv[3]);
    result = method_simpsona( a, b, N, f );
    printf("The result is: %.16lf\n",result);  
  
    return 0;
}
