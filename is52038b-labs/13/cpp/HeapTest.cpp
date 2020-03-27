#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Heap.hpp"

bool check_heap(Heap& h) {
  if (h.array.size() < h.heap_size)
    return false;
  for (unsigned int i = 0; i < h.heap_size; i++) {
    unsigned int l = left(i);
    if(l < h.heap_size && h.array[l] > h.array[i])
      return false;
    unsigned int r = right(i);
    if(r < h.heap_size && h.array[r] > h.array[i])
      return false;
  }
  return true;
}
