import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;
import java.util.Random;
import org.junit.Test;

public class TrieQueryTest {
    @Test
    public void testQueryOne() {
	Trie t = new Trie();
	t.insert("one");
	assertTrue(!t.query("a"));
	assertTrue(!t.query("on"));
	assertTrue(t.query("one"));
	assertTrue(!t.query("ones"));
	assertTrue(!t.query("two"));
	assertTrue(!t.query("only"));
    }
    @Test
    public void testQueryTwo() {
	Trie t = new Trie();
	t.insert("one");
	t.insert("two");
	assertTrue(!t.query("a"));
	assertTrue(!t.query("on"));
	assertTrue(t.query("one"));
	assertTrue(!t.query("ones"));
	assertTrue(!t.query("t"));
	assertTrue(!t.query("tw"));
	assertTrue(t.query("two"));
	assertTrue(!t.query("twos"));
	assertTrue(!t.query("only"));
    }
    @Test
    public void testQueryCommonPrefix() {
	Trie t = new Trie();
	t.insert("one");
	t.insert("only");
	assertTrue(!t.query("a"));
	assertTrue(!t.query("on"));
	assertTrue(t.query("one"));
	assertTrue(!t.query("ones"));
	assertTrue(!t.query("t"));
	assertTrue(!t.query("tw"));
	assertTrue(!t.query("two"));
	assertTrue(!t.query("twos"));
	assertTrue(t.query("only"));
    }
    @Test
    public void testQueryStock() {
	Trie t = new Trie();
	assertTrue(!t.query("bear"));
	t.insert("bear");
	assertTrue(t.query("bear"));
	assertTrue(!t.query("bell"));
	t.insert("bell");
	assertTrue(t.query("bell"));
	assertTrue(!t.query("bid"));
	t.insert("bid");
	assertTrue(t.query("bid"));
	assertTrue(!t.query("bull"));
	t.insert("bull");
	assertTrue(t.query("bull"));
	assertTrue(!t.query("buy"));
	t.insert("buy");
	assertTrue(t.query("buy"));
	assertTrue(!t.query("sell"));
	t.insert("sell");
	assertTrue(t.query("sell"));
	assertTrue(!t.query("stock"));
	t.insert("stock");
	assertTrue(t.query("stock"));
	assertTrue(!t.query("stop"));
	t.insert("stop");
	assertTrue(t.query("bear"));
	assertTrue(t.query("bell"));	
	assertTrue(t.query("bid"));
	assertTrue(t.query("bull"));	
	assertTrue(t.query("buy"));
	assertTrue(t.query("sell"));
	assertTrue(t.query("stock"));
	assertTrue(t.query("stop"));
    }
}
