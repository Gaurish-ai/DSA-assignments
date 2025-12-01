#include <iostream>
using namespace std;

/* ===================== DOUBLY LINKED LIST ===================== */

struct DNode {
    int data;
    DNode *prev;
    DNode *next;
};

// Insert at end of doubly linked list
void insertEndDoubly(DNode* &head, int val) {
    DNode *newNode = new DNode{val, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    DNode *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to find size of doubly linked list
int sizeDoubly(DNode *head) {
    int count = 0;
    DNode *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


/* ===================== CIRCULAR LINKED LIST ===================== */

struct CNode {
    int data;
    CNode *next;
};

// Insert at end of circular linked list
void insertEndCircular(CNode* &head, int val) {
    CNode *newNode = new CNode{val, nullptr};

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;   // points to itself
        return;
    }

    CNode *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Function to find size of circular linked list
int sizeCircular(CNode *head) {
    if (head == nullptr)
        return 0;

    int count = 0;
    CNode *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}


/* ===================== MAIN FUNCTION ===================== */

int main() {
    DNode *dhead = nullptr;
    CNode *chead = nullptr;

    int n, val;

    // Doubly Linked List input
    cout << "Enter number of nodes in Doubly Linked List: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEndDoubly(dhead, val);
    }

    cout << "Size of Doubly Linked List = " << sizeDoubly(dhead) << endl;


    // Circular Linked List input
    cout << "\nEnter number of nodes in Circular Linked List: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEndCircular(chead, val);
    }

    cout << "Size of Circular Linked List = " << sizeCircular(chead) << endl;

    return 0;
}
