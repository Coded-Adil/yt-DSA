#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to print the list using recursion
void ReversePrint(struct Node* p) {
    if (p == NULL) {
        return; // Exit condition
    }
    ReversePrint(p->next); // Recursive call
    printf("%d ", p->data); // Print the value in the node in reverse order
}

// Function to insert a node at the end of the list
struct Node* Insert(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct Node* temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;  // Correctly placed outside the loop
    }
    return head;
}

int main() {
    struct Node* head = NULL; // Local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    ReversePrint(head); // Should print: 2 4 6 5
    return 0;
}
