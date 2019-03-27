#include "TList.h"
#include <exception>
#include <memory>
#include <mutex>
#include <thread>

std::mutex mt;

template <class T> TList<T>::TList() : head(nullptr), tail(nullptr), size_l(0) {}

template <class T> std::shared_ptr<T> TList<T>::operator[](size_t i) {
    if (i > size() - 1) throw std::invalid_argument("index greater then stack size");
    size_t j = 0;

    for (std::shared_ptr<T> a : * this) {
        if (j == i) return a;
        j++;
    }

    return std::shared_ptr<T>(nullptr);
}

template <class T> void TList<T>::sort() {
    if (size() > 1) {
        std::shared_ptr<T> middle = pop_f();
        TList<T> left, right;

        while (!empty()) {
            std::shared_ptr<T> item = pop_f();
            if (*item < *middle) {
                left.push_f(item);
            } else {
                right.push_f(item);
            }
        }

        left.sort();
        right.sort();

        while (!left.empty()) push_f(left.pop_b());
        push_f(middle);
        while (!right.empty()) push_f(right.pop_b());

    }
}

template<class T > std::future<void> TList<T>::sort_in_background() {
    std::lock_guard<std::mutex> locker(mt);
    std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TList<T>::sort_parallel), this));
    std::future<void> res(task.get_future());
    std::thread th(std::move(task));
    th.detach();
    return res;
}

template <class T> void TList<T>::sort_parallel() {
    if (size() > 1) {
        std::shared_ptr<T> middle = pop_b();
        TList<T> left, right;

        while (!empty()) {
            std::shared_ptr<T> item = pop_b();
            if (*item < *middle) {
                left.push_f(item);
            } else {
                right.push_f(item);
            }
        }

        std::future<void> left_res = left.sort_in_background();
        std::future<void> right_res = right.sort_in_background();


        left_res.get();


        while (!left.empty()) push_f(left.pop_b());
        push_f(middle);

        right_res.get();
        while (!right.empty()) push_f(right.pop_b());

    }
    return;
}

template <class T> std::ostream& operator<<(std::ostream& os, const TList<T>& list) {

    std::shared_ptr<TListItem < T>> item = list.head;

    while (item != nullptr) {
        item->GetPFigure()->Print();
        if (item->GetNext() != nullptr) {os << '-';}
        item = item->GetNext();
    }

    return os;
}

template <class T> void TList<T>::push_f(T *item) {
    std::shared_ptr<TListItem < T >> other(new TListItem<T>(item));
    other->SetNext(head);
    other->SetPrev(nullptr);
    if (head != nullptr) {
      head->SetPrev(other);
    }
    if (size_l == 0) {
      head = other;
      tail = other;
    }
    else {head = other;}
    size_l++;
}

template <class T> void TList<T>::push_f(std::shared_ptr<T> item) {
    std::shared_ptr<TListItem < T >> other(new TListItem<T>(item));
    other->SetNext(head);
    other->SetPrev(nullptr);
    if (head != nullptr) {
      head->SetPrev(other);
    }
    if (size_l == 0) {
      head = other;
      tail = other;
    }
    else {head = other;}
    size_l++;
}

template <class T> void TList<T>::push_b(T* item) {
    std::shared_ptr<TListItem < T >> other(new TListItem<T>(item));
    other->SetNext(nullptr);
    other->SetPrev(tail);
    if (tail != nullptr) {
      tail->SetNext(other);
    }
    if (size_l == 0) {
      head = other;
      tail = other;
    }
    else {tail = other;}
    size_l++;
}

template <class T> void TList<T>::push_b(std::shared_ptr<T> item) {
    std::shared_ptr<TListItem < T >> other(new TListItem<T>(item));
    other->SetNext(nullptr);
    other->SetPrev(tail);
    if (tail != nullptr) {
      tail->SetNext(other);
    }
    if (size_l == 0) {
      head = other;
      tail = other;
    }
    else {tail = other;}
    size_l++;
}

