import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.Before;

public class SublistTest {
    private SLList n;
    private SLList ncirc;

    @Test
    public void testSublistOfNIL() {
	SLList r = SLList.NIL.sublist(0, 0);
	assertEquals("The sublist of NIL starting at 0 and ending at 0 should be NIL", SLList.NIL, r);
    }
    @Test
    public void testEmptySublist() {
	SLList r = n.sublist(0,0);
	assertEquals("The sublist of a list starting at 0 and ending at 0 should be NIL", SLList.NIL, r);
	SLList r2 = n.sublist(1,1);
	assertEquals("The sublist of a non-empty list starting at 1 and ending at 1 should be NIL", SLList.NIL, r2);
    }
    @Test
    public void testNonemptySublist() {
	SLList r = n.sublist(0,1);
	assertNotEquals("The list returned from sublist with start 0 and end 1 should not be NIL", SLList.NIL, r);
	assertEquals("The first element of the sublist with start 0 and end 1 should be 96", 96, r.first());
	assertEquals("The list returned from sublist with start 0 and end 1 should have length 1.", SLList.NIL, r.rest());
	SLList r2 = n.sublist(1,2);
	assertNotEquals("The list returned from sublist with start 1 and end 2 should not be NIL", SLList.NIL, r);
	assertEquals("The first element of the sublist with start 1 and end 2 should be 172", 172, r2.first());
	assertEquals("The list returned from sublist with start 1 and end 2 should have length 1.", SLList.NIL, r2.rest());
	SLList r3 = n.sublist(1,3);
	assertNotEquals("The list returned from sublist with start 1 and end 3 should not be NIL", SLList.NIL, r3);
	assertEquals("The first element of the sublist with start 1 and end 3 should be 172", 172, r3.first());
	assertNotEquals("The list returned from sublist with start 1 and end 3 should have length 2.", SLList.NIL, r3.rest());
	assertEquals("The second element of the sublist with start 1 and end 3 should be 3", 3, r3.rest().first());
	assertEquals("The list returned from sublist with start 1 and end 3 should have length 2.", SLList.NIL, r3.rest().rest());
	SLList r4 = ncirc.sublist(10,11);
	assertEquals("The sublist with start 10 and end 11 should be (4)", 4, r4.first());
	assertEquals("The sublist with start 10 and end 11 should be (4)", SLList.NIL, r4.rest());
    }

    @Before
    public void setUp() {
	n = new SLList(96, new SLList(172, new SLList(3, SLList.NIL)));
	ncirc = new SLList(4, new SLList(17, SLList.NIL));
	ncirc.rest().setRest(ncirc);
    }
}
