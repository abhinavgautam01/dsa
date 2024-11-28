#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data);
void insertAtPosition(struct Node** head, int data, int position);
void insert(struct Node** head, int data);
void deleteAtPosition(struct Node** head, int position);
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
        printf("1. Insert at Position in List 1\n");
        printf("2. Delete from Position in List 1\n");
        printf("3. Search in List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List 1 and List 2 into List 3\n");
        printf("6. Display List 1\n");
        printf("7. Display List 2\n");
        printf("8. Display List 3\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&list1, data, position);
                break;
            case 2:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteAtPosition(&list1, position);
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
                freeList(list3); // Free list3 if it was previously created
                int i,num,data;
                printf("Enter number of nodes for your list 2 for concatenation: ");
                scanf("%d",&num);
                for(i=0;i<num;i++){
                    printf("Enter data for node %d :",i+1);
                    scanf("%d",&data);
                    insert(&list2,data);
                }
                list3 = concatenateToNewList(list1, list2);
                printf("Concatenated List 1 and List 2 into List 3.\n");
                break;
            case 6:
                printf("List 1: ");
                display(list1);
                break;
            case 7:
                printf("List 2: ");
                display(list2);
                break;
            case 8:
                printf("List 3: ");
                display(list3);
                break;
            case 9:
                freeList(list1);
                freeList(list2);
                freeList(list3);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);
    return 0;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
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
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at the beginning.\n", data);
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
    printf("Inserted %d in the list.\n", data);
}
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from position %d.\n", position);
        return;
    }
    if (position <= 0) {
        printf("Invalid position. Position should be greater than 0.\n");
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
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}