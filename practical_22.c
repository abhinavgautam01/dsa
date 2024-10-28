#include <stdio.h>

#define MAX 100 // Maximum size of the matrix

// Function prototypes
void inputLowerTriangularMatrix(int arr[], int n);
void displayLowerTriangularMatrix(int arr[], int n);

int main() {
    int n;
    int lowerTriangular[MAX];

    // User input for the size of the lower triangular matrix
    printf("Enter the size of the lower triangular matrix (n x n): ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Size exceeds the maximum limit of %d.\n", MAX);
        return 1;
    }

    // Input the lower triangular matrix
    inputLowerTriangularMatrix(lowerTriangular, n);

    // Display the lower triangular matrix
    printf("Lower Triangular Matrix:\n");
    displayLowerTriangularMatrix(lowerTriangular, n);

    return 0;
}

// Function to input elements of the lower triangular matrix
void inputLowerTriangularMatrix(int arr[], int n) {
    printf("Enter the non-zero elements of the lower triangular matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                printf("Element at [%d][%d]: ", i, j);
                scanf("%d", &arr[(i * (i + 1)) / 2 + j]);
            } else {
                printf("Element at [%d][%d]: ", i, j);
                scanf("%d", &arr[(i * (i + 1)) / 2 + j]);
            }
        }
    }
}

// Function to display the lower triangular matrix
void displayLowerTriangularMatrix(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                printf("%d ", arr[(i * (i + 1)) / 2 + j]);
            } else {
                printf("0 "); // Elements above the diagonal are zero
            }
        }
        printf("\n");
    }
}
