import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;

public class BigIntSubTest {
    @Test
    public void testSub() {
        BigInt b1 = new BigInt(1);
        b1.data[0] = 5;
        BigInt b2 = new BigInt(1);
        b2.data[0] = 3;
        BigInt b3 = b1.Sub(b2);
        assertEquals("5-3 != 2?", 2, b3.get(0));
        assertEquals("5-3 > 10?", 0, b3.get(1));
    }
    @Test
    public void testSubWithBorrow() {
        BigInt b11 = new BigInt(2);
        b11.data[0] = 1;
        b11.data[1] = 1;
        BigInt b3 = new BigInt(1);
        b3.data[0] = 3;
        BigInt b18 = b11.Sub(b3);
        assertEquals("11-3 % 10 != 8?", 8, b18.get(0));
        assertEquals("11-3/10 % 10 != 0?", 0, b18.get(1));
        assertEquals("11-3/100 % 10 != 0?", 0, b18.get(2));
    }
    @Test
    public void testRandomSub() {
        BigInt ba = new BigInt(6);
        BigInt bb = new BigInt(6);
        Random r = new Random();
        long a = r.nextInt(1000000);
        long b = r.nextInt((int) a);
        long atmp = a;
        long btmp = b;
        for (int i = 0; i < 6; i++) {
            ba.data[i] = (char) (atmp % 10);
            atmp = atmp / 10;
            bb.data[i] = (char) (btmp % 10);
            btmp = btmp / 10;
        }
        BigInt bc = ba.Sub(bb);
        long c = a - b;
        long ctmp = c;
        for (int i = 0; i < 6; i++) {
            assertEquals("mismatch in random subtraction", ctmp % 10, bc.get(i));
            ctmp = ctmp / 10;
        }
    }
}
