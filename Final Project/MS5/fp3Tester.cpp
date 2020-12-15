// Final Project Tester
// file: fp3Tester.cpp
// Version: 1.0 
// Date: 11/25/2020
// Author: Fardad 
// Description:
// This file tests the Final project with 
// records more than the capcity of PriTirage
/////////////////////////////////////////////
#include <iostream>
#include "PreTriage.h"
#include "utils.h"
using namespace sdds;
int main() {
   sdds::debug = true;
   PreTriage P("bigdata.csv");
   P.run();
   return 0;
}

