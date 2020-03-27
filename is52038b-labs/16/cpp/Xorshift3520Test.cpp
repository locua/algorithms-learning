#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Xorshift.hpp"

class Xorshift3520Test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(Xorshift3520Test);
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

void Xorshift3520Test::testSequence() {
  Xorshift g = Xorshift(3, 5, 20, 1);
  {
    uint32_t z[10] = {9437193u, 32835u, 1687463497u, 3357546657u, 959044420u, 1628715375u, 2995281287u, 1692197938u, 4175043471u, 595235272u};
    for (int i = 0; i < 10; i++) {
      CPPUNIT_ASSERT_EQUAL_MESSAGE("unexpected next", z[i], g.next());
    }
  }
}

void Xorshift3520Test::testNext() {
  Xorshift g = Xorshift(3, 5, 20, 11);
  uint32_t z = 11;
  for (int i = 0; i < 256; i++) {
    z ^= z << 3;
    z ^= z >> 5;
    z ^= z << 20;
    uint32_t x = g.next();
    CPPUNIT_ASSERT_EQUAL_MESSAGE("unexpected next", z, x);
  }
}

void Xorshift3520Test::testSeed() {
  Xorshift g = Xorshift(3, 5, 20, 11);
  g.seed(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("seed appears not to have seeded", 9437193u, g.next());
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(Xorshift3520Test, "3520");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("3520");
