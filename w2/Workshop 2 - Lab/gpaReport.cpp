// Workshop 2: 
// Version: 0.9
// Date: 09/25/2020
// Author: Fardad Soleimanloo
// Reviewed by: Michael Huang
// Description:
// This file tests the lab section of your workshop
// Do not modify your code
/////////////////////////////////////////////

//#include <iostream>
#include "Student.h"
//#include "File.h"

using namespace sdds;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}