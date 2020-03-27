#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class ReverseSLListTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ReverseSLListTest);
  CPPUNIT_TEST(testReverseOfNIL);
  CPPUNIT_TEST(testReverse1);
  CPPUNIT_TEST(testReverse2);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testReverseOfNIL();
  void testReverse1();
  void testReverse2();
};

void ReverseSLListTest::testReverseOfNIL() {
  SLList *n = SLList::NIL->reverse();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What should the reverse of NIL be?", SLList::NIL, n);
}

void ReverseSLListTest::testReverse1() {
  SLList *n = new SLList(1, SLList::NIL);
  SLList *r = n->reverse();
  CPPUNIT_ASSERT_MESSAGE("reverse must return a fresh list", r != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse should not change the length of the list", 1U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the first item of a reversed one-element list is the same as the first element of the original", 1, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse of a one-element list should be a one-element list", SLList::NIL, r->rest());
  /* we're going to ignore memory leaks from ->reverse() for now */
  delete n;
}

void ReverseSLListTest::testReverse2() {
  SLList *n = new SLList(1, SLList::NIL);
  SLList *nn = new SLList(2, n);
  SLList *r = nn->reverse();
  CPPUNIT_ASSERT_MESSAGE("reverse must return a fresh list", r != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse must not change the length of the list", 2U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the second item becomes the first", 1, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the first item becomes the second", 2, r->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse of a two-element list should be a two-element list", SLList::NIL, r->rest()->rest());
  /* again, ignoring memory leaks from ->reverse() */
  delete n;
  delete nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(ReverseSLListTest, "Reverse");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Reverse");
