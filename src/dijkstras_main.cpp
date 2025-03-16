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
}