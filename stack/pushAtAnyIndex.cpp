#include<iostream>
#include<stack>
using namespace std;
// pass by reference - doing changes in the same stack not creating new stack every time
void print(stack<int> &st){
    stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        st.push(temp.top());
        cout<<temp.top()<<endl;
        temp.pop();
    }
}
void pushAtAnyIdex(stack<int> &st, int idx, int val){
    if (idx < 0 || idx > st.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    stack<int>temp;
    while(st.size()>idx){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    print(st);

    cout<<endl;

    pushAtAnyIdex(st, 2, 22);

    print(st);

}