#include "TListItem.h"
#include <iostream>
#include <memory>

template <class T> TListItem<T>::TListItem(T* item) {
  this->item = std::shared_ptr<T>(item);
  this->next = nullptr;
  this->prev = nullptr;
}

template <class T> TListItem<T>::TListItem(std::shared_ptr<T> item) {
    this->item = item;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T> TAllocationBlock TListItem<T>::TListItem_Allocator(sizeof(TListItem<T>), 4);

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> next) {
    std::shared_ptr<TListItem < T>> old = this->next;
    this->next = next;
    return old;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::SetPrev(std::shared_ptr<TListItem<T>> prev) {
    std::shared_ptr<TListItem < T>> old = this->prev;
    this->prev = prev;
    return old;
}

template <class T> std::shared_ptr<T> TListItem<T>::GetValue() const {
    return this->item;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() {
    return this->next;
}

template <class T> std::shared_ptr<TListItem<T>> TListItem<T>::GetPrev() {
    return this->prev;
}

template <class T> TListItem<T>::~TListItem() {}

template <class A> std::ostream& operator<<(std::ostream& os, const TListItem<A>& obj) {
    obj.GetFigure()->Print();
    if (obj.GetNext() != nullptr) {
      os << '-';
    }
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

#include "Figure.h"
template class TListItem<Figure>;
template <class A> std::ostream& operator<<(std::ostream& os, const TListItem<Figure>& obj);
