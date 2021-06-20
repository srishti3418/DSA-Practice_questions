//Optimized solution(Recursive approach)
//TC: O(n)
//SC: O(height of the tree)
class Solution{
  public:
    /*You are required to complete this method*/
    int leaflevel=0;
    bool check(Node *root, int level){
        if(root==NULL)
            return true;
        if(!root->left && !root->right){
            if(leaflevel==0){
                leaflevel=level;
            }
            return (level==leaflevel);
        }
        
        return check(root->left, level+1) &&
               check(root->right, level+1);
            
    }
    
    bool check(Node *root)
    {
        //Your code here
        if(root==NULL)
            return true;
        int level=0;
        return check(root, level);
    }
};
