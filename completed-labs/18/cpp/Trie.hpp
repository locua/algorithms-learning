#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>

class Trie {
public:
  Trie **children;
  Trie();
  bool isLeaf;
  void insert(std::string);
  bool query(std::string);
};

#endif
