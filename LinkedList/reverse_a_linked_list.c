#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
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
        temp1->next = temp;  // This line should be outside the while loop
    }
    return head;
}

// Function to print all the elements in the list
void Print(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the linked list
struct Node* Reverse(struct Node* head) {
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    struct Node* head = NULL; // Empty list
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5); // List: 2, 4, 6, 5
    Print(head);
    head = Reverse(head); // Corrected the function name
    Print(head); // Should print the reversed list: 5, 6, 4, 2
    return 0;
}
