#include "Trapeze.h"
#include <cmath>
#include <iostream>

Trapeze::Trapeze() : Trapeze(0,0,0) {
}

Trapeze::Trapeze(size_t i, size_t j, size_t k) : base_a(i), base_b(j), height(k) {
  std::cout << "Trapeze created: " << base_a << ", " << base_b << ", " << height << std::endl;
}

Trapeze::Trapeze(std::istream &is) {
  std::cout << "Enter base a, base b and height:" << std::endl;
  is >> base_a;
  is >> base_b;
  is >> height;

}

Trapeze::Trapeze(const Trapeze& orig) {
  std::cout << "Trapeze copy created" << std::endl;
  base_a = orig.base_a;
  base_b = orig.base_b;
  height = orig.height;
}

double Trapeze::Square() {
  double p = double(base_a + base_b) / 2.0;
  return (p * height);
}

void Trapeze::Print(){
  std::cout << "base a = " << base_a << ", base b = " << base_b << ", height = " << height << std::endl;
}

Trapeze::~Trapeze()
{
  std::cout << "Trapeze deleted" << std::endl;
}
