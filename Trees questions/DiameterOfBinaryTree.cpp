#include<iostream>
#include<climits>
#include<queue>
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

int levels(TreeNode* root, int &diameter){

    if(root == NULL)
        return 0;

    int leftLevel = levels(root->left, diameter);
    int rightLevel = levels(root->right, diameter);

    // Diameter passing through current node
    diameter = max(diameter, leftLevel + rightLevel);

    // Return height/levels
    return 1 + max(leftLevel, rightLevel);
}

int diameterOfBinaryTree(TreeNode* root){

    int diameter = 0;

    levels(root, diameter);

    return diameter;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = construct(arr, n);

    display(root);

    cout << endl;

    cout << "Diameter = "
         << diameterOfBinaryTree(root);

}