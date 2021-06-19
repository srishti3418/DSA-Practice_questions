/*struct Node
{
    int data;
    Node* left, * right;
}; */

//Most optimized solution (Using recursion)
//TC: O(n)
//SC: O(height of the tree)
class Solution {
  public:
  
    
    int ToSumTree(Node *Node){
        if(Node == NULL)
            return 0;
 
        int old_val = Node->data;
     
        Node->data = ToSumTree(Node->left) + ToSumTree(Node->right);

        return Node->data + old_val;
    }    
    
    void toSumTree(Node *node)
    {
        // Your code here
        if(node==NULL)
            return;
        ToSumTree(node);
        return;
    }
};
