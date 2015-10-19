#include "Quicksort.h"
void Quicksort(ARRTYPE* arr,int size,int (*cmp)(ARRTYPE,ARRTYPE))
{
 
        int p = arr[0];
        int i = 0, j = size - 1;
        ARRTYPE tmp;

    do
    {
        while ( cmp(p,arr[i])==0 )
        {
            i = i + 1;
        }
        while ( cmp(arr[j] , p)==0 )
        {
            j = j - 1;
        }
        if (i <= j)
        {
            tmp = arr[i]; 
            arr[i] = arr[j];
            arr[j] = tmp;
            i = i + 1; 
            j = j - 1;
        }
    }  while (i <= j);

        if ( j > 0 )
        { 
            Quicksort(arr, j+1,cmp);
        }

        if ( size - 1 > i )
        { 
            Quicksort(arr+i, size - i,cmp);
        }

}    
