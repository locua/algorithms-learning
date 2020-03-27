#ifndef LCG_HPP
#define LCG_HPP

#include <cstdint>

class LCG {
public:
  LCG(uint64_t, uint64_t, uint64_t, uint64_t);
  LCG(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);
  uint32_t next();
  void seed(uint64_t);
  uint64_t a;
  uint64_t c;
  uint64_t m;
  uint64_t s;
  uint64_t shift = 0;
};

#endif
