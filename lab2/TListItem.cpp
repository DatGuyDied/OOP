#include "TListItem.h"
#include <iostream>

TListItem::TListItem(const Rectangle& rec) {
  this->rec = rec;
  this->next = nullptr;
  this->prev = nullptr;
}

TListItem::TListItem(const TListItem& orig) {
  this->rec = orig.rec;
  this->next = orig.next;
  this->prev = orig.prev;
}

std::ostream& operator<<(std::ostream& os, const TListItem& obj) {
  os << '[' << obj.rec << ']' << std::endl;
  return os;
}

TListItem* TListItem::SetNext(TListItem* next) {
  TListItem* old = this->next;
  this->next = next;
  return old;
}

TListItem* TListItem::GetNext() {
  return this->next;
}

TListItem* TListItem::SetPrev(TListItem* prev) {
  TListItem* old = this->prev;
  this->prev = prev;
  return old;
}

TListItem* TListItem::GetPrev() {
  return this->prev;
}

Rectangle TListItem::GetRectangle() const {
  return this->rec;
}

TListItem::~TListItem()
{
  delete next;
}
