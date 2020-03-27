import static java.util.Arrays.asList;
import java.util.List;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertTrue;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class HashTableFindTest {
    @Test
    public void testFindOne() {
        HashTable t = new HashTable(29, 35, 256);
        t.insert(1);
        assertTrue("key 1 not found", t.find(1));
    }
    @Test
    public void testFindCollision() {
        HashTable t = new HashTable(29, 35, 256);
        t.insert(1);
        t.insert(257);
        assertTrue("key 1 not found", t.find(1));
        assertTrue("key 257 not found", t.find(257));
        assertTrue("key 513 found", !t.find(513));
    }
    @Test
    public void testFindSequence() {
        HashTable t = new HashTable(29, 35, 256);
        int z[] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
        for (int i = 0; i < 9; i++) {
            t.insert(z[i]);
            assertTrue("key " + z[i] + " not found", t.find(z[i]));
        }
    }
}
