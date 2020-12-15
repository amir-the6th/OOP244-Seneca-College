// Workshop 2: 
// Version: 0.9
// Date: 09/25/2020
// Author: Fardad Soleimanloo
// Reviewed by: Michael Huang
// Description:
// This file tests the DIY section of your workshop
// Do not modify your code
/////////////////////////////////////////////
#include "Account.h"
using namespace sdds;
int main() {
   if (load("accounts_subtest.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}