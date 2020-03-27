import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;

public class BigIntShiftTest {
    @Test
    public void testShift() {
        BigInt b1 = new BigInt(1);
        b1.data[0] = 5;
        BigInt b2 = b1.Shift(3);
        for(int i = 0; i < 3; i++) {
            assertEquals("low digits not zero after shift", 0, b2.get(i));
        }
        assertEquals("shifted data not right after shift", 5, b2.get(3));
    }
}
