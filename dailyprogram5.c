#include <stdio.h>

int findUnique(int arr[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
        if (arr[i] != arr[i + 1]) {
            return arr[i]; 
        }
    }
    return arr[n - 1]; 
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int uniqueElement = findUnique(arr, n);
    printf("The unique element is: %d\n", uniqueElement);
    
    return 0;
}
