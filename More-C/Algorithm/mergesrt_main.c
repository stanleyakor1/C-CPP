#include "header.h"
int main(void)
{
    int arr[] = {1,17,9,90,4,67,4,7,0,7,34,45,1,-5,-89,0,7,8,33,7,908,9009,78,12,-1,9,11, 4, 2, 0};
    unsigned int len = sizeof(arr)/sizeof(arr[0]);
    mergesrt(arr,len);
    for(int i = 0; i<len; i++)
        printf("%d, ",arr[i]);
    printf("\n");
}

// gcc mergesrt.c swap.c mergesrt_main.c -o a.out && ./a.out