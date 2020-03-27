import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.Before;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class ExtendedSLListTest {
    private SLList n;
    private SLList ncirc;
    
    @Test
    public void testNth() {
        assertEquals("Not getting the right first (index 0) item from nth", 17, n.nth(0));
        assertEquals("Not getting the right second (index 1) item from nth", 34, n.nth(1));
        assertEquals("Not getting the right third (index 2) item from nth", 3, n.nth(2));
        Random r = new Random();
        for (int k = 0; k < 100; k++) {
            int i = r.nextInt(1000);
            assertEquals(ncirc.nth(i % 2), ncirc.nth(i));
        }
    }
    @Test
    public void testNthRest() {
        assertEquals("Not getting the right rest (index 0) from nthRest", n, n.nthRest(0));
        assertEquals("Not getting the right rest (index 1) from nthRest", n.rest(), n.nthRest(1));
        assertEquals("Not getting the right rest (index 2) from nthRest", n.rest().rest(), n.nthRest(2));
        assertEquals("Not getting the right rest (index 3) from nthRest", SLList.NIL, n.nthRest(3));
        Random r = new Random();
        for (int k = 0; k < 100; k++) {
            int i = r.nextInt(1000);
            assertEquals(ncirc.nthRest(i % 2), ncirc.nthRest(i));
        }
    }

    @Before
    public void setUp() {
        n = new SLList(17, new SLList(34, new SLList(3, SLList.NIL)));
        ncirc = new SLList(2, new SLList (3, SLList.NIL));
        ncirc.rest().setRest(ncirc);
    }
}
