#include "findroot.h"
int main(int argc, char** argv)
{
    double a, b, result, eps;
    if (argc < 4)
    {
        printf("Usage: %s a b eps\n", argv[0]);
        return 1;    
    }
    a = atof(argv[1]);
    b = atof(argv[2]);
    eps = atof(argv[3]);
    result = biss( a, b, eps, f);
    if ( sign( f( result + eps/2 ) ) == sign( f( result - eps/2 ) ) )
    {        
        printf ("This method can't be used \n");  
    }
    else
    {  
        printf("The result is: %.16lf \n", result);
    }
     
    return 0;
}
