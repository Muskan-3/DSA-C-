#include<iostream>
using namespace std;
int main(){
    int n, count=0;
    cout<<"Enter a number:";
    cin>>n;

    if(n==0) count=1;

    else{
        // hadles negative numbers
        n = abs(n);

        while(n>0){
            // count one digit
            count++;
            
            // remove one digit
            n = n/10;
        }
    }
    cout<<"Number of digits = "<<count;
    return 0;

}