#include <cppunit/extensions/HelperMacros.h>

#include "Graph.hpp"

class GraphMSTTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GraphMSTTest);
  CPPUNIT_TEST(testEmptyMST);
  CPPUNIT_TEST(testOneElementMST);
  CPPUNIT_TEST(testNontrivialMST);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testEmptyMST();
  void testOneElementMST();
  void testNontrivialMST();
};

void GraphMSTTest::testEmptyMST() {
  Graph g;
  Graph *h = g.MST();
  CPPUNIT_ASSERT_MESSAGE("the MST of an empty graph should be non-NULL", h);
  unsigned long nv = h->vlist.size();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the MST of an empty graph should be empty", 0UL, nv);
}

void GraphMSTTest::testOneElementMST() {
  Graph g;
  g.addVertex("A");
  g.addEdge("A", "A", 3);
  Graph *h = g.MST();
  CPPUNIT_ASSERT_MESSAGE("the MST of an one-vertex graph should be non-NULL", h);
  Vertex *v = h->getVertex("A");
  CPPUNIT_ASSERT_MESSAGE("the MST of a one-vertex graph should contain a vertex", v);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the MST of a one-vertex graph should have a vertex with the same name", std::string("A"), v->name);
  CPPUNIT_ASSERT_MESSAGE("the vertex in the MST and the original graph should be distinct", v != g.getVertex("A"));
  Edge *e = h->getEdge("A", "A");
  CPPUNIT_ASSERT_MESSAGE("the MST of a one-vertex graph should have no edges", !e);
}

void GraphMSTTest::testNontrivialMST() {
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
  Graph *h = g.MST();
  CPPUNIT_ASSERT_MESSAGE("the MST of a non-trivial graph should be non-NULL", h);
  CPPUNIT_ASSERT_MESSAGE("edge should be present in MST", h->getEdge("F", "H"));
  CPPUNIT_ASSERT_MESSAGE("edge should be present in MST", h->getEdge("J", "I"));
  CPPUNIT_ASSERT_MESSAGE("edge should be present in MST", h->getEdge("H", "I"));
  CPPUNIT_ASSERT_MESSAGE("edge should be present in MST", h->getEdge("K", "H"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("F", "J"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("F", "I"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("K", "I"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("F", "K"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("J", "H"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("J", "K"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("F", "F"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("H", "H"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("I", "I"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("J", "J"));
  CPPUNIT_ASSERT_MESSAGE("edge should not be present in MST", !h->getEdge("K", "K"));
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(GraphMSTTest, "MST");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("MST");
