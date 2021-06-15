/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

//Most optimized solution(using stack and queue)
//TC: O(n)
//SC: O(n)
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> vec;
    if(root==NULL)
        return vec;
    stack<Node *> s;
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        
        root=q.front();
        s.push(root);
        q.pop();
        if(root->right)
            q.push(root->right);
        if(root->left)
            q.push(root->left);
        
    }
    
    while(!s.empty()){
        root=s.top();
        vec.push_back(root->data);
        s.pop();
    }
    return vec;
}
