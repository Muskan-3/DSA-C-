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

    // Print in S pattern
    for(int i =n-1; i>=0; i--){
        // if even then print it like normal left ro right
        if(i%2==0){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
        }
        // odd then reverse it
        else{
            for(int j =n-1; j>=0; j--){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}