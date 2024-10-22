#include <stdio.h>

void display(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}

void inputArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[], int n){
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
            swap(&arr[min_idx],&arr[i]);
        }
    }
}

int partition(int arr[], int p, int r){
    int pivot= arr[r];
    int i=p-1,j;
    for(j=p;j<r-1;j++){
        if(arr[j]>pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
            swap(&arr[i+1],&arr[r]);
            return (i+1);
    }
}
void quickSort(int arr[], int p, int r){
    if(p<r){
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n, int ){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}