#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "BigInt.hpp"

class BigIntShiftTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BigIntShiftTest);
  CPPUNIT_TEST(testShift);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testShift();
};

void BigIntShiftTest::testShift() {
  BigInt *b1 = new BigInt(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("ndigits wrong after basic constructor", (size_t) 1, b1->ndigits);
  b1->data[0] = 5;
  BigInt *b2 = b1->Shift(3);
  for(int i = 0; i < 3; i++) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("low digits not zero after shift", static_cast<unsigned char>(0), b2->get(i));
  }
  CPPUNIT_ASSERT_EQUAL_MESSAGE("shifted data not right after shift", static_cast<unsigned char>(5), b2->get(3));
  delete b1;
  delete b2;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BigIntShiftTest, "Shift");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Shift");
