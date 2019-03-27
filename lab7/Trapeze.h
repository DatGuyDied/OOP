#ifndef TRAPEZE_H
#define TRAPEZE_H
#include "Figure.h"
#include <iostream>
#include <cstdlib>
#include <memory>

class Trapeze : public Figure
{
  public:
    Trapeze();
    Trapeze(size_t i, size_t j, size_t k);
    Trapeze(const Trapeze& orig);
    Trapeze& operator++();
    void Print() override;
    size_t Square() override;
    int GetFType() override;
    size_t GetA() override;
    size_t GetB() override;
    size_t GetC() override;
    friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
    friend std::istream& operator>>(std::istream& is, Trapeze& obj);
    Trapeze& operator=(const Trapeze& right);
    virtual ~Trapeze() override;

  private:
    size_t base_a;
    size_t base_b;
    size_t height;
};

#endif // TRAPEZE_H
