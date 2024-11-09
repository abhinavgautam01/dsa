#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void insertAtEnd(struct Node** head, int data);
void deleteAtBeginning(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void deleteAtEnd(struct Node** head);
struct Node* search(struct Node* head, int key);
void reverse(struct Node** head);
struct Node* concatenateToNewList(struct Node* head1, struct Node* head2);
void display(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* list3 = NULL;
    int choice, data, position;

    do {
        printf("\nLinked List Menu:\n");
        printf("1. Insert at Beginning of List 1\n");
        printf("2. Insert at Position in List 1\n");
        printf("3. Insert at End of List 1\n");
        printf("4. Delete from Beginning of List 1\n");
        printf("5. Delete from Position in List 1\n");
        printf("6. Delete from End of List 1\n");
        printf("7. Search in List 1\n");
        printf("8. Reverse List 1\n");
        printf("9. Concatenate List 1 and List 2 into List 3\n");
        printf("10. Display List 1\n");
        printf("11. Insert into List 2\n");
        printf("12. Display List 2\n");
        printf("13. Display List 3\n");
        printf("14. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert at the beginning of List 1: ");
                scanf("%d", &data);
                insertAtBeginning(&list1, data);
                break;

            case 2:
                printf("Enter a number to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&list1, data, position);
                break;

            case 3:
                printf("Enter a number to insert at the end of List 1: ");
                scanf("%d", &data);
                insertAtEnd(&list1, data);
                break;

            case 4:
                deleteAtBeginning(&list1);
                break;

            case 5:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteAtPosition(&list1, position);
                break;

            case 6:
                deleteAtEnd(&list1);
                break;

            case 7:
                printf("Enter a number to search in List 1: ");
                scanf("%d", &data);
                struct Node* result = search(list1, data);
                if (result) {
                    printf("Found %d in List 1.\n", data);
                } else {
                    printf("%d not found in List 1.\n", data);
                }
                break;

            case 8:
                reverse(&list1);
                printf("List 1 reversed.\n");
                break;

            case 9:
                freeList(list3); // Free list3 if it was previously created
                list3 = concatenateToNewList(list1, list2);
                printf("Concatenated List 1 and List 2 into List 3.\n");
                break;

            case 10:
                printf("List 1: ");
                display(list1);
                break;

            case 11:
                printf("Enter a number to insert into List 2: ");
                scanf("%d", &data);
                insertAtEnd(&list2, data); // Insert at end by default for List 2
                break;

            case 12:
                printf("List 2: ");
                display(list2);
                break;

            case 13:
                printf("List 3: ");
                display(list3);
                break;

            case 14:
                freeList(list1);
                freeList(list2);
                freeList(list3);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 14);

    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

// Insert a new node at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position. Position should be greater than 0.\n");
        return;
    }

    if (*head == NULL && position != 1) {
        printf("List is empty. Cannot insert at position %d.\n", position);
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", data, position);
    }
}

// Insert a new node at the end
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
    printf("Inserted %d at the end.\n", data);
}

// Delete a node from the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted from the beginning.\n");
}

// Delete a node from a given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from position %d.\n", position);
        return;
    }

    if (position <= 0) {
        printf("Invalid position. Position should be greater than 0.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Deleted from position %d.\n", position);
    }
}

// Delete a node from the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        printf("Deleted from the end.\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Deleted from the end.\n");
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
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed.\n");
}

// Concatenate two linked lists into a new list
struct Node* concatenateToNewList(struct Node* head1, struct Node* head2) {
    struct Node* newHead = NULL;
    struct Node* tail = NULL;

    struct Node* temp = head1;
    while (temp != NULL) {
        struct Node* newNode = createNode(temp->data);
        if (newHead == NULL) {
            newHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        struct Node* newNode = createNode(temp->data);
        if (newHead == NULL) {
            newHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }

    return newHead;
}

// Display the linked list
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

// Free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
