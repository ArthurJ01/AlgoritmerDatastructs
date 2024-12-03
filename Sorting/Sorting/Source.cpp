#include <iostream>
#include <vector>
#include "InsertionSort.h"
#include "friendBFS.h"

/*
	    std::vector<int> list = { 5, 2, 9, 1, 5, 6 };
    InsertionSort sorter;

    std::cout << "Original list: ";
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sorter.sort(list);

    std::cout << "Sorted list: ";
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
*/

int main() {
    Graph g(8);
    vector<int> frens;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.printGraph();
    cout << endl;

    friendBFS fren;
    int nodeToCheck = 1;

    frens = fren.find(g, nodeToCheck);

    cout << "FRIENDS OF NODE " << nodeToCheck << ": " << endl;

    for (int i = 0; i < frens.size(); i++) {
        cout << frens[i] << " ";
    }
}
