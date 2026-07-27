#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> pi;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    // Max Heap
    priority_queue<pi> pq;

    for (int ele : arr) {
        int distance = abs(x - ele);

        pq.push({distance, ele});

        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;

    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    // find 4 closest element to 3 
    int k = 4;
    int x = 3;

    vector<int> ans = findClosestElements(arr, k, x);

    cout << "Closest Elements: ";

    for (int ele : ans) {
        cout << ele << " ";
    }

    return 0;
}