//TC: O(V+E)
//SC: O(V)
vector<int> DFS(vector<int> &result, int V, vector<int> adj[], int start, vector<int> &visited){
    
    result.push_back(start);
    visited[start]=1;

    for(auto i:adj[start]){
        if(!visited[i]) DFS(result, V, adj, i, visited);
    }
    return result;
}

vector<int> DFS(int V, vector<int> adj[]){
    
    vector<int> result;
    visited<int> visited(V, 0);
    for(auto i: adj){
        if(!visited[i]) return DFS(result, V, adj, 0, visited);
    }

}