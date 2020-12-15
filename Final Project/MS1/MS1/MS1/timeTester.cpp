// Time Tester:
// Version: 1.0
// Date: 11/03/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the Durtion Module of your project
/////////////////////////////////////////////
#include <iostream>
#include "Time.h"
#include "utils.h"
using namespace std;
using namespace sdds;
int main() {
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
   cout << "Actual system time is: " <<  Time().reset() << endl;
   return 0;
}
