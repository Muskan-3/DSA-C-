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

    // column wise print
    for(int j =0; j<n; j++){
        for(int i=0; i<m; i++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}