#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Trie.hpp"
#include "CompressedTrie.hpp"

class CompressTrieTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(CompressTrieTest);
  CPPUNIT_TEST(testCompressOne);
  CPPUNIT_TEST(testCompressTwo);
  CPPUNIT_TEST(testCompressCommonPrefix);
  CPPUNIT_TEST(testCompressStock);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testCompressOne();
  void testCompressTwo();
  void testCompressCommonPrefix();
  void testCompressStock();
};

void CompressTrieTest::testCompressOne() {
  Trie *t = new Trie();
  t->insert("one");
  CompressedTrie *c = CompressedTrie::compressTrie(t);
  CPPUNIT_ASSERT_MESSAGE("compressTrie should return a non-NULL trie", c);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be one entry in the compressed trie", (size_t) 1, c->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The entry should be 'one{'", (size_t) 1, c->children.count("one{"));
}

void CompressTrieTest::testCompressTwo() {
  Trie *u = new Trie();
  Trie *t = u;
  t->insert("one");
  t->insert("two");
  CompressedTrie *c = CompressedTrie::compressTrie(t);
  CPPUNIT_ASSERT_MESSAGE("compressTrie should return a non-NULL trie", c);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be two entries in the compressed trie", (size_t) 2, c->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'one{'", (size_t) 1, c->children.count("one{"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'two{'", (size_t) 1, c->children.count("two{"));
  
}

void CompressTrieTest::testCompressCommonPrefix() {
  Trie *t = new Trie();
  t->insert("one");
  t->insert("only");
  CompressedTrie *c = CompressedTrie::compressTrie(t);
  CPPUNIT_ASSERT_MESSAGE("compressTrie should return a non-NULL trie", c);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be one entry in the compressed trie", (size_t) 1, c->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The entry should be 'on'", (size_t) 1, c->children.count("on"));
  c = c->children["on"];
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be two entries in the compressed trie", (size_t) 2, c->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'e{'", (size_t) 1, c->children.count("e{"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'ly{'", (size_t) 1, c->children.count("ly{"));
}

void CompressTrieTest::testCompressStock() {
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
  CPPUNIT_ASSERT_MESSAGE("compressTrie should return a non-NULL trie", c);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be two entries in the compressed trie", (size_t) 2, c->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'b'", (size_t) 1, c->children.count("b"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 's'", (size_t) 1, c->children.count("s"));
  CompressedTrie *b = c->children["b"];
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be three entries in the compressed trie for b", (size_t) 3, b->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'e'", (size_t) 1, b->children.count("e"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'id{'", (size_t) 1, b->children.count("id{"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'u'", (size_t) 1, b->children.count("u"));
  CompressedTrie *be = b->children["e"];
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be two entries in the compressed trie", (size_t) 2, be->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'ar{'", (size_t) 1, be->children.count("ar{"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'll{'", (size_t) 1, be->children.count("ll{"));
  CompressedTrie *bu = b->children["u"];
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be two entries in the compressed trie", (size_t) 2, bu->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'y{'", (size_t) 1, bu->children.count("y{"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'll{'", (size_t) 1, bu->children.count("ll{"));
  CompressedTrie *s = c->children["s"];
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be two entries in the compressed trie", (size_t) 2, s->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'ell{'", (size_t) 1, s->children.count("ell{"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'to'", (size_t) 1, s->children.count("to"));
  CompressedTrie *sto = s->children["to"];
  CPPUNIT_ASSERT_EQUAL_MESSAGE("There should be two entries in the compressed trie", (size_t) 2, sto->children.size());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'ck{'", (size_t) 1, sto->children.count("ck{"));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("One entry should be 'p{'", (size_t) 1, sto->children.count("p{"));

}
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CompressTrieTest, "Compress");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Compress");
