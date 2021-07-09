//TC: O(V+E)
//SC: O(V)
class Solution
{
public:
    bool isCycle(vector<vector<int>> &edges, vector<int> &visited, int i)
    {
        if (visited[i] == 2)
            return true;
        visited[i] = 2;
        for (int j = 0; j < edges[i].size(); j++)
        {
            if (visited[edges[i][j]] != 1)
                if (isCycle(edges, visited, edges[i][j]))
                    return true;
        }
        visited[i] = 1;
        return false;
    }
    bool detectCycle(int num, vector<vector<int>> &pre)
    {
        vector<vector<int>> edges(num);
        for (int i = 0; i < pre.size(); i++)
        {
            edges[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> visited(num);
        for (int i = 0; i < num; i++)
        {
            if (!visited[i])
                if (isCycle(edges, visited, i))
                    return true;
        }
        return false;
    }
};