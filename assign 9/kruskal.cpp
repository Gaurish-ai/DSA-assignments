#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;  // from, to, weight
};

// Disjoint Set (Union-Find)
int findParent(int v, vector<int> &parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent); // path compression
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(V + 1), rank(V + 1, 0);
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (auto &e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if (pu != pv) {  // no cycle
            unionSet(pu, pv, parent, rank);
            mstWeight += e.w;
            mstEdges.push_back(e);
        }
    }

    cout << "\nKruskal's MST edges:\n";
    for (auto &e : mstEdges) {
        cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
    }
    cout << "Total weight of MST = " << mstWeight << endl;

    return 0;
}
