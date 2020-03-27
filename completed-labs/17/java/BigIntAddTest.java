import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;

public class BigIntAddTest {
    @Test
    public void testAdd() {
        BigInt b1 = new BigInt(1);
        b1.data[0] = 1;
        BigInt b2 = b1.Add(b1);
        assertEquals("1+1 != 2?", 2, b2.get(0));
        assertEquals("1+1 > 10?", 0, b2.get(1));
    }
    @Test
    public void testAddWithCarry() {
        BigInt b9 = new BigInt(1);
        b9.data[0] = 9;
        BigInt b18 = b9.Add(b9);
        assertEquals("9+9 % 10 != 8?", 8, b18.get(0));
        assertEquals("9+9/10 % 10 != 1?", 1, b18.get(1));
        assertEquals("9+9/100 % 10 != 0?", 0, b18.get(2));
    }
    @Test
    public void testRandomAdd() {
        BigInt ba = new BigInt(6);
        BigInt bb = new BigInt(6);
        Random r = new Random();
        long a = r.nextInt(1000000);
        long b = r.nextInt(1000000);
        long atmp = a;
        long btmp = b;
        for (int i = 0; i < 6; i++) {
            ba.data[i] = (char) (atmp % 10);
            atmp = atmp / 10;
            bb.data[i] = (char) (btmp % 10);
            btmp = btmp / 10;
        }
        BigInt bc = ba.Add(bb);
        long c = a + b;
        long ctmp = c;
        for (int i = 0; i < 7; i++) {
            assertEquals("mismatch in random addition", ctmp % 10, bc.get(i));
            ctmp = ctmp / 10;
        }
    }
}
