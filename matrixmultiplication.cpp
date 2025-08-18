#include<iostream>
using namespace std;

int main()
{
    int a[2][2] = { {1, 2}, {3, 4} };
    int b[2][2] = { {5, 6}, {7, 8} };
    int c[2][2] = {0};

    int rows = 2;
    int columns = 2;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < columns; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
