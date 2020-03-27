#include "SLList.hpp"
#include "ListVisualiser.hpp"

int main() {
  //SLList *a = new SLList(1, new SLList(11, new SLList(23, SLList::NIL)));
  // SLList *a = new SLList(aaa, new SLList(11, new SLList(23, SLList::NIL)));
  SLList *a = new SLList(777777787, new SLList(11, new SLList(23, new SLList(45, SLList::NIL))));
  ListVisualiser v = ListVisualiser(a);
  v.visualise();
  return 0;
}
