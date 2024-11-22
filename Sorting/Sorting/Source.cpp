#include <iostream>
#include <vector>
#include "InsertionSort.h"

int main() {
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
}
