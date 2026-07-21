#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* construct(int arr[], int n){
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()>0 && i<n){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;
         
        if(i<n && arr[i]!=INT_MIN){
          l = new TreeNode(arr[i]);
        }
        else{
             l = NULL;
        }
        if(j<n && arr[j]!=INT_MIN){
          r = new TreeNode(arr[j]);
        }
        else{
             r = NULL;
        }

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;

    }
    return root;
}

void leftboundary(TreeNode* root){
    if(root==NULL) return;
    // if(leaf node so return)
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->val<<" ";

    leftboundary(root->left);
 
    if(root->left==NULL) leftboundary(root->right);  
}
// same as preOrder traversal just extra condition is there
void bottomBoundaries(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        cout<<root->val<<" ";
    }
    bottomBoundaries(root->left);
    bottomBoundaries(root->right);
}
// But in reverse order we need so call ke baad print karo okay
void rightboundary(TreeNode* root){
    if(root==NULL) return;
    // if(leaf node so return)
    if(root->left==NULL && root->right==NULL){
        return;
    }

    rightboundary(root->right);

    if(root->right==NULL) rightboundary(root->left);  

    cout<<root->val<<" ";
}
void boundary(TreeNode* root){
    leftboundary(root);
    bottomBoundaries(root);
    rightboundary(root->right);
    return;
}
int main(){
    int arr[]= {1,2,3,4,5,INT_MIN, 6,7, INT_MIN,8, INT_MIN,9,10,INT_MIN,11, INT_MIN, 12, INT_MIN,13, INT_MIN, 14,15,16,INT_MIN,17,INT_MIN, INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    boundary(root);
}