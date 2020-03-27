#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "BinarySearch.hpp"

class BinarySearchSearchTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BinarySearchSearchTest);
  CPPUNIT_TEST(testZeroLengthSearch);
  CPPUNIT_TEST(testSmallSearch);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testZeroLengthSearch();
  void testSmallSearch();
};

void BinarySearchSearchTest::testZeroLengthSearch() {
  int x[0];
  BinarySearch b;
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty array", !b.search(x, 0, 0, 0));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty array", !b.search(x, 1, 0, 0));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty array", !b.search(x, 2, 0, 0));
  int y[4] = {0,2,3,4};
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !b.search(y, 0, 0, 0));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !b.search(y, 1, 1, 1));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !b.search(y, 2, 2, 2));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !b.search(y, 4, 3, 3));
}

void BinarySearchSearchTest::testSmallSearch() {
  int x[4] = {0,2,4,6};
  BinarySearch b;
  CPPUNIT_ASSERT_MESSAGE("-2 is not in {0,2,4,6}", !b.search(x, -2, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("-1 is not in {0,2,4,6}", !b.search(x, -1, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("0 is in {0,2,4,6}", b.search(x, 0, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("1 is not in {0,2,4,6}", !b.search(x, 1, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("2 is in {0,2,4,6}", b.search(x, 2, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("3 is not in {0,2,4,6}", !b.search(x, 3, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("4 is in {0,2,4,6}", b.search(x, 4, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("5 is not in {0,2,4,6}", !b.search(x, 5, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("6 is in {0,2,4,6}", b.search(x, 6, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("7 is not in {0,2,4,6}", !b.search(x, 7, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("8 is not in {0,2,4,6}", !b.search(x, 8, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("4 is not in the first half of {0,2,4,6}", !b.search(x, 4, 0, 2));
  CPPUNIT_ASSERT_MESSAGE("2 is not in the second half of {0,2,4,6}", !b.search(x, 2, 2, 4));
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BinarySearchSearchTest, "Search");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Search");
