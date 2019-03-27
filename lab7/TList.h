#ifndef TLIST_H
#define	TLIST_H
#include <memory>
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "Figure.h"
#include "TListItem.h"
#include "TIterator.h"
#include "IRemoveCriteria.h"

template <class T, class TT> class TList {

public:
    TList();

    void InsertSubitem(TT* value);
    void RemoveSubitem(IRemoveCriteria<TT> * criteria);
    void push_b(T* value);
    size_t Size();
    bool Remove(T* value);
    T GetElement(int position);
    int GetSize();
    TIterator<TListItem<T>, T> begin() const;
    TIterator<TListItem<T>, T> end() const;
    template <class A, class AA> friend std::ostream& operator<<(std::ostream& os, const TList<A, AA>& list);

    virtual ~TList();
private:
    std::shared_ptr<TListItem<T>> head;
    std::shared_ptr<TListItem<T>> tail;
    int size_l;
};

#endif
