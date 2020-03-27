public class BigInt {
    public int ndigits;
    // public for test purposes
    public char data[];

    public BigInt(int _ndigits) {
        this.ndigits = _ndigits;
        data = new char [ndigits];
    }
    public BigInt(String s) {
        this.ndigits = s.length();
        data = new char [ndigits];
        int j = 0;
        for(int i=s.length()-1; i>=0; i--) {
            data[i] = (char) (s.charAt(j)-'0');
            j++;
        }
    }

    public char get(int i) {
        if (i >= this.ndigits) {
            return 0;
        }

        return this.data[i];
    }
    public BigInt Add(BigInt y) {
        return this;
    }
    public BigInt Sub(BigInt y) {
        return this;
    }
    public BigInt Shift(int n) {
        return this;
    }
    public BigInt MulByDigit(char c) {
        return this;
    }
    public BigInt Mul(BigInt y) {
        String s1 = "";
        String s2 = "";
        for(int i=0; i<ndigits; i++){
            s1 += (int) get(i);
            s2 += (int) y.get(i);
        }
        int[] m = new int[s1.length()+s2.length()]; 
        for (int i = 0; i < s1.length(); i++)  
        { 

            for (int j = 0; j < s2.length(); j++)  
            { 
                m[i+j] = (s1.charAt(i)-'0')*(s2.charAt(j)-'0') + m[i+j]; 
              
            } 
        } 
        //System.out.println(s1 + "  s1:s2. " + s2);
          
      
        String f = "";
        for (int i = 0; i < m.length; i++) 
        { 
            int d = m[i]%10; 
            int carry = m[i]/10; 
            //System.out.println(d + "     ple    " + carry);
            if(i+1<m.length) 
            { 
                m[i+1] = m[i+1] + carry; 
            } 
            f = d+f; 
              
        } 
        // System.out.println(s1);
        // System.out.println(s2);

        // while(f.length()>1 && f.charAt(0) == '0') 
        // { 
        //     f = f.substring(1); 
        // }

        BigInt hey = new BigInt(f);
        return hey;
    }
    public BigInt Div(BigInt d) {
	return this;
    }
    public BigInt Rem(BigInt d) {
	return this;
    }
}
