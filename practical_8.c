// Implement Circular Linked List. Include functions for insertion, deletion and search of a number, reverse the list.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insert(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
struct Node* search(struct Node* head, int key);
void reverse(struct Node** head);
void display(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Reverse\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter a number to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter a number to search: ");
                scanf("%d", &data);
                struct Node* result = search(head, data);
                if (result) {
                    printf("Found %d in the list.\n", data);
                } else {
                    printf("%d not found in the list.\n", data);
                }
                break;
            case 4:
                reverse(&head);
                printf("List reversed.\n");
                break;
            case 5:
                printf("Circular Linked List: ");
                display(head);
                break;
            case 6:
                freeList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Pointing to itself
    return newNode;
}

// Insert a new node into the circular linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Delete a node by key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return; // Empty list

    struct Node *temp = *head, *prev = NULL;

    // If the node to be deleted is the head node
    if (temp->data == key) {
        if (temp->next == *head) { // Only one node in the list
            free(temp);
            *head = NULL;
            return;
        } else {
            // Find the last node
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = (*head)->next; // Point last node to the second node
            free(*head); // Free the old head
            *head = temp->next; // Update head
            return;
        }
    }

    // Search for the key to be deleted
    prev = temp;
    temp = temp->next;
    while (temp != *head) {
        if (temp->data == key) {
            prev->next = temp->next; // Unlink the node
            free(temp); // Free memory
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Search for a node by key
struct Node* search(struct Node* head, int key) {
    if (head == NULL) return NULL;

    struct Node* current = head;
    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return NULL;
}

// Reverse the circular linked list
void reverse(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) return; // Empty or single node

    struct Node *prev = NULL, *current = *head, *next = NULL;
    struct Node* tail = *head;

    // Traverse to find the tail of the list
    while (tail->next != *head) {
        tail = tail->next;
    }

    do {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev one step forward
        current = next;       // Move current one step forward
    } while (current != *head);

    // Update head
    *head = prev;
    tail->next = *head; // Complete the circular link
}

// Display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Free the circular linked list
void freeList(struct Node* head) {
    if (head == NULL) return;

    struct Node *temp = head, *nextNode;
    do {
        nextNode = temp->next; // Store next node
        free(temp);            // Free current node
        temp = nextNode;       // Move to next node
    } while (temp != head);
}

