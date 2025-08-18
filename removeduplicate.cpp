#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    sort(num.begin(), num.end());

    int m = n;
    for (int i = 0; i + 1 < m; i++) {
        if (num[i] == num[i + 1]) {
            for (int j = i + 1; j < m; j++) num[j - 1] = num[j];
            m = m - 1;
            i = i - 1;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << num[i];
        if (i + 1 < m) cout << ' ';
    }
    cout << '\n';
    return 0;
}
