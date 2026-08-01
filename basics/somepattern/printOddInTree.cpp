#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {        // Rows
        for (int j = 1; j <= i; j++) {    // Columns
            cout << 2 * j - 1;
        }
        cout << endl;
    }

    return 0;
}