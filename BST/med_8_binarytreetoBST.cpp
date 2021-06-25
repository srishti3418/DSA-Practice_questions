//Most optimized solution
//TC: O(nlogn)
//SC: O(n)
class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node *root, vector<int> &vec){
        if(root==NULL)  
            return;
        inorder(root->left, vec);
        vec.push_back(root->data);
        inorder(root->right, vec);
    }
    
    void constructBST(Node *root, vector<int> &vec, int *index){
        if(root==NULL)
            return;
        constructBST(root->left, vec, index);
        root->data=vec[*index];
        *index=*index+1;
        constructBST(root->right, vec, index);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> vec;
        inorder(root, vec);
        sort(vec.begin(), vec.end());
        int index=0;
        constructBST(root, vec, &index);
        return root;
    }
};
