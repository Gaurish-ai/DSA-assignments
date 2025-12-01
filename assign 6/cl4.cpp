#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev;
    Node *next;
};

// Insert at end of doubly linked list
void insertEnd(Node* &head, char ch) {
    Node *newNode = new Node;
    newNode->data = ch;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to check if doubly linked list is palindrome
bool isPalindrome(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return true;    // empty or single node is palindrome

    // Move right to the last node
    Node *left = head;
    Node *right = head;
    while (right->next != nullptr) {
        right = right->next;
    }

    // Compare from both ends
    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    Node *head = nullptr;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    // Create doubly linked list from string
    for (int i = 0; i < (int)s.length(); i++) {
        insertEnd(head, s[i]);
    }

    if (isPalindrome(head))
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is NOT a palindrome.\n";

    return 0;
}
