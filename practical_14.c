// Create and perform different operations on Double-ended Queues using Linked List implementation.
#include <stdio.h>
#include <stdlib.h>

// Node structure for the deque
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function prototypes
Deque* createDeque();
void addFront(Deque* deque, int value);
void addRear(Deque* deque, int value);
int removeFront(Deque* deque);
int removeRear(Deque* deque);
void displayDeque(Deque* deque);
int isEmpty(Deque* deque);
void freeDeque(Deque* deque);

int main() {
    Deque* deque = createDeque();
    int choice, value;

    while (1) {
        printf("\n1. Add to Front\n2. Add to Rear\n3. Remove from Front\n4. Remove from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add to front: ");
                scanf("%d", &value);
                addFront(deque, value);
                break;
            case 2:
                printf("Enter value to add to rear: ");
                scanf("%d", &value);
                addRear(deque, value);
                break;
            case 3:
                value = removeFront(deque);
                if (value != -1) {
                    printf("Removed from front: %d\n", value);
                }
                break;
            case 4:
                value = removeRear(deque);
                if (value != -1) {
                    printf("Removed from rear: %d\n", value);
                }
                break;
            case 5:
                displayDeque(deque);
                break;
            case 6:
                freeDeque(deque);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Create an empty deque
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Add an element to the front of the deque
void addFront(Deque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }

    deque->front = newNode;
    printf("Added %d to front\n", value);
}

// Add an element to the rear of the deque
void addRear(Deque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }

    deque->rear = newNode;
    printf("Added %d to rear\n", value);
}

// Remove an element from the front of the deque
int removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from front.\n");
        return -1; // Indicate an error
    }
    
    Node* temp = deque->front;
    int value = temp->data;

    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        // Deque is now empty
        deque->rear = NULL;
    }

    free(temp);
    return value;
}

// Remove an element from the rear of the deque
int removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from rear.\n");
        return -1; // Indicate an error
    }

    Node* temp = deque->rear;
    int value = temp->data;

    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        // Deque is now empty
        deque->front = NULL;
    }

    free(temp);
    return value;
}

// Display the elements of the deque
void displayDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    Node* current = deque->front;
    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Check if the deque is empty
int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

// Free the allocated memory for the deque
void freeDeque(Deque* deque) {
    while (!isEmpty(deque)) {
        removeFront(deque);
    }
    free(deque);
}
