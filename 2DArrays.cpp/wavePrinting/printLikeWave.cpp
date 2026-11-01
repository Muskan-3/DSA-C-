#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter rows of Matrix: ";
    cin >> m;

    cout << "Enter columns of Matrix: ";
    cin >> n;

    int arr[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    // Print in wave pattern
    for(int i = 0; i < m; i++) {
        if(i % 2 == 0) {
            // Even row: left to right
            for(int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        else {
            // Odd row: right to left
            for(int j = n - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}