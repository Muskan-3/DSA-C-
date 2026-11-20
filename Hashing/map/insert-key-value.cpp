#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int, int>m;
    m[10] = 100;
    m[20] = 10;
    m[30] = 33;

    cout<<m[10];

    return 0;


}