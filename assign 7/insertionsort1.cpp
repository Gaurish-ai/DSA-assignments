#include<iostream>
using namespace std;
int main()
{   int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<=n-1;i++){
        int temp=arr[i];
        int k=i;
        for(int j=i;j>0;j--){
            if(arr[j-1]>temp){
                arr[j]=arr[j-1];
                k=j-1;
            }
        }
        arr[k]=temp;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }



}