#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head;
void Reverse(struct Node* p, struct Node** head) {
    if (p->next == NULL) {
        *head = p; // Update the head pointer
        return;
    }
    Reverse(p->next, head);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}


// Function to print the list using recursion
void Print(struct Node* p) {
    if (p == NULL) {
        return; // Exit condition
    }
    printf("%d ", p->data); // Print the value in the node in correct order
    Print(p->next); // Recursive call
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
    printf("Original List: ");
    Print(head); // Should print: 2 4 6 5
    printf("\n");

    Reverse(head, &head); // Reverse the list using recursion

    printf("Reversed List: ");
    Print(head); // Should print: 5 6 4 2
    printf("\n");

    return 0;

}

