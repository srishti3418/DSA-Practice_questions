#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];

    int a, b, wt;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int Parent[N];

    int key[N];

    bool mst[N];

    for (int i = 0; i < N; i++)
        mst[i] = false, key[i] = INT_MAX;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    Parent[0] = -1;
    pq.push(make_pair(0, 0));

    for (int count = 0; count < N - 1; count++)
    {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v])
            {
                Parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }
}