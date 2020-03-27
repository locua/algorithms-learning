public class ListVisualiser {
	public SLList toVisualise;
	public String pointers = "";
	public String lines = "";
	public String values= "";

	// All instance of ListVisualiser share this atrs.
	public static String separatorLine = "->";
	public static String separatorSpace = "  ";
	public static String separatorTab = "    ";

    public ListVisualiser(SLList l) { 
		this.toVisualise = l;
    }
    public void visualise() {
        SLList.Node begin = this.toVisualise.l;
        while(begin.next.next!=null) {
			
			pointers += "[*|*]" + ListVisualiser.separatorLine;
			lines += "  |  " + ListVisualiser.separatorSpace;
			if((Integer) begin.info > 9 ) {
				values+= ListVisualiser.separatorSpace + begin.info + ListVisualiser.separatorTab.substring(0,ListVisualiser.separatorTab.length()-1);
			}else {
				values+= ListVisualiser.separatorSpace + begin.info + ListVisualiser.separatorTab;
			}
			
			
			begin = begin.next;
		}
		pointers += "[*|/]";
		lines += "  |  ";
        values+= "  " + begin.info;
        
        System.out.println(pointers);
		System.out.println(lines);
		System.out.println(values);

    }
}
