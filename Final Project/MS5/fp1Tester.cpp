// Final Project Tester
// file: fp1Tester.cpp
// Version: 1.0 
// Date: 11/25/2020
// Author: Fardad 
// Description:
// This file tests the Final project 
// with no data file
/////////////////////////////////////////////
#include <iostream>
#include "PreTriage.h"
#include "utils.h"
using namespace sdds;
int main() {
   sdds::debug = true;
   PreTriage P("data.csv");
   P.run();
   return 0;
}

