import static java.util.Arrays.asList;
import java.util.List;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class HeapInsertTest {
    boolean check_heap(Heap h) {
        for (int i = 0; i < h.heap_size; i++) {
            int l = Heap.left(i);
            if (l < h.heap_size && h.array.get(l) > h.array.get(i))
                return false;
            int r = Heap.right(i);
            if (r < h.heap_size && h.array.get(r) > h.array.get(i))
                return false;
        }
        return true;
    }
    @Test
    public void testInsertIntoZeroHeap() {
        Heap h = new Heap(0);
        h.insert(1);
        assertEquals("The object inserted into a zero heap should be at the root", Integer.valueOf(1), h.array.get(0));
    }
    @Test
    public void testInsertIntoHeap() {
        List<Integer> v = asList(1, -3, 17, 4, 2);
        Heap h = new Heap(v);
        assertTrue("The heap constructed violates the heap property", check_heap(h));
        assertEquals("The root of the heap should be the maximum element", Integer.valueOf(17), h.array.get(0));
        h.insert(-5);
        assertTrue("After inserting -5, the heap is no longer a heap", check_heap(h));
        assertEquals("Inserting something smaller than all elements should put the new element at the end", Integer.valueOf(-5), h.array.get(5));
        h.insert(200);
        assertTrue("After inserting 200, the heap is no longer a heap", check_heap(h));
        assertEquals("Inserting something larger than all elements should make it bubble up to the root", Integer.valueOf(200), h.array.get(0));
    }
}
