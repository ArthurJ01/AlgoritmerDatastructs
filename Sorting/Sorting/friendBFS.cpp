#include "friendBFS.h"
#include <list>
#include <vector>

using namespace std;

vector<int> friendBFS::find(Graph g, int startVertex) {
    int numVertices = g.getNumNodes();
    vector<bool> visited(numVertices, false);

    list<int> openList;
    openList.push_back(startVertex);
    visited[startVertex] = true;
    bool fren = true;
    int last = startVertex;
    vector<int> frens;

    while (openList.size() != 0) {
        int n = openList.front();
        openList.pop_front();

        if (fren && n != startVertex) {
            frens.push_back(n);
        }

        vector<int> children = g.getChildren(n);
        for (int m : children)
        {
            if (!visited[m])
            {
                openList.push_back(m);
                visited[m] = true;
            }
        }
        if (n == last && openList.size() != 0)
        {
            last = openList.back();
            fren = !fren;
        }
    }
    return frens;
}