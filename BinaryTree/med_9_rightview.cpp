// Should return  right view of tree
//Most optimized solution
//TC: O(n) (both iterative and recursive solution takes O(n) time and O(n) space)
//SC: O(n)
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(root==NULL)
        return ans;
       queue<Node *> q;
       q.push(root);
       
       while(!q.empty()){
           int n=q.size();
           for(int i=1;i<=n;i++){
               
               Node *node=q.front();
               q.pop();
               
               if(i==n)
                    ans.push_back(node->data);
               if(node->left)
                    q.push(node->left);
               if(node->right)
                    q.push(node->right);
               
           }
       }
       return ans;
    }
};

