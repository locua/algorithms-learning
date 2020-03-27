import java.util.Map;
import java.util.HashMap;
import java.util.*;
import java.lang.*;

public class CompressedTrie {
    public Map<String, CompressedTrie> children;
    public CompressedTrie() {
        children = new HashMap<String, CompressedTrie>();
    }

    public static CompressedTrie compressTrie(Trie t) {
        if( t.children == null){
            return null;
        }

        CompressedTrie temp = new CompressedTrie();

        for(int i=0;i<27;i++){
            if(t.children[i] != null){
                // i changed this line below
                String prefix = "";
                prefix += String.valueOf(((char)(i+'a')));
                Trie child = t.children[i];
                int nullNum = 0;
              
                do {
                    nullNum = 0;
                    int tempj = 0;
                    for(int j=0;j<27;j++){
                        if(child.children[j] != null){
                            tempj = j;
                            nullNum++;
                        }
                    }
                    if(nullNum == 1){
                        prefix += String.valueOf((char)(tempj+'a'));
                        child = child.children[tempj];
                    }

                } while (nullNum == 1);
                // while(nullNum == 1){
                //     nullNum = 0;
                //     int tempj = 0;
                //     for(int j=0;i<27;j++){
                //         if(child.children[j] != null){
                //             tempj = j;
                //             nullNum++;
                //         }
                //     }
                //     System.out.println(nullNum);
                //     if(nullNum == 1){
                //         // i changed this line below
                //         System.out.println(prefix);
                //         prefix += String.valueOf((char)(i+'a'));
                //         System.out.println(prefix);
                //         // prefix += String.valueOf(((char)(tempj+'a')));
                //         child = child.children[tempj];
                //     }
                // }
                System.out.println(prefix);
                temp.children.put(prefix,compressTrie(child));
            }
        }
        return temp;
    }

 //    //calls insert on all Strings in list
 //    public static CompressedTrie compressTrie(Trie t) {
 //        final CompressedTrie c = new CompressedTrie();
 //        List<String> w = getInString(t,null);
 //        for(int i=0; i<w.size(); i++){
 //            //adds "{" to all the Strings. GOTTA BE WHY WE USE LEN-1 CHECK!!!!
 //            c.insert(w.get(i) + '{');
 //        }
	// return c;
 //    }

 //    //makes a list of all words contained in trie
 //    private static List<String> getInString(Trie t, String thing){
 //        List<String> s = new ArrayList<String>();
 //        for(int i=0; i<26;i++){
 //            if(t.children[i] != null){
 //                String next = "";
 //                if(thing == null){
 //                    next = String.valueOf(((char)(i+'a')));
 //                }
 //                else{
 //                    next = thing.concat(String.valueOf((char)(i+'a')));
 //                }
 //                s.addAll(getInString(t.children[i], next));
 //            }

 //        }
 //        if(t.children[26] !=null){
 //            s.add(thing);
 //        }

 //        return s;
 //    }


    public boolean query(String s) {
        if (!s.endsWith("{")) {
            s = s + "{";
        }
        String w = "";
        CompressedTrie c = this;
        for(int i=0; i<s.length(); i++){
            w += s.charAt(i);
            if(c.children.containsKey(w)){
                c = c.children.get(w);
                w = "";
            }
        }

	return w.length() == 0;
    }

    //if a string in trie children starts with p, return that string
    //problem, returns the first one, not the best option
    public String containedChild(String p){
        for(String s : children.keySet()){
            if(s.startsWith(p)){
                return s;
            }
        }
        return null;
    }


    public void insert(String s) {
        // //make new string that holds first char of s
        // String w = String.valueOf(s.charAt(0));

        // //string that starts with first char of s
        // String im = containedChild(w.toString());

        // //if that exists
        // if(im != null){
        //     //while there's a string in children that contains w.
        //     while(containedChild(w.toString()) != null){
        //         //add the next character of s to w
        //         w += s.charAt(w.length());

        //         //if s is the same as w, it's already in so leave the function
        //         if(s.equals(w)){
        //             return;
        //         }        

        //     }

        //     //takes a substring of s before branch point
        //     String p = s.substring(0,w.length()-1);
        //     //takes a substring of s after branch point
        //     String ns = s.substring(w.length()-1);
        //     
        //     //in the case when s is an "extension" to an existing word
        //     if(p.equals(im)){
        //         //calls else at bottom to create an "leaf compressedtrie" with str ns
        //         //as a child of im
        //         children.get(im).insert(ns);
        //     }
        //     //if s isnt an extension of existing word
        //     else{
        //         //children.get(im) is the child Trie of im
        //         CompressedTrie pr = children.get(im);
        //         //makes empty new CTrie nt
        //         CompressedTrie nt = new CompressedTrie();
        //         //removes CTrie with key im
        //         children.remove(im);
        //         //adds new sub CTrie to root
        //         children.put(p, nt);
        //         //build the substring of the original im
        //         //from the end of str p to the end of im
        //         String os = im.substring(w.length()-1);
        //         //add both k,v pairs in nt's children
        //         nt.children.put(os, pr);
        //         nt.children.put(ns,nt);
        //     }

        // }
        // else{
        //         children.put(s,new CompressedTrie());
        //     }
        }

    
}
