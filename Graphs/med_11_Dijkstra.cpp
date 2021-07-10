//TC: O((n+m)logn) ~ O(nlogn)
//SC: O(n)+O(n) ~ O(n)
#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
using namespace std;

int main()
{
    int n, m, source;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    cin >> source;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (auto it : adj[prev])
        {
            int next = it.first;
            int nextDist = it.second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distances of nodes from source " << source << "are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << distTo[i] << endl;
    }
}