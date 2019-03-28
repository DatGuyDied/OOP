#include <cstdlib>
#include <iostream>
#include "Rectangle.h"
#include "TListItem.h"
#include "TList.h"
#include <memory>

using namespace std;

void PrintMenu() {
  cout << "Menu:" << endl;
  cout << "0. Print menu:" << endl;
  cout << "1. Push front" << endl;
  cout << "2. Push back" << endl;
  cout << "3. Insert" << endl;
  cout << "4. Print square" << endl;
  cout << "5. Is empty?" << endl;
  cout << "6. Pop" << endl;
  cout << "7. Print list" << endl;
  cout << "8. Delete list" << endl;
  cout << "9. Exit" << endl;
}

int main(int argc, char** argv) {


	TList list;
	shared_ptr<Figure> figure;
  PrintMenu();
	for (int i;;) {
    cout << ':';
    cin >> i;
    if (i == 0) {PrintMenu();}

		else if (i == 1) {
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

		else if (i == 2) {
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

		else if (i == 3) {
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
		else if (i == 4) {
			int p;
			cout << "Enter position:" << endl;
			cin >> p;
			cout << list.GetSquare(p) << endl;
		}
		else if (i == 5) {
      if (list.empty()) {cout << "YES" << endl;}
      else {cout << "NO" << endl;}
		}
		else if (i == 6) {
			cout << "Enter position:" << endl;
			int p;
			cin >> p;
			list.pop(p);
		}
		else if (i == 7) {
			cout << list;
		}
		else if (i == 8) {
			list.~TList();
		}
		else if (i == 9) {
      break;
		}
		else {cout << "?!" << endl;}

	}


    return 0;
}
