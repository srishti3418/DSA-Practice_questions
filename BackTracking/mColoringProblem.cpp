//Upper bound TC: O(m^n)
//SC: O(n)
bool issafe(int node, int color[], bool graph[101][101], int V, int col)
{
    for (int i = 0; i < V; i++)
    {
        if (i != node && graph[i][node] == 1 && color[i] == col)
            return false;
    }
    return true;
}

bool isCheck(int node, int color[], bool graph[101][101], int m, int V)
{
    if (node == V)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (issafe(node, color, graph, V, i))
        {
            color[node] = i;
            if (isCheck(node + 1, color, graph, m, V))
                return true;
            else
                color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V] = {0};
    if (isCheck(0, color, graph, m, V))
        return true;
    return false;
}
