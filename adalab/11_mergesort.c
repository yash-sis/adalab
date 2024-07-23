#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    int temp[right - left + 1];
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) 
        temp[k++] = arr[i++];

    while (j <= right) 
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
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
