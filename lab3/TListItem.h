#ifndef TLISTITEM_H
#define TLISTITEM_H
#include <Figure.h>
#include <memory>


class TListItem
{
  public:
    TListItem(const std::shared_ptr<Figure>& figure);
    std::shared_ptr<Figure> GetPtrFigure() const;
    std::shared_ptr<Figure> GetFigure() const;
    std::shared_ptr<TListItem> SetNext(std::shared_ptr<TListItem> next);
    std::shared_ptr<TListItem> GetNext();
    std::shared_ptr<TListItem> SetPrev(std::shared_ptr<TListItem> prev);
    std::shared_ptr<TListItem> GetPrev();
    friend std::ostream& operator<<(std::ostream& os, const TListItem& obj);

    virtual ~TListItem();

  private:
    std::shared_ptr<Figure> figure;
    std::shared_ptr<TListItem> next;
    std::shared_ptr<TListItem> prev;
};

#endif // TLISTITEM_H
