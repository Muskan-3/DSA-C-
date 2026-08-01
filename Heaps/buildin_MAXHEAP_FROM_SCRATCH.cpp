#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[50];
    int idx;

    MaxHeap() {
        idx = 0;
    }

    int top() {
        return arr[0];
    }

    int size() {
        return idx;
    }

    void display() {
        for (int i = 0; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Insert
    void push(int x) {

        arr[idx] = x;
        int i = idx;
        idx++;

        // Heapify Up
        while (i > 0) {

            int parent = (i - 1) / 2;

            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else {
                break;
            }
        }
    }

    // Delete Root
    void pop() {

        if (idx == 0)
            return;

        // Replace root with last element
        arr[0] = arr[idx - 1];
        idx--;

        int i = 0;

        // Heapify Down
        while (true) {

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // Assume current node is the largest
            int largest = i;

            // Check left child
            if (left < idx && arr[left] > arr[largest]) {
                largest = left;
            }

            // Check right child
            if (right < idx && arr[right] > arr[largest]) {
                largest = right;
            }

            // Heap property satisfied
            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }
};

int main() {

    MaxHeap pq;

    pq.push(20);
    pq.push(15);
    pq.push(10);
    pq.push(30);
    pq.push(40);

    cout << "Heap: ";
    pq.display();

    cout << "Top = " << pq.top() << endl;

    pq.pop();

    cout << "After Pop: ";
    pq.display();

    return 0;
}