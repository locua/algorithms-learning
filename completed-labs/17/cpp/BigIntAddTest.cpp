#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <cmath>

#include "BigInt.hpp"

class BigIntAddTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BigIntAddTest);
  CPPUNIT_TEST(testAdd);
  CPPUNIT_TEST(testAddWithCarry);
  CPPUNIT_TEST(testRandomAdd);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testAdd();
  void testAddWithCarry();
  void testRandomAdd();
};

void BigIntAddTest::testAdd() {
  BigInt *b1 = new BigInt(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 1, b1->ndigits);
  b1->data[0] = 1;
  BigInt *b2 = b1->Add(b1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("1+1 != 2?", static_cast<unsigned char>(2), b2->get(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("1+1 > 10?", static_cast<unsigned char>(0), b2->get(1));
  delete b1;
  delete b2;
}

void BigIntAddTest::testAddWithCarry() {
  BigInt *b9 = new BigInt(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 1, b9->ndigits);
  b9->data[0] = 9;
  BigInt *b18 = b9->Add(b9);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("9+9 % 10 != 8?", static_cast<unsigned char>(8), b18->get(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("9+9/10 % 10 != 1?", static_cast<unsigned char>(1), b18->get(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("9+9/100 % 10 != 0?", static_cast<unsigned char>(0), b18->get(2));
  delete b9;
  delete b18;
}

void BigIntAddTest::testRandomAdd() {
  BigInt *ba = new BigInt(6);
  BigInt *bb = new BigInt(6);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 6, ba->ndigits);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 6, bb->ndigits);
  unsigned long a = rand() % 1000000;
  unsigned long b = rand() % 1000000;
  unsigned long atmp = a;
  unsigned long btmp = b;
  for (int i = 0; i < 6; i++) {
    ba->data[i] = atmp % 10;
    atmp = atmp / 10;
    bb->data[i] = btmp % 10;
    btmp = btmp / 10;
  }
  BigInt *bc = ba->Add(bb);
  unsigned long c = a + b;
  unsigned long ctmp = c;
  for (int i = 0; i < 7; i++) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("mismatch in random addition", static_cast<unsigned char>(ctmp % 10), bc->get(i));
    ctmp = ctmp / 10;
  }
  delete ba;
  delete bb;
  delete bc;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BigIntAddTest, "Add");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Add");
