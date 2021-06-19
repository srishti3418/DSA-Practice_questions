//Function to check whether a binary tree is balanced or not.
//Most optimized solution
//TC: O(n)
//SC: O(height of the tree)
int height(Node *root){
    if(root==NULL)
        return 0;
    return max(height(root->left), height(root->right)) +1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL)
        return true;
    
    if(isBalanced(root->left) && isBalanced(root->right)){
        int leftpart=height(root->left);
        int rightpart=height(root->right);
        
        if(abs(leftpart-rightpart)<=1)
            return true;
        return false;
    }
    return false;
}

