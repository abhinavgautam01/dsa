#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int binary_search(int arr[], int target, int low, int high) {
    if (low > high) {
        return -1; 
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid; 
    } else if (target < arr[mid]) {
        return binary_search(arr, target, low, mid - 1);
    } else {
        return binary_search(arr, target, mid + 1, high);
    }
}

int main() {
    int n,target;
        char search_choice;
    char choice;
    do{
        input:
        printf("\nChoose the search method:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("Enter your choice (1 or 2): ");
        scanf(" %c", &search_choice);


        if(search_choice!= '1' && search_choice != '2'){
            printf("invalid input ...\nplease select valid option...!\n");
            goto input;
        }
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n],temp[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        temp[i]=arr[i];
    }

        if (search_choice == '1') {
        printf("Enter the element to search: ");
        scanf("%d", &target);
            int result = linear_search(arr, n, target);
            if (result != -1) {
                printf("Element found at index: %d\n", result);
            } else {
                printf("Element not found\n");
            }
        } else if (search_choice == '2') {
            printf("Elements after sorting:\n");
            bubble_sort(temp, n);
            printArray(temp,n);
            printf("Enter the element to search: ");
            scanf("%d", &target);
            int result = binary_search(temp, target, 0, n - 1);
            if (result != -1) {
                printf("Element found at index: %d\n", result);
            } else {
                printf("Element not found\n");
            }
        } else {
            printf("Invalid choice!\n");
        }

        printf("Do you want to search again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}