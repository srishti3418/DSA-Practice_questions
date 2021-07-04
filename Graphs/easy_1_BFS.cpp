//Most optimized solution
//TC: O(V+E)
//SC: O(V)
class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> result;
	    
	    vector<int> visited(V, 0);
	    queue<int> vertex;
	    
	    visited[0]=1;
	    vertex.push(0);
	    
	    while(!vertex.empty()){
	        int front=vertex.front();
	        result.push_back(front);
	        vertex.pop();
	        
	        for(auto i:adj[front]){
	            
	            if(!visited[i]){
	                visited[i]=1;
	                vertex.push(i);
	            }
	            
	        }
	    }
	    return result;
	}
};
