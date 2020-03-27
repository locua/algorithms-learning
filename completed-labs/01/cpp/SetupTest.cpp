#include <cppunit/extensions/HelperMacros.h>

class SetupTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(SetupTest);
  CPPUNIT_TEST(testSetup);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testSetup();
};

void SetupTest::testSetup() {
  CPPUNIT_ASSERT_MESSAGE("CppUnit is not working", true);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SetupTest, "Setup");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Setup");
