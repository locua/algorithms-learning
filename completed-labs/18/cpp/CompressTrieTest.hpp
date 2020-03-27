#include "Trie.hpp"
#include "CompressedTrie.hpp"

CompressedTrie::CompressedTrie() {
    this -> children = new std::map<std::string, CompressedTrie*>[27]; 
}

CompressedTrie *CompressedTrie::compressTrie(Trie *t) {
  return NULL;
}

bool CompressedTrie::query(std::string s) {
  return false;
}

void CompressedTrie::insert(std::string s) {
}
