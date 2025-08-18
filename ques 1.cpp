#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX], n = 0;

// CREATE
void create() {
    cout << "Enter number of elements: ";
    cin >> n;
   
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
 
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insert() {
    int pos, val;
 
    cout << "Enter position (1 to " << n+1 << "): ";
    cin >> pos;
    if(pos < 1 || pos > n+1) {
        cout << "Invalid position!" << endl;
        return;
    }
    cout << "Enter value to insert: ";
    cin >> val;
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = val;
    n++;
}

void deleteElement() {
    int pos;
  
    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;
  
    cout << "Deleted element: " << arr[pos-1] << endl;
    for(int i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}

void linearSearch() {
    int key;
    bool found = false;
    if(n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Enter element to search: ";
    cin >> key;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position " << i+1 << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "Element not found!" << endl;
}

int main() {
    int choice;
    do {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);

    return 0;
}
