//Most optimized solution
//TC: O(n)
//SC: O(height of the tree)
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node *root){
        if(root==NULL)
            return 0;
        int lefth=height(root->left);
        int righth=height(root->right);
        
        return max(lefth, righth)+1;
    }
    int diameter(Node* root) {
        // Your code here
        if(root==NULL)
            return 0;
            
        int heightleft=height(root->left);
        int heightright=height(root->right);
        
        int leftdiam=diameter(root->left);
        int rightdiam=diameter(root->right);
        
        return max(max(leftdiam, rightdiam), heightleft+heightright+1);
        
    }
};
