//Function to store the zig zag order traversal of tree in a list.
//Optimized solution
//TC: O(n)
//SC: O(n)
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int> ans;
	if(root==NULL)
	    return ans;
	queue<Node *> q;
	q.push(root);
	int level=0;
	stack<int> s;
	while(!q.empty()){
	    
	    int n=q.size();
	    for(int i=1; i<=n; i++){
	    
    	    Node *node=q.front();
    	    q.pop();
    	    
    	    if(level%2==0)
    	        ans.push_back(node->data);
    	    else
    	        s.push(node->data);
    	    if(node->left) q.push(node->left);
    	    if(node->right) q.push(node->right);
	    }
	    while(!s.empty()){
	        int top=s.top();
	        ans.push_back(top);
	        s.pop();
	    }
	    level++;
	}
	
}
