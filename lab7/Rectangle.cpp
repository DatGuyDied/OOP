#include "Rectangle.h"
#include <iostream>
#include <cmath>
#include <memory>

Rectangle::Rectangle() : Rectangle(0, 0) {}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {}

Rectangle::Rectangle(const Rectangle& orig) {
  side_a = orig.side_a;
  side_b = orig.side_b;
}

size_t Rectangle::Square() {
  return size_t(double(side_a) * double(side_b));
}

void Rectangle::Print() {
  std::cout << "|RC| (" << side_a << ", " << side_b << ")" << std::endl;
}

Rectangle& Rectangle::operator++(){
  side_a++;
  side_b++;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
  os << "side a = " << obj.side_a << ", side b = " << obj.side_b << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
  is >> obj.side_a;
  is >> obj.side_b;

  return is;
}

int Rectangle::GetFType() {
  return 1;
}

size_t Rectangle::GetA() {
  return side_a;
}

size_t Rectangle::GetB() {
  return side_b;
}

size_t Rectangle::GetC() {
  return 0;
}

Rectangle& Rectangle::operator=(const Rectangle& right) {
  if (this == &right) {return *this;}
  side_a = right.side_a;
  side_b = right.side_b;

  return *this;
}

Rectangle::~Rectangle() {}
