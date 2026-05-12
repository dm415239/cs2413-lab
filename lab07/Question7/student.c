#include <stdio.h>
#include <stdlib.h>

/*
Hybrid Merge Sort Lab
...
*/

/*
Print the array.
Do not modify this function.
*/
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

/*
Check whether the array is sorted.
Do not modify this function.
*/
int isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

/*
Sort arr[left...right] using insertion sort.
*/
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*
Merge two sorted subarrays into one sorted subarray.
*/
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

/*
Hybrid merge sort.
*/
void hybridMergeSort(int arr[], int left, int right, int k) {
    if (left >= right)
        return;

    if (right - left + 1 <= k) {
        insertionSort(arr, left, right);
    }
    else {
        int mid = left + (right - left) / 2;
        hybridMergeSort(arr, left, mid, k);
        hybridMergeSort(arr, mid + 1, right, k);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = { 39, 9, 81, 45, 90, 27, 72, 18 };
    int size = sizeof(arr) / sizeof(arr[0]);

    /*
    k is the threshold.
    When the current subarray size is less than or equal to k,
    insertion sort should be used.
    You may change k to test different behaviors.
    */
    int k = 3;

    printf("Original array:\n");
    printArray(arr, size);

    hybridMergeSort(arr, 0, size - 1, k);

    printf("Sorted array:\n");
    printArray(arr, size);

    if (isSorted(arr, size)) {
        printf("Result: PASS\n");
    }
    else {
        printf("Result: FAIL\n");
    }

    return 0;
}