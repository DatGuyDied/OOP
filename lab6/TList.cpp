#include "TList.h"
#include <memory>

template <class T> TList<T>::TList() : head(nullptr), tail(nullptr), size_l(0) {}

template <class T> void TList<T>::push_f(std::shared_ptr<T> &&figure) {
  std::shared_ptr<TListItem<T>> item(new TListItem<T>(figure));
  item->SetPrev(nullptr);
  item->SetNext(head);
  if (head != nullptr) {
    head->SetPrev(item);
  }
  if (size_l == 0) {
    head = item;
    tail = item;
  }
  else {head = item;}
  size_l++;
}

template <class T> void TList<T>::push_b(std::shared_ptr<T> &&figure) {
  std::shared_ptr<TListItem<T>> item(new TListItem<T>(figure));
  item->SetPrev(tail);
  item->SetNext(nullptr);
  if (tail != nullptr) {
    tail->SetNext(item);
  }
  if (size_l == 0) {
    head = item;
    tail = item;
  }
  else {tail = item;}
  size_l++;
}

template <class T> void TList<T>::ins(std::shared_ptr<T> && figure, int position) {
  if (position < 1 || position > size_l + 1) {
    std::cout << '!' << std::endl;
    return;
  }
  if (position == 1) {
    push_f(std::move(figure));
    return;
  }
  else if (position == size_l + 1) {
    push_b(std::move(figure));
    return;
  }
  std::shared_ptr<TListItem<T>> item = head;
  for (int i = 1; i < position; i++) {
    item = item->GetNext();
  }
  std::shared_ptr<TListItem<T>> itemPrev = item->GetPrev();
  std::shared_ptr<TListItem<T>> newi(new TListItem<T>(figure));
  if (itemPrev != nullptr && size_l != 1) {
    itemPrev->SetNext(newi);
  }
  newi->SetNext(item);
  newi->SetPrev(itemPrev);
  item->SetPrev(newi);
  size_l++;

}

template <class T> double TList<T>::GetSquare(int position) {
  if (position < 1 || position > size_l + 1) {
    std::cout << '!' << std::endl;
    return 0;
  }
  std::shared_ptr<TListItem<T>> item = head;
  for (int i = 1; i < position; i++) {
    item = item->GetNext();
  }
  std::shared_ptr<T> rt = item->GetFigure();
  return rt->Square();
}

template <class T> bool TList<T>::empty() {
  return (size_l == 0);
}

template <class T> void TList<T>::pop(int position) {
  if (position < 1 || position > size_l + 1) {
    std::cout << '!' << std::endl;
  }
  else if (size_l != 0){
  std::shared_ptr<TListItem<T>> popItem = head;
  for (int i = 1; i < position; i++) {
    popItem = popItem->GetNext();
  }
  std::shared_ptr<TListItem<T>> popPrev = popItem->GetPrev();
  std::shared_ptr<TListItem<T>> popNext = popItem->GetNext();
  if (popPrev != nullptr && size_l != 1) {
    popPrev->SetNext(popNext);
  }
  if (popNext != nullptr && size_l != 1) {
    popNext->SetPrev(popPrev);
  }
  if (position == 1) {
    head = popNext;
  }
  if (position == size_l) {
    tail = popPrev;
  }
  popItem = nullptr;
  size_l--;
  return;}
}

template <class T> std::ostream& operator<<(std::ostream& os, const TList<T>& list) {
  std::shared_ptr<TListItem<T>> item = list.head;
  for (;item != nullptr;) {
    item->GetPtrFigure()->Print();
    item = item->GetNext();
  }
  return os;
}

template <class T> TIterator<TListItem<T>, T> TList<T>::begin() {
  return TIterator<TListItem<T>, T> (head);
}

template <class T> TIterator<TListItem<T>, T> TList<T>::end() {
  return TIterator<TListItem<T>, T> (nullptr);
}

template <class T> TList<T>::~TList()
{
  for (int i = size_l; i > 0; i--) {
    pop(1);
  }
}

#include "Figure.h"
template class TList<Figure>;
template std::ostream& operator<<(std::ostream& os, const TList<Figure>& list);
