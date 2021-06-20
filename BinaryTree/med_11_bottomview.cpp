//Function to return a list containing the bottom view of the given tree.
//Most optimized solution (both iterative and recursive approach solution uses map that's why TC will be same)
//TC: O(nlogn)
//SC: O(n)
map<int,int> mapDis;
unordered_map<int,int> mapLevel;
void helper(Node *root,int dis,int level){
        if(!root)return;
        if(mapDis.count(dis)==0 || mapLevel[dis]<=level){
            mapDis[dis]=root->data;
            mapLevel[dis]=level;
        }
        
        helper(root->left,dis-1,level+1);
        helper(root->right,dis+1,level+1);
        return;
}
vector <int> bottomView(Node *root)
{
   vector<int> ans;
   helper(root,0,1);
   for(auto i:mapDis){
       ans.push_back(i.second);
   }
   return ans;
}



