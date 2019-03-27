#ifndef FIGURE_H
#define FIGURE_H
#include <memory>


class Figure
{
  public:
    virtual size_t Square() = 0;
    virtual void Print() = 0;

    bool operator==(Figure& f) {
      return this->Square() == f.Square();
    }
    bool operator!=(Figure& f) {
      return this->Square() != f.Square();
    }
    bool operator<=(Figure& f) {
      return this->Square() <= f.Square();
    }
    bool operator>=(Figure& f) {
      return this->Square() >= f.Square();
    }
    bool operator>(Figure& f) {
      return this->Square() > f.Square();
    }
    bool operator<(Figure& f) {
      return this->Square() < f.Square();
    }
    operator double() {
      return this->Square();
    }

    virtual ~Figure() {};
};

#endif // FIGURE_H
