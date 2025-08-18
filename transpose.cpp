#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int A[200][200], T[200][200];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            T[j][i] = A[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << T[i][j];
            if (j + 1 < m) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
