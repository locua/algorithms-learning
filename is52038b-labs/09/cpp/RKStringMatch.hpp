#ifndef RKSTRINGMATCH_HPP
#define RKSTRINGMATCH_HPP

#include "StringMatch.hpp"

class RKStringMatch : public StringMatch {
public:
  size_t match(std::string, std::string) override;
};

#endif
