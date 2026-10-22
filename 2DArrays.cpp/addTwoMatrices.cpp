#include<iostream>
using namespace std;
int main(){
    // addition possible only when the dimensions are same - m*n
    int a[2][3] = {{1,2,1},{1,2,2}};
    int b[2][3] = {{0,1,3},{1,1,0}};
    // calculating the sum
    for(int i =0; i<2;i++){
        for(int j =0; j<3; j++){
            cout<< a[i][j] + b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}