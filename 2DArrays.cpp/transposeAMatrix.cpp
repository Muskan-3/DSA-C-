// transpose of the matrix - Just printing
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;
//     int m;
//     cout<<"Enter the number of columns: ";
//     cin>>m;
//     int arr[n][m];
//     for(int i =0; i<n; i++){
//         for(int j =0; j<m; j++){
//             cin>>arr[i][j];
//         }
//     }
//     // normal printing 
//     for(int i =0; i<n; i++){
//         for(int j =0; j<m; j++){
//            cout<<arr[i][j];
//         }
//         cout<<endl;
//     }
//     // Transpose the matrix
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             cout << arr[j][i] << " ";
//         }
//         cout << endl;
//     }
// }

//transpose of a matrix by actually storing it 

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int m;
    cout<<"Enter the number of columns: ";
    cin>>m;
    int arr[n][m];
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    //     // normal printing 
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
           cout<<arr[i][j];
        }
        cout<<endl;
    }
    // store the transpose
    int t[m][n];
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
           t[i][j]=arr[j][i];
        }
    }
     for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
          cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }


    // for(int i =0; i<m; i++){
    //     for(int j =0; j<n; j++){
    //         int temp = res[i][j];
    //         res[i][j] = arr[i][j];
    //         arr[i][j] = temp;
    //     }
    // }
   
}