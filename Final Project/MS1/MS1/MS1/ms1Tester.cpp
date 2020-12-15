// Menu tester:
// Version: 1.0
// Date: 11/03/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the Menu module of the project
/////////////////////////////////////////////
#include <iostream>
#include "Menu.h"
#include "Time.h"
#include "utils.h"
using namespace sdds;
using namespace std; 
void menuTester();
void timeTester();
int main() {
   cout << "Menu tester -----------------------------------------" << endl;
   menuTester();
   cout << "Time tester -----------------------------------------" << endl;
   timeTester();
   return 0;
}


void menuTester() {
   Menu m("Tester Options menu:\n1- Option one\n2- Option two\n3- Option three", 3);
   int selection;
   while (m >> selection) {
      switch (selection) {
      case 1:
         cout << "option one selected" << endl << endl;
         break;
      case 2:
         cout << "option two selected" << endl << endl;
         break;
      case 3:
         cout << "option three selected" << endl << endl;
         break;
      default:
         cout << "This will never happen!!!!" << endl;
         break;
      }
   }
   cout << "goodbye!" << endl;
}

void timeTester() {
   sdds::debug = false;
   Time D(1385), C(65), E;
   cout << "E: " << E << endl;
   cout << "D: " << D << endl;
   cout << "C: " << C << endl;
   cout << "  D        C     D-=C" << endl;
   cout << D << " -= " << C << " = ";
   cout << (D -= C) << endl;
   cout << "  C        D     C-=D" << endl;
   cout << C << " -= " << D << " = ";
   cout << (C -= D) << endl;
   cout << "C: " << C << endl;
   cout << " C *= 2" << endl;
   cout << (C *= 2) << endl;
   cout << " C *= 12" << endl;
   cout << (C *= 12) << endl;

   cout << "Please enter the time (HH:MM): ";
   bool done;
   do {
      done = true;
      cin >> E;
      if (cin.fail()) {
         cin.clear();
         cin.ignore(1000, '\n');
         done = false;
         cout << "Bad time entry, retry (HH:MM): ";
      }
   } while (!done);
   cout << "you entered: " << E << endl;
   sdds::debug = true;
   E.reset();
   cout << E << endl;
   sdds::debug = false;
   cout << "Actual system time is: " << Time().reset() << endl;

}
