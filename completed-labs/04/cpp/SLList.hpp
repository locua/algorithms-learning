#ifndef SLLIST_HPP
#define SLLIST_HPP

class SLList {
public:
  SLList(int, SLList *);
  static SLList * const NIL;

  SLList *rest();
  int first();
  void setFirst(int);
  void setRest(SLList *);

  int nth(unsigned int);
  SLList *nthRest(unsigned int);

  unsigned int length();
  SLList *remove(int i);
  SLList *reverse();
  SLList *append(SLList *);  
  unsigned int lengthAux(int i);
  int sum();
  SLList *sublist(int start, int end);
  int f_;  
  SLList *r_;
  SLList *merge(SLList *);
  SLList *mergesort();
};

#endif
