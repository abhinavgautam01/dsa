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

void insertAtEnd(struct Node** head, int data) {
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


// Recursive function to build the reversed linked list
void f(struct Node* head, struct Node** reversedHead) {
    if (head) {
        // Traverse to the end of the original list
        f(head->next, reversedHead);
        insertAtEnd(reversedHead, head->data);
    }
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

// void f(struct Node * head){
//     if(head){
//         f(head->next);
//         printf("%d -> ", head->data);
//     }
// }

void reverse(struct Node** head) {
    struct Node* backNode = NULL;
    struct Node* temp = *head;
    struct Node* nextNode = NULL;
    while (temp) {
        nextNode = temp->next;
        temp->next = backNode;
        backNode = temp;
        temp = nextNode;
    }
    *head = backNode;
    printf("List reversed.\n");
}

// Stack after entering calls : recursiveReverse(4), recursiveReverse(3), recursiveReverse(2), recursiveReverse(1)
// Unwinding the stack (reversing pointers at each return):
// Returning recursiveReverse(4): Reversal begins from the last node.
// Returning recursiveReverse(3): Adds 4 -> 3.
// Returning recursiveReverse(2): Adds 3 -> 2.
// Returning recursiveReverse(1): Adds 2 -> 1.
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
    struct Node* rev = (*head)->next;
    recursiveReverse(&rev);

    // Reversing pointers
    (*head)->next->next = *head;
    (*head)->next = NULL;

    // Update head to the new head of the reversed list
    *head = rev;
}

int main(){

    int value,num,i;
    struct Node *head = NULL;
    struct Node *rev =NULL;
    struct Node* reversedHead = NULL;
    printf("Enter number of nodes for your linked list : ");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("Enter data for Node %d : ",i+1);
        scanf("%d",&value);
        insert(&head,value);
    }

    
    printf("Entered elements : \n");
    display(head);
    f(head, &reversedHead);
    // Print the reversed linked list
    printf("Reversed Linked List: ");
    display(reversedHead);

    // recursiveReverse(&head);
    // printf("Elements after reversing(by iteration) : \n");    
    // display(head);

}