import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class GraphEdgeTest {
    @Test
    public void TestNoEdges() {
	Graph g = new Graph();
	g.addVertex("A");
	g.addVertex("B");
	for (int i = 0; i < g.vlist.size(); i++) {
	    Vertex v = g.vlist.get(i);
	    assertEquals("edge list for fresh vertex is not empty", 0, v.adjlist.size());
	}
    }
    @Test
    public void TestNoFoundEdges() {
	Graph g = new Graph();
	g.addVertex("A");
	g.addVertex("B");
	Edge e = g.getEdge("A", "B");
	assertEquals("graph with two fresh vertices has an edge between them", null, e);
    }
    @Test
    public void TestNonexistentVertex() {
	Graph g = new Graph();
	g.addVertex("A");
	g.addVertex("B");
	g.addEdge("A", "B", 3);
	Edge e = g.getEdge("A", "C");
	assertEquals("returned an edge to a non-existent vertex", null, e);
    }
    @Test
    public void TestEdges() {
	Graph g = new Graph();
	g.addVertex("A");
	g.addVertex("B");
	g.addEdge("A", "B", 3);
	Edge e = g.getEdge("A", "B");
	assertNotEquals("edge not found when it should be", null, e);
	assertEquals("AB edge weight wrong", 3, e.weight);
	e = g.getEdge("B", "A");
	assertNotEquals("edge not found when it should be (undirected graph)", null, e);
	assertEquals("BA edge weight wrong", 3, e.weight);
    }
}
