#include<stdio.h>
int main(){
    int num,i,key,temp=0,low=0,mid;
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    int high=num-1;
    printf("Enter your elements\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search : ");
    scanf("%d",&key);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
            printf("Element found at loc %d at index %d\n",mid+1,mid);
            temp=1;
            break;
        }
        else if(key<mid)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(temp!=1)
    {
        printf("Element Not Found..!\n");
    }
}