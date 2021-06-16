void inorder(binarytreenode<int>* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorder_iterative(binarytreenode<int>* root){
    if(root==NULL)
        return;
    stack<binarytreenode<int>*> s;
    binarytreenode<int> *curr=root;
    
    while(!s.empty() || curr!=NULL){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            curr=s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
    return;
}
