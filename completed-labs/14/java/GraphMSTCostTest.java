import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class GraphMSTCostTest {
    @Test
    public void TestEmptyMSTCost() {
	Graph g = new Graph();
	int c = g.MSTCost();
	assertEquals("the MST cost of an empty graph should be...", 0, c);
    }
    @Test
    public void TestOneElementMSTCost() {
	Graph g = new Graph();
	g.addVertex("A");
	g.addEdge("A", "A", 3);
	int c = g.MSTCost();
	assertEquals("the MST cost of a one-vertex graph should be...", 0, c);
    }
    @Test
    public void TestNontrivialMSTCost() {
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
	int c = g.MSTCost();
	assertEquals("MST cost incorrect for non-trivial graph", 14, c);
    }
}
