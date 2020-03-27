public class Queue {
    private SLList head = SLList.NIL;
    private SLList tail = SLList.NIL;
    public Queue() { }
    public void enqueue(Object o) {
	if (tail == SLList.NIL) {
	    tail = new SLList(o, tail);
	    head = tail;
	} else {
	    tail.setRest(new SLList(o, SLList.NIL));
	    tail = tail.rest();
	}
    }
    public Object dequeue() {
	Object r = head.first();
	head = head.rest();
	if (head == SLList.NIL) {
	    tail = SLList.NIL;
	}
	return r;
    }
    public Object head() {
	return head.first();
    }
    public boolean empty() {
	return head == SLList.NIL;
    }
}
