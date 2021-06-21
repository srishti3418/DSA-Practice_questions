//Most optimized solution(Using recursion and hashmap)
//TC: O(n)
//SC: O(n)
class Solution {
public:
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int st, int end, unordered_map<int, int> &m, int *post_idx){
        if(st>end)
            return NULL;
        int val=postorder[(*post_idx)--];
        TreeNode *root=new TreeNode(val);
        if(st==end)
            return root;
        int index=m[val];
        root->right=buildTree(inorder, postorder, index+1, end, m, post_idx);
        root->left=buildTree(inorder, postorder, st, index-1, m, post_idx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> m;
        for(int i=0; i<n;i++){
            m[inorder[i]]=i;
        }
        int post_idx=n-1;
        return buildTree(inorder, postorder, 0, n-1, m, &post_idx);
    }
};
