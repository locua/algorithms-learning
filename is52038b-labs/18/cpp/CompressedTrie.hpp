#ifndef COMPRESSED_TRIE_HPP
#define COMPRESSED_TRIE_HPP

#include <map>
#include <string>

#include "Trie.hpp"

class CompressedTrie {
public:
  std::map<std::string, CompressedTrie *> children;
  CompressedTrie();
  static CompressedTrie *compressTrie(Trie *);
  bool query(std::string);
  void insert(std::string);
};

#endif
