#include <iostream>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode (int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

int heightOfBinaryTree(TreeNode *root){
    if(root==NULL)
        return 0;
    int leftHeight=heightOfBinaryTree(root->left);
    int rightheight=heightOfBinaryTree(root->right);

    return 1 + max( leftHeight, rightheight);
}

void Inorder(TreeNode *root){
    if(root==NULL)
        return;

    Inorder(root->left);
    cout <<root->data << " ";
    Inorder(root->right);
}

void PreOrder(TreeNode *root){
    if(root == NULL)
        return;
    cout <<root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(TreeNode *root){
    if(root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main(){
    TreeNode*root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout << heightOfBinaryTree(root) << endl;
    cout << "Inorder:";
    Inorder(root);
    cout <<endl;
    cout << "Preorder:";
    PreOrder(root);
    cout << endl;
    cout << "Postorder:";
    PostOrder(root);
    cout << endl;
}   