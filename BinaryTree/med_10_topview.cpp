//Recursive approach(not so oprimized)
//TC: O(nlogn) (since, map takes logn time to insert and for n elements it'll take nlogn time)
//SC: O(n)
/*class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void topView(Node *root, map<int, pair<int, int>> &m, int dis, int level){
        if(root==NULL)
            return;
        if(m.count(dis)==0 || m[dis].second>level)
            m[dis]=make_pair(root->data, level);
        topView(root->left, m, dis-1, level+1);
        topView(root->right, m, dis+1, level+1);
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int, pair<int, int>> m;
        topView(root, m, 0, 0);
        for(auto it=m.begin(); it!=m.end(); it++){
            ans.push_back(it->second.first);
        }
        return ans;
    }

};*/

//Most optimized solution (Iterative approah)
//TC: O(n)
//SC: O(n)
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        queue<pair<Node *, int>> q;
        
        int hd=0, l=0, r=0;
        stack<int> left;
        vector<int> right;
        
        q.push(make_pair(root, 0));
        Node *front;
        
        while(!q.empty()){
            
            front=q.front().first;
            hd=q.front().second;
            
            if(hd<l){
                left.push(front->data);
                l=hd;
            }
            
            if(hd>r){
                right.push_back(front->data);
                r=hd;
            }
            
            if(front->left)
                q.push(make_pair(front->left, hd-1));
            if(front->right)
                q.push(make_pair(front->right, hd+1));
            
            q.pop();
        }
        
        while(!left.empty()){
            int top=left.top();
            ans.push_back(top);
            left.pop();
        }
        
        ans.push_back(root->data);
        
        for(auto i:right){
            ans.push_back(i);
        }
        return ans;
    }

};
