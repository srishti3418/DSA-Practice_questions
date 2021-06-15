//Most optimized solution(Recursion)
//TC: O(n)
//SC: O(n)
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL)
            return 0;
    
        int leftheight=height(node->left);
        int rightheight=height(node->right);
        
        return max(leftheight, rightheight)+1;
    }
};
