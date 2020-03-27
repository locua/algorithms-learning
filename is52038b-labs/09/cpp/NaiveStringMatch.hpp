#ifndef NAIVESTRINGMATCH_HPP
#define NAIVESTRINGMATCH_HPP

#include "StringMatch.hpp"

class NaiveStringMatch : public StringMatch {
public:
  size_t match(std::string, std::string) override;
};

#endif
