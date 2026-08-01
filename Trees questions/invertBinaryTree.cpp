#include<iostream>
#include<climits>
#include<queue>
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

TreeNode* construct(int arr[], int n){

    if(n == 0 || arr[0] == INT_MIN)
        return NULL;

    queue<TreeNode*> q;

    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;

    while(!q.empty() && i < n){

        TreeNode* temp = q.front();
        q.pop();

        // Create left child
        if(i < n && arr[i] != -1){
            temp->left = new TreeNode(arr[i]);
            q.push(temp->left);
        }
        i++;

        // Create right child
        if(i < n && arr[i] != -1){
            temp->right = new TreeNode(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

void display(TreeNode* root){

    if(root == NULL)
        return;

    cout << root->val << " ";

    display(root->left);
    display(root->right);
}

void invertTree(TreeNode* root){

    if(root == NULL)
        return;

    // Swap left and right children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Invert left subtree
    invertTree(root->left);

    // Invert right subtree
    invertTree(root->right);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = construct(arr, n);

    cout << "Before Inversion: ";
    display(root);

    invertTree(root);

    cout << endl;

    cout << "After Inversion: ";
    display(root);

    return 0;
}