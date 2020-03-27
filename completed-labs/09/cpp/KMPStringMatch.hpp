#ifndef KMPSTRINGMATCH_HPP
#define KMPSTRINGMATCH_HPP

#include "StringMatch.hpp"

class KMPStringMatch : public StringMatch {
public:
  int *computePrefix(std::string);
  size_t match(std::string, std::string) override;
  char read(std::string, int);
};

#endif
