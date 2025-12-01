#include <iostream>
using namespace std;

#define MAX 10

void DFS(int v, int n, int adj[][MAX], int visited[])
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i, n, adj, visited);
        }
    }
}

int main()
{
    int n;
    int adj[MAX][MAX];
    int visited[MAX];
    int start;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cin >> start;

    DFS(start, n, adj, visited);

    return 0;
}
