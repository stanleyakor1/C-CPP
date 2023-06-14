 include "header.h"
int main(void)
{
    int arr[] = {1,17,9,90,4,67,4,7,0,7,12,-1,9,11, 4, 2, 0};
    unsigned int len = sizeof(arr)/sizeof(arr[0]);
    int check = linsearch(arr,len,2);
    printf("check status = %d\n", check);
}