#include "StringMatchTest.hpp"
#include "KMPStringMatch.hpp"

class KMPStringMatchTest : public StringMatchTest {
  CPPUNIT_TEST_SUITE(KMPStringMatchTest);
  CPPUNIT_TEST(testZeroPattern);
  CPPUNIT_TEST(testZeroText);
  CPPUNIT_TEST(testTable);
  CPPUNIT_TEST_SUITE_END();
public:
  virtual void setUp() {
    matcher = new KMPStringMatch();
  }
  virtual void tearDown() { };
};

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(KMPStringMatchTest, "KMPStringMatch");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("KMPStringMatch");
