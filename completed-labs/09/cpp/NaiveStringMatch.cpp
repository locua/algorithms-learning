#include "NaiveStringMatch.hpp"
#include <iostream>

size_t NaiveStringMatch::match(std::string text, std::string pattern) { 
    if (text == pattern) {
        return 0;
    }
    if (text.length() == 0) {
        return -1;
    }
    int m = pattern.length();
    int t = text.length() - m;
    
    if (t >= 0) {
        for (int s = 0; s <= t; s++) {
            bool found = true;
            for (int j = 0; j < m; j++) {
                counter.add(2);
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
