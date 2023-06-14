#include "header.h"

void insertsrt(int * arr, unsigned int len)
{
    unsigned int i,j;

    for(i=1; i<len; i++)
    {
        for(j=1; j<len;j++)
        {
            if(arr[j]<arr[j-1])
                swap(&arr[j], &arr[j-1]);
        }
    }
}