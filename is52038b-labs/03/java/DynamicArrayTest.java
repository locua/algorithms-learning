import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.Before;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class DynamicArrayTest {
    @Test
    public void testConstructor() {
        DynamicArray a = new DynamicArray(10);
        assertEquals("A fresh dynamic array should have zero length", 0, a.length());
    }
    @Test
    public void testSmall() {
        DynamicArray a = new DynamicArray(10);
        a.push(1);
        assertEquals(1, a.length());
        assertEquals(1, a.select(0));
        a.push(3);
        assertEquals(2, a.length());
        assertEquals(1, a.select(0));
        assertEquals(3, a.select(1));
        a.store(2, 0);
        assertEquals(2, a.length());
        assertEquals(2, a.select(0));
        assertEquals(3, a.select(1));
    }
    @Test
    public void testLargePush() {
        DynamicArray a = new DynamicArray(10);
        for (int i = 0; i < 100; i++) {
            a.push(i);
        }
        assertEquals(100, a.length());
        assertEquals(99, a.select(99));
        assertEquals(3, a.select(3));
    }
    @Test
    public void testLargePop() {
        DynamicArray a = new DynamicArray(10);
        for (int i = 1; i <= 100; i++) {
            a.push(i);
        }
        for (int i = 100; i >= 1; i--) {
            assertEquals(i, a.length());
            assertEquals(i, a.pop());
            assertEquals("pop should reduce the length of a dynamic array by 1", i-1, a.length());
        }
    }
    public static void main(String args[]) {
        JUnitCore core = new JUnitCore();
        core.run(DynamicArrayTest.class);
    }
    
}
