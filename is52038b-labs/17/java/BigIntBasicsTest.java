import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;

public class BigIntBasicsTest {
    @Test
    public void testGet() {
        BigInt b = new BigInt(1);
	assertEquals("ndigits is not right after basic constructor", 1, b.ndigits);
        b.data[0] = 9;
        assertEquals(".get() not returning known data", 9, b.get(0));
        assertEquals(".get() not returning zero for out-of-bounds", 0, b.get(1));
    }
    @Test
    public void testRandomGet() {
        BigInt b = new BigInt(10);
        char[] d = new char[10];
        Random r = new Random();
	assertEquals("ndigits is not right after basic constructor", 10, b.ndigits);
        for (int i = 0; i < 10; i++) {
            d[i] = (char) r.nextInt(10);
            b.data[i] = d[i];
        }
        for (int i = 0; i < 10; i++) {
            assertEquals(".get() not returning random data", d[i], b.get(i));
        }
    }
    @Test
    public void testStringConstructor() {
	BigInt b = new BigInt("6283");
	char[] d = new char[] {3, 8, 2, 6};
	assertEquals("ndigits wrong after string constructor", 4, b.ndigits);
	for (int i = 0; i < b.ndigits; i++) {
	    assertEquals("string constructor has introduced wrong data", d[i], b.get(i));
	}
    }
}
