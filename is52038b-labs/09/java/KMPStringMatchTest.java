import org.junit.Before;

public class KMPStringMatchTest extends StringMatchTest {
    @Before
    public void setUp() {
        matcher = new KMPStringMatch();
    }
}
