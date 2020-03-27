#include "Xorshift.hpp"
#include <iostream>

Xorshift::Xorshift(uint32_t _a, uint32_t _b, uint32_t _c, uint32_t seed) {
    this -> a = _a;
    this -> b = _b;
    this -> c = _c;
    this -> s = seed;
}

uint32_t Xorshift::next() {
    uint32_t y = s;
    y ^= y << a;
    y ^= y >> b;
    y ^= y << c;
    seed(y);
    return s;
}

void Xorshift::seed(uint32_t seed) {
    s = seed;
}
