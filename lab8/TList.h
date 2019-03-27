#ifndef TLIST_H
#define	TLIST_H
#include "TIterator.h"
#include "TListItem.h"
#include <memory>
#include <future>
#include <mutex>
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "Figure.h"

template <class T> class TList {
public:
    TList();

    void push_b(T* item);
    void push_f(T* item);
    void push_b(std::shared_ptr<T> item);
    void push_f(std::shared_ptr<T> item);
    void ins(T* item, int p);
    void ins(std::shared_ptr<T> item, int p);
    size_t GetSquare(int p);
    bool empty();
    void pop(int p);
    size_t size();

    TIterator<TListItem<T>,T> begin();
    TIterator<TListItem<T>,T> end();

    std::shared_ptr<T> operator[] (size_t i);
    void sort();
    void sort_parallel();

    std::shared_ptr<T> pop_b();
    std::shared_ptr<T> pop_f();
    template <class A> friend std::ostream& operator<<(std::ostream& os,const TList<A>& list);
    virtual ~TList();
private:
    std::future<void> sort_in_background();
    std::shared_ptr<TListItem<T>> head;
    std::shared_ptr<TListItem<T>> tail;
    int size_l;

};

#endif
