#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[50];
    int idx;

    MaxHeap() {
        idx = 1;
    }

    int top() {
        return arr[1];
    }

    int size() {
        return idx - 1;
    }

    void display() {
        for (int i = 1; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void push(int x) {

        arr[idx] = x;

        int i = idx;
        idx++;

        // Heapify Up
        while (i > 1) {

            int parent = i / 2;

            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else {
                break;
            }
        }
    }
};

int main() {

    MaxHeap pq;

    pq.push(20);
    pq.push(15);
    pq.push(10);
    pq.push(30);

    cout << "Top = " << pq.top() << endl;

    pq.display();
}