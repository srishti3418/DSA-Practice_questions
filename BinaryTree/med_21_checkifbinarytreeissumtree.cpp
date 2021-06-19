//Most optimized solution
//TC: O(n)
//SC: O(height of the tree)
class Solution
{
    public:
    bool isLeaf(Node *root){
        if(root==NULL)
            return false;
        if(!root->left && !root->right)
            return true;
        return false;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         int ls=0, rs=0;
         if(root==NULL || isLeaf(root))
            return true;
         
         if(isSumTree(root->left) && isSumTree(root->right)){
             if(root->left==NULL)
                ls=0;
             else if(isLeaf(root->left))
                ls=root->left->data;
             else
                ls=2*root->left->data;
                
             if(root->right==NULL)
                rs=0;
             else if(isLeaf(root->right))
                rs=root->right->data;
             else
                rs=2*root->right->data;
            
             if(root->data==ls+rs)
                return true;
         }
         return false;
    }
};
