#ifndef TLISTITEM_H
#define	TLISTITEM_H
#include <memory>
#include "Figure.h"
#include "TAllocationBlock.h"


template<class T> class TListItem {
public:
    TListItem(T *item);
    TListItem(std::shared_ptr<T> item);
    template<class A> friend std::ostream& operator<<(std::ostream& os, const TListItem<A>& obj);

    std::shared_ptr<TListItem<T>> SetNext(std::shared_ptr<TListItem> next);
    std::shared_ptr<TListItem<T>> GetNext();
    std::shared_ptr<TListItem<T>> SetPrev(std::shared_ptr<TListItem> prev);
    std::shared_ptr<TListItem<T>> GetPrev();
    std::shared_ptr<T> GetValue() const;
    void * operator new (size_t size);
    void operator delete(void *p);

    virtual ~TListItem();
private:
    std::shared_ptr<T> item;
    std::shared_ptr<TListItem<T>> next;
    std::shared_ptr<TListItem<T>> prev;
    size_t max_blocks = 4;
    static TAllocationBlock TListItem_Allocator;

};

#endif
