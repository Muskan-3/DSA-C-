
#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;

// Tree Node
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

// 1. Iterative Preorder: Root, Left, Right
void preorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->val);

        if (node->right != NULL)
            st.push(node->right);

        if (node->left != NULL)
            st.push(node->left);
    }
}

// 2. Iterative Inorder: Left, Root, Right
void inorder(TreeNode* root, vector<int>& ans) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->val);

        curr = curr->right;
    }
}

// 3. Iterative Postorder: Left, Right, Root
void postorder(TreeNode* root, vector<int>& ans) {
    stack<TreeNode*> st;
    if(root!=NULL){
        st.push(root);
    }
    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);

        if(temp->left!=NULL){
            st.push(temp->left);
        }
        if(temp->right!=NULL){
            st.push(temp->right);
        }
    }
    reverse(ans.begin(), ans.end());

}

int main() {

    // Create Binary Tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Preorder
    vector<int> pre;
    preorder(root, pre);

    cout << "Preorder: ";
    for (int x : pre)
        cout << x << " ";

    // Inorder
    vector<int> in;
    inorder(root, in);

    cout << "\nInorder: ";
    for (int x : in)
        cout << x << " ";

    // Postorder
    vector<int> post;
    postorder(root, post);

    cout << "\nPostorder: ";
    for (int x : post)
        cout << x << " ";

    return 0;
}
