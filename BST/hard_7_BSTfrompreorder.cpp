#include <iostream>
#include <climits>
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

//M1 (Brute force approach)
//TC: O(n^2)
//SC: O(h)
Node *createnode(Node *root, int key){
    if(root==NULL)
        return new Node(key);
    if(key<root->data)
        root->left=createnode(root->left, key);
    if(key>root->data)
        root->right=createnode(root->right, key);
    
    return root;
}

//M2 
//TC: O(n^2)
//SC: O(h)
Node *createbst(int arr[], int *preindex, int low, int high, int size){
    if(*preindex>=size || low>high)
        return NULL;
    
    Node *root=new Node(arr[*preindex]);
    *preindex=*preindex+1;

    if(low==high)
        return root;

    int i;
    for(i=low; i<=high; i++){
        if(arr[i]>root->data)
            break;
    }

    root->left=createbst(arr, preindex, *preindex, i-1, size);
    root->right=createbst(arr, preindex, i, high, size);
    return root;
}

Node *createbst(int arr[], int n){
    int preindex=0;
    return createbst(arr, &preindex, 0, n-1, n);
}

//Most optimized solution
//TC: O(n)
//SC: O(h)
Node *createbst2(int arr[], int *preindex, int key, int min, int max, int size){
    if(*preindex>=size)
        return NULL;

    Node *root=NULL;
    if(key>min && key<max){

        root=new Node(key);
        *preindex=*preindex+1;

        if(*preindex<size){
            root->left=createbst2(arr, preindex, arr[*preindex], min, key, size);
        }
        if(*preindex<size){
            root->right=createbst2(arr, preindex, arr[*preindex], key, max, size);
        }

    }
    return root;
}

Node *createbst2(int arr[], int n){
    int preindex=0;
    return createbst2(arr, &preindex, arr[0], INT_MIN, INT_MAX, n);
}


void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    
    int arr[]={10, 5, 1, 7, 40, 50};
    //Node *root=new Node(arr[0]);
    int n=sizeof(arr)/sizeof(arr[0]);
    /*for(int i=1; i<n; i++){
        createnode(root, arr[i]);
    }*/
    //Node* root=createbst(arr, n);
    Node *root=createbst2(arr, n);
    inorder(root);
    cout<<endl;
}
