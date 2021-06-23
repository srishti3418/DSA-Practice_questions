class Solution
{
    public:
    
    //Two traversal approach
    //TC: O(n+n)
    //SC: O(2h)
    //Function to return the lowest common ancestor in a Binary Tree.
    /*bool lca(Node *root, int n1, vector<Node*> &path){
        if(root==NULL)
            return false;
        path.push_back(root);
        if(root->data == n1)
            return true;
        if((root->left && lca(root->left, n1, path)) || 
            (root->right && lca(root->right, n1, path)))
            return true;
        path.pop_back();
        return false;
        
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       if(root==NULL)
        return NULL;
       vector<Node *> path1;
       vector<Node *> path2;
       if(!lca(root, n1, path1) || !lca(root, n2, path2))
            return NULL;
       int i=0;
       for(; i<path1.size() && i<path2.size();i++){
           if(path1[i]!=path2[i])
             break;
        }
        return path1[i-1];
    }*/
    
    //Most optimized approach (Using single traversal of the tree)
    //TC: O(n)
    //SC: O(h) (Because of recursion stack)
     Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       if(root==NULL)
            return NULL;
       if(root->data==n1 || root->data==n2)
            return root;
        Node *left_lca=lca(root->left, n1, n2);
        Node *right_lca=lca(root->right, n1, n2);
        
        if(left_lca && right_lca)
            return root;
        
        return (left_lca!=NULL) ? left_lca : right_lca;
    }
};


