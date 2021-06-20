//Most optimized solution(Using greedy approach)
//TC: O(nlogn)
//SC: O(n)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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

node *createnode(int val){
    node *root=new node(val);
    root->left=NULL;
    root->right=NULL;
    return root;
}
vector<int> ans;
void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
}

int min_swaps(vector<int> ans){
    int n=ans.size();
    int count=0;
    if(n<=1)
        return 0;
    vector<pair<int, int> > vec;
    for(int i=0; i<n; i++){
        vec.push_back(make_pair(ans[i],i));
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++){
        int index=vec[i].second;
        if(index==i)
            continue;
        else{
            swap(vec[i], vec[index]);
            count++;
            i--;
        }
    }
    return count;
}


int main(){
    node *root=createnode(5);
    root->left=createnode(6);
    root->right=createnode(7);
    root->left->left=createnode(8);
    root->left->right=createnode(9);
    root->right->left=createnode(10);
    root->right->right=createnode(11);

    inorder(root);
    cout<<min_swaps(ans)<<endl;
    
}
