#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head; // head is a global variable, can be accessed anywhere

void Insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print() {
    struct Node* temp = head;
    printf("THE LIST IS: ");
    while(temp != NULL) {
        printf("%d ", temp->data);  // Added space for readability
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;  // Initialize the head pointer to NULL
    int n, x, i;
    printf("How many numbers? \n");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the number: ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;  // Added return statement for the main function
}
