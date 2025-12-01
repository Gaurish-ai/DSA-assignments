#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool increasing) {
    int extreme = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (increasing) {
        if (left < n && a[left] > a[extreme])
            extreme = left;
        if (right < n && a[right] > a[extreme])
            extreme = right;
    } else {
        if (left < n && a[left] < a[extreme])
            extreme = left;
        if (right < n && a[right] < a[extreme])
            extreme = right;
    }

    if (extreme != i) {
        int temp = a[i];
        a[i] = a[extreme];
        a[extreme] = temp;

        heapify(a, n, extreme, increasing);
    }
}

void heapsort(int a[], int n, bool increasing) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, increasing);

    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0, increasing);
    }
}

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ch;
    cin >> ch;      // 1 = increasing, 2 = decreasing

    bool increasing = (ch == 1);
    heapsort(a, n, increasing);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
