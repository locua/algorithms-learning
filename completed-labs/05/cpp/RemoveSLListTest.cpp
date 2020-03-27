#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class RemoveSLListTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(RemoveSLListTest);
  CPPUNIT_TEST(testRemoveOfNIL);
  CPPUNIT_TEST(testRemove1);
  CPPUNIT_TEST(testRemove2);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testRemoveOfNIL();
  void testRemove1();
  void testRemove2();
};

void RemoveSLListTest::testRemoveOfNIL() {
  SLList *n = SLList::NIL->remove(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What can you remove from NIL?", SLList::NIL, n);
  n = SLList::NIL->remove(0);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What can you remove from NIL?", SLList::NIL, n);
}

void RemoveSLListTest::testRemove1() {
  SLList *n = new SLList(1, SLList::NIL);
  SLList *r = n->remove(0);
  CPPUNIT_ASSERT_MESSAGE("remove must return a fresh list", r != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the length", 1U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change any item", 1, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the next field", SLList::NIL, r->rest());
  /* we're going to ignore memory leaks from ->remove() for now */
  r = n->remove(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing the only item present gives a length zero list", 0U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the only length zero list is NIL", SLList::NIL, r);
  delete n;
}

void RemoveSLListTest::testRemove2() {
  SLList *n = new SLList(1, SLList::NIL);
  SLList *nn = new SLList(2, n);
  SLList *r = nn->remove(0);
  CPPUNIT_ASSERT_MESSAGE("remove must return a fresh list", r != nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the length", 2U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change any item", 2, r->first());
  CPPUNIT_ASSERT_MESSAGE("remove must return a completely fresh list", r->rest() != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change any item", 1, r->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the next fields", SLList::NIL, r->rest()->rest());
  /* again, ignoring memory leaks from ->remove() */
  r = nn->remove(1);
  CPPUNIT_ASSERT_MESSAGE("remove must return a fresh list", r != nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("remove of an object present will change the length", 1U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("remove of an object present can change which item is first", 2, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("remove of an object present will change the list structure", SLList::NIL, r->rest());
  
  delete n;
  delete nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(RemoveSLListTest, "Remove");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Remove");
