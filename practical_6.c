#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
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
void concatenate(struct Node** head1, struct Node* head2);
void display(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data;

    do {
        printf("\nLinked List Menu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Delete from List 1\n");
        printf("3. Search in List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List 1 and List 2\n");
        printf("6. Display List 1\n");
        printf("7. Insert into List 2\n");
        printf("8. Display List 2\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert into List 1: ");
                scanf("%d", &data);
                insert(&list1, data);
                break;
            case 2:
                printf("Enter a number to delete from List 1: ");
                scanf("%d", &data);
                deleteNode(&list1, data);
                break;
            case 3:
                printf("Enter a number to search in List 1: ");
                scanf("%d", &data);
                struct Node* result = search(list1, data);
                if (result) {
                    printf("Found %d in List 1.\n", data);
                } else {
                    printf("%d not found in List 1.\n", data);
                }
                break;
            case 4:
                reverse(&list1);
                printf("List 1 reversed.\n");
                break;
            case 5:
                printf("Concatenating List 1 and List 2.\n");
                concatenate(&list1, list2);
                break;
            case 6:
                printf("List 1: ");
                display(list1);
                break;
            case 7:
                printf("Enter a number to insert into List 2: ");
                scanf("%d", &data);
                insert(&list2, data);
                break;
            case 8:
                printf("List 2: ");
                display(list2);
                break;
            case 9:
                freeList(list1);
                freeList(list2);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
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
    }
}

// Delete a node by key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
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

// Reverse the linked list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    *head = prev; // Update head to the new first node
}

// Concatenate two linked lists
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

// Display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
