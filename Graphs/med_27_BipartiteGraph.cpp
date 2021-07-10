//TC: O(N+E) {BFS traversal}
//SC: O(N+E)+O(N)+O(N) ~ O(N+E)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bipartitegraph(vector<int> edges[], int color[], int j)
{
    queue<int> vertex;
    vertex.push(j);
    color[j] = 1;

    while (!vertex.empty())
    {
        int front = vertex.front();
        vertex.pop();

        for (int i : edges[front])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[front];
                vertex.push(i);
            }
            else if (color[front] == color[i])
                return false;
        }
    }
    return true;
}

int main()
{
    int N, m;
    cin >> N >> m;
    vector<int> edges[N];

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> color(N, -1);

    for (int i = 0; i < N; i++)
    {
        if (!color[i])
        {
            if (!bipartitegraph(edges, color, i))
            {
                cout << "False" << endl;
                break;
            }
        }
    }
    cout << "True" << endl;
}