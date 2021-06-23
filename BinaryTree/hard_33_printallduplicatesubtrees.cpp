//Most optimized solution
//TC: O(n)
//SC: O(n)
class Solution {
public:
    unordered_map<string, int> m;
    string pushAllDups(TreeNode *root, vector<TreeNode *> &res){
        if(root==NULL){
            return "$";
        }

        string s = to_string(root->val)+" ";
        s += pushAllDups(root->left, res);
        s += pushAllDups(root->right, res);

        if(m[s]==1)
            res.push_back(root);
        m[s]++;
        return s;
    
}

    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> res;
        pushAllDups(root, res);
        return res;
    }
};
