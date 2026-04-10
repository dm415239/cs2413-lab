#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key);
static void insert(Node* table[], int key, int value);
static int find(Node* table[], int key, int* value);
static void freeTable(Node* table[]);

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Initialize hash table (array of linked list heads)
    Node* table[TABLE_SIZE] = { NULL };

    // Scan the array once
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;

        // Check if complement has already been seen
        if (find(table, complement, &foundIndex)) {
            // Solution found: allocate and return the two indices
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;

            // Free the hash table before returning
            freeTable(table);
            return result;
        }

        // Not found, insert current element with its index
        insert(table, nums[i], i);
    }

    // According to the problem statement, there is exactly one solution,
    // so this line should never be reached.
    *returnSize = 0;
    freeTable(table);
    return NULL;
}

/*
 * Compute a non‑negative hash index for a given key.
 */
static int hash(int key) {
    // Handle negative keys by adding TABLE_SIZE before modulo
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

/*
 * Insert a (key, value) pair into the hash table.
 * Chaining is used to handle collisions.
 */
static void insert(Node* table[], int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx];
    table[idx] = newNode;
}

/*
 * Search for a key in the hash table.
 * If found, store the associated value in *value and return 1.
 * Otherwise return 0.
 */
static int find(Node* table[], int key, int* value) {
    int idx = hash(key);
    Node* current = table[idx];
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

/*
 * Free all memory allocated for the hash table.
 */
static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}