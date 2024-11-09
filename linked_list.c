#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Display the linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// search
struct Node *search(struct Node *head, int key)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
// insert
void insertAtBeginning(struct node** head,int data){
    struct Node *newNode = createNode(data);
    newNode->next=*head;
    *head=newNode;
    printf("Inserted %d at the beginning.\n",data);
}

int main()
{
    struct Node *head;

    head = createNode(4);
    head->next = createNode(5);
    head->next->next = createNode(6);
    
    display(head);
    
    int find;
    printf("Enter element to be search :");
    scanf("%d", &find);
    
    // search(head, find);
    struct Node *result = search(head, find);
    if (result)
    {
        printf("Found %d in List 1.\n", find);
    }
    else
    {
        printf("%d not found in List 1.\n", find);
    }

}