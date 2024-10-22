#include <stdio.h>
void display(int arr[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i=0;i<n-1;i++){
        for ( j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void insertionSort(int arr[], int n){
    int i,j,key;
    for ( i = 1; i < n; i++)
    {
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void selectionSort(int arr[], int n){
    int i, j, min_idx,temp;
    for(i=0;i<n-1;i++){
        min_idx=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
            min_idx=j;
            }
        }
        if (min_idx != i)
        swap(&arr[i],&arr[min_idx]);
    }
}
int partition(int arr[], int p, int r){
    int pivot= arr[r];
    int i=p-1,j;
    for(j=p;j<r-1;j++){
        if(pivot>arr[j]){
            i++;
            swap(&arr[i],&arr[j]);
        }
        swap(&arr[i+1],&arr[r]);
        return (i+1);
    }
}
void quickSort(int arr[], int p, int r){
    if(p<r){
        int q = partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}
void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+1;
    if(left<n && arr[largest]<arr[left]){
        largest=i;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=i;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr, int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}










void inputArray(int arr[],int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
}
int main(){
    int i, n;
    printf("Enter number of elements :");
    scanf("%d",&n);
    int arr[n];
    int temp[n];
    inputArray(arr,n);

    for ( i = 0; i < n; i++)
    {
        temp[i]=arr[i];
    }

    bubbleSort(arr,n);
    printf("Elements after sorting(using bubble sort) : \n");
    display(arr,n);

    printf("back to previous Array...! \n");
    for ( i = 0; i < n; i++)
    {
        arr[i]=temp[i];
    }
    display(arr,n);

    printf("Elements after sorting(using insertion sort) : \n");
    insertionSort(arr,n);
    display(arr,n);
    
    printf("back to previous Array...! \n");
    for ( i = 0; i < n; i++)
    {
        arr[i]=temp[i];
    }
    display(arr,n);

    printf("Elements after sorting(using selection sort) : \n");
    selectionSort(arr,n);
    display(arr,n);

}