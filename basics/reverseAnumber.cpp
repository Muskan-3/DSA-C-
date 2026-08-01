#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int reverse = 0;
    while(n>0){
        int lastDigit = n % 10;
        reverse *= 10;
        reverse+=lastDigit;
        n /=10;
    }
    cout<<reverse;
}