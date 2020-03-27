public class SLList {
	class Node{
		Node next;
		Object info;
		public Node(){
			this.next = null;
		}
		
		public Node(Object i, Node n) {
			this.info = i;
			this.next = n;
		}

		public Node getNext() {
			return next;
		}

		public void setNext(Node next) {
			this.next = next;
		}

		public Object getInfo() {
			return info;
		}

		public void setInfo(Object info) {
			this.info = info;
		}
		
	}
	
	public static final SLList NIL = new SLList(0, null);
	public Node l;

	public SLList() {
		l = new Node();
		l.next = null;
	}

	public SLList(Object info, SLList s){
		
		if(s == null) {
			l = new Node(info, null);
		}else {
			l = new Node();
			l.info = info;
			l.next = s.l;
		}
	}
	
	/*public SLList(Object info, Node n) {
		l = new Node((Integer) info, n);
	}*/
	
	public int length() {
		Node iter = this.l;
		int cont = 0;
		while(iter.next != null) {
			cont++;
			iter = iter.next;
		}
		return cont;
	}
	
	public void pushBack(Object a) {
		if( l.next == null && l.info == (Integer)0 ) {
			l.info = a;
		}else {
			Node iter = this.l;
			while(iter.next != null) {
				iter = iter.next;
			}
			iter.next = new Node(a, null);
		}
		
		
	}
	
	
}
