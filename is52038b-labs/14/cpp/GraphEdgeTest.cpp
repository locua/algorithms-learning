#include <cppunit/extensions/HelperMacros.h>

#include "Graph.hpp"

class GraphEdgeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GraphEdgeTest);
  CPPUNIT_TEST(testNoEdges);
  CPPUNIT_TEST(testNoFoundEdges);
  CPPUNIT_TEST(testNonexistentVertex);
  CPPUNIT_TEST(testEdges);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testNoEdges();
  void testNoFoundEdges();
  void testNonexistentVertex();
  void testEdges();
};

void GraphEdgeTest::testNoEdges() {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  for(int i = 0; i < g.vlist.size(); i++) {
    Vertex *v = g.vlist[i];
    CPPUNIT_ASSERT_EQUAL_MESSAGE("edge list for fresh vertex is not empty", 0UL, (unsigned long) v->adjlist.size());
  }
}

void GraphEdgeTest::testNoFoundEdges() {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  Edge *e = g.getEdge("A", "B");
  CPPUNIT_ASSERT_MESSAGE("graph with two fresh vertices has an edge between them", !e);
}

void GraphEdgeTest::testNonexistentVertex() {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addEdge("A", "B", 3);
  Edge *e = g.getEdge("A", "C");
  CPPUNIT_ASSERT_MESSAGE("returned an edge to a non-existent vertex", !e);
}

void GraphEdgeTest::testEdges() {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addEdge("A", "B", 3);
  Edge *e = g.getEdge("A", "B");
  CPPUNIT_ASSERT_MESSAGE("edge not found when it should be", e);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("AB edge weight wrong", 3, e->weight);
  e = g.getEdge("B", "A");
  CPPUNIT_ASSERT_MESSAGE("edge not found when it should be (undirected graph)", e);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("BA edge weight wrong", 3, e->weight);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(GraphEdgeTest, "Edge");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Edge");
