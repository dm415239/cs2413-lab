// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>
#include <stdbool.h>

// Create a new circular queue with capacity k
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (!obj) return NULL;                 // allocation failed
    obj->data = (int*)malloc(sizeof(int) * k);
    if (!obj->data) {
        free(obj);
        return NULL;
    }
    obj->capacity = k;
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0;
    return obj;
}

// Insert an element into the queue. Returns true on success, false if full.
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity)        // queue is full
        return false;
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;   // wrap around
    obj->size++;
    return true;
}

// Delete an element from the queue. Returns true on success, false if empty.
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0)                     // queue is empty
        return false;
    obj->head = (obj->head + 1) % obj->capacity;   // move head forward, wrap
    obj->size--;
    return true;
}

// Get the front element. Returns -1 if queue is empty.
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;
    return obj->data[obj->head];
}

// Get the rear (last) element. Returns -1 if queue is empty.
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;
    // tail points to next insertion, so last element is at (tail-1) mod capacity
    int lastIndex = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[lastIndex];
}

// Check whether the queue is empty.
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

// Check whether the queue is full.
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

// Free all memory used by the queue.
void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj) {
        free(obj->data);
        free(obj);
    }
}