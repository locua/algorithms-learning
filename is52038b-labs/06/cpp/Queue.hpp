#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "SLList.hpp"

class Queue {
private:
  SLList *hd = SLList::NIL;
  SLList *tail = SLList::NIL;
public:
  Queue() { };
  void enqueue(int o);
  int dequeue();
  int head();
  bool empty();
};

#endif
