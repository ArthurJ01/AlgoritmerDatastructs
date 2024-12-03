#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int>* adj;

public:
    Graph(int v);

    void addEdge(int v, int w);

    bool isEdge(int v, int w);

    int getNumNodes();

    void printGraph();

    std::vector<int> getChildren(int v);
};

#endif