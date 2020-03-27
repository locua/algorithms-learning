#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

unsigned int parent(unsigned int);
unsigned int left(unsigned int);
unsigned int right(unsigned int);

class Heap {
public: // for cppunit testing purposes
  std::vector<int> array;
  unsigned int heap_size;
public:
  Heap(unsigned int);
  Heap(std::vector<int>, bool = false);
  void maxHeapify(int);
  void buildMaxHeap();
  void insert(int);
  int maximum();
  int extractMax();
};

#endif
