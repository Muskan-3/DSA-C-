
#include <iostream>
#include <vector>
using namespace std;

// Tree Node structure
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Recursive Preorder Traversal
void preorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;

    ans.push_back(root->val);

    preorder(root->left, ans);
    preorder(root->right, ans);
}


// Recursive Inorder Traversal
void preorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    preorder(root->left, ans);
    ans.push_back(root->val);
    preorder(root->right, ans);
}

// Recursive PostOrder Traversal
void preorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    preorder(root->left, ans);
    preorder(root->right, ans);
    ans.push_back(root->val);
}

int main() {

    // Create the binary tree 
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Store traversal result
    vector<int> ans;

    preorder(root, ans);

    // Print the result
    cout << "Preorder Traversal: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
