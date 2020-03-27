import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class HeapIndexFunctionsTest {
    @Test
    public void testLeft() {
        assertEquals("what is the index of the left child of the node at position 0?", 1, Heap.left(0));
        assertEquals("what is the index of the left child of the node at position 1?", 3, Heap.left(1));
        assertEquals("what is the index of the left child of the node at position 2?", 5, Heap.left(2));
        Random r = new Random();
        for (int i = 0; i < 100; i++) {
            int x = r.nextInt(32768);
            assertEquals("a random choice of parent has an erroneous child!", 2*x+1, Heap.left(x));
        }
    }
    @Test
    public void testRight() {
        assertEquals("what is the index of the right child of the node at position 0?", 2, Heap.right(0));
        assertEquals("what is the index of the right child of the node at position 1?", 4, Heap.right(1));
        assertEquals("what is the index of the right child of the node at position 2?", 6, Heap.right(2));
        Random r = new Random();
        for (int i = 0; i < 100; i++) {
            int x = r.nextInt(32768);
            assertEquals("a random choice of parent has an erroneous child!", 2*x+2, Heap.right(x));
        }
    }
    @Test
    public void testParent() {
        assertEquals("what is the index of the parent of the node at position 1?", 0, Heap.parent(1));
        assertEquals("what is the index of the parent of the node at position 2?", 0, Heap.parent(2));
        assertEquals("what is the index of the parent of the node at position 3?", 1, Heap.parent(3));
        Random r = new Random();
        for (int i = 0; i < 100; i++) {
            int x = 1 + r.nextInt(32767);
            assertEquals("a random choice of child has an erroneous parent!", (x-1)/2, Heap.parent(x));
        }
    }
}
