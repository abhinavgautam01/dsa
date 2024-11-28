#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *item) {
    if (top < MAX - 1) {
        strcpy(stack[++top], item);
    } else {
        printf("Stack overflow\n");
    }
}

char* pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);  // Exit on stack underflow
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void prefixToInfix(char *prefix, char *infix) {
    char op1[MAX], op2[MAX], temp[MAX];
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(operand);
        } else if (isOperator(prefix[i])) {
            if (top < 1) {
                printf("Invalid prefix expression.\n");
                exit(1);  // Exit if insufficient operands
            }
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(temp, "(%s%c%s)", op1, prefix[i], op2);
            push(temp);
        }
    }
    if (top != 0) {
        printf("Invalid prefix expression.\n");
        exit(1);
    }
    strcpy(infix, pop());
}

void prefixToPostfix(char *prefix, char *postfix) {
    char op1[MAX], op2[MAX], temp[MAX];
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(operand);
        } else if (isOperator(prefix[i])) {
            if (top < 1) {
                printf("Invalid prefix expression.\n");
                exit(1);  // Exit if insufficient operands
            }
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(temp, "%s%s%c", op1, op2, prefix[i]);
            push(temp);
        }
    }
    if (top != 0) {
        printf("Invalid prefix expression.\n");
        exit(1);
    }
    strcpy(postfix, pop());
}

int evaluatePostfix(char *postfix) {
    int evalStack[MAX];
    int evalTop = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            evalStack[++evalTop] = postfix[i] - '0';
        } else if (isOperator(postfix[i])) {
            if (evalTop < 1) {
                printf("Invalid postfix expression.\n");
                exit(1);
            }
            int op2 = evalStack[evalTop--];
            int op1 = evalStack[evalTop--];
            switch (postfix[i]) {
                case '+': evalStack[++evalTop] = op1 + op2; break;
                case '-': evalStack[++evalTop] = op1 - op2; break;
                case '*': evalStack[++evalTop] = op1 * op2; break;
                case '/': evalStack[++evalTop] = op1 / op2; break;
            }
        }
    }
    if (evalTop != 0) {
        printf("Invalid postfix expression.\n");
        exit(1);
    }
    return evalStack[evalTop];
}

int main() {
    char prefix[MAX], infix[MAX], postfix[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Convert to infix
    prefixToInfix(prefix, infix);
    printf("Infix: %s\n", infix);

    // Convert to postfix
    prefixToPostfix(prefix, postfix);
    printf("Postfix: %s\n", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("Evaluation of postfix expression: %d\n", result);

    return 0;
}
