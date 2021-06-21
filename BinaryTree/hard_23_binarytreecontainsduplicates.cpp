//Most optimized solution(Using recursion and hashmap)
//TC: O(n)
//SC: O(n)
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

        node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

string checkduplicates(node *root, unordered_map<string, int> &m){
    string s="";
    if(!root)
        return '$';
    if(!root->left && !root->right){
        s=to_string(root->data);
        return s;
    }
    s = s+to_string(root->data);
    s = s+checkduplicates(root->left);
    s = s+checkduplicates(root->right);
    m[s]++;
    return s;

}

bool checkduplicate_trees(node *root){
    if(root==NULL)
        return false;
    unordered_map<string, int> m;
    checkduplicates(root, m);
    for(auto x:m){
        if(x.second>=2)
            return true;
    }
    return false;
    
}

int main(){
    node *root=new node(1);
    root->left=new node(-2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(-6);
    root->right->right=new node(2);
    
    cout<<checkduplicate_trees(root)<<endl;
    
    
}
