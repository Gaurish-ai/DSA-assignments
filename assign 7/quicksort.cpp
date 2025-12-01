#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partition(vector<int> &arr,int st,int end)
{   int index=st-1;
    int pivot=arr[end];
    for(int j=st;j<end;j++)
    {
        if(arr[j]<=pivot)
        {
            index++;
            swap(arr[index],arr[j]);
        }
    }
    index++;
    swap(arr[index],arr[end]);
    return index;
}
void quicksort(vector<int> &arr,int st,int end)
{
    if(st<end)
    {
        int pivindex=partition(arr,st,end);
        quicksort(arr,st,pivindex-1); //left
        quicksort(arr,pivindex+1,end); // right
    }
}
int main()
{
    vector<int> arr={5,43,57,2,3};
    quicksort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}