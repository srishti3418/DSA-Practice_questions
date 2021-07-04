//TC: O(V+E)
//SC: O(V)
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool checkcycle(int start, vector<int> &visited, int parent, vector<int>adj[]){
        
        visited[start]=1;
        
        for(auto i:adj[start]){
            if(i==parent)
                continue;
        
            if(visited[i])
                return true;
            
            if(checkcycle(i, visited, start, adj)) return true;
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> visited(V, 0);
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            bool smallans=checkcycle(i, visited, -1, adj);
	            if(smallans)
	                 return true;
	        }
	    }
	    return false;
	}
};
