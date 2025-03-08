#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// Recursive helper function to append a node at the end of a list
void append(Node*& head, Node*& tail, Node* node) {
    if (!head) {  // If the list is empty, initialize it
        head = tail = node;
    } else {  // Otherwise, append to the tail
        tail->next = node;
        tail = node;
    }
    node->next = nullptr; // Ensure the new node is the last one
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot, Node*& smallTail, Node*& largeTail) {
    if (!head) return; // Base case: If the list is empty, return.

    Node* nextNode = head->next; // Store next node before modifying head

    if (head->val <= pivot) {
        append(smaller, smallTail, head); // Add to smaller list
    } else {
        append(larger, largeTail, head); // Add to larger list
    }

    head = nextNode; // Move head forward
    llpivot(head, smaller, larger, pivot, smallTail, largeTail); // Recursive call
}

// Wrapper function to make calling easier
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    smaller = larger = nullptr;
    Node* smallTail = nullptr;
    Node* largeTail = nullptr;
    llpivot(head, smaller, larger, pivot, smallTail, largeTail);
}

