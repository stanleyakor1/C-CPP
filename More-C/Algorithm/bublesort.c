#include "header.h"

#if 0
void swap(int * a, int * b)
{
    int temp = *a;
     *a = *b;
     *b = temp;
}
#endif

void bubsort(int * arr, unsigned int len)
{
    unsigned int i,j;

    for(i = 0; i<len; i++)
    {
        for(j=0; j<len -1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }

}