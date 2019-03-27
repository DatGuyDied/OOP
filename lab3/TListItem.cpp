#include "TListItem.h"
#include <iostream>
#include <memory>

TListItem::TListItem(const std::shared_ptr<Figure>& figure) {
  this->figure = figure;
  this->next = nullptr;
  this->prev = nullptr;
}

std::shared_ptr<Figure> TListItem::GetPtrFigure() const {
  return this->figure;
}

std::shared_ptr<Figure> TListItem::GetFigure() const {
  return figure;
}

std::shared_ptr<TListItem> TListItem::SetNext(std::shared_ptr<TListItem> next) {
  std::shared_ptr<TListItem> old = this->next;
  this->next = next;
  return old;
}

std::shared_ptr<TListItem> TListItem::GetNext() {
  return this->next;
}

std::shared_ptr<TListItem> TListItem::SetPrev(std::shared_ptr<TListItem> prev) {
  std::shared_ptr<TListItem> old = this->prev;
  this->prev = prev;
  return old;
}

std::shared_ptr<TListItem> TListItem::GetPrev() {
  return this->prev;
}

std::ostream& operator<<(std::ostream& os, TListItem& obj) {
  obj.GetPtrFigure()->Print();
  return os;
}

TListItem::~TListItem()
{
}
