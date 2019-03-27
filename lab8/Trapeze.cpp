#include "Trapeze.h"
#include <memory>
#include <cmath>
#include <iostream>

Trapeze::Trapeze() : Trapeze(0, 0, 0) {}

Trapeze::Trapeze(size_t i, size_t j, size_t k) : base_a(i), base_b(j), height(k) {}

Trapeze::Trapeze(const Trapeze& orig) {
  base_a = orig.base_a;
  base_b = orig.base_b;
  height = orig.height;
}

size_t Trapeze::Square() {
  return size_t(double((base_a + base_b) / 2) * height);
}

void Trapeze::Print() {
  std::cout << "|TR|(" << base_a << ", " << base_b << ", " << height << ')';
}

Trapeze& Trapeze::operator++() {
  base_a++;
  base_b++;
  height++;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {
  os << '(' << obj.base_a << ", " << obj.base_b << ", " << obj.height << ')';
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
