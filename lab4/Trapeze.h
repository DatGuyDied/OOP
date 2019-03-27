#ifndef TRAPEZE_H
#define TRAPEZE_H
#include "Figure.h"
#include <iostream>
#include <cstdlib>

class Trapeze : public Figure
{
  public:
    Trapeze();
    Trapeze(size_t i, size_t j, size_t k);
    Trapeze(const Trapeze& orig);
    double Square() override;
    void Print() override;
    Trapeze& operator++();
    friend Trapeze operator+(const Trapeze& left, const Trapeze& right);
    friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
    friend std::istream& operator>>(std::istream& is, Trapeze& obj);
    Trapeze& operator=(const Trapeze& right);
    virtual ~Trapeze();

  private:
    size_t base_a;
    size_t base_b;
    size_t height;
};

#endif // TRAPEZE_H
