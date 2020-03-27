public class ListVisualiserDriver {
    private static void usage() {
        System.err.println("Usage: ListVisualiserDriver small|large|empty|cyclic|bigelem|nonint");
    }
    public static void main(String args[]) {
        int argc = args.length;
        if(argc == 0 || argc > 1) {
            usage();
            System.exit(1);
        }
        SLList test = SLList.NIL;
        if(args[0].equals("small")) {
            test = new SLList(14, new SLList(1 << 10, new SLList(-17, new SLList(9999, SLList.NIL))));
        } else if (args[0].equals("large")) {
            for (int i = 0; i < 200; i++) {
                test = new SLList(i, test);
            }
        } else if (args[0].equals("empty")) {
        } else if (args[0].equals("cyclic")) {
            test = new SLList(1, SLList.NIL);
            test.setRest(test);
	} else if (args[0].equals("bigelem")) {
	    test = new SLList(Integer.MIN_VALUE, new SLList(Integer.MAX_VALUE, SLList.NIL));
	} else if (args[0].equals("nonint")) {
	    test = new SLList("abcde", new SLList(new SLList(3, SLList.NIL), SLList.NIL));
        } else {
            usage();
            System.exit(1);
        }
	ListVisualiser v = new ListVisualiser(test);
        v.visualise();
    }
}
