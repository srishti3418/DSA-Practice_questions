//This algorithm is also used for directed graphs.(Like that of Bellman ford algo)
//TC: O(n+m)
//SC: O(n+m) + O(n) +O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<int> adj[], vector<int> &visited, stack<int> &s, int i)
{
    visited[i] = 1;
    for (auto j : adj[i])
    {
        if (!visited[j])
            DFS(adj, visited, s, j);
    }
    s.push(i);
}

void revDFS(vector<int> transpose[], vector<int> &visited, int node)
{
    cout << node << " ";
    visited[node] = 1;
    for (auto j : transpose[node])
    {
        if (!visited[j])
            revDFS(transpose, visited, j);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> s;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS(adj, visited, s, i);
    }

    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (auto j : adj[i])
            transpose[j].push_back(i);
    }

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
        {
            cout << "SCCs are:";
            revDFS(transpose, visited, node);
        }
    }
}