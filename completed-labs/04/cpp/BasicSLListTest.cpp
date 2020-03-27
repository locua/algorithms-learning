#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class BasicSLListTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BasicSLListTest);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testGetFirst);
  CPPUNIT_TEST(testSetFirst);
  CPPUNIT_TEST(testSetRest);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testConstructor();
  void testGetFirst();
  void testSetFirst();
  void testSetRest();
};

void BasicSLListTest::testConstructor() {
  SLList *n = new SLList(0, SLList::NIL);
  CPPUNIT_ASSERT_MESSAGE("The SLList constructor must never return NULL", n != NULL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The SLList constrctor must treat its first argument as the item (or first() isn't working yet)", 0, n->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The SLList constructor must treat its second argument as the next SLList (or rest() isn't working yet)", SLList::NIL, n->rest());
  SLList *nn = new SLList(104, n);
  CPPUNIT_ASSERT_MESSAGE("The SLList constructor must never return NULL", nn != NULL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The SLList constrctor must treat its first argument as the item (or first() isn't working yet); something might be defaulting to 0", 104, nn->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The SLList constructor must treat its second argument as the next SLList (or rest() isn't working yet); something might be defaulting to SLList::NIL", n, nn->rest());
  delete n;
  delete nn;
}

#include <cstdlib>

void BasicSLListTest::testGetFirst() {
  for (int k = 0; k < 100; k++) {
    int i = rand();
    SLList *n = new SLList(i, SLList::NIL);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("first() returned something unexpected after a constructor", i, n->first());
    delete n;
  }
}

void BasicSLListTest::testSetFirst() {
  SLList *n = new SLList(0, SLList::NIL);
  for (int k = 0; k < 100; k++) {
    int i = rand();
    n->setFirst(i);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("first() returned something unexpected after setFirst()", i, n->first());
  }
  delete n;
}

void BasicSLListTest::testSetRest() {
  SLList *n = new SLList(1, SLList::NIL);
  SLList *nn = new SLList(2, SLList::NIL);
  n->setRest(nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("rest() returned something unexpected after setRest()", nn, n->rest());
  nn->setRest(nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("rest() returned something unexpected after setRest()", nn, nn->rest());
  delete nn;
  delete n;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BasicSLListTest, "Basic");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Basic");
