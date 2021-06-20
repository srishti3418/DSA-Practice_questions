//Optimized solution
//TC: O(n)
//SC: O(height of the tree)
class Solution
{
public:
    
    int height(Node *root){
        if(root==NULL)
            return 0;
        return max(height(root->left), height(root->right))+1;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root==NULL)   
            return 0;
        
        int leftpart = sumOfLongRootToLeafPath(root->left);
        int rightpart = sumOfLongRootToLeafPath(root->right);
        
        int lefth=height(root->left);
        int righth=height(root->right);
        
        if(lefth>righth)
            return leftpart+root->data;
        else if(lefth<righth)
            return rightpart+root->data;
        else
            return max(leftpart+root->data, rightpart+root->data);
    }
};
