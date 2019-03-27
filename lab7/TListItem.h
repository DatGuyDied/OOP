#ifndef TLISTITEM_H
#define TLISTITEM_H
#include <Figure.h>
#include <memory>
#include "TAllocationBlock.h"


template <class T> class TListItem
{
  public:
    TListItem(T *item);
    std::shared_ptr<TListItem<T>> SetNext(std::shared_ptr<TListItem> next);
    std::shared_ptr<TListItem<T>> GetNext();
    std::shared_ptr<TListItem<T>> SetPrev(std::shared_ptr<TListItem> prev);
    std::shared_ptr<TListItem<T>> GetPrev();
    void push_b(std::shared_ptr<TListItem<T>> next);
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TListItem<A>& obj);
    std::shared_ptr<T> GetValue();
    virtual ~TListItem();

  private:
    std::shared_ptr<T> item;
    std::shared_ptr<TListItem> next;
    std::shared_ptr<TListItem> prev;
};

#endif // TLISTITEM_H
