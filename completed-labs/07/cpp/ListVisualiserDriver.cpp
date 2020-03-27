#include <iostream>
#include <string>
#include <climits>

#include "SLList.hpp"
#include "ListVisualiser.hpp"

void usage(char *argv[]) {
  std::cerr << "Usage: " << argv[0] << " small|large|empty|cyclic|bigelem" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc == 1 || argc > 2) {
    usage(argv);
    return 1;
  }
  SLList *test = SLList::NIL;
  std::string small("small");
  std::string large("large");
  std::string empty("empty");
  std::string cyclic("cyclic");
  std::string bigelem("bigelem");
  if (!small.compare(argv[1])) {
    test = new SLList(14, new SLList(1 << 10, new SLList(-17, new SLList(9999, SLList::NIL))));
  } else if (!large.compare(argv[1])) {
    for (int i = 0; i < 200; i++) {
      test = new SLList(i, test);
    }
  } else if (!empty.compare(argv[1])) {
  } else if (!cyclic.compare(argv[1])) {
    test = new SLList(1, SLList::NIL);
    test->setRest(test);
  } else if (!bigelem.compare(argv[1])) {
    test = new SLList(INT_MIN, new SLList(INT_MAX, SLList::NIL));
  } else {
    usage(argv);
    return 1;
  }
  ListVisualiser v = ListVisualiser(test);
  v.visualise();
  return 0;
}
