#ifndef TLISTITEM_H
#define TLISTITEM_H
#include "Rectangle.h"


class TListItem {
  public:
    TListItem(const Rectangle& rec);
    TListItem(const TListItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const TListItem& obj);

    TListItem* SetNext(TListItem* next);
    TListItem* GetNext();
    TListItem* SetPrev(TListItem* prev);
    TListItem* GetPrev();
    Rectangle GetRectangle() const;
    virtual ~TListItem();

  private:
    Rectangle rec;
    TListItem *next;
    TListItem *prev;
};

#endif // TLISTITEM_H
