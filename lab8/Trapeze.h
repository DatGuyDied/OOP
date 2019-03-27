#ifndef TRAPEZE_H
#define	TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
#include <memory>

class Trapeze : public Figure {
public:
    Trapeze();
    Trapeze(size_t i, size_t j, size_t k);
    Trapeze(const Trapeze& orig);

    Trapeze& operator++();
    size_t Square() override;
    void Print() override;

    friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
    friend std::istream& operator>>(std::istream& is, Trapeze& obj);
    Trapeze& operator=(const Trapeze& right);

    virtual ~Trapeze() override;
private:
    size_t base_a;
    size_t base_b;
    size_t height;
    int type = 3;
};

#endif
