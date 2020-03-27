#ifndef KMPSTRINGMATCH_HPP
#define KMPSTRINGMATCH_HPP

#include "StringMatch.hpp"

class KMPStringMatch : public StringMatch {
public:
  size_t match(std::string, std::string) override;
};

#endif
