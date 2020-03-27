#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

class HashTable {
public: // for testing purposes
  int *buckets = 0;
public:
  HashTable(long, long, long);
  ~HashTable();
  void insert(int);
  bool find(int);
  double loadFactor();
};

#endif
