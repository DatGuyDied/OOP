#include "TListItem.h"
#include <iostream>
#include <memory>
#include <cstdlib>

template <class T> TListItem<T>::TListItem(const std::shared_ptr<T>& figure) {
  this->figure = figure;
  this->next = nullptr;
  this->prev = nullptr;
}

template <class T> TAllocationBlock TListItem<T>::TListItem_Allocator(sizeof(TListItem<T>), 4);

template <class T> std::shared_ptr<T> TListItem<T>::GetPtrFigure() const {
  return this->figure;
}

template <class T> std::shared_ptr<T> TListItem<T>::GetFigure() const {
  return figure;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> next) {
  std::shared_ptr<TListItem<T>> old = this->next;
  this->next = next;
  return old;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() {
  return this->next;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::SetPrev(std::shared_ptr<TListItem<T>> prev) {
  std::shared_ptr<TListItem<T>> old = this->prev;
  this->prev = prev;
  return old;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::GetPrev() {
  return this->prev;
}

template <class A> std::ostream& operator<<(std::ostream& os, TListItem<A>& obj) {
  obj.GetPtrFigure()->Print();
  return os;
}

template <class T> void * TListItem<T>::operator new (size_t size) {
  if (TListItem_Allocator.has_free_blocks()) {
    return TListItem_Allocator.allocate();
  }
  else {
    TListItem_Allocator.reallocate();
    return TListItem_Allocator.allocate();
  }
}

template <class T> void TListItem<T>::operator delete(void *p) {
  TListItem_Allocator.deallocate(p);
}

template <class T> TListItem<T>::~TListItem()
{
}

#include "Figure.h"
template class TListItem<Figure>;
template <class A> std::ostream& operator<<(std::ostream& os, const TListItem<Figure>& obj);
