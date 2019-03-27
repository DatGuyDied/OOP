#include "Rhombus.h"
#include <cmath>
#include <iostream>
#include <memory>

Rhombus::Rhombus() : Rhombus(0, 0) {}

Rhombus::Rhombus(size_t i, size_t j) : side(i), height(j) {}

Rhombus::Rhombus(const Rhombus& orig) {
  side = orig.side;
  height = orig.height;
}

size_t Rhombus::Square() {
  double p = (double) sqrt(side * side - double(height * height / 4));
  return (p * height);
}

void Rhombus::Print() {
  std::cout << "|RH| (" << side << ", " << height << ")" << std::endl;
}

Rhombus& Rhombus::operator++(){
  side++;
  height++;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Rhombus& obj) {
  os << "side = " << obj.side << ", height = " << obj.height/* << std::endl*/;
  return os;
}

std::istream& operator>>(std::istream& is, Rhombus& obj) {
  is >> obj.side;
  is >> obj.height;

  return is;
}

int Rhombus::GetFType() {
  return 2;
}

size_t Rhombus::GetA() {
  return side;
}

size_t Rhombus::GetB() {
  return height;
}

size_t Rhombus::GetC() {
  return 0;
}



Rhombus& Rhombus::operator=(const Rhombus& right) {
  if (this == &right) {return *this;}
  side = right.side;
  height = right.height;

  return *this;
}

Rhombus::~Rhombus() {}
