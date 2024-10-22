#include <stdio.h>



void display(int arr[], int n){
    int i;
    for( i = 0 ; i < n ; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void inputArray(int arr[],int n){
    int i;
    for( i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}



void bubbleSort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void insertionSort(int arr[], int n){
    int i, key, j;
    for(i=1;i<n;i++){
        j=i-1;
        key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void selectionSort(int arr[], int n){
    int i,min_idx,j;
    for(i=0;i<n-1;i++){
        min_idx=i;
        for(j=i+1;j<n;j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            swap(&arr[i],&arr[min_idx]);
        }
    }
}
int partition(int arr[], int p, int r){
    int pivot=arr[r];
    int i=p-1,j;
    for(j=0;j<r-1;j++){
        if(arr[pivot]>arr[j]){
            i++;
            swap(&arr[i], &arr[j]);
        }
        swap(&arr[r],&arr[i+1]);
        return i+1;
    }
}
void quickSort(int arr[], int p, int r){
    if(p<r){
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}