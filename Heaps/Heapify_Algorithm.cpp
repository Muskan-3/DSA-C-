#include<iostream>
using namespace std;
    void print(int arr[], int n ){
        for(int i =0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(int arr[], int n, int i ){
        while (true) {
            //  as its 0 based indexing we can do it like this 2* i + 1;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // No child exists
            if (left >= n) {
                break;
            }

            // Only left child exists
            if (right >= n) {
                if (arr[i] > arr[left]) {
                    swap(arr[i], arr[left]);
                    i = left;
                }
                break;
            }

            // Both children exist
            if (arr[left] < arr[right]) {
                if (arr[i] > arr[left]) {
                    swap(arr[i], arr[left]);
                    i = left;
                } else {
                    break;
                }
            } 
            else {
                if (arr[i] > arr[right]) {
                    swap(arr[i], arr[right]);
                    i = right;
                } else {
                    break;
                }
            }
        }
    }
    int main(){
        int arr[] = {10,2,14,11,1,4};
        int n = sizeof(arr)/ sizeof(arr[0]);
        print(arr, n);

        for(int i=n/2-1; i>=0;i--){
            heapify(arr, n, i);
        }
        print(arr, n);
    }