#include "TList.h"

TList::TList() : head(nullptr), tail(nullptr), size_l(0){}

TList::TList(const TList& orig) {
  head = orig.head;
  tail = orig.tail;
  size_l = orig.size_l;
}

void TList::push_f(Rectangle &&rec) {
  TListItem *item = new TListItem(rec);
  item->SetPrev(nullptr);
  item->SetNext(head);
  if (head != nullptr) {
    head->SetPrev(item);
  }
  if (size_l == 0) {
    head = item;
    tail = item;
  }
  else {
    head = item;
  }
  size_l++;
  return;
}

void TList::push_b(Rectangle &&rec) {
  TListItem *item = new TListItem(rec);
  item->SetPrev(tail);
  item->SetNext(nullptr);
  if (tail != nullptr) {
    tail->SetNext(item);
  }
  if (size_l == 0) {
    head = item;
    tail = item;
  }
  else {
    tail = item;
  }
  size_l++;
  return;
}

void TList::ins(Rectangle &&rec, int position) {
  if (position < 1 || position > size_l + 1) {
    return;
  }
  if (position == 1) {
    push_f(std::move(rec));
    return;
  }
  if (position == size_l + 1) {
    push_b(std::move(rec));
    return;
  }
  TListItem *i2 = head;
  for (int i = 1; i < position; i++) {
    i2 = i2->GetNext();
  }
  TListItem *i1 = i2->GetPrev();
  TListItem *item = new TListItem(rec);
  i1->SetNext(item);
  i2->SetPrev(item);
  item->SetNext(i2);
  item->SetPrev(i1);
  size_l++;
}

bool TList::empty() {
  return (size_l == 0);
}

void TList::pop(int position) {
  if (position < 1 || position > size_l) {
    std::cout << '!' << std::endl;
    return;
  }
  TListItem *popItem = head;
  for (int i = 1; i < position; i++) {
    popItem = popItem->GetNext();
  }
  TListItem *popPrev = popItem->GetPrev();
  TListItem *popNext = popItem->GetNext();

  if (position == 1) {
    head = popNext;
  }
  else if (position == size_l) {
    tail = popPrev;
  }
  else {
      if (popPrev != nullptr && size_l != 1) {
        popPrev->SetNext(popNext);
      }
      if (popNext != nullptr && size_l != 1) {
        popNext->SetPrev(popPrev);
      }
  }
  popItem = nullptr;
  size_l--;
  return;
}

std::ostream& operator<<(std::ostream& os, const TList& list) {
  TListItem *item = list.head;
  for (; item !=  nullptr;) {
    os << *item;
    item = item->GetNext();
  }
  return os;
}

double TList::GetSquare(int position) {
  if (position < 1 || position > size_l + 1) {
    std::cout << '!' << std::endl;
    return 0;
  }
  TListItem *item = head;
  for (int i = 1; i < position; i++) {
    item = item->GetNext();
  }
  Rectangle rt = item->GetRectangle();
  return rt.Square();
}

TList::~TList()
{
  for (int i = size_l; i > 0; i--) {
    pop(1);
  }
}
