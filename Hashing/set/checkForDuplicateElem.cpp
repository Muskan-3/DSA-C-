#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
    unordered_set<int> set;
    vector<int> v = {10, 20, 30, 40};

    for(int i =0; i<v.size(); i++){
        if(set.find(v[i])!=set.end()){
            cout<<"Duplicate elem exists";
        }
        set.insert(v[i]);
    }

    cout<<"No duplicates";

}