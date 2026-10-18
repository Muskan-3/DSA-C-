
#include <iostream>
using namespace std;

// User-defined data type
class Node {
public:
    int val;
    Node* next;

    // Constructor
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// User-defined data structure
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    // Insert at tail
    void insertAtTail(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }

        size++;
    }

    // Insert at head
    void insertAtHead(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }

        size++;
    }

    // Insert at any index
    void insertAtAnyIdx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid index" << endl;
            return;
        }

        if (idx == 0) {
            insertAtHead(val);
            return;
        }

        if (idx == size) {
            insertAtTail(val);
            return;
        }

        Node* temp = new Node(val);
        Node* t = head;

        // Reach the node just before the target index
        for (int i = 0; i < idx - 1; i++) {
            t = t->next;
        }

        temp->next = t->next;
        t->next = temp;

        size++;
    }

    // Display the linked list
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList ll;

    ll.insertAtTail(10);
    ll.insertAtHead(20);
    ll.insertAtHead(30);

    ll.display();

    ll.insertAtAnyIdx(2, 100);
    ll.insertAtAnyIdx(0, 5);

    ll.display();

    return 0;
}
