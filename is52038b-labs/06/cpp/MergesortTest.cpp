#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class MergesortTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MergesortTest);
  CPPUNIT_TEST(testMergesortNIL);
  CPPUNIT_TEST(testMergesortOne);
  CPPUNIT_TEST(testNontrivialMergesort);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testMergesortNIL();
  void testMergesortOne();
  void testNontrivialMergesort();
};

void MergesortTest::testMergesortNIL() {
  SLList *r = SLList::NIL->mergesort();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("mergesort of NIL should be NIL", SLList::NIL, r);
}

void MergesortTest::testMergesortOne() {
  SLList *r = (new SLList(82, SLList::NIL))->mergesort();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("mergesort of (82) should be (82)", 82, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("mergesort of (82) should be (82)", SLList::NIL, r->rest());
}

void MergesortTest::testNontrivialMergesort() {
  SLList *l = new SLList(2, new SLList(32, new SLList(8, new SLList(64, new SLList(1, SLList::NIL)))));
  SLList *r = l->mergesort();

  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (1 2 8 32 64)", 1, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (1 2 8 32 64)", 2, r->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (1 2 8 32 64)", 8, r->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (1 2 8 32 64)", 32, r->rest()->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (1 2 8 32 64)", 64, r->rest()->rest()->rest()->rest()->first());

  CPPUNIT_ASSERT_EQUAL_MESSAGE("original: (2 32 8 64 1)", 2, l->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("original: (2 32 8 64 1)", 32, l->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("original: (2 32 8 64 1)", 8, l->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("original: (2 32 8 64 1)", 64, l->rest()->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("original: (2 32 8 64 1)", 1, l->rest()->rest()->rest()->rest()->first());
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(MergesortTest, "Mergesort");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Mergesort");
