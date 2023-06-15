


#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the pivot as the last element
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);  // Swap arr[i] and arr[j]
        }
    }
    
    swap(&arr[i + 1], &arr[high]);  // Swap arr[i+1] and arr[high]
    return (i + 1);
}

// Function to implement Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays
        int pivotIndex = partition(arr, low, high);
        
        // Recursive call to sort the sub-arrays
        quicksort(arr, low, pivotIndex - 1);  // Sort elements before the pivot
        quicksort(arr, pivotIndex + 1, high);  // Sort elements after the pivot
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Test the Quicksort algorithm
int main() {
    int arr[] = {9, 2, 5, 1, 7, 6, 8, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    quicksort(arr, 0, size - 1);
    
    printf("Sorted array: ");
    printArray(arr, size);
    
    return 0;
}
