#ifndef STRINGMATCHTEST_HPP
#define STRINGMATCHTEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "StringMatch.hpp"

class StringMatchTest : public CppUnit::TestFixture {
public:
  StringMatch *matcher;
public:
  virtual void setUp() {};
  virtual void tearDown() {};  
  void testZeroPattern();
  void testZeroText();
  void testTable();
};

#endif
