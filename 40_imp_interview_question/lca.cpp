//Optmized solution
//time complexity: O(N)
//space complexity: O(1)

TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q){
    if(root==NULL || root==p || root==q) return root;
    TreeNode *left=LCA(root->left, p, q);
    TreeNode *right=LCA(root->right, p, q);
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else
        return root;
}