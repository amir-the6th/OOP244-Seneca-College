// Final Project Tester
// file: fp2Tester.cpp
// Version: 1.0 
// Date: 11/25/2020
// Author: Fardad 
// Description:
// This file tests the Final project 
// overall functionality
/////////////////////////////////////////////
#include <iostream>
#include "PreTriage.h"
#include "utils.h"
using namespace sdds;
int main() {
   sdds::debug = true;
   PreTriage P("smalldata.csv");
   P.run();
   return 0;
}

