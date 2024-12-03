#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "InsertionSort.h"
#include "friendBFS.h"
#include "HuffmanCode.h"



void insertionTest() {
    const int size = 50000;
    std::vector<int> list(size);

    // Initialize random number generator
    std::random_device rd;                          
    std::mt19937 gen(rd());                         
    std::uniform_int_distribution<> distrib(0, size); 

    // Fill the vector with random numbers
    for (int& num : list) {
        num = distrib(gen);
    }

    InsertionSort sorter;

    auto start = std::chrono::high_resolution_clock::now();

    sorter.sort(list);

    // Stop timing
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken to sort: " << duration.count() << " microseconds." << std::endl;
}

void graphTest() {
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

void huffmanTest() {
    HuffmanCode huff;
    huff.sort("hej");
}

int main() {
    
    huffmanTest();
}
