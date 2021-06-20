/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
//Optimized solution 
//TC: O(n)
//SC: O(heigh of the tree)
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    struct Node * bToDLL(struct Node *root, Node **head, Node **tail){
        if(root==NULL)
            return NULL;
        struct Node *left=root->left;
        struct Node *right=root->right;
        
        bToDLL(root->left, head, tail);
        
        if((*head)==NULL)
            *head=root;
        
        root->left=*tail;
        
        if((*tail)!=NULL)
            (*tail)->right=root;
        
        (*tail)=root;
        
        bToDLL(root->right, head, tail);
        
        return root;
    }
    
    struct Node * bToDLL(struct Node *root)
    {
        // your code here
        if(root==NULL)
            return NULL;
        struct Node *head=NULL;
        struct Node *tail=NULL;
        
        bToDLL(root, &head, &tail);
        return head;
    }
};
