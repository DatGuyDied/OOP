#ifndef TLIST_H
#define TLIST_H
#include "TListItem.h"
#include "Rectangle.h"

class TList {
  public:
    TList();
    TList(const TList& orig);
    void push_f(Rectangle &&rec);
    void push_b(Rectangle &&rec);
    void ins(Rectangle &&rec, int position);
    bool empty();
    void pop(int position);
    friend std::ostream& operator<<(std::ostream& os, const TList& list);
    double GetSquare(int position);
    virtual ~TList();
  private:
    TListItem *head;
    TListItem *tail;
    int size_l;

};

#endif // TLIST_H
