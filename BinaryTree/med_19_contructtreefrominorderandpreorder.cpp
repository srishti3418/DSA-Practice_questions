//Most optimized solution (Using recursion and hashmap)
//TC: O(n)
//SC: O(n)
class Solution{
    public:
    int preindex=0;
    Node *buildTree(int in[], int pre[], int st, int end, unordered_map<int, int> &m){
        
        if(st>end)
            return NULL;
        int val=pre[preindex++];
        Node *root=new Node(val);
        if(st==end)
            return root;
        int index=m[val];
        Node *leftpart=buildTree(in, pre, st, index-1, m);
        Node *rightpart=buildTree(in, pre, index+1, end, m);
        root->left=leftpart;
        root->right=rightpart;
        return root;
    
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[in[i]]=i;
        }
        return buildTree(in, pre, 0, n-1, mp);
    }
};
