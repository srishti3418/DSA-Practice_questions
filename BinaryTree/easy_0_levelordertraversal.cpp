/* A binary tree Node

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

//Most optimized solution(Using queue)
//TC: O(n)
//SC: O(n)
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> vec;
      if(node==NULL)
        return vec;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
        Node *front = q.front();
        vec.push_back(front->data);
        q.pop();
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
        
      }
      return vec;
    }
};
