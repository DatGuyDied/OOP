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
    void Print() override;
    size_t Square() override;
    int GetFType() override;
    size_t GetA() override;
    size_t GetB() override;
    size_t GetC() override;
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& obj);
    friend std::istream& operator>>(std::istream& is, Rhombus& obj);
    Rhombus& operator=(const Rhombus& right);
    virtual ~Rhombus() override;

  private:
    size_t side;
    size_t height;
};

#endif // RHOMBUS_H
