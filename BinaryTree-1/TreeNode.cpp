#include <iostream>
#include <algorithm>   
#include <climits>    
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left= NULL;
        this->right= NULL;
    }
};
void display(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
    return;
}
int sum(TreeNode* root){
    if(root == NULL) return 0;
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    int ans = root->val + leftSum + rightSum;
    return ans;
}
int size(TreeNode* root){
    if(root == NULL) return 0;
    int leftSize = size(root->left);
    int rightSize = size(root->right);
    return 1  + leftSize + rightSize;
}
int maxRoot(TreeNode* root){
    if(root == NULL) return INT_MIN;

    int leftMax = maxRoot(root->left);
    int rightMax = maxRoot(root->right);

    return max(root->val, max(leftMax, rightMax));
}

int minRoot(TreeNode* root){
    if(root==NULL) return INT_MAX;
    int leftMin = minRoot(root->left);
    int rightMin = minRoot(root->right);

    return min(root->val, min(leftMin, rightMin));

}
int productOfNodes(TreeNode* root){
    if(root == NULL) return 1;
    return root->val * productOfNodes(root->left) * productOfNodes(root->right);
}

int heightOrLevels(TreeNode* root){
    if(root==NULL) return 0;
    return 1 + max(heightOrLevels(root->left), heightOrLevels(root->right));
}

int levels(TreeNode* root){
    if(root==NULL) return 0;
    int leftLevel= levels(root->left);
    int rightlevel= levels(root->right);
    return 1 + leftLevel + rightlevel; 
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
  
    a->left =b;
    a->right = c;
    b->left = d;
   

    display(a);
    cout<<productOfNodes(a);
    
    // cout<<productOfNodes(a);
    // cout<<levels(a);

    // cout<<endl;
    // cout<<sum(a);
    // cout<<endl;
    // cout<<size(a);
    // cout<<endl;
    // cout<<maxRoot(a);

}