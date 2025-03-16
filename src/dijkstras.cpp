# include "dijkstras.h"

// implement dij given source vertex 
vector<int> dijkstras_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.numVerticies;
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    previous.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    distances[source] = 0;
    minHeap.push({0, source});

    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (const Edge& edge : G[u])
        {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v])
            {
            distances[v] = distances[u] + weight;
            previous[v] = u;
            minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}

// get the shortest path from the source to given dest

// print shortest path and total cost
