#include "KMPStringMatch.hpp"
#include <iostream>

int *KMPStringMatch::computePrefix(std::string pattern) {
    int m = pattern.length();
    int *pre = new int[m];
    pre[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && (read(pattern, k) != read(pattern, q))) {
            k = pre[k-1];
        }
        if (read(pattern, k) == read(pattern, q)) {
            k++;
        }
        pre[q] = k;
    }

    return pre;

}

char KMPStringMatch::read(std::string text, int ind) {
    counter.add(1);
    return text[ind];
}

size_t KMPStringMatch::match(std::string text, std::string pattern) {
    if (pattern.length() == 0) {
        return 0;
    }
    if (text.length() == 0) {
        return -1;
    }
    
    int n = text.length();
    int m = pattern.length();
    int *pre = computePrefix(pattern);
    int q = 0;

    for (int i = 0; i < n; i++) {
        // while (q > 0 && (read(pattern, q) != read(text, i))) {
        while (q > 0 && (pattern[q] != text[i])) {
            q = pre[q-1];
        }
        // if (read(pattern, q) == read(text, i)) {
        //     q++;
        // }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            return i - m + 1;        
        }
    }

    return -1;
}
