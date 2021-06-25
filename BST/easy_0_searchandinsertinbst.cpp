#include <iostream>
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

//TC: O(h)
//SC: O(h)
bool isSearch(Node *root, int key){
    if(root==NULL)
        return false;
    if(key<root->data)
        return isSearch(root->left, key);
    else if(key>root->data)
        return isSearch(root->right, key);
    else    
        return true;
    return false;
}
//TC: O(h)
//SC: O(h)
Node* insert(Node *root, int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key<root->data){
        root->left=insert(root->left, key);
    }
    else if(key>root->data){
        root->right=insert(root->right, key);
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int key;
    cin>>key;
    Node *root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(11);
    root->left->left=new Node(3);
    root->left->right=new Node(7);
    root->left->right->left=new Node(6);

    /*if(isSearch(root, key)) 
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;*/

    insert(root, key);
    inorder(root);
    cout<<endl;
}
