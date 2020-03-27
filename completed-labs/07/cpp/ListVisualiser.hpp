#ifndef LISTVISUALISER_HPP
#define LISTVISUALISER_HPP

#include "SLList.hpp"

class ListVisualiser {
public:
  ListVisualiser(SLList *);
  void visualise();

	SLList * mySLList;
};

#endif
