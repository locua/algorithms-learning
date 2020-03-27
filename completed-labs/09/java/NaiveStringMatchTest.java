import org.junit.Before;

public class NaiveStringMatchTest extends StringMatchTest {
    @Before
    public void setUp() {
        matcher = new NaiveStringMatch();
    }
}
