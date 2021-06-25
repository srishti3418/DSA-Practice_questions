//Function to find the lowest common ancestor in a BST.

//Most optimized solution
//TC: O(h)
//SC: O(h)
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   
   if(root==NULL)
        return NULL;
 
   if(n1<root->data && n2<root->data)
        return LCA(root->left, n1, n2);
   if(n1>root->data && n2>root->data)
        return LCA(root->right, n1, n2);
    
   return root;
}
