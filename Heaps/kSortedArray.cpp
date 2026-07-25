#include<iostream>
#include<queue>
using namespace std;

void sorted(int arr[], int n, int k, vector<int>&ans){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i =0; i<n; i++){
        pq.push(arr[i]);

        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    // Add the remaining elements
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
}

int main(){
    int arr[] = {6,5,3,2,8,10};
    int n = sizeof(arr)/ sizeof(arr[0]);

    vector<int> ans;
    int k = 3;
    
    sorted(arr, n, k, ans);

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    
}