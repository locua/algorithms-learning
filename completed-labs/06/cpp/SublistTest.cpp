#include <cppunit/extensions/HelperMacros.h>

#include "SLList.hpp"

class SublistTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(SublistTest);
  CPPUNIT_TEST(testSublistOfNIL);
  CPPUNIT_TEST(testEmptySublist);
  CPPUNIT_TEST(testNonemptySublist);
  CPPUNIT_TEST_SUITE_END();

private:
  SLList *n, *ncirc;
public:
  void setUp() {
    n = new SLList(96, new SLList(172, new SLList(3, SLList::NIL)));
    ncirc = new SLList(4, new SLList(17, SLList::NIL));
    ncirc->rest()->setRest(ncirc);
  };
  void tearDown() {
    /* in principle delete the SLLists */
  };

  void testSublistOfNIL();
  void testEmptySublist();
  void testNonemptySublist();
};

void SublistTest::testSublistOfNIL() {
  SLList *r = SLList::NIL->sublist(0, 0);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The sublist of NIL starting at 0 and ending at 0 should be NIL", SLList::NIL, r);
}

void SublistTest::testEmptySublist() {
  SLList *r = n->sublist(0,0);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The sublist of a list starting at 0 and ending at 0 should be NIL", SLList::NIL, r);
  SLList *r2 = n->sublist(1,1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The sublist of a non-empty list starting at 1 and ending at 1 should be NIL", SLList::NIL, r2);
}

void SublistTest::testNonemptySublist() {
  SLList *r = n->sublist(0,1);
  CPPUNIT_ASSERT_MESSAGE("The list returned from sublist with start 0 and end 1 should not be NIL", SLList::NIL != r);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the sublist with start 0 and end 1 should be 96", 96, r->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The list returned from sublist with start 0 and end 1 should have length 1.", SLList::NIL, r->rest());
  SLList *r2 = n->sublist(1,2);
  CPPUNIT_ASSERT_MESSAGE("The list returned from sublist with start 1 and end 2 should not be NIL", SLList::NIL != r);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the sublist with start 1 and end 2 should be 172", 172, r2->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The list returned from sublist with start 1 and end 2 should have length 1.", SLList::NIL, r2->rest());
  SLList *r3 = n->sublist(1,3);
  CPPUNIT_ASSERT_MESSAGE("The list returned from sublist with start 1 and end 3 should not be NIL", SLList::NIL != r3);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the sublist with start 1 and end 3 should be 172", 172, r3->first());
  CPPUNIT_ASSERT_MESSAGE("The list returned from sublist with start 1 and end 3 should have length 2.", SLList::NIL != r3->rest());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The second element of the sublist with start 1 and end 3 should be 3", 3, r3->rest()->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The list returned from sublist with start 1 and end 3 should have length 2.", SLList::NIL, r3->rest()->rest());
  SLList *r4 = ncirc->sublist(10,11);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The sublist with start 10 and end 11 should be (4)", 4, r4->first());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The sublist with start 10 and end 11 should be (4)", SLList::NIL, r4->rest());
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SublistTest, "Sublist");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Sublist");
