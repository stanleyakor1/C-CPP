#include "header.h"
int main(void)
{
    int arr[] = {1, 2, 3, 5};

    int check = linsearch(arr,3);
    printf("check status = %d\n", check);

}

// gcc linearsearch.c main.c -o program && ./a.out  to run.