import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;
import org.junit.Test;
import org.junit.Before;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

abstract public class StringMatchTest {
    public StringMatch matcher;
    @Test
    public void testZeroPattern() {
        assertEquals(0, matcher.match("abcde", ""));
    }
    @Test
    public void testZeroText() {
        assertEquals(-1, matcher.match("", "abcde"));
        assertEquals(0, matcher.match("", ""));
    }
    @Test
    public void testTable() throws FileNotFoundException {
        Scanner in = new Scanner(new File("../match.txt"));
        while(in.hasNext()) {
            String text = in.next();
            String pattern = in.next();
            int pos = in.nextInt();
            if(pos != matcher.match(text, pattern))
                fail(text + " " + pattern + " " + pos);
        }
    }
}
