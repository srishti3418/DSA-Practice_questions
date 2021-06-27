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
//TC: O(n*h)
//SC :O(n)
Node *insert(Node *root, int data, Node *&succ){
    if(root==NULL)
        return new Node(data);
    
    if(data<root->data){
        succ=root;
        root->left=insert(root->left, data, succ);
    }
    else
        root->right=insert(root->right, data, succ);
    return root;
}

void replace(int arr[], int n){
    Node *root=NULL;
    for(int i=n-1; i>=0; i--){
        Node *succ=NULL;
        root=insert(root, arr[i], succ);
        if(succ)
            arr[i]=succ->data;
        else    
            arr[i]=-1;
    }
}


int main(){

    int arr[] = { 8,  58, 71, 18, 31, 32, 63, 92,
                  43, 3,  91, 93, 25, 80, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);

    replace(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
   
}
