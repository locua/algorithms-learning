#include <fstream>

#include "StringMatchTest.hpp"

void StringMatchTest::testZeroPattern() {
  CPPUNIT_ASSERT_EQUAL(0UL, (unsigned long) matcher->match("abcde", ""));
}

void StringMatchTest::testZeroText() {
  CPPUNIT_ASSERT_EQUAL(-1UL, (unsigned long) matcher->match("", "abcde"));
  CPPUNIT_ASSERT_EQUAL(0UL, (unsigned long) matcher->match("", ""));
}

void StringMatchTest::testTable() {
  std::ifstream in("../match.txt");
  std::string text, pattern;
  int pos;
  std::string line;
  while (std::getline(in, line)) {
    std::istringstream is(line);
    is >> text >> pattern >> pos;
    if ((size_t) pos != matcher->match(text, pattern))
      CPPUNIT_FAIL(line);
  }
}
