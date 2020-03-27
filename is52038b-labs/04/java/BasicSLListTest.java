import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class BasicSLListTest {
    @Test
    public void testConstructor() {
        SLList n = new SLList(0, SLList.NIL);
        assertNotEquals("The SLList constructor must never return null", null, n);
        assertEquals("The SLList constructor must treat its first argument as the item (or first() isn't working yet)", 0, n.first());
        assertEquals("The SLList constructor must treat its second argument as the next node (or rest() isn't working yet)", SLList.NIL, n.rest());
        SLList nn = new SLList(104, n);
        assertNotEquals("The SLList constructor must never return null", null, nn);
        assertEquals("The SLList constructor must treat its first argument as the item (or first() isn't working yet); something might be defaulting to 0", 104, nn.first());
        assertEquals("The SLList constructor must treat its second argument as the next node (or rest() isn't working yet); something might be defaulting to SLList.NIL", n, nn.rest());
    }
    @Test
    public void testFirst() {
        Random r = new Random();
        for (int k = 0; k < 100; k++) {
            int i = r.nextInt(Integer.MAX_VALUE);
            SLList n = new SLList(i, SLList.NIL);
            assertEquals("first() returned something unexpected after a constructor", i, n.first());
        }
    }
    @Test
    public void testSetFirst() {
        Random r = new Random();
        SLList n = new SLList(0, SLList.NIL);
        for (int k = 0; k < 100; k++) {
            int i = r.nextInt(Integer.MAX_VALUE);
            n.setFirst(i);
            assertEquals("first() returned something unexpected after setFirst()", i, n.first());
        }
    }
    @Test
    public void testSetRest() {
        SLList n = new SLList(1, SLList.NIL);
        SLList nn = new SLList(2, SLList.NIL);
        n.setRest(nn);
        assertEquals("rest() returned something unexpected after setRest()", nn, n.rest());
        nn.setRest(nn);
        assertEquals("rest() returned something unexpected after setRest()", nn, nn.rest());        
    }
}
