#include<iostream>
using namespace std;
int main()
{   int x;
    int arr[5]={1,2,3,4,5};
   cout<<"to print the reversed array: ";
   for(int i=0,j=4;i<=5/2,j>=5/2;i++,j--)
   {    int swap;
        swap=arr[i];
        arr[i]=arr[j];
        arr[j]=swap;
   }
   cout<<"reversed array is : ";
   for(int i=0;i<5;i++)
   {
        cout<<arr[i]<<endl;
   }
}