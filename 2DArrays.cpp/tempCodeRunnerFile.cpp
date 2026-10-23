#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows/columns";
    cin>>n;
    int arr[n][n];
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    // normal printing
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // transpose the matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n-1; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    // normal printing
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}