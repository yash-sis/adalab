#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) 
        arr[i] = rand() % 1000; 
    
    printf("\nOriginal array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    printf("\nTime taken: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;
}

/*
Enter the number of elements: 10

Original array: 
41 467 334 500 169 724 478 358 962 464

Sorted array:
41 169 334 358 464 467 478 500 724 962

Time taken: 0.000000 s
*/
