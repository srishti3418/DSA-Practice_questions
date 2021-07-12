//TC: O(V^3)
//SC :O(1)
#include <iostream>
#include <climits>
using namespace std;
#define V 6

void Floyd_warshall(int graph[V][V])
{

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if (graph[j][i] == INT_MAX || graph[i][k] == INT_MAX)
                    continue;
                else if (graph[j][i] + graph[i][k] < graph[j][k])
                    graph[j][k] = graph[j][i] + graph[i][k];
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (graph[i][i] < 0)
        {
            cout << "Negative cycle is present in the graph" << endl;
            break;
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << "shortest distance between " << i << " to " << j << " is " << graph[i][j] << endl;
        }
    }
}

int main()
{
    int graph[V][V] = {{0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                       {INT_MAX, 0, 4, 2, 7, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                       {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}};

    Floyd_warshall(graph);
}
