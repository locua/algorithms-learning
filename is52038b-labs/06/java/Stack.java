public class Stack {
    private SLList head = SLList.NIL;
    public Stack() { }
    public void push(Object o) {
	head = new SLList(o, head);
    }
    public Object pop() {
	Object r = head.first();
	head = head.rest();
	return r;
    }
    public Object top() {
	return head.first();
    }
    public boolean empty() {
	return head == SLList.NIL;
    }
}
