//Problem statement is same as that of Dijkstra algorithm, only diff is it works for negative wt edges too. Dijkstra algo doesn't work for negative weight edges.
//It works only for directed graph. If we have undirected graph then we can convert that into directed graph.
//It works for negative edges but won't work for negative cycle, if negative cycle is present then it can find that.
//TC: O(N-1*(m)) which is worse than dijskta btw.
//SC : O(N)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{

    int N, m, source;
    cin >> N >> m;
    vector<node> edges;

    int u, v, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    cin >> source;
    vector<int> dist(N, INT_MAX);

    dist[source] = 0;

    for (int i = 1; i <= N - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
                dist[it.v] = dist[it.u] + it.wt;
        }
    }

    int fl = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            fl = 1;
            cout << "negative cycle is present" << endl;
            break;
        }
    }

    if (!fl)
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }
}
