#include "TList.h"
#include <memory>

template <class T, class TT> TList<T, TT>::TList() {
  head = nullptr;
  tail = nullptr;
  size_l = 0;
}

template <class T, class TT> void TList<T, TT>::RemoveSubitem(IRemoveCriteria<TT> *criteria) {
  std::cout << "------>" << std::endl;
  for (auto i : *this) {
    T copy;
    while (!i->empty()) {
      std::shared_ptr<TT> value = i->pop_front();
      if (criteria->isIt(&*value)) {
        std::cout << "List: Delete element ";
        value->Print();
        std::cout << std::endl;
      }
      else {
        if (value->GetFType() == 1) {
          copy.push_back(new Rectangle(value->GetA(), value-> GetB()));
        }
        if (value->GetFType() == 2) {
          copy.push_back(new Rhombus(value->GetA(), value->GetB()));
        }
        if (value->GetFType() == 3) {
          copy.push_back(new Trapeze(value->GetA(), value->GetB(), value->GetC()));
        }
      }
    }
    while (!copy.empty()) {
      std::shared_ptr<TT> v = copy.pop_front();
      if (v->GetFType() == 1) {
        i->push_back(new Rectangle(v->GetA(), v->GetB()));
      }
      if (v->GetFType() == 2) {
        i->push_back(new Rhombus(v->GetA(), v->GetB()));
      }
      if (v->GetFType() == 3) {
        i->push_back(new Trapeze(v->GetA(), v->GetB(), v->GetC()));
      }
    }
  }
  for (auto i : *this) {
    if (i->empty()) {
      Remove(&*i);
    }
  }
  std::cout << "!!!!" << std::endl;
}

template <class T, class TT> void TList<T, TT>::InsertSubitem(TT* v) {
  bool inserted = false;
  if (head != nullptr) {
    for (auto i : *this) {
      if (i->size() < 5) {
        if (inserted == false) {
          i->push_back(v);
          std::cout << "List: Add Element in list:" << i->size() << std::endl;
          inserted = true;
        }
      }
    }
  }
  if (!inserted) {
    std::cout << "List: New list element created" << std::endl;
    T* tv = new T();
    tv->push_back(v);
    push_b(tv);
    size_l++;
  }
}

template <class T, class TT> void TList<T, TT>::push_b(T* v) {
  std::shared_ptr<TListItem<T>> vi(new TListItem<T>(v));
  std::cout << "List: Added to list" << std::endl;
  if (head != nullptr) {
    head->push_b(vi);
  }
  else {
    head = vi;
  }
}

template <class T, class TT> bool TList<T, TT>::Remove(T* v) {
  std::shared_ptr<TListItem<T>> item = head;
  std::shared_ptr<TListItem<T>> prev = nullptr;
  bool result = false;
  while((item != nullptr) && (!result)) {
    if (item->GetValue().get() == v) {
      if (prev != nullptr) {
        prev ->SetNext(item->GetNext());
      }
      else {
        head = item->GetNext();
      }
      result = true;
    }
    else {
      prev = item;
      item = item->GetNext();
    }
  }
  return result;
}

template <class T, class TT> T TList<T, TT>::GetElement(int position) {

	int ii = 1;
	for (auto i : *this) {
		if (ii == position) {
			return *i;
		}
		ii++;
	}
}

template <class T, class TT> int TList<T, TT>::GetSize() {
	return size_l;
}

template <class T, class TT> size_t TList<T, TT>::Size() {
	size_t result = 0;
	for (auto a : *this) {
    result++;
  }
	return result;
}


template <class T, class TT> TIterator<TListItem<T>, T> TList<T, TT>::begin()
const {
	return TIterator<TListItem<T>, T>(head);
}

template <class T, class TT> TIterator<TListItem<T>, T> TList<T, TT>::end()
const {
	return TIterator<TListItem<T>, T>(nullptr);
}


template <class T, class TT> TList<T, TT>::~TList() {
	std::cout << "List: deleted" << std::endl;
}

template <class A, class AA> std::ostream& operator<<(std::ostream& os, const TList<A, AA>& list) {
	std::cout << "Queues:" << std::endl;
	int L = 1;
	for (auto i : list) {
		std::cout << "{" << L << "}{" << *i << "}" << std::endl;
		L++;
	}
	return os;
}

#include "Figure.h"
#include "TQueue.h"
template class TList<TQueue<Figure>, Figure>;
template /*<class A, class AA>*/ std::ostream& operator<<(std::ostream& os, const TList<TQueue<Figure>, Figure>& list);
