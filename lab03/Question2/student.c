// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    // If list is empty or has only one node, nothing to swap
    if (!head || !head->next)
        return head;

    struct ListNode* prev = NULL;      // node before current pair
    struct ListNode* curr = head;      // first node of current pair

    while (curr && curr->next) {
        struct ListNode* first = curr;
        struct ListNode* second = curr->next;

        // Swap the two nodes
        first->next = second->next;
        second->next = first;

        // Connect the previous part (or update head) to the swapped pair
        if (prev) {
            prev->next = second;
        }
        else {
            head = second;
        }

        // Move to the next pair
        prev = first;            // 'first' is now after 'second' in the list
        curr = first->next;      // next pair starts here
    }

    return head;
}