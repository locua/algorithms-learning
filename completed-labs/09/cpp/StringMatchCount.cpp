#include <iostream>

#include "StringMatch.hpp"
#include "NaiveStringMatch.hpp"
#include "RKStringMatch.hpp"
#include "KMPStringMatch.hpp"

int main() {
  int moodleID = 59985;
  int studentID = 33551402;
  std::string P = "";
  std::string T = "";

  for (int i = 0; i != moodleID - 1; i++) P += "a";
  P += "b";

  // StringMatch *matcher = new NaiveStringMatch();
  // StringMatch *matcher = new RKStringMatch();
  StringMatch *matcher = new KMPStringMatch();
  
  matcher->match(P, P);
  std::cout << "char reads: " << matcher->counter.report() << std::endl;;

  delete matcher;
  return 0;
}
