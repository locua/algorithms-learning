public class LCG {
    long a,c,m,s;
    public LCG(long _a, long _c, long _m, long seed) { 
        a = _a;
        c = _c;
        m = _m;
        seed(s);
    }

    public long next() {
        return (a * s + c) % m;
    }
    public void seed(long seed) { 
        s = seed;
    }
}
