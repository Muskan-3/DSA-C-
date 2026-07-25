#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr[] = {4,5,-6,-2,1,8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k=4;

    // maxheap
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    cout<<pq.top();
}