import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class GraphMSTTest {
    @Test
    public void TestEmptyMST() {
	Graph g = new Graph();
	Graph h = g.MST();
	int nv = h.vlist.size();
	assertEquals("the MST of an empty graph should be empty", 0, nv);
    }
    @Test
    public void TestOneElementMST() {
	Graph g = new Graph();
	g.addVertex("A");
	g.addEdge("A", "A", 3);
	Graph h = g.MST();
	Vertex v = h.getVertex("A");
	assertNotEquals("the MST of a one-vertex graph should contain a vertex", null, v);
	assertEquals("the MST of a one-vertex graph should have a vertex with the same name", "A", v.name);
	assertNotEquals("the vertex in the MST and the original graph should be distinct", v, g.getVertex("A"));
	Edge e = h.getEdge("A", "A");
	assertEquals("the MST of a one-vertex graph should have no edges", null, e);
    }
    @Test
    public void TestNontrivialMST() {
	Graph g = new Graph();
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
	Graph h = g.MST();
	assertNotEquals("edge should be present in MST", null, h.getEdge("F", "H"));
	assertNotEquals("edge should be present in MST", null, h.getEdge("J", "I"));
	assertNotEquals("edge should be present in MST", null, h.getEdge("H", "I"));
	assertNotEquals("edge should be present in MST", null, h.getEdge("K", "H"));
	assertEquals("edge should not be present in MST", null, h.getEdge("F", "J"));
	assertEquals("edge should not be present in MST", null, h.getEdge("F", "I"));
	assertEquals("edge should not be present in MST", null, h.getEdge("K", "I"));
	assertEquals("edge should not be present in MST", null, h.getEdge("F", "K"));
	assertEquals("edge should not be present in MST", null, h.getEdge("J", "H"));
	assertEquals("edge should not be present in MST", null, h.getEdge("J", "K"));
	assertEquals("edge should not be present in MST", null, h.getEdge("F", "F"));
	assertEquals("edge should not be present in MST", null, h.getEdge("H", "H"));
	assertEquals("edge should not be present in MST", null, h.getEdge("I", "I"));
	assertEquals("edge should not be present in MST", null, h.getEdge("J", "J"));
	assertEquals("edge should not be present in MST", null, h.getEdge("K", "K"));
    }
}
