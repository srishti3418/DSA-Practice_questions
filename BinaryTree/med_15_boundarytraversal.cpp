//Most optimized solution
//Time complexity: O(n)
//SC: O(n)
class Solution {
public:

    void printleaves(Node *root, vector<int> &ans){
        if(root==NULL)
            return;
        printleaves(root->left, ans);
        if(!(root->left) && !(root->right))
            ans.push_back(root->data);
        printleaves(root->right, ans);
    }

    void printrightboundary(Node *root, vector<int> &ans){
        if(root==NULL)
            return;
        if(root->right){
            printrightboundary(root->right, ans);
            ans.push_back(root->data);
        }
        else if(root->left){
            printrightboundary(root->left, ans);
            ans.push_back(root->data);
        }
    }

    void printleftboundary(Node *root, vector<int> &ans){
        if(root==NULL)
            return;
        if(root->left){
            ans.push_back(root->data);
            printleftboundary(root->left, ans);
        }
        else if(root->right){
            ans.push_back(root->data);
            printleftboundary(root->right, ans);
        }
    }
    
    void printboundary(Node *root, vector<int> &ans){
        if(root==NULL)
            return;
        ans.push_back(root->data);
        printleftboundary(root->left, ans);
        printleaves(root->left, ans);
        printleaves(root->right, ans);
        printrightboundary(root->right, ans);
        
    }

    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)
            return ans;
        printboundary(root, ans);
        return ans;
    }
};