template <class T> void TList<T>::ins(std::shared_ptr<T> item, int p) {
  if (p < 1 || p > size_l + 1) {
    std::cout << "?!" << std::endl;
    return;
  }
  if (p == size_l + 1) {
    push_b(std::move(item));
    return;
  }
  else if (p == 1) {
    push_f(std::move(item));
    return;
  }
  std::shared_ptr<TListItem<T>> it = head;

  for (int i = 1; i < p; i++) {
    it =  it->GetNext();
  }

  std::shared_ptr<TListItem<T>> itPrev = it->GetPrev();
  std::shared_ptr<TListItem<T>> insItem(new TListItem<T>(item));
  if (itPrev != nullptr && size_l != 1) {
    itPrev->SetNext(insItem);
  }
  insItem->SetNext(it);
  insItem->SetPrev(itPrev);
  it->SetPrev(insItem);
  size_l++;
  return;
}

template <class T> void TList<T>::ins(T* item, int p) {
  if (p < 1 || p > size_l + 1) {
    std::cout << "?!" << std::endl;
    return;
  }
  if (p == size_l + 1) {
    push_b(std::move(item));
    return;
  }
  else if (p == 1) {
    push_f(std::move(item));
    return;
  }
  std::shared_ptr<TListItem<T>> it = head;

  for (int i = 1; i < p; i++) {
    it = it->GetNext();
  }

  std::shared_ptr<TListItem<T>> itPrev = it->GetPrev();
  std::shared_ptr<TListItem<T>> insItem(new TListItem<T>(item));
  if (itPrev != nullptr && size_l != 1) {
    itPrev->SetNext(insItem);
  }
  insItem->SetNext(it);
  insItem->SetPrev(itPrev);
  it->SetPrev(insItem);
  size_l++;
  return;
}

template <class T> size_t TList<T>::GetSquare(int p) {
  if (p < 1 || p > size_l + 1) {
    std::cout << "?!" << std::endl;
    return 0;
  }
  std::shared_ptr<TListItem<T>> it = head;
  for (int i = 1; i < p; i++) {
    it = it->GetNext();
  }
  std::shared_ptr<T> res = it->GetValue();
  return res->Square();
}

template <class T> bool TList<T>::empty() {
    return head == nullptr;
}

template <class T> void TList<T>::pop(int p) {
  if (p < 1 || p > size_l) {
    std::cout << "?!" << std::endl;
    return;
  }
  std::shared_ptr<TListItem<T>> popItem = head;
  for (int i = 0; i < p; i++) {
    popItem = popItem->GetNext();
  }

  std::shared_ptr<TListItem<T>> popPrev = popItem->GetPrev();
  std::shared_ptr<TListItem<T>> popNext = popItem->GetNext();
  if (popPrev != nullptr && size_l != 1) {
    popPrev->SetNext(popNext);
  }
  if (popNext != 0 && size_l != 1) {
    popNext->SetPrev(popPrev);
  }
  if (p == 1) {
    head = popNext;
  }
  if (p = size_l) {
    tail = popPrev;
  }

  popItem = nullptr;
  size_l--;
  return;
}

template <class T> std::shared_ptr<T> TList<T>::pop_f() {
  std::shared_ptr<T> res;
  if (head != nullptr) {
    res = head->GetValue();
    head = head->GetNext();
  }
  size_l--;
  return res;
}

template <class T> std::shared_ptr<T> TList<T>::pop_b() {
    std::shared_ptr<T> res;

    if (head != nullptr) {
        std::shared_ptr<TListItem < T>> element = head;
        std::shared_ptr<TListItem < T>> prevIt = nullptr;

        while (element->GetNext() != nullptr) {
            prevIt = element;
            element = element->GetNext();
        }

        if (prevIt != nullptr) {
            prevIt->SetNext(nullptr);
            tail = prevIt;
            res = element->GetValue();

        } else {
            res = element->GetValue();
            head = nullptr;
            tail = nullptr;
        }
    }
    size_l--;
    return res;

}

template <class T> size_t TList<T>::size() {

    int result = 0;
    for (auto i : * this) result++;
    return result;
}

template <class T> TIterator<TListItem<T>, T> TList<T>::begin() {
    return TIterator<TListItem<T>, T>(head);
}

template <class T> TIterator<TListItem<T>, T> TList<T>::end() {
    return TIterator<TListItem<T>, T>(nullptr);
}

template <class T> TList<T>::~TList() {
    for (; head != nullptr;) {
      pop(1);
    }
    tail = nullptr;
}

#include "Figure.h"
template class TList<Figure>;
template std::ostream& operator<<(std::ostream& os, const TList<Figure>& list);
