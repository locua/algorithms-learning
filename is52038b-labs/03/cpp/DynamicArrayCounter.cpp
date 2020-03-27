#include <vector>
#include <iostream>

#include "DynamicArray.hpp"
#include "OpCounter.hpp"

int main(int argc, char *argv[]) {
  std::vector<int> l = {1, 5, 10, 50, 100, 500, 1000};
  for (int i = 0; i < l.size(); i++) {
    DynamicArray *a = new DynamicArray(5);
    for(int n = 0; n < l[i]; n++) {
      a->push(n);
    }
    std::cout << l[i] << "," << a->counter.report() << std::endl;
    delete a;
  }
}
