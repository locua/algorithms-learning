#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class ExtendedSLListTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ExtendedSLListTest);
  CPPUNIT_TEST(testNth);
  CPPUNIT_TEST(testNthRest);
  CPPUNIT_TEST_SUITE_END();

  SLList *n;
  SLList *ncirc;
public:
  void setUp() {
    n = new SLList(17, new SLList(34, new SLList(3, SLList::NIL)));
    ncirc = new SLList(2, new SLList(3, SLList::NIL));
    ncirc->rest()->setRest(ncirc);
  };
  void tearDown() {
    SLList *tmp;
    while (n != SLList::NIL && n != NULL) {
      tmp = n->rest();
      delete n;
      n = tmp;
    }
    delete ncirc->rest();
    delete ncirc;
  };

  void testNth();
  void testNthRest();
};

#include <cstdlib>

void ExtendedSLListTest::testNth() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right first (index 0) item from nth()", 17, n->nth(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right second (index 1) item from nth()", 34, n->nth(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right third (index 2) item from nth()", 3, n->nth(2));
  for (int k = 0; k < 100; k++) {
    int i = rand() % 1000;
    CPPUNIT_ASSERT_EQUAL(ncirc->nth(i % 2), ncirc->nth(i));
  }
}

void ExtendedSLListTest::testNthRest() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right rest (index 0) from nthRest()", n, n->nthRest(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right rest (index 1) next from nthRest()", n->rest(), n->nthRest(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right rest (index 2) next from nthRest()", n->rest()->rest(), n->nthRest(2));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right rest (index 3) next from nthRest()", SLList::NIL, n->nthRest(3));
  for (int k = 0; k < 100; k++) {
    int i = rand() % 1000;
    CPPUNIT_ASSERT_EQUAL(ncirc->nthRest(i % 2), ncirc->nthRest(i));
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(ExtendedSLListTest, "Extended");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Extended");
