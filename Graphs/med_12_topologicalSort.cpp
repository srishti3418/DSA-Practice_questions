//TC: O(V+E) {because of DFS traversal}
//SC: O(V)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order
	 stack<int> s;
	
	void DFS(vector<bool> &visited, vector<int> adj[], int i, stack<int> &s){
	    visited[i]=true;
	    for(auto k:adj[i]){
	        if(!visited[k])
	            DFS(visited, adj, k, s);
	    }
	    s.push(i);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V, false);
	    for(int i=0; i<V; i++){
	        if(!visited[i])
	            DFS(visited, adj, i, s);
	    }
	    
	    vector<int> res;
	    while(!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    return res;
	}
};