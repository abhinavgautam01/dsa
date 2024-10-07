#include<iostream>
using namespace std;
void linearsearch(int y, int arr[], int x)
{
    int i,temp=0;
    for(i=0;i<x;i++)
    {
        if(arr[i]==y)
        {
            cout<<"element is found at positon\n"<<(i+1)<<endl;
            temp=1;

        }

    }
    if(temp==0){
        cout<<"element not found";
    }
}
int main()
{
    int i,x, y, z;
    cout<<"Enter size of array: ";
    cin>>x;
    int arr[x];
    cout<<"Enter array element: "<<endl;
    for(i=0;i<x;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<x;i++)
    {
        cout<<arr[i]<<"";
    }
    cout<<endl;
    cout<<"Enter the number you want to search: ";
    cin>>y;
    cout<<"Searching algorithms.."<<endl;
    cout<<"1.Linear Search"<<endl;
    cout<<"2.Binary Search"<<endl;
    cin>>z;
    if(z==1)
    {
        linearsearch(y,arr,x);
    }
    else{
        cout<<"Invalid input";
    }
}