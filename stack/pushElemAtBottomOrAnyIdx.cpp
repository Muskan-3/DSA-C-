#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> &st){
    stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    // putting elements back from temp to stacks
    // you will get elements in correct order 
    while(temp.size()>0){
        cout<<temp.top()<<endl;
        st.push(temp.top());
        temp.pop();
    }
}

void pushAtBottom(stack<int> &st, int val){
    stack<int> helper;
    while(st.size()>0){
        helper.push(st.top());
        st.pop();
    }
    st.push(val);
    while(helper.size()>0){
        st.push(helper.top());
        helper.pop();
    }
}
int main(){
    stack<int> st;
    stack<int> helper;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
   
    pushAtBottom(st,80);

    print(st);

}