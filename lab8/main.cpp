#include <iostream>
#include <cstdlib>
#include <memory>
#include <random>
#include <mutex>
#include <thread>
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "Figure.h"
#include "TList.h"


using namespace std;

void PrintMenu(){
  cout << "Menu:" << endl;
  cout << "0. Print Menu" << endl;
  cout << "1. Add" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Delete" << endl;
	cout << "4. Print List" << endl;
	cout << "5. Print Square" << endl;
	cout << "6. Add Random Elements" << endl;
	cout << "7. Sort" << endl;
	cout << "8. Exit" << endl;
}

int main(int argc, char** argv)
{
	int a, b, c;
	int Fig;
  PrintMenu();
	int allocated_blocks = 5;

	TList<Figure> list;
	shared_ptr<Figure> f;
	default_random_engine generator;
	uniform_int_distribution<int> genFigure(1, 3);


	for (;;) {
    cout << ':' << endl;
		int flag = 0;
		int flag2 = 0;
		int Fig_ = 0;
		cin >> flag;
		if (flag == 0) {
      PrintMenu();
		}
		if (flag == 1) {
			cout << "How many?" << endl;
			int k;
			cin >> k;
			for (int i = 0; i < k; i++) {
				cout << "1. Push front" << endl;
				cout << "2. Push back" << endl;
				cout << "3. Insert" << endl;
				cin >> flag2;
				if (flag2 == 1) {
					cout << "1. Rectangle" << endl;
					cout << "2. Rhombus" << endl;
					cout << "3. Trapeze" << endl;
					cin >> Fig;
					if (Fig == 1) {
						cout << "Enter Rectangle:" << endl;
					}
					if (Fig == 2) {
						cout << "Enter Rhombus:" << endl;
					}
					if (Fig == 3) {
						cout << "Enter Trapeze:" << endl;
					}
					cin >> a >> b;
					if (Fig == 3) {cin >> c;}
					if (Fig == 1) {f = make_shared<Rectangle>(Rectangle(a, b));}
					if (Fig == 2) {f = make_shared<Rhombus>(Rhombus(a, b));}
					if (Fig == 3) {f = make_shared<Trapeze>(Trapeze(a, b, c));}
					list.push_f(move(f));
				}
				if (flag2 == 2) {
					cout << "1. Rectangle" << endl;
					cout << "2. Rhombus" << endl;
					cout << "3. Trapeze" << endl;
					cin >> Fig;
					if (Fig == 1) {
						cout << "Enter Rectangle:" << endl;
					}
					if (Fig == 2) {
						cout << "Enter Rhombus:" << endl;
					}
					if (Fig == 3) {
						cout << "Enter Trapeze:" << endl;
					}
					cin >> a >> b;
					if (Fig == 3) {cin >> c;}
					if (Fig == 1) {f = make_shared<Rectangle>(Rectangle(a, b));}
					if (Fig == 2) {f = make_shared<Rhombus>(Rhombus(a, b));}
					if (Fig == 3) {f = make_shared<Trapeze>(Trapeze(a, b, c));}
					list.push_b(move(f));
				}
				if (flag2 == 3) {
					cout << "1. Rectangle" << endl;
					cout << "2. Rhombus" << endl;
					cout << "3. Trapeze" << endl;
					cin >> Fig;
					if (Fig == 1) {
						cout << "Enter Rectangle:" << endl;
					}
					if (Fig == 2) {
						cout << "Enter Rhombus:" << endl;
					}
					if (Fig == 3) {
						cout << "Enter Trapeze:" << endl;
					}
					cin >> a >> b;
					if (Fig == 3) {cin >> c;}
					if (Fig == 1) {f = make_shared<Rectangle>(Rectangle(a, b));}
					if (Fig == 2) {f = make_shared<Rhombus>(Rhombus(a, b));}
					if (Fig == 3) {f = make_shared<Trapeze>(Trapeze(a, b, c));}
					if (Fig <= 3) {
						int p;
						cout << "Enter position:" << endl;
						cin >> p;
						list.ins(move(f), p);
					}
				}
			}
		}
		if (flag == 2) {
			int p;
			cout << "Enter position:" << endl;
			cin >> p;
			list.pop(p);
		}
		if (flag == 3) {
      list.~TList();
		}
		if (flag == 4) {
			cout << "List:" << endl;
			for (auto i : list) {
				i->Print();
				cout << " - ";
			}
			cout << endl;
		}
		if (flag == 5) {
			int p;
			cout << "Enter position:" << endl;
			cin >> p;
			cout << "Square = " << list.GetSquare(p) << endl;
		}
		if (flag == 6) {
			int amount_;
			int range_side;
			cout << "How many elements? \n";
			cin >> amount_;
			cout << "Set side range: from 1 to ";
			cin >> range_side;
			cout << endl;
			uniform_int_distribution<int> genSide(1, range_side);
			for (int i = 0; i < amount_; ++i) {
				Fig_ = genFigure(generator);
				a = genSide(generator);
				b = genSide(generator);
				c = genSide(generator);
				if (Fig_ == 1) f = make_shared<Rectangle>(Rectangle(a, b));
				if (Fig_ == 2) f = make_shared<Rhombus>(Rhombus(a, b));
				if (Fig_ == 3) f = make_shared<Trapeze>(Trapeze(a, b, c));
				list.push_f(move(f));
			}
		}
		if (flag == 7) {
			int sortType;
			cout << "1. Usual Sort" << endl;
			cout << "2. Parallel Sort" << endl;
			cin >> sortType;
			cout << "Sort -------------" << endl;
			if (sortType == 1) {
				list.sort();
			}
			else {
				list.sort_parallel();
			}
			cout << "Done -------------" << endl;
		}
		if (flag == 8) {
			list.~TList();
			return 0;
		}
		else {}

	}


    return 0;
}
