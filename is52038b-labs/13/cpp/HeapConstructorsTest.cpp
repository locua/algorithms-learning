#include <cppunit/extensions/HelperMacros.h>

#include "Heap.hpp"

class HeapConstructorsTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HeapConstructorsTest);
  CPPUNIT_TEST(testMinimalConstructors);
  CPPUNIT_TEST(testIncrementalConstructor);
  CPPUNIT_TEST(testDirectConstructor);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() {};
  void tearDown() {};

  void testMinimalConstructors();
  void testIncrementalConstructor();
  void testDirectConstructor();
};

void HeapConstructorsTest::testMinimalConstructors() {
  Heap h = Heap(0);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("heap size violation for 0-length heap", 0U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("array length violation for 0-length heap", 0UL, (unsigned long) h.array.size());
  std::vector<int> v = std::vector<int>(0);
  h = Heap(v);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("heap size violation for 0-length heap", 0U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("array length violation for 0-length heap", 0UL, (unsigned long) h.array.size());
  h = Heap(v, false);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("heap size violation for 0-length heap", 0U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("array length violation for 0-length heap", 0UL, (unsigned long) h.array.size());
  h = Heap(v, true);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("heap size violation for 0-length heap", 0U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("array length violation for 0-length heap", 0UL, (unsigned long) h.array.size());
}

void HeapConstructorsTest::testIncrementalConstructor() {
  std::vector<int> v = {17};
  Heap h = Heap(v, true);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap size of a new one-element heap should be 1", 1U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the one-element heap's array should be the value in the initializer vector", 17, h.array[0]);
  std::vector<int> w = {18,14};
  h = Heap(w, true);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap size of a new two-element heap should be 2", 2U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the larger value in the initializer vector", 18, h.array[0]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the smaller value in the initializer vector", 14, h.array[1]);
  std::vector<int> x = {14,18};
  h = Heap(x, true);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap size of a new two-element heap should be 2", 2U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the larger value in the initializer vector", 18, h.array[0]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the smaller value in the initializer vector", 14, h.array[1]);
  std::vector<int> z = {10, 8, 14, 15, 12, 5, 6, 1};
  h = Heap(z, true);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap from figure 4.16 of Ida's subject guide should have length 8", 8U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the heap in figure 4.16 of Ida's subject guide is wrong", 15, h.array[0]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The second element of the heap in figure 4.16 of Ida's subject guide is wrong", 14, h.array[1]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The third element of the heap in figure 4.16 of Ida's subject guide is wrong", 10, h.array[2]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The fourth element of the heap in figure 4.16 of Ida's subject guide is wrong", 8, h.array[3]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The fifth element of the heap in figure 4.16 of Ida's subject guide is wrong", 12, h.array[4]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The sixth element of the heap in figure 4.16 of Ida's subject guide is wrong", 5, h.array[5]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The seventh element of the heap in figure 4.16 of Ida's subject guide is wrong", 6, h.array[6]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The eighth element of the heap in figure 4.16 of Ida's subject guide is wrong", 1, h.array[7]);
}

void HeapConstructorsTest::testDirectConstructor() {
  std::vector<int> v = {17};
  Heap h = Heap(v, false);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap size of a new one-element heap should be 1", 1U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the one-element heap's array should be the value in the initializer vector", 17, h.array[0]);
  std::vector<int> w = {18,14};
  h = Heap(w, false);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap size of a new two-element heap should be 2", 2U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the larger value in the initializer vector", 18, h.array[0]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the larger value in the initializer vector", 14, h.array[1]);
  std::vector<int> x = {14,18};
  h = Heap(x, false);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap size of a new two-element heap should be 2", 2U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the larger value in the initializer vector", 18, h.array[0]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the two-element heap's array should be the larger value in the initializer vector", 14, h.array[1]);
  std::vector<int> z = {10, 8, 14, 15, 12, 5, 6, 1};
  h = Heap(z, false);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The heap directly constructed from figure 4.16 of Ida's subject guide should have length 8", 8U, h.heap_size);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The first element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 15, h.array[0]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The second element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 12, h.array[1]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The third element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 14, h.array[2]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The fourth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 8, h.array[3]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The fifth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 10, h.array[4]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The sixth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 5, h.array[5]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The seventh element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 6, h.array[6]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The eighth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", 1, h.array[7]);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HeapConstructorsTest, "Constructors");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Constructors");
