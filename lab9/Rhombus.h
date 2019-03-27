#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Figure.h"
#include <iostream>
#include <cstdlib>
#include <memory>

class Rhombus : public Figure {
  public:
    Rhombus();
    Rhombus(size_t i, size_t j);
    Rhombus(const Rhombus& orig);
    Rhombus& operator++();
    size_t Square() override;
    void Print() override;
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& obj);
    friend std::istream& operator>>(std::istream& is, Rhombus& obj);
    Rhombus& operator=(const Rhombus& right);
    virtual ~Rhombus();

  private:
    size_t diag_a;
    size_t diag_b;
    int ft = 2;
};

#endif // RHOMBUS_H
