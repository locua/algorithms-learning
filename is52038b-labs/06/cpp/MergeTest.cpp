#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class MergeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MergeTest);
  CPPUNIT_TEST(testMergeNILNIL);
  CPPUNIT_TEST(testMergeNIL);
  CPPUNIT_TEST(testNontrivialMerge);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testMergeNILNIL();
  void testMergeNIL();
  void testNontrivialMerge();
};

void MergeTest::testMergeNILNIL() {
  SLList *r = SLList::NIL->merge(SLList::NIL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("NIL merged with NIL should be NIL", SLList::NIL, r);
}

void MergeTest::testMergeNIL() {
  SLList *r = SLList::NIL->merge(new SLList(10, SLList::NIL));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Merging NIL with x should give x", 10, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Merging NIL with x should give x", SLList::NIL, r->rest());
  SLList *r2 = (new SLList(20, SLList::NIL))->merge(SLList::NIL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Merging NIL with x should give x", 20, r2->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Merging NIL with x should give x", SLList::NIL, r2->rest());
}

void MergeTest::testNontrivialMerge() {
  SLList *l1 = new SLList(4, new SLList(17, SLList::NIL));
  SLList *l2 = new SLList(5, new SLList(29, SLList::NIL));

  SLList *r11 = l1->merge(l1);
  SLList *r12 = l1->merge(l2);
  SLList *r21 = l2->merge(l1);
  SLList *r22 = l2->merge(l2);

  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 4 17 17)", 4, r11->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 4 17 17)", 4, r11->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 4 17 17)", 17, r11->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 4 17 17)", 17, r11->rest()->rest()->rest()->first());

  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 4, r12->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 5, r12->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 17, r12->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 29, r12->rest()->rest()->rest()->first());

  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 4, r21->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 5, r21->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 17, r21->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (4 5 17 29)", 29, r21->rest()->rest()->rest()->first());

  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (5 5 29 29)", 5, r22->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (5 5 29 29)", 5, r22->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (5 5 29 29)", 29, r22->rest()->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("expected: (5 5 29 29)", 29, r22->rest()->rest()->rest()->first());
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(MergeTest, "Merge");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Merge");
