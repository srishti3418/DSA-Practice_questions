//Optimized solution
//TC: O(mlogm)+ O(m*(O(4*alpha))) ~ O(mlogm) where m is the number of edges
//SC: O(m)+ O(n) + O(n) ~ O(n)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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

bool comp(node u, node v)
{
    return u.wt < v.wt;
}

int findPar(int u, vector<int> &Parent)
{
    if (u == Parent[u])
        return u;
    return Parent[u] = findPar(Parent[u], Parent);
}

void unionn(int u, int v, vector<int> &Parent, vector<int> &rank)
{
    u = findPar(u, Parent);
    v = findPar(v, Parent);

    if (rank[u] < rank[v])
    {
        Parent[u] = v;
    }
    else if (rank[u] > rank[v])
        Parent[v] = u;
    else
    {
        Parent[u] = v;
        rank[v]++;
    }
}

int main()
{
    int N, m;
    cin >> N >> m;

    vector<node> edges;
    while (m--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> Parent(N);
    for (int i = 0; i < N; i++)
    {
        Parent[i] = i;
    }
    vector<int> Rank(N, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.u, Parent) != findPar(it.v, Parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, Parent, Rank);
        }
    }

    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << "-" << it.second << endl;
    }
}
