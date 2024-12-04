#include "HuffmanCode.h"
#include <unordered_map>
#include <iostream>
#include <queue>

TreeWrapper HuffmanCode::sort(std::string str)
{

    std::vector<char> charArray(str.begin(), str.end());
    std::unordered_map<char, int> map;
    std::priority_queue<TreeWrapper> q;

    //count occurences of each string
    for (char c : str) {
        map[c]++;
    }

    //for each entry in the map create a tree and add it to queue
    for (const auto& pair : map) {
        char character = pair.first;
        int weight = pair.second;
        q.push(TreeWrapper(new Tree(weight, character)));
    }

    while (q.size() > 1) {

        TreeWrapper t1 = TreeWrapper(q.top());
        q.pop();
        TreeWrapper t2 = TreeWrapper(q.top());
        q.pop();
        
        int w = t1.tree->getWeight() + t2.tree->getWeight();

        q.push(TreeWrapper(new Tree(w, t1.tree, t2.tree)));
    }

    TreeWrapper t = TreeWrapper(q.top());

    return t;

}
