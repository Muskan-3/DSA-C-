#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    // since it will be a square matrix
    int m;
    cout<<"Enter the no of rows/cols: ";
    cin>>m;
    int arr[m][m];
    for(int i=0; i<m; i++){
        for(int j =0; j<m; j++){
            cin>>arr[i][j];
        }
    } 
    cout<<endl;
    
    for(int i=0; i<m; i++){
        for(int j =0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
   
    for(int i=0; i<m; i++){
        for(int j =i+1; j<m; j++){
            if(i==j){
                continue;
            }
            else{
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j =0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


}