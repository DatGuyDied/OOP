#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#include <iostream>
#include <cstdlib>

class Rectangle : public Figure
{
  public:
    Rectangle();
    Rectangle(size_t i, size_t j);
    Rectangle(const Rectangle& orig);
    double Square() override;
    void Print() override;
    Rectangle& operator++();
    friend Rectangle operator+(const Rectangle& left, const Rectangle& right);
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
    friend std::istream& operator>>(std::istream& is, Rectangle& obj);
    Rectangle& operator=(const Rectangle& right);
    virtual ~Rectangle();

  private:
    size_t side_a;
    size_t side_b;
};

#endif // RECTANGLE_H
