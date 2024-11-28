// WAP to reverse the order of the elements in the stack using additional stack.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* s);
int isFull(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
void display(Stack* s);
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
    display(&original);

    // Reverse the stack
    reverseStack(&original);
    return 0;
}

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack* s, int value) {
    if (!isFull(s)) {
        s->arr[++s->top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop an element from the stack
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    } else {
        printf("Stack Underflow\n");
        return -1; // Indicate underflow
    }
}

// Display the elements of the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Reverse the stack using an additional stack
void reverseStack(Stack* original) {
    Stack auxiliary;
    initStack(&auxiliary);

    // Move all elements from the original stack to the auxiliary stack
    while (!isEmpty(original)) {
        push(&auxiliary, pop(original));
    }
    printf("Reversed Stack: ");
    display(&auxiliary);

    // Move all elements back to the original stack
    while (!isEmpty(&auxiliary)) {
        push(original, pop(&auxiliary));
    }
}
