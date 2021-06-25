/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:
    //Not so optimized solution
    //TC: O(n)
    //SC: O(n)
    /*void inorder(Node *root, vector<Node *> &vec){
        if(root==NULL)
            return;
        inorder(root->left, vec);
        vec.push_back(root);
        inorder(root->right, vec);
    }

    void populateNext(Node *root)
    {
        //code here
        vector<Node *> vec;
        inorder(root, vec);
        for(int i=0; i<vec.size(); i++){
            if(i!=vec.size()-1)
                vec[i]->next=vec[i+1];
            else
                vec[i]->next=NULL;
            
        }*/
        
    //Most optimized solution
    //TC: O(n)
    //SC: O(h)
    Node *next_ptr=NULL;   
    void populateNext(Node *root)
    {
        //code here
        if(root==NULL)
            return;
        populateNext(root->right);
        root->next=next_ptr;
        next_ptr=root;
        populateNext(root->left);
    }
};
