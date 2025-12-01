#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Insert a node at the end of circular linked list
void insertEnd(Node* &head, int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        // First node: points to itself
        head = newNode;
        newNode->next = head;
        return;
    }

    // Traverse to last node (whose next is head)
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;  // new node points back to head
}

// Display all nodes and repeat head value at end
void displayWithHeadRepeat(Node *head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;

    // Traverse whole circular list
    cout << "Circular Linked List (with head repeated at end): ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // Repeat head node value
    cout << head->data << " ";

    cout << endl;
}

int main() {
    Node *head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(head, val);
    }

    displayWithHeadRepeat(head);

    return 0;
}
