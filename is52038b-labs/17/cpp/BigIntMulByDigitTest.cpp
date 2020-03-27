#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <cmath>

#include "BigInt.hpp"

class BigIntMulByDigitTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BigIntMulByDigitTest);
  CPPUNIT_TEST(testMulByDigit);
  CPPUNIT_TEST(testRandomMulByDigit);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testMulByDigit();
  void testRandomMulByDigit();
};

void BigIntMulByDigitTest::testMulByDigit() {
  BigInt *b1 = new BigInt(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 1, b1->ndigits);
  b1->data[0] = 7;
  BigInt *b2 = b1->MulByDigit(8);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("7*8 % 10 != 6", static_cast<unsigned char>(6), b2->get(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("7*8 / 10 != 5", static_cast<unsigned char>(5), b2->get(1));
  delete b1;
  delete b2;
}

void BigIntMulByDigitTest::testRandomMulByDigit() {
  BigInt *ba = new BigInt(6);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 6, ba->ndigits);
  unsigned long a = rand() % 1000000;
  unsigned long atmp = a;
  for (int i = 0; i < 6; i++) {
    ba->data[i] = atmp % 10;
    atmp = atmp / 10;
  }
  BigInt *bm = ba->MulByDigit(9);
  unsigned long m = a * 9;
  unsigned long mtmp = m;
  for (int i = 0; i < 7; i++) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("mismatch in random multiplication by digit", static_cast<unsigned char>(mtmp % 10), bm->get(i));
    mtmp = mtmp / 10;    
  }
  delete ba;
  delete bm;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BigIntMulByDigitTest, "MulByDigit");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("MulByDigit");
