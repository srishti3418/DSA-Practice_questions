//Most optimized solution(Using recursion)
//TC: O(n)
//SC: O(n)
#include <iostream>
#include <cmath>
#include <climits>
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

//Using postorder traversal
int max_sum(node *root, int &ans){
    if(root==NULL)
        return 0;
    int leftpart = max_sum(root->left, ans);
    int rightpart = max_sum(root->right, ans);

    int sum=leftpart+rightpart+root->data;
    
    ans=max(ans, sum);
    return sum;
}


int main(){
    node *root=new node(1);
    root->left=new node(-2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(-6);
    root->right->right=new node(2);
    int ans=INT_MIN;
    max_sum(root, ans);
    cout<<ans<<endl;
    
    
}
