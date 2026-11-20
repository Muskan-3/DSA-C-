#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
int main(){
    vector<int> v = {1,2,3,4,5,6,6,6,6,6};
    unordered_map<int, int> map;

    for(int i =0; i<v.size(); i++){
        map[v[i]]++;
    }
    for(auto x: map){
        cout<<x.first<<" - "<<x.second<<endl;
    }
    return 0;

}