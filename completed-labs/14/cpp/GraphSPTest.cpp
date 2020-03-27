#include <cppunit/extensions/HelperMacros.h>

#include "Graph.hpp"

class GraphSPTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GraphSPTest);
  // CPPUNIT_TEST(testEmptySP);
  // CPPUNIT_TEST(testOneElementSP);
  CPPUNIT_TEST(testNontrivialSP);
  CPPUNIT_TEST(testNontrivialSPCost);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testEmptySP();
  void testOneElementSP();
  void testNontrivialSP();
  void testNontrivialSPCost();
};


void GraphSPTest::testNontrivialSP() { 
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addEdge("A", "B", 1);
    g.addEdge("A", "D", 3);
    g.addEdge("A", "E", 7);
    g.addEdge("B", "A", 1);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "C", 5);
    g.addEdge("C", "B", 3);
    g.addEdge("C", "D", 3);
    g.addEdge("D", "A", 2);
    g.addEdge("D", "B", 1);
    g.addEdge("D", "C", 3);
    g.addEdge("D", "E", 4);
    g.addEdge("E", "A", 7);

    Graph *h = g.SP("A", "E");
    CPPUNIT_ASSERT_MESSAGE("the SP of a non-trivial graph should be non-NULL", h);
    CPPUNIT_ASSERT_MESSAGE("edge should be present in SP", h->getEdge("A", "B"));
    CPPUNIT_ASSERT_MESSAGE("edge should be present in SP", h->getEdge("B", "D"));
    CPPUNIT_ASSERT_MESSAGE("edge should be present in SP", h->getEdge("D", "E"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("A", "D"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("A", "E"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("B", "A"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("B", "C"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("C", "D"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("C", "B"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("D", "A"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("D", "B"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("D", "C"));
    // CPPUNIT_ASSERT_MESSAGE("edge should not be present in SP", !h->getEdge("E", "A"));
}

void GraphSPTest::testNontrivialSPCost() { 
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addEdge("A", "B", 1);
    g.addEdge("A", "D", 3);
    g.addEdge("A", "E", 7);
    g.addEdge("B", "A", 1);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "C", 5);
    g.addEdge("C", "B", 3);
    g.addEdge("C", "D", 3);
    g.addEdge("D", "A", 2);
    g.addEdge("D", "B", 1);
    g.addEdge("D", "C", 3);
    g.addEdge("D", "E", 4);
    g.addEdge("E", "A", 7);
    
    int c = g.SPCost("A", "E");
    CPPUNIT_ASSERT_EQUAL_MESSAGE("incorrect cost", 6, c);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(GraphSPTest, "SP");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("SP");
