#include<iostream>
#include<vector>
using namespace std;
 void Merge(vector<int> & arr,int left,int right,int mid)
{
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int> L1(n1);
    vector<int> L2(n2);
    int k=left;
    for(int i=0;i<n1;i++)
    {
        L1[i]=arr[k];
        k++;
    }
    for(int j=0;j<n2;j++)
    {
        L2[j]=arr[k];
        k++;
    }
    int i=0;
    int j=0;
     k=left;
    while(i<n1 && j<n2){
       if(L1[i]<L2[j]){
        arr[k]=L1[i];
        i++;
       }
       else{
        arr[k]=L2[j];
        j++;
       }
       k++;
    }
    while(i<n1)
    {
        arr[k]=L1[i];
        i++;
        k++;
    }
     while(j<n2)
    {
        arr[k]=L2[j];
        j++;
        k++;
    }

}
void mergesort(vector<int> & arr,int left,int right)
{
    int mid=(left+right)/2;
    if(left>=right)
    {
        return;
    }
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    Merge(arr,left,right,mid);
}
int main()
{
    vector<int> arr={23,1,45,6,87};
    int n=arr.size();
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}