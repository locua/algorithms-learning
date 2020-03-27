import java.util.ArrayList;
import java.util.List;

class Heap {
    // public for JUnit testing purposes
    public ArrayList<Integer> array;
    public int heap_size;

    public Heap(int size) {
    }
    public Heap(List<Integer> source) {
        this(source, false);
    }
    public Heap(List<Integer> source, boolean incremental) {
    }

    public static int parent(int index) {
        return 0;
    }
    public static int left(int index) {
        return 0;
    }
    public static int right(int index) {
        return 0;
    }
    
    public void maxHeapify(int i) {
    }
    public void buildMaxHeap() {
    }
    public void insert(Integer k) {
    }
    public Integer maximum() {
        return 0;
    }
    public Integer extractMax() {
        return 0;
    }
}
