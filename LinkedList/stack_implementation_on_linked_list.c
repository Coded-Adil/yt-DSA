#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* link;
};
struct Node* top = NULL;
void Push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop()
{
    struct Node* temp;
    if(top==NULL)
    {
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}

void Print() {
    struct Node* temp = top;
    printf("THE LIST IS: ");
    while(temp != NULL) {
        printf("%d ", temp->data);  // Added space for readability
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    top = NULL;  // Initialize the head pointer to NULL
    int n, x, i;
    printf("How many numbers? \n");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the number: ");
        scanf("%d", &x);
        Push(x);
        Print();
    }
    return 0;  // Added return statement for the main function
}
