// #include<iostream>
// using namespace std;
// int main(){
    // declaration
    // int arr[3][3] = {{1,2,3}, {4,5,6}, {4,8,9}};
    // cout<<arr[0][0]<<endl;
    // cout<<arr[1][2];

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Taking input
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Printing elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
