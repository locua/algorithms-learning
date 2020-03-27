#include <cppunit/extensions/HelperMacros.h>

#include "Graph.hpp"

class GraphVertexTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GraphVertexTest);
  CPPUNIT_TEST(testNoVertices);
  CPPUNIT_TEST(testNoFoundVertices);
  CPPUNIT_TEST(testVertices);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testNoVertices();
  void testNoFoundVertices();
  void testVertices();
};

void GraphVertexTest::testNoVertices() {
  Graph g;
  CPPUNIT_ASSERT_EQUAL_MESSAGE("fresh graph has vertices (or NULL vlist)", 0UL, (unsigned long) g.vlist.size());
}

void GraphVertexTest::testNoFoundVertices() {
  Graph g;
  CPPUNIT_ASSERT_MESSAGE("fresh graph has non-null getVertex(A)", !g.getVertex("A"));
}

void GraphVertexTest::testVertices() {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  Vertex *v = g.getVertex("A");
  CPPUNIT_ASSERT_MESSAGE("getVertex(A) fails to find vertex", v);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("getVertex(A) finds vertex with the wrong name", std::string("A"), v->name);
  v = g.getVertex("B");
  CPPUNIT_ASSERT_MESSAGE("getVertex(B) fails to find vertex", v);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("getVertex(B) finds vertex with the wrong name", std::string("B"), v->name);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(GraphVertexTest, "Vertex");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Vertex");
