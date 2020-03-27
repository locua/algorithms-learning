#include <iostream>

#include "StringMatch.hpp"
#include "NaiveStringMatch.hpp"
#include "RKStringMatch.hpp"
#include "KMPStringMatch.hpp"

int main() {
  std::string P = "aaaab";
  std::string T = "";
  StringMatch *matcher = new KMPStringMatch();

  matcher->match(T, P);
  std::cout << "char reads: " << matcher->counter.report() << std::endl;;

  delete matcher;
  return 0;
}
