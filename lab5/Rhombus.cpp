#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus() : Rhombus(0, 0) {}

Rhombus::Rhombus(size_t i, size_t j) : diag_a(i), diag_b(j) {}

Rhombus::Rhombus(const Rhombus& orig) {
  diag_a = orig.diag_a;
  diag_b = orig.diag_b;
}

double Rhombus::Square() {
  return (diag_a * diag_b) / 2.0;
}

void Rhombus::Print() {
  std::cout << "|RH| (" << diag_a << ", " << diag_b << ")" << std::endl;
}

Rhombus& Rhombus::operator++(){
  diag_a++;
  diag_b++;
  return *this;
}

Rhombus operator+(const Rhombus& left, const Rhombus& right) {
  return Rhombus(left.diag_a + right.diag_a, left.diag_b + right.diag_b);
}

std::ostream& operator<<(std::ostream& os, const Rhombus& obj) {
  os << "diag_a = " << obj.diag_a << ", diag_b = " << obj.diag_b/* << std::endl*/;
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
