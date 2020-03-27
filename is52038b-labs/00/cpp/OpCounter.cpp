#include "OpCounter.hpp"

OpCounter::OpCounter() {
}
void OpCounter::add(int n) {
  counter += n;
}
int OpCounter::report() {
  return counter;
}
