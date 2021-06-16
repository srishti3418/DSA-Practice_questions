void postorder(binarytreenode<int>* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void postorder_iterative(binarytreenode<int>* root){
    if(root==NULL)
        return;
    stack<binarytreenode<int>*> s;
    stack<int> out;
    s.push(root);
    while(!s.empty()){
        binarytreenode<int> *curr=s.top();
        s.pop();
        out.push(curr->data);
        if(curr->left)
            s.push(curr->left);
        if(curr->right)
            s.push(curr->right);
    }
    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();
    }
    return;
}
