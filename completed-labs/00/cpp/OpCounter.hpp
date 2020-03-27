#ifndef OPCOUNTER_HPP
#define OPCOUNTER_HPP

class OpCounter {
private:
  int counter = 0;
public:
  OpCounter();
  void add(int);
  int report();
};

#endif /* OPCOUNTER_HPP */
