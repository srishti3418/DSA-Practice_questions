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


//optimized solution
//TC: O(n). {Once check}
//SC: O(1)
private TreeNode deleteRootNode(TreeNode root) {
        if (root == null) {
            return null;
        }
        if (root.left == null) {
            return root.right;
        }
        if (root.right == null) {
            return root.left;
        }
        TreeNode next = root.right;
        TreeNode pre = null;
        for(; next.left != null; pre = next, next = next.left);
        next.left = root.left;
        if(root.right != next) {
            pre.left = next.right;
            next.right = root.right;
        }
        return next;
    }
    
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode cur = root;
        TreeNode pre = null;
        while(cur != null && cur.val != key) {
            pre = cur;
            if (key < cur.val) {
                cur = cur.left;
            } else if (key > cur.val) {
                cur = cur.right;
            }
        }
        if (pre == null) {
            return deleteRootNode(cur);
        }
        if (pre.left == cur) {
            pre.left = deleteRootNode(cur);
        } else {
            pre.right = deleteRootNode(cur);
        }
        return root;
    }

