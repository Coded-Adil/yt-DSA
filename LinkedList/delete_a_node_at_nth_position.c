#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head; //Global v
void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
} //insert an integer at end of the linked list
void Print() {
    struct Node* temp = head;
    printf("THE LIST IS: ");
    while(temp != NULL) {
        printf("%d ", temp->data);  // Added space for readability
        temp = temp->next;
    }
    printf("\n");
} //Print all the elements
void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1){
        head = temp1->next; // head now points to second node
        free(temp1);
        return;
    }
    int i;
    for(i=0; i<n-2; i++)
    {
        temp1 = temp1->next;
    }
    // temp1 points to (n-1)th Node
    struct Node* temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    free(temp2); // delete temp2
} // Delete node at nth position
int main()
{
    head = NULL; // empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2, 4, 6, 5
    Print();
    int n;
    printf("ENTER A POSITION: ");
    scanf("%d",&n);
    Delete(n);
    Print();
}
