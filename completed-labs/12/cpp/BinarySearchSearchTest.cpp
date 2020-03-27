#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "BinarySearch.hpp"

class BinarySearchSearchTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BinarySearchSearchTest);
  CPPUNIT_TEST(testZeroLengthSearch);
  CPPUNIT_TEST(testSmallSearch);
  CPPUNIT_TEST(quiz);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testZeroLengthSearch();
  void testSmallSearch();
  void quiz();
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

void BinarySearchSearchTest::quiz(){
    // int x[] = {1,4,6,7,9,10,11};
    // int x[] = {};
    int x[] = {3,6,11,14,21,34,35,36,44,47,52,71,74,83,94};
    // int x[] = {0,6,9,43,49,101,236,305,307,354,415,438,459,477,489,601,616,617,632,644,669,676,691,722,742,822,830,857,858,862,930};
    // int x[] = {3,6,11,14,21,34,35,36,44,47,52,71,74,83,94};
    BinarySearch b;
    int y = 2;
    std::cout << b.count(x, y, 0, sizeof(x)/sizeof(*x));
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BinarySearchSearchTest, "Search");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Search");
