#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "HashTable.hpp"

class HashTableLoadFactorTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HashTableLoadFactorTest);
  CPPUNIT_TEST(testLoadFactorOne);
  CPPUNIT_TEST(testLoadFactorCollision);
  CPPUNIT_TEST(testLoadFactorSequence);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testLoadFactorOne();
  void testLoadFactorCollision();
  void testLoadFactorSequence();
};

void HashTableLoadFactorTest::testLoadFactorOne() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("load factor of empty table is not zero", 0.0, t.loadFactor(), 0.0);
  t.insert(1);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("load factor of table with one element is not right", 1.0/256, t.loadFactor(), 0.0);
}

void HashTableLoadFactorTest::testLoadFactorCollision() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  t.insert(1);
  t.insert(257);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("load factor of table with two elements is not right", 2.0/256, t.loadFactor(), 0.0);
}

void HashTableLoadFactorTest::testLoadFactorSequence() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  int z[] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
  for (int i = 0; i < 9; i++) {
    t.insert(z[i]);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("load factor is wrong", ((double) (i+1))/256, t.loadFactor(), 0.0);
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HashTableLoadFactorTest, "LoadFactor");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("LoadFactor");
