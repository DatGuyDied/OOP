#ifndef TLISTITEM_H
#define TLISTITEM_H
#include <Figure.h>
#include <memory>
#include "TAllocationBlock.h"


template <class T> class TListItem
{
  public:
    TListItem(const std::shared_ptr<T>& figure);
    std::shared_ptr<T> GetPtrFigure() const;
    std::shared_ptr<T> GetFigure() const;
    std::shared_ptr<TListItem<T>> SetNext(std::shared_ptr<TListItem> next);
    std::shared_ptr<TListItem<T>> GetNext();
    std::shared_ptr<TListItem<T>> SetPrev(std::shared_ptr<TListItem> prev);
    std::shared_ptr<TListItem<T>> GetPrev();
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TListItem<A>& obj);
    void * operator new (size_t size);
    void operator delete(void *p);
    virtual ~TListItem();

  private:
    std::shared_ptr<T> figure;
    std::shared_ptr<TListItem<T>> next;
    std::shared_ptr<TListItem<T>> prev;
    size_t _max_blocks = 4;
    static TAllocationBlock TListItem_Allocator;
};

#endif // TLISTITEM_H
