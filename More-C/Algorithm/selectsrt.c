#include "header.h"

#if 0
void swapit(int * a, int * b)
{
    int temp = *a;
     *a = *b;
     *b = temp;
}
#endif

void selectsrt(int * arr, unsigned int len)
{
    unsigned int i,j;
    for(i = 0; i<len;i++)
    {
        int current_min = arr[i];
        int k;
        for(j=i+1;j<len;j++)
        {
            if(current_min>arr[j])
            {
                current_min=arr[j];
                k=j;
            }       
        }
        if(current_min < arr[i])
            swap(&arr[k],&arr[i]);
    }
}

// gcc selectsrt.c swap.c selectsrt_main.c -o a.out && ./a.out