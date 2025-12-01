#include <iostream>
using namespace std;

/* ===================== CIRCULAR LINKED LIST ===================== */

struct CNode {
    int data;
    CNode *next;
};

// Display circular list
void displayCircular(CNode *head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    CNode *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

// Insert at beginning
void insertAtBegCircular(CNode* &head, int val) {
    CNode *newNode = new CNode{val, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode *temp = head;
    while (temp->next != head) temp = temp->next; // last node
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEndCircular(CNode* &head, int val) {
    CNode *newNode = new CNode{val, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Insert after key
void insertAfterCircular(CNode* &head, int key, int val) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    CNode *temp = head;
    do {
        if (temp->data == key) {
            CNode *newNode = new CNode{val, temp->next};
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Key " << key << " not found.\n";
}

// Insert before key
void insertBeforeCircular(CNode* &head, int key, int val) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    // If head itself has the key
    if (head->data == key) {
        insertAtBegCircular(head, val);
        return;
    }

    CNode *prev = nullptr, *curr = head;
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            CNode *newNode = new CNode{val, curr};
            prev->next = newNode;
            return;
        }
    } while (curr != head);

    cout << "Key " << key << " not found.\n";
}

// Delete node with given key
void deleteCircular(CNode* &head, int key) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    CNode *curr = head, *prev = nullptr;

    // Case 1: only one node and it is the key
    if (head->data == key && head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: head is to be deleted (more than one node)
    if (head->data == key) {
        CNode *last = head;
        while (last->next != head) last = last->next;
        last->next = head->next;
        curr = head;
        head = head->next;
        delete curr;
        return;
    }

    // Case 3: node in between or last node
    prev = head;
    curr = head->next;
    while (curr != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
}

// Search node
bool searchCircular(CNode *head, int key) {
    if (!head) return false;
    CNode *temp = head;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

/* ===================== DOUBLY LINKED LIST ===================== */

struct DNode {
    int data;
    DNode *prev;
    DNode *next;
};

// Display doubly list
void displayDoubly(DNode *head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    DNode *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Insert at beginning
void insertAtBegDoubly(DNode* &head, int val) {
    DNode *newNode = new DNode{val, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEndDoubly(DNode* &head, int val) {
    DNode *newNode = new DNode{val, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    DNode *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after key
void insertAfterDoubly(DNode* &head, int key, int val) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    DNode *temp = head;
    while (temp && temp->data != key) temp = temp->next;

    if (!temp) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    DNode *newNode = new DNode{val, temp, temp->next};
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

// Insert before key
void insertBeforeDoubly(DNode* &head, int key, int val) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    // If head is the key
    if (head->data == key) {
        insertAtBegDoubly(head, val);
        return;
    }

    DNode *temp = head->next;
    while (temp && temp->data != key) temp = temp->next;

    if (!temp) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    DNode *newNode = new DNode{val, temp->prev, temp};
    temp->prev->next = newNode;
    temp->prev = newNode;
}

// Delete node with given key
void deleteDoubly(DNode* &head, int key) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    DNode *temp = head;

    // If head is to be deleted
    if (head->data == key) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }

    while (temp && temp->data != key) temp = temp->next;

    if (!temp) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;

    delete temp;
}

// Search in doubly list
bool searchDoubly(DNode *head, int key) {
    DNode *temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

/* ===================== MAIN MENU ===================== */

int main() {
    CNode *chead = nullptr;
    DNode *dhead = nullptr;

    int mainChoice;

    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Circular Linked List Operations\n";
        cout << "2. Doubly Linked List Operations\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int ch, val, key;
            do {
                cout << "\n--- Circular Linked List Menu ---\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert after a node\n";
                cout << "4. Insert before a node\n";
                cout << "5. Delete a node (by value)\n";
                cout << "6. Search for a node\n";
                cout << "7. Display list\n";
                cout << "0. Back to main menu\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> val;
                        insertAtBegCircular(chead, val);
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> val;
                        insertAtEndCircular(chead, val);
                        break;
                    case 3:
                        cout << "Enter key after which to insert: ";
                        cin >> key;
                        cout << "Enter value: ";
                        cin >> val;
                        insertAfterCircular(chead, key, val);
                        break;
                    case 4:
                        cout << "Enter key before which to insert: ";
                        cin >> key;
                        cout << "Enter value: ";
                        cin >> val;
                        insertBeforeCircular(chead, key, val);
                        break;
                    case 5:
                        cout << "Enter value to delete: ";
                        cin >> val;
                        deleteCircular(chead, val);
                        break;
                    case 6:
                        cout << "Enter value to search: ";
                        cin >> val;
                        if (searchCircular(chead, val))
                            cout << "Found\n";
                        else
                            cout << "Not found\n";
                        break;
                    case 7:
                        displayCircular(chead);
                        break;
                }
            } while (ch != 0);
        }
        else if (mainChoice == 2) {
            int ch, val, key;
            do {
                cout << "\n--- Doubly Linked List Menu ---\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert after a node\n";
                cout << "4. Insert before a node\n";
                cout << "5. Delete a node (by value)\n";
                cout << "6. Search for a node\n";
                cout << "7. Display list\n";
                cout << "0. Back to main menu\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> val;
                        insertAtBegDoubly(dhead, val);
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> val;
                        insertAtEndDoubly(dhead, val);
                        break;
                    case 3:
                        cout << "Enter key after which to insert: ";
                        cin >> key;
                        cout << "Enter value: ";
                        cin >> val;
                        insertAfterDoubly(dhead, key, val);
                        break;
                    case 4:
                        cout << "Enter key before which to insert: ";
                        cin >> key;
                        cout << "Enter value: ";
                        cin >> val;
                        insertBeforeDoubly(dhead, key, val);
                        break;
                    case 5:
                        cout << "Enter value to delete: ";
                        cin >> val;
                        deleteDoubly(dhead, val);
                        break;
                    case 6:
                        cout << "Enter value to search: ";
                        cin >> val;
                        if (searchDoubly(dhead, val))
                            cout << "Found\n";
                        else
                            cout << "Not found\n";
                        break;
                    case 7:
                        displayDoubly(dhead);
                        break;
                }
            } while (ch != 0);
        }

    } while (mainChoice != 0);

    return 0;
}
