#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int maxNoOfStringPairs(vector<string> &words){
    int n = words.size();
    int count = 0;
    unordered_set<string> s;
    for(int i =0; i<n; i++){
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        if(words[i]==rev) continue;
        if(s.find(rev)!=s.end()){
            count++;
            s.erase(words[i]);
        }
        else s.insert(words[i]);
    }
    return count;
}

int main(){
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter the strings: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << "Maximum Number of String Pairs = "
         << maxNoOfStringPairs(words);

    return 0;
  
}