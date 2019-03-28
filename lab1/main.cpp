#include <iostream>
#include "Rectangle.h"
#include "Trapeze.h"
#include "Rhombus.h"

using namespace std;

int main(int argc, char** argv)
{
  Figure *ptr;
  while(true) {
    cout << "Menu:" << endl;
    cout << "1. Rectangle" << endl;
    cout << "2. Trapeze" << endl;
    cout << "3. Rhombus" << endl;
    cout << "4. Exit" << endl;
    int s;
    while(true) {
      cin >> s;
      if (s == 1) {
        ptr = new Rectangle(cin);
        break;
      }
      if (s == 2) {
        ptr = new Trapeze(cin);
        break;
      }
      if (s == 3) {
        ptr = new Rhombus(cin);
        break;
      }
      if (s == 4) {
        return 0;
      }
      else {
        cout << "?!" << endl;
      }
    }
    ptr->Print();
    cout << "Square: " << ptr->Square() << endl;
    delete ptr;
  }
  return 0;
}
