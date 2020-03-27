#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class LengthSLListTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(LengthSLListTest);
  CPPUNIT_TEST(testLengthOfNIL);
  CPPUNIT_TEST(testLength);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testLengthOfNIL();
  void testLength();
};

void LengthSLListTest::testLengthOfNIL() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What is the length of NIL?", 0U, SLList::NIL->length());
}

void LengthSLListTest::testLength() {
  SLList *n = new SLList(1, SLList::NIL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What is the length of a list whose next is NIL?", 1U, n->length());
  SLList *nn = new SLList(2, n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What is the length of a list whose next is a list with length 1?", 2U, nn->length());
  delete n;
  delete nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(LengthSLListTest, "Length");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Length");
