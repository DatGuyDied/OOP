#include "Rectangle.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle() : Rectangle(0,0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
  std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
  std::cout << "Enter side a and side b:" << std::endl;
  is >> side_a;
  is >> side_b;

}

Rectangle::Rectangle(const Rectangle& orig) {
  std::cout << "Rectangle copy created" << std::endl;
  side_a = orig.side_a;
  side_b = orig.side_b;
}

double Rectangle::Square() {
  return (side_a * side_b);
}

void Rectangle::Print(){
  std::cout << "side a = " << side_a << ", side b = " << side_b << std::endl;
}

Rectangle::~Rectangle()
{
  std::cout << "Rectangle deleted" << std::endl;
}
