#include "SLList.hpp"
#include "Queue.hpp"

using namespace std;

void Queue::enqueue(int o) {
  if (tail == SLList::NIL) {
    tail = new SLList(o, tail);
    hd = tail;
  } else {
    tail->setRest(new SLList(o, SLList::NIL));
    tail = tail->rest();
  }
}

int Queue::dequeue() {
  int r = hd->first();
  SLList *newhd = hd->rest();
  delete hd;
  hd = newhd;
  if (hd == SLList::NIL) {
    tail = SLList::NIL;
  }
  return r;
}

int Queue::head() {
  return hd->first();
}

bool Queue::empty() {
  return hd == SLList::NIL;
}
