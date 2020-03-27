import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;
import java.util.Random;
import org.junit.Test;

public class CompressTrieTest {
    @Test
    public void testCompressOne() {
	Trie t = new Trie();
	t.insert("one");
	CompressedTrie c = CompressedTrie.compressTrie(t);
	assertEquals("There should be one entry in the compressed trie", 1, c.children.size());
	assertTrue("The entry should be 'one{'", c.children.containsKey("one{"));
    }
    @Test
    public void testCompressTwo() {
	Trie t = new Trie();
	t.insert("one");
	t.insert("two");
	CompressedTrie c = CompressedTrie.compressTrie(t);
	assertEquals("There should be two entries in the compressed trie", 2, c.children.size());
	assertTrue("One entry should be 'one{'", c.children.containsKey("one{"));
	assertTrue("One entry should be 'two{'", c.children.containsKey("two{"));
    }
    @Test
    public void testCompressCommonPrefix() {
	Trie t = new Trie();
	t.insert("one");
	t.insert("only");
	CompressedTrie c = CompressedTrie.compressTrie(t);
	assertEquals("There should be one entry in the compressed trie", 1, c.children.size());
	assertTrue("The entry should be 'on'", c.children.containsKey("on"));
	c = c.children.get("on");
	assertEquals("There should be two entries in the compressed trie", 2, c.children.size());
	assertTrue("One entry should be 'e{'", c.children.containsKey("e{"));
	assertTrue("One entry should be 'ly{'", c.children.containsKey("ly{"));
    }
    @Test
    public void testCompressStock() {
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
	assertEquals("There should be two entries in the compressed trie", 2, c.children.size());
	assertTrue("One entry should be 'b'", c.children.containsKey("b"));
	assertTrue("One entry should be 's'", c.children.containsKey("s"));
	CompressedTrie b = c.children.get("b");
	assertEquals("There should be three entries in the compressed trie for b", 3, b.children.size());
	assertTrue("One entry should be 'e'", b.children.containsKey("e"));
	assertTrue("One entry should be 'id{'", b.children.containsKey("id{"));
	assertTrue("One entry should be 'u'", b.children.containsKey("u"));
	CompressedTrie be = b.children.get("e");
	assertEquals("There should be two entries in the compressed trie", 2, be.children.size());
	assertTrue("One entry should be 'ar{'", be.children.containsKey("ar{"));
	assertTrue("One entry should be 'll{'", be.children.containsKey("ll{"));
	CompressedTrie bu = b.children.get("u");
	assertEquals("There should be two entries in the compressed trie", 2, bu.children.size());
	assertTrue("One entry should be 'y{'", bu.children.containsKey("y{"));
	assertTrue("One entry should be 'll{'", bu.children.containsKey("ll{"));
	CompressedTrie s = c.children.get("s");
	assertEquals("There should be two entries in the compressed trie", 2, s.children.size());
	assertTrue("One entry should be 'ell{'", s.children.containsKey("ell{"));
	assertTrue("One entry should be 'to'", s.children.containsKey("to"));
	CompressedTrie sto = s.children.get("to");
	assertEquals("There should be two entries in the compressed trie", 2, sto.children.size());
	assertTrue("One entry should be 'ck{'", sto.children.containsKey("ck{"));
	assertTrue("One entry should be 'p{'", sto.children.containsKey("p{"));
    }
}
