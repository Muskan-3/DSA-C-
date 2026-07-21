#include <iostream>
#include <algorithm>   
#include <climits>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left= NULL;
        this->right= NULL;
    }
};
int levels(TreeNode* root){
    if(root==NULL) return 0;
    int leftLevel= levels(root->left);
    int rightlevel= levels(root->right);
    return 1 + max(leftLevel , rightlevel); 
}
void nthLevlels(TreeNode* root, int curr, int level){
    if(root==NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return;
    }
    nthLevlels(root->left, curr+1,level );
    nthLevlels(root->right, curr+1,level );
}
void levelOrderTraversal(TreeNode* root){
    int n = levels(root);
    for(int i = 1; i<=n; i++){
        nthLevlels(root, 1, i);
        cout<<endl;
    }
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
  
    a->left =b;
    a->right = c;
    b->left = d;
    b->right =e;
    c->left = f;
    c->right = g;

    levelOrderTraversal(a);

}