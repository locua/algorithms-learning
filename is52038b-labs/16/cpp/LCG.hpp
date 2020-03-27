#ifndef LCG_HPP
#define LCG_HPP

#include <cstdint>

class LCG {
public:
  LCG(uint64_t, uint64_t, uint64_t, uint64_t);
  uint32_t next();
  void seed(uint64_t);
};

#endif
