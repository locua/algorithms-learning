#ifndef STRINGMATCH_HPP
#define STRINGMATCH_HPP

#include <string>
#include <cstring>

#include "OpCounter.hpp"

class StringMatch {
public:
  OpCounter counter = OpCounter();
  virtual size_t match(std::string text, std::string pattern) = 0;
};
  
#endif
