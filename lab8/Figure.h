#ifndef FIGURE_H
#define FIGURE_H
#include <memory>


class Figure
{
  public:
    virtual size_t Square() = 0;
    virtual void Print() = 0;

    bool operator==(Figure& other) {
      return this->Square() == other.Square();
    }
    bool operator!=(Figure& other) {
      return this->Square() != other.Square();
    }
    bool operator<(Figure& other) {
      return this->Square() < other.Square();
    }
    bool operator>(Figure& other) {
      return this->Square() > other.Square();
    }
    bool operator<=(Figure& other) {
      return this->Square() <= other.Square();
    }
    bool operator>=(Figure& other) {
      return this->Square() >= other.Square();
    }
    virtual ~Figure() {};
};

#endif // FIGURE_H
