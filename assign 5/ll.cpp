#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class list {
    Node* head;
    Node* tail;
public:
    list() {
        head = tail = NULL;
    }

    // Insert at the front
    void push_front(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {   // if empty
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // Insert at the end
    void push_back(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {   // if empty
            head = tail = newnode;
        } else {
            tail->next = newnode; // link old tail to new node
            tail = newnode;       // update tail
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    list ll;
    ll.push_front(3);   // List: 3
    ll.push_front(5);   // List: 5 -> 3
    ll.push_front(7);   // List: 7 -> 5 -> 3
    ll.push_back(10);   // List: 7 -> 5 -> 3 -> 10
    ll.push_back(20);   // List: 7 -> 5 -> 3 -> 10 -> 20

    ll.display();
}
