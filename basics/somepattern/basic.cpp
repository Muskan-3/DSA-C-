#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no of rows:";
    cin>>n;
    int m;
    cout<<"Enter no of columns:";
    cin>>m;
    for(int i=0; i<n; i++){
        for(int j =0; j<m;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}