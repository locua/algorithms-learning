import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class LengthSLListTest {
    @Test
    public void testLengthOfNIL() {
        assertEquals("What is the length of NIL?", 0, SLList.NIL.length());
    }
    @Test
    public void testLength() {
        SLList n = new SLList(1, SLList.NIL);
        assertEquals("What is the length of a list whose next is NIL?", 1, n.length());
        SLList nn = new SLList(2, n);
        assertEquals("What is the length of a list whose next is a list with length 1?", 2, nn.length());
    }
    
    public static void main(String[] args) {
        JUnitCore core = new JUnitCore();
        core.run(LengthSLListTest.class);
    }
}
