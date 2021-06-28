//TC: O(n)
//SC: O(n)
/*void insert_nodes(Node *root, unordered_set<int> &s, unordered_set<int> &leaf){
    if(root==NULL)
        return;
    insert_nodes(root->left, s, leaf);
    if(!root->left && !root->right)
        leaf.insert(root->data);
    s.insert(root->data);
    insert_nodes(root->right, s, leaf);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    if(root==NULL)
        return false;
    unordered_set<int> s;
    unordered_set<int> leaf;
    s.insert(0);
    insert_nodes(root, s, leaf);
    for(auto i=leaf.begin(); i!=leaf.end(); i++){
        int x=(*i);
        if(s.find(x+1)!=s.end() && s.find(x-1)!=s.end())
            return true;
    }
    return false;
}*/

//Optimized solution
//TC: O(n)
//SC: O(h)
bool solve(Node* root,int mi,int mx)
{
    if(root == NULL)
        return false;
    
    if(root->data == mi && root->data == mx)
        return true;
        
    return solve(root->left, mi, root->data - 1) || solve(root->right, root->data + 1, mx);
}

bool isDeadEnd(Node *root)
{
    if(root==NULL)
        return false;
    int mi = 1;
    int mx = INT_MAX;
    return solve(root,mi,mx);
}


