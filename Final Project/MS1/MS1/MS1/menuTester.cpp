// Menu tester:
// Version: 1.0
// Date: 11/03/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the Menu module of the project
/////////////////////////////////////////////
#include <iostream>
#include "Menu.h"

using namespace sdds;
using namespace std;
int main() {
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
   return 0;
}