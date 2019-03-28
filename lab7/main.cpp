#include <cstdlib>
#include <iostream>
#include "Figure.h"
#include "TListItem.h"
#include "TList.h"
#include "TQueueItem.h"
#include "TQueue.h"
#include "TIterator.h"
#include "TAllocationBlock.h"
#include "IRemoveCriteriaByValue.h"
#include "IRemoveCriteriaByType.h"
#include "IRemoveCriteriaAll.h"
#include <memory>

using namespace std;

void PrintMenu() {
    cout << "Menu:" << endl;
    cout << "0. Print Menu" << endl;
		cout << "1. Add" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Print List" << endl;
		cout << "5. Get Square" << endl;
		cout << "6. Exit" << endl;
}

int main(int argc, char** argv) {
	TList<TQueue<Figure>, Figure> list;
  PrintMenu();
	while (true) {
    cout << ':';
		int flag = 0;
		cin >> flag;
    if (flag == 0) {PrintMenu();}
		if (flag == 1) {
			cout << "How many elements?" << endl;
			int k = 0;
			cin >> k;
			for (int i = 0; i < k; ++i) {
				cout << "1. Rectangle" << endl;
				cout << "2. Rhombus" << endl;
				cout << "3. Trapezium:" << endl;
				int Fig, a, b, c;
				cin >> Fig;
				if (Fig == 1) {
					cout << "Enter Rectangle:" << endl;
				}
				if (Fig == 2) {
					cout << "Enter Rhombus:" << endl;
				}
				if (Fig == 3) {
					cout << "Enter Trapezium:" << endl;
				}
				cin >> a >> b;
				if (Fig == 3) cin >> c;
				if (Fig == 1) list.InsertSubitem(new Rectangle(a, b));
				if (Fig == 2) list.InsertSubitem(new Rhombus(a, b));
				if (Fig == 3) list.InsertSubitem(new Trapeze(a, b, c));
			}
		}
		if (flag == 2) {
			cout << "1. By type" << endl;
			cout << "2. By square (below)" << endl;
      int flag2 = 0;
      int flag3 = 0;
			cin >> flag2;
			if (flag2 == 1) {
				cout << "1. All Rectangles" << endl;
				cout << "2. All Rhombuses" << endl;
				cout << "3. All Trapeziums" << endl;
				cin >> flag3;
				if (flag3 == 1) {
					IRemoveCriteriaByType<Figure> criteria(1);
					list.RemoveSubitem(&criteria);
				}
				else if (flag3 == 2) {
					IRemoveCriteriaByType<Figure> criteria(2);
					list.RemoveSubitem(&criteria);
				}
				else if (flag3 == 3) {
					IRemoveCriteriaByType<Figure> criteria(3);
					list.RemoveSubitem(&criteria);
				}

			}
			else {
				cout << "Insert Square:";
				cin >> flag3;
				IRemoveCriteriaByValue<Figure> criteria(flag3);
				list.RemoveSubitem(&criteria);
			}
		}
		if (flag == 3) {
				IRemoveCriteriaAll<Figure> criteria;
				list.RemoveSubitem(&criteria);
		}
		if (flag == 4) {
			cout << "List:" << endl;
			cout << list << endl;
		}
		if (flag == 5) {
			int position;
			int position2;
			cout << "Enter List item position:" << endl;
			cin >> position;
			if (position >= 1 && position <= list.GetSize()) {
				TQueue<Figure> CurQueue = list.GetElement(position);
				cout << "Enter Queue item position:" << endl;
				cin >> position2;
				if (position2 >= 1 && position2 <= CurQueue.GetCount()) {
					TQueueItem<Figure> CurElement = CurQueue.GetElement(position2);
					cout << "Square = " << CurElement.GetValue()->Square() << endl;
				}
				else {
					cout << "Incorrect position!!!" << endl;
				}
			}
			else {
				cout << "Incorrect position!!!" << endl;
			}
		}
		if (flag == 6) {
			list.~TList();
			break;
		}
		else {}

	}


    return 0;
}
