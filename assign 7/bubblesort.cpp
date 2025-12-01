#include<iostream>
using namespace std;
int main()
{
    //bubble sort
    int a[10] = {5, 3, 8, 4,7,44,99,33,22,335};
    for(int i=0;i<9;i++)
    {
        for(int j=1;j<10-i-1;j++)
        {
            if(a[j]<a[j-1])
            {   int temp;
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    for(int i=0;i<10;i++)
{
    cout<<a[i]<<" ";
}}