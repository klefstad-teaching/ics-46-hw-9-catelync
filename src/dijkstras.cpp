# include "dijkstras.h"

// implement dij given source vertex 
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.numVertices;
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
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
{
    vector<int> path;
    if (previous[destination] == -1)
    {
        return path; 
    }
    for (int at = destination; at != -1; at = previous[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path; 
}

// print shortest path and total cost
void print_path(const vector<int>& path, int total)
{
    if (path.empty())
    {
        cout << "No path found" << endl;
        return;
    }
    for (size_t i = 0; i <path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size() - 1) 
        {
            cout << " -> ";
        }
    }
    cout << "\nTotal cost: " << total << endl; 
}
