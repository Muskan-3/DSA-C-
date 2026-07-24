#include<iostream>
#include <queue>
using namespace std;
int main(){

    max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top();


    // min heap
    // priority_queue< int, vector<int> , greater<int> > pq;
    // pq.push(10);
    // pq.push(20);
    // pq.push(-6);
    // pq.push(40);
    // cout<<pq.top()<<endl;

}