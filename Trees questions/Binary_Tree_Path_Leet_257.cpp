#include <iostream>
#include <vector>
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

void helper(TreeNode* root, string path, vector<string>& ans) {

    if (root == NULL)
        return;

    path += to_string(root->val);

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(path);
        return;
    }

    path += "->";

    helper(root->left, path, ans);
    helper(root->right, path, ans);
}

vector<string> binaryTreePaths(TreeNode* root) {

    vector<string> ans;

    helper(root, "", ans);

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    vector<string> ans = binaryTreePaths(root);

    for (string path : ans) {
        cout << path << endl;
    }

    return 0;
}