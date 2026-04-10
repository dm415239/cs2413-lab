#include <stdlib.h>

static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

int findKthLargest(int* nums, int numsSize, int k) {
    // Allocate memory for a min-heap of size k
    int* heap = (int*)malloc(k * sizeof(int));
    if (!heap) return -1;  // allocation failure (should not happen)

    // 1. Insert first k elements into the heap
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
        heapifyUp(heap, i);
    }

    // 2. Process the remaining elements
    for (int i = k; i < numsSize; i++) {
        // If current element is larger than the smallest in the heap,
        // replace the root and restore heap order.
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    // The root of the min-heap is the kth largest element
    int result = heap[0];
    free(heap);
    return result;
}

/*
 * Swap the values of two integers.
 */
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Restore min-heap property by moving a node upward.
 * Used when inserting a new element at the end.
 */
static void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

/*
 * Restore min-heap property by moving a node downward.
 * Used after replacing the root or during heap construction.
 */
static void heapifyDown(int* heap, int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else {
            break;
        }
    }
}