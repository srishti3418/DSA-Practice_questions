void preorder(binarytreenode<int>* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void preorder_iterative(binarytreenode<int>* root){
    if(root==NULL)
        return;
    stack<binarytreenode<int>*> s;
    s.push(root);
    while(!s.empty()){
        binarytreenode<int> *curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
    return;
}
