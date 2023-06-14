#include "header.h"

void splitarray(int *arr, int **ptr1, int **ptr2, int len1, int len2) {
    *ptr1 = (int *)malloc(sizeof(int) * len1);
    *ptr2 = (int *)malloc(sizeof(int) * len2);

    for (int i = 0; i < len1; i++) {
        (*ptr1)[i] = arr[i];
    }

    for (int j = 0; j < len2; j++) {
        (*ptr2)[j] = arr[j + len1];
    }
}

void mergesrt(int *arr, unsigned int len) {
    if (len <= 1) {
        return;
    }

    unsigned int len1 = len / 2;
    unsigned int len2 = len - len1;
    int *ptr1, *ptr2;

    splitarray(arr, &ptr1, &ptr2, len1, len2);
    mergesrt(ptr1, len1);
    mergesrt(ptr2, len2);

    unsigned int i = 0, j = 0, k = 0;

    // merge data into array
    while (i < len1 && j < len2) {
        if (ptr1[i] <= ptr2[j]) {
            arr[k] = ptr1[i];
            i++;
        } else {
            arr[k] = ptr2[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = ptr1[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = ptr2[j];
        j++;
        k++;
    }

    free(ptr1);
    free(ptr2);
}
