#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    
    for(int i =2; i<n; i++){
        if(n%i==0){
            return false;
            break;
        }
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter a Number to check whether its Prime or Not: ";
    cin>>n;

    if(isPrime(n)){
        cout<<"Yes a Prime number";
    }
    else{
        cout<<"Not a Prime number";
    }
    return 0;
}