//Most optimized solution
//TC: O(n*h*h)
//SC: O(h)
#include <iostream>
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

void print_all_ksum(Node *root, vector<int> &path, int k){
    if(root==NULL)
        return;

    path.push_back(root->data);
    print_all_ksum(root->left, path, k);
    print_all_ksum(root->right, path, k);

    int f=0;
    for(int j=path.size()-1; j>=0; j--){

        f += path[j];
        if(f==k){
            for(int i=j; i<path.size(); i++)
                cout<<path[i]<<" ";
            cout<<endl;
        }

    }
    path.pop_back();
    return;
}

int main(){
    int k;
    cin>>k;
    Node *root=new Node(1);
    root->left=new Node(3);
    root->right=new Node(-1);
    root->left->left=new Node(2);
    root->left->right=new Node(1);
    root->left->right->left=new Node(1);
    root->right=new Node(-1);
    root->right->left=new Node(4);
    root->right->right=new Node(5);
    root->right->left->left=new Node(1);
    root->right->left->right=new Node(2);
    root->right->right=new Node(5);
    root->right->right->right=new Node(6);

    vector<int> path;
    print_all_ksum(root, path, k);
}
