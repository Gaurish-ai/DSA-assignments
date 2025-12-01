#include <iostream>
using namespace std;

const int MAX = 100;

int heapArr[MAX];
int heapSize = 0;

void swapInt(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heapArr[parent] < heapArr[i]) {
            swapInt(heapArr[parent], heapArr[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && heapArr[left] > heapArr[largest])
            largest = left;
        if (right < heapSize && heapArr[right] > heapArr[largest])
            largest = right;

        if (largest != i) {
            swapInt(heapArr[i], heapArr[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void insertPQ(int x) {
    if (heapSize == MAX) {
        cout << "Priority queue overflow\n";
        return;
    }
    heapArr[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}

int deleteMaxPQ() {
    if (heapSize == 0) {
        cout << "Priority queue underflow\n";
        return -1;
    }
    int maxVal = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return maxVal;
}

void displayPQ() {
    if (heapSize == 0) {
        cout << "Priority queue is empty\n";
        return;
    }
    for (int i = 0; i < heapSize; i++)
        cout << heapArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, x;

    do {
        cout << "\n1. Insert\n";
        cout << "2. Delete max\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> x;
            insertPQ(x);
            break;
        case 2:
            x = deleteMaxPQ();
            if (x != -1)
                cout << "Deleted max: " << x << endl;
            break;
        case 3:
            displayPQ();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
