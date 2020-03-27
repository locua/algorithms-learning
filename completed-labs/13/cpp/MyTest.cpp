#include <iostream>
#include <vector>
#include "Heap.hpp"

/*
g++ -std=c++11 -o MyTest MyTest.cpp Heap.cpp
./MyTest
*/

void incremental(std::vector<int> x) {
    Heap h = Heap(x, true);
	std::cout << "Contents of heap: [";
	for (size_t i = 0; i < h.array.size(); i++) {
		std::cout << h.array[i] << ",";
	}
	
    std::cout << "]" << std::endl;
}

void inplace(std::vector<int> x) {
    Heap h = Heap(x, false);
	std::cout << "Contents of heap: [";
	for (size_t i = 0; i < h.array.size(); i++) {
		std::cout << h.array[i] << ",";
	}
	
    std::cout << "]" << std::endl;
}

int main() {
    // std::vector<int> y = {5,1,9,95,94,36,93,55}; 
    std::vector<int> y = {}; 
	incremental(y);
    //inplace(y);
    return 0;
}

