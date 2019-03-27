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


int main(int argc, char** argv) {
	int a, b, c;
	int Fig;

	TList<TQueue<Figure>, Figure> list;

	while (true) {
		int flag = 0;
		int flag2 = 0;
		int flag3 = 0;
		int amounts = 0;
		cout << "Menu:" << endl;
		cout << "1. Add" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Destructor" << endl;
		cout << "4. Print Container" << endl;
		cout << "5. Get Square" << endl;
		cout << "6. Exit" << endl;

		cin >> flag;

		if (flag == 1) {
			cout << "How many elements?" << endl;
			cin >> amounts;
			for (int i = 0; i < amounts; ++i) {
				cout << "Choose Figure:" << endl;
				cout << "1. Rectangle" << endl;
				cout << "2. Rhombus" << endl;
				cout << "3. Trapezium:" << endl;
				cin >> Fig;
				if (Fig == 1) {
					cout << "Enter side a and side b:" << endl;
				}
				if (Fig == 2) {
					cout << "Enter diag a and diag b:" << endl;
				}
				if (Fig == 3) {
					cout << "Enter base a, base b and height:" << endl;
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
			cout << "Container:" << endl;
			cout << list << endl;
		}
		if (flag == 5) {
			int position;
			int position2;
			cout << "Enter Container:" << endl;
			cin >> position;
			if (position >= 1 && position <= list.GetSize()) {
				TQueue<Figure> CurQueue = list.GetElement(position);
				cout << "Enter Position:" << endl;
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
			return 0;
		}
		else {}

	}


    return 0;
}
