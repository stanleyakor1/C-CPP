#include "header.h"

int linsearch(int * arr, unsigned int len,int num)
{

    unsigned int i;
    for(i = 0; i<len; i++)
    {
        
        if(arr[i] == num)
            return i;
    }

    return -1;

}

