#include <stdio.h>
#include <stdlib.h>

// Node structure for the polynomial linked list
typedef struct Node {
    int coeff;       // Coefficient
    int exp;        // Exponent
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int coeff, int exp);
void insert(Node** head, int coeff, int exp);
void display(Node* head);
Node* addPolynomials(Node* poly1, Node* poly2);
void freePolynomial(Node* head);

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;
    int numTerms, coeff, exp;
    char choice;

    do {
        // Input first polynomial
        printf("Enter number of terms in first polynomial: ");
        scanf("%d", &numTerms);
        printf("Enter terms in the format (coefficient exponent):\n");
        for (int i = 0; i < numTerms; i++) {
            scanf("%d %d", &coeff, &exp);
            insert(&poly1, coeff, exp);
        }

        // Input second polynomial
        printf("Enter number of terms in second polynomial: ");
        scanf("%d", &numTerms);
        printf("Enter terms in the format (coefficient exponent):\n");
        for (int i = 0; i < numTerms; i++) {
            scanf("%d %d", &coeff, &exp);
            insert(&poly2, coeff, exp);
        }

        // Add the polynomials
        result = addPolynomials(poly1, poly2);

        // Display the results
        printf("First Polynomial: ");
        display(poly1);
        printf("Second Polynomial: ");
        display(poly2);
        printf("Resultant Polynomial: ");
        display(result);

        // Free allocated memory
        freePolynomial(poly1);
        freePolynomial(poly2);
        freePolynomial(result);

        // Ask user if they want to perform the operation again
        printf("Do you want to add another pair of polynomials? (y/n): ");
        scanf(" %c", &choice);

        // Reset polynomials for the next operation
        poly1 = NULL;
        poly2 = NULL;
        result = NULL;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list
void insert(Node** head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->exp >= exp) {
            if (current->next->exp == exp) {
                current->next->coeff += coeff; // Combine like terms
                free(newNode); // Free unused node
                return;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the polynomial
void display(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* current1 = poly1;
    Node* current2 = poly2;

    while (current1 != NULL || current2 != NULL) {
        int coeff = 0, exp;

        if (current1 != NULL && (current2 == NULL || current1->exp > current2->exp)) {
            coeff = current1->coeff;
            exp = current1->exp;
            current1 = current1->next;
        } else if (current2 != NULL && (current1 == NULL || current2->exp > current1->exp)) {
            coeff = current2->coeff;
            exp = current2->exp;
            current2 = current2->next;
        } else { // current1->exp == current2->exp
            coeff = current1->coeff + current2->coeff;
            exp = current1->exp;
            current1 = current1->next;
            current2 = current2->next;
        }

        // Only insert if coefficient is not zero
        if (coeff != 0) {
            insert(&result, coeff, exp);
        }
    }

    return result;
}

// Function to free the polynomial linked list
void freePolynomial(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}
