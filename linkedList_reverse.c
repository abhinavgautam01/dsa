#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// void reverse(struct Node** head)
// {
//     struct Node *newNode = NULL;
//     struct Node *temp = *head;
//     while(temp){
//         insertAtBeginning(&newNode,temp->data);
//         temp=temp->next;
//     }
//     *head=newNode;
    
// }

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* temp = *head;
    struct Node* next = NULL;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
    printf("List reversed.\n");
}

// Stack after entering calls (top to bottom): reverseRecursive(4), reverseRecursive(3), reverseRecursive(2), reverseRecursive(1)
// Unwinding the stack (reversing pointers at each return):
// Returning reverseRecursive(4): Reversal begins from the last node.
// Returning reverseRecursive(3): Adds 4 -> 3.
// Returning reverseRecursive(2): Adds 3 -> 2.
// Returning reverseRecursive(1): Adds 2 -> 1.
// Final output is 4 -> 3 -> 2 -> 1 -> NULL.

// Example Execution for 1 -> 2 -> 3 -> 4 -> NULL
// Stack after Pushing: 4, 3, 2, 1 (top points to 4).
// Reconstruction:
// Pop 4: head points to 4.
// Pop 3: 4 -> 3
// Pop 2: 4 -> 3 -> 2
// Pop 1: 4 -> 3 -> 2 -> 1 -> NULL

void recursiveReverse(struct Node** head) {
    // Base case: if the list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Recursive call to reverse the rest of the list
    struct Node* rest = (*head)->next;
    recursiveReverse(&rest);

    // Reversing pointers
    (*head)->next->next = *head;
    (*head)->next = NULL;

    // Update head to the new head of the reversed list
    *head = rest;
}

int main(){

    int value,num,i;
    struct Node *head = NULL;
    struct Node *rev =NULL;
    printf("Enter number of nodes for your linked list : ");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("Enter data for Node %d : ",i+1);
        scanf("%d",&value);
        insert(&head,value);
    }
    printf("Entered elements : \n");
    display(head);
    recursiveReverse(&head);
    printf("Elements after reversing(by iteration) : \n");    
    display(head);

}