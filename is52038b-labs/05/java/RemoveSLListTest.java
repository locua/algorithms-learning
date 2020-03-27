import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class RemoveSLListTest {
    @Test
    public void testRemoveOfNIL() {
        SLList n = SLList.NIL.remove(1);
        assertEquals("What can you remove from NIL?", SLList.NIL, n);
        n = SLList.NIL.remove(0);
        assertEquals("What can you remove from NIL?", SLList.NIL, n);
    }
    @Test
    public void testRemove1() {
        SLList n = new SLList(1, SLList.NIL);
        SLList r = n.remove(0);
        assertNotEquals("remove must return a fresh list", n, r);
        assertEquals("removing an object not present doesn't change the length", 1, r.length());
        assertEquals("removing an object not present doesn't change any item", 1, r.first());
        assertEquals("removing an object not present doesn't change the next field", SLList.NIL, r.rest());
        r = n.remove(1);
        assertEquals("removing the only item present gives a length zero list", 0, r.length());
        assertEquals("the only length zero list is NIL", SLList.NIL, r);
    }
    @Test
    public void testRemove2() {
        SLList n = new SLList(1, SLList.NIL);
        SLList nn = new SLList(2, n);
        SLList r = nn.remove(0);
        assertNotEquals("remove must return a fresh list", nn, r);
        assertEquals("removing an object not present doesn't change the length", 2, r.length());
        assertEquals("removing an object not present doesn't change any item", 2, r.first());
        assertNotEquals("remove must return a completely fresh list", n, r.rest());
        assertEquals("removing an object not present doesn't change any item", 1, r.rest().first());
        assertEquals("removing an object not present doesn't change the next fields", SLList.NIL, r.rest().rest());
        r = nn.remove(1);
        assertNotEquals("remove must return a fresh list", nn, r);
        assertEquals("remove of an object present will change the length", 1, r.length());
        assertEquals("remove of an object present can change which item is first", 2, r.first());
        assertEquals("remove of an object present will change the list structure", SLList.NIL, r.rest());
    }
}
