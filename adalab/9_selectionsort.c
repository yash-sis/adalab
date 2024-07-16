#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) 
            if (arr[j] < arr[min]) 
                min = j;

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr, n);
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
