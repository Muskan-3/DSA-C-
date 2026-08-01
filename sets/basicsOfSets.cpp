#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(3);
    s.insert(4);

    cout<<s.size();
    cout<<endl;

    s.erase(2);

    
    for(int elem: s){
        cout<<elem;
    }
    cout<<endl;

    int target =4;
    if(s.find(target)!=s.end()){
        cout<<"It exists";
    }
    else{
        cout<<"No";
    }
}