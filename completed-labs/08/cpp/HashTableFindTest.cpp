#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "HashTable.hpp"

class HashTableFindTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HashTableFindTest);
  CPPUNIT_TEST(testFindOne);
  CPPUNIT_TEST(testFindCollision);
  CPPUNIT_TEST(testFindSequence);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testFindOne();
  void testFindCollision();
  void testFindSequence();
};

void HashTableFindTest::testFindOne() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  t.insert(1);
  CPPUNIT_ASSERT_MESSAGE("key 1 not found", t.find(1));
}

void HashTableFindTest::testFindCollision() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  t.insert(1);
  t.insert(257);
  CPPUNIT_ASSERT_MESSAGE("key 1 not found", t.find(1));
  CPPUNIT_ASSERT_MESSAGE("key 257 not found", t.find(257));
  CPPUNIT_ASSERT_MESSAGE("key 513 found", !t.find(513));
}

void HashTableFindTest::testFindSequence() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  int z[] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
  for (int i = 0; i < 9; i++) {
    t.insert(z[i]);
    CPPUNIT_ASSERT_MESSAGE("key not found", t.find(z[i]));
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HashTableFindTest, "Find");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Find");
