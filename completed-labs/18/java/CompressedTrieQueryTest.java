import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;
import java.util.Random;
import org.junit.Test;

public class CompressedTrieQueryTest {
    @Test
    public void testCompressedQueryOne() {
	Trie t = new Trie();
	t.insert("one");
	CompressedTrie c = CompressedTrie.compressTrie(t);
	assertTrue(c.query("one"));
	assertTrue(!c.query("two"));
	assertTrue(!c.query("on"));
	assertTrue(!c.query("ones"));
    }
    @Test
    public void testCompressedQueryTwo() {
	Trie t = new Trie();
	t.insert("one");
	t.insert("two");
	CompressedTrie c = CompressedTrie.compressTrie(t);
	assertTrue(c.query("one"));
	assertTrue(c.query("two"));
	assertTrue(!c.query("on"));
	assertTrue(!c.query("ones"));
    }
    @Test
    public void testCompressedQueryCommonPrefix() {
	Trie t = new Trie();
	t.insert("one");
	t.insert("only");
	CompressedTrie c = CompressedTrie.compressTrie(t);
	assertTrue(c.query("one"));
	assertTrue(!c.query("two"));
	assertTrue(!c.query("on"));
	assertTrue(c.query("only"));
	assertTrue(!c.query("ones"));
    }
    @Test
    public void testCompressedQueryStock() {
	Trie t = new Trie();
	t.insert("bear");
	t.insert("bell");
	t.insert("bid");
	t.insert("bull");
	t.insert("buy");
	t.insert("sell");
	t.insert("stock");
	t.insert("stop");
	CompressedTrie c = CompressedTrie.compressTrie(t);
	assertTrue(c.query("bear"));
	assertTrue(c.query("bell"));
	assertTrue(c.query("bid"));
	assertTrue(c.query("bull"));
	assertTrue(c.query("buy"));
	assertTrue(c.query("sell"));
	assertTrue(c.query("stock"));
	assertTrue(c.query("stop"));
	assertTrue(!c.query("be"));
	assertTrue(!c.query("bells"));
	assertTrue(!c.query("bide"));
	assertTrue(!c.query("hull"));
	assertTrue(!c.query("bay"));
	assertTrue(!c.query("sill"));
	assertTrue(!c.query("stack"));
	assertTrue(!c.query("stops"));
    }
}
