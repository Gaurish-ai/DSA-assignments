#include<iostream>
using namespace std;
int main()
{
    int matrix[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int rows=3;
    int columns=4;
   
    /*for(int i=0;i<rows;i++)
    {    int sum=0;
        for(int j=0;j<columns;j++)
        {
            sum=sum+matrix[i][j];
        }
        cout<<"sum of the row"<<i+1<<" is : "<<sum<<endl;
    }*/
    for(int i=0;i<columns;i++)
    {    int sum=0;
        for(int j=0;j<rows;j++)
        {
            sum=sum+matrix[j][i];
        }
        cout<<"sum of the columns"<<i+1<<" is : "<<sum<<endl;
    }
}