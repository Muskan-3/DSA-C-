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
    if(n==0 || arr[0]==-1)
    return NULL;

    
    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*>q;
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
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        if(root==NULL) return;
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}

int main(){
    int arr[]= {1,2,3,4,5,INT_MIN, 6, INT_MIN, INT_MIN, 7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);

    levelOrderTraversal(root);
}