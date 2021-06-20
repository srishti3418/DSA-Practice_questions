/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
//Most optimized solution (both iterative and recursive solution takes same complexities)
//TC: O(n)
//SC: O(n)
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> res;
    if(root==NULL)
        return res;
    queue<Node *> q;
    q.push(root);
    Node *node;
    while(!q.empty()){
       
       int n=q.size();
       for(int i=1; i<=n; i++){
           node=q.front();
           q.pop();
           if(i==1)
                res.push_back(node->data);
           if(node->left)
             q.push(node->left);
           if(node->right)
             q.push(node->right);
       }
           
    }
    return res;
   
}
