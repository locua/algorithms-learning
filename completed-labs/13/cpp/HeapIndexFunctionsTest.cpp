#include <cmath>
#include <cppunit/extensions/HelperMacros.h>

#include "Heap.hpp"

class HeapIndexFunctionsTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HeapIndexFunctionsTest);
  CPPUNIT_TEST(testLeft);
  CPPUNIT_TEST(testRight);
  CPPUNIT_TEST(testParent);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() {};
  void tearDown() {};

  void testLeft();
  void testRight();
  void testParent();
};

void HeapIndexFunctionsTest::testLeft() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the left child of the node at position 0?", 1U, left(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the left child of the node at position 1?", 3U, left(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the left child of the node at position 2?", 5U, left(2));
  for (int i = 0; i < 100; i++) {
    unsigned int x = rand() % 32768;
    CPPUNIT_ASSERT_EQUAL_MESSAGE("a random choice of parent has an erroneous child!", 2*x+1, left(x));
  }
}

void HeapIndexFunctionsTest::testRight() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the right child of the node at position 0?", 2U, right(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the right child of the node at position 1?", 4U, right(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the right child of the node at position 2?", 6U, right(2));
  for (int i = 0; i < 100; i++) {
    unsigned int x = rand() % 32768;
    CPPUNIT_ASSERT_EQUAL_MESSAGE("a random choice of parent has an erroneous child!", 2*x+2, right(x));
  }
}

void HeapIndexFunctionsTest::testParent() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the parent of the node at position 1?", 0U, parent(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the parent of the node at position 2?", 0U, parent(2));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("what is the index of the parent of the node at position 3?", 1U, parent(3));
  for (int i = 0; i < 100; i++) {
    unsigned int x = 1 + rand() % 32767;
    CPPUNIT_ASSERT_EQUAL_MESSAGE("a random choice of child has an erroneous parent!", (x-1)/2, parent(x));
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HeapIndexFunctionsTest, "IndexFunctions");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("IndexFunctions");
