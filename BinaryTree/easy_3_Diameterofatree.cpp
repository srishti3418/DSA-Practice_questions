#include<iostream>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;

class binarytreenode{
	public:
	int data;
	binarytreenode*left;
	binarytreenode*right;
		binarytreenode(int data){
			this->data=data;
			left=NULL;
			right=NULL;
					}
		~binarytreenode(){
			delete left;
			delete right;
				}
		   };

binarytreenode *createnode(int val){
    binarytreenode *root=new binarytreenode(val);
    root->left=NULL;
    root->right=NULL;
    return root;
}

void inorder(binarytreenode *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void mirrorify(binarytreenode *root){
    if(root==NULL)
        return;
    binarytreenode *temp=root->left;
    root->left=root->right;
    root->right=temp;
    if(root->left)
        mirrorify(root->left);
    if(root->right)
        mirrorify(root->right);
}

int main(){
	binarytreenode *root=createnode(5);
	root->left=createnode(3);
    root->right=createnode(6);
    root->left->left=createnode(2);
    root->left->right=createnode(4);

    inorder(root);
    cout<<endl;
    mirrorify(root);
    inorder(root);
    cout<<endl;
}
