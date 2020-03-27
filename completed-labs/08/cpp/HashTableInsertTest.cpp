#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "HashTable.hpp"

class HashTableInsertTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(HashTableInsertTest);
  CPPUNIT_TEST(testInsertOne);
  CPPUNIT_TEST(testInsertCollision);
  CPPUNIT_TEST(testInsertSequence);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testInsertOne();
  void testInsertCollision();
  void testInsertSequence();
};

void HashTableInsertTest::testInsertOne() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  t.insert(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("key 1 not found in bucket 64", 1, t.buckets[64]);
}

void HashTableInsertTest::testInsertCollision() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  t.insert(1);
  t.insert(257);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("key 1 not found in bucket 64", 1, t.buckets[64]);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("key 257 not found in bucket 65", 257, t.buckets[65]);
}

void HashTableInsertTest::testInsertSequence() {
  HashTable t = HashTable(29, 35, 256);
  CPPUNIT_ASSERT_MESSAGE("buckets array is null", t.buckets != NULL);
  int z[] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
  for (int i = 0; i < 9; i++) {
    t.insert(z[i]);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("key not found in right table bucket", z[i], t.buckets[z[i+1]]);
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(HashTableInsertTest, "Insert");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Insert");
