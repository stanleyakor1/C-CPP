#include "header.h"
int linsearch(int * arr, int num)
{

    unsigned int len = sizeof(arr)/sizeof(arr[0]), i;

    for(i = 0; i<len; i++)
    {
        if(arr[i] = num)
            return 1;
    }

    return -1;

}

