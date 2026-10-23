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
        for(int j=i+1; j<n; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    cout<<endl;
    // reverse each row 
    for(int k=0; k<n; k++){
        int i=0;
        int j=n-1;
        while(i<j){
            int temp = arr[k][i];
            arr[k][i]= arr[k][j];
            arr[k][j]= temp;
            i++;
            j--;
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
}

// rotation by 90 degree of 
// 1 2 3 
// 4 5 6 
// 7 8 9
// is 

// 7 4 1 
// 8 5 2 
// 9 6 3 
