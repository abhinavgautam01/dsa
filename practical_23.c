// WAP to implement Symmetric Matrix using one-dimensional array.
#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the matrix

// Function to get the index in the one-dimensional array
int getIndex(int row, int col) {
    if (row < col) {
        return (col * (col + 1)) / 2 + row;  // Upper triangle
    } else {
        return (row * (row + 1)) / 2 + col;  // Lower triangle (symmetric)
    }
}

// Function to set an element in the symmetric matrix
void setElement(int *arr, int row, int col, int value) {
    arr[getIndex(row, col)] = value;
}

// Function to get an element from the symmetric matrix
int getElement(int *arr, int row, int col) {
    return arr[getIndex(row, col)];
}

// Function to print the symmetric matrix
void printMatrix(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", getElement(arr, i, j));
        }
        printf("\n");
    }
}

int main() {
    int n;  // Size of the symmetric matrix
    int arr[MAX_SIZE * (MAX_SIZE + 1) / 2] = {0};  // One-dimensional array to store the symmetric matrix

    printf("Enter the size of the symmetric matrix (n x n): ");
    scanf("%d", &n);

    // Input elements in the symmetric matrix
    printf("Enter the elements of the symmetric matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &value);
            setElement(arr, i, j, value);
        }
    }

    // Print the symmetric matrix
    printf("The symmetric matrix is:\n");
    printMatrix(arr, n);

    return 0;
}
