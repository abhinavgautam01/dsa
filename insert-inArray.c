#include <stdio.h>

void insertAtBeginning(int arr[], int *size, int element, int maxSize) {
    if (*size >= maxSize) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    (*size)++;
}

void insertAtEnd(int arr[], int *size, int element, int maxSize) {
    if (*size >= maxSize) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    arr[*size] = element;
    (*size)++;
}

void insertAtPosition(int arr[], int *size, int position, int element, int maxSize) {
    if (*size >= maxSize) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int maxSize = 100;
    int arr[maxSize];
    int size = 0;
    int choice, element, position;

    printf("Enter the initial size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Print array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insertAtBeginning(arr, &size, element, maxSize);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insertAtEnd(arr, &size, element, maxSize);
            break;
        case 3:
            printf("Enter the position and element to insert: ");
            scanf("%d %d", &position, &element);
            insertAtPosition(arr, &size, position, element, maxSize);
            break;
        case 4:
            printf("Array elements: ");
            printArray(arr, size);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
