#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#include <iostream>
#include <cstdlib>
#include <memory>

class Rectangle : public Figure
{
  public:
    Rectangle();
    Rectangle(size_t i, size_t j);
    Rectangle(const Rectangle& orig);
    Rectangle& operator++();
    void Print() override;
    size_t Square() override;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
    friend std::istream& operator>>(std::istream& is, Rectangle& obj);
    Rectangle& operator=(const Rectangle& right);
    virtual ~Rectangle();

  private:
    size_t side_a;
    size_t side_b;
    int ft = 1;
};

#endif // RECTANGLE_H
