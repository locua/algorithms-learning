import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class GraphVertexTest {
    @Test
    public void TestNoVertices() {
	Graph g = new Graph();
	assertEquals("fresh graph has vertices (or null vlist)", 0, g.vlist.size());
    }
    @Test
    public void TestNoFoundVertices() {
	Graph g = new Graph();
	assertEquals("fresh graph has non-null getVertex(A)", null, g.getVertex("A"));
    }
    @Test
    public void TestVertices() {
	Graph g = new Graph();
	g.addVertex("A");
	g.addVertex("B");
	Vertex v = g.getVertex("A");
	assertNotEquals("getVertex(A) fails to find vertex", null, v);
	assertEquals("getVertex(A) finds vertex with the wrong name", "A", v.name);
	v = g.getVertex("B");
	assertNotEquals("getVertex(B) fails to find vertex", null, v);
	assertEquals("getVertex(B) finds vertex with the wrong name", "B", v.name);
    }
}
