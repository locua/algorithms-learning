import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class ReverseSLListTest {
    @Test
    public void testReverseOfNIL() {
        SLList n = SLList.NIL.reverse();
        assertEquals("What should the reverse of NIL be?", SLList.NIL, n);
    }
    @Test
    public void testReverse1() {
        SLList n = new SLList(1, SLList.NIL);
        SLList r = n.reverse();
        assertNotEquals("reverse must return a fresh list", n, r);
        assertEquals("reverse should not change the length of the list", 1, r.length());
        assertEquals("the first item of a reversed one-element list is the same as the first element of the original", 1, r.first());
        assertEquals("reverse of a one-element list should be a one-element list", SLList.NIL, r.rest());
    }
    @Test
    public void testReverse2() {
        SLList n = new SLList(1, SLList.NIL);
        SLList nn = new SLList(2, n);
        SLList r = nn.reverse();
        assertNotEquals("reverse must return a fresh list", nn, r);
        assertEquals("reverse must not change the length of the list", 2, r.length());
        assertEquals("the second item becomes the first", 1, r.first());
        assertNotEquals("all nodes in the reversed list must be fresh", n, r.rest());
        assertEquals("the first item becomes the second", 2, r.rest().first());
        assertEquals("reverse of a two-element list should be a two-element list", SLList.NIL, r.rest().rest());
    }
}
