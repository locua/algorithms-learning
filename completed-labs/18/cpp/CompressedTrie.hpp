#ifndef COMPRESSED_TRIE_HPP
#define COMPRESSED_TRIE_HPP

#include <map>
#include <string>
#include <vector>

#include "Trie.hpp"

class CompressedTrie {
public:
  std::map<std::string, CompressedTrie *> children;
  CompressedTrie();
  static CompressedTrie *compressTrie(Trie *);
  bool query(std::string);
  void insert(std::string);
  std::vector<std::string> addStr(Trie *, std::string);
  bool endsWith(std::string const &fullString, std::string const &ending);
  std::string prefix(std::string);
};

#endif
