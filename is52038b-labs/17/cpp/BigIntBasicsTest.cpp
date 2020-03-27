#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <cmath>

#include "BigInt.hpp"

class BigIntBasicsTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BigIntBasicsTest);
  CPPUNIT_TEST(testGet);
  CPPUNIT_TEST(testRandomGet);
  CPPUNIT_TEST(testStringConstructor);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testGet();
  void testRandomGet();
  void testStringConstructor();
};

void BigIntBasicsTest::testGet() {
  BigInt *b = new BigInt(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 1, b->ndigits);
  b->data[0] = 9;
  CPPUNIT_ASSERT_EQUAL_MESSAGE("->get() not returning known data", static_cast<unsigned char>(9), b->get(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("->get() not returning zero for out-of-bounds", static_cast<unsigned char>(0), b->get(1));
  delete b;
}

void BigIntBasicsTest::testRandomGet() {
  BigInt *b = new BigInt(10);
  unsigned char d[10];
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 10, b->ndigits);
  for (int i = 0; i < (int) b->ndigits; i++) {
    d[i] = rand() % 10;
    b->data[i] = d[i];
  }
  for (int i = 0; i < 10; i++) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("->get() not returning random data", d[i], b->get(i));
  }
  delete b;
}

void BigIntBasicsTest::testStringConstructor() {
  BigInt *b = new BigInt("6283");
  unsigned char d[4] = {3, 8, 2, 6};
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after string constructor", (size_t) 4, b->ndigits);
  for (int i = 0; i < (int) b->ndigits; i++) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("string constructor has unexpected content", d[i], b->get(i));
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BigIntBasicsTest, "Basics");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Basics");
