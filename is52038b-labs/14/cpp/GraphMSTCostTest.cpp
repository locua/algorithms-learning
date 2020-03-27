#include <cppunit/extensions/HelperMacros.h>

#include "Graph.hpp"

class GraphMSTCostTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GraphMSTCostTest);
  CPPUNIT_TEST(testEmptyMSTCost);
  CPPUNIT_TEST(testOneElementMSTCost);
  CPPUNIT_TEST(testNontrivialMSTCost);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testEmptyMSTCost();
  void testOneElementMSTCost();
  void testNontrivialMSTCost();
};

void GraphMSTCostTest::testEmptyMSTCost() {
  Graph g;
  int c = g.MSTCost();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the MST cost of an empty graph should be...", 0, c);
}

void GraphMSTCostTest::testOneElementMSTCost() {
  Graph g;
  g.addVertex("A");
  g.addEdge("A", "A", 3);
  int c = g.MSTCost();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the MST cost of a one-vertex graph should be...", 0, c);
}

void GraphMSTCostTest::testNontrivialMSTCost() {
  Graph g;
  g.addVertex("F");
  g.addVertex("H");
  g.addVertex("I");
  g.addVertex("J");
  g.addVertex("K");
  g.addEdge("F", "H", 1);
  g.addEdge("J", "I", 2);
  g.addEdge("H", "I", 3);
  g.addEdge("J", "J", 4);
  g.addEdge("F", "J", 5);
  g.addEdge("F", "I", 6);
  g.addEdge("H", "H", 7);
  g.addEdge("K", "H", 8);
  g.addEdge("K", "I", 9);
  g.addEdge("F", "K", 10);
  g.addEdge("F", "F", 11);
  g.addEdge("I", "I", 12);
  g.addEdge("J", "H", 13);
  g.addEdge("J", "K", 14);
  g.addEdge("K", "K", 15);
  int c = g.MSTCost();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("MST cost incorrect for non-trivial graph", 14, c);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(GraphMSTCostTest, "MSTCost");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("MSTCost");
