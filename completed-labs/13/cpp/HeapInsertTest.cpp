#include <cppunit/extensions/HelperMacros.h>

#include "Heap.hpp"
#include "HeapTest.hpp"

class HeapInsertTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HeapInsertTest);
  CPPUNIT_TEST(testInsertIntoZeroHeap);
  CPPUNIT_TEST(testInsertIntoHeap);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() {};
  void tearDown() {};

  void testInsertIntoZeroHeap();
  void testInsertIntoHeap();
};

void HeapInsertTest::testInsertIntoZeroHeap() {
  Heap h = Heap(0);
  h.insert(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The array should have a size of 1", 1UL, (unsigned long) h.array.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The object inserted into a zero heap should be at the root", 1, h.array[0]);
}

void HeapInsertTest::testInsertIntoHeap() {
  std::vector<int> v = {1, -3, 17, 4, 2};
  Heap h = Heap(v);
  CPPUNIT_ASSERT_MESSAGE("The heap constructed violates the heap property", check_heap(h));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The array should have a size of 5", 5UL, (unsigned long) h.array.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The root of the heap should be the maximum element", 17, h.array[0]);
  h.insert(-5);
  CPPUNIT_ASSERT_MESSAGE("After inserting -5, the heap is no longer a heap", check_heap(h));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The array should have a size of 6", 6UL, (unsigned long) h.array.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Inserting something smaller than all elements should put the new element at the end", -5, h.array[5]);
  h.insert(200);
  CPPUNIT_ASSERT_MESSAGE("After inserting 200, the heap is no longer a heap", check_heap(h));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The array should have a size of 7", 7UL, (unsigned long) h.array.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Inserting something larger than all elements should make it bubble up to the root", 200, h.array[0]);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HeapInsertTest, "Insert");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Insert");
