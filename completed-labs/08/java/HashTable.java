public class HashTable {
    long a;
    long c;
    long m;
    float counter;
    // public for testing purposes
    public int buckets[];
    public int oldBuckets[];
    public HashTable(long _a, long _c, long _m) {
        this.a = _a;
        this.c = _c;
        this.m = _m;

        buckets = new int[(int)_m];

    }

    public void extend(){
        oldBuckets = new int[(int)this.m];
        oldBuckets = buckets;
        this.m = this.m*2;
        buckets = new int[(int)this.m];

        for(int i = 0;i<counter;i++){
            this.insert(oldBuckets[i]);
        }
    }

    public void insert(int key) {
        int val = hashing(key);

        if(buckets[val] == 0){
            buckets[val] = key;
            counter ++;
        } else if(counter == buckets.length){
            extend();
        } else {
            while(true){
                if(buckets[val] == 0){
                    buckets[val] = key;
                    counter ++;
                    break;
                }
                val = (val+1)%(int)this.m;                
            }
        }

    }
    public boolean find(int key) {
        int val = hashing(key);
        if(buckets[val]==key){
            return true;
        }
        else{
            while(buckets[val] != 0){
                if(buckets[val]==key){
                    return true;
                }
                val++;
            }
        }
        return false;
    }
    public double loadFactor() {
        return counter/this.m;
    }

    public void remove(int key){
        int val = hashing(key);
        int startVal = val;
        while(buckets[val] != key){
            val++;
        }
        if(buckets[val] == key){
            buckets[val] = 0;
            if(hashing(buckets[val+1])==startVal){
                buckets[startVal]=buckets[val+1];
                buckets[val+1]=0;
            }
        }
    }

    private int hashing(int x){
        return (int)((this.a*x +this.c)%buckets.length);
    }
}