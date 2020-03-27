#include "Edge.hpp"

Edge::Edge(Vertex *_from, Vertex *_to, int _weight) {
    this -> from = _from;
    this -> to = _to;
    this -> weight = _weight;
}
