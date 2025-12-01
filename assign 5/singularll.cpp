#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;   

    node(int value) {
        data = value;
        next = NULL;
    }
};

class list {
    node* head;
    node* tail;
public:
    list() {
        head = tail = NULL;
    }

    void push_front(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void push_back(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;  // ✅ link old tail to new node
            tail = newnode;
        }
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {  // list became empty
            tail = NULL;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {  // only one node
            delete head;
            head = tail = NULL;
            return;
        }
        node* temp = head;
        while (temp->next != tail) {  // ✅ stop at second-last node
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    int search(int key) {
        node* temp = head;
        int pos = 1;  // positions start from 1
        while (temp != NULL) {
            if (temp->data == key) {
                return pos;   // found
            }
            temp = temp->next;
            pos++;
        }
        return -1; // not found
    }
};

int main() {
    list ll;
    ll.push_front(3);   // 3
    ll.push_front(5);   // 5 -> 3
    ll.push_back(10);   // 5 -> 3 -> 10
    ll.push_back(20);   // 5 -> 3 -> 10 -> 20

    cout << "Initial list: ";
    ll.display();

    ll.pop_front();     // remove 5
    cout << "After pop_front: ";
    ll.display();

    ll.pop_back();      // remove 20
    cout << "After pop_back: ";
    ll.display();
}
