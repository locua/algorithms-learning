import org.junit.Test;
import static org.junit.Assert.assertTrue;

public class HelloTest {
    @Test
    public void testStudentNumber() {
	Hello h = new Hello();
	int sn = h.studentNumber();
	assertTrue("Your student number should be greater than 200000", sn > 200000);
	assertTrue("Your student number should be less than 40000000", sn < 40000000);
    }
    @Test
    public void testMoodleID() {
	Hello h = new Hello();
	int mid = h.moodleID();
	assertTrue("Your moodle ID number should be greater than 10000", mid > 10000);
	assertTrue("Your moodle ID number should be less than 100000", mid < 100000);
    }
}
