#include <iostream>
#include "friendBFS.h"

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph::isEdge(int v, int w) {
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (w == *i) return (true);
    return (false);
}

int Graph::getNumNodes() {
    return V;
}

void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of node " << v << "\n head ";
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            cout << "-> " << *i;
            cout << " ";
        }
    }
}

std::vector<int> Graph::getChildren(int v) {
    vector<int> children;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        children.push_back(*i);
    }
    return children;
}