#include "InsertionSort.h"
#include <iostream>
#include <vector>

void InsertionSort::sort(std::vector<int>& list) {
		
	for (int i = 1; i < list.size(); i++) {

		for (int j = i; j >= 1 && list[j - 1] > list[j]; j--) {
				
			int temp = list[j];
			list[j] = list[j - 1];
			list[j - 1] = temp;
		}
	}
}
