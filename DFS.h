#include <iostream>
#include <map>
#include <list>

using std::map; using std::list; using std::cout;

/// <summary>
/// Depth-first search 
/// <para>The algorightms goes through each vertex adjecent with the current one</para>
/// </summary>
class DFS
{
private:
    map<int, list<int>> adjecentVertexes;
    map<int, bool> visited;
public:
    void addEdge(int first, int second)
    {
        adjecentVertexes[first].push_back(second);
    }
    // General algorithm
    void DFS_Search(int vertex)
    {
        visited[vertex] = true;
        cout << vertex << " ";
        for (auto& i : adjecentVertexes[vertex])
            if (!visited[i])
                DFS_Search(i);
    } 
};
