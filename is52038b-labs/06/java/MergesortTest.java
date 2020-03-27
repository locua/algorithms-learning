import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.Before;

public class MergesortTest {
    @Test
    public void testMergesortNIL() {
	SLList r = SLList.NIL.mergesort();
	assertEquals("mergesort of NIL should be NIL", SLList.NIL, r);
    }
    @Test
    public void testMergesortOne() {
	SLList r = new SLList(82, SLList.NIL).mergesort();
	assertEquals("mergesort of (82) should be (82)", 82, r.first());
	assertEquals("mergesort of (82) should be (82)", SLList.NIL, r.rest());
    }
    @Test
    public void testNontrivialMergesort() {
	SLList l = new SLList(2, new SLList(32, new SLList(8, new SLList(64, new SLList(1, SLList.NIL)))));
	SLList r = l.mergesort();

	assertEquals("expected: (1 2 8 32 64)", 1, r.first());
	assertEquals("expected: (1 2 8 32 64)", 2, r.rest().first());
	assertEquals("expected: (1 2 8 32 64)", 8, r.rest().rest().first());
	assertEquals("expected: (1 2 8 32 64)", 32, r.rest().rest().rest().first());
	assertEquals("expected: (1 2 8 32 64)", 64, r.rest().rest().rest().rest().first());

	assertEquals("original: (2 32 8 64 1)", 2, l.first());
	assertEquals("original: (2 32 8 64 1)", 32, l.rest().first());
	assertEquals("original: (2 32 8 64 1)", 8, l.rest().rest().first());
	assertEquals("original: (2 32 8 64 1)", 64, l.rest().rest().rest().first());
	assertEquals("original: (2 32 8 64 1)", 1, l.rest().rest().rest().rest().first());
    }
}
