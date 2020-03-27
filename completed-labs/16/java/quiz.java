public class quiz{
    public static void main(String[] args) {

        long x = 1;
        for (long i = 0; i < 4294967296L; i++) {
            x = i;
            x ^= (x << 13) % 4294967296L;
            x ^= (x >> 17) % 4294967296L;
            x ^= (x << 5) % 4294967296L;
        
            if (x == 62019) {
                System.out.println(i);
            }
        }
    }
}
