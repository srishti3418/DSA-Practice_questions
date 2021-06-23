//Most efficient and optimized solution
//TC: O(n) {n+2h}
//SC: O(h)
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

Node *LCA(Node *root, int a, int b){
    if(root==NULL)
        return NULL;
    if(root->data==a || root->data==b)
        return root;
    
    Node *left_part=LCA(root->left, a, b);
    Node *right_part=LCA(root->right, a, b);

    if(left_part && right_part)
        return root;
    
    return (left_part) ? left_part : right_part;
}

int findlevel(Node *lca, int x, int level){
    if(lca==NULL)
        return -1;
    if(lca->data==x)
        return level;
    int left_level=findlevel(lca->left, x, level+1);
    if(left_level==-1)
        return findlevel(lca->right, x, level+1);
    return left_level;
}

int find_dis(Node *root, int a, int b){

    Node *lca=LCA(root, a, b);

    int d1=findlevel(lca, a, 0);
    int d2=findlevel(lca, b, 0);

    return d1+d2;
}

int main(){

    int a, b;
    cin>>a>>b;
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    cout<<find_dis(root, a, b)<<endl;

}
