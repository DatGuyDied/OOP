#include "Rhombus.h"
#include <cmath>
#include <iostream>

Rhombus::Rhombus() : Rhombus(0,0) {
}

Rhombus::Rhombus(size_t i, size_t j) : diag_a(i), diag_b(j) {
  std::cout << "Rhombus created: " << diag_a << ", " << diag_b << std::endl;
}

Rhombus::Rhombus(std::istream &is) {
  std::cout << "Enter diag a and diag b:" << std::endl;
  is >> diag_a;
  is >> diag_b;

}

Rhombus::Rhombus(const Rhombus& orig) {
  std::cout << "Rhombus copy created" << std::endl;
  diag_a = orig.diag_a;
  diag_b = orig.diag_b;
}

double Rhombus::Square() {
  return (diag_a * diag_b) / 2.0;
}

void Rhombus::Print(){
  std::cout << "diag a = " << diag_a << ", diag b = " << diag_b << std::endl;
}

Rhombus::~Rhombus()
{
  std::cout << "Rhombus deleted" << std::endl;
}
