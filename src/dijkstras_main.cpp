# include "dijkstras.h"

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " <input _file> <start_vertex>" << endl;
        return 1; 
    }

    string filename = argv[1];
    int start_vertex = stoi(argv[2]); 

    Graph G;
    try 
    {
        file_to_graph(filename, G);
    }
    catch (const exception&)
    {
        cerr << "Error: Unable to process input file" << endl;
        return 1; 
    }

    vector<int> previous;
    vector<int> distances = dijkstras_shortest_path(G, start_vertex, previous);

    for (int i = 0; i < G.numVertices; ++i)
    {
        cout << "Shortest path to vertex " << i << ": ";
        vector<int> path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]);
    }
    return 0; 
}