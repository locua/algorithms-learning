#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>

#include "Edge.hpp"

// I am disappointed that C++ needs forward declarations for
// mutually-recursive class definitions
class Edge;

class Vertex {
public:
  std::string name;
  std::vector<Edge *> adjlist;
  Vertex(std::string);
};

#endif
