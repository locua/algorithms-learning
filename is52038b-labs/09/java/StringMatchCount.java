class StringMatchCount {
    public static void main(String args[]) {
	String P = "ab";
	String T = "aaaaaaaaaa";
	StringMatch matcher = new NaiveStringMatch();

	matcher.match(T, P);
	System.out.println("char reads: " + matcher.counter.report());
    }
}
