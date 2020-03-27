import static java.util.Arrays.asList;
import java.util.List;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class HashTableLoadFactorTest {
    @Test
    public void testLoadFactorOne() {
        HashTable t = new HashTable(29, 35, 256);
        assertEquals("load factor of empty table is not zero", 0.0, t.loadFactor(), 0.0);
        t.insert(1);
        assertEquals("load factor of table with one element is not right", 1.0/256, t.loadFactor(), 0.0);
    }
    @Test
    public void testLoadFactorCollision() {
        HashTable t = new HashTable(29, 35, 256);
        t.insert(1);
        t.insert(257);
        assertEquals("load factor of table with two elements is not right", 2.0/256, t.loadFactor(), 0.0);
    }
    @Test
    public void testLoadFactorSequence() {
        HashTable t = new HashTable(29, 35, 256);
        int z[] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
        for (int i = 0; i < 9; i++) {
            t.insert(z[i]);
            assertEquals("load factor is wrong", ((double)(i+1))/256, t.loadFactor(), 0.0);
        }
    }
}
