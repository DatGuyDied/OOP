#ifndef TLIST_H
#define TLIST_H
#include <memory>
#include <mutex>
#include <thread>
#include <future>
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "TListItem.h"
#include "TIterator.h"

template <class T> class TList
{
  public:
    TList();
    void push_f(T* item);
    void push_b(T* item);
    void push_f(std::shared_ptr<T> item);
    void push_b(std::shared_ptr<T> item);
    void ins(T* item, int p);
    void ins(std::shared_ptr<T> item, int p);
    size_t GetSquare(int p);
    bool empty();
    size_t size();
    void pop(int p);
    std::shared_ptr<T> pop_f();
    std::shared_ptr<T> pop_b();
    TIterator<TListItem<T>, T> begin();
    TIterator<TListItem<T>, T> end();
    std::shared_ptr<T> operator[] (size_t i);
    void sort();
    void sort_parallel();
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TList<A>& list);
    virtual ~TList();

  private:
    std::future<void> sort_in_background();
    std::shared_ptr<TListItem<T>> head;
    std::shared_ptr<TListItem<T>> tail;
    int size_l;
};

#endif // TLIST_H
