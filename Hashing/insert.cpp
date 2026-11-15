#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> st;
    st.insert(40);
    st.insert(10);
    st.insert(20);
    st.insert(30);
    // trying to insert duplicate elem again but set will only store unoique elems
    st.insert(30);
   
    for(auto x : st){
        cout<<x<<" ";
    }

}