import static java.util.Arrays.asList;
import java.util.List;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class HashTableInsertTest {
    @Test
    public void testInsertOne() {
        HashTable t = new HashTable(29, 35, 256);
        t.insert(1);
        assertEquals("key 1 not found in bucket 64", 1, t.buckets[64]);
    }
    @Test
    public void testInsertCollision() {
        HashTable t = new HashTable(29, 35, 256);
        t.insert(1);
        t.insert(257);
        assertEquals("key 1 not found in bucket 64", 1, t.buckets[64]);
        assertEquals("key 257 not found in bucket 65", 257, t.buckets[65]);
    }
    @Test
    public void testInsertSequence() {
        HashTable t = new HashTable(29, 35, 256);
        int z[] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
        for (int i = 0; i < 9; i++) {
            t.insert(z[i]);
            assertEquals("key not found in right table bucket", z[i], t.buckets[z[i+1]]);
        }
    }
}
