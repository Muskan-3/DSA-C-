#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> set;
    set.insert(10);
    set.insert(20);
    set.insert(30);
    set.insert(40);

    set.erase(20);

    for(auto x: set){
        cout<<x<<endl;
    }


}

