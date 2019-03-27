#include <cstdlib>
#include <iostream>
#include "Rectangle.h"
#include "TListItem.h"
#include "TList.h"
#include "TQueueItem.h"
#include "TQueue.h"
#include "TAllocationBlock.h"
#include <memory>
#include <random>
#include <thread>
#include <mutex>
#include <future>
#include <functional>

using namespace std;

int main(int argc, char** argv) {

	int a, b, c;
	int Fig;

	int allocated_blocks = 5;

	TList<Figure> list;
	shared_ptr<Figure> f;
	default_random_engine generator;
	uniform_int_distribution<int> genFigure(1, 3);

	typedef function<void(void) > command;
	TQueue<command> queue_cmd;

	command cmd_insert = [&]() {
		int amount_;
		int range_side;
		cout << "How many elements?" << endl;
		cin >> amount_;
		cout << "Enter side range: from 1 to" << endl;
		cin >> range_side;
		cout << endl;;
		uniform_int_distribution<int> genSide(1, range_side);
		for (int i = 0; i < amount_; ++i) {
			int Fig_ = genFigure(generator);
			a = genSide(generator);
			b = genSide(generator);
			c = genSide(generator);
			if (Fig_ == 1) f = make_shared<Rectangle>(Rectangle(a, b));
			if (Fig_ == 2) f = make_shared<Rhombus>(Rhombus(a, b));
			if (Fig_ == 3) f = make_shared<Trapeze>(Trapeze(a, b, c));
			list.push_f(move(f));
		}
	};

	command cmd_print = [&]() {
		cout << "Command: Print list" << endl;
		cout << list;
	};


	command cmd_reverse = [&]() {
		cout << "Command: Reverse list" << endl;

		TList<Figure> *list_tmp = new TList<Figure>();
		while (!list.empty()) list_tmp->push_f(list.pop_b());
		while (!list_tmp->empty()) list.push_f(list_tmp->pop_f());

	};


	command cmd_deleteBAD = [&]() {
		cout << "Command: Deletes figure with s <= " << endl;
		size_t square_X;
		cin >> square_X;

		int num = 1;
		for (auto i : list) {
			if (i->Square() <= square_X) {
				list.pop(num);
			}
			else {
				++num;
			}
		}

	};



	while (true) {
		int flag = 0;
		int flag2 = 0;
		int amounts = 0;
		int Fig_ = 0;
		cout << "Menu:" << endl;
		cout << "1. Add " << endl;
		cout << "2. Pop" << endl;
		cout << "3. Destructor" << endl;
		cout << "4. Print List" << endl;
		cout << "5. Print Square" << endl;
		cout << "6. Sort" << endl;
		cout << "7. Queue menu" << endl;
		cout << "8. Exit" << endl;

		cin >> flag;

		if (flag == 1) {
			cout << "How many elements?" << endl;
			cin >> amounts;
			for (int i = 0; i < amounts; ++i) {
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
						cout << "Enter side a and side b:" << endl;
					}
					if (Fig == 2) {
						cout << "Enter diag a and diag b:" << endl;
					}
					if (Fig == 3) {
						cout << "Set 2 Sizes and height:" << endl;
					}
					cin >> a >> b;
					if (Fig == 3) cin >> c;
					if (Fig == 1) f = make_shared<Rectangle>(Rectangle(a, b));
					if (Fig == 2) f = make_shared<Rhombus>(Rhombus(a, b));
					if (Fig == 3) f = make_shared<Trapeze>(Trapeze(a, b, c));
					list.push_f(move(f));
				}
				if (flag2 == 2) {
					cout << "Choose Figure:" << endl;
					cout << "1 - Rectangle" << endl;
					cout << "2 - Rhombus" << endl;
					cout << "3 - Trapeze:" << endl;
					cin >> Fig;
					if (Fig == 1) {
						cout << "Set Sizes:" << endl;
					}
					if (Fig == 2) {
						cout << "Set Heights:" << endl;
					}
					if (Fig == 3) {
						cout << "Set 2 Sizes and height:" << endl;
					}
					cin >> a >> b;
					if (Fig == 3) cin >> c;
					if (Fig == 1) f = make_shared<Rectangle>(Rectangle(a, b));
					if (Fig == 2) f = make_shared<Rhombus>(Rhombus(a, b));
					if (Fig == 3) f = make_shared<Trapeze>(Trapeze(a, b, c));
					list.push_b(move(f));
				}
				if (flag2 == 3) {
					cout << "Choose Figure:" << endl;
					cout << "1 - Rectangle " << endl;
					cout << "2 - Rhombus" << endl;
					cout << "3 - Trapeze:" << endl;
					cin >> Fig;
					if (Fig == 1) {
						cout << "Set Sizes:" << endl;
					}
					if (Fig == 2) {
						cout << "Set Heights:" << endl;
					}
					if (Fig == 3) {
						cout << "Set 2 Sizes and height:" << endl;
					}
					cin >> a >> b;
					if (Fig == 3) cin >> c;
					if (Fig == 1) f = make_shared<Rectangle>(Rectangle(a, b));
					if (Fig == 2) f = make_shared<Rhombus>(Rhombus(a, b));
					if (Fig == 3) f = make_shared<Trapeze>(Trapeze(a, b, c));
					if (Fig <= 3) {
						int position;
						cout << "Set Position:" << endl;
						cin >> position;
						list.ins(move(f), position);
					}
				}
			}
		}
		if (flag == 2) {
			int position;
			cout << "Set Position:" << endl;
			cin >> position;
			list.pop(position);
		}
		if (flag == 3) {
      list.~TList();
		}
		if (flag == 4) {
			cout << "Container:" << endl;
			for (auto i : list) {
				i->Print();
				cout << " - ";
			}
			cout << endl;
		}
		if (flag == 5) {
			int position;
			cout << "Which Element?" << endl;
			cin >> position;
			cout << "Square = " << list.GetSquare(position) << endl;
		}
		if (flag == 6) {
			int sortType;
			cout << "Choose sort type:" << endl;
			cout << "1) Usual Sort" << endl;
			cout << "2) Parallel Sort" << endl;
			cin >> sortType;
			cout << "Sort" << endl;
			if (sortType == 1) {
				list.sort();
			}
			else {
				list.sort_parallel();
			}
			cout << "Done" << endl;
		}
		if (flag == 7) {
			int command_add;
			cout << "Queue menu:" << endl;
			cout << "1. Print list." << endl;
			cout << "2. Add random elements." << endl;
			cout << "3. Reverse list." << endl;
			cout << "4. Delete elements lower centrain square." << endl;
			cout << "5. Execute all commands" << endl;
			cin >> command_add;
			if (command_add == 1) {
				queue_cmd.push(shared_ptr<command>(&cmd_print, [](command*) {
				}));
			}
			else if (command_add == 2) {
				queue_cmd.push(shared_ptr<command>(&cmd_insert, [](command*) {
				}));
			}
			else if (command_add == 3) {
				queue_cmd.push(shared_ptr<command>(&cmd_reverse, [](command*) {
				}));
			}
			else if (command_add == 4) {
				queue_cmd.push(shared_ptr<command>(&cmd_deleteBAD, [](command*) {
				}));
			}
			else if (command_add == 5) {
				while (!queue_cmd.empty()) {
					shared_ptr<command> cmd = queue_cmd.pop();
					future<void> ft = async(*cmd);
					ft.get();
				}

			}

		}
		if (flag == 8) {
			list.~TList();
			return 0;
		}
		else {}

	}


    return 0;
}
