import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.Before;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class BinarySearchSearchTest {
    @Test
    public void testZeroLengthSearch() {
        int[] x = {};
	BinarySearch b = new BinarySearch();
        assertTrue("nothing is in an empty array", !b.search(x, 0, 0, 0));
        assertTrue("nothing is in an empty array", !b.search(x, 1, 0, 0));
        assertTrue("nothing is in an empty array", !b.search(x, 2, 0, 0));
        int[] y = {0,2,3,4};
        assertTrue("nothing is in an empty search", !b.search(y, 0, 0, 0));
        assertTrue("nothing is in an empty search", !b.search(y, 1, 1, 1));
        assertTrue("nothing is in an empty search", !b.search(y, 2, 2, 2));
        assertTrue("nothing is in an empty search", !b.search(y, 4, 3, 3));

    };
    @Test
    public void testSmallSearch() {
        int[] x = {0,2,4,6};
	BinarySearch b = new BinarySearch();
        assertTrue("-2 is not in {0,2,4,6}", !b.search(x, -2, 0, 4));
        assertTrue("-1 is not in {0,2,4,6}", !b.search(x, -1, 0, 4));
        assertTrue("0 is in {0,2,4,6}", b.search(x, 0, 0, 4));
        assertTrue("1 is not in {0,2,4,6}", !b.search(x, 1, 0, 4));
        assertTrue("2 is in {0,2,4,6}", b.search(x, 2, 0, 4));
        assertTrue("3 is not in {0,2,4,6}", !b.search(x, 3, 0, 4));
        assertTrue("4 is in {0,2,4,6}", b.search(x, 4, 0, 4));
        assertTrue("5 is not in {0,2,4,6}", !b.search(x, 5, 0, 4));
        assertTrue("6 is in {0,2,4,6}", b.search(x, 6, 0, 4));
        assertTrue("7 is not in {0,2,4,6}", !b.search(x, 7, 0, 4));
        assertTrue("8 is not in {0,2,4,6}", !b.search(x, 8, 0, 4));
        assertTrue("4 is not in the first half of {0,2,4,6}", !b.search(x, 4, 0, 2));
        assertTrue("2 is not in the second half of {0,2,4,6}", !b.search(x, 2, 2, 4));
    };

    public static void main(String args[]) {
        JUnitCore core = new JUnitCore();
        core.run(BinarySearchSearchTest.class);
    }
}
