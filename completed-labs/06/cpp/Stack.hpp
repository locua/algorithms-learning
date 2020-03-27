#ifndef STACK_HPP
#define STACK_HPP

#include "SLList.hpp"

class Stack {
private:
  SLList *head = SLList::NIL;
public:
  Stack() { };
  void push(int o);
  int pop();
  int top();
  bool empty();
};

#endif
