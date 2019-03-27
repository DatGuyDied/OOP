#include "Rhombus.h"
#include <memory>
#include <cmath>
#include <iostream>

Rhombus::Rhombus() : Rhombus(0, 0) {}

Rhombus::Rhombus(size_t i, size_t j) : diag_a(i), diag_b(j) {}

Rhombus::Rhombus(const Rhombus& orig) {
  diag_a = orig.diag_a;
  diag_b = orig.diag_b;
}

size_t Rhombus::Square() {
  return size_t((double)(diag_a * diag_b / 2));
}

void Rhombus::Print() {
  std::cout << "|RH|(" << diag_a << ", " << diag_b << ')';
}

Rhombus& Rhombus::operator++() {
  diag_a++;
  diag_b++;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Rhombus& obj) {
  os << '(' << obj.diag_a << ", " << obj.diag_b << ')';
  return os;
}

std::istream& operator>>(std::istream& is, Rhombus& obj) {
  is >> obj.diag_a;
  is >> obj.diag_b;
  return is;
}

Rhombus& Rhombus::operator=(const Rhombus& right) {
  if (this == &right) {return *this;}
  diag_a = right.diag_a;
  diag_b = right.diag_b;
  return *this;
}

Rhombus::~Rhombus() {}
