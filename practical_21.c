// WAP to reverse the order of the elements in the stack using additional Queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Stack structure
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function prototypes for stack
void initStack(Stack* s);
int isFullStack(Stack* s);
int isEmptyStack(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
void displayStack(Stack* s);

// Function prototypes for queue
void initQueue(Queue* q);
int isFullQueue(Queue* q);
int isEmptyQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void displayQueue(Queue* q);

// Function to reverse stack using an additional queue
void reverseStack(Stack* original);

int main() {
    Stack original;
    initStack(&original);
    
    int n, value;

    // User input for the number of elements in the stack
    printf("Enter the number of elements to push onto the stack (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    // Push elements onto the stack
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(&original, value);
    }

    printf("Original Stack: ");
    displayStack(&original);

    // Reverse the stack
    reverseStack(&original);

    printf("Reversed Stack: ");
    displayStack(&original);

    return 0;
}

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is full
int isFullStack(Stack* s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmptyStack(Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack* s, int value) {
    if (!isFullStack(s)) {
        s->arr[++s->top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop an element from the stack
int pop(Stack* s) {
    if (!isEmptyStack(s)) {
        return s->arr[s->top--];
    } else {
        printf("Stack Underflow\n");
        return -1; // Indicate underflow
    }
}

// Display the elements of the stack
void displayStack(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if the queue is full
int isFullQueue(Queue* q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmptyQueue(Queue* q) {
    return q->front > q->rear;
}

// Enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (!isFullQueue(q)) {
        q->arr[++q->rear] = value;
    } else {
        printf("Queue Overflow\n");
    }
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (!isEmptyQueue(q)) {
        return q->arr[q->front++];
    } else {
        printf("Queue Underflow\n");
        return -1; // Indicate underflow
    }
}

// Display the elements of the queue
void displayQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Reverse the stack using an additional queue
void reverseStack(Stack* original) {
    Queue auxiliary;
    initQueue(&auxiliary);

    // Move all elements from the original stack to the auxiliary queue
    while (!isEmptyStack(original)) {
        enqueue(&auxiliary, pop(original));
    }

    // Move all elements back to the original stack from the queue
    while (!isEmptyQueue(&auxiliary)) {
        push(original, dequeue(&auxiliary));
    }
}
