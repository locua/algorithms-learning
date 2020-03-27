#ifndef XORSHIFT_HPP
#define XORSHIFT_HPP

#include <cstdint>

class Xorshift {
public:
  Xorshift(uint32_t, uint32_t, uint32_t, uint32_t);
  uint32_t next();
  void seed(uint32_t);
  uint32_t a;
  uint32_t b;
  uint32_t c;
  uint32_t s;
};

#endif
