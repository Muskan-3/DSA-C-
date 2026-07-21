#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Construct Tree
TreeNode* construct(int arr[], int n){

    if(n == 0 || arr[0] == INT_MIN)
        return NULL;

    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    int j = 2;

    while(!q.empty() && i < n){

        TreeNode* temp = q.front();
        q.pop();

        TreeNode* l = NULL;
        TreeNode* r = NULL;

        if(i < n && arr[i] != INT_MIN)
            l = new TreeNode(arr[i]);

        if(j < n && arr[j] != INT_MIN)
            r = new TreeNode(arr[j]);

        temp->left = l;
        temp->right = r;

        if(l) q.push(l);
        if(r) q.push(r);

        i += 2;
        j += 2;
    }

    return root;
}

// Height of Tree
int level(TreeNode* root){

    if(root == NULL)
        return 0;

    return 1 + max(level(root->left), level(root->right));
}

// Print nth level and store last node
void nthLevels(TreeNode* root, int curr, int lev, vector<int>& ans){

    if(root == NULL)
        return;

    if(curr == lev){
        ans[curr] = root->val;
        return;
    }

    nthLevels(root->left, curr + 1, lev, ans);
    nthLevels(root->right, curr + 1, lev, ans);
}

// Recursive Level Order
void levelOrderTraversal(TreeNode* root, vector<int>& ans){

    int n = ans.size();

    for(int i = 0; i < n; i++){
        nthLevels(root, 0, i, ans);
    }
}

// Right Side View
vector<int> rightSideView(TreeNode* root){

    vector<int> ans(level(root), 0);

    levelOrderTraversal(root, ans);

    return ans;
}

int main(){

    // INT_MIN represents NULL
    int arr[] = {1,2,3,4,5,6,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = construct(arr, n);

    vector<int> ans = rightSideView(root);

    cout << "Right Side View: ";

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}