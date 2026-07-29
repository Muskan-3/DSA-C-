#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[50];
    int idx;

    MinHeap() {
        idx = 1;
    }

    int top() {
        if (idx == 1) return -1;
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

        while (i != 1) {
            int parent = i / 2;

            if (arr[i] < arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (idx == 1) {
            return;
        }

        idx--;
        arr[1] = arr[idx];

        int i = 1;

        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;

            // No child exists
            if (left >= idx) {
                break;
            }

            // Only left child exists
            if (right >= idx) {
                if (arr[i] > arr[left]) {
                    swap(arr[i], arr[left]);
                    i = left;
                }
                break;
            }

            // Both children exist
            if (arr[left] < arr[right]) {
                if (arr[i] > arr[left]) {
                    swap(arr[i], arr[left]);
                    i = left;
                } else {
                    break;
                }
            } else {
                if (arr[i] > arr[right]) {
                    swap(arr[i], arr[right]);
                    i = right;
                } else {
                    break;
                }
            }
        }
    }
};

int main() {
    MinHeap pq;

    pq.push(10);
    pq.push(20);

    cout << pq.top() << " " << pq.size() << endl;

    pq.push(11);
    pq.push(2);

    cout << pq.top() << " " << pq.size() << endl;

    pq.display();

    pq.pop();

    cout << pq.top() << " " << pq.size() << endl;

    pq.display();

    return 0;
}