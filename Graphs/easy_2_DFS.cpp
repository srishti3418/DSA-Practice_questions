//Most optimized solution
//TC: O(V+E)
//SC: O(V)
class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> DFS(vector<int> &result, int V, vector<int> adj[], int start, vector<int> &visited){
    
        result.push_back(start);
        visited[start]=1;
    
        for(auto i:adj[start]){
            if(!visited[i]) DFS(result, V, adj, i, visited);
        }
        return result;
    }
    
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> result;
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]) DFS(result, V, adj, i, visited);
        }
        return result;
    }
};
