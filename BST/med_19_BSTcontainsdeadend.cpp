//Most optimized solution
//TC: O(n)
//SC: O(n)
void insert_nodes(Node *root, unordered_set<int> &s, unordered_set<int> &leaf){
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
}
