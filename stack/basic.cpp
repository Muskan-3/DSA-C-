#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    stack<int> temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size()<<endl;

    // Printing in reverse order
    // while(st.size()>0){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }

    // store the elements somewhere
    while(st.size()>0){
        cout<<st.top()<<endl;
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    // putting elements from temp to stack
    while(temp.size()>0){
         st.push(temp.top());
         temp.pop();
    }
    cout<<endl;
    cout<<st.top()<<" ";
}