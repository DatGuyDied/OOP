#ifndef TLIST_H
#define TLIST_H
#include <memory>
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "TListItem.h"

class TList
{
  public:
    TList();
    void push_f(std::shared_ptr<Figure> &&figure);
    void push_b(std::shared_ptr<Figure> &&figure);
    void ins(std::shared_ptr<Figure> &&figure, int position);
    double GetSquare(int position);
    bool empty();
    void pop(int position);
    friend std::ostream& operator<<(std::ostream& os, const TList& list);
    virtual ~TList();

  private:
    std::shared_ptr<TListItem> head;
    std::shared_ptr<TListItem> tail;
    int size_l;
};

#endif // TLIST_H
