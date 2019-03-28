#include <cstdlib>
#include <iostream>
#include "Rectangle.h"
#include "TListItem.h"
#include "TList.h"
#include <memory>

using namespace std;

void PrintMenu() {
  cout << "Menu:" << endl;
  cout << "0. Print menu" << endl;
  cout << "1. Add" << endl;
  cout << "2. Pop" << endl;
  cout << "3. Is empty?" << endl;
  cout << "4. Print square" << endl;
  cout << "5. Print list" << endl;
  cout << "6. Delete list" << endl;
  cout << "7. Exit" << endl;
}

int main(int argc, char** argv) {


	TList<Figure> list;
	shared_ptr<Figure> figure;
  PrintMenu();
	for (int i;;) {
    cout << ':';
    cin >> i;
    if (i == 0) {PrintMenu();}

		else if (i == 1) {
			std::cout << "How many?" << endl;
			int hm;
			std::cin >> hm;
			for (int i = 0; i < hm; ++i) {
				std::cout << "1. Push front" << endl;
				std::cout << "2. Push back" << endl;
				std::cout << "3. Insert" << endl;
				int ii;
				std::cin >> ii;
				if (ii == 1) {
          int f;
          cout << "1. Rectangle" << endl;
          cout << "2. Rhombus" << endl;
          cout << "3. Trapeze" << endl;;
          cin >> f;
          if (f == 1) {
            cout << "Enter Rectangle:" << endl;
            int a, b;
            cin >> a >> b;
            figure = make_shared<Rectangle> (Rectangle(a, b));
          }
          if (f == 2) {
            cout << "Enter Rhombus:" << endl;
            int a, h;
            cin >> a >> h;
            figure = make_shared<Rhombus> (Rhombus(a, h));
          }
          if (f == 3) {
            cout << "Enter Trapeze:" << endl;
            int a, b, h;
            cin >> a >> b >> h;
            figure = make_shared<Trapeze> (Trapeze(a, b, h));
          }
          list.push_f(move(figure));
				}
				if (ii == 2) {
          int f;
          cout << "1. Rectangle" << endl;
          cout << "2. Rhombus" << endl;
          cout << "3. Trapeze" << endl;;
          cin >> f;
          if (f == 1) {
            cout << "Enter Rectangle:" << endl;
            int a, b;
            cin >> a >> b;
            figure = make_shared<Rectangle> (Rectangle(a, b));
          }
          if (f == 2) {
            cout << "Enter Rhombus:" << endl;
            int a, h;
            cin >> a >> h;
            figure = make_shared<Rhombus> (Rhombus(a, h));
          }
          if (f == 3) {
            cout << "Enter Trapeze:" << endl;
            int a, b, h;
            cin >> a >> b >> h;
            figure = make_shared<Trapeze> (Trapeze(a, b, h));
          }
          list.push_b(move(figure));
				}
				if (ii == 3) {
          int f;
          cout << "1. Rectangle" << endl;
          cout << "2. Rhombus" << endl;
          cout << "3. Trapeze" << endl;;
          cin >> f;
          if (f == 1) {
            cout << "Enter Rectangle:" << endl;
            int a, b;
            cin >> a >> b;
            figure = make_shared<Rectangle> (Rectangle(a, b));
          }
          if (f == 2) {
            cout << "Enter Rhombus:" << endl;
            int a, h;
            cin >> a >> h;
            figure = make_shared<Rhombus> (Rhombus(a, h));
          }
          if (f == 3) {
            cout << "Enter Trapeze:" << endl;
            int a, b, h;
            cin >> a >> b >> h;
            figure = make_shared<Trapeze> (Trapeze(a, b, h));
          }
          cout << "Enter position:" << endl;
          int p;
          cin >> p;
          list.ins(move(figure), p);
				}
			}
		}
		else if (i == 2) {
			int p;
			cout << "Enter position:" << endl;
			cin >> p;
			list.pop(p);
		}
		else if (i == 3) {
      if (list.empty()) {cout << "YES" << endl;}
      else {cout << "NO" << endl;}
		}
		else if (i == 4) {
      cout << "Enter position:" << endl;
      int p;
      cin >> p;
      cout << list.GetSquare(p) << endl;
		}
		else if (i == 5) {
			for (auto i : list) {i->Print();}
		}
		else if (i == 6) {
			list.~TList();
		}
		else if (i == 7) {
      break;
		}
		else {cout << "?!" << endl;}

	}
    return 0;
}
