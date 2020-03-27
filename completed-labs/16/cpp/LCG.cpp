#include "LCG.hpp"

LCG::LCG(uint64_t _a, uint64_t _c, uint64_t _m, uint64_t _seed) {  
    this -> a = _a;
    this -> c = _c;
    this -> m = _m;
    this -> s = _seed;
}

LCG::LCG(uint64_t _a, uint64_t _c, uint64_t _m, uint64_t seed, uint64_t _shift) {
    this -> a = _a;
    this -> c = _c;
    this -> m = _m;
    this -> s = seed;
    shift = _shift;
}

uint32_t LCG::next() {
    seed((this -> a * this -> s + this -> c) % this -> m);
    if (shift == 0) {
        return s;
    }
    else {
        return s >> shift;
    }
}

void LCG::seed(uint64_t seed) {  
    s = seed; 
}
