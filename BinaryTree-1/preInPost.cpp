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

    if(n==0 || arr[0]==-1){
        return NULL;
    }
    // create root NOde
    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*>q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i<n){
        TreeNode* temp = q.front();
        q.pop();
        // create left child;
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

// if you want in different line use the queue size 

void displayLikeATree(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
    int size = q.size();

    while(size--) {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    cout << endl;
}
}
void preOrderTraversal(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrdertraversal(TreeNode* root){
    if(root==NULL) return;
    inOrdertraversal(root->left);
    cout<<root->val<<" ";
    inOrdertraversal(root->right);
}

void postOrderTraversal(TreeNode* root){
    if(root==NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<<" ";

}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr, n);
   
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    inOrdertraversal(root);
    cout<<endl;
    postOrderTraversal(root);
}