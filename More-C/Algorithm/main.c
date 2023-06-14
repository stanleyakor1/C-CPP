#include "header.h"
int main(void)
{
    int arr[] = {1, 2, 3, 5};
    unsigned int len = sizeof(arr)/sizeof(arr[0]);
    int check = linsearch(arr,len,3);
    printf("check status = %d\n", check);

}

// gcc linearsearch.c main.c -o a.out && ./a.out  to run.