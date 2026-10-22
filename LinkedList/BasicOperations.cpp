
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

        for (int i = 0; i < idx - 1; i++) {
            t = t->next;
        }

        temp->next = t->next;
        t->next = temp;
        size++;
    }

    // Get value at any index
    int getAtIndex(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }

        Node* temp = head;

        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    // Delete at head
    void deleteAtHead() {
        if (size == 0) {
            cout << "Your list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

        if (size == 0) {
            tail = NULL;
        }
    }

    // Delete at tail
    void deleteAtTail() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        if (size == 1) {
            delete head;
            head = tail = NULL;
            size = 0;
            return;
        }

        Node* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
        size--;
    }

    // Delete at any index
    void deleteAANyIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return;
        }

        if (idx == 0) {
            deleteAtHead();
            return;
        }

        if (idx == size - 1) {
            deleteAtTail();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        delete nodeToDelete;
        size--;
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

    // Destructor: free all remaining nodes
    ~LinkedList() {
        Node* temp = head;

        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList ll;

    ll.insertAtHead(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.insertAtTail(50);

    cout << "Value at index 2: "
         << ll.getAtIndex(2) << endl;

    ll.display();

    ll.deleteAtHead();
    cout << "After deleting head: ";
    ll.display();

    ll.deleteAtTail();
    cout << "After deleting tail: ";
    ll.display();

    ll.deleteAANyIdx(1);
    cout << "After deleting index 1: ";
    ll.display();

    return 0;
}
