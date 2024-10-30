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
        return NULL;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void prefixToInfix(char *prefix, char *infix) {
    char op1[MAX], op2[MAX];
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char temp[2] = {prefix[i], '\0'};
            push(temp);
        } else if (isOperator(prefix[i])) {
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(infix, "(%s%c%s)", op1, prefix[i], op2);
            push(infix);
        }
    }
}

void prefixToPostfix(char *prefix, char *postfix) {
    char op1[MAX], op2[MAX];
    for (int i = 0; i < strlen(prefix); i++) {
        if (isalnum(prefix[i])) {
            char temp[2] = {prefix[i], '\0'};
            push(temp);
        } else if (isOperator(prefix[i])) {
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(postfix, "%s%s%c", op1, op2, prefix[i]);
            push(postfix);
        }
    }
}

int evaluatePostfix(char *postfix) {
    int stack[MAX];
    int top = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        } else if (isOperator(postfix[i])) {
            int op2 = stack[top--];
            int op1 = stack[top--];
            switch (postfix[i]) {
                case '+': stack[++top] = op1 + op2; break;
                case '-': stack[++top] = op1 - op2; break;
                case '*': stack[++top] = op1 * op2; break;
                case '/': stack[++top] = op1 / op2; break;
            }
        }
    }
    return stack[top];
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
