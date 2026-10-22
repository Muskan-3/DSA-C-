#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no of rows: ";
    cin>>n;
    int m;
    cout<<"Enter the no of columns: ";
    cin>>m;
    int arr[n][m];
    cout<<"Enter the elements: ";
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(arr[i][j]>max){
                max = arr[i][j];
            }
        }
    }
    cout<<"Maximum element is: "<<max;
}