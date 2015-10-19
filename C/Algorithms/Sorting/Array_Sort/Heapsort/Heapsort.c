#include "Heapsort.h"
void Sift(ARRTYPE* arr,int start,int end,int *(cmp)(ARRTYPE,ARRTYPE))
{
         int child = 2*start+1;
         int parrent = start;
         ARRTYPE tmp;
 
    while(child<end)
    {
        if ((child+1<end) && (cmp(arr[child+1],arr[child])==0))
        {
            child=child+1;
        }
        if (cmp(arr[child],arr[parrent])==0)
        {            
            tmp = arr[parrent]; arr[parrent]=arr[child];arr[child]=tmp;
            parrent=child;child=2*child+1;
        }
        else
        {
            break;
        }
    }

}

void Heapsort(ARRTYPE* arr, int size, int *(cmp)(ARRTYPE,ARRTYPE))
{

        int i;
        ARRTYPE tmp;

    for (i = (size-2)/2; i >= 0; i--)
    {
        Sift(arr, i, size,cmp);
    }
    for (i = size - 1; i > 0; i--)
    {
        tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;
        Sift(arr, 0, i,cmp);
    }
}

