//Most optimized solution
//TC: O(n)
//SC: O(h)
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool helper(Node *root, int min, int max){
        if(root==NULL)
            return true;
        if(root->data<min || root->data>max)
            return false;
        return helper(root->left, min, root->data-1) &&
               helper(root->right, root->data+1, max);
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        if(root==NULL)
            return true;
        return helper(root, INT_MIN, INT_MAX);
    }
};
