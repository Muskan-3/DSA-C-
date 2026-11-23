#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int main(){
    unordered_map<int, int>  map;
    // map[key] = value;
    map[10]=100;
    map[20]=200;
    map[30]=300;
    map[40]=400;

    //finding key
    if(map.find(20)!=map.end()){
        cout<<"This key exists!"<<endl;
    }
    else{
        cout<<"Not exists";
    }

    // to find value we need to traverse the map
    for(auto x: map){
        if(x.second==200){
            cout<<"Value 200 is there";
        }
        else{
            "its not there";
        }
    }
    return 0;

}