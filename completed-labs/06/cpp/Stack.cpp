#include "SLList.hpp"
#include "Stack.hpp"

using namespace std;

void Stack::push(int o) {
  head = new SLList(o, head);
}

int Stack::pop() {
  int r = head->first();
  SLList *newhead = head->rest();
  delete head;
  head = newhead;
  return r;
}

int Stack::top() {
  return head->first();
}

bool Stack::empty() {
  return head == SLList::NIL;
}
