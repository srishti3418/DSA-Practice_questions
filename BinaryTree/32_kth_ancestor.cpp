//Most optimized solution
//TC: O(n)
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

Node *temp=NULL;
int flag=0;
Node *kth_ancestor(Node *root, int &k, int a){
    if(root==NULL)
        return NULL;
    if((root->data==a) || (temp = kth_ancestor(root->left, k, a)) || (temp = kth_ancestor(root->right, k, a))){
            
            if(k>0)
                k--;
            else if(k==0){
                cout<<root->data<<endl;
                flag=1;
                return NULL;
            }
            return root;
        }
}


int main(){

    int k, a;
    cin>>k>>a;
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right ->left= new Node(6);

    kth_ancestor(root, k, a);

    if(flag==0)
        cout<<"-1"<<endl;

}
