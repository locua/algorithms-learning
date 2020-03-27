#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Trie.hpp"

class TrieInsertTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(TrieInsertTest);
  CPPUNIT_TEST(testInsertOne);
  CPPUNIT_TEST(testInsertTwo);
  CPPUNIT_TEST(testInsertCommonPrefix);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() { };
  void tearDown() { };

  void testInsertOne();
  void testInsertTwo();
  void testInsertCommonPrefix();
};

void TrieInsertTest::testInsertOne() {
  Trie *t = new Trie();
  t->insert("one");
  for (int i = 0; i < 27; i++) {
    if ('a' + i != 'o') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['o'-'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if ('a' + i != 'n') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['n'-'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if ('a' + i != 'e') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['e'-'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if ('a' + i != '{') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['{'-'a'];
  CPPUNIT_ASSERT(t);
}

void TrieInsertTest::testInsertTwo() {
  Trie *u = new Trie();
  Trie *t = u;
  t->insert("one");
  t->insert("two");
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'o' && ('a' + i) != 't') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['o' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'n') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['n' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'e') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['e' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != '{') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['{' - 'a'];
  CPPUNIT_ASSERT(t);
  t = u;
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 't' && ('a' + i) != 'o') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['t' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'w') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['w' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'o') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['o' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != '{') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['{' - 'a'];
  CPPUNIT_ASSERT(t);
}

void TrieInsertTest::testInsertCommonPrefix() {
  Trie *t = new Trie();
  t->insert("one");
  t->insert("only");
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'o') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['o' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'n') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['n' - 'a'];
  CPPUNIT_ASSERT(t);
  Trie *u = t;
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'e' && ('a' + i) != 'l') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['e' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != '{') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['{' - 'a'];
  CPPUNIT_ASSERT(t);
  t = u->children['l' - 'a'];
  CPPUNIT_ASSERT(t);
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != 'y') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['y' - 'a'];
  for (int i = 0; i < 27; i++) {
    if (('a' + i) != '{') CPPUNIT_ASSERT(!t->children[i]);
  }
  t = t->children['{' - 'a'];
  CPPUNIT_ASSERT(t);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TrieInsertTest, "Insert");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Insert");
