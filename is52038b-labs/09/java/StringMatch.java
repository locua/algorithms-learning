public abstract class StringMatch {
    public OpCounter counter = new OpCounter();
    public abstract int match(String text, String pattern);
}
