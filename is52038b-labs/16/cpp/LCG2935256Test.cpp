#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "LCG.hpp"

class LCG2935256Test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(LCG2935256Test);
  CPPUNIT_TEST(testSequence);
  CPPUNIT_TEST(testNext);
  CPPUNIT_TEST(testSeed);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testSequence();
  void testNext();
  void testSeed();
};

void LCG2935256Test::testSequence() {
  LCG g = LCG(29, 35, 256, 1);
  {
    uint32_t z[10] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
    for (int i = 0; i < 10; i++) {
      CPPUNIT_ASSERT_EQUAL_MESSAGE("unexpected next", z[i], g.next());
    }
  }
  g = LCG(29, 35, 256, 2);
  {
    uint32_t z[10] = {93, 172, 159, 38, 113, 240, 83, 138, 197, 116};
    for (int i = 0; i < 10; i++) {
      CPPUNIT_ASSERT_EQUAL_MESSAGE("unexpected next", z[i], g.next());
    }
  }
  g = LCG(29, 35, 256, 3);
  {
    uint32_t z[10] = {122, 245, 228, 247, 30, 137, 168, 43, 2, 93};
    for (int i = 0; i < 10; i++) {
      CPPUNIT_ASSERT_EQUAL_MESSAGE("unexpected next", z[i], g.next());
    }
  }
}

void LCG2935256Test::testNext() {
  LCG g = LCG(29, 35, 256, 0);
  uint32_t z = 0;
  for (int i = 0; i < 256; i++) {
    z = (29*z + 35) % 256;
    uint32_t x = g.next();
    CPPUNIT_ASSERT_EQUAL_MESSAGE("unexpected next", z, x);
  }
}

void LCG2935256Test::testSeed() {
  LCG g = LCG(29, 35, 256, 11);
  g.seed(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("seed appears not to have seeded", 64u, g.next());
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(LCG2935256Test, "2935256");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("2935256");
