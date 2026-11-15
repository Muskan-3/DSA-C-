#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> set;
    set.insert(10);
    set.insert(20);
    set.insert(30);

    if(set.find(22)!=set.end()){
        cout<<"yes its there"<<endl;
    }
    else{
        cout<<"Its not there";
    }

}