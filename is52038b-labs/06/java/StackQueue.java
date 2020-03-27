public class StackQueue {
    private static Stack s;
    private static Queue q;
    public static void main(String[] args) {
	prepare();
	System.out.print(q.dequeue());
	System.out.print(s.pop());
	System.out.print(s.pop());
	System.out.print(q.dequeue());
	s.pop();
	q.dequeue();
	System.out.print(s.pop());
	System.out.print(q.dequeue());
	System.out.print(s.pop());
	System.out.println(q.dequeue());
	s.pop();
	q.dequeue();
    }
    private static void prepare() {
    }
}
