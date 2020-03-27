import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;

public class BigIntMulByDigitTest {
    @Test
    public void testMulByDigit() {
        BigInt b1 = new BigInt(1);
        b1.data[0] = 7;
        BigInt b2 = b1.MulByDigit((char) 8);
        assertEquals("7*8 % 10 != 6", 6, b2.get(0));
        assertEquals("7*8/10 % 10 != 5", 5, b2.get(1));
    }
    @Test
    public void testRandomMulByDigit() {
        BigInt ba = new BigInt(6);
        Random r = new Random();
        long a = r.nextInt(1000000);
        long atmp = a;
        for (int i = 0; i < 6; i++) {
            ba.data[i] = (char) (atmp % 10);
            atmp = atmp / 10;
        }
        BigInt bm = ba.MulByDigit((char) 9);
        long m = a * 9;
        long mtmp = m;
        for (int i = 0; i < 7; i++) {
            assertEquals("mismatch in random multiplication by digit", (mtmp % 10), bm.get(i));
            mtmp = mtmp / 10;
        }
    }
}
