#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <cmath>

#include "BigInt.hpp"

class BigIntSubTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BigIntSubTest);
  CPPUNIT_TEST(testSub);
  CPPUNIT_TEST(testSubWithBorrow);
  CPPUNIT_TEST(testRandomSub);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testSub();
  void testSubWithBorrow();
  void testRandomSub();
};

void BigIntSubTest::testSub() {
  BigInt *b1 = new BigInt(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 1, b1->ndigits);
  b1->data[0] = 5;
  BigInt *b2 = new BigInt(1);
  b2->data[0] = 3;
  BigInt *b3 = b1->Sub(b2);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("5-3 != 2?", static_cast<unsigned char>(2), b3->get(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("5-3 > 10?", static_cast<unsigned char>(0), b3->get(1));
  delete b1;
  delete b2;
  delete b3;
}

void BigIntSubTest::testSubWithBorrow() {
  BigInt *b11 = new BigInt(2);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 2, b11->ndigits);
  b11->data[0] = 1;
  b11->data[1] = 1;
  BigInt *b3 = new BigInt(1);
  b3->data[0] = 3;
  BigInt *b8 = b11->Sub(b3);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("11-3 % 10 != 8?", static_cast<unsigned char>(8), b8->get(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("11-3/10 % 10 != 0?", static_cast<unsigned char>(0), b8->get(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("11-3/100 % 10 != 0?", static_cast<unsigned char>(0), b8->get(2));
  delete b11;
  delete b3;
  delete b8;
}

void BigIntSubTest::testRandomSub() {
  BigInt *ba = new BigInt(6);
  BigInt *bb = new BigInt(6);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 6, ba->ndigits);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 6, bb->ndigits);
  unsigned long a = rand() % 1000000;
  unsigned long b = rand() % a;
  unsigned long atmp = a;
  unsigned long btmp = b;
  for (int i = 0; i < 6; i++) {
    ba->data[i] = atmp % 10;
    atmp = atmp / 10;
    bb->data[i] = btmp % 10;
    btmp = btmp / 10;
  }
  BigInt *bc = ba->Sub(bb);
  unsigned long c = a - b;
  unsigned long ctmp = c;
  for (int i = 0; i < 6; i++) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("mismatch in random subtraction", static_cast<unsigned char>(ctmp % 10), bc->get(i));
    ctmp = ctmp / 10;
  }
  delete ba;
  delete bb;
  delete bc;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BigIntSubTest, "Sub");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Sub");
