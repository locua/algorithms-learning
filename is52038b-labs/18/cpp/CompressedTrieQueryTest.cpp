#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Trie.hpp"
#include "CompressedTrie.hpp"

class CompressedTrieQueryTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(CompressedTrieQueryTest);
  CPPUNIT_TEST(testCompressedQueryOne);
  CPPUNIT_TEST(testCompressedQueryTwo);
  CPPUNIT_TEST(testCompressedQueryCommonPrefix);
  CPPUNIT_TEST(testCompressedQueryStock);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testCompressedQueryOne();
  void testCompressedQueryTwo();
  void testCompressedQueryCommonPrefix();
  void testCompressedQueryStock();
};

void CompressedTrieQueryTest::testCompressedQueryOne() {
  Trie *t = new Trie();
  t->insert("one");
  CompressedTrie *c = CompressedTrie::compressTrie(t);
  CPPUNIT_ASSERT(c->query("one"));
  CPPUNIT_ASSERT(!c->query("two"));
  CPPUNIT_ASSERT(!c->query("on"));
  CPPUNIT_ASSERT(!c->query("ones"));
}

void CompressedTrieQueryTest::testCompressedQueryTwo() {
  Trie *u = new Trie();
  Trie *t = u;
  t->insert("one");
  t->insert("two");
  CompressedTrie *c = CompressedTrie::compressTrie(t);
  CPPUNIT_ASSERT(c->query("one"));
  CPPUNIT_ASSERT(c->query("two"));
  CPPUNIT_ASSERT(!c->query("on"));
  CPPUNIT_ASSERT(!c->query("ones"));
}

void CompressedTrieQueryTest::testCompressedQueryCommonPrefix() {
  Trie *t = new Trie();
  t->insert("one");
  t->insert("only");
  CompressedTrie *c = CompressedTrie::compressTrie(t);
  CPPUNIT_ASSERT(c->query("one"));
  CPPUNIT_ASSERT(!c->query("two"));
  CPPUNIT_ASSERT(!c->query("on"));
  CPPUNIT_ASSERT(c->query("only"));
  CPPUNIT_ASSERT(!c->query("ones"));
}

void CompressedTrieQueryTest::testCompressedQueryStock() {
  Trie *t = new Trie();
  t->insert("bear");
  t->insert("bell");
  t->insert("bid");
  t->insert("bull");
  t->insert("buy");
  t->insert("sell");
  t->insert("stock");
  t->insert("stop");
  CompressedTrie *c = CompressedTrie::compressTrie(t);
  CPPUNIT_ASSERT(c->query("bear"));
  CPPUNIT_ASSERT(c->query("bell"));
  CPPUNIT_ASSERT(c->query("bid"));
  CPPUNIT_ASSERT(c->query("bull"));
  CPPUNIT_ASSERT(c->query("buy"));
  CPPUNIT_ASSERT(c->query("sell"));
  CPPUNIT_ASSERT(c->query("stock"));
  CPPUNIT_ASSERT(c->query("stop"));
  CPPUNIT_ASSERT(!c->query("be"));
  CPPUNIT_ASSERT(!c->query("bells"));
  CPPUNIT_ASSERT(!c->query("bide"));
  CPPUNIT_ASSERT(!c->query("hull"));
  CPPUNIT_ASSERT(!c->query("bay"));
  CPPUNIT_ASSERT(!c->query("sill"));
  CPPUNIT_ASSERT(!c->query("stack"));
  CPPUNIT_ASSERT(!c->query("stops"));
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CompressedTrieQueryTest, "CompressedQuery");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("CompressedQuery");
