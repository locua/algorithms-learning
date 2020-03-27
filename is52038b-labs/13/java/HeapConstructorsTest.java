import static java.util.Arrays.asList;
import java.util.List;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class HeapConstructorsTest {
    @Test
    public void testMinimalConstructors() {
        Heap h = new Heap(0);
        assertEquals("heap size violation for 0-length heap", 0, h.heap_size);
        assertEquals("array length violation for 0-length heap", 0, h.array.size());
        List<Integer> v = asList();
        h = new Heap(v);
        assertEquals("heap size violation for 0-length heap", 0, h.heap_size);
        assertEquals("array length violation for 0-length heap", 0, h.array.size());
        h = new Heap(v, false);
        assertEquals("heap size violation for 0-length heap", 0, h.heap_size);
        assertEquals("array length violation for 0-length heap", 0, h.array.size());
        h = new Heap(v, true);
        assertEquals("heap size violation for 0-length heap", 0, h.heap_size);
        assertEquals("array length violation for 0-length heap", 0, h.array.size());
    }
    @Test
    public void testIncrementalConstructor() {
        List<Integer> v = asList(17);
        Heap h = new Heap(v, true);
        assertEquals("The heap size of a new one-element heap should be 1", 1, h.heap_size);
        assertEquals("The first element of the one-element heap's array should be the value in the initializer list", Integer.valueOf(17), h.array.get(0));
        List<Integer> w = asList(18,14);
        h = new Heap(w, true);
        assertEquals("The heap size of a new two-element heap should be 2", 2, h.heap_size);
        assertEquals("The first element of the one-element heap's array should be the larger value in the initializer vector", Integer.valueOf(18), h.array.get(0));
        assertEquals("The first element of the one-element heap's array should be the smaller value in the initializer vector", Integer.valueOf(14), h.array.get(1));
        List<Integer> x = asList(18,14);
        h = new Heap(x, true);
        assertEquals("The heap size of a new two-element heap should be 2", 2, h.heap_size);
        assertEquals("The first element of the one-element heap's array should be the larger value in the initializer vector", Integer.valueOf(18), h.array.get(0));
        assertEquals("The first element of the one-element heap's array should be the smaller value in the initializer vector", Integer.valueOf(14), h.array.get(1));
        List<Integer> z = asList(10, 8, 14, 15, 12, 5, 6, 1);
        h = new Heap(z, true);
        assertEquals("The heap from figure 4.16 of Ida's subject guide should have length 8", 8, h.heap_size);
        assertEquals("The first element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(15), h.array.get(0));
        assertEquals("The second element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(14), h.array.get(1));
        assertEquals("The third element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(10), h.array.get(2));
        assertEquals("The fourth element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(8), h.array.get(3));
        assertEquals("The fifth element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(12), h.array.get(4));
        assertEquals("The sixth element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(5), h.array.get(5));
        assertEquals("The seventh element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(6), h.array.get(6));
        assertEquals("The eighth element of the heap in figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(1), h.array.get(7));
    }
    @Test
    public void testDirectConstructor() {
        List<Integer> v = asList(17);
        Heap h = new Heap(v, false);
        assertEquals("The heap size of a new one-element heap should be 1", 1, h.heap_size);
        assertEquals("The first element of the one-element heap's array should be the value in the initializer list", Integer.valueOf(17), h.array.get(0));
        List<Integer> w = asList(18,14);
        h = new Heap(w, false);
        assertEquals("The heap size of a new two-element heap should be 2", 2, h.heap_size);
        assertEquals("The first element of the one-element heap's array should be the larger value in the initializer vector", Integer.valueOf(18), h.array.get(0));
        assertEquals("The first element of the one-element heap's array should be the smaller value in the initializer vector", Integer.valueOf(14), h.array.get(1));
        List<Integer> x = asList(18,14);
        h = new Heap(x, false);
        assertEquals("The heap size of a new two-element heap should be 2", 2, h.heap_size);
        assertEquals("The first element of the one-element heap's array should be the larger value in the initializer vector", Integer.valueOf(18), h.array.get(0));
        assertEquals("The first element of the one-element heap's array should be the smaller value in the initializer vector", Integer.valueOf(14), h.array.get(1));
        List<Integer> z = asList(10, 8, 14, 15, 12, 5, 6, 1);
        h = new Heap(z, false);
        assertEquals("The heap directly constructed from figure 4.16 of Ida's subject guide should have length 8", 8, h.heap_size);
        assertEquals("The first element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(15), h.array.get(0));
        assertEquals("The second element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(12), h.array.get(1));
        assertEquals("The third element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(14), h.array.get(2));
        assertEquals("The fourth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(8), h.array.get(3));
        assertEquals("The fifth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(10), h.array.get(4));
        assertEquals("The sixth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(5), h.array.get(5));
        assertEquals("The seventh element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(6), h.array.get(6));
        assertEquals("The eighth element of the heap directly constructed from the contents of figure 4.16 of Ida's subject guide is wrong", Integer.valueOf(1), h.array.get(7));
    }
}
