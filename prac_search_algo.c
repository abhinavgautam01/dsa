#include <stdio.h>
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]); // Removed unnecessary '&'
    }
    printf("\n"); // Added newline for better formatting
}
void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index: %d\n", i); // Use 'i' instead of '&key'
            return; // Exit once found
        }
    }
    printf("Element not found..!\n");
}
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; // Element not found
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid; // Element found
    } else if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key); // Search in left half
    } else {
        return binarySearch(arr, mid + 1, high, key); // Search in right half
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { // Corrected bounds
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, key, choice;
    int arr[100]; // Declare array with a fixed size
    while (1) {
        printf("....Searching Algorithms....\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice); // Added space before %d to ignore whitespace
        switch (choice) {
            case 1:
                printf("Enter number of elements for your array: ");
                scanf("%d", &n);
                printf("Enter your elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]); // Use '&' to read values
                }
                printf("Enter the element you want to search: ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;
            case 2:
                printf("Enter number of elements for your array: ");
                scanf("%d", &n);
                printf("Enter your elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]); // Use '&' to read values
                }
                bubbleSort(arr, n); // Sort the array before binary search
                printf("Enter the element you want to search: ");
                scanf("%d", &key);
                int result = binarySearch(arr, 0, n - 1, key);
                if (result != -1) {
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found..!\n");
                }
                break;
            case 3:
                printf("Exiting the program..!\n");
                return 0; // Exit the program properly
            default:
                printf("Invalid input..!\n");
                break;
        }
    }
    return 0; // Exit the program
}
