#include "Tree.h"

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Tree::~Tree() {
    delete left;
    delete right;
}

Tree::Tree(int w, char c)
{
    this->weight = w;
    this->c = c;
    this->left = NULL;
    this->right = NULL;
}

Tree::Tree(int w, Tree* t1, Tree* t2) {
    this->c = NULL;
    this->weight = w;
    this->left = t1;
    this->right = t2;
}

int Tree::getWeight() const {
    return weight;
}



void Tree::printTree(vector<char>& bitString) const {
    if (this->c != NULL) {
        bitString.push_back(this->c);
        bitString.push_back(':');
        bitString.push_back(' ');

        //convert weight to string
        std::ostringstream oss;
        oss << this->weight;
        std::string weightStr = oss.str();

        //insert weight
        bitString.insert(bitString.end(), weightStr.begin(), weightStr.end());
        bitString.push_back('\n');
    }

    // Recursive calls
    if (this->left != NULL) {
        this->left->printTree(bitString);
    }

    if (this->right != NULL) {
        this->right->printTree(bitString);
    }
}
