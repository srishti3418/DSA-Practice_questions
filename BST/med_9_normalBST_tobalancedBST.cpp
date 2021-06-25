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
//SC: O(n)
void inorder(Node *root, vector<int> &vec){
    if(root==NULL)
        return;
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

void preorder(Node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


Node *BuildTree(vector<int> &vec, int low, int high){
    if(low>high)
        return NULL;
    int mid=(low+high)/2;
    Node *root=new Node(vec[mid]);
    root->left=BuildTree(vec, low, mid-1);
    root->right=BuildTree(vec, mid+1, high);
    return root;
}

int main(){
    
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    vector<int> vec;
    inorder(root, vec);
    root=BuildTree(vec, 0, vec.size()-1);
    preorder(root);
    cout<<endl;
}
