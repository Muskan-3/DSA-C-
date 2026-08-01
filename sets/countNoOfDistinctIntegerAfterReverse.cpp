#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int reverse(int n ){
    int r = 0;
    while(n>0){
        r*=10;
        r+=n%10;
        n/=10;
    }
    return r;
}
int countNoOfDistinctInteger(vector<int> nums){
    int n = nums.size();
    unordered_set< int> s;
    for(int i =0; i<n; i++){
        int rev =  reverse(nums[i]);
        s.insert(rev);
        s.insert(nums[i]);
    }
    return s.size();
}

int main(){
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Number of distinct integers: "
         << countNoOfDistinctInteger(nums);

    return 0;

}