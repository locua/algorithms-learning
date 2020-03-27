#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"

// I am disappointed that C++ needs forward declarations for
// mutually-recursive class definitions
class Vertex;

class Edge {
public:
  Vertex *from;
  Vertex *to;
  int weight;
  Edge(Vertex *, Vertex*, int);
};

#endif
