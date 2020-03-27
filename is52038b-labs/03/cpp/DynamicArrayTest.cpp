#include <cmath>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "DynamicArray.hpp"

class DynamicArrayTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(DynamicArrayTest);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testSmall);
  CPPUNIT_TEST(testLargePush);
  CPPUNIT_TEST(testLargePop);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };
  void testConstructor();
  void testSmall();
  void testLargePush();
  void testLargePop();
};

void DynamicArrayTest::testConstructor() {
  DynamicArray *a = new DynamicArray(10);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A fresh dynamic array should have zero length", ((size_t) 0UL), a->length());
  delete a;
}

void DynamicArrayTest::testSmall() {
  DynamicArray *a = new DynamicArray(10);
  a->push(1);
  CPPUNIT_ASSERT_EQUAL(((size_t) 1UL), a->length());
  CPPUNIT_ASSERT_EQUAL(1, a->select(0));
  a->push(3);
  CPPUNIT_ASSERT_EQUAL(((size_t) 2UL), a->length());
  CPPUNIT_ASSERT_EQUAL(1, a->select(0));
  CPPUNIT_ASSERT_EQUAL(3, a->select(1));
  a->store(2, 0UL);
  CPPUNIT_ASSERT_EQUAL(((size_t) 2UL), a->length());
  CPPUNIT_ASSERT_EQUAL(2, a->select(0));
  CPPUNIT_ASSERT_EQUAL(3, a->select(1));
  delete a;
}

void DynamicArrayTest::testLargePush() {
  DynamicArray *a = new DynamicArray(10);
  for (int i = 0; i < 100; i++) {
    a->push(i);
  }
  CPPUNIT_ASSERT_EQUAL(((size_t) 100UL), a->length());
  CPPUNIT_ASSERT_EQUAL(99, a->select(99));
  CPPUNIT_ASSERT_EQUAL(3, a->select(3));
  delete a;
}

void DynamicArrayTest::testLargePop() {
  DynamicArray *a = new DynamicArray(10);
  for (int i = 1; i <= 100; i++) {
    a->push(i);
  }
  for (int i = 100; i >= 1; i--) {
    CPPUNIT_ASSERT_EQUAL((size_t) i, a->length());
    CPPUNIT_ASSERT_EQUAL(i, a->pop());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("pop should reduce the length of a dynamic array by 1", (size_t) (i-1), a->length());
  }
  delete a;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(DynamicArrayTest, "DynamicArray");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("DynamicArray");

/* FIXME: more boilerplate */
int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cerr << "Usage: " << argv[0] << " [suitename]" << std::endl;
    return 1;
  }
  CppUnit::Test *test;
  CppUnit::TextUi::TestRunner runner;
  if (argc == 2)
    test = CppUnit::TestFactoryRegistry::getRegistry(argv[1]).makeTest();
  else
    test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  runner.addTest(test);
  runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));

  bool wasSuccessful = runner.run();
  return wasSuccessful ? 0 : 1;
}
