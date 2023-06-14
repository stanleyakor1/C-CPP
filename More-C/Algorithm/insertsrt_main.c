#include "header.h"
int main(void)
{
    int arr[] = {1,17,9,90,4,67,4,7,0,7,12,-1,9,11, 4, 2, 0};

    //int * arr = (int *)malloc(sizeof(int)*18);

    unsigned int len = sizeof(arr)/sizeof(arr[0]);
    insertsrt(arr,len);
    for(int i = 0; i<len; i++)
        printf("%d, ",arr[i]);
    printf("\n");
}
// gcc inserttsrt.c swap.c selectsrt_main.c -o a.out && ./a.out