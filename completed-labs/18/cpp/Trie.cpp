#include "Trie.hpp"

Trie::Trie() {
    this -> isLeaf = false;
    this -> children = new Trie* [27]; 
    for (int i = 0; i < 27; i++) {
        this -> children[i] = NULL; 
    }
}

void Trie::insert(std::string s) {        
    Trie* temp = this;
    int index;
    for (int i = 0; i < s.length(); i++) {
        index = s[i] - 'a';

        if (temp -> children[index] == NULL){
            temp -> children[index] = new Trie();
        }
        temp = temp -> children[index];
    }
    index = '{' -'a';
    temp -> children[index] = new Trie();
    
    temp -> isLeaf = true;
}

bool Trie::query(std::string s) {
    Trie* temp = this;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        temp = temp -> children[index];

        if (temp == NULL) {
            return false;
        }
    }
    return temp -> isLeaf;
}
