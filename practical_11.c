#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define the structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue node
struct QueueNode* createNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createNode(data);
    if (queue->rear == NULL) {
        // If the queue is empty, both front and rear point to the new node
        queue->front = queue->rear = newNode;
        printf("%d enqueued to queue\n", data);
        return;
    }
    // Add the new node at the end and update the rear pointer
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Indicates that the queue is empty
    }
    struct QueueNode* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = queue->front->next;

    // If the front becomes NULL, then also set rear to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    printf("%d dequeued from queue\n", dequeuedData);
    return dequeuedData;
}

// Function to display the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    struct QueueNode* current = queue->front;
    printf("Queue elements:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                free(queue); // Clean up the queue memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
