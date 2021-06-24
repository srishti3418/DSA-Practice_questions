//Most optimized solution
//TC: O(h)
//SC: O(h)
class Solution {
public:
    bool isLeaf(TreeNode *root){
        if(root==NULL)
            return false;
        if(!root->left && !root->right)
            return true;
        return false;
    }
    int successor(TreeNode *root){
        if(root==NULL)
            return NULL;
        root=root->right;
        while(root->left!=NULL)
            root=root->left;
        return root->val;
    }
    int predessor(TreeNode *root){
        if(root==NULL)
            return NULL;
        root=root->left;
        while(root->right!=NULL)
            root=root->right;
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val<key)
            root->right=deleteNode(root->right, key);
        else if(root->val>key)
            root->left=deleteNode(root->left, key);
        else{
            if(isLeaf(root))
                root=NULL;
            else if(root->right){
                root->val=successor(root);
                root->right=deleteNode(root->right, root->val);
            }
            else if(root->left){
                root->val=predessor(root);
                root->left=deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};

