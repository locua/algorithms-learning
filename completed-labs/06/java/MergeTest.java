import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.Before;

public class MergeTest {
    @Test
    public void testMergeNILNIL() {
	SLList r = SLList.NIL.merge(SLList.NIL);
	assertEquals("NIL merged with NIL should be NIL", SLList.NIL, r);
    }
    @Test
    public void testMergeNIL() {
	SLList r = SLList.NIL.merge(new SLList(10, SLList.NIL));
	assertEquals("Merging NIL with x should give x", 10, r.first());
	assertEquals("Merging NIL with x should give x", SLList.NIL, r.rest());
	SLList r2 = new SLList(20, SLList.NIL).merge(SLList.NIL);
	assertEquals("Merging x with NIL should give x", 20, r2.first());
	assertEquals("Merging x with NIL should give x", SLList.NIL, r2.rest());
    }
    @Test
    public void testNontrivialMerge() {
	SLList l1 = new SLList(4, new SLList(17, SLList.NIL));
	SLList l2 = new SLList(5, new SLList(29, SLList.NIL));

	SLList r11 = l1.merge(l1);
	SLList r12 = l1.merge(l2);
	SLList r21 = l2.merge(l1);
	SLList r22 = l2.merge(l2);

	assertEquals("expected: (4 4 17 17)", 4, r11.first());
	assertEquals("expected: (4 4 17 17)", 4, r11.rest().first());
	assertEquals("expected: (4 4 17 17)", 17, r11.rest().rest().first());
	assertEquals("expected: (4 4 17 17)", 17, r11.rest().rest().rest().first());

	assertEquals("expected: (4 5 17 29)", 4, r12.first());
	assertEquals("expected: (4 5 17 29)", 5, r12.rest().first());
	assertEquals("expected: (4 5 17 29)", 17, r12.rest().rest().first());
	assertEquals("expected: (4 5 17 29)", 29, r12.rest().rest().rest().first());

	assertEquals("expected: (4 5 17 29)", 4, r21.first());
	assertEquals("expected: (4 5 17 29)", 5, r21.rest().first());
	assertEquals("expected: (4 5 17 29)", 17, r21.rest().rest().first());
	assertEquals("expected: (4 5 17 29)", 29, r21.rest().rest().rest().first());

	assertEquals("expected: (5 5 29 29)", 5, r22.first());
	assertEquals("expected: (5 5 29 29)", 5, r22.rest().first());
	assertEquals("expected: (5 5 29 29)", 29, r22.rest().rest().first());
	assertEquals("expected: (5 5 29 29)", 29, r22.rest().rest().rest().first());
    }
}
