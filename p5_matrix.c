#include <stdio.h>

void rotateArray(double arr[][3], int n, int k) {
    k = k % n;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            double temp = arr[i][j];
            arr[i][j] = arr[n - i - 1][j];
            arr[n - i - 1][j] = temp;
        }
    }
    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < n; j++) {
            double temp = arr[i][j];
            arr[i][j] = arr[k - i - 1][j];
            arr[k - i - 1][j] = temp;
        }
    }
    for (int i = k; i < (n + k) / 2; i++) {
        for (int j = 0; j < n; j++) {
            double temp = arr[i][j];
            arr[i][j] = arr[n - i + k - 1][j];
            arr[n - i + k - 1][j] = temp;
        }
    }
}

void sortArray(double arr[3][3]) {
    double temp;
    for (int i = 0; i < 9 - 1; i++) {
        for (int j = 0; j < 9 - i - 1; j++) {
            if (((j % 3) < 2 && arr[j / 3][j % 3] > arr[j / 3][(j % 3) + 1]) ||
                ((j % 3) == 2 && arr[j / 3][j % 3] > arr[(j / 3) + 1][0])) {
                temp = arr[j / 3][j % 3];
                arr[j / 3][j % 3] = arr[(j % 3 == 2) ? (j / 3) + 1 : j / 3][(j % 3 + 1) % 3];
                arr[(j % 3 == 2) ? (j / 3) + 1 : j / 3][(j % 3 + 1) % 3] = temp;
            }
        }
    }
}

double determinant(double matrix[3][3], int n) {
    double det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        for (int p = 0; p < n; p++) {
            double subMatrix[3][3];
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == p) continue;
                    subMatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += (p % 2 == 0 ? 1 : -1) * matrix[0][p] * determinant(subMatrix, n - 1);
        }
    }
    return det;
}

void input2DArray(double arr[3][3]) {
    printf("Enter the elements of a 3x3 matrix (row-wise):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
}

void displayMatrix(double arr[3][3]) {
    printf("Matrix elements:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Rotate 3x3 Matrix\n");
        printf("2. Sort 3x3 Matrix\n");
        printf("3. Calculate Determinant of a 3x3 Matrix\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                double matrix[3][3];
                input2DArray(matrix);
                int k;
                printf("Enter the number of rotations: ");
                scanf("%d", &k);

                printf("Original matrix:\n");
                displayMatrix(matrix);

                rotateArray(matrix, 3, k);
                printf("Rotated matrix:\n");
                displayMatrix(matrix);
                break;
            }
            case 2: {
                double matrix[3][3];
                input2DArray(matrix);
                printf("Matrix before sorting:\n");
                displayMatrix(matrix);

                sortArray(matrix);
                printf("Sorted matrix:\n");
                displayMatrix(matrix);
                break;
            }
            case 3: {
                double matrix[3][3];
                input2DArray(matrix);
                printf("Determinant of the matrix: %.2f\n", determinant(matrix, 3));
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
