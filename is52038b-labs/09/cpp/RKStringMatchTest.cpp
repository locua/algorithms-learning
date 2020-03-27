#include "StringMatchTest.hpp"
#include "RKStringMatch.hpp"

class RKStringMatchTest : public StringMatchTest {
  CPPUNIT_TEST_SUITE(RKStringMatchTest);
  CPPUNIT_TEST(testZeroPattern);
  CPPUNIT_TEST(testZeroText);
  CPPUNIT_TEST(testTable);
  CPPUNIT_TEST_SUITE_END();
public:
  virtual void setUp() {
    matcher = new RKStringMatch();
  }
  virtual void tearDown() { };
};

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(RKStringMatchTest, "RKStringMatch");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("RKStringMatch");
