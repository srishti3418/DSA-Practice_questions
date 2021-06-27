#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

//Most optimized solution 
//TC: O(n)
//SCL O(h) {Because of recursion}
void inorder(Node *root, Node *&prev){
    if(root==NULL)
        return;
    inorder(root->left, prev);
    prev->left=NULL;
    prev->right=root;
    prev=root;
    inorder(root->right, prev);
}
void printnodes(Node *root){
    if(root==NULL)
        return;
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }
    cout<<endl;
}


int main(){
    
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(7);
    root->left->left = new Node(6);
    root->left->left->left = new Node(5);
    
    Node *dummy=new Node(-1);
    Node *prev=dummy;

    inorder(root, prev);
    prev->left=NULL;
    prev->right=NULL;
    
    Node *newroot=dummy->right;
    printnodes(newroot);
}
