import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertNotNull;
import java.util.Random;
import org.junit.Test;

public class TrieInsertTest {
    @Test
    public void testInsertOne() {
	Trie t = new Trie();
	t.insert("one");
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'o') assertNull(t.children[i]);
	}
	t = t.children['o' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'n') assertNull(t.children[i]);
	}
	t = t.children['n' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'e') assertNull(t.children[i]);
	}
	t = t.children['e' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != '{') assertNull(t.children[i]);
	}
	t = t.children['{' - 'a'];
	assertNotNull(t);
    }
    @Test
    public void testInsertTwo() {
	Trie u = new Trie();
	Trie t = u;
	t.insert("one");
	t.insert("two");
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'o' && ('a' + i) != 't') assertNull(t.children[i]);
	}
	t = t.children['o' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'n') assertNull(t.children[i]);
	}
	t = t.children['n' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'e') assertNull(t.children[i]);
	}
	t = t.children['e' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != '{') assertNull(t.children[i]);
	}
	t = t.children['{' - 'a'];
	assertNotNull(t);
	t = u;
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 't' && ('a' + i) != 'o') assertNull(t.children[i]);
	}
	t = t.children['t' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'w') assertNull(t.children[i]);
	}
	t = t.children['w' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'o') assertNull(t.children[i]);
	}
	t = t.children['o' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != '{') assertNull(t.children[i]);
	}
	t = t.children['{' - 'a'];
	assertNotNull(t);
    }
    @Test
    public void testInsertCommonPrefix() {
	Trie t = new Trie();
	t.insert("one");
	t.insert("only");
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'o') assertNull(t.children[i]);
	}
	t = t.children['o' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'n') assertNull(t.children[i]);
	}
	t = t.children['n' - 'a'];
	assertNotNull(t);
	Trie u = t;
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'e' && ('a' + i) != 'l') assertNull(t.children[i]);
	}
	t = t.children['e' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != '{') assertNull(t.children[i]);
	}
	t = t.children['{' - 'a'];
	assertNotNull(t);
	t = u.children['l' - 'a'];
	assertNotNull(t);
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != 'y') assertNull(t.children[i]);
	}
	t = t.children['y' - 'a'];
	for (int i = 0; i < 27; i++) {
	    if (('a' + i) != '{') assertNull(t.children[i]);
	}
	t = t.children['{' - 'a'];
	assertNotNull(t);
    }
}
