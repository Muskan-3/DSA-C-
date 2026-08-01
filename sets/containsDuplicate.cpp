#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containDuplicate(vector<int> &nums) {

    unordered_set<int> s;

    for (int num : nums) {

        if (s.find(num) != s.end()) {
            return true;
        }

        s.insert(num);
    }

    return false;
}

int main() {

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (containDuplicate(nums))
        cout << "True";
    else
        cout << "False";

    return 0;
}