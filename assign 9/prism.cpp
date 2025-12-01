#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int minKey(int key[], bool inMST[], int V) {
    int minVal = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "Enter adjacency matrix (use 0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int parent[MAX];   // to store MST
    int key[MAX];      // min weight for each vertex
    bool inMST[MAX];   // true if included in MST

    // Initialize
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1; // first node is root of MST

    // Build MST with V-1 edges
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST, V); // pick min key vertex not in MST
        inMST[u] = true;

        // Update key value of neighbors
        for (int v = 0; v < V; v++) {
            // graph[u][v] != 0 means edge exists
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    cout << "\nPrim's MST edges:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (weight " << graph[i][parent[i]] << ")\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total weight of MST = " << totalWeight << endl;

    return 0;
}
