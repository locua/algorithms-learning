import static java.util.Arrays.asList;
import java.util.List;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class HeapMaximumTest {
    // FIXME: shared with HeapInsertTest
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
    public void testMaximum() {
        Heap h = new Heap(0);
        h.insert(1);
        assertEquals("The object inserted into a zero heap should be the maximum", Integer.valueOf(1), h.maximum());
        List<Integer> v = asList(1, 49, 3, 578, 2, -1000);
        h = new Heap(v);
        assertEquals("The largest element in the initialization vector should be the maximum", Integer.valueOf(578), h.maximum());
    }
    @Test
    public void testExtractMax() {
        List<Integer> v = asList(17);
        Heap h = new Heap(v);
        assertEquals("The maximum extracted should be the single value", Integer.valueOf(17), h.extractMax());
        assertEquals("After removing the maximum from the heap, the heap should be empty", 0, h.heap_size);
        List<Integer> w = asList(15,14,10,8,12,5,6,1); // heap-ordered already
        h = new Heap(w);
        assertTrue("The heap formed from w is not a heap", check_heap(h));
        assertEquals("The maximum extracted is wrong", Integer.valueOf(15), h.extractMax());
        assertTrue("After extracting, the heap property is violated", check_heap(h));
        assertEquals("After extracting, the current maximum is wrong", Integer.valueOf(14), h.maximum());
    }
}
