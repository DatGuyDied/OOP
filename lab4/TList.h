#ifndef TLIST_H
#define TLIST_H
#include <memory>
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "TListItem.h"

template <class T> class TList
{
  public:
    TList();
    void push_f(std::shared_ptr<T> &&item);
    void push_b(std::shared_ptr<T> &&item);
    void ins(std::shared_ptr<T> &&item, int position);
    double GetSquare(int position);
    bool empty();
    void pop(int position);
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TList<A>& list);
    virtual ~TList();

  private:
    std::shared_ptr<TListItem<T>> head;
    std::shared_ptr<TListItem<T>> tail;
    int size_l;
};

#endif // TLIST_H
