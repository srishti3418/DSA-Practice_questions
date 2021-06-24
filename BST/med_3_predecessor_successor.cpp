//Optimized solution
//TC: O(h) {exactly 2h}
//SC: O(h)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    if(root==NULL)
        return;
    if(root->key<key){
        pre=root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if(root->key>key){
        suc=root;
        findPreSuc(root->left, pre, suc, key);
    }
    else{
        Node *temp=root;
        if(root->right){
            temp=root->right;
            while(temp->left!=NULL)
                temp=temp->left;
            suc=temp;
        }
        if(root->left){
            temp=root->left;
            while(temp->right!=NULL)
                temp=temp->right;
            pre=temp;
        }
    }
    return;
}
