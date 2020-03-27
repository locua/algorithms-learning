#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Trie.hpp"

class TrieQueryTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(TrieQueryTest);
  CPPUNIT_TEST(testQueryOne);
  CPPUNIT_TEST(testQueryTwo);
  CPPUNIT_TEST(testQueryCommonPrefix);
  CPPUNIT_TEST(testQueryStock);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testQueryOne();
  void testQueryTwo();
  void testQueryCommonPrefix();
  void testQueryStock();
};

void TrieQueryTest::testQueryOne() {
  Trie *t = new Trie();
  t->insert("one");
  CPPUNIT_ASSERT(!t->query("a"));
  CPPUNIT_ASSERT(!t->query("on"));
  CPPUNIT_ASSERT(t->query("one"));
  CPPUNIT_ASSERT(!t->query("ones"));
  CPPUNIT_ASSERT(!t->query("two"));
  CPPUNIT_ASSERT(!t->query("only"));
}

void TrieQueryTest::testQueryTwo() {
  Trie *t = new Trie();
  t->insert("one");
  t->insert("two");
  CPPUNIT_ASSERT(!t->query("a"));
  CPPUNIT_ASSERT(!t->query("on"));
  CPPUNIT_ASSERT(t->query("one"));
  CPPUNIT_ASSERT(!t->query("ones"));
  CPPUNIT_ASSERT(!t->query("t"));
  CPPUNIT_ASSERT(!t->query("tw"));
  CPPUNIT_ASSERT(t->query("two"));
  CPPUNIT_ASSERT(!t->query("twos"));
  CPPUNIT_ASSERT(!t->query("only"));
}

void TrieQueryTest::testQueryCommonPrefix() {
  Trie *t = new Trie();
  t->insert("one");
  t->insert("only");
  CPPUNIT_ASSERT(!t->query("a"));
  CPPUNIT_ASSERT(!t->query("on"));
  CPPUNIT_ASSERT(t->query("one"));
  CPPUNIT_ASSERT(!t->query("ones"));
  CPPUNIT_ASSERT(!t->query("t"));
  CPPUNIT_ASSERT(!t->query("tw"));
  CPPUNIT_ASSERT(!t->query("two"));
  CPPUNIT_ASSERT(!t->query("twos"));
  CPPUNIT_ASSERT(t->query("only"));
}

void TrieQueryTest::testQueryStock() {
  Trie *t = new Trie();
  CPPUNIT_ASSERT(!t->query("bear"));
  t->insert("bear");
  CPPUNIT_ASSERT(t->query("bear"));
  CPPUNIT_ASSERT(!t->query("bell"));
  t->insert("bell");
  CPPUNIT_ASSERT(t->query("bell"));
  CPPUNIT_ASSERT(!t->query("bid"));
  t->insert("bid");
  CPPUNIT_ASSERT(t->query("bid"));
  CPPUNIT_ASSERT(!t->query("bull"));
  t->insert("bull");
  CPPUNIT_ASSERT(t->query("bull"));
  CPPUNIT_ASSERT(!t->query("buy"));
  t->insert("buy");
  CPPUNIT_ASSERT(t->query("buy"));
  CPPUNIT_ASSERT(!t->query("sell"));
  t->insert("sell");
  CPPUNIT_ASSERT(t->query("sell"));
  CPPUNIT_ASSERT(!t->query("stock"));
  t->insert("stock");
  CPPUNIT_ASSERT(t->query("stock"));
  CPPUNIT_ASSERT(!t->query("stop"));
  t->insert("stop");
  CPPUNIT_ASSERT(t->query("bear"));
  CPPUNIT_ASSERT(t->query("bell"));	
  CPPUNIT_ASSERT(t->query("bid"));
  CPPUNIT_ASSERT(t->query("bull"));	
  CPPUNIT_ASSERT(t->query("buy"));
  CPPUNIT_ASSERT(t->query("sell"));
  CPPUNIT_ASSERT(t->query("stock"));
  CPPUNIT_ASSERT(t->query("stop"));
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TrieQueryTest, "Query");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Query");
