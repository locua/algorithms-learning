#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <cstdlib>
#include <algorithm>
#include <string>

class BigInt {
public:
  size_t ndigits;
  unsigned char *data;
public:
  BigInt(size_t);
  BigInt(std::string);
  ~BigInt();
  unsigned char get(size_t);
  BigInt *Add(BigInt *);
  BigInt *Sub(BigInt *);
  BigInt *Shift(size_t);
  BigInt *MulByDigit(unsigned char);
  BigInt *Mul(BigInt *);
  BigInt *Div(BigInt *);
  BigInt *Rem(BigInt *);
};

#endif
