#include "TListItem.h"
#include <iostream>
#include <memory>
#include <cstdlib>

template <class T> TListItem<T>::TListItem(T* _item) {
  item = std::shared_ptr<T> (_item);
  next = nullptr;
  prev = nullptr;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> _next) {
  std::shared_ptr<TListItem<T>> old = _next;
  next = _next;
  return old;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() {
  return next;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::SetPrev(std::shared_ptr<TListItem<T>> _prev) {
  std::shared_ptr<TListItem<T>> old = prev;
  prev = _prev;
  return old;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::GetPrev() {
  return prev;
}

template <class A> std::ostream& operator<<(std::ostream& os, TListItem<A>& obj) {
  obj.GetFigure()->Print();
  return os;
}

template <class T> std::shared_ptr<T> TListItem<T>::GetValue() {
  return item;
}

template <class T> void TListItem<T>::push_b(std::shared_ptr<TListItem> _next) {
  if (next != nullptr) {
    next->push_b(_next);
  }
  else {
    next = _next;
  }
}

template <class T> TListItem<T>::~TListItem()
{
}

#include "TQueue.h"
#include "Figure.h"
template class TListItem<TQueue<Figure>>;
template class TListItem<Figure>;
