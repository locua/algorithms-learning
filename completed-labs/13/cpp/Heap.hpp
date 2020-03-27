#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
// #include "OpCounter.hpp"

unsigned int parent(unsigned int);
unsigned int left(unsigned int);
unsigned int right(unsigned int);

class Heap {
public: // for cppunit testing purposes
  std::vector<int> array;
  unsigned int heap_size;
  // OpCounter counter = OpCounter();
public:
  Heap(unsigned int);
  Heap(std::vector<int>, bool = false);
  void maxHeapify(int);
  void buildMaxHeap();
  void insert(int);
  int maximum();
  int extractMax();
  void swap(int*, int*);
  std::vector<int> sort();
};


#endif
