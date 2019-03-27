#include <iostream>
#include "TList.h"
#include "TListItem.h"
#include "Rectangle.h"

using namespace std;

void PrintMenu() {
  cout << "Menu:" << endl;
  cout << "0. Print Menu" << endl;
  cout << "1. Push front" << endl;
  cout << "2. Push back" << endl;
  cout << "3. Insert" << endl;
  cout << "4. Is empty?" << endl;
  cout << "5. Pop" << endl;
  cout << "6. Print square" << endl;
  cout << "7. Print list" << endl;
  cout << "8. Delete list" << endl;
  cout << "9. Exit" << endl;
}

int main()
{
  TList lst;
  PrintMenu();
  for (int flag;;) {
    cout << ':';
    cin >> flag;
    if (flag == 0) {
      PrintMenu();
    }
    if (flag == 1) {
      cout << "Enter Rectangle:" << endl;
      Rectangle rec;
      cin >> rec;
      lst.push_f(move(rec));
    }
    if (flag == 2) {
      cout << "Enter Rectangle:" << endl;
      Rectangle rec;
      cin >> rec;
      lst.push_b(move(rec));
    }
    if (flag == 3) {
      cout << "Enter Rectangle and position:" << endl;
      int p;
      Rectangle rec;
      cin >> rec >> p;
      lst.ins(move(rec), p);
    }
    if (flag == 4) {
      if (lst.empty()) {
        cout << "YES" << endl;
      }
      else {
        cout << "NO" << endl;
      }
    }
    if (flag == 5) {
      cout << "Enter position:" << endl;
      int p;
      cin >> p;
      lst.pop(p);
    }
    if (flag == 6) {
      cout << "Enter position:" << endl;
      int p;
      cin >> p;
      cout << lst.GetSquare(p) << endl;
    }
    if (flag == 7) {
      cout << lst << endl;
    }
    if (flag == 8) {
      cout << "List deleted" << endl;
      lst.~TList();
    }
    if (flag == 9) {
      break;
    }
  }

  return 0;
}
