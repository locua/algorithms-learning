public class Trie {

	public static final int alphabet_size = 26;

    public Trie[] children;
    boolean endWord;
    public Trie() {
    	this.children = new Trie[alphabet_size+1];
    	this.endWord = false;
    	for(int i=0;i<children.length;i++){
    		children[i] = null;
    	}
    }
    public void insert(String s) {
    	int curIndex;

    	//current trie
    	Trie crawl = this;

    	//loop through input string and add to current's array
    	for(int i = 0;i<s.length();i++){
    		curIndex = s.charAt(i) -'a';
    		if(crawl.children[curIndex] == null){
    			crawl.children[curIndex] = new Trie();
    		}
    		crawl = crawl.children[curIndex];
    	}
    		curIndex = '{' - 'a';

    		crawl.children[curIndex] = new Trie();
    		crawl.endWord = true;
    }
    public boolean query(String s) {
    	Trie temp = this;

    	for(int i=0; i<s.length();i++){
    		int index = s.charAt(i) - 'a';
    		temp = temp.children[index];
    		if(temp == null){
    			return false;
    		}
    	}

	return (temp.endWord && temp != null);
    }
}
