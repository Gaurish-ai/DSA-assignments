#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int count=1;
    sort(nums.begin(),nums.end());
    for (int i = 1; i < n; i++) 
    {
        if(nums[i]!=nums[i-1])
        { 
            count++;
        }
    }

    cout<<"no of unique elements : "<<count;
}