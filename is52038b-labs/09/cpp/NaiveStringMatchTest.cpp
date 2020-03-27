#include "StringMatchTest.hpp"
#include "NaiveStringMatch.hpp"

class NaiveStringMatchTest : public StringMatchTest {
  CPPUNIT_TEST_SUITE(NaiveStringMatchTest);
  CPPUNIT_TEST(testZeroPattern);
  CPPUNIT_TEST(testZeroText);
  CPPUNIT_TEST(testTable);
  CPPUNIT_TEST_SUITE_END();
public:
  virtual void setUp() {
    matcher = new NaiveStringMatch();
  }
  virtual void tearDown() { };
};

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(NaiveStringMatchTest, "NaiveStringMatch");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("NaiveStringMatch");
