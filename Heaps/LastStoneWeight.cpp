#include <iostream>
#include <queue>
using namespace std;

int main() {
    int arr[] = {2, 7, 4, 1, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    priority_queue<int> pq;

    for (int element : arr) {
        pq.push(element);
    }

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if (first != second) {
            pq.push(first - second);
        }
    }

    if (pq.empty()) {
        cout << 0;
    } else {
        cout << pq.top();
    }

    return 0;
}