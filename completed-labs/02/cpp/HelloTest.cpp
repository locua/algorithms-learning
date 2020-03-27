#include <cppunit/extensions/HelperMacros.h>
#include "Hello.hpp"

class HelloTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HelloTest);
  CPPUNIT_TEST(testMoodleID);
  CPPUNIT_TEST(testStudentNumber);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testMoodleID();
  void testStudentNumber();
};

void HelloTest::testStudentNumber() {
  Hello h;
  int sn = h.studentNumber();
  CPPUNIT_ASSERT_MESSAGE("Your student number should be greater than 200000", sn > 200000);
  CPPUNIT_ASSERT_MESSAGE("Your student number should be less than 40000000", sn < 40000000);
}

void HelloTest::testMoodleID() {
  Hello h;
  int mid = h.moodleID();
  CPPUNIT_ASSERT_MESSAGE("Your moodle ID number should be greater than 10000", mid > 10000);
  CPPUNIT_ASSERT_MESSAGE("Your moodle ID number should be less than 100000", mid < 100000);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HelloTest, "Hello");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Hello");
