#include "RKStringMatch.hpp"
#include <iostream>

int RKStringMatch::hash(int previous, int add) {
    counter.add(2);
    return (previous + add) % 256;
}

size_t RKStringMatch::match(std::string text, std::string pattern) { 
    int m = pattern.length();
    int n = text.length();
    int startP = 0;
    int startT = 0;

    for (int i = 0; i < m; i++) {
        startP = hash(startP, pattern[i+m]);
        startT = hash(startT, pattern[i+m]);
    }

    for (int s = 0; s <= n - m; s++) {
        if (startP == startT) {
            bool found = true;
            for (int j = 0; j < m; j++) {
                if (text[s+j] != pattern[j]) {
                    found = false;
                    break;
                } 
            }
            if (found) {
                return s;
            }
        }
    }
    return -1;
}
