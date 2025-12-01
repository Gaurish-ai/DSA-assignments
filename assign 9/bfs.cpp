#include <iostream>
using namespace std;

#define MAX 10

int main()
{
    int n;
    int adj[MAX][MAX];
    int visited[MAX];
    int q[MAX];
    int front = 0, rear = 0;
    int start;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cin >> start;

    q[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int v = q[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }

    return 0;
}
