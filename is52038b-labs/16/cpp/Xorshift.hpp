#ifndef XORSHIFT_HPP
#define XORSHIFT_HPP

#include <cstdint>

class Xorshift {
public:
  Xorshift(uint32_t, uint32_t, uint32_t, uint32_t);
  uint32_t next();
  void seed(uint32_t);
};

#endif
