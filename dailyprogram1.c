#include <stdio.h>

void inputArray(int arr[], int n){
    int i;
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++){
        printf("Enter element %d : ", i+1);
        scanf("%d",&arr[i]);
    }
}
void display(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;
    printf("Enter number of elements for array: ");
    scanf("%d", &n);
    int arr[n];
    inputArray(arr, n);
    printf("Entered Elements:\n");
    display(arr, n);
    insertionSort(arr, n);
    printf("Sorted Elements:\n");
    display(arr, n);
}