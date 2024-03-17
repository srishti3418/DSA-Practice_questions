bool rooToLeaf(TreeNode *root, TreeNode *q, vector<int> &arr){
    if(root==NULL) return false;
    arr.push_back(root->val);
    if(root->val==q->val) return true;
    if(rooToLeaf(root->left, q, arr) || rooToLeaf(root->right, q, arr)) return true;
    arr.pop_back();
    return false;
}