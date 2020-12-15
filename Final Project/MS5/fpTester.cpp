// Final Project Tester
// file: fpTester.cpp
// Version: 1.0 
// Date: 11/25/2020
// Author: Fardad 
// Description:
// This file tests the Final project
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PreTriage.h"
#include "utils.h"
using namespace std;
using namespace sdds;
void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void fp1tester() {
   sdds::debug = true;
   PreTriage P("data.csv");
   P.run();
}
void fp2tester() {
   sdds::debug = true;
   PreTriage P("smalldata.csv");
   P.run();
}
void fp3tester() {
   sdds::debug = true;
   PreTriage P("bigdata.csv");
   P.run();
}
int main() {
   fp1tester();
   displayFile("data.csv");
   fp3tester();
   displayFile("bigdata.csv");
   fp2tester();
   displayFile("smalldata.csv");
   return 0;
}


