#include <cstdlib>
#include <climits>

#include "SLList.hpp"

using namespace std;

SLList * const SLList::NIL = new SLList(0, NULL);

SLList::SLList(int i, SLList *n) {
}

int SLList::first() {
  return 0;
}

SLList *SLList::rest() {
  return NULL;
}

void SLList::setFirst(int i) {
}

void SLList::setRest(SLList *n) {
}

int SLList::nth(unsigned int i) {
  return 0;
}

SLList *SLList::nthRest(unsigned int i) {
  return NULL;
}

unsigned int SLList::length() {
  return UINT_MAX;
}

SLList *SLList::remove(int i) {
  return NULL;
}

SLList *SLList::reverse() {
  return NULL;
}
