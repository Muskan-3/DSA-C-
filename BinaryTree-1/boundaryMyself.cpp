#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};
TreeNode* construct(int arr[], int n){
    if(n==0 || arr[0]==-1) return NULL;
    queue<TreeNode*> q;

    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i=1;
    while(!q.empty() && i<n){
        TreeNode* temp = q.front();
        q.pop();
        if(i<n && arr[i]!=-1){
            temp->left = new TreeNode(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(i<n && arr[i]!=-1){
            temp->right = new TreeNode(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
void leftBoundary(TreeNode* root){

    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;

    cout<<root->val<<" ";

    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);

}
void leafBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        cout<<root->val<<" ";
        return;
    }
    leafBoundary(root->left);
    leafBoundary(root->right);
    
}
void rightBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;

    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    cout<<root->val<<" ";
    
}
void boundary(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);

    leafBoundary(root->left);
    leafBoundary(root->right);

    rightBoundary(root->right);
    return;
}

void display(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";

        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr, n);
    boundary(root);
}