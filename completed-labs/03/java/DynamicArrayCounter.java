class DynamicArrayCounter {
    public static void main(String args[]) {
	int[] l = {1, 5, 10, 50, 100, 500, 1000};
	for (int i = 0; i < l.length; i++) {
	    DynamicArray a = new DynamicArray(5);
	    for(int n = 0; n < l[i]; n++) {
		a.push(n);
	    }
	    System.out.println("" + l[i] + "," + a.counter.report());
	}
    }
}
