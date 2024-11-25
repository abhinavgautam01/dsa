// Implement Doubly Linked List. Include functions for insertion, deletion and search of a number, reverse the list.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
        printf("\nDoubly Linked List Menu:\n");
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
                printf("Doubly Linked List: ");
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
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert a new node at the end
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
        newNode->prev = temp;
    }
}

// Delete a node by key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // If the list is empty
    if (temp == NULL) return;

    // If head node itself holds the key
    if (temp->data == key) {
        *head = temp->next; // Changed head
        if (*head != NULL) {
            (*head)->prev = NULL; // Update previous head's previous pointer
        }
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) return;

    // Unlink the node from the doubly linked list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp); // Free memory
}

// Search for a node by key
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Reverse the doubly linked list
void reverse(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    // Swap next and prev for all nodes of the list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node
    }

    // Before changing the head, check for the cases like empty list and list with one node
    if (temp != NULL) {
        *head = temp->prev; // Update head to the new first node
    }
}

// Display the doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the doubly linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
