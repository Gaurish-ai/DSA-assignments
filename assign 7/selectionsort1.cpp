#include<iostream>
using namespace std;
int main()
{
    int arr[5]={2,54,44,1,7};
    //selection sort
    for(int i=0;i<4;i++)
    {
        int min=i+1;
        for(int j=i+1;j<4;j++)
        {
            if(arr[j]>arr[j+1])
            { min=j+1;
            }
        }
        if(arr[i]>arr[min])
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
}
}