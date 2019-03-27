#include "TList.h"
#include <memory>

TList::TList() : head(nullptr), tail(nullptr), size_l(0) {}

void TList::push_f(std::shared_ptr<Figure> &&figure) {
  std::shared_ptr<TListItem> item(new TListItem(figure));
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

void TList::push_b(std::shared_ptr<Figure> &&figure) {
  std::shared_ptr<TListItem> item(new TListItem(figure));
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

void TList::ins(std::shared_ptr<Figure> && figure, int position) {
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
  std::shared_ptr<TListItem> item = head;
  for (int i = 1; i < position; i++) {
    item = item->GetNext();
  }
  std::shared_ptr<TListItem> itemPrev = item->GetPrev();
  std::shared_ptr<TListItem> newi(new TListItem(figure));
  if (itemPrev != nullptr && size_l != 1) {
    itemPrev->SetNext(newi);
  }
  newi->SetNext(item);
  newi->SetPrev(itemPrev);
  item->SetPrev(newi);
  size_l++;

}

double TList::GetSquare(int position) {
  if (position < 1 || position > size_l) {
    std::cout << '!' << std::endl;
    return 0;
  }
  std::shared_ptr<TListItem> item = head;
  for (int i = 1; i < position; i++) {
    item = item->GetNext();
  }
  std::shared_ptr<Figure> rt = item->GetFigure();
  return rt->Square();
}

bool TList::empty() {
  return (size_l == 0);
}

void TList::pop(int position) {
  if (position < 1 || position > size_l + 1) {
    std::cout << '!' << std::endl;
  }
  else if (size_l != 0){
  std::shared_ptr<TListItem> popItem = head;
  for (int i = 1; i < position; i++) {
    popItem = popItem->GetNext();
  }
  std::shared_ptr<TListItem> popPrev = popItem->GetPrev();
  std::shared_ptr<TListItem> popNext = popItem->GetNext();
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

std::ostream& operator<<(std::ostream& os, const TList& list) {
  std::shared_ptr<TListItem> item = list.head;
  for (;item != nullptr;) {
    item->GetPtrFigure()->Print();
    item = item->GetNext();
  }
  return os;
}

TList::~TList()
{
  for (int i = size_l; i > 0; i--) {
    pop(1);
  }
}
