//TC: O(V+E) {whatever is required for DFS traversal}
//SC: O(V+E)
class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int curr, vector<bool> &visited){
        
        visited[curr]=true;
        for(auto i:adj[curr]){
            if(!visited[i])
                DFS(adj, i, visited);
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;
        
        int edges=0;
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }
        
        int components=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                components++;
                DFS(adj, i, visited);
            }
        }
        
        if(edges<n-1)
            return -1;
        int redundant = edges-((n-1)-(components-1));
        if(redundant>=components-1)
            return components-1;
        return -1;
        
    }
};