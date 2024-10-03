#include<stdio.h>
int main(){
    int num,i,key,temp=0;
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter your elements\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search : ");
    scanf("%d",&key);
    for(i=0;i<num;i++)
    {
        if(key==arr[i])
        {
            temp=1;
            break;
        }
    }
    if(temp==1)
    printf("Element found at loc %d\n",i+1);
    else
    printf("Element not found");
    return 0;
}