#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};
// approch 1
bool hasPathSum(TreeNode* root, int targetSum) {

    if (root == NULL)
        return false;

    // If current node is a leaf
    if (root->left == NULL && root->right == NULL)
        return root->val == targetSum;

    // Subtract current node's value
    targetSum = targetSum - root->val;

    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
}

// approach 2
bool hasPathSumByAdding(TreeNode* root, int sum, int targetSum){
    if(root==NULL) return false;
    sum +=root->val;
    if(root->left==NULL && root->right==NULL){
        return sum == targetSum;
    }
    bool foundInleftTree =hasPathSumByAdding(root->left,sum, targetSum);
    bool foundInrightTree =hasPathSumByAdding(root->right, sum, targetSum);
    return  foundInleftTree || foundInrightTree;
}
int main() {

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    int targetSum = 22;

    // if (hasPathSum(root, targetSum))
    //     cout << "Path exists";
    // else
    //     cout << "Path does not exist";

    bool result =hasPathSumByAdding(root, 0, targetSum);
    if(result){
        cout<< " path exists";
    }
    else{
        cout<<"not exist";
    }
    

    return 0;
}