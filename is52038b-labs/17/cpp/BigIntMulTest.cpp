#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <cmath>

#include "BigInt.hpp"

class BigIntMulTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BigIntMulTest);
  CPPUNIT_TEST(testMul);
  CPPUNIT_TEST(testRandomMul);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testMul();
  void testRandomMul();
};

void BigIntMulTest::testMul() {
  BigInt *b1 = new BigInt(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 1, b1->ndigits);
  b1->data[0] = 7;
  BigInt *b2 = new BigInt(2);
  b2->data[0] = 8;
  BigInt *b3 = b1->Mul(b2);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("7*8 % 10 != 6", static_cast<unsigned char>(6), b3->get(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("7*8 / 10 != 5", static_cast<unsigned char>(5), b3->get(1));
  delete b1;
  delete b2;
  delete b3;
}

void BigIntMulTest::testRandomMul() {
  BigInt *ba = new BigInt(3);
  BigInt *bb = new BigInt(3);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 3, ba->ndigits);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 3, bb->ndigits);
  unsigned long a = rand() % 1000;
  unsigned long b = rand() % 1000;
  unsigned long atmp = a;
  unsigned long btmp = b;
  for (int i = 0; i < 3; i++) {
    ba->data[i] = atmp % 10;
    atmp = atmp / 10;
    bb->data[i] = btmp % 10;
    btmp = btmp / 10;
  }
  BigInt *bc = ba->Mul(bb);
  unsigned long c = a * b;
  unsigned long ctmp = c;
  for (int i = 0; i < 7; i++) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("mismatch in random multiplication", static_cast<unsigned char>(ctmp % 10), bc->get(i));
    ctmp = ctmp / 10;
  }
  delete ba;
  delete bb;
  delete bc;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BigIntMulTest, "Mul");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Mul");
