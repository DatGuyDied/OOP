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
    int GetFType() override;
    size_t GetA() override;
    size_t GetB() override;
    size_t GetC() override;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
    friend std::istream& operator>>(std::istream& is, Rectangle& obj);
    Rectangle& operator=(const Rectangle& right);
    virtual ~Rectangle() override;

  private:
    size_t side_a;
    size_t side_b;
};

#endif // RECTANGLE_H
