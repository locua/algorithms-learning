import static java.util.Arrays.asList;
import java.util.List;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class LCG2935256Test {
    @Test
    public void testSequence() {
        LCG g = new LCG(29, 35, 256, 1);
        {
            long z[] = {64, 99, 90, 85, 196, 87, 254, 233, 136, 139};
            for (int i = 0; i < 10; i++) {
                assertEquals("unexpected next", z[i], g.next());
            }
        }
        g = new LCG(29, 35, 256, 2);
        {
            long z[] = {93, 172, 159, 38, 113, 240, 83, 138, 197, 116};
            for (int i = 0; i < 10; i++) {
                assertEquals("unexpected next", z[i], g.next());
            }
        }
        g = new LCG(29, 35, 256, 3);
        {
            long z[] = {122, 245, 228, 247, 30, 137, 168, 43, 2, 93};
            for (int i = 0; i < 10; i++) {
                assertEquals("unexpected next", z[i], g.next());
            }
        }
    }
    @Test
    public void testNext() {
        LCG g = new LCG(29, 35, 256, 0);
        long z = 0;
        for (int i = 0; i < 256; i++) {
            z = (29*z + 35) % 256;
            long x = g.next();
            assertEquals("unexpected next", z, x);
        }
    };
    @Test
    public void testSeed() {
        LCG g = new LCG(29, 35, 256, 11);
        g.seed(1);
        assertEquals("seed appears not to have seeded", 64, g.next());
    };
}
