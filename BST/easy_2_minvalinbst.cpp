//Most optimized solution
//TC: O(h)
//SC: O(h)
int minValue(Node* root)
{
    // Code here
    if(root==NULL)
        return -1;
    if(root->left==NULL)
        return root->data;
    return minValue(root->left);
}
