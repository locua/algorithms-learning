import java.util.Map;

public class CompressedTrie {
    public Map<String, CompressedTrie> children;
    public CompressedTrie() {
    }
    public static CompressedTrie compressTrie(Trie t) {
	return new CompressedTrie();
    }
    public boolean query(String s) {
	return false;
    }
    public void insert(String s) {
    }
}
