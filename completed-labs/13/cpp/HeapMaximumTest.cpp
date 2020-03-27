#include <cppunit/extensions/HelperMacros.h>

#include "Heap.hpp"
#include "HeapTest.hpp"

class HeapMaximumTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HeapMaximumTest);
  CPPUNIT_TEST(testMaximum);
  CPPUNIT_TEST(testExtractMax);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() {};
  void tearDown() {};

  void testMaximum();
  void testExtractMax();
};

void HeapMaximumTest::testMaximum() {
  Heap h = Heap(0);
  h.insert(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The object inserted into a zero heap should be the maximum", 1, h.maximum());
  std::vector<int> v = {1, 49, 3, 578, 2, -1000};
  h = Heap(v);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The largest element in the initialization vector should be the maximum", 578, h.maximum());
}

void HeapMaximumTest::testExtractMax() {
  std::vector<int> v = {17};
  Heap h = Heap(v);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The maximum extracted should be the single value", 17, h.extractMax());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("After removing the maximum from the heap, the heap should be empty", 0U, h.heap_size);
  std::vector<int> w = {15,14,10,8,12,5,6,1}; // heap-ordered already
  h = Heap(w);
  CPPUNIT_ASSERT_MESSAGE("The heap formed from w is not a heap", check_heap(h));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The maximum extracted is wrong", 15, h.extractMax());
  CPPUNIT_ASSERT_MESSAGE("After extracting, the heap property is violated", check_heap(h));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("After extracting, the current maximum is wrong", 14, h.maximum());
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HeapMaximumTest, "Maximum");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Maximum");
