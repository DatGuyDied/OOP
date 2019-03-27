#include "Trapeze.h"
#include <cmath>

Trapeze::Trapeze() : Trapeze(0, 0, 0) {}

Trapeze::Trapeze(size_t i, size_t j, size_t k) : base_a(i), base_b(j), height(k) {}

Trapeze::Trapeze(const Trapeze& orig) {
  base_a = orig.base_a;
  base_b = orig.base_b;
  height = orig.height;
}

double Trapeze::Square() {
  double p = (base_a + base_b) / 2.0;
  return (p * height);
}

void Trapeze::Print() {
  std::cout << "|TR| (" << base_a << ", " << base_b << ", " << height << ")" << std::endl;
}

Trapeze& Trapeze::operator++(){
  base_a++;
  base_b++;
  height++;
  return *this;
}

Trapeze operator+(const Trapeze& left, const Trapeze& right) {
  return Trapeze(left.base_a + right.base_a, left.base_b + right.base_b, left.height + right.height);
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {
  os << "base a = " << obj.base_a << ", base b = " << obj.base_b << ", height = " << obj.height;/* << std::endl*/;
  return os;
}

std::istream& operator>>(std::istream& is, Trapeze& obj) {
  is >> obj.base_a;
  is >> obj.base_b;
  is >> obj.height;

  return is;
}

Trapeze& Trapeze::operator=(const Trapeze& right) {
  if (this == &right) {return *this;}
  base_a = right.base_a;
  base_b = right.base_b;
  height = right.height;

  return *this;
}

Trapeze::~Trapeze() {}
