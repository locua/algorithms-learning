#include "Vertex.hpp"

Vertex::Vertex(std::string _name) {
    this -> name = _name;
    std::vector<Edge *> temp;
    this -> adjlist = temp;
}

